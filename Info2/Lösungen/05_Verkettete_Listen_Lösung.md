# Lösung Übung 05 – Einfach verkettete Liste

> **Info 2 · Übung 05** — Aufgabe: [Einfach verkettete Liste](../Aufgaben/05_Verkettete_Listen.md) · Lösung: Einfach verkettete Liste · Hilfsmittel: [Recap Pointer und Speicherverwaltung](../Hilfsmittel/04_Recap_Pointer_und_Speicherverwaltung.md)

---

Musterlösung zu [Übung 05 – Einfach verkettete Liste](../Aufgaben/05_Verkettete_Listen.md). Die Aufgabe war im ursprünglichen Laborblatt „Aufgabe 2“ – daher die Nummerierung der Teilaufgaben 2.1–2.4. Der Code liegt in [Code/05_Verkettete_Listen/](Code/05_Verkettete_Listen/) und ist am Ende dieses Dokuments vollständig abgedruckt.

## Übersetzen und Ausführen

Die Dateien im Code-Ordner heißen `Aufgabe2_Loesung_Liste.h`, `Aufgabe2_Loesung_Liste.cpp` und `Aufgabe2_Loesung_main.cpp`. Der Code bindet den Header aber als `#include "Liste.h"` ein. Vor dem Übersetzen die Dateien deshalb unter den Namen aus der Aufgabe (`Liste.h`, `Liste.cpp`, `main.cpp`) kopieren:

```bash
cd Code/05_Verkettete_Listen
cp Aufgabe2_Loesung_Liste.h Liste.h
cp Aufgabe2_Loesung_Liste.cpp Liste.cpp
cp Aufgabe2_Loesung_main.cpp main.cpp
g++ -std=c++17 -Wall Liste.cpp main.cpp -o liste
./liste
```

---

## Teilaufgabe 2.1 — Struktur und Klasse

`Knoten` bündelt den gespeicherten Wert und den Zeiger `naechster` auf den Folgeknoten (`nullptr` am Listenende). Die Klasse `Liste` speichert nur den Zeiger `kopf` auf den ersten Knoten – alle weiteren Knoten sind über die `naechster`-Zeiger erreichbar. Der Include-Guard `LISTE_H` verhindert, dass der Header mehrfach eingebunden wird.

Auszug aus `Liste.h`:

```cpp
#ifndef LISTE_H
#define LISTE_H

/**
 * @struct Knoten
 * @brief Repraesentiert einen einzelnen Knoten in der einfach verketteten Liste.
 */
struct Knoten {
    int wert;          ///< Der im Knoten gespeicherte Wert.
    Knoten* naechster; ///< Zeiger auf den naechsten Knoten (nullptr am Listenende).
};

/**
 * @class Liste
 * @brief Einfach verkettete Liste fuer Integer-Werte.
 * @details Bietet Operationen zum Einfuegen, Loeschen, Suchen und zur Ausgabe.
 *          Der Speicher fuer alle Knoten wird im Destruktor automatisch freigegeben.
 */
class Liste {
private:
    Knoten* kopf; ///< Zeiger auf den ersten Knoten der Liste (nullptr bei leerer Liste).

public:
    // ... Methodendeklarationen (siehe Teilaufgaben 2.2 und 2.3)
};

#endif // LISTE_H
```

## Teilaufgabe 2.2 — Konstruktor und Destruktor

Der Konstruktor setzt `kopf` über die Initialisierungsliste auf `nullptr` – die Liste ist damit leer. Der Destruktor läuft die Liste vom Kopf aus ab: Der aktuelle Kopf wird in `temp` gemerkt, `kopf` rückt auf den nächsten Knoten vor und erst dann wird `temp` mit `delete` freigegeben. So wird jeder mit `new` angelegte Knoten genau einmal freigegeben und es entsteht kein Memory Leak (prüfbar z. B. mit `valgrind ./liste` unter Linux).

Auszug aus `Liste.cpp`:

```cpp
Liste::Liste() : kopf(nullptr) {
    // Liste startet leer.
}

Liste::~Liste() {
    // Alle Knoten freigeben, damit kein Memory Leak entsteht.
    while (kopf != nullptr) {
        Knoten* temp = kopf;
        kopf = kopf->naechster;
        delete temp;
    }
}
```

## Teilaufgabe 2.3 — Methoden

### `einfuegenVorne`

Der neue Knoten zeigt auf den bisherigen Kopf, danach wird er selbst zum neuen Kopf. Das funktioniert auch bei leerer Liste, weil `kopf` dann `nullptr` ist und der neue Knoten damit automatisch das Listenende bildet.

```cpp
void Liste::einfuegenVorne(int wert) {
    Knoten* neu = new Knoten;
    neu->wert = wert;
    neu->naechster = kopf;  // Neuer Knoten zeigt auf den alten Kopf.
    kopf = neu;             // Neuer Kopf ist jetzt der neue Knoten.
}
```

### `einfuegenHinten`

Der neue Knoten erhält `naechster = nullptr`, da er das neue Listenende wird. Bei leerer Liste wird er direkt zum Kopf (Sonderfall); sonst läuft `aktuell` bis zum letzten Knoten (dessen `naechster` `nullptr` ist) und hängt den neuen Knoten dort an.

```cpp
void Liste::einfuegenHinten(int wert) {
    Knoten* neu = new Knoten;
    neu->wert = wert;
    neu->naechster = nullptr;

    // Sonderfall: leere Liste.
    if (kopf == nullptr) {
        kopf = neu;
        return;
    }

    // Sonst: bis zum letzten Knoten laufen.
    Knoten* aktuell = kopf;
    while (aktuell->naechster != nullptr) {
        aktuell = aktuell->naechster;
    }
    aktuell->naechster = neu;
}
```

### `loesche`

Es werden drei Fälle unterschieden: leere Liste (Rückgabe `false`), der gesuchte Wert steht im Kopf (Kopf rückt weiter, alter Kopf wird freigegeben) und der allgemeine Fall. Im allgemeinen Fall sucht die Schleife den **Vorgänger** des zu löschenden Knotens, damit dessen `naechster`-Zeiger über den gelöschten Knoten hinweg umgehängt werden kann. Ist `aktuell->naechster` nach der Schleife `nullptr`, wurde der Wert nicht gefunden.

```cpp
bool Liste::loesche(int wert) {
    // Sonderfall: leere Liste.
    if (kopf == nullptr) {
        return false;
    }

    // Sonderfall: Kopf-Knoten loeschen.
    if (kopf->wert == wert) {
        Knoten* temp = kopf;
        kopf = kopf->naechster;
        delete temp;
        return true;
    }

    // Allgemeiner Fall: Vorgaenger des zu loeschenden Knotens suchen.
    Knoten* aktuell = kopf;
    while (aktuell->naechster != nullptr && aktuell->naechster->wert != wert) {
        aktuell = aktuell->naechster;
    }

    // Wert nicht gefunden?
    if (aktuell->naechster == nullptr) {
        return false;
    }

    // Vorgaenger ueber den geloeschten Knoten "hinwegzeigen" lassen.
    Knoten* temp = aktuell->naechster;
    aktuell->naechster = temp->naechster;
    delete temp;
    return true;
}
```

### `enthaelt`, `laenge` und `istLeer`

`enthaelt` und `laenge` laufen mit einem Hilfszeiger `aktuell` vom Kopf bis `nullptr` durch die Liste – `enthaelt` bricht beim ersten Treffer mit `true` ab, `laenge` zählt die Knoten. `istLeer` muss die Liste nicht durchlaufen: Sie ist genau dann leer, wenn `kopf == nullptr` gilt. Alle drei Methoden sind `const`, da sie die Liste nicht verändern.

```cpp
bool Liste::enthaelt(int wert) const {
    Knoten* aktuell = kopf;
    while (aktuell != nullptr) {
        if (aktuell->wert == wert) {
            return true;
        }
        aktuell = aktuell->naechster;
    }
    return false;
}

int Liste::laenge() const {
    int anzahl = 0;
    Knoten* aktuell = kopf;
    while (aktuell != nullptr) {
        ++anzahl;
        aktuell = aktuell->naechster;
    }
    return anzahl;
}

bool Liste::istLeer() const {
    return kopf == nullptr;
}
```

### `ausgabe`

Gibt alle Werte im Format `[ 1 -> 5 -> 10 ]` aus. Der Pfeil ` -> ` wird nur geschrieben, wenn noch ein Folgeknoten existiert.

```cpp
void Liste::ausgabe() const {
    std::cout << "[ ";
    Knoten* aktuell = kopf;
    while (aktuell != nullptr) {
        std::cout << aktuell->wert;
        if (aktuell->naechster != nullptr) {
            std::cout << " -> ";
        }
        aktuell = aktuell->naechster;
    }
    std::cout << " ]" << std::endl;
}
```

## Teilaufgabe 2.4 — Testprogramm

Das Testprogramm ruft alle Methoden auf und prüft die Sonderfälle „Löschen aus leerer Liste“, „Löschen des Kopf-Knotens“ und „Löschen eines nicht vorhandenen Wertes“. Am Ende von `main` gibt der Destruktor automatisch alle verbliebenen Knoten frei.

> **Hinweis:** Der in der Aufgabe ebenfalls geforderte Sonderfall **„Suche in leerer Liste“** (`enthaelt` auf einer leeren Liste) wird im Testprogramm nicht geprüft.

Auszug aus `main.cpp`:

```cpp
int main() {
    Liste liste;

    std::cout << "Liste leer? " << (liste.istLeer() ? "ja" : "nein") << std::endl;

    // Sonderfall: Loeschen aus leerer Liste.
    std::cout << "Loesche aus leerer Liste: "
              << (liste.loesche(42) ? "ok" : "nicht gefunden") << std::endl;

    // Einfuegen am Ende.
    liste.einfuegenHinten(10);
    liste.einfuegenHinten(20);
    liste.einfuegenHinten(30);
    std::cout << "Nach einfuegenHinten(10, 20, 30): ";
    liste.ausgabe();

    // Einfuegen am Anfang.
    liste.einfuegenVorne(5);
    liste.einfuegenVorne(1);
    std::cout << "Nach einfuegenVorne(5, 1):        ";
    liste.ausgabe();

    std::cout << "Laenge: " << liste.laenge() << std::endl;

    // Suche.
    std::cout << "Enthaelt 20? " << (liste.enthaelt(20) ? "ja" : "nein") << std::endl;
    std::cout << "Enthaelt 99? " << (liste.enthaelt(99) ? "ja" : "nein") << std::endl;

    // Mittleren Knoten loeschen.
    std::cout << "Loesche 20: "
              << (liste.loesche(20) ? "ok" : "nicht gefunden") << std::endl;
    liste.ausgabe();

    // Kopf-Knoten loeschen.
    std::cout << "Loesche 1 (Kopf): "
              << (liste.loesche(1) ? "ok" : "nicht gefunden") << std::endl;
    liste.ausgabe();

    // Nicht vorhandenen Wert loeschen.
    std::cout << "Loesche 99: "
              << (liste.loesche(99) ? "ok" : "nicht gefunden") << std::endl;
    liste.ausgabe();

    std::cout << "Endlaenge: " << liste.laenge() << std::endl;

    // Destruktor wird automatisch aufgerufen und gibt Speicher frei.
    return 0;
}
```

### Ausgabe des Programms

Aus dem Code abgeleitet (entspricht der Beispielausgabe der Aufgabe, ergänzt um die Zeilen „Loesche aus leerer Liste“ und „Endlaenge“):

```
Liste leer? ja
Loesche aus leerer Liste: nicht gefunden
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
Endlaenge: 3
```

## Bonus (optional)

`umkehren()`, `wertAnIndex(int index)` und die Template-Variante: _Noch keine Musterlösung vorhanden._

---

## Vollständiger Code

### Aufgabe2_Loesung_Liste.h (eingebunden als `Liste.h`)

```cpp
/**
 * @file Liste.h
 * @brief Definition einer einfach verketteten Liste fuer Integer-Werte.
 * @details Demonstriert dynamische Speicherverwaltung mit new/delete sowie
 *          die Verwendung von Pointern als Verbindungsglieder zwischen Knoten.
 */

#ifndef LISTE_H
#define LISTE_H

/**
 * @struct Knoten
 * @brief Repraesentiert einen einzelnen Knoten in der einfach verketteten Liste.
 */
struct Knoten {
    int wert;          ///< Der im Knoten gespeicherte Wert.
    Knoten* naechster; ///< Zeiger auf den naechsten Knoten (nullptr am Listenende).
};

/**
 * @class Liste
 * @brief Einfach verkettete Liste fuer Integer-Werte.
 * @details Bietet Operationen zum Einfuegen, Loeschen, Suchen und zur Ausgabe.
 *          Der Speicher fuer alle Knoten wird im Destruktor automatisch freigegeben.
 */
class Liste {
private:
    Knoten* kopf; ///< Zeiger auf den ersten Knoten der Liste (nullptr bei leerer Liste).

public:
    /**
     * @brief Konstruktor: erzeugt eine leere Liste.
     */
    Liste();

    /**
     * @brief Destruktor: gibt den Speicher aller Knoten frei.
     */
    ~Liste();

    /**
     * @brief Fuegt einen neuen Wert am Anfang der Liste ein.
     * @param wert Der einzufuegende Wert.
     */
    void einfuegenVorne(int wert);

    /**
     * @brief Fuegt einen neuen Wert am Ende der Liste an.
     * @param wert Der anzufuegende Wert.
     */
    void einfuegenHinten(int wert);

    /**
     * @brief Loescht den ersten Knoten mit dem angegebenen Wert.
     * @param wert Der zu loeschende Wert.
     * @return true, wenn ein Knoten geloescht wurde, sonst false.
     */
    bool loesche(int wert);

    /**
     * @brief Prueft, ob ein Wert in der Liste enthalten ist.
     * @param wert Der gesuchte Wert.
     * @return true, wenn der Wert vorhanden ist.
     */
    bool enthaelt(int wert) const;

    /**
     * @brief Liefert die Anzahl der Knoten in der Liste.
     * @return Anzahl der Listenelemente.
     */
    int laenge() const;

    /**
     * @brief Prueft, ob die Liste leer ist.
     * @return true, wenn die Liste keine Knoten enthaelt.
     */
    bool istLeer() const;

    /**
     * @brief Gibt alle Werte der Liste auf der Konsole aus.
     * @note Format: [ 1 -> 5 -> 10 ]
     */
    void ausgabe() const;
};

#endif // LISTE_H
```

### Aufgabe2_Loesung_Liste.cpp (`Liste.cpp`)

```cpp
/**
 * @file Liste.cpp
 * @brief Implementierung der einfach verketteten Liste.
 * @see Liste.h
 */

#include "Liste.h"
#include <iostream>

Liste::Liste() : kopf(nullptr) {
    // Liste startet leer.
}

Liste::~Liste() {
    // Alle Knoten freigeben, damit kein Memory Leak entsteht.
    while (kopf != nullptr) {
        Knoten* temp = kopf;
        kopf = kopf->naechster;
        delete temp;
    }
}

void Liste::einfuegenVorne(int wert) {
    Knoten* neu = new Knoten;
    neu->wert = wert;
    neu->naechster = kopf;  // Neuer Knoten zeigt auf den alten Kopf.
    kopf = neu;             // Neuer Kopf ist jetzt der neue Knoten.
}

void Liste::einfuegenHinten(int wert) {
    Knoten* neu = new Knoten;
    neu->wert = wert;
    neu->naechster = nullptr;

    // Sonderfall: leere Liste.
    if (kopf == nullptr) {
        kopf = neu;
        return;
    }

    // Sonst: bis zum letzten Knoten laufen.
    Knoten* aktuell = kopf;
    while (aktuell->naechster != nullptr) {
        aktuell = aktuell->naechster;
    }
    aktuell->naechster = neu;
}

bool Liste::loesche(int wert) {
    // Sonderfall: leere Liste.
    if (kopf == nullptr) {
        return false;
    }

    // Sonderfall: Kopf-Knoten loeschen.
    if (kopf->wert == wert) {
        Knoten* temp = kopf;
        kopf = kopf->naechster;
        delete temp;
        return true;
    }

    // Allgemeiner Fall: Vorgaenger des zu loeschenden Knotens suchen.
    Knoten* aktuell = kopf;
    while (aktuell->naechster != nullptr && aktuell->naechster->wert != wert) {
        aktuell = aktuell->naechster;
    }

    // Wert nicht gefunden?
    if (aktuell->naechster == nullptr) {
        return false;
    }

    // Vorgaenger ueber den geloeschten Knoten "hinwegzeigen" lassen.
    Knoten* temp = aktuell->naechster;
    aktuell->naechster = temp->naechster;
    delete temp;
    return true;
}

bool Liste::enthaelt(int wert) const {
    Knoten* aktuell = kopf;
    while (aktuell != nullptr) {
        if (aktuell->wert == wert) {
            return true;
        }
        aktuell = aktuell->naechster;
    }
    return false;
}

int Liste::laenge() const {
    int anzahl = 0;
    Knoten* aktuell = kopf;
    while (aktuell != nullptr) {
        ++anzahl;
        aktuell = aktuell->naechster;
    }
    return anzahl;
}

bool Liste::istLeer() const {
    return kopf == nullptr;
}

void Liste::ausgabe() const {
    std::cout << "[ ";
    Knoten* aktuell = kopf;
    while (aktuell != nullptr) {
        std::cout << aktuell->wert;
        if (aktuell->naechster != nullptr) {
            std::cout << " -> ";
        }
        aktuell = aktuell->naechster;
    }
    std::cout << " ]" << std::endl;
}
```

### Aufgabe2_Loesung_main.cpp (`main.cpp`)

```cpp
/**
 * @file main.cpp
 * @brief Testprogramm fuer die einfach verkettete Liste.
 * @details Demonstriert alle Operationen der Liste inklusive Sonderfaelle:
 *          - Loeschen aus leerer Liste
 *          - Loeschen des Kopf-Knotens
 *          - Loeschen eines nicht vorhandenen Wertes
 *
 * Uebersetzen: g++ -std=c++17 -Wall Liste.cpp main.cpp -o liste
 */

#include "Liste.h"
#include <iostream>

int main() {
    Liste liste;

    std::cout << "Liste leer? " << (liste.istLeer() ? "ja" : "nein") << std::endl;

    // Sonderfall: Loeschen aus leerer Liste.
    std::cout << "Loesche aus leerer Liste: "
              << (liste.loesche(42) ? "ok" : "nicht gefunden") << std::endl;

    // Einfuegen am Ende.
    liste.einfuegenHinten(10);
    liste.einfuegenHinten(20);
    liste.einfuegenHinten(30);
    std::cout << "Nach einfuegenHinten(10, 20, 30): ";
    liste.ausgabe();

    // Einfuegen am Anfang.
    liste.einfuegenVorne(5);
    liste.einfuegenVorne(1);
    std::cout << "Nach einfuegenVorne(5, 1):        ";
    liste.ausgabe();

    std::cout << "Laenge: " << liste.laenge() << std::endl;

    // Suche.
    std::cout << "Enthaelt 20? " << (liste.enthaelt(20) ? "ja" : "nein") << std::endl;
    std::cout << "Enthaelt 99? " << (liste.enthaelt(99) ? "ja" : "nein") << std::endl;

    // Mittleren Knoten loeschen.
    std::cout << "Loesche 20: "
              << (liste.loesche(20) ? "ok" : "nicht gefunden") << std::endl;
    liste.ausgabe();

    // Kopf-Knoten loeschen.
    std::cout << "Loesche 1 (Kopf): "
              << (liste.loesche(1) ? "ok" : "nicht gefunden") << std::endl;
    liste.ausgabe();

    // Nicht vorhandenen Wert loeschen.
    std::cout << "Loesche 99: "
              << (liste.loesche(99) ? "ok" : "nicht gefunden") << std::endl;
    liste.ausgabe();

    std::cout << "Endlaenge: " << liste.laenge() << std::endl;

    // Destruktor wird automatisch aufgerufen und gibt Speicher frei.
    return 0;
}
```
