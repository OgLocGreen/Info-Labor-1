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
