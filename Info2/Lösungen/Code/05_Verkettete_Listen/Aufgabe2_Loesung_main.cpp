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
