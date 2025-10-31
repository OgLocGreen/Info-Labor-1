# Übung 3 – 1-Bit-Komparator, Flipflops und Datentypen

---

## Teil A: 1-Bit-Komparator (Partner- oder 3er-Team)

Gegeben:  
Eingänge **A**, **B** (je 1 Bit).  
Ausgänge:  
- **X** = 1, wenn A < B  
- **Y** = 1, wenn A = B  
- **Z** = 1, wenn A > B  

**Aufgabe:**
1. Erstellt die **Wahrheitstabelle** mit Spalten \(A, B, X, Y, Z\).  
2. Leitet für **X**, **Y**, **Z** jeweils eine **minimierte logische Gleichung** her (nur NOT, AND, OR).  
3. Zeichnet das **logische Schaltbild** mit elementaren Gattern (NICHT/AND/OR).  

Tipp: Arbeitsteilig vorgehen – eine Person Tabelle, eine Person Gleichungen, eine Person Schaltbild.  

---

## Teil B: Flipflops (Grundglieder der Speichertechnik)

**Aufgabe:**  
Zählt die unten genannten Flipflop-Typen auf und beschreibt kurz ihre Besonderheiten bzw. charakteristischen Eigenschaften.

| Nr. | Flipflop-Typ | Besonderheit / Beschreibung |
|-----|---------------|-----------------------------|
| 1 | **RS-Flipflop (Set-Reset)** | |
| 2 | **RS-Flipflop mit S-dominierendem Eingang** | |
| 3 | **D-Flipflop (taktzustandsgesteuert)** |  |
| 4 | **JK-Flipflop (taktzustandsgesteuert)** | |
| 5 | **JK-Master-Slave-Flipflop (taktzustandsgesteuert)** |  |
| 6 | **Flankengesteuerte Flipflops** |  |
| 7 | **T-Flipflop (flankengesteuert)** |  |

---

## Teil C: Datentypen & Wertebereiche

Füllt die Tabelle aus:

| Nr. | Datentyp | Speicher (Byte) | Wertebereich | Vorzeichen |
|-----|-----------|-----------------|---------------|-------------|
| 1 | `uint8_t` | | | |
| 2 | `int16_t` | | | |
| 3 | `float` | | | |

**Bonus (für Schnelle):**  
Was passiert, wenn eine `uint8_t`-Variable den Wert `1111 1111₂` (= 255₁₀) hat und um 1 erhöht wird?  
Berechne den neuen Wert und erkläre kurz, warum.
