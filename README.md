# Info-Labor – Informatik 1 & 2

Dieses Repository sammelt Übungsaufgaben, Lösungen und Hilfsmittel für das Labor zu **Informatik 1 und Informatik 2** an der **Hochschule Heilbronn (HHN)**.  
Laborbetreuung: *Christian Heinzmann*.  
Die Inhalte werden auf **[GitHub](https://github.com/OgLocGreen/Info-Labor-1)** und im **[Ilias](https://ilias.hs-heilbronn.de/ilias.php?baseClass=ilrepositorygui&ref_id=27780)** veröffentlicht.

---

## Kurse

- **[Info 1](Info1/README.md)** – Info 1 / Embedded Systeme: Grundlagen der Digitaltechnik (Boolesche Algebra, Zahlensysteme, Flipflops) und Einstieg in die Programmierung mit C/C++ (Kontrollstrukturen, Schleifen, Funktionen, Filestreams); dazu der [Semesterplan WS 2025/26](Info1/Semesterplan_WS2025.md).
- **[Info 2](Info2/README.md)** – Objektorientierte Programmierung, dynamische Speicherverwaltung, Datenstrukturen (verkettete Listen, Bäume) und Algorithmen (Rekursion, Suche, mathematische Formeln) in C++.

---

## Ordnerstruktur

```text
Info-Labor/
├── README.md              diese Startseite
├── Info1/                 Informatik 1 / Embedded Systeme
│   ├── README.md          Einführung, Lernhilfen und Inhaltsübersicht
│   ├── Semesterplan_WS2025.md
│   ├── Aufgaben/          Übungsblätter und Klausuren
│   │   └── bilder/        Abbildungen zu den Aufgaben
│   ├── Lösungen/          Musterlösungen
│   │   └── Code/          Quellcode (.cpp/.h), ein Ordner pro Thema
│   ├── Hilfsmittel/       Cheatsheets, Anleitungen und Recaps
│   └── _Original/         Original-PDFs, draw.io- und .ods-Dateien (unverändert)
└── Info2/                 Informatik 2 – gleicher Aufbau wie Info1/
    ├── README.md
    ├── Aufgaben/
    │   └── bilder/
    ├── Lösungen/
    │   └── Code/
    ├── Hilfsmittel/
    └── _Original/
```

**Dateinamen:** Aufgaben heißen `<Nr>_<Thema>.md` (z. B. `01_Boolesche_Algebra.md`, bei Teilübungen `03_01_Vererbung.md` für Übung 03.1). Die zugehörige Lösung trägt in der Regel denselben Namen mit `_Lösung` (z. B. `01_Boolesche_Algebra_Lösung.md`), Hilfsmittel beginnen mit der Nummer der Übung, zu der sie gehören. Klausuren liegen als `Klausur_<Semester>_<Fach>.md` bei den Aufgaben.

**Navigation:** Oben in jedem Dokument steht eine Navigationszeile, z. B. **Info 1 · Übung 01** — Aufgabe · Lösung · Hilfsmittel. Darüber wechselt ihr direkt zwischen Aufgabe, Lösung und Hilfsmitteln derselben Übung; bei aus PDFs übertragenen Dokumenten verweist sie zusätzlich auf die Quelle in `_Original/`.

---

## So arbeitest du mit dem Labor

1. **Aufgabe lesen** – Übung in der Inhaltsübersicht von [Info 1](Info1/README.md) oder [Info 2](Info2/README.md) auswählen und die Aufgabenstellung vollständig durchlesen.
2. **Hilfsmittel nutzen** – Cheatsheets, Anleitungen und Recaps zur Übung (über die Navigationszeile verlinkt) wiederholen die nötigen Grundlagen.
3. **Selbst lösen** – erst eigenständig auf Papier oder im Code lösen, in kleinen Schritten testen und bei Problemen frühzeitig nachfragen.
4. **Erst dann mit der Lösung vergleichen** – die Musterlösung dient zur Kontrolle und zum Verstehen alternativer Wege, nicht als Abkürzung.
