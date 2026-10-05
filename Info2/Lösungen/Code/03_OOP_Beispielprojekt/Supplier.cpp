/**
 * @file Supplier.cpp
 * @brief Implementierung der abgeleiteten Klasse Supplier.
 *
 * Zeigt mehrere ueberladene Konstruktoren in einer Kindklasse
 * und die Weiterleitung an den Eltern-Konstruktor.
 */

#include "Supplier.h"
#include "Utility.h"
#include <iostream>

Supplier::Supplier() {
    company = "Unknown Company";
    Utility::printSuccess("Supplier() default constructor called");
}

Supplier::Supplier(std::string n, int a, std::string comp) : Person(n, a) {
    company = comp;
    Utility::printSuccess("Supplier(name, age, company) constructor called");
}

Supplier::Supplier(std::string comp) : Person() {
    company = comp;
    Utility::printSuccess("Supplier(company) constructor called");
}

void Supplier::showSupplierInfo() const {
    Utility::printKeyValue("Name", name);                   // public    -> OK
    Utility::printKeyValue("Age", std::to_string(age));     // protected -> OK in subclass
    Utility::printKeyValue("Company", company);

    // password ist private in Person -> NICHT zugaenglich!
    // Utility::printKeyValue("Password", password);  // COMPILE ERROR
}
