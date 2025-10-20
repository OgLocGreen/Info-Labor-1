# Lösungblatt – Register, Binärlogik und Datentypen

---

## **Teil 1 – Zahlensysteme umrechnen (Lösungen)**

| Nr. | Dezimal | Binär | Hexadezimal |
|-----|---------|-------|-------------|
| 1 | 13 | 0b1101 | 0x0D |
| 2 | 64 | 0b1000000 | 0x40 |
| 3 | 255 | 0b11111111 | 0xFF |
| 4 | 202 | 0b11001010 | 0xCA |
| 5 | 127 | 0b01111111 | 0x7F |
| 6 | 45 | 0b00101101 | 0x2D |
| 7 | 102 | 0b01100110 | 0x66 |
| 8 | 255 | 0b11111111 | 0xFF |

> Hinweis: Binärwerte können bei Bedarf auf 8 Bit aufgefüllt werden (führende Nullen).

---

## **Teil 2 – Bitweise Verknüpfungen (Lösungen)**

| Nr. | Operation | Ergebnis (Binär) | Ergebnis (Dezimal) |
|-----|-----------|------------------|--------------------|
| 1 | 0b10101010 & 0b11110000 | 0b10100000 | 160 |
| 2 | 0b00110011 \| 0b01010101 | 0b01110111 | 119 |
| 3 | 0b11111111 ^ 0b00001111 | 0b11110000 | 240 |
| 4 | ~0b00001111 (8 Bit) | 0b11110000 | 240 |
| 5 | (1 << 5) | 0b00100000 | 32 |

---

## **Teil 3 – Rechnen mit verschiedenen Zahlensystemen (Lösungen)**

### **A) Normale Rechenoperationen**

| Nr. | Aufgabe | Ergebnis (Dez) | Ergebnis (Binär) | Ergebnis (Hex) |
|-----|---------|----------------|------------------|----------------|
| 1 | 0b1010 + 0x0F | 25 | 0b11001 | 0x19 |
| 2 | 25 + 0b0011 | 28 | 0b11100 | 0x1C |
| 3 | 0x14 + 12 | 32 | 0b100000 | 0x20 |
| 4 | 0b1111 - 0x05 | 10 | 0b1010 | 0x0A |

### **B) Bitweise Operationen**

| Nr. | Aufgabe | Ergebnis (Dez) | Ergebnis (Binär) | Ergebnis (Hex) |
|-----|---------|----------------|------------------|----------------|
| 1 | 0b0101 << 1 | 10 | 0b1010 | 0x0A |
| 2 | 0x0C >> 2 | 3 | 0b0011 | 0x03 |
| 3 | 0b0111 ^ 0x03 | 4 | 0b0100 | 0x04 |

---

## **Teil 4 – Datentypen und Wertebereiche (Lösungen)**

| Nr. | Datentyp | Speicher (Byte) | Wertebereich | Vorzeichen |
|-----|----------|------------------|--------------|------------|
| 1 | uint8_t | 1 | 0 .. 255 | nein |
| 2 | int16_t | 2 | -32768 .. +32767 | ja |
| 3 | float | 4 | ca. -3.4×10^38 .. +3.4×10^38 | ja |

---

## **Zusatzaufgabe (Lösung)**

> Ausgang: PORTB = 0b00101100  
> **Setze Bit 0** → 0b00101101  
> **Lösche Bit 3** → 0b00100101  
> **Kippe Bit 5** → **0b00000101**

**Ergebnis (binär): 0b00000101**

