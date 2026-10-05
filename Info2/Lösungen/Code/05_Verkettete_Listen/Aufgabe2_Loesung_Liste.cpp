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
