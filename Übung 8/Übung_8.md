# Übung 8 – `switch`, Arrays und Funktionen

---

### Aufgabe 1 – Getränkeautomat mit `switch`

Schreiben Sie ein C++-Programm für einen einfachen Getränkeautomaten.

1. Das Programm soll folgendes Menü anzeigen:

   ```text
   Wähle ein Getränk:
   A) Wasser      (1,00 €)
   B) Cola        (1,50 €)
   C) Kaffee      (2,00 €)
   D) Tee         (1,80 €)
   Bitte Auswahl eingeben (1-4):
   ```

2. Der Benutzer gibt eine Zahl von `1` bis `4` ein (als `int`).

3. Verwenden Sie ein `switch`-Statement, um je nach Eingabe auszugeben:

   * bei `1`: „Du hast Wasser gewählt. Preis: 1,00 €“
   * bei `2`: „Du hast Cola gewählt. Preis: 1,50 €“
   * bei `3`: „Du hast Kaffee gewählt. Preis: 2,00 €“
   * bei `4`: „Du hast Tee gewählt. Preis: 1,80 €“
   * bei allen anderen Werten: „Ungültige Auswahl!“

4. Verwenden Sie in jedem `case` ein `break`, sodass nur der passende Block ausgeführt wird.

Optional: Lassen Sie den Benutzer nach der Ausgabe entscheiden, ob er erneut bestellen möchte (`j/n`), und wiederholen Sie das Menü mit einer Schleife, solange `j` eingegeben wird.

5. Für die schnellen bitte Switch Case mit Enumeration lösen.
Beispiel und erklärung zu finden in [w3schools](https://www.w3schools.com/cpp/cpp_enum.asp).

---

### Aufgabe 2 – Wetter-Statistik mit 2D-Array (Temperatur & Luftfeuchtigkeit)

Schreiben Sie ein C++-Programm, das für eine Woche sowohl Temperatur als auch Luftfeuchtigkeit speichert und auswertet.

1. Legen Sie ein **2D-Array** für 7 Tage an, z. B.:

   ```cpp
   // Spalte 0: Temperatur in °C
   // Spalte 1: Luftfeuchtigkeit in %
   double werte[7][2];
   ```

2. Lesen Sie mit einer Schleife (oder zwei verschachtelten Schleifen) für jeden der 7 Tage:

   * die Temperatur in °C
   * die Luftfeuchtigkeit in %

   Beispiel-Dialog:

   ```text
   Tag 1:
   Bitte Temperatur in °C eingeben:
   ...
   Bitte Luftfeuchtigkeit in % eingeben:
   ...
   ```

3. Verwenden Sie anschließend Schleifen, um:

   a) Für alle 7 Tage Temperatur und Luftfeuchtigkeit wieder auszugeben, z. B.:

   ```text
   Tag 1: 21.5 °C, 55 %
   Tag 2: 19.0 °C, 62 %
   ...
   ```

   b) Die **Durchschnittstemperatur** der Woche zu berechnen und auszugeben.

   c) Die **durchschnittliche Luftfeuchtigkeit** der Woche zu berechnen und auszugeben.

   d) Die **Minimum- und Maximumtemperatur** zu bestimmen und auszugeben.

   e) Zu zählen, wie viele Tage über **25 °C** lagen, und diese Anzahl auszugeben.

Hinweise:

* Verwenden Sie ein 2D-Array mit 7 Zeilen und 2 Spalten.
* Nutzen Sie für alle Auswertungen ausschließlich Schleifen (`for` oder `while`), keine fertigen Bibliotheksfunktionen.

---

### Aufgabe 3 – Taschenrechner mit Funktionen in eigener Header- und Cpp-Datei

Erstellen Sie einen einfachen Taschenrechner in C++, der Grundrechenarten mit Funktionen ausführt.
Die Funktionen sollen in eine eigene Header- und Cpp-Datei ausgelagert werden.

#### Dateien

Legen Sie folgende Dateien an:

* `main.cpp`
* `taschenrechner.h`
* `taschenrechner.cpp`

#### a) Header-Datei `taschenrechner.h`

Deklarieren Sie in `taschenrechner.h` mindestens folgende Funktionen:

```cpp
double add(double a, double b);
double sub(double a, double b);
double mul(double a, double b);
double divi(double a, double b); // Division
```

Verwenden Sie Include-Guards, z. B.:

```cpp
#ifndef TASCHENRECHNER_H
#define TASCHENRECHNER_H

// Funktionsprototypen hier

#endif
```

In dieser Datei befindet sich **kein** `main()`.

#### b) Implementierung in `taschenrechner.cpp`

Definieren Sie die Funktionen aus der Header-Datei:

* `add` soll die Summe von `a` und `b` zurückgeben.
* `sub` soll die Differenz von `a` und `b` zurückgeben.
* `mul` soll das Produkt zurückgeben.
* `divi` soll den Quotienten berechnen.
  Bei Division durch 0 soll eine Fehlermeldung ausgegeben und z. B. `0` zurückgegeben werden.

#### c) `main.cpp` – Menü und Bedienung

In `main.cpp`:

1. Binden Sie die Header-Datei ein:

   ```cpp
   #include "taschenrechner.h"
   ```

2. Erstellen Sie ein Menü:

   ```text
   Taschenrechner:
   1) Addition
   2) Subtraktion
   3) Multiplikation
   4) Division
   0) Beenden
   Bitte Auswahl eingeben:
   ```

3. Solange die Auswahl **nicht 0** ist:

   * Lassen Sie den Benutzer zwei Zahlen (`double a, b`) eingeben.
   * Verwenden Sie ein `switch`, um abhängig von der Auswahl die passende Funktion (`add`, `sub`, `mul`, `divi`) aufzurufen.
   * Geben Sie das Ergebnis aus.
   * Zeigen Sie anschließend das Menü erneut an.

