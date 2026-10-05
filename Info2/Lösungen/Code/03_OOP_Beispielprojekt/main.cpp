/**
 * @file main.cpp
 * @brief Einstiegspunkt – demonstriert alle OOP-Konzepte Schritt fuer Schritt.
 *
 * Dieses Programm zeigt:
 * 1. Konstruktor-Ueberladung (Person mit 0, 1 oder 2 Parametern)
 * 2. Vererbung (Client und Supplier erben von Person)
 * 3. Konstruktor-Reihenfolge (Eltern vor Kind)
 * 4. Zugriffsmodifizierer (private / protected / public)
 *
 * @note Kompilieren mit:
 *       g++ -o program main.cpp Person.cpp Client.cpp Supplier.cpp Utility.cpp
 */

#include "Person.h"
#include "Client.h"
#include "Supplier.h"
#include "Utility.h"

#include <iostream>
using namespace std;


int main() {

    // ==================================================
    //  SECTION 1: Constructor Overloading (Person)
    // ==================================================
    Utility::printHeader("1) CONSTRUCTOR OVERLOADING");

    Utility::printSubHeader("Person p1 no arguments");
    Person p1;
    p1.showInfo();

    Utility::printSubHeader("Person p2 name only");
    Person p2("Anna");
    p2.showInfo();

    Utility::printSubHeader("Person p3 name and age");
    Person p3("Max", 25);
    p3.showInfo();


    // ==================================================
    //  SECTION 2: Inheritance – Client
    // ==================================================
    //Utility::printHeader("2) INHERITANCE - Client");

    //Utility::printSubHeader("Client c1 default (watch constructor order!)");
    //Client c1;
    //c1.showClientInfo();

    //Utility::printSubHeader("Client c2 full constructor");
    //Client c2("Lisa", 30, 1001);
    //c2.showClientInfo();


    // ==================================================
    //  SECTION 3: Inheritance – Supplier
    // ==================================================
    //Utility::printHeader("3) INHERITANCE Supplier");

    //Utility::printSubHeader("Supplier s1 default");
    //Supplier s1;
    //s1.showSupplierInfo();

    //Utility::printSubHeader("Supplier s2 full constructor");
    //Supplier s2("Tom", 45, "FastParts GmbH");
    //s2.showSupplierInfo();

    //Utility::printSubHeader("Supplier s3 company only");
    //Supplier s3("QuickShip AG");
    //s3.showSupplierInfo();


    // ==================================================
    //  SECTION 4: Access Modifiers
    // ==================================================
    //Utility::printHeader("4) ACCESS MODIFIERS");

    //Utility::printSubHeader("From main() we can only access PUBLIC members");

    //Utility::printSuccess("p3.name is public  -->  " + p3.name);
    //Utility::printBlocked("p3.age is protected  -->  NOT accessible from main()");
    //Utility::printBlocked("p3.password is private  -->  NOT accessible from main()");

    //Utility::printSubHeader("Person CAN access its own private data");
    //p3.showPassword();

    //Utility::printSubHeader("Subclass CAN access protected data");
    //cout << "  (Client::showClientInfo accesses 'age' from Person)" << endl;
    //c2.showClientInfo();

    //Utility::printDivider();
    //Utility::printSubHeader("SUMMARY");
    //cout << "  private:    only inside the class itself" << endl;
    //cout << "  protected:  inside the class + its subclasses" << endl;
    //cout << "  public:     accessible from everywhere" << endl;
    //Utility::printDivider();

    return 0;
}
