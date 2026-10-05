# Recap – Rekursion und Bäume

> **Info 2 · Übung 06** — Aufgabe: [Rekursion und binäre Bäume](../Aufgaben/06_Rekursion_und_Bäume.md) · Hilfsmittel: Recap Rekursion und Bäume

---

> **Lesezeit:** ca. 10 Minuten

## 1. Was ist Rekursion?

Eine **rekursive Funktion** ist eine Funktion, die sich selbst aufruft. Statt ein Problem mit einer Schleife zu lösen, zerlegt man es in einen kleineren Fall *desselben Problems* und ruft sich damit erneut auf.

```cpp
int fakultaet(int n) {
    if (n <= 1) return 1;            // Basisfall
    return n * fakultaet(n - 1);     // Rekursionsschritt
}
```

So entsteht eine Aufrufkette, die sich am Ende wieder auflöst:

```
fakultaet(4)
  = 4 * fakultaet(3)
        = 3 * fakultaet(2)
              = 2 * fakultaet(1)
                    = 1                 ← Basisfall stoppt die Rekursion
              = 2 * 1   = 2
        = 3 * 2   = 6
  = 4 * 6   = 24
```

Jede rekursive Funktion braucht **zwei Bestandteile**:

| Teil | Bedeutung |
|---|---|
| **Basisfall** | Liefert direkt einen Wert, **ohne** sich erneut aufzurufen — beendet die Rekursion |
| **Rekursionsschritt** | Reduziert das Problem auf einen kleineren Fall und ruft sich damit auf |

**Was passiert intern?** Jeder Aufruf legt einen eigenen **Stack Frame** auf dem Aufrufstack ab — mit eigenen lokalen Variablen. Erst wenn der Basisfall erreicht ist, werden die Frames in umgekehrter Reihenfolge wieder abgebaut.

**Typische Fehler:**
- Vergessener Basisfall → endlose Rekursion → **Stack Overflow**
- Falscher Rekursionsschritt, der das Problem nicht *kleiner* macht → ebenfalls Stack Overflow

## 2. Wann lohnt sich Rekursion?

Rekursion ist kein Selbstzweck — vieles kann man auch iterativ lösen. Aber: **Wenn die Datenstruktur oder das Problem selbst eine rekursive Struktur hat, ist Rekursion meist klarer und kürzer als jede Schleife.**

| Iterativ | Rekursiv |
|---|---|
| Schleife mit Zähler oder Iterator | Selbstaufruf mit kleinerem Argument |
| Lokale Variable für Zwischenergebnis | Rückgabewert des rekursiven Aufrufs |
| Alle Schritte explizit kontrolliert | Basisfall + Schritt — der Rest ergibt sich |

**Faustregel:** Bei **rekursiv definierten Strukturen** (Bäume, verschachtelte Listen, Dateisysteme, Ausdrücke mit Klammern) ist Rekursion fast immer die natürliche Wahl.

## 3. Was ist ein Baum?

Ein **Baum** ist eine **hierarchische Datenstruktur**. Anders als bei einer verketteten Liste, in der jedes Element genau einen Nachfolger hat, kann ein Knoten in einem Baum **mehrere Kinder** besitzen. Es gibt genau **einen Knoten ohne Eltern** — die **Wurzel** — und Knoten ohne Kinder heißen **Blätter**.

```
                   [ A ]      ← Wurzel (root)
                   /   \
                  ▼     ▼
                [ B ]   [ C ]
                / \       \
               ▼   ▼       ▼
             [ D ] [ E ] [ F ]   ← Blätter (leaves)
```

### Wichtige Begriffe

| Begriff | Bedeutung |
|---|---|
| **Wurzel** (root) | Oberster Knoten, hat keine Eltern |
| **Knoten** (node) | Ein Element des Baumes (Daten + Pointer) |
| **Kind** (child) | Direkt unter einem Knoten hängender Knoten |
| **Eltern** (parent) | Direkt über einem Knoten hängender Knoten |
| **Blatt** (leaf) | Knoten ohne Kinder |
| **Teilbaum** (subtree) | Ein Knoten zusammen mit allen seinen Nachfahren |
| **Tiefe** / **Höhe** | Längster Weg von der Wurzel zu einem Blatt |

### Warum brauchen wir Bäume?

Bäume sind eine der wichtigsten Datenstrukturen überhaupt:

- **Dateisystem:** Ordner enthalten Unterordner und Dateien
- **HTML/XML/JSON:** verschachtelte Dokumente → DOM-Baum
- **Compiler:** abstrakter Syntaxbaum (AST) eines Programms
- **Datenbanken:** B-Bäume verwalten Millionen Datensätze
- **KI:** Entscheidungsbäume, Spielbäume (Schach!)

Der zentrale Vorteil: In **balancierten Suchbäumen** sind Suchen, Einfügen und Löschen in **O(log n)** möglich — eine verkettete Liste braucht dafür **O(n)**.

## 4. Warum passen Rekursion und Bäume so gut zusammen?

Schau dir die Definition eines Baumes an:

> **Ein Baum ist entweder leer (`nullptr`) oder ein Knoten mit zwei Teilbäumen.**

Diese Definition ist **selbst rekursiv** — der Baum ist über sich selbst definiert. Daher ist es nur folgerichtig, dass Algorithmen auf Bäumen ebenfalls rekursiv sind:

- **Basisfall:** Der Teilbaum ist leer (`knoten == nullptr`) → nichts zu tun
- **Rekursionsschritt:** Verarbeite den aktuellen Knoten und rufe dich für die beiden Teilbäume auf

```cpp
void tueEtwas(Node* knoten) {
    if (knoten == nullptr) return;     // Basisfall
    // ... etwas mit knoten->key tun
    tueEtwas(knoten->links);           // Rekursion in linken Teilbaum
    tueEtwas(knoten->rechts);          // Rekursion in rechten Teilbaum
}
```

**Dieses Schema kommt in fast jeder Baum-Methode vor.** Was variiert, ist nur die *Reihenfolge* und *was* du am aktuellen Knoten tust.

## 5. Traversierung — drei Reihenfolgen

Im Gegensatz zu einem Array gibt es bei einem Baum **keine natürliche Reihenfolge** der Knoten. Drei Standard-Traversierungen haben sich etabliert:

```
        [ A ]
        /   \
      [B]   [C]
      / \
    [D] [E]
```

| Verfahren | Reihenfolge | Ausgabe oben |
|---|---|---|
| **Preorder** | Wurzel → links → rechts | A, B, D, E, C |
| **Inorder**  | links → Wurzel → rechts | D, B, E, A, C |
| **Postorder**| links → rechts → Wurzel | D, E, B, C, A |

```cpp
void preorder(Node* knoten) {
    if (knoten == nullptr) return;
    knoten->key.ausgabeName();      // Wurzel
    preorder(knoten->links);        // Linker Teilbaum
    preorder(knoten->rechts);       // Rechter Teilbaum
}
```

**Was sich zwischen den drei Verfahren ändert, ist nur die Reihenfolge dieser drei Zeilen.**

### Wann nutzt man welche Variante?

- **Preorder:** Baum kopieren, Struktur seriell ausgeben (z. B. JSON serialisieren)
- **Inorder:** In einem **binären Suchbaum** liefert sie die Werte **sortiert**
- **Postorder:** Baum **löschen** — man muss die Kinder zuerst freigeben, *dann* den Elternknoten

## 6. Speicherverwaltung mit Rekursion

Knoten werden mit `new` angelegt und liegen auf dem **Heap** — sie müssen mit `delete` wieder freigegeben werden, sonst entsteht ein **Memory Leak**. Da jeder Knoten Pointer auf weitere Knoten enthält, geht das nur **rekursiv** sinnvoll:

```cpp
void loescheBaum(Node* knoten) {
    if (knoten == nullptr) return;
    loescheBaum(knoten->links);   // erst die Kinder
    loescheBaum(knoten->rechts);  // erst die Kinder
    delete knoten;                // dann diesen Knoten
}
```

**Reihenfolge ist entscheidend!** Würdest du `delete knoten;` zuerst aufrufen, hättest du keinen Zugriff mehr auf seine Kinder — du verlierst den ganzen Teilbaum im Speicher. Das ist exakt das **Postorder-Schema**.

## 7. Faustregeln

1. **Basisfall zuerst denken.** Ohne ihn endet keine Rekursion.
2. **Bei rekursiven Datenstrukturen → rekursive Methoden.** Bei Bäumen ist `nullptr` der natürliche Basisfall.
3. **Vertraue dem Selbstaufruf.** Du musst nicht im Kopf die volle Aufrufkette verfolgen — nimm an, der Aufruf für den kleineren Fall „funktioniert schon“ und konzentriere dich auf den aktuellen Schritt.
4. **Auf Papier mitlaufen.** Zeichne den Baum oder schreibe die Aufrufkette auf — Verstehen kommt durch Mit-Simulieren.
5. **Pass auf bei sehr tiefen Strukturen.** Tausende rekursive Aufrufe können den Stack zum Überlaufen bringen.

---

> **Kernidee:** Rekursion ist eine Funktion, die sich selbst aufruft. Bäume sind eine Struktur, die sich über sich selbst definiert. Beides gehört zusammen — wer das eine versteht, versteht auch das andere.
