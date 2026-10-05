# Übung 11.2 – Arrays & Vektoren

> **Info 1 · Übung 11.2** — Aufgaben: [Funktionen & Sichtbarkeit (Übung 11)](../Aufgaben/11_Funktionen_Sichtbarkeit.md), Arrays & Vektoren (Übung 11.2)
>
> Quelle: [Original-PDF](<../_Original/Übung_11_2_(ss25_ArraysVektoren).pdf>)

---

**Veranstaltung:** Informatik 1 (304031) · **Originalblatt:** Übungsblatt #10 (ss25 – ArraysVektoren)

## Aufgabe 1

Analysieren Sie folgenden Codeabschnitt:

```cpp
1  array<int, 9> pos { { 1, 2, 3, 4, 5, 6, 7, 8, 9 } };
2  array<int, 9> neg { { -1, -2, -3, -4, -5, -6, -7, -8, -9 } };
3
4  int erg;
5
6  erg = (pos[2] + neg.at(2) - pos[5] + neg[5] + pos.at(8)) * neg[0];
7
8  cout << "Ergebnis: " << erg << "\n";
```

Welchen Wert wird die Variable `erg` am Ende des Programmablaufs einnehmen?

Programmieren Sie anschließend den Code nach, um Ihr Ergebnis zu verifizieren.

## Aufgabe 2

Schreiben Sie ein Programm, welches folgende Elemente enthält:

- Legen Sie ein Array des Typs `double` der Größe 30 an.
- Füllen Sie die Elemente des Arrays mit aufsteigenden geraden Zahlen (z. B. `a[0]=2`, `a[1]=4`, `a[2]=6`, ...).
- Geben Sie alle Elemente des Arrays auf der Konsole aus.
- Ermitteln Sie die Größe des Arrays mit Hilfe der `size`-Methode und geben Sie diese aus.
- Suchen Sie die Zahl 22 im Array und geben Sie deren Position und beide Nachbarn im Array aus.

## Aufgabe 3

Schreiben Sie ein C++-Programm, in dem der Nutzer maximal 100 `double`-Zahlen über die Konsole eingeben kann. Die Eingabe von Zahlen soll abgebrochen werden, sobald der Nutzer eine 0 eingibt.

Anschließend sollen die eingegebenen Zahlen (ohne die 0) in umgekehrter Reihenfolge wieder auf der Konsole ausgegeben werden.

## Aufgabe 4

Schreiben Sie ein Programm, in dem Sie zunächst ein Array von Ganzzahlen mit folgendem Inhalt anlegen:

23, 1, 45, 7, 243, 0, 5

Ihr Programm soll anschließend die größte und die kleinste Zahl in diesem Array bestimmen und auf der Konsole ausgeben.

## Aufgabe 5

Schreiben Sie ein Programm zur Berechnung des Kreuzprodukts zweier Vektoren im dreidimensionalen Raum. Hierzu soll der Nutzer in der Lage sein, die einzelnen ganzzahligen Komponenten der beiden Vektoren über die Konsole einzugeben. Anschließend soll das Kreuzprodukt nach folgender Formel berechnet werden:

$$
\vec{a} \times \vec{b} =
\begin{pmatrix} a_1 \\ a_2 \\ a_3 \end{pmatrix} \times
\begin{pmatrix} b_1 \\ b_2 \\ b_3 \end{pmatrix} =
\begin{pmatrix} a_2 b_3 - a_3 b_2 \\ a_3 b_1 - a_1 b_3 \\ a_1 b_2 - a_2 b_1 \end{pmatrix}
$$

## Aufgabe 6

Schreiben Sie nun eine Funktion, welche die Berechnung des Kreuzprodukts aus Aufgabe 5 übernimmt. Rufen Sie diese Funktion nach Eingabe der beiden Vektoren aus der `main`-Methode heraus auf.
