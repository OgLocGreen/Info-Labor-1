# Übung 09 – Schleifen (for, while, do-while)

> **Info 1 · Übung 09** — Aufgabe: Schleifen (for, while, do-while)
>
> Quelle: [Original-PDF](<../_Original/Übung_9_(ss25_Übung5_forloop).pdf>)

---

**Veranstaltung:** Informatik 1 (304031) · **Originalblatt:** Übungsblatt #5 (ss25 Übung 5 – forloop)

## Aufgabe 1

Analysieren Sie folgenden Codeabschnitt:

```cpp
1  int j = 0;
2  int k = 100;
3
4  do {
5      k -= j * 3;
6      j += 3;
7      cout << k << "\n";
8  } while (j <= 18);
9  cout << "k = " << k << "\n";
```

Welchen Wert wird die Variable `k` am Ende des Programmablaufs einnehmen?

Programmieren Sie anschließend den Code nach, um Ihr Ergebnis zu verifizieren.

## Aufgabe 2

Wandeln Sie folgende for-Schleife in eine while-Schleife um:

```cpp
1  int n, s = 0;
2
3  for (n = 1; n <= 4; n++) {
4      s += n;
5      cout << s << "\n";
6  }
```

## Aufgabe 3

Schreiben Sie ein Programm, welches folgendes Muster auf der Konsole erzeugt:

```text
*
**
***
****
*****
******
*******
```

*Hinweis: Verschachteln Sie hierfür zwei Schleifen ineinander.*

## Aufgabe 4

Schreiben Sie ein C++-Programm, welches von 100 rückwärts zählt, die Zahl jedoch nicht um 1 dekrementiert, sondern um die Hälfte der aktuellen Zahl. (Zahlenfolge: 100.0, 50.0, 25.0, 12.5, ...). Ist die Zahl kleiner als 1, soll das Programm abgebrochen werden.

## Aufgabe 5

Schreiben Sie ein Programm, welches nach Eingabe einer Ganzzahl auf der Konsole die Fakultät dieser Zahl berechnet und ausgibt.

*Hinweis: Erläuterungen zur Berechnung der Fakultät finden Sie unter* [https://de.wikipedia.org/wiki/Fakultät_(Mathematik)](https://de.wikipedia.org/wiki/Fakult%C3%A4t_%28Mathematik%29).

## Aufgabe 6

Schreiben Sie ein Programm, welches in einer Schleife auf die Eingabe von Ganzzahlen auf der Konsole wartet. Die Schleife soll solange wiederholt werden, bis die Zahl `45` eingegeben wird. Falls eine größere Zahl eingegeben wird, soll das Programm `Die Zahl ist zu groß` auf der Konsole ausgeben. Falls die Zahl kleiner ist, soll `Die Zahl ist zu klein` ausgegeben werden. Bei Eingabe der `45` soll die Ausgabe `Richtige Zahl` erscheinen.

## Aufgabe 7

Schreiben Sie ein Programm, welches mit Hilfe einer Schleife alle durch 5 teilbaren Zahlen zwischen 1 und 100 aufaddiert und am Ende das Ergebnis ausgibt.

*Hinweis: Nutzen Sie den Modulo-Operator.*

## Aufgabe 8

Schreiben Sie ein Programm, welches einen Lautstärkeregler simuliert. Hierbei soll das Programm den Lautstärke-Pegel um eins erhöhen, wenn ein `+` auf der Konsole eingegeben wird und bei `-` um eins verringern. Die aktuelle Lautstärke soll in Form eines „Sternchen-Balkens“ auf der Konsole ausgegeben werden. Sobald ein anderes Zeichen als `+` oder `-` eingegeben wurde, soll das Programm stoppen.

Beispiel: Bei einem Pegel von 4 soll folgendes auf der Konsole ausgegeben werden: `****`

## Aufgabe 9

Schreiben Sie ein Programm, welches mit Hilfe einer einzigen Schleife und mehreren Verzweigungen von 0 auf 10 hochzählt, anschließend wieder auf 0 zurückzählt, dann wiederum auf 10 zählt, um dann ein letztes Mal bis 0 zurück zu zählen.
