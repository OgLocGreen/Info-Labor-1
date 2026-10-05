#ifndef PERSON_H       // Include Guard
#define PERSON_H

#include <string>

/**
 * @file Person.h
 * @brief Deklaration der Basisklasse Person.
 *
 * Person ist die Elternklasse fuer Client und Supplier.
 * Demonstriert: private / protected / public, Konstruktor-Ueberladung.
 */

/**
 * @class Person
 * @brief Basisklasse fuer alle Personen im System.
 *
 * Enthaelt grundlegende Attribute wie Name und Alter.
 * Dient als Elternklasse fuer Client und Supplier.
 *
 * - @c private:   password – nur innerhalb von Person zugaenglich
 * - @c protected: age      – auch in Kindklassen zugaenglich
 * - @c public:    name     – ueberall zugaenglich
 *
 * @see Client
 * @see Supplier
 */
class Person {

private:
    std::string password;   ///< Internes Passwort (nur in Person selbst zugaenglich)

protected:
    int age;                ///< Alter der Person (auch in Kindklassen zugaenglich)

public:
    std::string name;       ///< Oeffentlicher Name der Person

    /**
     * @brief Default-Konstruktor – erzeugt eine Person ohne Daten.
     *
     * Setzt Name auf "Unknown" und Alter auf 0.
     */
    Person();

    /**
     * @brief Konstruktor mit Name.
     * @param n  Name der Person
     */
    Person(std::string n);

    /**
     * @brief Konstruktor mit Name und Alter.
     * @param n  Name der Person
     * @param a  Alter der Person
     */
    Person(std::string n, int a);

    /**
     * @brief Gibt Name und Alter auf der Konsole aus.
     */
    void showInfo() const;

    /**
     * @brief Gibt das private Passwort aus.
     *
     * Nur Person selbst kann auf das private Attribut @c password zugreifen.
     * Diese Methode zeigt, dass private Daten intern nutzbar sind.
     */
    void showPassword() const;
};

#endif // PERSON_H
