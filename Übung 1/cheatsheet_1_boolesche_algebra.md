# Cheat Sheet – Boolesche Algebra & Grundschaltungen (mit Alltags- & Mathebeispielen)

## 1. Grundoperatoren

| Funktion | Symbol | Logischer Ausdruck | Wahrheitstabelle (Kurz) | Elektrotechnisches Schaltzeichen | Vergleich aus der normalen Mathematik |
|-----------|---------|--------------------|--------------------------|----------------------------------|--------------------------------------|
| **AND (UND)** | ∧ | `y = a ∧ b` | Nur 1, wenn beide 1 | Halbrund (AND) | Multiplikation: `1·1=1`, sonst 0 |
| **OR (ODER)** | ∨ | `y = a ∨ b` | 1, wenn mind. einer 1 | Geschwungene OR-Form | Addition mit Begrenzung: `1+1=1` |
| **NOT (NICHT)** | ¬ | `y = ¬a` | Invertiert | Dreieck + Kreis | Negation: `¬1=0`, `¬0=1` |
| **XOR (exklusiv ODER)** | ⊕ | `y = (a∧¬b)∨(¬a∧b)` | 1 bei ungleichen Eingängen | OR mit zweiter Eingangs-Linie | „Entweder-oder“ – wie gerade/ungerade |
| **NAND** | ↑ | `y = ¬(a∧b)` | 1 außer bei (1,1) | AND mit Kreis | Negiertes UND → „nicht beide“ |
| **NOR** | ↓ | `y = ¬(a∨b)` | 1 nur bei (0,0) | OR mit Kreis | Negiertes ODER → „keiner“ |

---

## 2. Wichtige Gesetze der Booleschen Algebra  
(mit analogen Beispielen aus der Schulmathematik)

| Kategorie | Gesetz | Boolesche Formel | Mathematische Analogie / Alltag |
|------------|---------|------------------|--------------------------------|
| **Kommutativgesetz** | Reihenfolge egal | `a∧b=b∧a`, `a∨b=b∨a` | Wie `a+b=b+a` oder `a·b=b·a` |
| **Assoziativgesetz** | Klammern verschiebbar | `(a∧b)∧c=a∧(b∧c)`<br>`(a∨b)∨c=a∨(b∨c)` | Wie `(a+b)+c=a+(b+c)` |
| **Idempotenzgesetz** | Wiederholung ändert nichts | `a∧a=a`, `a∨a=a` | Wie `a·a=a` wenn a∈{0,1} |
| **Distributivgesetz** | „Ausmultiplizieren“ | `a∧(b∨c)=(a∧b)∨(a∧c)`<br>`a∨(b∧c)=(a∨b)∧(a∨c)` | Wie `a·(b+c)=a·b+a·c` |
| **Neutralitätsgesetz** | 1 oder 0 ist neutral | `a∧1=a`, `a∨0=a` | Wie `a·1=a` oder `a+0=a` |
| **Extremalgesetz** | 1 oder 0 dominiert | `a∧0=0`, `a∨1=1` | Wie `a·0=0` oder `a+1=1` (bei max. 1) |
| **Doppelnegation** | Zweimal negieren = Original | `¬(¬a)=a` | Wie `-(-a)=a` |
| **De Morgan-Gesetze** | Negation verteilt sich | `¬(a∧b)=¬a∨¬b`<br>`¬(a∨b)=¬a∧¬b` | Vergleichbar mit Umkehrung: „Nicht (A und B)“ ⇔ „Nicht A oder Nicht B“ |
| **Komplementärgesetz** | Gegensatz hebt auf | `a∧¬a=0`, `a∨¬a=1` | Wie `x·(1−x)=0` oder `x+(1−x)=1` |
| **Dualitätsprinzip** | Vertausche 0↔1 und ∧↔∨ | `¬0=1`, `¬1=0` | Spiegelung der Formeln |
| **Absorptionsgesetz** | Teil verschluckt Rest | `a∨(a∧b)=a`, `a∧(a∨b)=a` | Wie `a+(a·b)=a` – „A bestimmt das Ergebnis“ |

---

## 3. Typische Vereinfachungen

| Ausdruck | Vereinfachung | Begründung |
|-----------|----------------|-------------|
| `(a∨b)∧(a∨¬b)` | `a` | Distributivgesetz |
| `(a∧b)∨(a∧¬b)` | `a` | Distributivgesetz |
| `(¬a∨b)∧(a∨b)` | `b` | Distributivgesetz |
| `¬(a∧b)` | `¬a∨¬b` | De Morgan |
| `¬(a∨b)` | `¬a∧¬b` | De Morgan |

**Hinweis:** Solche Vereinfachungen helfen, Schaltungen zu reduzieren → weniger Gatter = weniger Strom & Platz.

---

## 4. Logische Sonderfunktionen (erweiterte Darstellung)

### **XOR – exklusiv ODER**
- `y = a ⊕ b = (a∧¬b) ∨ (¬a∧b)`  
- Bedeutet: *„Genau einer wahr“*
- Mathematisch: entspricht der Addition mod 2 → `1⊕1=0`

### **NAND – Negiertes UND**
- `y = ¬(a∧b)` ⇔ `¬a ∨ ¬b`  
- Wichtig: **universell** → jede logische Funktion lässt sich nur mit NAND-Gattern aufbauen

### **NOR – Negiertes ODER**
- `y = ¬(a∨b)` ⇔ `¬a ∧ ¬b`  
- Ebenfalls **universell** (komplettes Schaltalgebra-System mit NOR möglich)

---


## 5. Kleine Alltag-Analogien

| Logikfunktion | Alltagssituation |
|----------------|------------------|
| **AND** | Zwei Schalter in Reihe: *Licht an, wenn beide Schalter an sind.* |
| **OR** | Zwei Schalter parallel: *Licht an, wenn einer an ist.* |
| **NOT** | Ein Kippschalter: *Licht aus → 1, Licht an → 0 (invertiert).* |
| **XOR** | Zwei Lichtschalter im Flur: *Licht an, wenn genau einer betätigt ist.* |
| **NAND** | Sicherheitsverriegelung: *Tür bleibt geschlossen, solange beide Sensoren aktiv sind.* |
| **NOR** | Alarmanlage: *Ruhig nur, wenn keine Bewegung und kein Fenster offen ist.* |
