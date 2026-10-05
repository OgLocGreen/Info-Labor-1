# Klausur 2021SS – Informatik 1 (ASE)

> **Info 1 · Klausur** — Aufgabe: Klausur 2021SS Informatik 1 (ASE)
>
> Quelle: [Original-PDF](<../_Original/Pruefung 2021SS ASE.pdf>)

---

**Prüfung:** Informatik 1 · **Studiengang:** ASE (Hochschule Heilbronn, Fakultät für Technik 1) · **Dozent:** D. Hägele · **Semester:** SS 2021 · **Punkte:** 90 (Programmieraufgabe 1: 60, Programmieraufgabe 2: 30) · **Art:** Open-Book-Klausur · **Bearbeitungszeit:** im Original nicht angegeben

## Prüfung Informatik 1

Dies ist eine Open-Book-Klausur. Bücher, Skripte und Vorlagen sind dabei ausdrücklich erlaubt. Die Verwendung von Quellen aus dem Internet ist ebenfalls erlaubt, müssen jedoch entsprechend bekannt gegeben werden. Die Kommunikation der Prüfungsteilnehmer untereinander und die Verwendung von Chats o.ä. ist jedoch nicht erlaubt.

Beachten Sie hierzu auch die ehrenwörtliche Erklärung, die Sie bitte ausgefüllt und unterschrieben in Ilias hochladen.

---

## 1) Programmieraufgabe 1 (60 Punkte)

Schreiben Sie ein Programm, das die IBAN eines deutschen Kontos aus Bankleitzahl BLZ und Kontonummer errechnet. Die Werte sollen dabei manuell eingegeben werden können. Bitte berücksichtigen Sie dabei, dass es üblich ist, die Zahlen in Blöcken einzugeben (z.B. „500 105 17“ statt 50010517). Das Programm soll dies berücksichtigen.

Die IBAN besteht aus dem Länderkennzeichen „DE“, einer 2-stelligen Prüfzahl, der 8-stelligen BLZ und der Kontonummer, die falls notwendig auf 10 Stellen erweitert wird, indem man 0 voranstellt.

Um die Prüfziffer zu berechnen, wird zunächst eine Zahl aus BLZ, Kontonummer ggf. mit führenden Nullen im 10-stelligen Format und der Kennzahl 131400 für Deutschland gebildet. Diese Zahl besitzt dann 24 Stellen. Der Rest einer Ganzzahl-Division (Modulo) dieser Zahl durch 97 wird von 98 abgezogen. Sollte das eine einstellige Zahl ergeben, wird sie um eine führende Null erweitert. Das Resultat sind also zwei Prüfziffern.

**Beispiel:**

BLZ: 500 105 17  
Kontonummer: 123456789  
Zahl: 500105170123456789131400  
Modulo 97 ergibt 57  
98 – 57 = 41 ist damit die Prüfzahl  
Daraus ergibt sich die IBAN DE41500105170123456789.

Leider ist die Zahl zu groß, um sie in C++ direkt verarbeiten zu können. Allerdings kann man den Modulo auch in Schritten berechnen. Dazu wird zunächst der Modulo der BLZ berechnet und der Rest dann vor die 10-stellige Kontonummer gesetzt. Danach wird wieder das Modulo gebildet usw.

**Beispiel:**

50010517 % 97 = **33**  
**33**0123456789 % 97 = **7**  
**7**131400 % 97 = **<ins>57</ins>**

Eingabe und Berechnung der IBAN sollen dabei jeweils als eigenständige Funktionen ausgeführt sein. Beachten Sie dabei auch die Regeln zu den Zugriffsrechten und zur Datenkapselung. Die Ausgabe Ihres Programms soll bei gleichen Eingaben auch dem unten gezeigten Beispiel entsprechen.

Für jede Funktion ist ein Programmablaufplan oder ein Struktogramm abzugeben. Bitte laden Sie in Ilias ihren kompletten Quellcode inklusive der verwendeten Headerdateien hoch. Jede Datei enthält dabei Ihren Namen und Matrikelnummer als Kommentar.

**Beispiel:**

```text
IBAN-Rechner
============

Bitte geben Sie die BLZ ein (Programmende mit 0): 500 105 17
Bitte geben Sie die Kontonummer ein (Programmende mit 0): 123456789

Die IBAN für diese Bankverbindung ist DE41500105170123456789.

Bitte geben Sie die BLZ ein (Programmende mit 0): 62050000
Bitte geben Sie die Kontonummer ein (Programmende mit 0): 76553

Die IBAN für diese Bankverbindung ist DE06620500000000076553.

Bitte geben Sie die BLZ ein (Programmende mit 0): 0

Fertig!
```

---

## 2) Programmieraufgabe 2 (30 Punkte)

Laden Sie die Datei Abgase.txt aus Ilias und speichern Sie sie in Ihrem Verzeichnis für dieses Programmierprojekt.

Schreiben Sie ein Programm, das den ursprünglichen Text zur Verschlüsselung in die 2 Dateien Abgase_1.txt und Abgase_2.txt aufteilt. Dabei werden die Zeichen des Ursprungstextes immer abwechselnd in Abgase_1 und Abgase_2 gespeichert. Abgase_1 enthält danach das 1., 3., 5., usw. Zeichen, Abgase_2 dann immer die übrigen Zeichen. Absatzmarken sollen dabei berücksichtigt werden. Der erste Buchstabe jedes Absatzes ist in Abgase_1 gespeichert.

**Beispiel:**

Text: `Hallo, Studenten`  
Text1: `Hlo tdne`  
Text2: `al,Suetn`

Für jede Funktion ist ein Programmablaufplan oder ein Struktogramm abzugeben. Bitte laden Sie in Ilias ihren kompletten Quellcode inklusive der verwendeten Headerdateien hoch.

**Beispiel der Ausgabe:**

```text
Text aufteilen
==============

"Abgase_1.txt" und "Abgase_2.txt" wurden angelegt.
"Abgase.txt" wurde aufgeteilt.

Fertig!
```

*Abgase.txt (Ausschnitt)*

```text
Verbrennungsmotoren für Automobile gibt es seit dem späten 19. Jahrhundert, ...
Prinzipiell ist das Abgasverhalten eines Dieselmotors dem eines Ottomotors i...
Dieselmotoren für Pkw haben etwa seit Beginn der 1990er-Jahre wegen des beim...
```

*Abgase_1.txt (Ausschnitt)*

```text
VrrnugmtrnfrAtmbl ite etdmsäe 9 arudr,dc ükedsPolmdrLfvrcmtugdrhKzes mZg e a...
PizpelitdsAgsehle ie isloosdmensOtmtr njdrHnih bree,wi mRhba eie olntfdoi,wn...
DeemtrnfrPwhbnew etBgn e 90rJhewgndsbi isloo ih ukinfhgnDewgktlstr ie neeetn...
```

*Abgase_2.txt (Ausschnitt)*

```text
ebennsooe ü uooiegb ssi e ptn1.Jhhnet ohrct a rbe e uteshuzn uc f rti uedrMs...
rniil s a bavratnensDeemtr e ie tooosi ee isctüelgn eli oagswngrKhesofixd ei...
islooe ü k ae tasi eindr19e-ar ee e emDeemtrnctfntosäie rieeaayaosennugrgle ...
```
