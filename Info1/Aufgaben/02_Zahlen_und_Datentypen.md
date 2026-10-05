# Übung 02 – Register, Binärlogik und Datentypen

> **Info 1 · Übung 02** — Aufgaben: Zahlen und Datentypen, [Recap Logik zur Programmierung](../Aufgaben/02_Recap_Logik_zur_Programmierung.md) · Lösungen: [Zahlen und Datentypen](../Lösungen/02_Zahlen_und_Datentypen_Lösung.md), [Recap Logik zur Programmierung](../Lösungen/02_Recap_Logik_zur_Programmierung_Lösung.md) · Hilfsmittel: [Cheatsheet Register und Datentypen](../Hilfsmittel/02_Cheatsheet_Register_und_Datentypen.md)

---

## Teil 1 – Zahlensysteme umrechnen

> Rechne die folgenden Zahlen jeweils in die beiden anderen Zahlensysteme um.  
> (Dezimal ↔ Binär ↔ Hexadezimal)

| Nr. | Dezimal | Binär | Hexadezimal |
|-----|----------|--------|--------------|
| 1 | 13 |        |        |
| 2 | 64 |        |        |
| 3 | 255 |        |        |
| 4 |     | 0b11001010 |        |
| 5 |     |        | 0x7F |
| 6 |     | 0b00101101 |        |
| 7 | 102 |        |        |
| 8 |     |        | 0xFF |

---

## Teil 2 – Bitweise Verknüpfungen (UND, ODER, NICHT, XOR)

> Berechne das Ergebnis der Operationen.  
> Notiere das Ergebnis **binär und dezimal**.

| Nr. | Operation | Ergebnis (Binär) | Ergebnis (Dezimal) |
|-----|------------|------------------|--------------------|
| 1 | `0b10101010 & 0b11110000` | | |
| 2 | `0b00110011 \| 0b01010101` | | |
| 3 | `0b11111111 ^ 0b00001111` | | |
| 4 | `~0b00001111` (nur 8 Bit beachten!) | | |
| 5 | `(1 << 5)` | | |

---

## Teil 3 – Rechnen mit verschiedenen Zahlensystemen

> Führe die Rechnungen durch.  
> Gib alle Ergebnisse in **Dezimal, Binär und Hexadezimal** an.

### A) Normale Rechenoperationen

| Nr. | Aufgabe | Ergebnis (Dez) | Ergebnis (Binär) | Ergebnis (Hex) |
|-----|----------|----------------|------------------|----------------|
| 1 | `0b1010 + 0x0F` | | | |
| 2 | `25 + 0b0011` | | | |
| 3 | `0x14 + 12` | | | |
| 4 | `0b1111 - 0x05` | | | |

> Tipp: Umwandeln in Dezimal, rechnen, dann wieder in Binär und Hex zurück.

---

### B) Bitweise Operationen

| Nr. | Aufgabe | Ergebnis (Dez) | Ergebnis (Binär) | Ergebnis (Hex) |
|-----|----------|----------------|------------------|----------------|
| 1 | `0b0101 << 1` | | | |
| 2 | `0x0C >> 2` | | | |
| 3 | `0b0111 ^ 0x03` | | | |

---

## Teil 4 – Datentypen und Wertebereiche

> Bestimme jeweils:
> - a) den **Speicherbedarf in Byte**
> - b) den **Wertebereich**
> - c) ob der Datentyp vorzeichenbehaftet ist

| Nr. | Datentyp | Speicher (Byte) | Wertebereich | Vorzeichen |
|-----|-----------|------------------|---------------|-------------|
| 1 | `uint8_t` | | | |
| 2 | `int16_t` | | | |
| 3 | `float` | | | |

---

## Zusatzaufgabe (optional)

> Ein Mikrocontroller-Portregister `PORTB` hat den Wert `0b00101100`.  
> Setze Bit 0, lösche Bit 3 und kippe Bit 5.  
> Gib das neue Ergebnis **binär** an.
