# Übung 01 – Boolesche Algebra & Grundschaltungen

> **Info 1 · Übung 01** — Aufgabe: Boolesche Algebra · Lösung: [Boolesche Algebra](../Lösungen/01_Boolesche_Algebra_Lösung.md) · Hilfsmittel: [Cheatsheet Boolesche Algebra](../Hilfsmittel/01_Cheatsheet_Boolesche_Algebra.md)

---

## Teil 1 – Grundschaltungen verstehen

**Aufgabe 1:** Zeichne für jeden der folgenden logischen Ausdrücke eine Schaltung mit UND-, ODER- und NICHT-Gattern.  
Ergänze jeweils die Wahrheitstabelle, Schaltzeichen, Timing-Diagramm, Schaltung

a) `y = a ∧ b`  
b) `y = a ∨ b`  
c) `y = ¬a`  
d) `y = a ⊕ b`  
e) `y = ¬(a ∧ b)`  
f) `y = ¬(a ∨ b)`

---

## Teil 2 – Anwendung der Gesetze

**Aufgabe 2:** Wende die Distributivgesetze an.

a) `a ∧ (b ∨ c)` → …  
b) `a ∨ (b ∧ c)` → …

**Aufgabe 3:** Wende die De Morgan’schen Gesetze an.

a) `¬(a ∧ b)`  
b) `¬(a ∨ b)`  
c) `¬(a ∧ (b ∨ c))`

**Aufgabe 4:** Vereinfache die folgenden Ausdrücke.

a) `(a ∧ b) ∨ (a ∧ ¬b)`  
b) `(a ∨ b) ∧ (a ∨ ¬b)`  
c) `(¬a ∨ b) ∧ (a ∨ b)`

*(Hinweis: Verwende Distributiv- und Absorptionsgesetze.)*

**Aufgabe 5:** Ergänze die Dualgesetze.

- Dual zu `a ∧ 1 = a` lautet: …  
- Dual zu `a ∧ 0 = 0` lautet: …

---

## Teil 3 – Kombinierte Aufgaben

**Aufgabe 6:**  
Gegeben: `y = ¬((a ∧ b) ∨ ¬c)`

1. **Schaltung zeichnen:** Zeichne die Schaltung genau so, wie die Formel dasteht, also noch ohne umzuformen. Arbeite von innen nach außen: zuerst `a ∧ b`, dann `¬c`, dann das ODER aus beidem, zum Schluss die äußere Negation. Verwende UND-, ODER- und NICHT-Gatter.  
2. **De Morgan anwenden:** Vor der großen Klammer steht ein `¬`. Löse es mit De Morgan auf. Wiederhole das so lange, bis kein `¬` mehr vor einer Klammer steht, in der `∧` oder `∨` vorkommt. Doppelte Negationen wie `¬¬c` dürfen dabei noch stehen bleiben, die entfernst du in Teilaufgabe 3. Schreibe jeden Zwischenschritt in eine eigene Zeile und notiere daneben das verwendete Gesetz.  
3. **Vereinfachen:** Entferne doppelte Negationen (Doppelnegation: `¬¬p = p`) und gib die Endformel an.  
4. **Kontrolle:** Prüfe mit einer Wahrheitstabelle (`a`, `b`, `c` → 8 Zeilen), dass die gegebene Formel und deine Endformel für alle Eingänge dasselbe `y` liefern.  
5. **In Worten:** Beschreibe in einem Satz, wann `y = 1` ist.

*Tipp zu De Morgan: `¬(p ∨ q) = ¬p ∧ ¬q` und `¬(p ∧ q) = ¬p ∨ ¬q`. Merksatz: „Negation hineinziehen, Zeichen tauschen.“*

**Aufgabe 7:**  
Gegeben: `y = (a ∧ ¬b) ∨ (¬a ∧ b)`  
1. Erkenne die Funktionsart.  
2. Erstelle die Wahrheitstabelle.  
3. Gib eine vereinfachte Beschreibung.

**Aufgabe 8:**  
Vollständige Vereinfachung:

`y = (a ∧ b) ∨ (¬a ∧ c) ∨ (b ∧ c)`

1. **Erst verstehen:** Stelle die Wahrheitstabelle auf (8 Zeilen) mit den Hilfsspalten `a ∧ b`, `¬a ∧ c` und `b ∧ c`. Gibt es eine Zeile, in der **nur** der Term `b ∧ c` eine 1 liefert? Was bedeutet das für diesen Term?  
2. **Mit 1 erweitern:** Das Absorptionsgesetz hilft hier nicht direkt: Damit `b ∧ c` wegfallen könnte, müsste es einen der anderen Terme vollständig enthalten. Es enthält aber weder `a ∧ b` noch `¬a ∧ c`. Der Trick: Ein Term ändert sich nicht, wenn man ihn mit 1 **UND**-verknüpft (`p ∧ 1 = p`, Neutralitätsgesetz), und es gilt `1 = a ∨ ¬a` (Komplementärgesetz). Schreibe also `b ∧ c = b ∧ c ∧ (a ∨ ¬a)`.  
3. **Distributivgesetz:** Multipliziere `b ∧ c ∧ (a ∨ ¬a)` aus.  
4. **Absorption:** Sortiere die Terme so, dass jeder lange Term direkt neben dem kurzen Term steht, der vollständig in ihm enthalten ist. Ordne im langen Term die Variablen so, dass der kurze Term vorne steht. Fasse dann mit dem Absorptionsgesetz `p ∨ (p ∧ q) = p` zusammen.  
5. **Endformel:** Gib die vereinfachte Formel an. Wie viele Gatter sparst du gegenüber der gegebenen Formel? *(Ein ODER mit drei Eingängen zählt als ein Gatter.)*  
6. **In Worten:** Was macht die Schaltung? *(Tipp: Betrachte die Fälle `a = 1` und `a = 0` getrennt.)*

---

## Teil 4 – Zusatz: Wahrheitstabellen & Timing

Ergänze für folgende Ausdrücke jeweils eine Wahrheitstabelle und beschreibe das Timing-Diagramm:

1. `y = a ∧ b`  
2. `y = a ∨ b`  
3. `y = ¬a`  
4. `y = a ⊕ b`  
5. `y = ¬(a ∧ b)`  
6. `y = ¬(a ∨ b)`

---

## Teil 5 – Reflexion

1. Welche Gesetze erlauben das Herausziehen und Hineinziehen von Negationen?  
2. Welche Gesetze sind für Vereinfachungen in Schaltplänen am wichtigsten?  
3. Warum sind NAND- und NOR-Gatter in der Hardwareentwicklung so wichtig?
