/**
 * @file Person.cpp
 * @brief Implementierung der Basisklasse Person.
 *
 * Enthaelt die Konstruktoren und Methoden von Person.
 * Die Deklarationen stehen in Person.h.
 */

#include "Person.h"
#include "Utility.h"
#include <iostream>

Person::Person() {
    name     = "Unknown";
    age      = 0;
    password = "default";
    Utility::printSuccess("Person() default constructor called");
}

Person::Person(std::string n) {
    name     = n;
    age      = 0;
    password = "default";
    Utility::printSuccess("Person(name) constructor called");
}

Person::Person(std::string n, int a) {
    name     = n;
    age      = a;
    password = "secret123";
    Utility::printSuccess("Person(name, age) constructor called");
}

void Person::showInfo() const {
    Utility::printKeyValue("Name", name);
    Utility::printKeyValue("Age", std::to_string(age));
}

void Person::showPassword() const {
    Utility::printKeyValue("Password", password);
}
