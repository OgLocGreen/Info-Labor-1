# Übung 05 – Einfach verkettete Liste

> **Info 2 · Übung 05** — Aufgabe: Einfach verkettete Liste · Lösung: [Einfach verkettete Liste](../Lösungen/05_Verkettete_Listen_Lösung.md) · Hilfsmittel: [Recap Pointer und Speicherverwaltung](../Hilfsmittel/04_Recap_Pointer_und_Speicherverwaltung.md)

---

_Aufgabe 2 des Laborblatts 4 (Aufgabe 1: [Übung 04.1 – Funktionen mit Zeigerparametern](../Aufgaben/04_01_Pointer.md)) – daher sind die Teilaufgaben mit 2.1 – 2.4 nummeriert._

## Lernziele

- Dynamische Datenstrukturen mit `new` und `delete` selbst aufbauen
- Pointer als Verbindungsglieder zwischen Knoten verstehen
- Eine Klasse mit Konstruktor und Destruktor korrekt implementieren (Speicherverwaltung)
- Modulare Projektstruktur mit Header- und Implementierungsdatei (`.h` / `.cpp`) anwenden
- Sonderfälle (leere Liste, Kopf-Knoten) bei Pointer-Operationen beachten

## Hintergrund

Eine **einfach verkettete Liste** (singly linked list) ist eine dynamische Datenstruktur, bei der jedes Element (ein **Knoten**) einen Wert sowie einen Pointer auf den **nächsten** Knoten enthält. Der letzte Knoten zeigt auf `nullptr`.

```
 kopf
  │
  ▼
[10|·]──▶[20|·]──▶[30|·]──▶[40|/]
```

Anders als ein `Array` hat die Liste keine feste Größe — Knoten werden zur Laufzeit mit `new` angelegt und müssen mit `delete` wieder freigegeben werden.

## Aufgabenstellung

Implementiere die Klasse `Liste` zur Verwaltung einer einfach verketteten Liste von `int`-Werten. Verteile dein Projekt auf drei Dateien:

| Datei | Inhalt |
|---|---|
| `Liste.h` | Definition der Struktur `Knoten` und der Klasse `Liste` (mit Include-Guard) |
| `Liste.cpp` | Implementierung aller Methoden |
| `main.cpp` | Testprogramm |

### Teilaufgabe 2.1 — Struktur und Klasse

Definiere in `Liste.h`:

```cpp
struct Knoten {
    int wert;
    Knoten* naechster;
};

class Liste {
private:
    Knoten* kopf;
public:
    // ... Methoden siehe unten
};
```

Vergiss den **Include-Guard** (`#ifndef … #define … #endif`) nicht.

### Teilaufgabe 2.2 — Konstruktor und Destruktor

- Der **Konstruktor** initialisiert `kopf` mit `nullptr` (leere Liste).
- Der **Destruktor** muss alle Knoten mit `delete` freigeben, sonst entsteht ein **Memory Leak**.

### Teilaufgabe 2.3 — Methoden

Implementiere folgende Methoden:

| Methode | Beschreibung |
|---|---|
| `void einfuegenVorne(int wert)` | Fügt einen neuen Knoten am Anfang der Liste ein |
| `void einfuegenHinten(int wert)` | Hängt einen neuen Knoten am Ende an |
| `bool loesche(int wert)` | Löscht den ersten Knoten mit diesem Wert; gibt `true` bei Erfolg zurück |
| `bool enthaelt(int wert) const` | Prüft, ob der Wert in der Liste vorkommt |
| `int laenge() const` | Gibt die Anzahl der Knoten zurück |
| `bool istLeer() const` | Prüft, ob die Liste leer ist |
| `void ausgabe() const` | Gibt alle Werte z. B. als `[ 1 -> 5 -> 10 ]` aus |

### Teilaufgabe 2.4 — Testprogramm

Schreibe in `main.cpp` ein Programm, das alle Methoden testet, insbesondere folgende Sonderfälle:

- Löschen aus leerer Liste
- Löschen des Kopf-Knotens
- Löschen eines nicht vorhandenen Wertes
- Suche in leerer Liste

## Beispielausgabe

```
Liste leer? ja
Nach einfuegenHinten(10, 20, 30): [ 10 -> 20 -> 30 ]
Nach einfuegenVorne(5, 1):        [ 1 -> 5 -> 10 -> 20 -> 30 ]
Laenge: 5
Enthaelt 20? ja
Enthaelt 99? nein
Loesche 20: ok
[ 1 -> 5 -> 10 -> 30 ]
Loesche 1 (Kopf): ok
[ 5 -> 10 -> 30 ]
Loesche 99: nicht gefunden
[ 5 -> 10 -> 30 ]
```

## Bonus (optional)

1. **`void umkehren()`** — Kehrt die Reihenfolge der Knoten in der Liste um, ohne neue Knoten anzulegen (nur Pointer umhängen).
2. **`int wertAnIndex(int index) const`** — Gibt den Wert an der angegebenen Position zurück (Exception oder `-1` bei ungültigem Index).
3. **Template-Variante** — Verallgemeinere die Liste mit `template<typename T>`, sodass nicht nur `int`, sondern beliebige Datentypen gespeichert werden können.

## Hinweise

- **Sonderfälle beachten:** Beim Einfügen am Ende einer leeren Liste, beim Löschen des Kopf-Knotens und beim Suchen müssen die Pointer-Manipulationen genau stimmen.
- Beim Löschen brauchst du den **Vorgänger** des zu löschenden Knotens, denn dessen `naechster`-Pointer muss umgehängt werden.
- Vergiss nicht, gelöschte Knoten mit `delete` freizugeben.
- Übersetzung: `g++ -std=c++17 -Wall Liste.cpp main.cpp -o liste`
- Mit `valgrind ./liste` lassen sich Memory Leaks aufspüren (Linux).

## Tipp zum Debuggen

Zeichne dir die Liste als Pfeildiagramm auf, wenn du eine Operation entwickelst. Markiere die Pointer, die du umhängen musst, in einer anderen Farbe — das hilft enorm.
