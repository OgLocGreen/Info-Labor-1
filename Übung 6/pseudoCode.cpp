


Input:
    teilnummer : Integer        // Nummer des Werkstücks
    start_button : Boolean      // True, wenn Starttaste gedrückt

Output / Aktoren:
    Motor : Boolean             // Förderband-Motor an/aus
    Bohrmaschine_start : Boolean // Signal an Bohrmaschine
    func Abtransport()          // Unterfunktion für den Roboter

func istPrimzahl(n : Integer) -> Boolean:
    if n < 2:
        return False

    for i = 2 to n-1:
        if n % i == 0:
            return False

    return True

// Anfangszustand
Motor = False
Bohrmaschine_start = False

if start_button == True:
    Motor = True
    // Werkstück wird transportiert ...

    // Anzahl der Bohrungen bestimmen
    anzahl_bohrungen = 0

    if teilnummer % 4 == 0:
        anzahl_bohrungen = 4
    else if teilnummer % 2 == 0:
        anzahl_bohrungen = 2
    else if istPrimzahl(teilnummer) == True:
        anzahl_bohrungen = teilnummer
    else:
        anzahl_bohrungen = 0     // für andere Zahlen ist im Text nichts definiert

    // Bohrvorgang ausführen
    for i = 1 to anzahl_bohrungen:
        Bohrmaschine_start = True
        // Bohrung ausführen
        Bohrmaschine_start = False

    // Nach dem Bohren: Abtransport
    Abtransport()
