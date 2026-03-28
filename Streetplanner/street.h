///////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXV
// Versuch 9
/////////////////////////////////////////////////////////////////////////////
#ifndef STREET_H
#define STREET_H

#include "city.h" // Nötig, da eine Straße zwei City-Objekte kennt.
#include <QGraphicsScene> // Nötig, um die Straße zeichnen zu können.
#include <QPen>           // Definiert den "Stift" für die Zeichenlinie.

/**
 * @class Street
 * @brief Repräsentiert eine Straße als direkte Verbindung zwischen zwei Städten.
 */
class Street
{
public:
    /**
     * @brief Konstruktor, der Zeiger auf die beiden zu verbindenden Städte erhält.
     * @param city1 Zeiger auf die erste Stadt.
     * @param city2 Zeiger auf die zweite Stadt.
     */
    Street(City* city1, City* city2);

    // Zeichnet die Straße mit einer Standardfarbe (z.B. gelb) in die Szene.
    void draw(QGraphicsScene& scene);

    // Zeichnet die Straße rot, z.B. um den Dijkstra-Weg hervorzuheben.
    void drawRed(QGraphicsScene& scene);

    // --- Getter-Funktionen ---
    // Geben die Zeiger auf die beiden verbundenen Städte zurück.
    City* getCity1() const;
    City* getCity2() const;

private:
    // Private Member-Variablen.
    // Wir speichern hier Zeiger, keine Kopien der City-Objekte.
    // So verweist die Straße immer auf die originalen Städte in unserer Map.
    City* p_city1;
    City* p_city2;
};

#endif // STREET_H
