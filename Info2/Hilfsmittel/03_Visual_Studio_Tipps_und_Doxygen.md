# Anleitung – Visual Studio: Tipps, Shortcuts & Doxygen

> **Info 2 · Übung 03** — Aufgabe: [Vererbung & Polymorphie (Übung 03.0)](../Aufgaben/03_00_Vererbung_Polymorphie.md), [Vererbung (Übung 03.1)](../Aufgaben/03_01_Vererbung.md) · Lösung: [OOP-Beispielprojekt](../Lösungen/03_OOP_Beispielprojekt.md) · Hilfsmittel: Anleitung Visual Studio – Tipps, Shortcuts & Doxygen

---

> **Praktische Tipps für effizientes Arbeiten mit C++ in Visual Studio**  
> Navigation, IntelliSense, Tastenkombinationen und automatische Dokumentation

---

## 1. Navigation – In Klassen und Methoden springen

Die wichtigsten Shortcuts, um sich schnell durch modularen Code zu bewegen:

### Zur Definition springen

| Aktion                            | Shortcut                       | Beschreibung                                                                 |
|:----------------------------------|:-------------------------------|:-----------------------------------------------------------------------------|
| **Go to Definition**              | `F12`                          | Springt von der Nutzung direkt zur Definition (z.B. von `p.showInfo()` → `Person.cpp`) |
| **Peek Definition**               | `Alt + F12`                    | Zeigt die Definition in einem kleinen Fenster an, ohne die aktuelle Datei zu verlassen |
| **Go to Declaration**             | `Strg + F12`                   | Springt zur Deklaration in der `.h`-Datei                                    |
| **Navigate Backward**             | `Strg + -`                     | Springt zurück zur vorherigen Position (nach F12)                            |
| **Navigate Forward**              | `Strg + Shift + -`             | Springt wieder vorwärts                                                      |

### Beispiel-Workflow

```
main.cpp:   Client c2("Lisa", 30, 1001);
                    ^
                    |
            F12 auf "Client" drücken
                    |
                    ↓
Client.h:   Client(std::string n, int a, int id);     ← Deklaration

            Nochmal F12 auf die Deklaration
                    |
                    ↓
Client.cpp: Client::Client(string n, int a, int id) : Person(n, a) { ... }  ← Implementierung

            Strg + -  → springt zurück zu main.cpp
```

### Referenzen finden

| Aktion                            | Shortcut                       | Beschreibung                                                                 |
|:----------------------------------|:-------------------------------|:-----------------------------------------------------------------------------|
| **Find All References**           | `Shift + F12`                  | Zeigt alle Stellen, wo eine Klasse/Methode/Variable benutzt wird             |
| **Go to Symbol**                  | `Strg + T`                     | Suche nach Klassen, Methoden, Variablen im ganzen Projekt                    |

---

## 2. IntelliSense – Hover & Parameterinfo

Visual Studio zeigt automatisch Informationen an, wenn man mit der Maus über Code fährt oder tippt.

### Hover-Info

Einfach die **Maus über einen Bezeichner halten** (Klasse, Methode, Variable) – es erscheint ein Tooltip mit:

- Typ und Signatur der Methode
- Welche Parameter erwartet werden
- Den Doxygen-Kommentar (wenn vorhanden – siehe Abschnitt 4!)

### Parameter-Hilfe beim Tippen

| Aktion                            | Shortcut                       | Beschreibung                                                                 |
|:----------------------------------|:-------------------------------|:-----------------------------------------------------------------------------|
| **Parameter Info**                | `Strg + Shift + Leertaste`     | Zeigt die erwarteten Parameter an, während man tippt                         |
| **Quick Info (Hover manuell)**    | `Strg + K, Strg + I`          | Zeigt die Hover-Info ohne Maus an                                            |
| **Autocomplete**                  | `Strg + Leertaste`            | Öffnet die Vorschlagsliste                                                   |

### Beispiel

```cpp
Client c2(   // ← Hier Strg+Shift+Leertaste drücken
             // Tooltip zeigt: Client(string n, int a, int id)
             // und den Doxygen-Kommentar dazu
```

Wenn die Methode überladen ist, kann man mit den **Pfeiltasten ↑↓** zwischen den verschiedenen Überladungen wechseln.

---

## 3. Allgemeine Shortcuts

### Code bearbeiten

| Aktion                            | Shortcut                       |
|:----------------------------------|:-------------------------------|
| Zeile auskommentieren             | `Strg + K, Strg + C`          |
| Kommentar entfernen               | `Strg + K, Strg + U`          |
| Zeile duplizieren                 | `Strg + D`                    |
| Zeile verschieben (hoch/runter)   | `Alt + ↑ / ↓`                 |
| Alles formatieren (Einrückung)    | `Strg + K, Strg + D`          |
| Umbenennen (Refactor)             | `Strg + R, Strg + R`          |
| Rückgängig                        | `Strg + Z`                    |
| Wiederholen                       | `Strg + Y`                    |

### Suchen & Navigieren

| Aktion                            | Shortcut                       |
|:----------------------------------|:-------------------------------|
| Suchen                            | `Strg + F`                    |
| Suchen & Ersetzen                 | `Strg + H`                    |
| Im gesamten Projekt suchen        | `Strg + Shift + F`            |
| Zu Zeilennummer springen          | `Strg + G`                    |
| Datei schnell öffnen              | `Strg + T`                    |

### Build & Debug

| Aktion                            | Shortcut                       |
|:----------------------------------|:-------------------------------|
| Kompilieren (Build)               | `Strg + Shift + B`            |
| Starten mit Debugger              | `F5`                          |
| Starten ohne Debugger             | `Strg + F5`                   |
| Breakpoint setzen/entfernen       | `F9`                          |
| Nächste Zeile (Step Over)         | `F10`                         |
| In Methode rein (Step Into)       | `F11`                         |
| Aus Methode raus (Step Out)       | `Shift + F11`                 |

---

## 4. Doxygen – Code-Dokumentation

### Was ist Doxygen?

Doxygen ist ein Tool, das aus speziellen Kommentaren im Code automatisch eine **HTML- oder PDF-Dokumentation** generiert – ähnlich wie JavaDoc für Java.

### Doxygen-Kommentare schreiben

In Visual Studio tippt man `/**` über einer Methode und drückt `Enter` – das Grundgerüst wird automatisch erzeugt.

#### Vorher (ohne Doxygen)

```cpp
// Konstruktor mit allen Parametern
Client(string n, int a, int id);
```

#### Nachher (mit Doxygen)

```cpp
/**
 * @brief Erstellt einen neuen Client mit allen Daten.
 *
 * Ruft intern den Person-Konstruktor mit Name und Alter auf
 * und setzt die Client-ID.
 *
 * @param n     Name des Clients
 * @param a     Alter des Clients
 * @param id    Eindeutige Client-ID
 */
Client(string n, int a, int id);
```

### Die wichtigsten Doxygen-Tags

| Tag                | Bedeutung                                    | Beispiel                              |
|:-------------------|:---------------------------------------------|:--------------------------------------|
| `@brief`           | Kurzbeschreibung der Methode/Klasse          | `@brief Erstellt einen neuen Client`  |
| `@param`           | Beschreibt einen Parameter                   | `@param n Name des Clients`           |
| `@return`          | Beschreibt den Rückgabewert                  | `@return true wenn erfolgreich`       |
| `@note`            | Zusätzlicher Hinweis                         | `@note Ruft Person() intern auf`      |
| `@see`             | Verweis auf verwandte Klasse/Methode         | `@see Person::showInfo()`             |
| `@deprecated`      | Markiert als veraltet                        | `@deprecated Nutze newMethod()`       |

### Klassen dokumentieren

```cpp
/**
 * @class Person
 * @brief Basisklasse für alle Personen im System.
 *
 * Enthält grundlegende Attribute wie Name und Alter.
 * Dient als Elternklasse für Client und Supplier.
 *
 * @see Client
 * @see Supplier
 */
class Person { ... };
```

### Attribute dokumentieren

```cpp
class Person {
private:
    std::string password;   ///< Internes Passwort (nur in Person zugänglich)

protected:
    int age;                ///< Alter der Person (auch in Kindklassen zugänglich)

public:
    std::string name;       ///< Öffentlicher Name der Person
};
```

Das `///<` ist ein Doxygen-Inline-Kommentar – er gehört zum Element **davor** (links davon).

### Warum Doxygen nutzen?

- **Hover-Info in Visual Studio:** Die `@brief`- und `@param`-Texte erscheinen automatisch im Tooltip, wenn man über eine Methode hovert.
- **Automatische Doku:** Mit einem Befehl kann man eine komplette HTML-Dokumentation aus dem Code generieren.
- **Professioneller Standard:** Wird in der Industrie und in Open-Source-Projekten regelmäßig eingesetzt.

---

## 5. Doxygen-Dokumentation generieren

### Installation

1. Doxygen herunterladen: [https://www.doxygen.nl/download.html](https://www.doxygen.nl/download.html)
2. Installieren und sicherstellen, dass `doxygen` im Systempfad liegt

### Konfiguration erstellen

Im Projektordner in der Konsole:

```bash
doxygen -g Doxyfile
```

Das erstellt eine `Doxyfile`-Konfigurationsdatei. Die wichtigsten Einstellungen:

```
# Projektname
PROJECT_NAME           = "Modular C++ Beispiel"

# Quellcode-Ordner (. = aktueller Ordner)
INPUT                  = .

# Auch .h und .cpp Dateien durchsuchen
FILE_PATTERNS          = *.h *.cpp

# Unterordner mit einbeziehen
RECURSIVE              = YES

# HTML-Dokumentation erzeugen
GENERATE_HTML          = YES

# LaTeX/PDF nicht erzeugen (optional)
GENERATE_LATEX         = NO
```

### Dokumentation erzeugen

```bash
doxygen Doxyfile
```

Das erstellt einen Ordner `html/` mit einer kompletten Webseite. Öffne `html/index.html` im Browser, um die fertige Dokumentation zu sehen.

### Ergebnis

Doxygen erzeugt automatisch:

- Klassenübersicht mit Vererbungshierarchie (Person → Client / Supplier)
- Methodenliste mit allen `@param` und `@return` Beschreibungen
- Quellcode-Referenz mit verlinkten Klassen und Methoden
- Vererbungsdiagramme als Grafiken

---

## 6. Quick-Reference Karte

```
┌─────────────────────────────────────────────────────────────┐
│                    NAVIGATION                               │
│                                                             │
│  F12                  →  Zur Definition springen            │
│  Alt + F12            →  Definition im Peek-Fenster         │
│  Strg + F12           →  Zur Deklaration (.h Datei)         │
│  Shift + F12          →  Alle Referenzen finden             │
│  Strg + -             →  Zurück springen                    │
│  Strg + T             →  Symbol suchen                      │
├─────────────────────────────────────────────────────────────┤
│                    INTELLISENSE                             │
│                                                             │
│  Hover                →  Typ + Doxygen-Info anzeigen        │
│  Strg+Shift+Leertaste →  Parameter-Info                     │
│  Strg + Leertaste     →  Autocomplete                       │
├─────────────────────────────────────────────────────────────┤
│                    DEBUGGER                                 │
│                                                             │
│  F5                   →  Starten (Debug)                    │
│  F9                   →  Breakpoint                         │
│  F10                  →  Step Over                          │
│  F11                  →  Step Into (in Methode rein)        │
│  Shift + F11          →  Step Out  (aus Methode raus)       │
├─────────────────────────────────────────────────────────────┤
│                    DOXYGEN                                  │
│                                                             │
│  /**  + Enter         →  Kommentar-Gerüst erzeugen          │
│  @brief               →  Kurzbeschreibung                   │
│  @param name          →  Parameter beschreiben              │
│  @return              →  Rückgabewert beschreiben           │
│  ///< Kommentar       →  Inline-Doku für Attribute          │
└─────────────────────────────────────────────────────────────┘
```
