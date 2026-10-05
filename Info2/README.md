# Labor – Info 2

> **Info 2** — [Startseite](../README.md) · [Info 1](../Info1/README.md)

Im Labor zu Informatik 2 wird die Programmierung in **C++** vertieft: objektorientierte Programmierung (Klassen, Kapselung, Vererbung, Polymorphie), dynamische Speicherverwaltung mit Pointern, Datenstrukturen wie verkettete Listen und binäre Bäume, Rekursion sowie Such- und mathematische Algorithmen.

**Entwicklungsumgebung:** Die Übungen lassen sich in **Visual Studio** bearbeiten – Tipps, Shortcuts und Doxygen stehen in [Hilfsmittel 03](Hilfsmittel/03_Visual_Studio_Tipps_und_Doxygen.md), den Einstieg zeigt die [Anleitung Visual Studio](../Info1/Hilfsmittel/06_Visual_Studio_Erste_Schritte.md) aus Info 1. Alternativ wird auf der Kommandozeile mit `g++ -std=c++17 -Wall` übersetzt.

Allgemeine Lernhilfen (Buchempfehlungen, Online-Übungsplattformen, Tipps fürs Labor) stehen in der [Einführung zu Info 1](../Info1/README.md).

---

## Inhaltsübersicht

Alle Übungen mit Aufgabe, Lösung und passenden Hilfsmitteln. Die Nummerierung folgt den ursprünglichen Dateinamen der Blätter; eine Übung 07 gibt es in dieser Sammlung nicht.

| Nr. | Thema | Aufgabe | Lösung | Hilfsmittel |
|---|---|---|---|---|
| 01 | Klassen | [Aufgabe](Aufgaben/01_Klassen.md) | – | – |
| 02 | Klassen & Kapselung | [Aufgabe](Aufgaben/02_Klassen_Kapselung.md) | – | – |
| 03.0 | Vererbung & Polymorphie | [Aufgabe](Aufgaben/03_00_Vererbung_Polymorphie.md) | [Beispielprojekt](Lösungen/03_OOP_Beispielprojekt.md) · [Code](Lösungen/Code/03_OOP_Beispielprojekt/) | [Visual Studio: Tipps & Doxygen](Hilfsmittel/03_Visual_Studio_Tipps_und_Doxygen.md) |
| 03.1 | Vererbung | [Aufgabe](Aufgaben/03_01_Vererbung.md) | [Beispielprojekt](Lösungen/03_OOP_Beispielprojekt.md) · [Code](Lösungen/Code/03_OOP_Beispielprojekt/) | [Visual Studio: Tipps & Doxygen](Hilfsmittel/03_Visual_Studio_Tipps_und_Doxygen.md) |
| 04.0 | Dynamische Speicherverwaltung | [Aufgabe](Aufgaben/04_00_Dynamische_Speicherverwaltung.md) | – | [Recap Pointer und Speicherverwaltung](Hilfsmittel/04_Recap_Pointer_und_Speicherverwaltung.md) |
| 04.1 | Funktionen mit Zeigerparametern | [Aufgabe](Aufgaben/04_01_Pointer.md) | [Lösung](Lösungen/04_01_Pointer_Lösung.md) · [Code](Lösungen/Code/04_01_Pointer/) | [Recap Pointer und Speicherverwaltung](Hilfsmittel/04_Recap_Pointer_und_Speicherverwaltung.md) |
| 05 | Einfach verkettete Liste | [Aufgabe](Aufgaben/05_Verkettete_Listen.md) | [Lösung](Lösungen/05_Verkettete_Listen_Lösung.md) · [Code](Lösungen/Code/05_Verkettete_Listen/) | [Recap Pointer und Speicherverwaltung](Hilfsmittel/04_Recap_Pointer_und_Speicherverwaltung.md) |
| 06 | Rekursion und binäre Bäume | [Aufgabe](Aufgaben/06_Rekursion_und_Bäume.md) | – | [Recap Rekursion und Bäume](Hilfsmittel/06_Recap_Rekursion_und_Bäume.md) |
| 08 | Suchalgorithmen: lineare, binäre und Interpolationssuche | [Aufgabe](Aufgaben/08_Suchalgorithmen.md) | – | – |
| 09 | Mathematische Formeln in C++ | [Aufgabe](Aufgaben/09_Mathematische_Formeln.md) | – | – |

Das **Beispielprojekt** zu Übung 03.0/03.1 ist keine 1:1-Musterlösung, sondern ein erklärtes Beispiel zu Klassen und Vererbung (`Person`, `Client`, `Supplier`).

### Weitere Hilfsmittel

- **[String splitten in C++ (Bibliothek vs. von Hand)](Hilfsmittel/String_Splitten_Erklärung.md):** übungsübergreifende Kurzreferenz zum Zerlegen eines `std::string` an Trennzeichen (`find`/`substr`, `find_first_of`, eigene Schleife, `getline` mit `istringstream`, `>>`-Operator).

### Klausuren

- **[Klausur 2024SS – Programming 2](Aufgaben/Klausur_2024SS_Programming2.md):** englischsprachige Klausur mit drei C-Programmieraufgaben (Rekursion, Einfügen in eine einfach verkettete Liste, Sortieren und Suchen in `struct`-Arrays). Zur Vorbereitung passen besonders die Übungen 05 und 06.

Der Quellcode zu den Lösungen liegt in [`Lösungen/Code/`](Lösungen/Code/) (ein Ordner pro Projekt mit allen `.h`- und `.cpp`-Dateien), die Original-PDFs der Übungsblätter und der Klausur unverändert in [`_Original/`](_Original/).
