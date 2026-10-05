# Übung 10 – switch-case-Verzweigung

> **Info 1 · Übung 10** — Aufgaben: switch-case-Verzweigung (Übung 10), [Filestream & Schleifen (Übung 10.2)](../Aufgaben/10_2_Filestream.md)
>
> Quelle: [Original-PDF](<../_Original/Übung_10_(ss25_Übung6_switchcase).pdf>)

---

**Veranstaltung:** Informatik 1 (304031) · **Originalblatt:** Übungsblatt #6 (ss25 Übung 6 – switchcase)

## Aufgabe 1

Implementieren Sie folgenden Code mit Hilfe einer switch-case-Verzweigung neu:

```cpp
 1  int a;
 2
 3  cin >> a;
 4
 5  if (a == 0) {
 6      cout << "Die Eingabe ist 0";
 7  } else if (a == 1) {
 8      cout << "Die Eingabe ist 1";
 9  } else if (a == 3) {
10      cout << "Die Eingabe ist 3";
11  } else if (a == 7) {
12      cout << "Die Eingabe ist 7";
13  } else {
14      cout << "Diese Zahl ist nicht in der Liste!";
15  }
```

## Aufgabe 2

Analysieren Sie folgenden Codeabschnitt:

```cpp
 1  int c = 4, d = 7;
 2
 3  switch (c) {
 4  case 2:
 5  case 3:
 6      break;
 7  case 4:
 8      d++;
 9      c = c << 1;
10  case 5:
11  case 6:
12  case 7:
13      d = c + d;
14  case 9:
15      if (d > 15) {
16          c = 0;
17      } else {
18          break;
19      }
20  default:
21      d *= 7;
22      break;
23  }
24
25  cout << "c = " << c << "\n";
26  cout << "d = " << d << "\n";
```

Welchen Wert werden die Variablen `c` und `d` am Ende des Programmablaufs einnehmen?

Programmieren Sie anschließend den Code nach, um Ihr Ergebnis zu verifizieren.

## Aufgabe 3

Ersetzen Sie in Aufgabe 5 von Blatt #3 die Unterscheidung zwischen männlich/weiblich durch eine switch-case-Verzweigung und verwenden Sie den `default` Ausdruck zur Ausgabe einer Fehlermeldung bei falscher Eingabe des Geschlechts.

## Aufgabe 4

Schreiben Sie ein Programm, welches Schulnoten von der Konsole einliest und den dazugehörigen Namen anschließend auf der Konsole ausgibt. Verwenden Sie hierfür die switch-case-Verzweigung. Mögliche Ausgaben des Programms sind: `sehr gut`, `gut`, `befriedigend`, `ausreichend` und `nicht bestanden`.

Beispiel: Eingabe: `1`, Ausgabe `sehr gut`.
