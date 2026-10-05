#ifndef UTILITY_H      // Include Guard: prevents this file from being
#define UTILITY_H      // included more than once during compilation

#include <string>

/**
 * @file Utility.h
 * @brief Hilfsfunktionen fuer formatierte Terminalausgaben.
 *
 * Dieses Modul hat nichts mit der Person/Client/Supplier-Hierarchie zu tun.
 * Es zeigt, dass Module unabhaengig voneinander existieren koennen.
 */

/**
 * @namespace Utility
 * @brief Sammlung von Hilfsfunktionen fuer huebsche Konsolenausgaben.
 */
namespace Utility {

    /**
     * @brief Gibt einen Titel in einer Box aus.
     *
     * Erzeugt eine Zeile mit '=' Zeichen ueber und unter dem Titel.
     *
     * @param title  Der Text, der in der Box angezeigt wird
     */
    void printHeader(const std::string& title);

    /**
     * @brief Gibt einen Untertitel mit Strichen aus.
     * @param title  Der Text des Untertitels
     */
    void printSubHeader(const std::string& title);

    /**
     * @brief Gibt eine horizontale Trennlinie aus.
     */
    void printDivider();

    /**
     * @brief Gibt ein Key-Value-Paar rechtsbuendig formatiert aus.
     * @param key    Der Schluessel (z.B. "Name")
     * @param value  Der Wert (z.B. "Max")
     */
    void printKeyValue(const std::string& key, const std::string& value);

    /**
     * @brief Gibt eine Erfolgsmeldung mit [OK] Prefix aus.
     * @param message  Die Nachricht
     */
    void printSuccess(const std::string& message);

    /**
     * @brief Gibt eine Fehlermeldung mit [XX] Prefix aus.
     * @param message  Die Nachricht
     */
    void printBlocked(const std::string& message);

}

#endif // UTILITY_H
