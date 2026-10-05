# Einführung ins Labor – Info 1 / Embedded Systeme

> **Info 1** — [Startseite](../README.md) · [Semesterplan WS 2025/26](Semesterplan_WS2025.md) · [Info 2](../Info2/README.md)

Willkommen im Labor!  
Dieses Dokument dient als kurze Einführung und Orientierungshilfe für alle Studierenden, die hier arbeiten.  
Es enthält eine Übersicht über die Laborinhalte, nützliche Ressourcen und Tipps zur erfolgreichen Bearbeitung der Übungen und Projekte.

Die Inhalte werden auf folgenden Seiten veröffentlicht:

- **[GitHub](https://github.com/OgLocGreen/Info-Labor-1)**
- **[Ilias](https://ilias.hs-heilbronn.de/ilias.php?baseClass=ilrepositorygui&ref_id=27780)**

---

## Ziel und Inhalte des Labors

Im Labor „Info 1 / Embedded Systeme“ werden Grundlagen der **Informatik und digitalen Systeme** praktisch angewendet.  
Ihr lernt den Umgang mit logischen Schaltungen und grundlegenden Programmierkonzepten in **C/C++**.  
Das Ziel ist, ein Verständnis für den Aufbau und das Verhalten eingebetteter Systeme zu entwickeln – von der Logik bis zur Programmierung.

---

## Inhaltsübersicht

Alle Übungen mit Aufgabe, Lösung und passenden Hilfsmitteln. Welche Themen wann im Semester behandelt werden, zeigt der **[Semesterplan WS 2025/26](Semesterplan_WS2025.md)**.

| Nr. | Thema | Aufgabe | Lösung | Hilfsmittel |
|---|---|---|---|---|
| 01 | Boolesche Algebra & Grundschaltungen | [Aufgabe](Aufgaben/01_Boolesche_Algebra.md) | [Lösung](Lösungen/01_Boolesche_Algebra_Lösung.md) | [Cheatsheet Boolesche Algebra](Hilfsmittel/01_Cheatsheet_Boolesche_Algebra.md) |
| 02 | Register, Binärlogik und Datentypen<br>Recap: Von Boolescher Logik zur Programmierung | [Zahlen und Datentypen](Aufgaben/02_Zahlen_und_Datentypen.md)<br>[Recap Logik zur Programmierung](Aufgaben/02_Recap_Logik_zur_Programmierung.md) | [Zahlen und Datentypen](Lösungen/02_Zahlen_und_Datentypen_Lösung.md)<br>[Recap Logik zur Programmierung](Lösungen/02_Recap_Logik_zur_Programmierung_Lösung.md) | [Cheatsheet Register und Datentypen](Hilfsmittel/02_Cheatsheet_Register_und_Datentypen.md) |
| 03 | 1-Bit-Komparator, Flipflops und Datentypen | [Aufgabe](Aufgaben/03_Komparator_Flipflops_Datentypen.md) | [Lösung](Lösungen/03_Komparator_Flipflops_Datentypen_Lösung.md) | – |
| 04 | EVA, Struktogramm und PAP | [Aufgabe](Aufgaben/04_EVA_Struktogramm_PAP.md) | [Lösung](Lösungen/04_EVA_Struktogramm_PAP_Lösung.md) | – |
| 05 | Probeklausur – Grundlagen der Digitaltechnik | [Aufgabe](Aufgaben/05_Probeklausur.md) | – | – |
| 06 | Ablaufsteuerung Bohrstation | [Aufgabe](Aufgaben/06_Ablaufsteuerung_Bohrstation.md) | [Lösung](Lösungen/06_Ablaufsteuerung_Bohrstation_Lösung.md) · [Code](Lösungen/Code/06_Bohrstation/) | [Anleitung Visual Studio](Hilfsmittel/06_Visual_Studio_Erste_Schritte.md) |
| 07 | Kontrollstrukturen in C++ (If, For, Switch, While) | [Aufgabe](Aufgaben/07_Kontrollstrukturen.md) | – | – |
| 08 | Switch, Arrays und Funktionen | [Aufgabe](Aufgaben/08_Switch_Arrays_Funktionen.md) | – | [Erklärung C++-Projektaufbau](Hilfsmittel/08_CPP_Projektaufbau_Header_und_Source.md) |
| 09 | Schleifen (for, while, do-while) | [Aufgabe](Aufgaben/09_For_Schleifen.md) | – | – |
| 10 | switch-case-Verzweigung | [Aufgabe](Aufgaben/10_Switch_Case.md) | – | – |
| 10.2 | Dateiein- und -ausgabe (Filestream) & Schleifen | [Aufgabe](Aufgaben/10_2_Filestream.md) | – | – |
| 11 | Funktionen & Sichtbarkeit von Variablen | [Aufgabe](Aufgaben/11_Funktionen_Sichtbarkeit.md) | – | – |
| 11.2 | Arrays & Vektoren | [Aufgabe](Aufgaben/11_2_Arrays_Vektoren.md) | – | – |

### Klausuren

- **Probeklausur – Grundlagen der Digitaltechnik:** steht als Übung 05 in der Tabelle oben ([Aufgabe](Aufgaben/05_Probeklausur.md)).
- **[Klausur 2021SS – Informatik 1 (ASE)](Aufgaben/Klausur_2021SS_ASE.md):** Open-Book-Prüfung mit zwei C++-Programmieraufgaben (IBAN-Rechner mit Modulo-97-Prüfziffer, Aufteilen einer Textdatei mit Filestreams).

Die Original-PDFs und draw.io-Quellen liegen unverändert in [`_Original/`](_Original/), der Quellcode zu den Lösungen in [`Lösungen/Code/`](Lösungen/Code/).

---

## Unterstützung und Lernhilfen

### 📘 Mathematische Grundlagen

Wenn ihr beim mathematischen Teil Unterstützung benötigt, nutzt das  
**[Mathe-Lernzentrum der HHN](https://www.hs-heilbronn.de/de/mathe-lernzentrum)**.  
Hier findet ihr Tutorien, Übungsangebote und persönliche Beratung.

Für visuelles Lernen oder Wiederholung empfiehlt sich:  
**[Mathe by Daniel Jung (YouTube)](https://www.youtube.com/@MathebyDanielJung)**  
– Kurze, leicht verständliche Videos zu allen wichtigen Grundlagen.

---

### 💻 Mikrocontroller & Embedded Systeme

Für zusätzliche Informationen, Schaltpläne, Tutorials und Foren:

- [mikrocontroller.net](https://www.mikrocontroller.net/)  
  → Sehr gute Plattform mit Community, Schaltbeispielen und Einsteigerhilfen.

---

### 📚 Buchempfehlungen

#### C / C++

- *Jürgen Wolf und Martin Guddat:* **Grundkurs C++**

#### Embedded Systeme

- *Joachim Wietzke:* **Automotive Embedded Systeme – Effizientes Framework: Vom Design zur Implementierung**
- *Ansgar Meroth und Petre Sora:* **Sensornetzwerke in Theorie und Praxis – Embedded Systems-Projekte erfolgreich realisieren**

---

## 🧠 Online-Übungsplattformen

### [HackerRank](https://www.hackerrank.com/)

Ideal, um **Programmieren systematisch zu üben**.  
Hier könnt ihr Aufgaben aus den Bereichen *C, C++, Python, Algorithmen, Datenstrukturen, Mathematik u. v. m.* lösen.  
Die Plattform bewertet automatisch eure Lösungen und zeigt Optimierungsmöglichkeiten.

### Alternative: [Exercism](https://exercism.org/)

Eine sehr gute Ergänzung oder Alternative zu HackerRank.  
Bei **Exercism** lernt ihr Schritt für Schritt verschiedene Sprachen (z. B. C, C++, Python, JavaScript, Rust …) mit echtem Mentoren-Feedback.  
Ideal, um **langfristig** und **sprachübergreifend** Programmierfähigkeiten aufzubauen.

---

## Tipps & Tricks fürs Labor

- Arbeitet **in kleinen Schritten** und testet regelmäßig – kleine funktionierende Blöcke sind besser als ein großer Fehler.
- Nutzt die **Wahrheitstabellen** und **Schaltbilder**, um euer Verständnis zu überprüfen.
- Dokumentiert eure Arbeit kurz (z. B. was funktioniert, was nicht).
- Bei Problemen: Fragt frühzeitig – ob Mitstudierende, Tutor:innen oder mich.
- Probiert Dinge aus! Fehler gehören zum Lernprozess – besonders in der Embedded-Welt.

---

**Viel Erfolg und Spaß im Labor!**  
*Christian Heinzmann*  
Laborbetreuung Info 1 / Embedded Systeme  
Hochschule Heilbronn
