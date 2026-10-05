# Übung 04.1 – Funktionen mit Zeigerparametern

> **Info 2 · Übung 04.1** — Aufgabe: [Dynamische Speicherverwaltung (Übung 04.0)](../Aufgaben/04_00_Dynamische_Speicherverwaltung.md), Funktionen mit Zeigerparametern (Übung 04.1) · Lösung: [Funktionen mit Zeigerparametern](../Lösungen/04_01_Pointer_Lösung.md) · Hilfsmittel: [Recap Pointer und Speicherverwaltung](../Hilfsmittel/04_Recap_Pointer_und_Speicherverwaltung.md)

---

_Aufgabe 1 des Laborblatts 4 – Aufgabe 2 (Einfach verkettete Liste) steht in [Übung 05 – Einfach verkettete Liste](../Aufgaben/05_Verkettete_Listen.md)._

## Lernziele

- Funktionen mit Pointer-Parametern definieren und aufrufen
- Werte über Adressen (`&`) und Dereferenzierung (`*`) modifizieren
- Mehrere "Rückgabewerte" über Pointer realisieren (statt `return`)
- Den Unterschied zwischen Wertübergabe (call-by-value) und Adressübergabe (call-by-reference per Pointer) verstehen

## Hintergrund

In C++ können Funktionen nur einen einzigen Wert mit `return` zurückgeben. Wenn eine Funktion mehrere Ergebnisse liefern oder eine übergebene Variable direkt im Aufrufer ändern soll, kann man das mit **Zeigerparametern** lösen. Statt einen Wert zu übergeben, übergibt man die Adresse einer Variablen.

| Aufruf | Bedeutung |
|---|---|
| `funktion(x)` | Kopie von `x` wird übergeben |
| `funktion(&x)` | Adresse von `x` wird übergeben (kann verändert werden) |

In der Funktion greift man mit `*zeiger` auf den Wert hinter der Adresse zu.

## Aufgabenstellung

Schreibe ein Programm zur Verwaltung von Punktzahlen einer Klausur. Implementiere alle Funktionen **ohne Rückgabewert** (`void`) und übergib alle Ausgaben über Pointer-Parameter.

### Teilaufgabe 1.1 — `tausche`

Schreibe eine Funktion `void tausche(int* a, int* b)`, die die Werte zweier Integer-Variablen tauscht.

**Test:**
```cpp
int x = 5, y = 10;
tausche(&x, &y);
// Erwartung: x == 10, y == 5
```

### Teilaufgabe 1.2 — `erhoehePunkte`

Schreibe eine Funktion `void erhoehePunkte(int* punkte, int bonus)`, die zur übergebenen Punktzahl einen Bonuswert addiert.

### Teilaufgabe 1.3 — `findeMinMax`

Schreibe eine Funktion 
```cpp
void findeMinMax(const int* werte, int anzahl, int* min, int* max);
```
die im Array `werte` den Minimal- und Maximalwert findet und die Ergebnisse über die Pointer `min` und `max` zurückliefert.

### Teilaufgabe 1.4 — `berechneStatistik`

Schreibe eine Funktion
```cpp
void berechneStatistik(const int* werte, int anzahl, int* summe, double* durchschnitt);
```
die Summe (Integer) und Durchschnitt (Double) der Werte berechnet und über die Pointer ausgibt.

### Teilaufgabe 1.5 — `ausgabePunkte`

Schreibe eine Funktion `void ausgabePunkte(const int* werte, int anzahl)`, die alle Punktzahlen formatiert auf der Konsole ausgibt.

### Teilaufgabe 1.6 — `main`

Lege im `main` ein Array mit mindestens fünf Punktzahlen an und teste alle deine Funktionen.

## Beispielausgabe

```
Vor dem Tausch: a = 5, b = 10
Nach dem Tausch: a = 10, b = 5

--- Notenverwaltung ---
Punkte: 85 72 91 68 77 
Nach Bonus für Student 1:
Punkte: 90 72 91 68 77 
Minimum: 68, Maximum: 91
Summe: 398, Durchschnitt: 79.60
```

## Bonus (optional)

Schreibe eine Funktion `void sortiere(int* werte, int anzahl)`, die das Array aufsteigend sortiert (z. B. mit Bubble Sort). Nutze dabei deine Funktion `tausche` wieder.

## Hinweise

- `const int*` bedeutet: Die Funktion liest aus dem Array, verändert es aber nicht.
- Vergiss beim Aufruf nicht den `&`-Operator: `findeMinMax(arr, 5, &min, &max);`
- Übersetzung: `g++ -std=c++17 -Wall Aufgabe1_Loesung.cpp -o aufgabe1`
