# Übung 11 – Funktionen & Sichtbarkeit von Variablen

> **Info 1 · Übung 11** — Aufgaben: Funktionen & Sichtbarkeit (Übung 11), [Arrays & Vektoren (Übung 11.2)](../Aufgaben/11_2_Arrays_Vektoren.md)
>
> Quelle: [Original-PDF](<../_Original/Übung_11_(ss25_Übung9_Funktionen_Sichtbarkeit).pdf>)

---

**Veranstaltung:** Informatik 1 (304031) · **Originalblatt:** Übungsblatt #9 (ss25 Übung 9 – Funktionen Sichtbarkeit)

## Aufgabe 1

Analysieren Sie folgenden Codeabschnitt:

```cpp
 1  int a = 3;
 2  string b = "Hallo";
 3  float c = 1.2f;
 4
 5  void methode1() {
 6      a++;
 7      int a = 3;
 8      for (int i = 0; i < 3; i++) {
 9          a *= 2;
10      }
11
12      // Programmstelle A
13
14  }
15
16  void methode2() {
17      string b = " Test";
18      ::b += b;
19      c = 2.4f;
20  }
21
22  int main(int argc, char **argv) {
23
24      // Programmstelle B
25
26      methode1();
27      methode2();
28
29      // Programmstelle C
30  }
```

Geben Sie die sichtbaren Variablen und ihren Wert an den Programmstellen A, B und C an.

## Aufgabe 2

Schreiben Sie eine Funktion, die als Parameter eine Ganzzahl entgegennimmt. Der Parameter soll dann mit zwei potenziert werden und zurückgegeben werden.

## Aufgabe 3

Überladen Sie die Funktion aus Aufgabe 2 so, dass sie zwei Ganzzahlen entgegennimmt. Der erste Parameter soll dann mit dem zweiten Parameter potenziert werden und zurückgegeben werden.

Testen Sie beide Funktionen in Ihrer `main`-Funktion auf Richtigkeit.

*Hinweis: Verwenden Sie eine Schleife zur Berechnung der Potenz.*

## Aufgabe 4

Schreiben Sie eine Funktion zur Berechnung der Gesamtfläche der Seitenflächen eines Quaders. Als Parameter werden der Methode Höhe, Breite und Tiefe des Quaders übergeben. Das Ergebnis der Berechnung soll dann in einer globalen Variable gespeichert werden.

Schreiben Sie anschließend eine weitere Funktion `printFlaeche`, die die Fläche auf der Konsole ausgibt.

*Hinweis: Die Funktion zur Berechnung der Seitenflächen hat keinen Rückgabewert!*
