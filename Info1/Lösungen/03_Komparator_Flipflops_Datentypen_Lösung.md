# Lösung Übung 03 – 1-Bit-Komparator, Flipflops und Datentypen

> **Info 1 · Übung 03** — Aufgabe: [Komparator, Flipflops und Datentypen](../Aufgaben/03_Komparator_Flipflops_Datentypen.md) · Lösung: Komparator, Flipflops und Datentypen

---

## Teil A: 1-Bit-Komparator

**Wahrheitstabelle:**

| A | B | X (=A<B) | Y (=A=B) | Z (=A>B) |
|---|---|-----------|-----------|-----------|
| 0 | 0 | 0 | 1 | 0 |
| 0 | 1 | 1 | 0 | 0 |
| 1 | 0 | 0 | 0 | 1 |
| 1 | 1 | 0 | 1 | 0 |

**Logische Gleichungen:**
- `X = ¬A ∧ B`  
- `Y = (¬A ∧ ¬B) ∨ (A ∧ B)`  
- `Z = A ∧ ¬B`

**Logisches Schaltbild:** _Noch keine Musterlösung vorhanden._

---

## Teil B: Flipflops (Kurzüberblick)

| Nr. | Flipflop-Typ | Besonderheit / Beschreibung |
|-----|---------------|-----------------------------|
| 1 | RS-FF | Grund-Speicherelement mit Set/Reset, asynchron. |
| 2 | RS-FF mit S-dominierendem Eingang | Set = 1 dominiert → kein undefinierter Zustand. |
| 3 | D-FF (taktzustandsgesteuert) | Übernimmt D bei aktivem Takt, 1 Bit Speicher. |
| 4 | JK-FF (taktzustandsgesteuert) | Universell, toggelt bei J = K = 1. |
| 5 | JK-MS-FF (taktzustandsgesteuert) | Zweistufig → Flankensteuerung. |
| 6 | Flankengesteuerte FF | Reaktion nur auf Taktflanke → störsicher. |
| 7 | T-FF (flankengesteuert) | Toggle bei jeder Flanke, wenn T = 1. |

---

## Teil C: Datentypen

| Nr. | Datentyp  | Speicher (Byte) | Wertebereich | Vorzeichen |
|-----|-----------|-----------------|---------------|-------------|
| 1 | `uint8_t` | 1 | 0 – 255 | nein |
| 2 | `int16_t` | 2 | −32 768 – +32 767 | ja |
| 3 | `float` | 4 | ±3.4028235×10³⁸ (~6–7 Dezimalstellen) | ja |

---

### Bonus – Overflow

`1111 1111₂ = 255₁₀`, nach `+1` → `0000 0000₂`, da `(255 + 1) mod 256 = 0`.  
→ **Überlauf (Wrap-around)** im 8-Bit-Bereich.
