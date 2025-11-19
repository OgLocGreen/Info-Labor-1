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
