# Lösung Übung 04.1 – Funktionen mit Zeigerparametern

> **Info 2 · Übung 04.1** — Aufgabe: [Dynamische Speicherverwaltung (Übung 04.0)](../Aufgaben/04_00_Dynamische_Speicherverwaltung.md), [Funktionen mit Zeigerparametern (Übung 04.1)](../Aufgaben/04_01_Pointer.md) · Lösung: Funktionen mit Zeigerparametern · Hilfsmittel: [Recap Pointer und Speicherverwaltung](../Hilfsmittel/04_Recap_Pointer_und_Speicherverwaltung.md)

---

Musterlösung zu [Übung 04.1 – Funktionen mit Zeigerparametern](../Aufgaben/04_01_Pointer.md). Alle Funktionen haben den Rückgabetyp `void` und liefern ihre Ergebnisse ausschließlich über Pointer-Parameter. Der vollständige Code liegt in [Code/04_01_Pointer/](Code/04_01_Pointer/) (`Aufgabe1_Loesung.cpp`) und ist am Ende dieses Dokuments abgedruckt.

## Übersetzen und Ausführen

```bash
cd Code/04_01_Pointer
g++ -std=c++17 -Wall Aufgabe1_Loesung.cpp -o aufgabe1
./aufgabe1
```

---

## Teilaufgabe 1.1 — `tausche`

Die Funktion erhält die Adressen zweier Variablen und greift über `*a` und `*b` direkt auf die Originalvariablen des Aufrufers zu. Die Hilfsvariable `temp` merkt sich den ersten Wert, damit er beim Überschreiben nicht verloren geht. Beim Aufruf wird deshalb der Adressoperator verwendet: `tausche(&a, &b);`.

```cpp
void tausche(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
```

## Teilaufgabe 1.2 — `erhoehePunkte`

`*punkte += bonus` addiert den Bonus direkt auf die Variable, auf die der Zeiger zeigt. Der Bonus selbst wird als Kopie (call-by-value) übergeben, da er nicht verändert werden muss. In `main` wird die Adresse des ersten Array-Elements übergeben (`erhoehePunkte(&punkte[0], 5);`), sodass nur die Punktzahl von Student 1 erhöht wird.

```cpp
void erhoehePunkte(int* punkte, int bonus) {
    *punkte += bonus;
}
```

## Teilaufgabe 1.3 — `findeMinMax`

Minimum und Maximum werden zunächst mit dem ersten Element initialisiert; danach werden alle weiteren Elemente ab Index 1 verglichen. Die Ergebnisse landen über `*min` und `*max` direkt in den Variablen des Aufrufers – so liefert eine `void`-Funktion zwei Ergebnisse. Das Array wird als `const int*` übergeben, weil es nur gelesen wird, und muss mindestens ein Element enthalten.

```cpp
void findeMinMax(const int* werte, int anzahl, int* min, int* max) {
    *min = werte[0];
    *max = werte[0];
    for (int i = 1; i < anzahl; ++i) {
        if (werte[i] < *min) *min = werte[i];
        if (werte[i] > *max) *max = werte[i];
    }
}
```

## Teilaufgabe 1.4 — `berechneStatistik`

`*summe` wird zuerst auf 0 gesetzt und dann in der Schleife aufaddiert. Für den Durchschnitt wird die Summe mit `static_cast<double>` in eine Kommazahl umgewandelt, bevor durch `anzahl` geteilt wird – sonst würde die Ganzzahldivision die Nachkommastellen abschneiden. Die Ausgabe mit zwei Nachkommastellen erfolgt in `main` über `std::fixed` und `std::setprecision(2)` aus `<iomanip>`.

```cpp
void berechneStatistik(const int* werte, int anzahl, int* summe, double* durchschnitt) {
    *summe = 0;
    for (int i = 0; i < anzahl; ++i) {
        *summe += werte[i];
    }
    *durchschnitt = static_cast<double>(*summe) / anzahl;
}
```

## Teilaufgabe 1.5 — `ausgabePunkte`

Die Funktion liest das Array nur (`const int*`) und gibt nach dem Präfix `Punkte: ` alle Werte durch Leerzeichen getrennt aus. Der Zugriff über den Pointer erfolgt wie bei einem Array mit `werte[i]`.

```cpp
void ausgabePunkte(const int* werte, int anzahl) {
    std::cout << "Punkte: ";
    for (int i = 0; i < anzahl; ++i) {
        std::cout << werte[i] << " ";
    }
    std::cout << std::endl;
}
```

## Teilaufgabe 1.6 — `main`

Das Hauptprogramm testet zuerst `tausche` mit zwei einzelnen Variablen und legt dann ein Array mit fünf Punktzahlen an. Anschließend werden nacheinander Bonus, Minimum/Maximum sowie Summe und Durchschnitt berechnet und ausgegeben; für die Ergebnisvariablen (`minWert`, `maxWert`, `summe`, `durchschnitt`) werden jeweils ihre Adressen mit `&` übergeben. Zum Schluss wird die Bonus-Funktion `sortiere` aufgerufen.

```cpp
int main() {
    // --- Test: tausche ---
    int a = 5, b = 10;
    std::cout << "Vor dem Tausch: a = " << a << ", b = " << b << std::endl;
    tausche(&a, &b);
    std::cout << "Nach dem Tausch: a = " << a << ", b = " << b << std::endl;

    std::cout << "\n--- Notenverwaltung ---\n";

    // Punktzahlen für 5 Studenten
    int punkte[] = {85, 72, 91, 68, 77};
    const int anzahl = 5;

    ausgabePunkte(punkte, anzahl);

    // Bonuspunkte für ersten Studenten (+5 Punkte)
    erhoehePunkte(&punkte[0], 5);
    std::cout << "Nach Bonus fuer Student 1:\n";
    ausgabePunkte(punkte, anzahl);

    // Minimum und Maximum
    int minWert, maxWert;
    findeMinMax(punkte, anzahl, &minWert, &maxWert);
    std::cout << "Minimum: " << minWert << ", Maximum: " << maxWert << std::endl;

    // Summe und Durchschnitt
    int summe;
    double durchschnitt;
    berechneStatistik(punkte, anzahl, &summe, &durchschnitt);
    std::cout << "Summe: " << summe
              << ", Durchschnitt: " << std::fixed << std::setprecision(2)
              << durchschnitt << std::endl;

    // --- Bonus: Sortierung ---
    std::cout << "\n--- Bonus: Sortierung ---\n";
    sortiere(punkte, anzahl);
    std::cout << "Sortiert:  ";
    ausgabePunkte(punkte, anzahl);

    return 0;
}
```

### Ausgabe des Programms

Aus dem Code abgeleitet (entspricht der Beispielausgabe der Aufgabe, ergänzt um den Bonus-Teil):

```
Vor dem Tausch: a = 5, b = 10
Nach dem Tausch: a = 10, b = 5

--- Notenverwaltung ---
Punkte: 85 72 91 68 77 
Nach Bonus fuer Student 1:
Punkte: 90 72 91 68 77 
Minimum: 68, Maximum: 91
Summe: 398, Durchschnitt: 79.60

--- Bonus: Sortierung ---
Sortiert:  Punkte: 68 72 77 90 91 
```

## Bonus — `sortiere`

Bubble Sort vergleicht jeweils benachbarte Elemente und vertauscht sie, wenn sie in der falschen Reihenfolge stehen. Nach jedem Durchlauf der äußeren Schleife steht das größte verbleibende Element am Ende, deshalb läuft die innere Schleife nur bis `anzahl - 1 - i`. Zum Vertauschen wird `tausche` aus Teilaufgabe 1.1 wiederverwendet, indem die Adressen der beiden Array-Elemente übergeben werden (`&werte[j]`, `&werte[j + 1]`).

```cpp
void sortiere(int* werte, int anzahl) {
    for (int i = 0; i < anzahl - 1; ++i) {
        for (int j = 0; j < anzahl - 1 - i; ++j) {
            if (werte[j] > werte[j + 1]) {
                tausche(&werte[j], &werte[j + 1]);
            }
        }
    }
}
```

---

## Vollständiger Code

### Aufgabe1_Loesung.cpp

```cpp
/**
 * @file Aufgabe1_Loesung.cpp
 * @brief Musterlösung zu Aufgabe 1: Funktionen mit Zeigerparametern.
 * @details Demonstriert die Verwendung von Pointer-Parametern in Funktionen
 *          ohne Rückgabewert (void). Funktionen modifizieren Werte direkt
 *          über die übergebenen Adressen, statt Werte per return zurückzugeben.
 *
 * Übersetzen mit: g++ -std=c++17 -Wall Aufgabe1_Loesung.cpp -o aufgabe1
 */

#include <iostream>
#include <iomanip>

/**
 * @brief Tauscht die Werte zweier Integer-Variablen über Pointer.
 * @param a Zeiger auf die erste Variable.
 * @param b Zeiger auf die zweite Variable.
 */
void tausche(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * @brief Erhöht eine Punktzahl um einen Bonuswert.
 * @param punkte Zeiger auf die zu modifizierende Punktzahl.
 * @param bonus Wert, der addiert werden soll.
 */
void erhoehePunkte(int* punkte, int bonus) {
    *punkte += bonus;
}

/**
 * @brief Sucht das Minimum und Maximum eines Integer-Arrays.
 * @param werte Zeiger auf das Array (nur lesend).
 * @param anzahl Anzahl der Elemente im Array.
 * @param min Zeiger auf die Variable, in die das Minimum geschrieben wird.
 * @param max Zeiger auf die Variable, in die das Maximum geschrieben wird.
 * @note Das Array muss mindestens ein Element enthalten.
 */
void findeMinMax(const int* werte, int anzahl, int* min, int* max) {
    *min = werte[0];
    *max = werte[0];
    for (int i = 1; i < anzahl; ++i) {
        if (werte[i] < *min) *min = werte[i];
        if (werte[i] > *max) *max = werte[i];
    }
}

/**
 * @brief Berechnet Summe und Durchschnitt eines Integer-Arrays.
 * @param werte Zeiger auf das Array (nur lesend).
 * @param anzahl Anzahl der Elemente.
 * @param summe Zeiger auf die Variable für die Summe.
 * @param durchschnitt Zeiger auf die Variable für den Durchschnitt.
 */
void berechneStatistik(const int* werte, int anzahl, int* summe, double* durchschnitt) {
    *summe = 0;
    for (int i = 0; i < anzahl; ++i) {
        *summe += werte[i];
    }
    *durchschnitt = static_cast<double>(*summe) / anzahl;
}

/**
 * @brief Gibt alle Punktzahlen formatiert auf der Konsole aus.
 * @param werte Zeiger auf das Array.
 * @param anzahl Anzahl der Elemente.
 */
void ausgabePunkte(const int* werte, int anzahl) {
    std::cout << "Punkte: ";
    for (int i = 0; i < anzahl; ++i) {
        std::cout << werte[i] << " ";
    }
    std::cout << std::endl;
}

/**
 * @brief Sortiert ein Array aufsteigend mittels Bubble Sort (Bonus).
 * @param werte Zeiger auf das Array.
 * @param anzahl Anzahl der Elemente.
 * @see tausche
 */
void sortiere(int* werte, int anzahl) {
    for (int i = 0; i < anzahl - 1; ++i) {
        for (int j = 0; j < anzahl - 1 - i; ++j) {
            if (werte[j] > werte[j + 1]) {
                tausche(&werte[j], &werte[j + 1]);
            }
        }
    }
}

/**
 * @brief Hauptprogramm: testet alle Funktionen.
 */
int main() {
    // --- Test: tausche ---
    int a = 5, b = 10;
    std::cout << "Vor dem Tausch: a = " << a << ", b = " << b << std::endl;
    tausche(&a, &b);
    std::cout << "Nach dem Tausch: a = " << a << ", b = " << b << std::endl;

    std::cout << "\n--- Notenverwaltung ---\n";

    // Punktzahlen für 5 Studenten
    int punkte[] = {85, 72, 91, 68, 77};
    const int anzahl = 5;

    ausgabePunkte(punkte, anzahl);

    // Bonuspunkte für ersten Studenten (+5 Punkte)
    erhoehePunkte(&punkte[0], 5);
    std::cout << "Nach Bonus fuer Student 1:\n";
    ausgabePunkte(punkte, anzahl);

    // Minimum und Maximum
    int minWert, maxWert;
    findeMinMax(punkte, anzahl, &minWert, &maxWert);
    std::cout << "Minimum: " << minWert << ", Maximum: " << maxWert << std::endl;

    // Summe und Durchschnitt
    int summe;
    double durchschnitt;
    berechneStatistik(punkte, anzahl, &summe, &durchschnitt);
    std::cout << "Summe: " << summe
              << ", Durchschnitt: " << std::fixed << std::setprecision(2)
              << durchschnitt << std::endl;

    // --- Bonus: Sortierung ---
    std::cout << "\n--- Bonus: Sortierung ---\n";
    sortiere(punkte, anzahl);
    std::cout << "Sortiert:  ";
    ausgabePunkte(punkte, anzahl);

    return 0;
}
```
