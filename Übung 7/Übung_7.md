**Übung 7 – Kontrollstrukturen in C++ (If, For, Switch, While)**

1. **If-Abfrage – Temperaturklassifikation**
   Schreibe ein C++-Programm, das eine Temperatur in Grad Celsius (`double`) einliest und den Zustand von Wasser ausgibt:

   * unter 0 °C: „Wasser ist fest (Eis).“
   * von 0 °C bis einschließlich 100 °C: „Wasser ist flüssig.“
   * über 100 °C: „Wasser ist gasförmig (Dampf).“

   Zusätzlich soll eine Plausibilitätsprüfung eingebaut werden:
   Wenn die Temperatur kleiner als −100 oder größer als 200 ist, soll zusätzlich ausgegeben werden:
   „Warnung: Temperaturwert außerhalb des erwarteten Bereichs.“
   Verwende `double` und eine saubere `if / else if / else`-Struktur.

2. **For-Schleife – Statistik über Messwerte**
   Schreibe ein C++-Programm, das zuerst eine ganze Zahl `n` (Anzahl der Messwerte) einliest.

   * Wenn `n <= 0`, soll das Programm mit der Meldung
     „Fehler: Anzahl der Messwerte muss positiv sein.“
     abbrechen.
   * Ansonsten sollen `n` Messwerte vom Typ `double` eingelesen werden.

   Mit einer `for`-Schleife sollst du:

   * die Summe aller Messwerte berechnen,
   * daraus den Durchschnitt (arithmetisches Mittel) berechnen.

   Am Ende soll ausgegeben werden:

   * Anzahl der Messwerte,
   * Summe,
   * Durchschnitt.

   Achte auf passende Datentypen (`int` für `n`, `double` für Summe und Durchschnitt) und korrekte Division.

3. **Switch-Case – Einfache Menüsteuerung für einen Taschenrechner**
   Schreibe ein C++-Programm, das zwei Gleitkommazahlen `a` und `b` (`double`) einliest und anschließend ein Textmenü anzeigt:

   * 1: Addition
   * 2: Subtraktion
   * 3: Multiplikation
   * 4: Division

   Der Benutzer gibt eine ganze Zahl (`int auswahl`) ein. Mit einem `switch (auswahl)` soll entsprechend die gewählte Operation berechnet werden:

   * Fall 1: `a + b`
   * Fall 2: `a - b`
   * Fall 3: `a * b`
   * Fall 4: `a / b`, aber nur, wenn `b != 0`. Wenn `b == 0`, soll eine Fehlermeldung
     „Fehler: Division durch 0 nicht erlaubt.“
     ausgegeben werden und kein Ergebnis berechnet werden.
   * Bei allen anderen Werten: „Ungültige Auswahl.“

   Bei gültiger Operation soll das Ergebnis als „Ergebnis: …“ ausgegeben werden. Verwende `int` für die Auswahl und `double` für die Zahlen.

4. **While-Schleife – Passwort-Abfrage mit begrenzten Versuchen**
   Schreibe ein C++-Programm, das eine einfache Passwort-Abfrage simuliert.

   * Das korrekte Passwort wird in einer `std::string`-Variablen gespeichert, zum Beispiel `info123`.
   * Der Benutzer hat maximal 3 Versuche, das Passwort korrekt einzugeben.

   Verwende eine `while`-Schleife, die so lange läuft, bis entweder

   * das Passwort korrekt eingegeben wurde oder
   * 3 Fehlversuche erreicht sind.

   Anforderungen:

   * Bei falscher Eingabe: „Falsches Passwort. Versuchen Sie es erneut.“
   * Bei korrekter Eingabe: „Zugang gewährt.“
   * Nach 3 falschen Versuchen ohne Erfolg: „Zugang gesperrt. Zu viele Fehlversuche.“

   Verwende `int` für den Zähler der Versuche und `std::string` für die Eingabe. Eine boolesche Variable kann kennzeichnen, ob der Login erfolgreich war.
