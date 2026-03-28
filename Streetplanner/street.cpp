///////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXV
// Versuch 9
/////////////////////////////////////////////////////////////////////////////
#include "street.h"

/**
 * @brief Konstruktor der Street-Klasse.
 * Speichert die Zeiger auf die beiden City-Objekte, die verbunden werden sollen.
 * Nutzt eine Initialisierungsliste für eine effiziente Zuweisung.
 */
Street::Street(City* city1, City* city2) : p_city1(city1), p_city2(city2)
{
    // Der Funktionskörper ist leer, da alles in der Initialisierungsliste passiert.
}

/**
 * @brief Zeichnet die Straße als normale gelbe Linie.
 * @param scene Die Zeichenfläche, auf der die Linie erscheinen soll.
 */
void Street::draw(QGraphicsScene& scene)
{
    // 1. Koordinaten der beiden verbundenen Städte abfragen.
    int x1 = p_city1->getX();
    int y1 = p_city1->getY();
    int x2 = p_city2->getX();
    int y2 = p_city2->getY();

    // 2. Eine Linie zwischen den Mittelpunkten der Stadt-Punkte zeichnen.
    // Die "+ 2.5" Korrektur ist nötig, weil die Stadt-Punkte (Ellipsen) 5x5 Pixel groß sind
    // und ihre Koordinate die linke obere Ecke ist.
    scene.addLine(x1 + 2.5, y1 + 2.5, x2 + 2.5, y2 + 2.5, QPen(Qt::yellow));
}

/**
 * @brief Zeichnet die Straße als dicke, rote Linie.
 * Nützlich, um einen Pfad (z.B. den Dijkstra-Weg) hervorzuheben.
 * @param scene Die Zeichenfläche, auf der die Linie erscheinen soll.
 */
void Street::drawRed(QGraphicsScene& scene)
{
    // 1. Koordinaten der beiden verbundenen Städte abfragen.
    int x1 = p_city1->getX();
    int y1 = p_city1->getY();
    int x2 = p_city2->getX();
    int y2 = p_city2->getY();

    // 2. Einen speziellen Stift (Pen) für die rote Linie erstellen.
    QPen pen(Qt::red);
    pen.setWidth(3);   // Die Linie dicker machen.

    // 3. Die Linie mit dem vorbereiteten roten Stift zeichnen.
    scene.addLine(x1 + 2.5, y1 + 2.5, x2 + 2.5, y2 + 2.5, pen);
}


// --- Getter-Implementierungen ---
// Geben einfach die gespeicherten Zeiger auf die City-Objekte zurück.

City* Street::getCity1() const {
    return p_city1;
}

City* Street::getCity2() const {
    return p_city2;
}
