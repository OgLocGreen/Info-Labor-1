#ifndef SUPPLIER_H     // Include Guard
#define SUPPLIER_H

#include "Person.h"
#include <string>

/**
 * @file Supplier.h
 * @brief Deklaration der abgeleiteten Klasse Supplier.
 *
 * Supplier erbt von Person und fuegt einen Firmennamen hinzu.
 */

/**
 * @class Supplier
 * @brief Ein Lieferant im System – erbt von Person.
 *
 * Demonstriert:
 * - Oeffentliche Vererbung (@c public @c Person)
 * - Mehrere ueberladene Konstruktoren in einer Kindklasse
 * - Zugriff auf @c protected Attribute der Elternklasse
 *
 * @see Person
 * @see Client
 */
class Supplier : public Person {

private:
    std::string company;    ///< Name der Firma des Lieferanten

public:
    /**
     * @brief Default-Konstruktor.
     *
     * Ruft automatisch Person() auf und setzt company auf "Unknown Company".
     */
    Supplier();

    /**
     * @brief Konstruktor mit allen Daten.
     *
     * Leitet Name und Alter an Person(string, int) weiter.
     *
     * @param n     Name des Lieferanten (wird an Person weitergegeben)
     * @param a     Alter des Lieferanten (wird an Person weitergegeben)
     * @param comp  Firmenname des Lieferanten
     */
    Supplier(std::string n, int a, std::string comp);

    /**
     * @brief Konstruktor nur mit Firmenname.
     *
     * Ruft Person() Default-Konstruktor auf – Name und Alter
     * bleiben auf den Standardwerten.
     *
     * @param comp  Firmenname des Lieferanten
     */
    Supplier(std::string comp);

    /**
     * @brief Gibt alle Lieferanten-Informationen aus.
     *
     * Greift auf @c name (public) und @c age (protected) aus Person zu.
     * Kann @b nicht auf @c password (private) aus Person zugreifen.
     */
    void showSupplierInfo() const;
};

#endif // SUPPLIER_H
