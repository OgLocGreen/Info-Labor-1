# Lösung Übung 06 – Ablaufsteuerung Bohrstation

> **Info 1 · Übung 06** — Aufgabe: [Ablaufsteuerung Bohrstation](../Aufgaben/06_Ablaufsteuerung_Bohrstation.md) · Lösung: Ablaufsteuerung Bohrstation · Hilfsmittel: [Anleitung Visual Studio](../Hilfsmittel/06_Visual_Studio_Erste_Schritte.md)

---

> **Hinweis:** Der Code liegt in [Code/06_Bohrstation/](Code/06_Bohrstation/). Wie man ihn in Visual Studio kompiliert und debuggt, steht in der [Anleitung Visual Studio](../Hilfsmittel/06_Visual_Studio_Erste_Schritte.md).

| Aufgabe | Lösung im Material |
|---|---|
| 1 – Ablaufdiagramm | – |
| 2 – Struktogramm | – |
| 3 – Pseudocode | `pseudoCode.cpp` |
| 4 – C++-Programm | `RealCode_einfach.cpp` (einfache Variante), `RealCode.cpp` (mit Funktionen) |
| 5 – Taschenrechner | – |

---

## Aufgabe 1

_Noch keine Musterlösung vorhanden._

---

## Aufgabe 2

_Noch keine Musterlösung vorhanden._

---

## Aufgabe 3

Der Pseudocode legt zuerst die Eingänge (`teilnummer`, `start_button`) und die Ausgänge/Aktoren (`Motor`, `Bohrmaschine_start`, Unterfunktion `Abtransport()`) fest und definiert eine Hilfsfunktion `istPrimzahl`. Nur wenn der Starttaster gedrückt ist, wird der Motor eingeschaltet und die Anzahl der Bohrungen über eine `if`-`else if`-Kette bestimmt: durch 4 teilbar → 4, durch 2 teilbar → 2, Primzahl → so oft wie die Teilnummer, sonst 0. Anschließend wird in einer Zählschleife entsprechend oft gebohrt und danach `Abtransport()` aufgerufen. Die Datei hat zwar die Endung `.cpp`, ist aber Pseudocode und nicht kompilierbar.

### pseudoCode.cpp

```cpp



Input:
    teilnummer : Integer        // Nummer des Werkstücks
    start_button : Boolean      // True, wenn Starttaste gedrückt

Output / Aktoren:
    Motor : Boolean             // Förderband-Motor an/aus
    Bohrmaschine_start : Boolean // Signal an Bohrmaschine
    func Abtransport()          // Unterfunktion für den Roboter

func istPrimzahl(n : Integer) -> Boolean:
    if n < 2:
        return False

    for i = 2 to n-1:
        if n % i == 0:
            return False

    return True

// Anfangszustand
Motor = False
Bohrmaschine_start = False

if start_button == True:
    Motor = True
    // Werkstück wird transportiert ...

    // Anzahl der Bohrungen bestimmen
    anzahl_bohrungen = 0

    if teilnummer % 4 == 0:
        anzahl_bohrungen = 4
    else if teilnummer % 2 == 0:
        anzahl_bohrungen = 2
    else if istPrimzahl(teilnummer) == True:
        anzahl_bohrungen = teilnummer
    else:
        anzahl_bohrungen = 0     // für andere Zahlen ist im Text nichts definiert

    // Bohrvorgang ausführen
    for i = 1 to anzahl_bohrungen:
        Bohrmaschine_start = True
        // Bohrung ausführen
        Bohrmaschine_start = False

    // Nach dem Bohren: Abtransport
    Abtransport()
```

---

## Aufgabe 4

Zu dieser Aufgabe gibt es zwei Varianten. Beide lesen Starttaster und Werkstücknummer über die Konsole ein, simulieren den Transport durch Ein- und Ausschalten der Variablen `Motor`, bestimmen die Anzahl der Bohrungen mit derselben `if`-`else if`-Kette wie im Pseudocode und simulieren Bohrungen und Abtransport durch Konsolenausgaben. Jede Datei enthält eine eigene `main()`-Funktion – im Visual-Studio-Projekt also immer nur eine der beiden Dateien einbinden.

### RealCode_einfach.cpp

Einfache Variante: Der gesamte Ablauf steht in `main()`. Die Bohrungen werden direkt in einer `for`-Schleife ausgeführt, der Abtransport erfolgt ohne eigene Unterfunktion am Ende von `main()`.

```cpp
#include <iostream>

// Hilfsfunktion: Prüft, ob eine Zahl eine Primzahl ist
bool istPrimzahl(int n) {
    if (n < 2) {
        return false;
    }

    for (int i = 2; i <= n - 1; ++i) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}


int main() {
    bool Motor = false;
    bool start_button = false;
    int teilnummer = 0;
    bool Bohrmaschine_start = false;

    std::cout << "Starttaste gedrückt? (0 = Nein, 1 = Ja): ";
    std::cin >> start_button;

    if (!start_button) {
        std::cout << "Prozess wird nicht gestartet." << std::endl;
        return 0;
    }

    std::cout << "Bitte Werkstücknummer eingeben: ";
    std::cin >> teilnummer;

    // Motor starten – Werkstück wird befördert
    Motor = true;
    std::cout << "Motor eingeschaltet. Werkstück wird zur Bohrstation transportiert..." << std::endl;

    // (Optional) Motor könnte hier wieder ausgeschaltet werden
    Motor = false;
    std::cout << "Motor ausgeschaltet. Werkstück liegt in der Vorrichtung." << std::endl;

    // Anzahl der Bohrungen bestimmen
    int anzahl_bohrungen = 0;

    if (teilnummer % 4 == 0) {
        anzahl_bohrungen = 4;
    } else if (teilnummer % 2 == 0) {
        anzahl_bohrungen = 2;
    } else if (istPrimzahl(teilnummer)) {
        anzahl_bohrungen = teilnummer;
    } else {
        anzahl_bohrungen = 0;
    }

    std::cout << "Anzahl der geplanten Bohrungen: " << anzahl_bohrungen << std::endl;

    // Bohrvorgang ausführen
    for (int i = 1; i <= anzahl_bohrungen; ++i) {
        Bohrmaschine_start = true;
        std::cout << "Bohrung " << i << " gestartet." << std::endl;

        // Hier würde in echt gebohrt werden
        // ...

        Bohrmaschine_start = false;
        std::cout << "Bohrung " << i << " abgeschlossen." << std::endl;
    }

    if (anzahl_bohrungen == 0) {
        std::cout << "Keine Bohrung erforderlich." << std::endl;
    }

    // Nach dem Bohren: Abtransport
    std::cout << "Roboter-Abtransport wird gestartet..." << std::endl;
    // Hier würde in echt der Roboter angesteuert
    // ...
    std::cout << "Werkstück wurde abtransportiert." << std::endl;

    std::cout << "Prozess abgeschlossen." << std::endl;

    return 0;
}
```

### RealCode.cpp

Strukturierte Variante: gleiche Logik, aber der Bohrvorgang (`bohren(int anzahl_bohrungen)`) und der Abtransport (`Abtransport()`) sind in eigene Funktionen ausgelagert. Damit entspricht sie der geforderten Strukturierung mit Funktionen und der Unterfunktion `Abtransport` aus der Ablaufbeschreibung.

```cpp
#include <iostream>

// Hilfsfunktion: Prüft, ob eine Zahl eine Primzahl ist
bool istPrimzahl(int n) {
    if (n < 2) {
        return false;
    }

    for (int i = 2; i <= n - 1; ++i) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

// Unterfunktion: Bohrvorgang
void bohren(int anzahl_bohrungen) {
    bool Bohrmaschine_start = false;

    for (int i = 1; i <= anzahl_bohrungen; ++i) {
        Bohrmaschine_start = true;
        std::cout << "Bohrung " << i << " gestartet." << std::endl;

        // Hier würde in echt gebohrt werden
        // ...

        Bohrmaschine_start = false;
        std::cout << "Bohrung " << i << " abgeschlossen." << std::endl;
    }

    if (anzahl_bohrungen == 0) {
        std::cout << "Keine Bohrung erforderlich." << std::endl;
    }
}

// Unterfunktion: Abtransport durch Roboter
void Abtransport() {
    std::cout << "Roboter-Abtransport wird gestartet..." << std::endl;
    // Hier würde in echt der Roboter angesteuert
    // ...
    std::cout << "Werkstück wurde abtransportiert." << std::endl;
}

int main() {
    bool Motor = false;
    bool start_button = false;
    int teilnummer = 0;

    std::cout << "Starttaste gedrückt? (0 = Nein, 1 = Ja): ";
    std::cin >> start_button;

    if (!start_button) {
        std::cout << "Prozess wird nicht gestartet." << std::endl;
        return 0;
    }

    std::cout << "Bitte Werkstücknummer eingeben: ";
    std::cin >> teilnummer;

    // Motor starten – Werkstück wird befördert
    Motor = true;
    std::cout << "Motor eingeschaltet. Werkstück wird zur Bohrstation transportiert..." << std::endl;

    // (Optional) Motor könnte hier wieder ausgeschaltet werden
    Motor = false;
    std::cout << "Motor ausgeschaltet. Werkstück liegt in der Vorrichtung." << std::endl;

    // Anzahl der Bohrungen bestimmen
    int anzahl_bohrungen = 0;

    if (teilnummer % 4 == 0) {
        anzahl_bohrungen = 4;
    } else if (teilnummer % 2 == 0) {
        anzahl_bohrungen = 2;
    } else if (istPrimzahl(teilnummer)) {
        anzahl_bohrungen = teilnummer;
    } else {
        anzahl_bohrungen = 0;
    }

    std::cout << "Anzahl der geplanten Bohrungen: " << anzahl_bohrungen << std::endl;

    // Bohrvorgang ausführen
    bohren(anzahl_bohrungen);

    // Nach dem Bohren: Abtransport
    Abtransport();

    std::cout << "Prozess abgeschlossen." << std::endl;

    return 0;
}
```

---

## Aufgabe 5

_Noch keine Musterlösung vorhanden._
