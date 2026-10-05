/**
 * @file Liste.h
 * @brief Definition einer einfach verketteten Liste fuer Integer-Werte.
 * @details Demonstriert dynamische Speicherverwaltung mit new/delete sowie
 *          die Verwendung von Pointern als Verbindungsglieder zwischen Knoten.
 */

#ifndef LISTE_H
#define LISTE_H

/**
 * @struct Knoten
 * @brief Repraesentiert einen einzelnen Knoten in der einfach verketteten Liste.
 */
struct Knoten {
    int wert;          ///< Der im Knoten gespeicherte Wert.
    Knoten* naechster; ///< Zeiger auf den naechsten Knoten (nullptr am Listenende).
};

/**
 * @class Liste
 * @brief Einfach verkettete Liste fuer Integer-Werte.
 * @details Bietet Operationen zum Einfuegen, Loeschen, Suchen und zur Ausgabe.
 *          Der Speicher fuer alle Knoten wird im Destruktor automatisch freigegeben.
 */
class Liste {
private:
    Knoten* kopf; ///< Zeiger auf den ersten Knoten der Liste (nullptr bei leerer Liste).

public:
    /**
     * @brief Konstruktor: erzeugt eine leere Liste.
     */
    Liste();

    /**
     * @brief Destruktor: gibt den Speicher aller Knoten frei.
     */
    ~Liste();

    /**
     * @brief Fuegt einen neuen Wert am Anfang der Liste ein.
     * @param wert Der einzufuegende Wert.
     */
    void einfuegenVorne(int wert);

    /**
     * @brief Fuegt einen neuen Wert am Ende der Liste an.
     * @param wert Der anzufuegende Wert.
     */
    void einfuegenHinten(int wert);

    /**
     * @brief Loescht den ersten Knoten mit dem angegebenen Wert.
     * @param wert Der zu loeschende Wert.
     * @return true, wenn ein Knoten geloescht wurde, sonst false.
     */
    bool loesche(int wert);

    /**
     * @brief Prueft, ob ein Wert in der Liste enthalten ist.
     * @param wert Der gesuchte Wert.
     * @return true, wenn der Wert vorhanden ist.
     */
    bool enthaelt(int wert) const;

    /**
     * @brief Liefert die Anzahl der Knoten in der Liste.
     * @return Anzahl der Listenelemente.
     */
    int laenge() const;

    /**
     * @brief Prueft, ob die Liste leer ist.
     * @return true, wenn die Liste keine Knoten enthaelt.
     */
    bool istLeer() const;

    /**
     * @brief Gibt alle Werte der Liste auf der Konsole aus.
     * @note Format: [ 1 -> 5 -> 10 ]
     */
    void ausgabe() const;
};

#endif // LISTE_H
