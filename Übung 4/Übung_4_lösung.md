# Übungsblatt 4

## Aufgabe 1 – EVA und ADAM in der Informatik

**EVA-Prinzip:**
- **Eingabe – Verarbeitung – Ausgabe**
- Beschreibt den grundsätzlichen Ablauf in der Informatik:
  1. **Eingabe:** Daten oder Signale werden aufgenommen (z. B. durch Sensoren oder Benutzereingabe).  
  2. **Verarbeitung:** Die Daten werden durch das Programm oder System verarbeitet (z. B. Berechnungen, Steuerung).  
  3. **Ausgabe:** Ergebnisse werden ausgegeben (z. B. Anzeige, Aktor, Motor).  

**Beispiel:**  
Ein Lichtsensor misst Helligkeit (Eingabe), das Programm entscheidet, ob das Licht eingeschaltet werden soll (Verarbeitung), und schaltet dann eine Lampe an oder aus (Ausgabe).

**ADAM-Prinzip:**
- **Analysieren – Designen – Ausführen – Messen**
- Erweiterung des EVA-Prinzips für den Entwicklungsprozess:
  1. **Analysieren:** Problem und Anforderungen verstehen.  
  2. **Designen:** Lösung oder Algorithmus entwerfen.  
  3. **Ausführen:** Implementierung/Programmierung.  
  4. **Messen:** Überprüfen und bewerten des Ergebnisses.

---

## Aufgabe 2 – Struktogramm und Programmablaufplan (PAP)

Erstelle zu folgendem System (siehe Abbildung *Ablauf_Skizze.png*):
![Ablauf-Skizze](Ablauf_Skizze.png)

**Beschreibung:**
- Das System steuert zwei Motoren und eine Lampe.  
- Über den **Start-Button** (bool `Start`) wird der Ablauf aktiviert.  
- Der **Soft-E-Stop** (`Soft_E_Stop`) kann den Prozess jederzeit sicher anhalten.  
- Der **Lichtsensor** (`Lichtsensor`) erkennt, ob neues Teil vom Roboter angeliefert wurde.
- Der **Motor 1** treibt das Hauptförderband an.  
- Der **Motor 2** steuert die Auswurfrichtung (1–4) mit den Stufen `25`, `50` oder `100`.  
- Der **Roboterarm** legt die Objekte auf das Förderband.  

### Teil a) Struktogramm

### Teil b) Programmablaufplan (PAP)
  

---

💡 **Hinweis:**  
Ein echter **Not-Aus** darf niemals softwarebasiert sein. Der *Soft_E_Stop* dient nur als logische Simulation.
