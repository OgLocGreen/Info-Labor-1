# Übung 6

## Ablaufbeschreibung

Der gesamte Prozess beginnt mit dem Betätigen des Starttasters. Wird der Startbutton gedrückt, startet der Ablauf und der Motor fährt an, sodass das Werkstück über ein Förderband zur Bearbeitungsstation transportiert wird. Am Ende des Förderweges gelangt das Teil auf eine Vorrichtung, in der der Bohrvorgang stattfindet.

Je nach Nummer des Werkstücks wird anschließend eine unterschiedliche Anzahl von Bohrungen ausgeführt:

- Ist die Nummer durch 4 teilbar, wird das Teil **viermal** gebohrt.
- Ist die Nummer **nicht** durch 4, aber durch 2 teilbar, wird das Teil **zweimal** gebohrt.
- Handelt es sich bei der Nummer um eine **Primzahl**, wird das Werkstück so oft gebohrt, wie es dem Zahlenwert der Nummer selbst entspricht.

Nachdem alle notwendigen Bohrungen abgeschlossen sind, wird ein Roboter zum Abtransport des Werkstücks verwendet. Hierfür wird die Unterfunktion `Abtransport` aufgerufen. Diese veranlasst den Roboter, das fertig bearbeitete Teil aus der Vorrichtung zu entnehmen und an den vorgesehenen Ablageort zu bringen.

> Hinweis: Orientiere dich zusätzlich an der Ablaufskizze.

![Ablaufskizze v3](Ablauf_Skizze_v3.drawio.png)

---

## Aufgabe 1

Erstelle ein **Ablaufdiagramm** (z. B. Flussdiagramm) zu der gegebenen Ablaufbeschreibung bzw. Skizze.

---

## Aufgabe 2

Erstelle ein **Struktogramm** zu diesem Ablauf.

---

## Aufgabe 3

Leite aus den Diagrammen einen **Pseudocode** ab, der den beschriebenen Ablauf vollständig abbildet.

---

## Aufgabe 4

Erstelle ein **C++-Programm**, das diesen Ablauf umsetzt.  
Nutze dabei eine sinnvolle Strukturierung (z. B. Funktionen) und kommentiere die wichtigsten Programmteile.

---

## Aufgabe 5

Erstelle einen **Taschenrechner** in C++ als Konsolenanwendung.  
Der Taschenrechner soll mindestens einfache Grundrechenarten unterstützen und Eingaben über die Konsole verarbeiten.
