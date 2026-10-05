# Erklärung – String splitten in C++ (Bibliothek vs. von Hand)

> **Info 2 · Hilfsmittel** — gehört zu: keiner Übung eindeutig zuzuordnen (übungsübergreifende Kurzreferenz zu `std::string`-Methoden und String-Streams)

---

Kurzreferenz zu zwei Fragen aus dem Labor: Wie zerlegt man einen `std::string`
an Trennzeichen (z. B. `,` oder Leerzeichen) in einzelne Teilstrings?

Alle Beispiele sind C++17 und kompilieren mit `g++ -std=c++17 -Wall`.

---

## Frage 1 — Splitten mit `std::string`-Methoden

### a) `find` + `substr`

`find(c, start)` sucht das Trennzeichen `c` ab Position `start` und liefert dessen
Index zurück — oder `std::string::npos`, falls nichts gefunden wird.
`substr(start, len)` schneidet den Teilstring davor heraus.

```cpp
#include <string>
#include <vector>

std::vector<std::string> split(const std::string& s, char delim) {
    std::vector<std::string> out;
    std::size_t start = 0;

    while (true) {
        std::size_t pos = s.find(delim, start);       // Trenner ab 'start' suchen
        if (pos == std::string::npos) {
            out.push_back(s.substr(start));           // Rest = letztes Token
            break;
        }
        out.push_back(s.substr(start, pos - start));  // Token vor dem Trenner
        start = pos + 1;                              // Trenner überspringen
    }
    return out;
}
```

**Ablauf für `"a,b,c"`:**

```
"a,b,c"
 01234                  <- Index

find(',', 0) -> 1     substr(0, 1) = "a"    start = 2
find(',', 2) -> 3     substr(2, 1) = "b"    start = 4
find(',', 4) -> npos  substr(4)    = "c"    (Rest)
```

Merke:
- `npos` ist der „nicht gefunden“-Wert (ein sehr großer `size_t`).
- Token-Länge = `pos - start`.
- Das letzte Token holt `substr(start)` ohne Längenangabe → bis zum Ende.

### b) Mehrere Trenner gleichzeitig: `find_first_of`

Soll an `,` *oder* Leerzeichen getrennt werden, ersetzt `find_first_of` das `find`.
Es findet das nächste Vorkommen *irgendeines* der angegebenen Zeichen:

```cpp
std::size_t pos = s.find_first_of(", ", start);  // Komma ODER Leerzeichen
```

Die restliche Schleife bleibt unverändert.

> **Fallstrick:** Zwei Trenner direkt hintereinander (`"a, b"` → erst `,` dann ` `)
> erzeugen ein leeres Token: Ergebnis `["a", "", "b"]`.

### c) Von Hand: Zeichen-Schleife

Ohne `find`/`substr` — wir laufen Zeichen für Zeichen durch und bauen das aktuelle
Token selbst auf:

```cpp
std::vector<std::string> split_manual(const std::string& s, char delim) {
    std::vector<std::string> out;
    std::string cur;

    for (char c : s) {            // Zeichen für Zeichen
        if (c == delim) {
            out.push_back(cur);   // Trenner -> Token ist fertig
            cur.clear();
        } else {
            cur += c;             // Zeichen an das Token anhängen
        }
    }
    out.push_back(cur);           // letztes Token (nach dem letzten Trenner)
    return out;
}
```

Logik:
- `cur` sammelt Zeichen, bis ein Trenner kommt.
- Trenner → `cur` ablegen und leeren.
- Nach der Schleife `cur` einmal ablegen (der Teil nach dem letzten Trenner).

Verhält sich identisch zur `find`/`substr`-Variante, inklusive leerer Token bei
`"a,,b"` → `["a", "", "b"]`.

---

## Frage 2 — Splitten mit `getline` und Streams

### a) `getline` mit festem Trenner

`std::getline(stream, token, delim)` liest aus einem Stream bis zum Trennzeichen,
verbraucht den Trenner und legt das Gelesene in `token` ab. Den String packt man
dafür in einen `std::istringstream`.

```cpp
#include <sstream>
#include <string>
#include <vector>

std::vector<std::string> split(const std::string& s, char delim) {
    std::vector<std::string> out;
    std::istringstream iss(s);
    std::string token;
    while (std::getline(iss, token, delim)) {  // bis zum Trenner lesen
        out.push_back(token);
    }
    return out;
}
```

Sehr kompakt — ideal, wenn genau *ein* fester Trenner reicht.

> **Fallstrick:** Steht ein Trenner ganz am Ende (`"a,b,"`), liefert `getline` nur
> `["a", "b"]` — das leere Token am Schluss fällt weg. Leere Token *mittendrin*
> (`"a,,b"` → `["a", "", "b"]`) bleiben dagegen erhalten.

### b) An Whitespace trennen: `stream >> token`

Der `>>`-Operator überspringt führenden Whitespace, liest ein „Wort“ bis zum
nächsten Whitespace und stoppt. Praktisch für Wörter oder Zahlen:

```cpp
std::vector<std::string> split_ws(const std::string& s) {
    std::istringstream iss(s);
    std::vector<std::string> out;
    std::string token;
    while (iss >> token) {        // überspringt Whitespace, liest ein Wort
        out.push_back(token);
    }
    return out;
}
```

`split_ws("  Hallo   Welt  ")` → `["Hallo", "Welt"]`.

> **Fallstrick:** `>>` trennt *immer* an beliebigem Whitespace (Leerzeichen, Tab,
> Zeilenumbruch) — ein eigenes Zeichen wie `,` lässt sich damit nicht festlegen.
> Dafür schluckt es führende/abschließende sowie mehrfache Leerzeichen automatisch
> und liefert nie leere Token.

---

## Vergleich

| Methode             | Trennzeichen                       | Leere Token            | Wann nutzen                          |
|---------------------|------------------------------------|------------------------|--------------------------------------|
| `find` + `substr`   | beliebig (mehrere via `find_first_of`) | bleiben erhalten   | volle Kontrolle, z. B. CSV mit leeren Feldern |
| Von Hand (Schleife) | beliebig                           | bleiben (oder filtern) | zum Verstehen, eigene Sonderlogik    |
| `getline(iss, t, c)`| genau ein Zeichen                  | bleiben (außer am Ende)| einfach, ein fester Trenner          |
| `iss >> t`          | beliebiger Whitespace              | werden geschluckt      | Wörter/Zahlen, Mehrfach-Leerzeichen egal |

**Leere Token herausfiltern** (für alle Varianten): vor dem `push_back` prüfen.

```cpp
if (!token.empty()) out.push_back(token);
```

---

## Spickzettel

```cpp
s.find(c, start)          // Index des Trenners oder npos
s.find_first_of(",;", k)  // nächstes beliebiges Zeichen aus der Menge
s.substr(start, len)      // Teilstring (len optional -> bis Ende)
std::string::npos         // "nicht gefunden"

std::istringstream iss(s);
std::getline(iss, tok, c); // bis zum Zeichen c
iss >> tok;                // bis zum nächsten Whitespace
```
