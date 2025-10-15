# Cheat Sheet – Boolesche Algebra & Grundschaltungen

## 1. Grundoperatoren

| Funktion | Symbol | Logischer Ausdruck | Wahrheitstabelle (Kurz) | Elektrotechnisches Schaltzeichen |
|-----------|---------|--------------------|--------------------------|----------------------------------|
| **AND (UND)** | ∧ | `y = a ∧ b` | Nur 1 wenn beide 1 | Halbrund (AND) |
| **OR (ODER)** | ∨ | `y = a ∨ b` | 1 wenn mind. einer 1 | Geschwungene OR-Form |
| **NOT (NICHT)** | ¬ | `y = ¬a` | Invertiert | Dreieck + Kreis |
| **XOR (exklusiv ODER)** | ⊕ | `y = (a∧¬b)∨(¬a∧b)` | 1 bei ungleichen Eingängen | OR mit zweiter Eingangs-Linie |
| **NAND** | ↑ | `y = ¬(a∧b)` | 1 außer bei (1,1) | AND mit Kreis |
| **NOR** | ↓ | `y = ¬(a∨b)` | 1 nur bei (0,0) | OR mit Kreis |

---

## 2. Wichtige Gesetze der Booleschen Algebra

| Kategorie | Regel | Formel |
|------------|--------|--------|
| **Kommutativgesetze** | Reihenfolge egal | `a∧b=b∧a`, `a∨b=b∨a` |
| **Assoziativgesetze** | Klammern verschiebbar | `(a∧b)∧c=a∧(b∧c)`, `(a∨b)∨c=a∨(b∨c)` |
| **Idempotenzgesetze** | Wiederholung ändert nichts | `a∧a=a`, `a∨a=a` |
| **Distributivgesetze** | Ausmultiplizieren | `a∧(b∨c)=(a∧b)∨(a∧c)`, `a∨(b∧c)=(a∨b)∧(a∨c)` |
| **Neutralitätsgesetze** | 1 bzw. 0 neutral | `a∧1=a`, `a∨0=a` |
| **Extremalgesetze** | 0 bzw. 1 extrem | `a∧0=0`, `a∨1=1` |
| **Doppelnegation** | Negation der Negation | `¬(¬a)=a` |
| **De Morgan** | Negation von Verknüpfungen | `¬(a∧b)=¬a∨¬b`, `¬(a∨b)=¬a∧¬b` |
| **Komplementärgesetze** | Widerspruch & Tautologie | `a∧¬a=0`, `a∨¬a=1` |
| **Dualitätsgesetze** | 0↔1, ∧↔∨ | `¬0=1`, `¬1=0` |
| **Absorptionsgesetze** | Teil verschluckt | `a∨(a∧b)=a`, `a∧(a∨b)=a` |

---

## 3. Wichtige Vereinfachungen

| Ausdruck | Vereinfachung | Begründung |
|-----------|----------------|-------------|
| `(a∨b)∧(a∨¬b)` | `a` | Distributivgesetz |
| `(a∧b)∨(a∧¬b)` | `a` | Distributivgesetz |
| `(¬a∨b)∧(a∨b)` | `b` | Distributivgesetz |
| `¬(a∧b)` | `¬a∨¬b` | De Morgan |
| `¬(a∨b)` | `¬a∧¬b` | De Morgan |

---

## 4. Logische Sonderfunktionen

### XOR
`y = a ⊕ b = (a∧¬b) ∨ (¬a∧b)`  
⇔ `y = (a∨b) ∧ ¬(a∧b)`

### NAND
`y = ¬(a∧b)` ⇔ `¬a ∨ ¬b`

### NOR
`y = ¬(a∨b)` ⇔ `¬a ∧ ¬b`

---

## 5. Typische Timing-Diagramme (verbale Beschreibung)

- **AND:** y=1 nur wenn beide Eingänge gleichzeitig 1.  
- **OR:** y=1, sobald mindestens einer 1.  
- **NOT:** y invertiert das Eingangssignal.  
- **XOR:** y=1 nur bei ungleichen Pegeln.  
- **NAND:** wie AND, jedoch invertiert.  
- **NOR:** wie OR, jedoch invertiert.

---

## 6. Zusammenfassung

- Alle Gesetze sind **dual** zueinander (Tausch 0↔1, ∧↔∨).  
- NAND und NOR sind **funktional vollständig** – jedes logische Netz kann damit aufgebaut werden.  
- De Morgan ist die wichtigste Umformungsregel bei Negationen.

---
