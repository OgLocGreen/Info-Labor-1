# Übung 02 – Klassen & Kapselung

> **Info 2 · Übung 02** — Aufgabe: Klassen & Kapselung
>
> Quelle: [Original-PDF](../_Original/02_Aufgaben_KlassenKapselung.pdf)

---

**Veranstaltung:** Informatik 1 (304031) · **Original:** Übungsblatt #12 (1 Seite) · **Einsatz:** Info 2, Übung 02

## Aufgabe 1

Legen Sie zwei Variablen an, eine vom Typ Integer, die andere vom Typ Double. Lesen Sie die Werte der Variablen von der Konsole ein. Schreiben Sie eine Methode, die die beiden Variablen entgegennimmt, miteinander dividiert und das Ergebnis anschließend zurückgibt. Geben Sie das Ergebnis der Berechnung auf der Konsole aus.

## Aufgabe 2

Schreiben Sie ein Programm, mit dem die Summe aller Zahlen zwischen zwei Grenzen berechnet werden kann. Die Grenzen sollen vom Benutzer abgefragt werden und anschließend wird dem Benutzer das Ergebnis mitgeteilt.

Beispiel: Eingabe: 5, 10; Ergebnis: 45

## Aufgabe 3

Schreiben Sie ein Programm zur Verwaltung von Netzwerkdruckern.

Um die Daten für jeden Drucker speichern zu können, soll eine passende Klasse angelegt werden. Diese Klasse hat folgende Attribute, die alle private sind: Name (String), IP-Adresse (String), Farbe (Boolean), Duplexeinheit (Boolean), Seiten pro Minute (Integer). Auf alle Attribute soll ein lesender Zugriff möglich sein, bei den Attributen Name und IP-Adresse auch ein schreibender Zugriff. Die Klasse soll eine Methode `printInfo` haben, die den Inhalt der Attribute auf der Konsole ausgibt. Schreiben Sie auch zwei Konstruktoren, einmal den Standardkonstruktor und einen Konstruktor, der Werte für alle Attribute entgegennimmt.

In der `main`-Methode soll es einen `vector` geben, der die verschiedenen Netzwerkdrucker abspeichern kann. Legen Sie mindestens zwei Drucker im `vector` an und geben Sie anschließend alle Drucker, die im `vector` abgelegt sind, mit Hilfe einer Schleife und der Methode `printInfo` auf der Konsole aus.
