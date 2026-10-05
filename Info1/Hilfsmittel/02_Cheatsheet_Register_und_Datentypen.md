# Cheatsheet – Register, Datentypen und Bit-Logik

> **Info 1 · Übung 02** — Aufgaben: [Zahlen und Datentypen](../Aufgaben/02_Zahlen_und_Datentypen.md), [Recap Logik zur Programmierung](../Aufgaben/02_Recap_Logik_zur_Programmierung.md) · Lösungen: [Zahlen und Datentypen](../Lösungen/02_Zahlen_und_Datentypen_Lösung.md), [Recap Logik zur Programmierung](../Lösungen/02_Recap_Logik_zur_Programmierung_Lösung.md) · Hilfsmittel: Cheatsheet Register und Datentypen

---

*Grundlagen für Mikrocontroller.*

## 1. Register – die kleinste Recheneinheit

Ein **Register** ist ein **kleiner, schneller Speicherbereich** **innerhalb der CPU**.  
Hier werden Werte **geladen, verändert und gespeichert**.

- Größe meist **8 Bit = 1 Byte**  
- Jedes **Bit (0 oder 1)** steht für einen **Zustand im Schaltkreis**
- Register liegen **in der CPU**, nicht im RAM

**Beispiel (AVR / Arduino):**
```cpp
DDRB = 0b00000001;   // Pin 0 von PORTB als Ausgang
PORTB = 0b00000001;  // Pin 0 auf HIGH setzen
```

---

## 2. Datentypen und Speichergröße

| Datentyp | Bedeutung | Speicherplatz | Wertebereich (ca.) | Beispiel |
|-----------|------------|----------------|--------------------|-----------|
| `bool` | Wahr/Falsch | 1 Bit (intern 1 Byte) | 0 oder 1 | `bool led = true;` |
| `uint8_t` | Unsigned Integer (8 Bit) | 1 Byte | 0 … 255 | `uint8_t counter = 200;` |
| `int8_t` | Signed Integer (8 Bit) | 1 Byte | −128 … +127 | `int8_t temp = -20;` |
| `uint16_t` | Unsigned Integer (16 Bit) | 2 Byte | 0 … 65 535 | `uint16_t timer = 50000;` |
| `int32_t` | Signed Integer (32 Bit) | 4 Byte | −2 147 483 648 … +2 147 483 647 | `int32_t position = 100000;` |
| `float` | Gleitkommazahl | 4 Byte | ≈ ±3.4×10³⁸ | `float temp = 23.75;` |

---

## 3. Warum ein `float` mehr Speicher braucht

Ein `float` besteht aus mehreren Teilen:

```text
| 1 Bit Vorzeichen | 8 Bit Exponent | 23 Bit Mantisse |
```

- 4 Byte = **32 Bit**
- Passt **nicht in ein einzelnes Register**
- Compiler muss **mehrere Register oder Speicherstellen kombinieren**
- Rechenoperationen mit `float` sind **langsamer und energieintensiver**

**Beispiel:**
```cpp
uint8_t counter = 100;     // nutzt 1 Register (8 Bit)
float temperature = 23.75; // braucht 4 Register oder Speicherstellen
```

---

## 4. Zahlensysteme in der Mikrocontrollerwelt

Jede Information im Mikrocontroller ist **binär** gespeichert.  
Zahlensysteme sind nur **Darstellungen derselben Bits**.

| Darstellung | Beispiel | Binärwert | Kommentar |
|--------------|-----------|------------|------------|
| **Dezimal** | `32` | `0b00100000` | menschlich gut lesbar |
| **Hexadezimal** | `0x20` | `0b00100000` | kompakt, gruppiert Bits in 4er-Blöcken |
| **Binär** | `0b00100000` | Bit 5 = 1 | direkt für Registermanipulation |

👉 Um Register richtig zu nutzen, muss man **zwischen Hex ↔ Binär ↔ Dezimal** umrechnen können.

---

## 5. Bitweise Operationen

Diese Operationen werden genutzt, um gezielt einzelne Bits zu verändern:

| Operator | Bedeutung | Beispiel | Wirkung |
|-----------|------------|-----------|----------|
| `&` | UND | `PORTB & 0b00001111` | löscht obere 4 Bits |
| `\|` | ODER | `PORTB \| 0b00000100` | setzt Bit 2 |
| `^` | XOR | `PORTB ^ 0b00000001` | kippt Bit 0 |
| `~` | NICHT | `~PORTB` | invertiert alle Bits |
| `<<` | Shift links | `1 << 5` | ergibt `0b00100000` |
| `>>` | Shift rechts | `0b10000000 >> 7` | ergibt `1` |

**Beispiel:**
```cpp
PORTB |= (1 << 5);   // setzt Bit 5
PORTB &= ~(1 << 5);  // löscht Bit 5
```

---

## 6. Verbindung zwischen Register und Datentyp

Ein Datentyp beschreibt, **wie viele Bits** der Mikrocontroller **reserviert** und **wie er sie interpretiert**.  
Ein Register ist der **physische Ort**, an dem diese Bits **bearbeitet** werden.

| Ebene | Bedeutung |
|--------|------------|
| **Register (Hardware)** | enthält rohe 0/1-Zustände |
| **Datentyp (Software)** | legt fest, wie diese Bits interpretiert werden |
| **Operation (Programm)** | verändert Bits über Logik- oder Rechenregeln |

---

## 7. Spätere Anwendungen

- Register + Datentypen sind **die Schnittstelle zwischen Software und Hardware**
- Ohne Verständnis von Binärlogik kann man keine Hardware gezielt steuern
- Binär-, Hex- und Bitoperationen sind Grundlage für:
  - GPIO-Programmierung  
  - Interrupt-Steuerung  
  - Kommunikationsprotokolle (I²C, SPI, UART)
  - Sensorregister lesen/schreiben
