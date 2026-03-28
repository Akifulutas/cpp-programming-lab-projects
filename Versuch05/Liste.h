//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXV
//////////////////////////////////////////////////////////////////////////////

#ifndef LISTE_H_
#define LISTE_H_

#include <iostream>

#include "ListenElement.h"
#include "Student.h"

/**
 * @brief Klasse für eine Liste mit Studenten
 *
 * Die Liste hat einen Anfang (front) und ein Ende (back).
 * Man kann Studenten vorne oder hinten einfügen.
 * Man kann den ersten Student löschen oder einen bestimmten Student über die Nummer entfernen.
 */
class Liste
{
private:
    ListenElement* front;  // Zeigt auf das erste Element
    ListenElement* back;   // Zeigt auf das letzte Element

public:
    /**
     * @brief Macht eine neue leere Liste
     */
    Liste(); // Konstruktor

    /**
     * @brief Fügt einen Student ganz hinten zur Liste
     * @param pData Der Student, den man speichern will
     */
    void pushBack(Student pData); // hinten einfügen

    /**
     * @brief Fügt einen Student ganz vorne zur Liste
     * @param pData Der Student, den man speichern will
     */
    void pushFront(Student pData); // vorne einfügen

    /**
     * @brief Löscht den ersten Student aus der Liste
     */
    void popFront(); // ersten löschen

    /**
     * @brief Prüft, ob die Liste leer ist
     * @return true, wenn Liste leer ist, sonst false
     */
    bool empty(); // ist die Liste leer?

    /**
     * @brief Gibt den ersten Student zurück
     * @return Der Student ganz vorne in der Liste
     */
    Student dataFront(); // erster Student

    /**
     * @brief Zeigt alle Studenten von vorne nach hinten
     */
    void ausgabeVorwaerts() const; // normale Reihenfolge

    /**
     * @brief Zeigt alle Studenten von hinten nach vorne
     */
    void ausgabeRueckwaerts() const; // umgekehrte Reihenfolge

    /**
     * @brief Löscht einen bestimmten Student mit Nummer
     * @param matNr Die Matrikelnummer vom Student
     * @return true, wenn der Student gelöscht wurde, sonst false
     */
    bool deleteNode(unsigned int matNr); // Student löschen
};

#endif /*LISTE_H_*/
