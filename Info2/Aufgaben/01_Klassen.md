# Übung 01 – Klassen

> **Info 2 · Übung 01** — Aufgabe: Klassen
>
> Quelle: [Original-PDF](../_Original/01_Aufgaben_Klassen.pdf)

---

**Veranstaltung:** Informatik 1 (304031) · **Original:** Übungsblatt #11 (2 Seiten) · **Einsatz:** Info 2, Übung 01

## Aufgabe 1

Analysieren Sie folgende Klasse:

```cpp
 1  #include <iostream>
 2  #include <string>
 3
 4  using namespace std;
 5
 6  class Fahrzeug {
 7  public:
 8      int anzahlRaeder;
 9      string farbe;
10      int anzahlTueren;
11      string marke;
12      string typ;
13      Fahrzeug(int anzRaeder, string autoFarbe, int anzTueren,
14              string autoMarke, string autoTyp) :
15              anzahlRaeder(anzRaeder), anzahlTueren(anzTueren) {
16          farbe = autoFarbe;
17          marke = autoMarke;
18          typ = autoTyp;
19      }
20      void print() {
21          cout << "Das Fahrzeug " << marke << " " << typ  << " hat "
22          << anzahlRaeder << " Räder, " << anzahlTueren
23          << " Türen und ist " << farbe << ".";
24      }
25  };
```

- Wie viele Attribute besitzt die Klasse `Fahrzeug`?
- Welchen Attributen wird vom Konstruktor ein Wert zugewiesen?
- Wie viele Methoden besitzt die Klasse `Fahrzeug` außer dem Konstruktor noch?
- Implementieren Sie auf Papier:
  - Instanziieren Sie ein Objekt der Klasse `Fahrzeug` namens „auto1“.
  - Lassen Sie sich die Informationen zu dieser Klasse mit Hilfe der Methode `print` ausgeben.

## Aufgabe 2

Implementieren Sie eine Klasse `Visitenkarte`, welche eine Visitenkarte beschreibt.

- Ihre Klasse soll folgende Attribute besitzen:
  - Name (Text)
  - Titel (Text)
  - Stellenbezeichnung (Text)
  - Telefonnummer (Text)
  - E-Mail-Adresse (Text)
- Ihre Klasse soll einen Konstruktor besitzen, welcher alle Attribute initialisiert.
- Implementieren Sie eine Methode `printKarte`, welche alle Daten im Stile einer Visitenkarte auf der Konsole ausgibt.
- Schreiben Sie eine Methode, welche den Inhalt des Attributes E-Mail-Adresse auf Plausibilität prüft. Hierzu soll geprüft werden, ob ein `@`-Zeichen enthalten ist.

## Aufgabe 3

Instanziieren Sie ein Objekt der Klasse `Visitenkarte`.

- Legen Sie die Attribute per Konstruktor fest.
- Überprüfen Sie die E-Mail-Adresse auf Plausibilität.
- Geben Sie die Visitenkarte auf der Konsole aus.

## Aufgabe 4

Schreiben Sie ein Programm zur Verwaltung von Visitenkarten. Hierzu soll eine Klasse namens `Visitenkartenliste` implementiert werden, welche maximal 10 verschiedene Visitenkarten speichert. Implementieren Sie eine Methode, welche sämtliche Visitenkarten auf Plausibilität der E-Mail-Adresse prüft. Schreiben Sie eine Methode, welche alle Visitenkarten der Reihe nach auf der Konsole ausgibt.
