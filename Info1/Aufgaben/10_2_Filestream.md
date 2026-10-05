# Übung 10.2 – Dateiein- und -ausgabe (Filestream) & Schleifen

> **Info 1 · Übung 10.2** — Aufgaben: [switch-case-Verzweigung (Übung 10)](../Aufgaben/10_Switch_Case.md), Filestream & Schleifen (Übung 10.2)
>
> Quelle: [Original-PDF](<../_Original/Übung_10_2_(ss25_Übung6_filestream).pdf>)

---

**Veranstaltung:** Informatik 1 (304031) · **Originalblatt:** Übungsblatt #7 (ss25 Übung 6 – filestream)

## Aufgabe 1

Schreiben Sie ein Programm, das eine beliebige Anzahl von Sätzen von der Konsole einliest und diese dann in eine Datei schreibt. Das Programm soll bei der Eingabe des Worts `Ende` sich beenden.

*Hinweis: Verwenden Sie eine Schleife.*

## Aufgabe 2

Erstellen Sie ein Programm, das folgendes Muster mit Hilfe von Schleifen auf der Konsole ausgibt:

```text
      *
     ***
    *****
   *******
  *********
 ***********
*************
     ***
     ***
```

Die Anzahl der „Nadel“- und „Stamm“-Zeilen soll über zwei Variablen anpassbar sein.

*Hinweis: Als Grundlage können Sie Aufgabe 3 von Blatt #5 verwenden.* (Blatt #5 = [Übung 09 – Schleifen](../Aufgaben/09_For_Schleifen.md))

## Aufgabe 3

Verändern Sie Ihr Programm von Aufgabe 2 so, dass die Ausgabe des Musters nicht mehr über die Konsole erfolgt, sondern in eine Datei geschrieben wird.

## Aufgabe 4

Schreiben Sie ein C++-Programm, welches das Muster, das in Aufgabe 3 in eine Datei geschrieben wurde, wieder ausliest und auf der Konsole anzeigt. Der Benutzer soll zu Beginn des Programms den Dateinamen der zu lesenden Datei über die Konsole eingeben.

## Aufgabe 5

Analysieren Sie folgenden Codeabschnitt:

```cpp
1  int geradeZahlen = 0;
2
3  for (int i = 1; i <= 10; i++) {
4      if (i % 2 == 0) {
5          geradeZahlen++;
6      }
7  }
8
9  cout << geradeZahlen << "\n";
```

Welchen Wert wird die Variable `geradeZahlen` am Ende des Programmablaufs einnehmen?

Programmieren Sie anschließend den Code nach, um Ihr Ergebnis zu verifizieren.

## Aufgabe 6

Wandeln Sie folgende while-Schleife in eine for-Schleife um:

```cpp
1  int a = 1, b = 5, c = -5;
2
3  while (b > 0) {
4      a *= b;
5      c /= -1;
6      b--;
7  }
8
9  cout << "a = " << a << " b = " << b << "\n":
```

## Aufgabe 7

Schreiben Sie ein C++-Programm, welches die Fläche aller Kreise mit einem Radius zwischen 1 und 5 m in 50 cm Schritten berechnet und ausgibt.
