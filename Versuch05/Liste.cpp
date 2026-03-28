//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXV
//////////////////////////////////////////////////////////////////////////////

#include "Liste.h"
#include "ListenElement.h"

/**
 * @brief Konstruktor: Macht eine neue leere Liste
 *
 * Die Liste hat am Anfang keine Elemente.
 * Die Zeiger vorne und hinten zeigen auf nichts.
 */
Liste::Liste(): front(nullptr), back(nullptr)
{
    // Die Liste ist leer
}

/**
 * @brief Fügt einen neuen Studenten hinten zur Liste
 *
 * Der neue Student kommt ans Ende der Liste.
 *
 * @param pData Das ist der Student, den wir speichern
 */
void Liste::pushBack(Student pData)
{
    // Wir machen ein neues Element
    ListenElement* neuesElement = new ListenElement(pData, nullptr, nullptr);

    if (front == nullptr) // Ist die Liste leer?
    {
        // Das ist das erste Element
        front = neuesElement;
        back = neuesElement;
    }
    else
    {
        // Das alte letzte zeigt jetzt auf das neue
        back->setNext(neuesElement);
        // Das neue zeigt zurück auf das alte
        neuesElement->setPrev(back);
        // Das neue ist jetzt das letzte
        back = neuesElement;
    }
}

/**
 * @brief Fügt einen neuen Studenten vorne zur Liste
 *
 * Der neue Student kommt ganz vorne in die Liste.
 *
 * @param pData Das ist der Student, den wir speichern
 */
void Liste::pushFront(Student pData)
{
    // Wir machen ein neues Element
    ListenElement* neuesElement = new ListenElement(pData, nullptr, nullptr);

    if (front == nullptr) // Ist die Liste leer?
    {
        // Das ist das erste Element
        front = neuesElement;
        back = neuesElement;
    }
    else
    {
        // Das neue zeigt auf das alte erste Element
        neuesElement->setNext(front);
        // Das alte erste zeigt zurück auf das neue
        front->setPrev(neuesElement);
        // Das neue ist jetzt ganz vorne
        front = neuesElement;
    }
}

/**
 * @brief Löscht den ersten Studenten in der Liste
 *
 * Der Student ganz vorne wird entfernt.
 */
void Liste::popFront()
{
    if (front == nullptr)
        return; // Liste ist leer, nichts zu tun

    ListenElement* cursor = front;

    if (front == back) // Nur ein Student in der Liste?
    {
        // Lösche das einzige Element
        delete front;
        front = nullptr;
        back = nullptr;
    }
    else
    {
        // Das zweite Element ist jetzt das erste
        front = front->getNext();
        front->setPrev(nullptr);
        delete cursor; // Altes erstes löschen
    }
}

/**
 * @brief Prüft, ob die Liste leer ist
 *
 * @return true, wenn Liste leer ist, sonst false
 */
bool Liste::empty()
{
    return (front == nullptr);
}

/**
 * @brief Holt die Daten vom ersten Studenten
 *
 * @return Der erste Student oder ein leerer Student, wenn die Liste leer ist
 */
Student Liste::dataFront()
{
    if (front != nullptr)
    {
        // Wir geben die Daten vom ersten zurück
        return front->getData();
    }
    else
    {
        // Liste ist leer, gib leeren Student zurück
        return Student();
    }
}

/**
 * @brief Zeigt die Liste von vorne bis hinten
 *
 * Geht durch die Liste und zeigt alle Studenten.
 */
void Liste::ausgabeVorwaerts() const
{
    ListenElement* cursor = front; // Start vorne

    while (cursor != nullptr)
    {
        // Student zeigen
        cursor->getData().ausgabe();
        cursor = cursor->getNext(); // zum nächsten gehen
    }
}

/**
 * @brief Zeigt die Liste von hinten bis vorne
 *
 * Geht rückwärts durch die Liste.
 */
void Liste::ausgabeRueckwaerts() const
{
    ListenElement* cursor = back; // Start hinten

    while (cursor != nullptr)
    {
        // Student zeigen
        cursor->getData().ausgabe();
        cursor = cursor->getPrev(); // zum vorherigen gehen
    }
}

/**
 * @brief Löscht einen Studenten mit bestimmter Nummer
 *
 * Sucht den Studenten mit der Matrikelnummer und löscht ihn.
 *
 * @param matNr Die Matrikelnummer vom gesuchten Studenten
 * @return true, wenn gelöscht wurde, sonst false
 */
bool Liste::deleteNode(unsigned int matNr)
{
    ListenElement* cursor = front; // Suche beginnt vorne

    while (cursor != nullptr)
    {
        if (cursor->getData().getMatNr() == matNr)
        {
            // Wir haben den richtigen Studenten gefunden

            if (cursor == front && cursor == back)
            {
                // Nur ein Student in der Liste
                delete cursor;
                front = nullptr;
                back = nullptr;
            }
            else if (cursor == front)
            {
                // Student ist ganz vorne
                front = cursor->getNext();
                front->setPrev(nullptr);
                delete cursor;
            }
            else if (cursor == back)
            {
                // Student ist ganz hinten
                back = cursor->getPrev();
                back->setNext(nullptr);
                delete cursor;
            }
            else
            {
                // Student ist in der Mitte
                cursor->getPrev()->setNext(cursor->getNext());
                cursor->getNext()->setPrev(cursor->getPrev());
                delete cursor;
            }

            return true; // Hat geklappt
        }

        cursor = cursor->getNext(); // Nächsten prüfen
    }

    // Student nicht gefunden
    return false;
}
