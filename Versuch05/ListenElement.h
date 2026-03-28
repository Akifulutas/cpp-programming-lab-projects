//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXV
//////////////////////////////////////////////////////////////////////////////
#ifndef _LISTENELEMENT_H_
#define _LISTENELEMENT_H_

#include "Student.h"

/**
 * @brief Ein Teilstück (Element) in einer Liste
 *
 * In jedem Element ist ein Student gespeichert.
 * Es weiß auch, welches Element davor und danach kommt.
 */
class ListenElement
{
private:
    Student data;              ///< Der gespeicherte Student
    ListenElement* next;       ///< Zeigt auf das nächste Element
    ListenElement* prev;       ///< Zeigt auf das vorige Element

public:
    /**
     * @brief Erstellt ein neues Element mit Daten
     *
     * Speichert einen Student. Kann auch zeigen, was davor oder danach kommt.
     *
     * @param pData Der Student
     * @param pNext (optional) nächstes Element
     * @param pPrev (optional) vorheriges Element
     */
    ListenElement(const Student& pData, ListenElement* pNext = nullptr, ListenElement* pPrev = nullptr);

    /**
     * @brief Speichert neue Student-Daten
     *
     * @param pData Der neue Student
     */
    void setData(Student pData);

    /**
     * @brief Setzt, was als nächstes kommt
     *
     * @param pNext Das nächste Element
     */
    void setNext(ListenElement* pNext);

    /**
     * @brief Setzt, was davor kommt
     *
     * @param pPrev Das vorige Element
     */
    void setPrev(ListenElement* pPrev);

    /**
     * @brief Holt den gespeicherten Student
     *
     * @return Der Student in diesem Element
     */
    Student getData() const;

    /**
     * @brief Holt das nächste Element
     *
     * @return Zeiger auf das nächste Element oder nullptr
     */
    ListenElement* getNext() const;

    /**
     * @brief Holt das vorige Element
     *
     * @return Zeiger auf das vorige Element oder nullptr
     */
    ListenElement* getPrev() const;
};

#endif // _LISTENELEMENT_H_
