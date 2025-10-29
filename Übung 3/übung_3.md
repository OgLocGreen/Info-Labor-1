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
| 1 | **RS-Flipflop (Set-Reset)** | Grundform aus zwei NOR- oder NAND-Gattern. Speichert 1 Bit. Set = 1 setzt Ausgang Q=1, Reset = 1 löscht Q=0. |
| 2 | **RS-Flipflop mit S-dominierendem Eingang** | Wie normales RS-FF, aber **Set hat Vorrang**, falls S = R = 1. Vermeidet undefinierte Zustände. |
| 3 | **D-Flipflop (taktzustandsgesteuert)** | „Data“-Eingang wird **bei aktivem Takt** direkt übernommen. Verhindert verbotene Kombinationen; einfachster synchroner Speicher. |
| 4 | **JK-Flipflop (taktzustandsgesteuert)** | Kombination aus RS-FF mit Rückkopplung. Wenn J = K = 1 → Ausgang toggelt. Keine verbotenen Zustände. |
| 5 | **JK-Master-Slave-Flipflop (taktzustandsgesteuert)** | Zwei JK-FFs in Reihe (Master + Slave). Master reagiert bei Takt = 1, Slave bei Takt = 0 → flankengesteuertes Verhalten. |
| 6 | **Flankengesteuerte Flipflops** | Zustandsänderung nur **bei Taktflanke** (steigend oder fallend), nicht während des Pegels. Erhöht Störsicherheit. |
| 7 | **T-Flipflop (flankengesteuert)** | Toggle-FF. Wenn T = 1 → Zustand wechselt bei jeder Flanke, wenn T = 0 → Zustand bleibt. Praktisch für Zähler. |

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
