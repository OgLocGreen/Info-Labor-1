# Recap – Pointer, Parameterübergabe und dynamische Speicherverwaltung

> **Info 2 · Übung 04** — Aufgabe: [Dynamische Speicherverwaltung (Übung 04.0)](../Aufgaben/04_00_Dynamische_Speicherverwaltung.md), [Funktionen mit Zeigerparametern (Übung 04.1)](../Aufgaben/04_01_Pointer.md) · Lösung: [Funktionen mit Zeigerparametern (Übung 04.1)](../Lösungen/04_01_Pointer_Lösung.md) · Hilfsmittel: Recap Pointer und Speicherverwaltung · siehe auch: [Übung 05 – Einfach verkettete Liste](../Aufgaben/05_Verkettete_Listen.md), [Lösung Übung 05](../Lösungen/05_Verkettete_Listen_Lösung.md)

---

## Inhalt

1. [Pointer (Zeiger)](#1-pointer-zeiger)
2. [Parameterübergabe an Funktionen](#2-parameterübergabe-an-funktionen)
   - 2.1 Call by Value
   - 2.2 Call by Reference (über Pointer)
   - 2.3 Call by Reference (über C++-Referenz `&`)
   - 2.4 Vergleich
3. [Stack und Heap — wo leben Variablen?](#3-stack-und-heap--wo-leben-variablen)
4. [Dynamische Speicherallokation mit `new` / `delete`](#4-dynamische-speicherallokation-mit-new--delete)
5. [Dynamische Speicherallokation mit `malloc` / `free`](#5-dynamische-speicherallokation-mit-malloc--free)
6. [Vergleich `new` vs. `malloc`](#6-vergleich-new-vs-malloc)
7. [Häufige Fehlerquellen](#7-häufige-fehlerquellen)

---

## 1. Pointer (Zeiger)

Ein **Pointer** ist eine Variable, die eine **Speicheradresse** speichert — also den Ort, an dem ein anderer Wert im Speicher liegt.

### Deklaration und wichtige Operatoren

| Operator | Bedeutung |
|---|---|
| `int* p` | Deklaration: `p` ist ein Pointer auf einen `int` |
| `&x` | **Adress-Operator**: liefert die Adresse der Variablen `x` |
| `*p` | **Dereferenzierungs-Operator**: liefert den Wert, auf den `p` zeigt |
| `nullptr` | Spezielle Adresse "zeigt auf nichts" (seit C++11) |

### Beispiel

```cpp
int x = 42;
int* p = &x;     // p enthält die Adresse von x

std::cout << x   << std::endl; // 42  (der Wert von x)
std::cout << &x  << std::endl; // z.B. 0x7ffe... (Adresse von x)
std::cout << p   << std::endl; // gleiche Adresse — was p speichert
std::cout << *p  << std::endl; // 42  (Wert hinter der Adresse)

*p = 100;                       // Wert hinter p ändern…
std::cout << x   << std::endl; // 100 (x wurde mitverändert!)
```

### Visualisierung

```
   Variable x          Pointer p
  ┌───────────┐       ┌───────────┐
  │    42     │ ◄─────│  0x7ffe…  │
  └───────────┘       └───────────┘
   Adresse: 0x7ffe…
```

### Wichtige Hinweise

- Ein **uninitialisierter Pointer** zeigt auf eine zufällige Adresse. Immer mit `nullptr` initialisieren!
- `*p` darf **nur** verwendet werden, wenn `p` auf gültigen Speicher zeigt (nicht `nullptr`!).

```cpp
int* p = nullptr;
if (p != nullptr) {
    std::cout << *p; // sicher
}
```

---

## 2. Parameterübergabe an Funktionen

In C++ gibt es **drei Wege**, Parameter an Funktionen zu übergeben.

### 2.1 Call by Value

Die Funktion erhält eine **Kopie** des übergebenen Wertes. Änderungen innerhalb der Funktion betreffen die Originalvariable **nicht**.

```cpp
void verdopple(int x) {
    x = x * 2;        // ändert nur die Kopie
}

int main() {
    int a = 5;
    verdopple(a);
    std::cout << a;   // Ausgabe: 5  (unverändert!)
}
```

**Wann verwenden?**
- Wenn die Funktion den Wert nur lesen soll
- Bei kleinen Datentypen (`int`, `double`, `bool`, …)

### 2.2 Call by Reference (über Pointer)

Statt eines Werts wird die **Adresse** übergeben. Die Funktion kann über Dereferenzierung den Originalwert modifizieren.

```cpp
void verdopple(int* x) {
    *x = *x * 2;      // verändert den Wert hinter der Adresse
}

int main() {
    int a = 5;
    verdopple(&a);    // Adresse von a übergeben
    std::cout << a;   // Ausgabe: 10
}
```

**Vorteile:** klassische C-Variante, explizit sichtbar an der Aufrufstelle (`&a`).
**Nachteile:** umständlichere Syntax (`*` und `&` ständig nötig), Pointer könnte `nullptr` sein.

### 2.3 Call by Reference (über C++-Referenz `&`)

C++ bietet eine **Referenz** als saubere Alternative. Eine Referenz ist ein **anderer Name** für eine bestehende Variable.

```cpp
void verdopple(int& x) {
    x = x * 2;        // x ist ein Alias — wirkt direkt auf das Original
}

int main() {
    int a = 5;
    verdopple(a);     // ohne &-Operator!
    std::cout << a;   // Ausgabe: 10
}
```

**Vorteile:** saubere Syntax, kann nicht `nullptr` sein, muss bei der Erzeugung initialisiert werden.
**Nachteile:** an der Aufrufstelle nicht sichtbar, dass die Variable verändert werden könnte.

> **Tipp:** Soll eine Referenz nur lesend sein, mit `const` markieren: `void ausgabe(const int& x);`

### 2.4 Vergleich

| Merkmal | Call by Value | Pointer (`int*`) | Referenz (`int&`) |
|---|---|---|---|
| Original veränderbar? | nein | ja | ja |
| Kann `nullptr` sein? | — | ja | nein |
| Kann umgesetzt werden? | — | ja (`p = &y;`) | nein |
| Aufruf-Syntax | `f(a)` | `f(&a)` | `f(a)` |
| Funktionsrumpf | `x` | `*x` | `x` |
| Speicherbedarf | Kopie | nur Adresse | nur Adresse |
| Typisch für | kleine Werte | C-Stil, optionale Parameter | C++-Stil, große Objekte |

```cpp
// Drei Varianten derselben Idee:
void f1(int  x);   // Value      — Kopie
void f2(int* x);   // Pointer    — Adresse, ggf. nullptr
void f3(int& x);   // Referenz   — Alias, niemals nullptr
```

---

## 3. Stack und Heap — wo leben Variablen?

Beim Programmstart erhält ein Programm vom Betriebssystem einen **Speicherbereich**, der grob in mehrere Zonen aufgeteilt ist. Die wichtigsten für uns: **Stack** und **Heap**.

### Speicherlayout eines Programms

```
       Hohe Adressen
   ┌─────────────────────┐
   │       Stack         │  ← wächst nach unten
   │         ▼           │     (lokale Variablen, Funktionsaufrufe)
   │                     │
   │     ↕  frei  ↕      │
   │                     │
   │         ▲           │
   │        Heap         │  ← wächst nach oben
   │                     │     (new, malloc)
   ├─────────────────────┤
   │ globale / statische │     (z. B. globale Variablen)
   │     Variablen       │
   ├─────────────────────┤
   │      Code (Text)    │     (das Programm selbst)
   └─────────────────────┘
       Niedrige Adressen
```

### Der Stack

Der **Stack** ist ein eng verwalteter Speicherbereich, der nach dem Prinzip **LIFO** (Last In, First Out) funktioniert — wie ein Stapel Teller.

**Eigenschaften:**

- Bei jedem **Funktionsaufruf** wird ein **Stack Frame** angelegt: er enthält Parameter, lokale Variablen und die Rücksprungadresse.
- Beim **Verlassen** der Funktion wird der Frame **automatisch** entfernt — kein `delete` nötig.
- **Sehr schnell** (nur ein Pointer wird verschoben).
- **Begrenzt groß** (typisch 1–8 MB pro Thread).

```cpp
void f() {
    int a = 5;            // a lebt auf dem Stack
    double b = 3.14;      // b lebt auf dem Stack
    int arr[100];         // auch dieses Array lebt auf dem Stack
}                         // Stack Frame wird hier abgebaut: a, b, arr verschwinden
```

### Der Heap

Der **Heap** (auch "freier Speicher") ist ein großer, ungeordneter Speicherbereich, in dem man **gezielt** Speicher anfordern kann.

**Eigenschaften:**

- Speicher wird **manuell** mit `new` (oder `malloc`) reserviert und mit `delete` (oder `free`) freigegeben.
- Lebensdauer ist **unabhängig** von Funktionen — Heap-Speicher überlebt Funktionsende.
- **Langsamer** als Stack-Allokation (Verwaltungsoverhead).
- **Praktisch unbegrenzt** (durch verfügbaren Arbeitsspeicher).
- Zugriff **nur über Pointer** möglich, da man die Adresse nicht zur Compile-Zeit kennt.

```cpp
void f() {
    int* p = new int(42); // *p lebt auf dem Heap
                          // p selbst (der Pointer) lebt auf dem Stack
}                         // p verschwindet — *p existiert weiter — MEMORY LEAK!
```

### Wo lebt was? Übersicht

| Variablenart | Speicherbereich | Lebensdauer |
|---|---|---|
| Lokale Variable in Funktion | **Stack** | bis Funktionsende |
| Funktionsparameter (by value) | **Stack** | bis Funktionsende |
| Lokales Array fester Größe `int a[10];` | **Stack** | bis Funktionsende |
| Lokaler Pointer `int* p;` | **Stack** | bis Funktionsende |
| Mit `new` / `malloc` reserviert | **Heap** | bis `delete` / `free` |
| Globale Variable | Datensegment | gesamtes Programm |
| `static` Variable | Datensegment | gesamtes Programm |
| String-Literal `"Hallo"` | Codesegment (read-only) | gesamtes Programm |

### Wichtig: Pointer und Daten können in unterschiedlichen Bereichen liegen!

```cpp
void f() {
    int* p = new int(42);
    //  └─ Stack          └─ Heap
}
```

```
   Stack                      Heap
  ┌───────────┐              ┌───────────┐
  │ p: 0x9a…  │ ─────────────│    42     │
  └───────────┘              └───────────┘
                              Adresse: 0x9a…
```

Wenn `f()` endet, verschwindet `p` vom Stack — der `int` mit Wert 42 bleibt aber auf dem Heap liegen. Da nun niemand mehr seine Adresse kennt, ist er **unerreichbar** und für immer verloren: ein **Memory Leak**.

### Lebensdauer im Vergleich

```cpp
int global = 100;             // Datensegment, lebt vom Programmstart bis -ende

void f() {
    int local = 1;            // Stack: lebt von Zeile 4 bis Zeile 8
    static int counter = 0;   // Datensegment: einmalig initialisiert,
    counter++;                //   behält Wert über Funktionsaufrufe hinweg
    int* heap = new int(7);   // heap (Pointer): Stack
                              // *heap (Wert 7): Heap, lebt bis delete
    delete heap;              // hier wird der Heap-Speicher freigegeben
}                             // local und heap (Pointer) werden hier abgebaut
```

### Wann Stack, wann Heap?

| Situation | Empfehlung |
|---|---|
| Größe zur Compile-Zeit bekannt, kleine Variablen | **Stack** |
| Variable lebt nur während der Funktion | **Stack** |
| Größe erst zur Laufzeit bekannt (`int n; cin >> n;`) | **Heap** |
| Datenstruktur soll Funktion überleben | **Heap** |
| Sehr große Objekte (z. B. Array mit 10 Mio. Einträgen) | **Heap** (Stack zu klein!) |
| Polymorphie / dynamische Typen | **Heap** |

### Stack Overflow vs. Memory Leak

Beide sind klassische Speicherprobleme — aber unterschiedliche!

| Problem | Wo? | Ursache |
|---|---|---|
| **Stack Overflow** | Stack | Stack ist voll (z. B. zu tiefe Rekursion oder riesiges lokales Array) — **Programmabsturz** |
| **Memory Leak** | Heap | `new` ohne passendes `delete` — Speicher wird nie freigegeben, Programm braucht immer mehr RAM |

```cpp
// Stack Overflow durch unendliche Rekursion:
void f() { f(); }              // jeder Aufruf legt einen neuen Stack Frame an

// Stack Overflow durch zu großes lokales Array:
void g() { int riesig[10'000'000]; }  // passt nicht in 1–8 MB Stack

// Memory Leak:
void h() { int* p = new int(5); }  // p verschwindet, *5 bleibt unerreichbar
```

---

## 4. Dynamische Speicherallokation mit `new` / `delete`

Variablen, die innerhalb einer Funktion deklariert werden, liegen auf dem **Stack** und werden automatisch entfernt. Manchmal braucht man Speicher, der **länger lebt** oder dessen **Größe erst zur Laufzeit** bekannt ist — dafür gibt es den **Heap** (auch "freier Speicher" genannt).

### Einzelne Objekte

```cpp
int* p = new int;        // Speicher für einen int reservieren
*p = 42;
std::cout << *p;
delete p;                // Speicher wieder freigeben
p = nullptr;             // gute Praxis: Pointer auf nullptr setzen
```

### Mit Initialwert

```cpp
int*    p1 = new int(42);          // int mit Wert 42
double* p2 = new double(3.14);
```

### Arrays

```cpp
int n = 10;
int* arr = new int[n];   // Array mit n Elementen reservieren

for (int i = 0; i < n; ++i) {
    arr[i] = i * i;
}

delete[] arr;            // !!! delete[] für Arrays !!!
arr = nullptr;
```

### Objekte einer Klasse

`new` ruft den **Konstruktor** automatisch auf, `delete` ruft den **Destruktor**:

```cpp
class Person {
public:
    Person(std::string name) { std::cout << "Konstruktor: " << name << "\n"; }
    ~Person()                { std::cout << "Destruktor\n"; }
};

Person* p = new Person("Anna");  // Konstruktor wird aufgerufen
delete p;                         // Destruktor wird aufgerufen
```

### Goldene Regeln

| Reserviert mit | Freigeben mit |
|---|---|
| `new T`     | `delete p`   |
| `new T[n]`  | `delete[] p` |

> **Wichtig:** `new` und `delete` müssen immer paarweise auftreten — sonst entsteht ein **Memory Leak** (reservierter Speicher, der nie zurückgegeben wird).

---

## 5. Dynamische Speicherallokation mit `malloc` / `free`

`malloc` (memory allocate) stammt aus C und ist in C++ über `<cstdlib>` weiterhin verfügbar. Die Verwendung ist **rohem Bytewerk** näher und kennt **keine Klassen**.

### Grundlegende Verwendung

```cpp
#include <cstdlib>   // für malloc und free

int* p = (int*) malloc(sizeof(int));   // Speicher für 1 int (in Bytes)
if (p == nullptr) {                     // !!! immer prüfen !!!
    std::cerr << "Speicheranforderung fehlgeschlagen\n";
    return 1;
}
*p = 42;
free(p);                                // Freigabe
p = nullptr;
```

### Wichtige Eigenschaften

- `malloc(n)` reserviert `n` **Bytes** und gibt einen `void*` zurück. In C++ muss explizit gecastet werden: `(int*) malloc(...)`.
- Bei Fehlschlag (z. B. kein Speicher mehr) gibt `malloc` `nullptr` zurück — dies muss überprüft werden.
- `malloc` **ruft keinen Konstruktor** auf — der reservierte Speicher enthält undefinierte Werte.
- Freigabe mit `free`, **niemals** mit `delete`.

### Array

```cpp
int n = 10;
int* arr = (int*) malloc(n * sizeof(int));  // n * sizeof(int) Bytes
for (int i = 0; i < n; ++i) {
    arr[i] = i;
}
free(arr);
```

### Warum `malloc` in C++ meist vermeiden?

Bei Klassen ist `malloc` gefährlich, weil **kein Konstruktor läuft**:

```cpp
class Person {
    std::string name;
public:
    Person() : name("unbekannt") {}
};

Person* p = (Person*) malloc(sizeof(Person));
// p->name ist NICHT initialisiert -> undefiniertes Verhalten!
free(p);   // ruft auch keinen Destruktor auf -> Speicherleck
```

Daher: in C++ **immer `new`/`delete`** für Objekte verwenden, `malloc` höchstens für rohe Speicherblöcke (z. B. bei Schnittstellen zu C-Bibliotheken).

---

## 6. Vergleich `new` vs. `malloc`

| Merkmal | `new` / `delete` (C++) | `malloc` / `free` (C) |
|---|---|---|
| Header | keiner nötig (Sprachfeature) | `<cstdlib>` |
| Größenangabe | typbasiert: `new int` | byteweise: `malloc(sizeof(int))` |
| Rückgabetyp | typisierter Pointer (`int*`) | `void*` — Cast nötig |
| Konstruktor wird aufgerufen? | **ja** | nein |
| Destruktor wird aufgerufen? | **ja** (durch `delete`) | nein |
| Fehlerbehandlung | wirft `std::bad_alloc` (Exception) | gibt `nullptr` zurück |
| Größe ändern möglich? | nein | ja, mit `realloc` |
| Freigabe | `delete` / `delete[]` | `free` |
| Empfohlen in C++? | **ja** | nur in Spezialfällen |

### Niemals mischen!

```cpp
int* a = new int(5);
free(a);          // FALSCH — undefiniertes Verhalten

int* b = (int*) malloc(sizeof(int));
delete b;         // FALSCH — undefiniertes Verhalten
```

---

## 7. Häufige Fehlerquellen

### Memory Leak

```cpp
void f() {
    int* p = new int(42);
    return;          // p geht verloren — Speicher nie freigegeben!
}
```
**Lösung:** `delete p;` vor dem `return`.

### Dangling Pointer

```cpp
int* p = new int(5);
delete p;
std::cout << *p;     // FEHLER — Speicher schon freigegeben
```
**Lösung:** nach `delete` immer `p = nullptr;` setzen.

### Double Free

```cpp
int* p = new int(5);
delete p;
delete p;            // FEHLER — derselbe Speicher zweimal freigegeben
```
**Lösung:** ebenfalls `p = nullptr;` nach erstem `delete`.

### Falsche Freigabeform

```cpp
int* arr = new int[10];
delete arr;          // FEHLER — muss delete[] sein
```

### Dereferenzierung von `nullptr`

```cpp
int* p = nullptr;
*p = 5;              // CRASH (Segmentation Fault)
```

---

## Merksatz

> **Jedes `new` braucht ein `delete`. Jedes `new[]` braucht ein `delete[]`. Jedes `malloc` braucht ein `free`. Niemals mischen.**

In modernem C++ (ab C++11) sollte man `new`/`delete` und `malloc`/`free` möglichst durch **Smart Pointer** (`std::unique_ptr`, `std::shared_ptr`) und **Container** (`std::vector`, `std::string`) ersetzen — diese kümmern sich automatisch um die Freigabe. Für die Einführung in die Speicherverwaltung ist das manuelle Modell aber unerlässlich, um zu verstehen, was im Hintergrund passiert.
