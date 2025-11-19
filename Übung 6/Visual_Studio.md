Alles klar, machen wir ein kleines „Dozenten-Skript“ dafür.
Ich schreibe es so, dass du es fast 1:1 an die Studierenden ausgeben oder vorlesen kannst.

---

## 1. Ziel

In diesem Skript lernen wir:

1. Wie man in **Visual Studio** ein erstes **C++-Projekt** anlegt
2. Wie man ein einfaches **„Hello World“** schreibt
3. Wie man das Programm **kompiliert**
4. Wie man das Programm **im Debugger startet** und einen Breakpoint nutzt

Ich gehe von **Visual Studio 2022 (Community)** unter Windows aus.

---

## 2. Neues C++-Projekt anlegen

1. **Visual Studio starten**

   * Visual Studio über das Startmenü öffnen.

2. **Neues Projekt erstellen**

   * Auf der Startseite:
     `Create a new project` anklicken.

3. **Projekttyp auswählen**

   * In der Suchleiste „C++“ eingeben.
   * Vorlage wählen:
     **„Console App“** oder **„Konsolenanwendung“** mit C++
     (nicht C#, nicht .NET).
   * Weiter mit `Next`.

4. **Projekt benennen**

   * `Project name`: z. B. `HelloWorld`
   * `Location`: Ordner auswählen (z. B. `C:\Users\...\source\repos`)
   * `Solution name`: kann gleich wie `Project name` bleiben.
   * `Create` anklicken.

5. Visual Studio legt jetzt die **Solution** und das **Projekt** an und öffnet automatisch eine C++-Datei, meist `HelloWorld.cpp` oder `ProjectName.cpp`.

---

## 3. „Hello World“ in C++ schreiben

Falls noch keine sinnvolle Vorlage da ist oder du es selbst schreiben willst:

1. Stelle sicher, dass eine `.cpp`-Datei geöffnet ist, z. B. `HelloWorld.cpp`.

2. Ersetze den Inhalt der Datei durch:

   ```cpp
   #include <iostream>

   int main()
   {
       std::cout << "Hello World!" << std::endl;
       return 0;
   }
   ```

3. Datei speichern:

   * `Strg + S`

---

## 4. Projekt kompilieren (Build)

„Kompilieren“ = den Quellcode in eine ausführbare Datei übersetzen.

1. Menü oben: **Build** → **Build Solution**

   * oder Tastenkombination: **Strg + Umschalt + B**

2. Unten im **Output**-Fenster siehst du den Build-Status:

   * Bei Erfolg steht dort z. B.:
     `========== Build: 1 succeeded, 0 failed ==========`

3. Falls Fehler auftreten, erscheinen sie im **Error List**-Fenster.

   * Ein Doppelklick auf eine Fehlermeldung springt direkt zur entsprechenden Codezeile.

---

## 5. Programm starten (ohne und mit Debugger)

### 5.1 Start ohne Debugger (nur ausführen)

Das ist praktisch, um das Programm einfach laufen zu lassen.

* Menü: **Debug** → **Start Without Debugging**
* oder Tastenkombination: **Strg + F5**

Es öffnet sich ein Konsolenfenster mit der Ausgabe:

```text
Hello World!
```

Das Fenster bleibt normalerweise kurz stehen, damit man die Ausgabe lesen kann.

---

### 5.2 Debuggen: Erster Breakpoint und Debug-Start

Jetzt starten wir das Programm **mit Debugger**, um Schritt für Schritt zu sehen, was passiert.

1. **Breakpoint setzen**

   * In der Zeile mit `std::cout << "Hello World!" << std::endl;`
   * Links am Rand in den grauen Bereich neben der Zeile klicken.
   * Es erscheint ein roter Punkt = **Breakpoint**.

2. **Debugging starten**

   * Menü: **Debug** → **Start Debugging**
   * oder Tastenkombination: **F5**

3. Verhalten im Debugger

   * Das Programm startet und hält an der Zeile mit dem Breakpoint an.
   * Die aktuelle Zeile ist gelb markiert.

4. **Schrittweise ausführen** (optional kurz zeigen)

   * **F10** = Step Over: Nächste Zeile ausführen, nicht in Funktionen hinein.
   * **F11** = Step Into: In Funktionsaufrufe hineingehen.
   * Unten oder rechts sieht man z. B. **Autos / Locals**-Fenster mit Variablen (hier ist noch wenig Spannendes, aber das Prinzip ist klar).

5. **Debugging beenden**

   * Menü: **Debug** → **Stop Debugging**
   * oder Tastenkombination: **Shift + F5**

---
