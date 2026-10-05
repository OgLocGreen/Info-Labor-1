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
1. Zeichne die Schaltung mit AND-, OR-, NOT-Gattern.  
2. Wende De Morgan an und forme um.  
3. Vereinfache die resultierende Formel.

**Aufgabe 7:**  
Gegeben: `y = (a ∧ ¬b) ∨ (¬a ∧ b)`  
1. Erkenne die Funktionsart.  
2. Erstelle die Wahrheitstabelle.  
3. Gib eine vereinfachte Beschreibung.

**Aufgabe 8:**  
Vollständige Vereinfachung:

`y = (a ∧ b) ∨ (¬a ∧ c) ∨ (b ∧ c)`

1. Wende das Distributivgesetz an.  
2. Fasse Terme mit Absorption zusammen.  
3. Gib die Endformel an.

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
