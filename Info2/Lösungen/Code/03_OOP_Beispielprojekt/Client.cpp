/**
 * @file Client.cpp
 * @brief Implementierung der abgeleiteten Klasse Client.
 *
 * Zeigt die Konstruktor-Reihenfolge bei Vererbung:
 * Zuerst wird der Person-Konstruktor aufgerufen, dann der Client-Konstruktor.
 */

#include "Client.h"
#include "Utility.h"
#include <iostream>

Client::Client() {
    clientId = -1;
    Utility::printSuccess("Client() default constructor called");
}

Client::Client(std::string n, int a, int id) : Person(n, a) {
    clientId = id;
    Utility::printSuccess("Client(name, age, id) constructor called");
}

void Client::showClientInfo() const {
    Utility::printKeyValue("Client ID", std::to_string(clientId));
    Utility::printKeyValue("Name", name);                   // public    in Person -> OK
    Utility::printKeyValue("Age", std::to_string(age));     // protected in Person -> OK in subclass

    // password ist private in Person -> NICHT zugaenglich!
    // Utility::printKeyValue("Password", password);  // COMPILE ERROR
}
