
# Übung 3 – Von Boolescher Logik zur Programmierung (Recap & Anwendung)

## 1. Kurzer Recap der wichtigsten Gesetze

| Kategorie | Beispiel | Bedeutung |
|------------|-----------|------------|
| **Kommutativgesetz** | `a∧b = b∧a` | Reihenfolge egal |
| **Assoziativgesetz** | `(a∨b)∨c = a∨(b∨c)` | Klammern verschiebbar |
| **Distributivgesetz** | `a∧(b∨c) = (a∧b)∨(a∧c)` | „Ausmultiplizieren“ |
| **De Morgan** | `¬(a∧b) = ¬a∨¬b` | Negation verteilt sich |
| **Neutralität / Extremal** | `a∧1=a`, `a∨0=a`, `a∧0=0`, `a∨1=1` | 0/1 verhalten sich wie Multiplikation/Addition |
| **Komplementär** | `a∧¬a=0`, `a∨¬a=1` | Gegensatz hebt sich auf |
| **Absorption** | `a∨(a∧b)=a` | Überflüssige Teile verschwinden |

---

## 2. Aufgabenstellung

### Ausgangssituation (Textform)

> In unserer Steuerung soll der **Motor** nur eingeschaltet werden, wenn folgende Bedingung erfüllt ist:  
>
> - **Nur wenn A und B bei 1 sind, aber nicht C.**  
> - Wenn **D und A und B**, dann **geht er *nicht* an**.  
> - Wenn **nur D und A**, dann **geht er an**.

### Ziel

1. Schreibe die **Boolesche Funktion** aus dem Text.  
2. Erstelle eine **Wahrheitstabelle**.  
3. **Vereinfache** den Ausdruck mit den Gesetzen.  
4. Übersetze das Ergebnis in **eine einfache if-else-Struktur**.

---

## 3. Schritt-für-Schritt-Auflösung (zum Selbermachen)

### a) Boolescher Ausdruck (direkt aus dem Text)

```

M = (A ∧ B ∧ ¬C) ∨ (D ∧ A ∧ ¬B) ∧ ¬(D ∧ A ∧ B)

```

> Erklärung:  
> - „Nur wenn A und B, aber nicht C“ → `(A ∧ B ∧ ¬C)`  
> - „Wenn D und A und B, dann nicht“ → `¬(D ∧ A ∧ B)`  
> - „Wenn nur D und A, dann ja“ → `(D ∧ A ∧ ¬B)`

---

### b) Wahrheitstabelle

| A | B | C | D | M (Motor) |
|---|---|---|---|------------|
| 0 | 0 | 0 | 0 | 0 |
| 1 | 0 | 0 | 0 | 0 |
| 0 | 1 | 0 | 0 | 0 |
| 1 | 1 | 0 | 0 | 1 |
| 1 | 1 | 1 | 0 | 0 |
| 1 | 1 | 0 | 1 | 0 |
| 1 | 0 | 0 | 1 | 1 |
| 1 | 0 | 1 | 1 | 0 |
| 0 | 1 | 0 | 1 | 0 |

---

### c) Vereinfachung

Durch Beobachtung oder mit KV-Diagramm ergibt sich:

```c

M = (A ∧ ¬C ∧ (B ⊕ D))

```

> Erklärung:  
> - `B ⊕ D` (XOR) bedeutet: genau einer von beiden ist 1  
> - Also: Motor an, wenn A aktiv ist, C nicht aktiv ist, und **entweder B oder D**, aber nicht beide.

---

### d) Übertragung in Programm-Logik

```c
if (A && !C && (B ^ D)) {
    motor = 1;   // Motor EIN
} else {
    motor = 0;   // Motor AUS
}
````

---

## 4. Bonusfrage

Wie würde sich die Schaltung verändern, wenn „D“ ein **Not-Aus-Schalter** wäre, also der Motor **nie an** ist, wenn D = 1, egal was A, B oder C machen?

> Tipp: Überlege, wie du „D“ als zusätzliche Negation in die Formel einbauen würdest.

