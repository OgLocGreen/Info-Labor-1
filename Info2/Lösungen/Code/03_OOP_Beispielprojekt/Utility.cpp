/**
 * @file Utility.cpp
 * @brief Implementierung der Utility-Hilfsfunktionen.
 *
 * Enthaelt die Logik fuer formatierte Konsolenausgaben.
 * Die Deklarationen stehen in Utility.h.
 */

#include "Utility.h"
#include <iostream>

namespace Utility {

    void printHeader(const std::string& title) {
        std::string border(title.length() + 6, '=');
        std::cout << "\n" << border << std::endl;
        std::cout << "|| " << title << " ||" << std::endl;
        std::cout << border << std::endl;
    }

    void printSubHeader(const std::string& title) {
        std::cout << "\n--- " << title << " ---" << std::endl;
    }

    void printDivider() {
        std::cout << "----------------------------------------" << std::endl;
    }

    void printKeyValue(const std::string& key, const std::string& value) {
        std::cout << "  ";
        for (int i = key.length(); i < 15; i++) std::cout << " ";
        std::cout << key << " : " << value << std::endl;
    }

    void printSuccess(const std::string& message) {
        std::cout << "  [OK] " << message << std::endl;
    }

    void printBlocked(const std::string& message) {
        std::cout << "  [XX] " << message << std::endl;
    }

}
