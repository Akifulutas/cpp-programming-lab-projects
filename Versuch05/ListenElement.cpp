//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXV
//////////////////////////////////////////////////////////////////////////////

#include "ListenElement.h"

/**
 * @brief Konstruktor: Macht ein neues Listen-Element
 *
 * Dieses Listen-Element bekommt Student-Daten.
 * Es weiß auch, welches Element davor und danach kommt.
 *
 * @param pData Ein Student-Objekt, das hier gespeichert wird
 * @param pNext Zeiger auf das nächste Element (oder nichts/nullptr)
 * @param pPrev Zeiger auf das vorige Element (oder nichts/nullptr)
 */
ListenElement::ListenElement(const Student& pData, ListenElement* pNext, ListenElement* pPrev)
    : data(pData), next(pNext), prev(pPrev)
{
    // Daten und Zeiger sind schon gesetzt (oben)
}

/**
 * @brief Speichert neue Student-Daten in diesem Element
 *
 * @param pData Das ist der neue Student
 */
void ListenElement::setData(Student pData)
{
    data = pData; // Wir speichern die neuen Daten
}

/**
 * @brief Speichert, welches Element danach kommt
 *
 * @param pNext Das ist das nächste Element
 */
void ListenElement::setNext(ListenElement* pNext)
{
    next = pNext; // Zeigt auf das nächste Element
}

/**
 * @brief Speichert, welches Element davor kommt
 *
 * @param pPrev Das ist das vorige Element
 */
void ListenElement::setPrev(ListenElement* pPrev)
{
    prev = pPrev; // Zeigt auf das vorige Element
}

/**
 * @brief Holt die Student-Daten aus diesem Element
 *
 * @return Der Student in diesem Element
 */
Student ListenElement::getData() const
{
    return data; // Gibt die Daten zurück
}

/**
 * @brief Holt das nächste Element in der Liste
 *
 * @return Zeiger auf das nächste Element (oder nichts)
 */
ListenElement* ListenElement::getNext() const
{
    return next; // Gibt das nächste Element zurück
}

/**
 * @brief Holt das vorige Element in der Liste
 *
 * @return Zeiger auf das vorige Element (oder nichts)
 */
ListenElement* ListenElement::getPrev() const
{
    return prev; // Gibt das vorige Element zurück
}
