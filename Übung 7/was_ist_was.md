## 1. Wie ist ein C++-Projekt aufgebaut?

Ein C++-Projekt besteht typischerweise aus:

* **Header-Dateien (`.h` / `.hpp`)** – Schnittstellen / Deklarationen
* **Quellcode-Dateien (`.cpp`)** – Implementierungen / eigentlicher Code
* **Projekt-/Build-Konfiguration** – Einstellungen für Compiler, Linker, Libraries

Aus mehreren `.cpp`-Dateien wird am Ende ein **ausführbares Programm** oder eine **Library** gebaut.

---

## 2. Was ist eine `.h`-Datei (Header)?

* Enthält **Deklarationen**, z. B.:

  * Funktionsköpfe
  * Klassendeklarationen
  * Konstanten, Typdefintionen (`typedef`, `using`)
* Wird mit `#include` in `.cpp`-Dateien eingebunden.
* Idee: **Trennung von Schnittstelle und Implementierung**.

Beispiel `math_utils.h`:

```cpp
#pragma once

int add(int a, int b);   // Nur Deklaration
```

---

## 3. Was ist eine `.cpp`-Datei?

* Enthält die **Implementierung** der deklarierten Funktionen/Klassen.
* Jede `.cpp` wird vom Compiler separat übersetzt.

Beispiel `math_utils.cpp`:

```cpp
#include "math_utils.h"

int add(int a, int b) {
    return a + b;        // Implementierung
}
```

Beispiel `main.cpp`:

```cpp
#include <iostream>
#include "math_utils.h"

int main() {
    std::cout << add(2, 3) << std::endl;
    return 0;
}
```

---

## 4. Was ist ein Compiler?

* Programm, das **C++-Quellcode (.cpp)** in **Maschinencode** übersetzt.
* Schritte:

  1. Präprozessor ausführen (siehe unten)
  2. Jede `.cpp` in eine **Objektdatei** (`.o` / `.obj`) übersetzen
  3. Linker verbindet alle Objektdateien zu einer **EXE** oder **Library**

Typische Compiler: `g++`, `clang++`, MSVC (Visual Studio).

---

## 5. Was ist der Precompiler / Präprozessor?

* Läuft **vor** dem eigentlichen Compilieren.
* Bearbeitet alle Direktiven, die mit `#` anfangen:

  * `#include` – andere Dateien hineinkopieren
  * `#define` – Makros (Textersetzungen)
  * `#if`, `#ifdef`, `#ifndef` – bedingte Übersetzung
* Ergebnis ist eine „flache“ C++-Datei, die dann vom Compiler übersetzt wird.

---

### 6. Was ist `using namespace std;`?

* **`namespace`**
  Ein Namensraum bündelt Namen (Funktionen, Klassen usw.), damit es keine Namenskollisionen gibt.
  Die Standardbibliothek steckt im Namensraum `std`.

* **Wirkung von `using namespace std;`**
  Ermöglicht die Nutzung von Namen aus `std` **ohne** `std::` davor.

  ```cpp
  #include <iostream>
  using namespace std;

  int main() {
      cout << "Hallo";      // statt std::cout
  }
  ```

* **Problem**
  Holt **alle** Namen aus `std` in den globalen Namensraum → kann zu Namenskonflikten führen.
  Für kleine Beispiele okay, in größerem/sauberem Code besser `std::cout`, `std::string` usw. explizit schreiben.
---

## 7. Was ist `#define`?

* Definiert ein **Makro** (Textersetzung, kein richtiger Typ, keine Variable).
* Wird vom Präprozessor **einfach ersetzt**, noch bevor der Compiler loslegt.

Beispiele:

```cpp
#define PI 3.14159
#define MAX(a, b) ((a) > (b) ? (a) : (b))
```

* Überall im Code, wo `PI` steht, setzt der Präprozessor `3.14159` ein.
* Vorsicht: Makros haben **keine Typprüfung** und können leicht Fehler verursachen.
* In modernerem C++ nutzt man oft lieber `const` oder `constexpr` statt `#define` für Konstanten.

---

## 8. Was bedeutet „Build“?

„Build“ = **kompletter Bauprozess** eines Projekts:

1. Präprozessor ausführen (`#include`, `#define`, …)
2. Compiler übersetzt jede `.cpp` → Objektdatei
3. Linker verbindet alle Objektdateien + Libraries → Programm (z. B. `.exe`)

In IDEs (z. B. Visual Studio) steckt hinter „Build“ meist ein ganzer Satz von Befehlen und Einstellungen.

---

## 9. Was bedeutet „Clean“?

* „Clean“ löscht **alle erzeugten Build-Artefakte**:

  * Objektdateien (`.o` / `.obj`),
  * Zwischendateien,
  * alte EXE/Build-Outputs.
* Danach ist das Projekt „sauber“, als wäre es gerade frisch ausgecheckt.
* Nützlich, wenn:

  * der Build spinnt,
  * Einstellungen geändert wurden,
  * man sicherstellen will, dass **alles neu** übersetzt wird.

---

## 10. Was bedeutet „Run“?

* „Run“ startet das **fertig gebaute Programm**.
* Voraussetzungen:

  * Projekt wurde erfolgreich gebaut (keine Compile-/Link-Fehler)
  * ausführbare Datei ist vorhanden.
* In der IDE oft ein Button wie „Run“ oder „Start ohne Debugging“.

---

## 11. Was ist „Debugging“?

* Debugging = Programm **schrittweise ausführen**, um Fehler zu finden.
* Typische Funktionen im Debugger:

  * **Breakpoints** setzen: Programm hält an einer bestimmten Zeile.
  * **Step over / Step into / Step out**: Zeile für Zeile durchgehen.
  * **Variablen inspizieren**: Werte ansehen, live beobachten.
  * **Call Stack**: sehen, von welcher Funktion man woher kommt.
* Debug-Build enthält zusätzliche Infos (Symbole), ist meist langsamer, dafür besser analysierbar.

---

## 12. Was ist „nur“ Syntax Highlighting?

* Funktion des **Editors**, nicht des Compilers.
* Erkennung und farbliche Hervorhebung von:

  * Schlüsselwörtern (`int`, `if`, `class`, …)
  * Typen
  * Strings, Zahlen
  * Kommentaren
* Hilft beim Lesen und Erkennen von Fehlern, hat aber **keinen Einfluss** auf:

  * Kompilierung
  * Ausführung
  * Build-Ergebnis

Ein Editor kann **perfekte Syntax Highlighting-Farben** anzeigen, auch wenn der Code trotzdem nicht kompiliert.

--- 
