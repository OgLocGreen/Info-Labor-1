# Übung 08 – Suchalgorithmen: Lineare Suche, Binäre Suche & Interpolationssuche

> **Info 2 · Übung 08** — Aufgabe: Suchalgorithmen

---

**Modul:** Algorithmen & Datenstrukturen  
**Sprache:** C++17 (Übersetzung mit `g++ -std=c++17 -Wall`)  
**Bearbeitungszeit:** ca. 90 Minuten (Pflichtteil) + Bonus

---

## Lernziele

Nach dieser Übung könnt ihr …

- die **lineare Suche** implementieren und ihren Aufwand einschätzen,
- die **binäre Suche** auf einem sortierten Array korrekt umsetzen (inkl. der klassischen Fallstricke),
- die **Interpolationssuche** als Verfeinerung der binären Suche verstehen und implementieren,
- begründen, **warum** die jeweilige Voraussetzung (sortiert / gleichverteilt) gebraucht wird,
- den Aufwand der drei Verfahren in der Landau-Notation einordnen und experimentell vergleichen.

---

## Vorbereitung

Legt eine Datei `suche.cpp` an. Das Grundgerüst mit `main()` und den Tests findet ihr ganz unten unter **„Test-Gerüst“** — kopiert es euch zu Beginn hinein. Eure Aufgabe ist es, die drei Funktionen `lineareSuche`, `binaereSuche` und `interpolationsSuche` zu füllen.

**Konvention für alle Funktionen:**
Gesucht wird in einem aufsteigend sortierten `std::vector<int>` (außer bei der linearen Suche). Rückgabewert ist der **Index** des gefundenen Elements oder **`-1`**, falls der Wert nicht vorkommt.

```cpp
int lineareSuche(const std::vector<int>& daten, int schluessel);
int binaereSuche(const std::vector<int>& daten, int schluessel);
int interpolationsSuche(const std::vector<int>& daten, int schluessel);
```

---

## Aufgabe 0 – Aufwärmer: Lineare Suche (≈ 10 Min)

Bevor es ans „Suchen mit Köpfchen“ geht, baut zuerst die schlichteste Variante: durchlaufe das Array von vorne nach hinten und gib den Index des ersten Treffers zurück.

> **Warum überhaupt?** Die lineare Suche braucht **keine** sortierten Daten und dient uns gleich als Mess-Referenz: Wie viele Vergleiche braucht sie im Vergleich zu den cleveren Verfahren?

**Zu implementieren:**

```cpp
/**
 * @brief Sucht einen Schlüssel sequenziell von vorne nach hinten.
 * @param daten      Beliebiger (auch unsortierter) Vektor.
 * @param schluessel Gesuchter Wert.
 * @return Index des ersten Treffers, sonst -1.
 */
int lineareSuche(const std::vector<int>& daten, int schluessel);
```

---

## Aufgabe 1 – Binäre Suche (≈ 30 Min)

Die binäre Suche halbiert in jedem Schritt den Suchbereich. **Voraussetzung:** Das Array muss **sortiert** sein.

### Idee

Wir merken uns die untere und obere Grenze (`low`, `high`) des noch in Frage kommenden Bereichs. In jedem Schritt schauen wir auf das mittlere Element:

- Mitte **== Schlüssel** → gefunden, fertig.
- Mitte **< Schlüssel** → Treffer kann nur **rechts** liegen → `low = mid + 1`.
- Mitte **> Schlüssel** → Treffer kann nur **links** liegen → `high = mid - 1`.

So sieht das für die Suche nach der **23** aus:

```
Index:   0    1    2    3    4    5    6    7    8
Wert:    3    9   14   19   23   31   40   55   72
         ↑low                ↑mid                ↑high     mid=4 → daten[4]=23 == 23  → Treffer bei Index 4!

Suche nach 40:
         ↑low                ↑mid                ↑high     mid=4 → 23 < 40  → low = 5
                                  ↑low      ↑mid      ↑high mid=6 → 40 == 40 → Treffer bei Index 6
```

### Fallstricke (bitte ernst nehmen!)

1. **Schleifenbedingung:** `while (low <= high)` — das `<=` ist entscheidend. Mit `<` verpasst ihr den Fall, in dem der gesuchte Wert genau auf der letzten verbliebenen Position liegt.
2. **Mittelpunkt überlaufsicher berechnen:** Schreibt `mid = low + (high - low) / 2;` statt `(low + high) / 2;`. Bei sehr großen Indizes kann die Summe sonst überlaufen.
3. **Endlosschleife:** Vergesst nicht das `+ 1` bzw. `- 1` beim Verschieben der Grenze — sonst dreht sich die Schleife ewig.

**Zu implementieren:**

```cpp
/**
 * @brief Binäre Suche in einem aufsteigend sortierten Vektor.
 * @param daten      Sortierter Vektor.
 * @param schluessel Gesuchter Wert.
 * @return Index des Treffers, sonst -1.
 * @note  Voraussetzung: daten ist aufsteigend sortiert.
 */
int binaereSuche(const std::vector<int>& daten, int schluessel);
```

### 📝 Papier-Simulation (vor dem Coden!)

Schreibt für die Suche nach der **31** im obigen Array Schritt für Schritt eine kleine Tabelle:

| Schritt | low | high | mid | daten[mid] | Vergleich | Aktion        |
|:-------:|:---:|:----:|:---:|:----------:|:----------|:--------------|
| 1       |  0  |  8   |  4  |    23      | 23 < 31   | low = 5       |
| 2       | …   | …    | …   |    …       | …         | …             |

Führt die Tabelle zu Ende. Wenn euer Code später nicht stimmt, ist diese Tabelle euer bester Debugger.

---

## Aufgabe 2 – Interpolationssuche (≈ 30 Min)

Die Interpolationssuche ist die „schlaue Schwester“ der binären Suche. Statt **stur in die Mitte** zu greifen, **schätzt** sie anhand des Wertes, *wo* der Schlüssel ungefähr liegen müsste — so wie ihr im Telefonbuch beim Namen „Aldenhoven“ vorne aufschlagt und nicht in der Mitte.

### Idee

Liegt der Schlüssel nahe am unteren Rand, sollte auch unsere Sondierungsstelle nahe am unteren Rand liegen. Die Position wird linear interpoliert:

```
            (schluessel - daten[low]) * (high - low)
pos = low + ─────────────────────────────────────────
                  (daten[high] - daten[low])
```

Ansonsten ist die Logik identisch zur binären Suche (`pos` < bzw. > Schlüssel → Grenze verschieben).

```
Wert:    10   20   30   40   50   60   70   80   90
Index:    0    1    2    3    4    5    6    7    8

Suche nach 80:  schluessel liegt weit oben → pos springt direkt fast ans Ende
pos = 0 + (80-10)*(8-0) / (90-10) = 0 + 70*8/80 = 7   → daten[7]=80 → Treffer in EINEM Schritt!
```

### Fallstricke (hier wird's heikel!)

1. **Division durch null:** Wenn `daten[high] == daten[low]` (alle Werte im Bereich gleich), wird der Nenner 0. Fangt das ab — z. B. mit einer Sonderbehandlung: ist `daten[low] == schluessel`? Sonst `-1`.
2. **Bereichsgrenzen prüfen:** Die Schleifenbedingung muss zusätzlich sicherstellen, dass der Schlüssel überhaupt im Wertebereich liegt:
   ```cpp
   while (low <= high && schluessel >= daten[low] && schluessel <= daten[high])
   ```
   Sonst kann `pos` aus dem gültigen Indexbereich „herauslaufen“.
3. **Überlauf:** Das Produkt `(schluessel - daten[low]) * (high - low)` kann groß werden. Für unsere kleinen Testdaten ist `int` okay, denkt aber darüber nach, was bei großen Wertebereichen passiert (Tipp: `long long`).

**Zu implementieren:**

```cpp
/**
 * @brief Interpolationssuche in einem sortierten Vektor.
 * @param daten      Aufsteigend sortierter Vektor.
 * @param schluessel Gesuchter Wert.
 * @return Index des Treffers, sonst -1.
 * @note  Funktioniert am besten bei (annähernd) gleichverteilten Werten.
 */
int interpolationsSuche(const std::vector<int>& daten, int schluessel);
```

---

## Vergleich – das große Ganze

Tragt am Ende für euch selbst zusammen, was ihr gelernt habt:

| Verfahren            | Voraussetzung              | Best Case | Average      | Worst Case |
|:---------------------|:---------------------------|:---------:|:------------:|:----------:|
| Lineare Suche        | keine                      | O(1)      | O(n)         | O(n)       |
| Binäre Suche         | sortiert                   | O(1)      | O(log n)     | O(log n)   |
| Interpolationssuche  | sortiert + gleichverteilt  | O(1)      | O(log log n) | O(n)       |

**Diskussionsfrage fürs Labor:** Warum hat die Interpolationssuche einen *schlechteren* Worst Case als die binäre Suche, obwohl sie im Schnitt schneller ist? (Stichwort: stark ungleichmäßig verteilte Daten, z. B. `1, 2, 3, ..., 99, 1000000`.)

---

## Bonusaufgaben (gestaffelt nach Schwierigkeit)

### ⭐ Bonus 1 (leicht): Erstes Vorkommen bei Duplikaten
Erweitert die binäre Suche so, dass bei mehrfach vorkommendem Schlüssel der **kleinste** Index (das erste Vorkommen) zurückgegeben wird. Tipp: Nicht sofort abbrechen, sondern den Treffer merken und weiter links suchen.

### ⭐⭐ Bonus 2 (mittel): Rekursive binäre Suche
Schreibt eine zweite Variante `binaereSucheRekursiv`, die statt einer Schleife rekursiv arbeitet. Was übernimmt hier die Rolle von `low` und `high`? Wie sieht die Abbruchbedingung aus? (Brücke zurück zu [Übung 06 – Rekursion](../Aufgaben/06_Rekursion_und_Bäume.md)!)

### ⭐⭐⭐ Bonus 3 (schwer): Schritte zählen & Verteilungen vergleichen
Baut in **alle drei** Funktionen einen Vergleichszähler ein (z. B. via Referenzparameter `int& schritte`). Sucht dann denselben Wert in:
- **(a)** einem gleichverteilten Array `10, 20, 30, …` und
- **(b)** einem stark ungleichverteilten Array `1, 2, 3, …, 99, 1000000`.

Gebt für beide Fälle die Schrittzahl aller drei Verfahren aus. Erklärt mit euren Messwerten, **warum** die Interpolationssuche in Fall (b) zusammenbricht. Das ist der praktische Beleg für die Worst-Case-Diskussion oben.

---

## Test-Gerüst (zu Beginn in `suche.cpp` kopieren)

```cpp
#include <iostream>
#include <vector>
#include <cassert>

// === Hier kommen eure Implementierungen hinein ===

int lineareSuche(const std::vector<int>& daten, int schluessel) {
    // TODO: Aufgabe 0
    return -1;
}

int binaereSuche(const std::vector<int>& daten, int schluessel) {
    // TODO: Aufgabe 1
    return -1;
}

int interpolationsSuche(const std::vector<int>& daten, int schluessel) {
    // TODO: Aufgabe 2
    return -1;
}

// === Tests (nicht verändern) ===
int main() {
    std::vector<int> daten = {3, 9, 14, 19, 23, 31, 40, 55, 72};

    // Treffer
    assert(lineareSuche(daten, 23) == 4);
    assert(binaereSuche(daten, 23) == 4);
    assert(interpolationsSuche(daten, 23) == 4);

    // Randelemente
    assert(binaereSuche(daten, 3)  == 0);   // erstes Element
    assert(binaereSuche(daten, 72) == 8);   // letztes Element

    // Nicht enthalten
    assert(lineareSuche(daten, 100) == -1);
    assert(binaereSuche(daten, 100) == -1);
    assert(interpolationsSuche(daten, 100) == -1);
    assert(binaereSuche(daten, 2)  == -1);  // kleiner als alles

    // Gleichverteilte Daten (Paradedisziplin der Interpolationssuche)
    std::vector<int> gleich = {10, 20, 30, 40, 50, 60, 70, 80, 90};
    assert(interpolationsSuche(gleich, 80) == 7);
    assert(interpolationsSuche(gleich, 10) == 0);

    std::cout << "Alle Tests bestanden! \xF0\x9F\x8E\x89\n";
    return 0;
}
```

**Übersetzen & ausführen:**
```bash
g++ -std=c++17 -Wall suche.cpp -o suche
./suche
```

Erst wenn `Alle Tests bestanden!` erscheint, seid ihr mit dem Pflichtteil durch. 🚀

---

## Abgabe

- Datei `suche.cpp`, sauber übersetzbar unter `g++ -std=c++17 -Wall` (keine Warnungen!)
- Alle drei Funktionen implementiert, alle Tests grün
- Bonusaufgaben optional, aber gerne dokumentiert (kurze Notiz, welche ihr gelöst habt)
