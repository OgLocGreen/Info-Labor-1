#ifndef CLIENT_H       // Include Guard
#define CLIENT_H

#include "Person.h"
#include <string>

/**
 * @file Client.h
 * @brief Deklaration der abgeleiteten Klasse Client.
 *
 * Client erbt von Person und fuegt eine Client-ID hinzu.
 */

/**
 * @class Client
 * @brief Ein Kunde im System – erbt von Person.
 *
 * Demonstriert:
 * - Oeffentliche Vererbung (@c public @c Person)
 * - Weiterleitung von Parametern an den Eltern-Konstruktor
 * - Zugriff auf @c protected Attribute der Elternklasse
 *
 * @see Person
 * @see Supplier
 */
class Client : public Person {

private:
    int clientId;           ///< Eindeutige Kundennummer

public:
    /**
     * @brief Default-Konstruktor.
     *
     * Ruft automatisch Person() auf und setzt clientId auf -1.
     */
    Client();

    /**
     * @brief Konstruktor mit allen Daten.
     *
     * Leitet Name und Alter ueber die Initializer List an
     * Person(string, int) weiter.
     *
     * @param n   Name des Clients (wird an Person weitergegeben)
     * @param a   Alter des Clients (wird an Person weitergegeben)
     * @param id  Eindeutige Client-ID
     */
    Client(std::string n, int a, int id);

    /**
     * @brief Gibt alle Client-Informationen aus.
     *
     * Greift auf @c name (public) und @c age (protected) aus Person zu.
     * Kann @b nicht auf @c password (private) aus Person zugreifen.
     */
    void showClientInfo() const;
};

#endif // CLIENT_H
