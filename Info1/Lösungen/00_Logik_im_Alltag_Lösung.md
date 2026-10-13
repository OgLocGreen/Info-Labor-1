# Lösung Übung 00 – Logik im Alltag: Vom Satz zur booleschen Funktion

> **Info 1 · Übung 00** — Aufgabe: [Logik im Alltag](../Aufgaben/00_Logik_im_Alltag.md) · Lösung: Logik im Alltag

---

## Teil B – Jetzt kommt der Regen

### Zum Aufwärmen

„Wenn es regnet, gehe ich nicht feiern.“ → Ich gehe feiern, wenn es **nicht** regnet:

```
F = ¬R
```

| R | F = ¬R |
|:-:|:-:|
| 0 | **1** |
| 1 | 0 |

### Aufgabe 1 – Funktion aufstellen

**a)** Neue Bedingung: „Es regnet.“ → Variable **R** (`R = 1` heißt „es regnet“).

| Rolle | Aussage | Variable |
|---|---|:-:|
| Eingang | Ich habe Freitag Zeit. | **Z** |
| Eingang | Es gibt Freibier. | **B** |
| Eingang | Es regnet. | **R** |
| Ausgang | Ich gehe feiern. | **F** |

„Es ist Freitag“ ist **keine** neue Variable: Wir betrachten ohnehin nur den Freitag, und das steckt schon in Z. Wer trotzdem eine eigene Variable T = „es ist Freitag“ einführt, erhält `F = T ∧ Z ∧ B ∧ ¬R` mit 16 Zeilen. Das ist auch richtig, nur umständlicher.

**b)** Das Wort „**aber**“ kündigt die Ausnahme an, das Wort „**nicht**“ dreht das Ergebnis um. Die Ausnahme hat Vorrang: Selbst wenn Z und B erfüllt sind, gewinnt der Regen. „Aber“ wirkt also wie ein UND: Satz 1 muss erfüllt sein **und** die Ausnahme aus Satz 2 darf nicht eintreten. Damit du feiern gehst, muss zusätzlich gelten: Es regnet nicht, also ¬R.

**c)** Alle drei Bedingungen müssen gleichzeitig erfüllt sein:

```
F = Z ∧ B ∧ ¬R
```

Gesprochen: „Ich gehe feiern, wenn ich Zeit habe **und** es Freibier gibt **und** es **nicht** regnet.“

> **Auch richtig:** `F = (Z ∧ B) ∧ ¬(Z ∧ R)`. Das ist die wörtliche Übersetzung beider Sätze („Zeit und Freibier“, aber nicht „Freitag und Regen“). Sie ergibt genau dieselbe Wahrheitstabelle (siehe letzte Spalte unten): Wenn Z ∧ B = 1 ist, ist Z schon 1, und ¬(Z ∧ R) hängt dann nur noch von R ab. Wie man solche Ausdrücke kürzt, lernst du in Übung 01.

**d)** Mit 3 Eingängen gibt es 2³ = **8** Kombinationen, denn jeder neue Eingang verdoppelt die Anzahl der Zeilen. Die Hilfsspalte ¬R macht das Ausfüllen leichter:

| Z | B | R | ¬R | F = Z ∧ B ∧ ¬R | (Z ∧ B) ∧ ¬(Z ∧ R) |
|:-:|:-:|:-:|:-:|:-:|:-:|
| 0 | 0 | 0 | 1 | 0 | 0 |
| 0 | 0 | 1 | 0 | 0 | 0 |
| 0 | 1 | 0 | 1 | 0 | 0 |
| 0 | 1 | 1 | 0 | 0 | 0 |
| 1 | 0 | 0 | 1 | 0 | 0 |
| 1 | 0 | 1 | 0 | 0 | 0 |
| 1 | 1 | 0 | 1 | **1** | **1** |
| 1 | 1 | 1 | 0 | 0 | 0 |

**e)** Nur in **einem** Fall: Du hast Zeit, es gibt Freibier und es regnet nicht (Z = 1, B = 1, R = 0).

**f)** FUB:

![FUB: F = Z ∧ B ∧ ¬R](../Aufgaben/bilder/00_FUB_Loesung_A1_Feiern.svg)

Gleichwertig: Statt des eigenen NICHT-Bausteins darf der Negationskreis auch direkt am R-Eingang des `&`-Bausteins sitzen. So ist es in der SPS-Programmierung üblich.

> **Typische Fehler:**
> - `F = Z ∧ B ∧ R` – dann gehst du nur bei Regen feiern. Das „nicht“ fehlt.
> - `F = (Z ∧ B) ∨ ¬R` – dann gehst du auch ohne Zeit und ohne Freibier feiern, sobald es nicht regnet (prüfe Zeile 1 der Tabelle: Z = 0, B = 0, R = 0 ergäbe F = 1).

In C++ sähe das so aus:

```cpp
bool feiern = zeit && freibier && !regen;
```

### Aufgabe 2 – Ablaufdiagramm erweitern

![Ablaufdiagramm: Feiern gehen, wenn Zeit und Freibier und kein Regen](../Aufgaben/bilder/00_Ablauf_Loesung_A2_Feiern.svg)

Bei der Regen-Frage geht es bei „**nein**“ weiter zum Feiern, bei „ja“ bleibst du zu Hause. Die Reihenfolge der Fragen ist für das Ergebnis egal: Du könntest auch zuerst nach dem Regen fragen. Bei UND spielt die Reihenfolge keine Rolle. In Übung 01 lernst du das als *Kommutativ- und Assoziativgesetz* kennen.

---

## Teil C – Logik im Alltag

### Aufgabe 3 – Vom Satz zur Funktion

#### a) Flurlicht mit Bewegungsmelder

**D** = es ist dunkel, **M** = jemand bewegt sich, **L** = Licht geht an

```
L = D ∧ M
```

| D | M | L = D ∧ M |
|:-:|:-:|:-:|
| 0 | 0 | 0 |
| 0 | 1 | 0 |
| 1 | 0 | 0 |
| 1 | 1 | **1** |

![FUB: L = D ∧ M](../Aufgaben/bilder/00_FUB_Loesung_A3a_Flurlicht.svg)

#### b) Regenschirm

**R** = es regnet, **W** = die Wetter-App sagt Regen an, **S** = Schirm mitnehmen

```
S = R ∨ W
```

| R | W | S = R ∨ W |
|:-:|:-:|:-:|
| 0 | 0 | 0 |
| 0 | 1 | **1** |
| 1 | 0 | **1** |
| 1 | 1 | **1** |

![FUB: S = R ∨ W](../Aufgaben/bilder/00_FUB_Loesung_A3b_Regenschirm.svg)

Wichtig: ODER ist auch dann 1, wenn **beide** Eingänge 1 sind. Wenn es regnet **und** die App Regen ansagt, nimmst du den Schirm natürlich auch mit.

#### c) Gurtwarner im Auto

**M** = Motor läuft, **G** = Gurt ist angelegt, **P** = Auto piept

```
P = M ∧ ¬G
```

| M | G | ¬G | P = M ∧ ¬G |
|:-:|:-:|:-:|:-:|
| 0 | 0 | 1 | 0 |
| 0 | 1 | 0 | 0 |
| 1 | 0 | 1 | **1** |
| 1 | 1 | 0 | 0 |

![FUB: P = M ∧ ¬G](../Aufgaben/bilder/00_FUB_Loesung_A3c_Gurtwarner.svg)

> **Hinweis:** Du kannst die Variable auch anders festlegen, z. B. **O** = „Gurt ist offen“. Dann lautet die Funktion `P = M ∧ O` ohne NICHT. Beides ist richtig, entscheidend ist, dass die Festlegung der Variablen klar dazugeschrieben wird. Üblich ist es, Variablen nach dem Zustand zu benennen, den der Sensor meldet (Gurt angelegt, Motor an, Fenster offen), und das „nicht“ mit ¬ auszudrücken.

#### d) Alarmanlage

**S** = Anlage ist scharf geschaltet, **F** = ein Fenster ist offen, **T** = die Tür ist offen, **A** = Alarm

```
A = S ∧ (F ∨ T)
```

| S | F | T | F ∨ T | A = S ∧ (F ∨ T) |
|:-:|:-:|:-:|:-:|:-:|
| 0 | 0 | 0 | 0 | 0 |
| 0 | 0 | 1 | 1 | 0 |
| 0 | 1 | 0 | 1 | 0 |
| 0 | 1 | 1 | 1 | 0 |
| 1 | 0 | 0 | 0 | 0 |
| 1 | 0 | 1 | 1 | **1** |
| 1 | 1 | 0 | 1 | **1** |
| 1 | 1 | 1 | 1 | **1** |

![FUB: A = S ∧ (F ∨ T)](../Aufgaben/bilder/00_FUB_Loesung_A3d_Alarmanlage.svg)

> **Warum die Klammern?** UND bindet stärker als ODER (wie „Punkt vor Strich“ in der Mathematik). Ohne Klammern würde `S ∧ F ∨ T` als `(S ∧ F) ∨ T` gelesen. Dann gäbe es Alarm, sobald die Tür aufgeht, auch wenn die Anlage **nicht** scharf ist. Zum Beispiel jedes Mal, wenn du zu Hause bist und dem Paketboten die Tür öffnest.

### Aufgabe 4 (Zusatz) – Von der Funktion zum Satz

Es gibt viele richtige Lösungen. Zwei Beispiele für `Y = (A ∨ B) ∧ ¬C`:

- **Alltag:** „Ich gehe joggen, wenn Wochenende ist **oder** ich Urlaub habe, **aber nicht**, wenn ich krank bin.“  
  A = Wochenende, B = Urlaub, C = krank, Y = joggen gehen
- **Technik:** „Der Lüfter läuft, wenn die Temperatur zu hoch ist **oder** der Taster gedrückt wird, **aber nicht**, wenn die Wartungsklappe offen ist.“  
  A = Temperatur zu hoch, B = Taster gedrückt, C = Klappe offen, Y = Lüfter an

| A | B | C | A ∨ B | ¬C | Y = (A ∨ B) ∧ ¬C |
|:-:|:-:|:-:|:-:|:-:|:-:|
| 0 | 0 | 0 | 0 | 1 | 0 |
| 0 | 0 | 1 | 0 | 0 | 0 |
| 0 | 1 | 0 | 1 | 1 | **1** |
| 0 | 1 | 1 | 1 | 0 | 0 |
| 1 | 0 | 0 | 1 | 1 | **1** |
| 1 | 0 | 1 | 1 | 0 | 0 |
| 1 | 1 | 0 | 1 | 1 | **1** |
| 1 | 1 | 1 | 1 | 0 | 0 |

Prüfe deinen eigenen Satz: Er muss in genau diesen drei Fällen „ja“ ergeben.

### Denkfrage (Bonus) – Ist „oder“ immer ODER?

Bei „Möchtest du Tee **oder** Kaffee?“ ist meistens „**entweder** Tee **oder** Kaffee“ gemeint, also genau eins von beiden und nicht beides. Das ist das **exklusive ODER (XOR, ⊕)**.

**T** = ich nehme Tee, **K** = ich nehme Kaffee, **Y** = ich bekomme genau ein Getränk (so ist die Frage gemeint)

| T | K | Y = T ⊕ K |
|:-:|:-:|:-:|
| 0 | 0 | 0 |
| 0 | 1 | **1** |
| 1 | 0 | **1** |
| 1 | 1 | 0 |

Der Unterschied zu Aufgabe 3b liegt in der letzten Zeile: Beim Regenschirm (normales ODER) ist „beides“ erlaubt, bei Tee oder Kaffee (XOR) nicht. In der Informatik bedeutet „ODER“ ohne Zusatz immer das **normale (inklusive) ODER**. Das XOR lernst du in Übung 01 genauer kennen.
