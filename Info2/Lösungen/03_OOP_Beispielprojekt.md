# Lösung Übung 03 – OOP-Beispielprojekt: Klassen & Vererbung

> **Info 2 · Übung 03** — Aufgabe: [Vererbung & Polymorphie (Übung 03.0)](../Aufgaben/03_00_Vererbung_Polymorphie.md), [Vererbung (Übung 03.1)](../Aufgaben/03_01_Vererbung.md) · Lösung: OOP-Beispielprojekt · Hilfsmittel: [Visual Studio Tipps und Doxygen](../Hilfsmittel/03_Visual_Studio_Tipps_und_Doxygen.md)

---

Dieses Beispielprojekt veranschaulicht die Grundlagen von Klassen und Vererbung (Zugriffsmodifizierer, Konstruktor-Überladung, Weiterleitung an den Eltern-Konstruktor, Aufteilung in `.h`/`.cpp`) an der Basisklasse `Person` mit den abgeleiteten Klassen `Client` und `Supplier`. Es ist **keine 1:1-Musterlösung** zu einer Aufgabe aus Übung 03.0 oder 03.1 – am nächsten liegt es an Übung 03.1, Aufgabe 1 (Basisklasse `Person` mit abgeleiteten Klassen, Sichtbarkeit von `protected`-Attributen, Objekte anlegen und ausgeben). Die Bankkonten-Aufgaben (Übung 03.0, Aufgaben 1–3; Übung 03.1, Aufgabe 2), das UML-Beispiel (Übung 03.1, Aufgabe 3) sowie `virtual`/`override` und dynamische Bindung werden hier nicht behandelt.

**Musterlösungen zu den Aufgaben aus Übung 03.0 und 03.1:** _Noch keine Musterlösung vorhanden._

**Themen:** Klassen, Vererbung, Konstruktor-Überladung, Zugriffsmodifizierer, modularer Aufbau

---

## Dateiübersicht

Der Quellcode liegt in [Code/03_OOP_Beispielprojekt/](Code/03_OOP_Beispielprojekt/) und ist am Ende dieses Dokuments vollständig abgedruckt (siehe [Quellcode](#quellcode)).

```
Code/03_OOP_Beispielprojekt/
│
├── main.cpp            Einstiegspunkt – nutzt alle Module, kennt nur die Header
│
├── Person.h            Deklaration der Basisklasse Person
├── Person.cpp          Implementierung der Basisklasse Person
│
├── Client.h            Deklaration der abgeleiteten Klasse Client
├── Client.cpp          Implementierung der abgeleiteten Klasse Client
│
├── Supplier.h          Deklaration der abgeleiteten Klasse Supplier
├── Supplier.cpp        Implementierung der abgeleiteten Klasse Supplier
│
├── Utility.h           Deklaration von Hilfsfunktionen (Terminalausgabe)
└── Utility.cpp         Implementierung der Hilfsfunktionen
```

### Kompilieren und Ausführen

```bash
cd Code/03_OOP_Beispielprojekt
g++ -o program main.cpp Person.cpp Client.cpp Supplier.cpp Utility.cpp
./program
```

---

## 1. Modularer Aufbau (.h und .cpp)

In C++ trennt man **Deklaration** und **Implementierung**:

| Datei  | Inhalt                            | Zweck                                         |
|--------|-----------------------------------|-----------------------------------------------|
| `.h`   | Klassen-Definition, Methodenköpfe | Sagt **was** existiert (die "Versprechen")    |
| `.cpp` | Methodenrümpfe, Logik             | Sagt **wie** es funktioniert (die Umsetzung)  |

### Warum?

- **Übersicht:** Die `.h`-Datei ist wie ein Inhaltsverzeichnis – man sieht sofort, welche Methoden eine Klasse hat.
- **Kompilierung:** Jede `.cpp`-Datei wird einzeln kompiliert. Ändert man nur `Client.cpp`, muss `Person.cpp` nicht neu kompiliert werden.
- **Kapselung:** `main.cpp` braucht nur `#include "Client.h"` – es muss nicht wissen, wie `Client` intern funktioniert.

### Include Guards

Jede `.h`-Datei hat am Anfang:

```cpp
#ifndef PERSON_H
#define PERSON_H
// ... Inhalt ...
#endif
```

Das verhindert, dass der Compiler die Datei mehrfach einbindet, wenn sie aus verschiedenen Dateien inkludiert wird (z. B. `Client.h` inkludiert `Person.h`, und `main.cpp` inkludiert beide).

---

## 2. Klassen (class)

Eine Klasse ist ein **Bauplan** für Objekte. Sie bündelt Daten (Attribute) und Funktionen (Methoden):

```cpp
class Person {
private:
    string password;     // Attribut – nur intern sichtbar

protected:
    int age;             // Attribut – auch für Kindklassen sichtbar

public:
    string name;         // Attribut – überall sichtbar

    Person();            // Konstruktor
    void showInfo();     // Methode
};
```

### Objekt erzeugen

```cpp
Person p("Max", 25);    // Ruft den Konstruktor Person(string, int) auf
p.showInfo();            // Ruft die Methode auf dem Objekt auf
```

---

## 3. Zugriffsmodifizierer (private / protected / public)

| Modifizierer | Innerhalb der Klasse | In Kindklassen | Von außen (main) |
|:-------------|:--------------------:|:--------------:|:----------------:|
| `private`    | ✅                   | ❌             | ❌               |
| `protected`  | ✅                   | ✅             | ❌               |
| `public`     | ✅                   | ✅             | ✅               |

### Im Projekt

```
Person:
    private:    password    → Nur Person selbst kann darauf zugreifen
    protected:  age         → Person + Client + Supplier können darauf zugreifen
    public:     name        → Jeder kann darauf zugreifen (auch main())
```

### Beispiel

```cpp
Person p("Max", 25);
cout << p.name;         // OK       – name ist public
cout << p.age;          // FEHLER   – age ist protected
cout << p.password;     // FEHLER   – password ist private

// Aber INNERHALB von Client:
void Client::showClientInfo() {
    cout << name;       // OK – public
    cout << age;        // OK – protected, und Client erbt von Person
    cout << password;   // FEHLER – private bleibt private
}
```

---

## 4. Konstruktor-Überladung (Constructor Overloading)

Eine Klasse kann **mehrere Konstruktoren** haben, solange sie sich in den Parametern unterscheiden:

```cpp
Person();                    // Default – keine Parameter
Person(string n);            // Nur Name
Person(string n, int a);     // Name und Alter
```

Der Compiler wählt automatisch den passenden Konstruktor anhand der übergebenen Argumente:

```cpp
Person p1;                   // → ruft Person()
Person p2("Anna");           // → ruft Person(string)
Person p3("Max", 25);        // → ruft Person(string, int)
```

### Warum?

Überladung macht eine Klasse flexibel – man kann Objekte mit unterschiedlich vielen Informationen erzeugen, ohne verschiedene Klassennamen zu brauchen.

---

## 5. Vererbung (Inheritance)

Eine Klasse kann von einer anderen Klasse **erben**. Die Kindklasse übernimmt alle `public`- und `protected`-Mitglieder der Elternklasse:

```
        Person           ← Basisklasse (Eltern)
       /      \
    Client   Supplier    ← Abgeleitete Klassen (Kinder)
```

### Syntax

```cpp
class Client : public Person {
    // Client hat automatisch: name, age, showInfo(), ...
    // Client hat NICHT: password (private in Person)
};
```

### Konstruktor-Reihenfolge

Beim Erzeugen einer Kindklasse wird **zuerst** der Konstruktor der Elternklasse aufgerufen:

```
Client c("Lisa", 30, 1001);
→  1. Person("Lisa", 30)    wird aufgerufen    (Eltern zuerst!)
→  2. Client(...)           wird danach aufgerufen
```

### Konstruktor weiterleiten (Initializer List)

Mit `: Person(n, a)` übergibt man Werte an den Eltern-Konstruktor:

```cpp
Client::Client(string n, int a, int id) : Person(n, a) {
    clientId = id;   // Nur das Client-eigene Attribut setzen
}
```

Ohne diese Weiterleitung würde automatisch `Person()` (der Default) aufgerufen werden.

---

## 6. Zusammenfassung auf einen Blick

| Konzept                  | Was es bedeutet                                              |
|:-------------------------|:-------------------------------------------------------------|
| **Klasse**               | Bauplan für Objekte (Attribute + Methoden)                   |
| **Objekt**               | Konkrete Instanz einer Klasse                                |
| **private**              | Nur innerhalb der eigenen Klasse zugänglich                  |
| **protected**            | Eigene Klasse + Kindklassen                                  |
| **public**               | Überall zugänglich                                           |
| **Konstruktor**          | Spezielle Methode, wird beim Erzeugen automatisch aufgerufen |
| **Überladung**           | Mehrere Konstruktoren mit verschiedenen Parametern           |
| **Vererbung**            | Kindklasse erbt Attribute und Methoden der Elternklasse      |
| **Initializer List**     | `: Person(n, a)` – leitet Werte an den Eltern-Konstruktor    |
| **Include Guard**        | `#ifndef` / `#define` – verhindert doppeltes Einbinden       |
| **.h / .cpp Trennung**   | Deklaration (was) vs. Implementierung (wie)                  |

---

## Konsolenausgabe (Auszug)

> **Hinweis:** In der aktuellen `main.cpp` sind die Abschnitte 2–4 auskommentiert. Die Ausgaben zu Client und zu den Zugriffsmodifizierern erscheinen erst, wenn diese Abschnitte wieder einkommentiert werden (Abschnitt 4 verwendet das Objekt `c2` aus Abschnitt 2).

```
================================
|| 1) CONSTRUCTOR OVERLOADING ||
================================

--- Person p1 no arguments ---
  [OK] Person() default constructor called
             Name : Unknown
              Age : 0

=============================
|| 2) INHERITANCE - Client ||
=============================

--- Client c2 full constructor ---
  [OK] Person(name, age) constructor called       ← Eltern zuerst!
  [OK] Client(name, age, id) constructor called   ← Dann Kind
        Client ID : 1001
             Name : Lisa
              Age : 30

=========================
|| 4) ACCESS MODIFIERS ||
=========================
  [OK] p3.name is public  -->  Max
  [XX] p3.age is protected  -->  NOT accessible from main()
  [XX] p3.password is private  -->  NOT accessible from main()
```

---

## Quellcode

Alle Dateien aus [Code/03_OOP_Beispielprojekt/](Code/03_OOP_Beispielprojekt/) unverändert.

### Person.h

```cpp
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
```

### Person.cpp

```cpp
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
```

### Client.h

```cpp
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
```

### Client.cpp

```cpp
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
```

### Supplier.h

```cpp
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
```

### Supplier.cpp

```cpp
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
```

### Utility.h

```cpp
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
```

### Utility.cpp

```cpp
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
```

### main.cpp

```cpp
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
```
