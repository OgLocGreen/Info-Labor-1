# Übung 09 – Mathematische Formeln in C++

> **Info 2 · Übung 09** — Aufgabe: Mathematische Formeln in C++

---

**Algorithmen & Datenstrukturen (2. Semester)** · Labor, 90 Min · `g++ -std=c++17 -Wall -o block09 block09.cpp`

Ihr wertet die Daten eines Temperatursensors aus: Statistik, Kennlinien-Tabelle, Kontrollsummen,
Numerik. Keine neuen Sprachfeatures – heute geht es ums **Übersetzen von Formeln in Code**.

## Hinweise

- Eine Datei genügt: Kopiert den **Testrahmen** (unten) als `block09.cpp` und implementiert die Funktionen.
- doubles **nie** mit `==` vergleichen → `fastGleich(a, b, toleranz)` aus dem Testrahmen nutzen. Ganzzahlen: `==` ist okay.
- `<iomanip>`: `std::fixed` und `std::setprecision(k)` wirken dauerhaft, `std::setw(k)` nur für die **nächste** Ausgabe.
- Jede Funktion bekommt einen Doxygen-Kommentar: `@brief`, `@param` (mit Einheit!), `@return`, ggf. `@pre` – Vorlage: `fastGleich`.

| Zeit      | Aufgabe                      | Schwierigkeit |
|-----------|------------------------------|:-------------:|
| 00–15 Min | 1 – Statistik                | ★             |
| 15–35 Min | 2 – Wertetabelle             | ★★            |
| 35–55 Min | 3 – Summen                   | ★★            |
| 55–85 Min | 4 – Numerik (4a + 4b)        | ★★★           |
| 85–90 Min | Puffer / Doxygen prüfen      | –             |

Bonusaufgaben (★ bis ★★★): für Schnelle oder zu Hause.

---

## Aufgabe 1 (★) – Statistik einer Messreihe

```cpp
const std::vector<double> messung = {21.5, 22.0, 21.8, 23.1, 22.7, 21.9, 22.4, 22.2};
```

```
Mittelwert = ( x_1 + x_2 + ... + x_n ) / n
```

**a)** `double mittelwert(const std::vector<double>& werte);`  
**b)** `double minimum  (const std::vector<double>& werte);`  
**c)** `double maximum  (const std::vector<double>& werte);`

*(jeweils `@pre`: `werte` ist nicht leer)*

⚠️ **Fallstricke**

- Minimum **nicht** mit `0.0` initialisieren → mit `werte[0]` starten, Schleife ab Index 1.
- Bei einem `vector<int>` würde `summe / anzahl` ganzzahlig teilen (`7 / 2 == 3`) → vorher nach `double` wandeln.
- Leerer Vektor: Vorbedingung mit `@pre` dokumentieren, optional `assert(!werte.empty());`

**Bonus ★** – `spannweite` = Maximum − Minimum. *(Kontrolle: 1.6)*  
**Bonus ★★** – `standardabweichung`: `s = sqrt( 1/(n−1) · Σ (x_i − Mittelwert)² )`, braucht `std::sqrt` aus `<cmath>`. *(Kontrolle: ≈ 0.5182)*

---

## Aufgabe 2 (★★) – Sensorkennlinie als Wertetabelle

Der Sensor liefert eine Spannung `U`, das Datenblatt die Kennlinie:

```
T(U) = m · U + c          m = 25.0 °C/V (Steigung),   c = −5.0 °C (Achsenabschnitt)
```

**a)** `double kennlinie(double u, double m, double c);`

**b)** `void wertetabelle(double m, double c, double uStart, double uEnde, double schritt);`
gibt pro Schritt eine Zeile aus. `wertetabelle(25.0, -5.0, 0.0, 2.0, 0.25)` muss **exakt** liefern:

```
   U [V]    T [°C]
------------------
    0.00     -5.00
    0.25      1.25
    0.50      7.50
    0.75     13.75
    1.00     20.00
    1.25     26.25
    1.50     32.50
    1.75     38.75
    2.00     45.00
```

Format: `std::fixed << std::setprecision(2)`, Spalten mit `setw(8)` / `setw(10)`.

**Tipp (robuste Schleife):** mit Ganzzahl-Index zählen, `u` jedes Mal frisch berechnen:

```
anzahlSchritte = RUNDE( (uEnde − uStart) / schritt )      // std::round aus <cmath>!
FÜR i = 0 BIS anzahlSchritte:                             // einschließlich!
    u = uStart + i · schritt
```

**c)** Experiment: Lasst testweise die naive Variante `for (double u = 0.0; u <= 1.0; u += 0.1)`
laufen. Wie viele Zeilen erscheinen – und warum fehlt eine? *(Antwort als Kommentar in den Code.)*

⚠️ **Fallstricke**

- double-Schleifenzähler sammeln Rundungsfehler an (siehe c). Dass 0.25 zufällig exakt wäre (= 2⁻²), ist kein Freibrief.
- `(uEnde − uStart) / schritt` ergibt gern `9.999…` → ohne `std::round` fehlt die letzte Zeile.
- `setprecision` ohne `fixed` zählt gültige Ziffern statt Nachkommastellen.

**Bonus ★** – `m`, `c`, `uStart`, `uEnde`, `schritt` per `std::cin` einlesen. Prüfen: `schritt > 0` und `uEnde > uStart`, sonst Fehlermeldung.

---

## Aufgabe 3 (★★) – Summen: Gauß & π

```
1 + 2 + 3 + ... + n  =  n · (n + 1) / 2
```

**a)** `unsigned long long summeIterativ(unsigned int n);` *(Schleife)*  
**b)** `unsigned long long summeFormel(unsigned int n);` *(geschlossene Formel)*  
Der Testrahmen lässt beide für n = 0 … 50 gegeneinander antreten.

**c)** Papiersimulation: Füllt die Tabelle für `summeIterativ(5)` aus. *(Kontrolle: 5 · 6 / 2 = 15)*

| Durchlauf | `i` | `summe` vorher | `summe` nachher |
|:---------:|:---:|:--------------:|:---------------:|
| 1         | 1   | 0              | 1               |
| 2         |     |                |                 |
| 3         |     |                |                 |
| 4         |     |                |                 |
| 5         |     |                |                 |

**d)** Notiert die Laufzeit beider Varianten in Landau-Notation als Kommentar im Code. *(Brücke zu Übung 07/08, vgl. [Übung 08 – Suchalgorithmen](../Aufgaben/08_Suchalgorithmen.md))*

⚠️ **Fallstricke**

- Überlauf: `summeFormel(100000)` = 5.000.050.000 sprengt `int` – und das Zwischenprodukt `n * (n + 1)`
  sprengt sogar `unsigned int`. Lösung: `static_cast<unsigned long long>(n) * (n + 1) / 2`.
  Der Test im Rahmen deckt genau das auf.
- `(n / 2) * (n + 1)` ist für ungerade n falsch (ganzzahlige Division!). `n * (n + 1) / 2` geht immer,
  weil n · (n+1) stets gerade ist.

**Bonus ★★ – Leibniz-Reihe für π:**

```
π/4  =  1 − 1/3 + 1/5 − 1/7 + 1/9 − ...
```

`double piLeibniz(unsigned int anzahlGlieder);` – in `main()` für wachsende n aufrufen:

```
n =      1:  pi ≈ 4.000000
n =     10:  pi ≈ 3.041840
n =    100:  pi ≈ 3.131593
n =   1000:  pi ≈ 3.140593
n =  10000:  pi ≈ 3.141493
```

Der Fehler ist ≈ 1/n – Konvergenz kann langsam sein.  
⚠️ `1 / (2*k + 1)` ist ganzzahlig ab dem zweiten Glied 0 → `1.0 / (2.0*k + 1.0)` schreiben.

---

## Aufgabe 4 (★★★) – Numerik-Werkstatt

Grundidee aller drei Stufen: Wo die Mathematik „unendlich klein“ sagt, sagt der Rechner **„klein genug“**.  
**4a und 4b sind Pflicht, 4c ist Bonus.** Testfunktion (im Testrahmen vorgegeben):

```cpp
double f(double x) { return x * x; }     //  f'(x) = 2x   und   ∫₀¹ f(x) dx = 1/3
```

### 4a – Numerische Ableitung

```
f'(x)  ≈  ( f(x + h) − f(x) ) / h        (Vorwärtsdifferenz: Sekante statt Tangente)
```

**a)** `double ableitungVorwaerts(double x, double h);`  
*(Kontrolle: f′(2) = 4 – mit h = 0.001 kommt ≈ 4.001 heraus.)*

**Bonus ★★** – zentrale Differenz `( f(x+h) − f(x−h) ) / (2·h)` als `ableitungZentral`.
Vergleicht die Fehler beider Varianten für h = 0.1 / 0.01 / 0.001. Für x² ist die zentrale
Differenz sogar exakt – warum?

### 4b – Numerische Integration: Trapezregel

```
 f(x)
  ^                        __--●
  |                  __--●*    |
  |            __--●*    |     |      Fläche unter f
  |       ●**--    |     |     |      ≈ Summe der Trapezflächen
  |       |        |     |     |
  +-------+--------+-----+-----+-->  x
          a       a+h   a+2h   b
```

```
∫ₐᵇ f(x) dx  ≈  h · [ f(a)/2 + f(a+h) + ... + f(b−h) + f(b)/2 ]        h = (b − a) / n
```

**b)** `double trapezregel(double a, double b, unsigned int n);`  
*(Kontrolle: ∫₀¹ x² dx = 1/3. Fehler bei n = 10: ≈ 0.0017, bei n = 1000: ≈ 0.00000017 → Fehler ~ h².)*

**Bonus ★★★** *(Brücke zu [Übung 04 – Pointer](../Aufgaben/04_01_Pointer.md))* – Funktionszeiger statt festem `f`:  
`double trapezregel(double (*funktion)(double), double a, double b, unsigned int n);`

### 4c – Bonus ★★★: Euler-Verfahren (Kondensator-Entladung)

Ein Kondensator entlädt sich über einen Widerstand (RC-Glied). Die Physik liefert eine DGL:

```
U'(t) = − U(t) / (R·C),   U(0) = U0          exakt:  U(t) = U0 · e^( −t / (R·C) )

Euler-Schritt:   U_neu = U_alt + h · U'(t_alt)  =  U_alt · ( 1 − h / (R·C) )
```

**a)** Papiersimulation: U₀ = 10 V, R·C = 1 s, h = 0.5 s *(absichtlich grob)* – rechnet
3 Euler-Schritte von Hand. *(Kontrolle: U₃ = 1.25 V; exakt wäre U(1.5 s) ≈ 2.23 V → h viel zu groß!)*

**b)** `double eulerEntladung(double u0, double rc, double tEnde, double h);`  
*Tipp: Schrittanzahl runden, mit Ganzzahl-Index zählen – gleicher Trick wie in Aufgabe 2.*

**c)** Ausgabe für h = 0.01 (Aufruf in einer Schleife für tEnde = 0, 1, …, 5):

```
  t [s]   U_Euler [V]   U_exakt [V]   Fehler [V]
   0.00       10.0000       10.0000       0.0000
   1.00        3.6603        3.6788        0.0185
   2.00        1.3398        1.3534        0.0136
   3.00        0.4904        0.4979        0.0075
   4.00        0.1795        0.1832        0.0037
   5.00        0.0657        0.0674        0.0017
```

h durch 10 → Fehler durch 10: Euler ist 1. Ordnung *(die Trapezregel: 2. Ordnung)*.

⚠️ **Fallstricke (ganz Aufgabe 4)**

- Toleranz von `fastGleich` zur Schrittweite passend wählen (grobes n → großzügige Toleranz, siehe Testrahmen).
- Trapezregel: `f(a)` und `f(b)` nur **halb** zählen – die Schleife läuft von 1 bis n − 1.
- h-Dilemma: zu groß → Verfahrensfehler; extrem klein (≈ 1e-15) → Auslöschung. „Klein genug“ ≠ „so klein wie möglich“.

---

## Testrahmen: `block09.cpp`

Als Startpunkt kopieren, Funktionen implementieren. Noch fehlende Blöcke in `main()`
vorübergehend auskommentieren; Bonus-Tests einkommentieren, sobald implementiert.

```cpp
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

/**
 * @brief Vergleicht zwei double-Werte mit Toleranz.
 *        (doubles wegen Rundungsfehlern NIE mit == vergleichen!)
 * @param a        erster Wert
 * @param b        zweiter Wert
 * @param toleranz erlaubte Abweichung
 * @return true, falls |a - b| < toleranz
 */
bool fastGleich(double a, double b, double toleranz = 1e-9) {
    return std::fabs(a - b) < toleranz;
}

/**
 * @brief Testfunktion für Aufgabe 4: f(x) = x²  (vorgegeben, nicht ändern)
 * @param x Stelle, an der ausgewertet wird
 * @return Funktionswert x²
 */
double f(double x) {
    return x * x;
}

// ===== Prototypen – diese Funktionen implementiert IHR =====================

// Aufgabe 1
double mittelwert(const std::vector<double>& werte);
double minimum(const std::vector<double>& werte);
double maximum(const std::vector<double>& werte);
// Bonus Aufgabe 1
// double spannweite(const std::vector<double>& werte);
// double standardabweichung(const std::vector<double>& werte);

// Aufgabe 2
double kennlinie(double u, double m, double c);
void wertetabelle(double m, double c, double uStart, double uEnde, double schritt);

// Aufgabe 3
unsigned long long summeIterativ(unsigned int n);
unsigned long long summeFormel(unsigned int n);
// Bonus Aufgabe 3
// double piLeibniz(unsigned int anzahlGlieder);

// Aufgabe 4
double ableitungVorwaerts(double x, double h);
double trapezregel(double a, double b, unsigned int n);
// Bonus Aufgabe 4
// double ableitungZentral(double x, double h);
// double eulerEntladung(double u0, double rc, double tEnde, double h);

// ===========================================================================

int main() {
    const std::vector<double> messung = {21.5, 22.0, 21.8, 23.1,
                                         22.7, 21.9, 22.4, 22.2};

    // ---------- Aufgabe 1: Statistik ----------
    assert(fastGleich(mittelwert(messung), 22.2));
    assert(fastGleich(minimum(messung),    21.5));
    assert(fastGleich(maximum(messung),    23.1));
    // Bonus:
    // assert(fastGleich(spannweite(messung), 1.6));
    // assert(fastGleich(standardabweichung(messung), 0.5182, 1e-3));
    std::cout << "Aufgabe 1: alle Tests bestanden\n";

    // ---------- Aufgabe 2: Kennlinie & Wertetabelle ----------
    assert(fastGleich(kennlinie(0.0, 25.0, -5.0), -5.0));
    assert(fastGleich(kennlinie(1.0, 25.0, -5.0), 20.0));
    assert(fastGleich(kennlinie(2.0, 25.0, -5.0), 45.0));
    std::cout << "Aufgabe 2: alle Tests bestanden\n\n";

    wertetabelle(25.0, -5.0, 0.0, 2.0, 0.25);   // Sichtpruefung gegen Soll-Ausgabe!
    std::cout << "\n";

    // ---------- Aufgabe 3: Summen ----------
    assert(summeIterativ(0)   == 0);            // Ganzzahlen: == ist hier erlaubt!
    assert(summeIterativ(1)   == 1);
    assert(summeIterativ(100) == 5050);
    for (unsigned int n = 0; n <= 50; ++n) {
        assert(summeIterativ(n) == summeFormel(n));
    }
    assert(summeFormel(100000) == 5000050000ULL);   // passt NICHT in einen int!
    // Bonus (Fehler nach n Gliedern: etwa 1/n):
    // assert(fastGleich(piLeibniz(10000), 3.141592653589793, 1e-3));
    std::cout << "Aufgabe 3: alle Tests bestanden\n";

    // ---------- Aufgabe 4: Numerik ----------
    assert(fastGleich(ableitungVorwaerts(2.0, 0.001), 4.0, 0.01));
    assert(fastGleich(trapezregel(0.0, 1.0, 10),   1.0 / 3.0, 1e-2));
    assert(fastGleich(trapezregel(0.0, 1.0, 1000), 1.0 / 3.0, 1e-6));
    // Bonus:
    // assert(fastGleich(ableitungZentral(2.0, 0.001), 4.0, 1e-6));
    // assert(fastGleich(eulerEntladung(10.0, 1.0, 1.0, 0.01), 3.6603, 1e-3));
    std::cout << "Aufgabe 4: alle Tests bestanden\n";

    std::cout << "\nAlle Tests bestanden!\n";
    return 0;
}
```

---

## Checkliste vor der Abgabe

- [ ] Kompiliert mit `g++ -std=c++17 -Wall` **ohne Warnungen**
- [ ] Alle `assert`-Tests laufen durch
- [ ] Wertetabelle stimmt mit der Soll-Ausgabe überein – **alle 9 Zeilen**, auch `2.00`
- [ ] Jede Funktion hat einen Doxygen-Kommentar (`@brief`, `@param` mit Einheit, `@return`, ggf. `@pre`)
- [ ] Nirgends doubles mit `==` verglichen
