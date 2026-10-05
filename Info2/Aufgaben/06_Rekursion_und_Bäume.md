# Übung 06 – Rekursion und binäre Bäume

> **Info 2 · Übung 06** — Aufgabe: Rekursion und binäre Bäume · Hilfsmittel: [Recap Rekursion und Bäume](../Hilfsmittel/06_Recap_Rekursion_und_Bäume.md)

---

## Lernziele

- **Rekursive Funktionen** entwerfen und korrekt implementieren (Basisfall + Rekursionsschritt)
- Den **Aufrufstack** bei rekursiven Aufrufen nachvollziehen können
- Eine **hierarchische Datenstruktur** (binärer Baum) selbst aufbauen
- Verstehen, **warum Bäume und Rekursion natürlich zusammengehören**
- Klassen über mehrere Dateien (`.h` / `.cpp`) modular organisieren
- Rekursive **Traversierungsverfahren** (Preorder, Inorder) implementieren
- Speicher dynamisch verwalten und (rekursiv) wieder freigeben

## Hintergrund

Eine **rekursive Funktion** ist eine Funktion, die sich selbst aufruft. Sie braucht immer zwei Bestandteile:

1. einen **Basisfall**, in dem sie *ohne weiteren Aufruf* ein Ergebnis liefert,
2. einen **Rekursionsschritt**, der das Problem auf einen kleineren Fall reduziert.

Ein **binärer Baum** ist eine verzweigte Datenstruktur, in der jeder Knoten höchstens zwei Kinder hat. Da ein Baum **selbst rekursiv definiert** ist (ein Baum ist entweder leer oder ein Knoten mit zwei Teilbäumen), sind fast alle Algorithmen auf Bäumen ebenfalls rekursiv.

```
                    [ Max Müller ]
                    /            \
                   ▼              ▼
          [ Martin Müller ]   [ Marta Maier ]
           /            \      /            \
          ▼              ▼    ▼              ▼
    [Holger M.]   [Hannah M.] [Michael M.] [Michaela M.]
```

In dieser Aufgabe übst du Rekursion zuerst an drei kleinen Beispielen und wendest sie anschließend auf einen Stammbaum an.

## Aufgabenstellung

Die Aufgabe besteht aus **zwei Teilen**:
- **Teil A — Aufwärmen mit Rekursion** (≈ 30 min)
- **Teil B — Stammbaum als binärer Baum** (≈ 45 min)

---

## Teil A — Aufwärmen mit Rekursion (≈ 30 min)

### Wie funktioniert eine rekursive Funktion?

Eine **rekursive Funktion** ist nichts anderes als eine Funktion, die sich **selbst aufruft**. Das klingt zunächst merkwürdig — aber wenn man zwei Dinge richtig macht, funktioniert es problemlos:

1. **Basisfall** — eine Bedingung, bei der die Funktion *ohne weiteren Aufruf* zurückkehrt.
2. **Rekursionsschritt** — die Funktion ruft sich mit einem **kleineren** oder **einfacheren** Argument selbst auf.

Ohne Basisfall würde sich die Funktion endlos selbst aufrufen, bis der Speicher voll ist (Stack Overflow). Der Basisfall ist also der **Notausgang** aus der Rekursion.

#### Vorgemachtes Beispiel: Eine Funktion, die rückwärts zählt

```cpp
void countdown(int n) {
    if (n <= 0) return;          // Basisfall: bei 0 ist Schluss
    std::cout << n << '\n';      // erst den aktuellen Wert ausgeben
    countdown(n - 1);            // dann sich selbst mit (n-1) aufrufen
}
```

Der Aufruf `countdown(3)` läuft so ab:

```
countdown(3)  → gibt "3" aus, ruft countdown(2)
  countdown(2)  → gibt "2" aus, ruft countdown(1)
    countdown(1)  → gibt "1" aus, ruft countdown(0)
      countdown(0)  → Basisfall, kehrt sofort zurück
    kehrt zurück
  kehrt zurück
kehrt zurück
```

Ausgabe: `3 2 1` — genauso wie eine `for`-Schleife, nur ganz ohne Schleife.

---

### Aufgabe A.1 — Countdown nachvollziehen

Lege eine Datei `rekursion.cpp` an. Tippe die Funktion `countdown` aus dem Beispiel oben ab und teste sie in `main()` mit `countdown(5);`.

**Frage zum Nachdenken** (kein zusätzlicher Code nötig):
Was passiert, wenn du den Basisfall (`if (n <= 0) return;`) weglässt? Überleg dir die Antwort und probier es vorsichtig aus — das Programm wird abstürzen.

> Ziel dieser Mini-Aufgabe ist nur, dass du **siehst**, wie eine rekursive Funktion abläuft, bevor du selbst eine schreibst.

---

### Aufgabe A.2 — Fakultät

Die Fakultät einer Zahl *n* ist definiert als:

```
n! = n * (n-1) * (n-2) * ... * 1     für n ≥ 1
0! = 1
```

Die **rekursive Definition** lautet:

```
fakultaet(0) = 1                              ← Basisfall
fakultaet(n) = n * fakultaet(n-1)             ← Rekursionsschritt
```

Schreibe folgende Funktion:

```cpp
int fakultaet(int n);
```

**Aufrufkette für `fakultaet(4)`** (zur Selbstkontrolle):

```
fakultaet(4) = 4 * fakultaet(3)
             = 4 * 3 * fakultaet(2)
             = 4 * 3 * 2 * fakultaet(1)
             = 4 * 3 * 2 * 1 * fakultaet(0)
             = 4 * 3 * 2 * 1 * 1
             = 24
```

Teste mit:

```cpp
for (int i = 0; i <= 6; ++i) {
    std::cout << "fakultaet(" << i << ") = " << fakultaet(i) << '\n';
}
```

---

### Aufgabe A.3 — Fibonacci-Folge

Die Fibonacci-Folge ist eine berühmte Zahlenfolge, in der jede Zahl die Summe der beiden vorherigen ist:

```
0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, ...
```

Rekursive Definition:

```
fib(0) = 0                              ← Basisfall 1
fib(1) = 1                              ← Basisfall 2
fib(n) = fib(n-1) + fib(n-2)            ← Rekursionsschritt mit ZWEI Aufrufen
```

Schreibe:

```cpp
int fibonacci(int n);
```

**Wichtige Beobachtung:** Diese Funktion ruft sich **zweimal** selbst auf. Genau dieses Schema mit zwei Selbstaufrufen wirst du gleich beim Baum-Traversal wiedersehen — dort einmal für den Vater-Teilbaum und einmal für den Mutter-Teilbaum!

Teste mit:

```cpp
for (int i = 0; i <= 9; ++i) {
    std::cout << "fibonacci(" << i << ") = " << fibonacci(i) << '\n';
}
```

---

## Teil B — Binärer Baum: Stammbaum (≈ 45 min)

Implementiere ein Programm, das den oben gezeigten Stammbaum aufbaut und mittels zweier rekursiver Traversierungsverfahren ausgibt. Verteile dein Projekt auf folgende Dateien:

| Datei | Inhalt |
|---|---|
| `Person.h` / `Person.cpp` | Klasse `Person` mit Vor- und Nachname |
| `Node.h` / `Node.cpp` | Klasse `Node` (ein Knoten im Baum) |
| `main.cpp` | Aufbau des Stammbaums + Traversierung |

Vergiss in jeder Header-Datei den **Include-Guard** (`#ifndef … #define … #endif`) nicht.

### Teilaufgabe B.1 — Klasse `Person`

- Zwei **private** Attribute: `vorname` und `nachname` (jeweils `std::string`)
- Ein **Konstruktor**, der beide Attribute initialisiert
- **get/set-Methoden** für beide Attribute
- Eine Methode `void ausgabeName() const`, die den vollständigen Namen ausgibt (z. B. `"Max Müller"`)

### Teilaufgabe B.2 — Klasse `Node`

- Ein Attribut `key` vom Typ `Person`
- Zwei Pointer-Attribute auf `Node`: `vater` und `mutter`
- Ein **Konstruktor**, der eine `Person` als Übergabeparameter erhält und im Attribut `key` ablegt. Beide Pointer werden mit `nullptr` initialisiert.

```cpp
class Node {
private:
    Person key;
    Node* vater;
    Node* mutter;
public:
    Node(Person p);
    // ... getter/setter
};
```

> **Hinweis:** Die Pointer `vater` und `mutter` dürfen für diese Aufgabe auch **public** sein, falls dir das das Aufbauen des Baums in `main.cpp` erleichtert.

### Teilaufgabe B.3 — Stammbaum aufbauen

Erzeuge in `main.cpp` den oben dargestellten Stammbaum dynamisch mit `new`. Du brauchst **7 Knoten**:

- Wurzel: **Max Müller**
- Vater von Max: **Martin Müller**, Mutter von Max: **Marta Maier**
- Vater von Martin: **Holger Müller**, Mutter von Martin: **Hannah Müller**
- Vater von Marta: **Michael Maier**, Mutter von Marta: **Michaela Maier**

Verbinde die Knoten korrekt über ihre `vater`- und `mutter`-Pointer.

### Teilaufgabe B.4 — Rekursive Traversierung

Implementiere zwei freie Funktionen, die rekursiv durch den Baum laufen:

| Funktion | Reihenfolge |
|---|---|
| `void preorder(Node* knoten)` | **Wurzel → Vater-Teilbaum → Mutter-Teilbaum** |
| `void inorder(Node* knoten)` | **Vater-Teilbaum → Wurzel → Mutter-Teilbaum** |

Erkenne wieder das **Schema von Teil A**: Eine rekursive Funktion braucht immer einen Basisfall und einen Rekursionsschritt.

```cpp
void preorder(Node* knoten) {
    if (knoten == nullptr) return;          // Basisfall
    // 1. Aktuellen Knoten ausgeben
    // 2. Rekursiv in den Vater-Teilbaum
    // 3. Rekursiv in den Mutter-Teilbaum
}
```

**Was sich zwischen Preorder und Inorder ändert, ist nur die Reihenfolge dieser drei Zeilen.**

## Beispielausgabe

```
=== Teil A: Rekursion ===
countdown(5): 5 4 3 2 1
fakultaet(5) = 120
fibonacci(7) = 13

=== Teil B: Preorder ===
Max Müller
Martin Müller
Holger Müller
Hannah Müller
Marta Maier
Michael Maier
Michaela Maier

=== Teil B: Inorder ===
Holger Müller
Martin Müller
Hannah Müller
Max Müller
Michael Maier
Marta Maier
Michaela Maier
```

## Bonus (optional)

1. **`int summeZiffern(int n)`** — Berechnet rekursiv die Quersumme einer Zahl (z. B. `1234 → 10`). Tipp: `n % 10` ist die letzte Ziffer, `n / 10` schneidet sie ab.
2. **`int potenz(int basis, int exponent)`** — Berechnet rekursiv `basis^exponent` ohne `pow()`.
3. **`void postorder(Node* knoten)`** — Implementiere zusätzlich die Postorder-Traversierung (Vater-Teilbaum → Mutter-Teilbaum → Wurzel).
4. **`int anzahlKnoten(Node* knoten)`** — Gibt rekursiv die Gesamtzahl der Knoten im (Teil-)Baum zurück.
5. **`int tiefe(Node* knoten)`** — Gibt die Tiefe des Baumes zurück (Wurzel hat Tiefe 1, leerer Baum hat Tiefe 0).
6. **`Node* sucheNachname(Node* knoten, const std::string& nachname)`** — Sucht rekursiv den ersten Knoten mit diesem Nachnamen und gibt ihn zurück (oder `nullptr`).
7. **Speicher freigeben:** Implementiere `void loescheBaum(Node* knoten)`, die den gesamten Baum rekursiv mit `delete` freigibt. **Knifflige Frage:** In welcher Reihenfolge musst du löschen — vor oder nach den Rekursionsaufrufen? **Tipp:** Postorder!

## Hinweise

- **Basisfall zuerst denken!** Ohne `if (knoten == nullptr) return;` (bzw. `if (n <= 0) return …;` bei den Zahlenfunktionen) läufst du in eine endlose Rekursion oder einen Segmentation Fault.
- **Vertraue der Rekursion:** Du musst dir nicht alle Aufrufe gleichzeitig im Kopf merken. Nimm an, der rekursive Aufruf für den kleineren Fall „funktioniert schon“ — und konzentriere dich nur auf den aktuellen Schritt.
- **Reihenfolge der Knoten-Erzeugung:** Es ist meist einfacher, **zuerst die Blätter** anzulegen und dann die inneren Knoten — so kannst du beim Konstruieren der Eltern direkt die schon existierenden Pointer übergeben.
- Übersetzung Teil A: `g++ -std=c++17 -Wall rekursion.cpp -o rekursion`
- Übersetzung Teil B: `g++ -std=c++17 -Wall Person.cpp Node.cpp main.cpp -o stammbaum`

## Tipp zum Debuggen

Bei einer rekursiven Funktion hilft es, **die Aufrufkette auf Papier mitzuschreiben**. Bei `fakultaet(4)` z. B.:

```
fakultaet(4) = 4 * fakultaet(3)
             = 4 * 3 * fakultaet(2)
             = 4 * 3 * 2 * fakultaet(1)
             = 4 * 3 * 2 * 1 = 24
```

Beim Baum machst du dasselbe — zeichne den Baum auf Papier und führe die Traversierung mit dem Stift mit. Bei Preorder schreibst du den Namen auf, **bevor** du in einen Teilbaum „hinabsteigst“, bei Inorder erst, **wenn du aus dem Vater-Teilbaum zurückkommst**. Wenn dein Programm dieselbe Reihenfolge produziert wie deine Hand-Simulation, stimmt deine Rekursion.
