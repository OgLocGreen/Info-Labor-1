# app.py
import base64
import io
import itertools
import textwrap
from dataclasses import dataclass
from typing import Dict, List, Tuple, Any

import dash
from dash import html, dcc, Input, Output, State, ctx
import dash_cytoscape as cyto
import networkx as nx
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

# ---------------------------------------
# Logic gate primitives
# ---------------------------------------
def _as_bool(arr):
    return np.array(arr, dtype=bool)

def gate_and(xs):  # n-ary
    return bool(np.all(_as_bool(xs)))

def gate_or(xs):   # n-ary
    return bool(np.any(_as_bool(xs)))

def gate_not(xs):  # unary
    assert len(xs) == 1
    return (not bool(xs[0]))

def gate_xor(xs):  # n-ary XOR (odd parity)
    b = _as_bool(xs)
    return bool(np.sum(b) % 2 == 1)

def gate_nand(xs):
    return not gate_and(xs)

def gate_nor(xs):
    return not gate_or(xs)

GATE_DEF = {
    "INPUT": dict(fn=None, min_in=0, max_in=0, symbol="", out_label="I"),
    "OUTPUT": dict(fn=None, min_in=1, max_in=1, symbol="", out_label="O"),
    "AND": dict(fn=gate_and, min_in=2, max_in=8, symbol="·"),
    "OR": dict(fn=gate_or, min_in=2, max_in=8, symbol="+"),
    "NOT": dict(fn=gate_not, min_in=1, max_in=1, symbol="¬"),
    "XOR": dict(fn=gate_xor, min_in=2, max_in=8, symbol="⊕"),
    "NAND": dict(fn=gate_nand, min_in=2, max_in=8, symbol="⊼"),
    "NOR": dict(fn=gate_nor, min_in=2, max_in=8, symbol="⊽"),
}

# ---------------------------------------
# Helpers
# ---------------------------------------
def new_node(node_id: str, gate_type: str, pos=(100, 100), label=None, value: int = 0):
    label = label or f"{gate_type}_{node_id}"
    shape = "rectangle" if gate_type in ("INPUT", "OUTPUT") else "round-rectangle"
    color = "#1f77b4" if gate_type not in ("INPUT", "OUTPUT") else ("#2ca02c" if gate_type=="INPUT" else "#9467bd")
    return {
        "data": {"id": node_id, "label": label, "type": gate_type, "value": int(value)},
        "position": {"x": pos[0], "y": pos[1]},
        "classes": gate_type.lower(),
        "style": {"background-color": color, "label": label, "width": 70, "height": 40},
        "selectable": True,
        "grabbable": True,
    }

def new_edge(edge_id: str, src: str, tgt: str):
    return {
        "data": {"id": edge_id, "source": src, "target": tgt},
    }

def elements_to_graph(elements) -> nx.DiGraph:
    G = nx.DiGraph()
    for el in elements:
        if "source" in el.get("data", {}):  # edge
            G.add_edge(el["data"]["source"], el["data"]["target"])
        else:  # node
            n = el["data"]["id"]
            G.add_node(n, **el["data"])
    return G

def topo_or_raise(G: nx.DiGraph) -> List[str]:
    if not nx.is_directed_acyclic_graph(G):
        cycles = list(nx.simple_cycles(G))
        raise ValueError(f"Schaltung enthält Rückkopplungen/Loops (nicht unterstützt). Beispiel-Zyklus: {cycles[:1]}")
    return list(nx.topological_sort(G))

def find_ios(G: nx.DiGraph) -> Tuple[List[str], List[str]]:
    inputs = [n for n, d in G.nodes(data=True) if d.get("type") == "INPUT"]
    outputs = [n for n, d in G.nodes(data=True) if d.get("type") == "OUTPUT"]
    return inputs, outputs

def eval_circuit(G: nx.DiGraph, assignment: Dict[str, int]) -> Dict[str, int]:
    order = topo_or_raise(G)
    values: Dict[str, int] = {}
    # seed inputs
    for n in order:
        t = G.nodes[n].get("type")
        if t == "INPUT":
            values[n] = int(assignment.get(n, G.nodes[n].get("value", 0)))

    # compute intermediates
    for n in order:
        t = G.nodes[n].get("type")
        if t in ("INPUT",):
            continue
        preds = list(G.predecessors(n))
        # fetch inputs as current values
        in_vals = [values.get(p, 0) for p in preds]
        if t == "OUTPUT":
            # pass-through single input to an output node
            if len(in_vals) != 1:
                raise ValueError(f"OUTPUT {n} muss genau 1 Eingang haben.")
            values[n] = int(in_vals[0])
        else:
            fn = GATE_DEF[t]["fn"]
            mn, mx = GATE_DEF[t]["min_in"], GATE_DEF[t]["max_in"]
            if not (mn <= len(in_vals) <= mx):
                raise ValueError(f"{t} {n} benötigt {mn}..{mx} Eingänge, gefunden: {len(in_vals)}")
            values[n] = int(bool(fn(in_vals)))
    return values

def build_symbolic_expr(G: nx.DiGraph, node: str, cache: Dict[str, str]) -> str:
    if node in cache:
        return cache[node]
    t = G.nodes[node]["type"]
    if t == "INPUT":
        expr = G.nodes[node]["label"]
    elif t == "OUTPUT":
        preds = list(G.predecessors(node))
        if len(preds) != 1:
            raise ValueError(f"OUTPUT {node} muss genau 1 Eingang haben.")
        expr = build_symbolic_expr(G, preds[0], cache)
    else:
        preds = list(G.predecessors(node))
        parts = [build_symbolic_expr(G, p, cache) for p in preds]
        sym = GATE_DEF[t]["symbol"]
        if t == "NOT":
            expr = f"{sym}({parts[0]})"
        elif t in ("AND", "OR", "XOR", "NAND", "NOR"):
            expr = f' {sym} '.join(f"({p})" for p in parts)
            if t in ("NAND", "NOR"):
                expr = f"¬({expr})"
        else:
            expr = "?"
    cache[node] = expr
    return expr

def truth_table(G: nx.DiGraph) -> pd.DataFrame:
    inputs, outputs = find_ios(G)
    if len(inputs) == 0 or len(outputs) == 0:
        raise ValueError("Mindestens ein INPUT und ein OUTPUT sind erforderlich.")
    order = topo_or_raise(G)  # also validates DAG
    rows = []
    # Deterministic order: sort by node id to keep stable column order
    inputs_sorted = sorted(inputs)
    outputs_sorted = sorted(outputs)
    for bits in itertools.product([0, 1], repeat=len(inputs_sorted)):
        assign = {inp: b for inp, b in zip(inputs_sorted, bits)}
        vals = eval_circuit(G, assign)
        row = {inp: assign[inp] for inp in inputs_sorted}
        row.update({out: vals[out] for out in outputs_sorted})
        rows.append(row)
    df = pd.DataFrame(rows, columns=inputs_sorted + outputs_sorted)
    return df

def timing_diagram_image(df: pd.DataFrame) -> str:
    # Create a timing diagram from truth table order (binary count)
    signals = list(df.columns)
    x = np.arange(len(df))
    fig = plt.figure(figsize=(max(8, len(df)*0.25), 1.2*len(signals)))
    # One big axis stacking step plots per signal
    ax = plt.gca()
    y_offset = 0
    y_step = 1.2
    for sig in signals:
        y = y_offset + df[sig].values.astype(float)
        ax.step(x, y, where="post")
        # annotate signal name
        ax.text(-0.5, y_offset + 0.5, sig, va="center", ha="right")
        # draw baseline
        ax.hlines(y_offset, xmin=x.min(), xmax=x.max(), linewidth=0.5)
        y_offset += y_step
    ax.set_yticks([])
    ax.set_xlim(-0.5, len(df)-0.5)
    ax.set_xlabel("Schritt")
    ax.set_title("Timing-Diagramm (Folge der Wahrheitstabelle)")
    fig.tight_layout()
    buf = io.BytesIO()
    plt.savefig(buf, format="png", bbox_inches="tight")
    plt.close(fig)
    b64 = base64.b64encode(buf.getvalue()).decode("ascii")
    return "data:image/png;base64," + b64

# ---------------------------------------
# Dash App
# ---------------------------------------
app = dash.Dash(__name__)
app.title = "Logik-Simulator (Drag & Drop)"

default_elements = [
    new_node("I1", "INPUT", (100, 100), label="A", value=0),
    new_node("I2", "INPUT", (100, 200), label="B", value=0),
    new_node("G1", "AND", (300, 150)),
    new_node("O1", "OUTPUT", (520, 150), label="Y"),
    new_edge("e1", "I1", "G1"),
    new_edge("e2", "I2", "G1"),
    new_edge("e3", "G1", "O1"),
]

stylesheet = [
    {"selector": "node", "style": {"label": "data(label)", "text-valign": "center", "font-size": "12px", "color": "#111"}},
    {"selector": ".input", "style": {"shape": "rectangle", "background-color": "#2ca02c"}},
    {"selector": ".output", "style": {"shape": "rectangle", "background-color": "#9467bd"}},
    {"selector": ".and", "style": {"background-color": "#1f77b4"}},
    {"selector": ".or", "style": {"background-color": "#1f77b4"}},
    {"selector": ".not", "style": {"background-color": "#1f77b4"}},
    {"selector": ".xor", "style": {"background-color": "#1f77b4"}},
    {"selector": ".nand", "style": {"background-color": "#1f77b4"}},
    {"selector": ".nor", "style": {"background-color": "#1f77b4"}},
    {"selector": "edge", "style": {"curve-style": "bezier", "target-arrow-shape": "triangle", "arrow-scale": 1, "width": 2}},
]

app.layout = html.Div([
    dcc.Store(id="store-elements", data=default_elements),
    html.H2("Logik-Simulator (Drag & Drop) – mit Notation, Wahrheitstabelle & Timing-Diagramm"),
    html.Div([
        html.Div([
            html.H4("Bausteine hinzufügen"),
            dcc.Dropdown(
                id="add-type",
                options=[{"label": t, "value": t} for t in ["INPUT", "OUTPUT", "AND", "OR", "NOT", "XOR", "NAND", "NOR"]],
                value="AND",
                clearable=False
            ),
            dcc.Input(id="add-label", placeholder="Label (optional)", type="text"),
            html.Button("Baustein hinzufügen", id="btn-add-node", n_clicks=0),

            html.Hr(),
            html.H4("Kante hinzufügen"),
            dcc.Input(id="edge-src", placeholder="Quelle (Node-ID)", type="text"),
            dcc.Input(id="edge-tgt", placeholder="Ziel (Node-ID)", type="text"),
            html.Button("Kante hinzufügen", id="btn-add-edge", n_clicks=0),
            html.Div(id="edge-msg", style={"marginTop": "6px", "fontSize": "12px"}),

            html.Hr(),
            html.H4("Eingangswerte (Live)"),
            dcc.Textarea(
                id="input-assign",
                placeholder="z.B. A=0, B=1  oder  I1=1, I2=0",
                style={"width": "100%", "height": "60px"}
            ),
            html.Button("Live auswerten", id="btn-eval", n_clicks=0),
            html.Div(id="live-output", style={"marginTop": "8px"}),

            html.Hr(),
            html.Button("Wahrheitstabelle erzeugen", id="btn-truth", n_clicks=0),
            html.Button("Timing-Diagramm erzeugen", id="btn-timing", n_clicks=0),

        ], style={"flex": "0 0 320px", "paddingRight": "16px", "borderRight": "1px solid #ddd"}),

        html.Div([
            cyto.Cytoscape(
                id="cy",
                layout={"name": "preset"},
                style={"width": "100%", "height": "520px", "border": "1px solid #ddd"},
                elements=default_elements,
                stylesheet=stylesheet,
                responsive=True,
                minZoom=0.2,
                maxZoom=2.0,
                wheelSensitivity=0.2,
            ),
            html.Div(id="notation", style={"marginTop": "12px", "whiteSpace": "pre-wrap", "fontFamily": "monospace"}),
            html.Hr(),
            html.Div(id="truth-table"),
            html.Div(id="timing", style={"marginTop": "12px"}),
        ], style={"flex": "1 1 auto", "paddingLeft": "16px"}),
    ], style={"display": "flex", "gap": "16px"}),
], style={"maxWidth": "1200px", "margin": "16px auto", "fontFamily": "Inter, system-ui, Arial"})

# ---------------------------------------
# Callbacks
# ---------------------------------------
@app.callback(
    Output("store-elements", "data"),
    Output("cy", "elements"),
    Input("btn-add-node", "n_clicks"),
    State("add-type", "value"),
    State("add-label", "value"),
    State("store-elements", "data"),
    prevent_initial_call=True,
)
def add_node(n_clicks, gate_type, label, els):
    if not els:
        els = []
    # generate new id
    existing_ids = {el["data"]["id"] for el in els if "data" in el and "id" in el["data"]}
    base = gate_type[0]
    idx = 1
    while f"{base}{idx}" in existing_ids:
        idx += 1
    node_id = f"{base}{idx}"
    # place near center-ish
    pos_x = 150 + 40*idx
    pos_y = 120 + 40*((idx//4)%8)
    value = 0
    if gate_type == "INPUT":
        value = 0
    node = new_node(node_id, gate_type, (pos_x, pos_y), label=label or None, value=value)
    els2 = els + [node]
    return els2, els2

@app.callback(
    Output("edge-msg", "children"),
    Output("store-elements", "data"),
    Output("cy", "elements"),
    Input("btn-add-edge", "n_clicks"),
    State("edge-src", "value"),
    State("edge-tgt", "value"),
    State("store-elements", "data"),
    prevent_initial_call=True,
)
def add_edge(n_clicks, src, tgt, els):
    if not els:
        return "Keine Elemente geladen.", els, els
    if not src or not tgt:
        return "Bitte Quelle und Ziel angeben.", els, els
    nodes = {el["data"]["id"] for el in els if "data" in el and "id" in el["data"] and "source" not in el["data"]}
    if src not in nodes or tgt not in nodes:
        return "Quelle/Ziel nicht gefunden.", els, els
    # unique edge id
    existing_eids = {el["data"]["id"] for el in els if "data" in el and "source" in el["data"]}
    idx = 1
    eid = f"e{idx}"
    while eid in existing_eids:
        idx += 1
        eid = f"e{idx}"
    edge = new_edge(eid, src, tgt)
    els2 = els + [edge]
    # try detect simple violations early (optional)
    return f"Kante hinzugefügt: {src} → {tgt}", els2, els2

@app.callback(
    Output("live-output", "children"),
    Output("notation", "children"),
    Input("btn-eval", "n_clicks"),
    State("input-assign", "value"),
    State("store-elements", "data"),
    prevent_initial_call=True,
)
def live_eval(n_clicks, txt_assign, els):
    try:
        G = elements_to_graph(els or [])
        # parse assignment: A=0, B=1 or by node id
        assign = {}
        if txt_assign:
            for token in txt_assign.replace("\n", ",").split(","):
                token = token.strip()
                if not token:
                    continue
                if "=" not in token:
                    continue
                k, v = token.split("=", 1)
                assign[k.strip()] = int(v.strip())
        values = eval_circuit(G, assign)
        inputs, outputs = find_ios(G)

        out_lines = []
        for o in sorted(outputs):
            out_lines.append(f"{G.nodes[o]['label']}: {values[o]}")
        live_text = " | ".join(out_lines) if out_lines else "Keine OUTPUT-Knoten."

        # Notation (symbolische Ausdrücke der Outputs)
        cache = {}
        lines = []
        for o in sorted(outputs):
            expr = build_symbolic_expr(G, o, cache)
            lines.append(f"{G.nodes[o]['label']} = {expr}")
        notation = "\n".join(lines) if lines else "Keine Outputs."
        return live_text, notation
    except Exception as e:
        return f"Fehler: {e}", f"Fehler: {e}"

@app.callback(
    Output("truth-table", "children"),
    Input("btn-truth", "n_clicks"),
    State("store-elements", "data"),
    prevent_initial_call=True,
)
def make_truth(n_clicks, els):
    try:
        G = elements_to_graph(els or [])
        df = truth_table(G)
        # Render as simple HTML table
        header = html.Tr([html.Th(c) for c in df.columns])
        rows = [html.Tr([html.Td(int(v)) for v in row]) for row in df.values]
        tbl = html.Table([html.Thead(header), html.Tbody(rows)], style={"borderCollapse": "collapse"},
                         className="truth-table")
        return html.Div([html.H4("Wahrheitstabelle"), tbl])
    except Exception as e:
        return html.Div(f"Fehler: {e}")

@app.callback(
    Output("timing", "children"),
    Input("btn-timing", "n_clicks"),
    State("store-elements", "data"),
    prevent_initial_call=True,
)
def make_timing(n_clicks, els):
    try:
        G = elements_to_graph(els or [])
        df = truth_table(G)
        img = timing_diagram_image(df)
        return html.Div([
            html.H4("Timing-Diagramm (aus der Wahrheitstabelle)"),
            html.Img(src=img, style={"maxWidth": "100%"}),
        ])
    except Exception as e:
        return html.Div(f"Fehler: {e}")

# ---------------------------------------
# Run
# ---------------------------------------
if __name__ == "__main__":
    app.run(debug=True)
