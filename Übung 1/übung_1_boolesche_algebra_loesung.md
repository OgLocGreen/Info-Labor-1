# Lösungen – Übungsblatt Boolesche Algebra & Grundschaltungen

---

## Teil 1 – Grundschaltungen (Wahrheitstabellen)

### a) `y = a ∧ b`
| a | b | y = a∧b |
|:-:|:-:|:-------:|
| 0 | 0 | 0 |
| 0 | 1 | 0 |
| 1 | 0 | 0 |
| 1 | 1 | 1 |

### b) `y = a ∨ b`
| a | b | y = a∨b |
|:-:|:-:|:-------:|
| 0 | 0 | 0 |
| 0 | 1 | 1 |
| 1 | 0 | 1 |
| 1 | 1 | 1 |

### c) `y = ¬a`
| a | y = ¬a |
|:-:|:------:|
| 0 | 1 |
| 1 | 0 |

### d) `y = a ⊕ b = (a∧¬b) ∨ (¬a∧b)`
| a | b | y = a⊕b |
|:-:|:-:|:--------:|
| 0 | 0 | 0 |
| 0 | 1 | 1 |
| 1 | 0 | 1 |
| 1 | 1 | 0 |

### e) `y = ¬(a ∧ b)` (NAND)
| a | b | y = ¬(a∧b) |
|:-:|:-:|:-----------:|
| 0 | 0 | 1 |
| 0 | 1 | 1 |
| 1 | 0 | 1 |
| 1 | 1 | 0 |

### f) `y = ¬(a ∨ b)` (NOR)
| a | b | y = ¬(a∨b) |
|:-:|:-:|:-----------:|
| 0 | 0 | 1 |
| 0 | 1 | 0 |
| 1 | 0 | 0 |
| 1 | 1 | 0 |

---

## Teil 2 – Anwendung der Gesetze

### Aufgabe 2 – Distributivgesetze
a) `a ∧ (b ∨ c) = (a ∧ b) ∨ (a ∧ c)`  
b) `a ∨ (b ∧ c) = (a ∨ b) ∧ (a ∨ c)`

### Aufgabe 3 – De Morgan
a) `¬(a ∧ b) = ¬a ∨ ¬b`  
b) `¬(a ∨ b) = ¬a ∧ ¬b`  
c) `¬(a ∧ (b ∨ c)) = ¬a ∨ ¬(b ∨ c) = ¬a ∨ (¬b ∧ ¬c)`

### Aufgabe 4 – Vereinfachungen (mit Begründung)
1. `(a ∧ b) ∨ (a ∧ ¬b)`  
   → `a ∧ (b ∨ ¬b)` = `a ∧ 1` = **a**  
   *(Distributiv, Komplementär, Neutralität)*  

2. `(a ∨ b) ∧ (a ∨ ¬b)`  
   → `a ∨ (b ∧ ¬b)` = `a ∨ 0` = **a**  
   *(Distributiv, Komplementär, Extremal)*  

3. `(¬a ∨ b) ∧ (a ∨ b)`  
   → `b ∨ (¬a ∧ a)` = `b ∨ 0` = **b**  
   *(Distributiv, Komplementär, Extremal)*  

### Aufgabe 5 – Dualgesetze
- Dual zu `a ∧ 1 = a`  →  `a ∨ 0 = a`  
- Dual zu `a ∧ 0 = 0`  →  `a ∨ 1 = 1`

---

## Teil 3 – Kombinierte Aufgaben

### Aufgabe 6
**Gegeben:** `y = ¬((a ∧ b) ∨ ¬c)`

**Lösungsschritte:**
1. De Morgan:  
   `y = ¬(a ∧ b) ∧ ¬(¬c)` = `(¬a ∨ ¬b) ∧ c`
2. Optional verteilt:  
   `y = (c ∧ ¬a) ∨ (c ∧ ¬b)`
3. **Endform:**  
   `y = c ∧ (¬a ∨ ¬b)`

---

### Aufgabe 7
**Gegeben:** `y = (a ∧ ¬b) ∨ (¬a ∧ b)`  
→ **XOR-Funktion**

| a | b | y |
|:-:|:-:|:-:|
| 0 | 0 | 0 |
| 0 | 1 | 1 |
| 1 | 0 | 1 |
| 1 | 1 | 0 |

**Beschreibung:**  
`y = 1` genau dann, wenn `a` und `b` verschieden sind.

---

### Aufgabe 8 – Vollständige Vereinfachung
**Ausgang:**  
`y = (a ∧ b) ∨ (¬a ∧ c) ∨ (b ∧ c)`

**Begründung:**  
`(b ∧ c)` wird durch `(a ∧ b)` und `(¬a ∧ c)` abgedeckt, da:  
`(b ∧ c) = (b ∧ c ∧ (a ∨ ¬a)) = (a ∧ b ∧ c) ∨ (¬a ∧ b ∧ c)`  
⊆ `(a ∧ b) ∨ (¬a ∧ c)`

**Endform:**  
`y = (a ∧ b) ∨ (¬a ∧ c)`  
**Interpretation:** Multiplexerform → `y = (a ? b : c)`

---

## Teil 4 – Wahrheitstabellen & Timing (verbale Beschreibung)

- **AND:** y = 1 nur wenn a = 1 und b = 1 gleichzeitig.  
- **OR:** y = 1, sobald mindestens einer der Eingänge 1 ist.  
- **NOT:** y ist das Inverse von a.  
- **XOR:** y = 1, wenn a und b verschieden sind.  
- **NAND:** Invertiertes AND.  
- **NOR:** Invertiertes OR.

---

## Teil 5 – Reflexion

1. **Welche Gesetze erlauben das Herausziehen und Hineinziehen von Negationen?**  
   → *De Morgan-Gesetze.*

2. **Welche Gesetze sind für Vereinfachungen in Schaltplänen am wichtigsten?**  
   → *Distributiv-, Absorptions-, Komplementär- und De Morgan-Gesetze.*

3. **Warum sind NAND- und NOR-Gatter in der Hardwareentwicklung so wichtig?**  
   → *Sie sind universell einsetzbar (funktional vollständig) und benötigen weniger Transistoren.*

---
