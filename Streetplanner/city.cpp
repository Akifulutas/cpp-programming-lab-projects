///////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXV
// Versuch 9
//////////////////////////////////////////////////////////////////////////////
#include "city.h"
#include <QDebug>

/**
 * @brief Konstruktor der City-Klasse.
 *
 * Nutzt eine Initialisierungsliste (der Teil nach dem Doppelpunkt ":").
 * Dies ist die moderne und effiziente C++ Methode, um Member-Variablen
 * ihre Anfangswerte zuzuweisen.
 *
 * @param name Name der Stadt.
 * @param x x-Koordinate.
 * @param y y-Koordinate.
 */
City::City(QString name, int x, int y) : name(name), x(x), y(y)
{
    // Der Funktionskörper ist leer, da die ganze Arbeit in der Initialisierungsliste erledigt wird.
}

/**
 * @brief Zeichnet die Stadt auf der Grafikooberfläche.
 * @param scene Die Szene, auf der gezeichnet werden soll.
 */
void City::draw(QGraphicsScene& scene)
{
     qDebug() << "Drawing city:" << name;
    // 1. Einen kleinen roten Punkt für die Stadtposition zeichnen.
    QPen pen(Qt::red);
    QBrush brush(Qt::red);
    scene.addEllipse(x, y, 5, 5, pen, brush);

    // 2. Den Stadtnamen als Text-Objekt erstellen.
    QGraphicsTextItem* text = new QGraphicsTextItem(name);
    // 3. Den Text etwas über dem Punkt positionieren (y-15).
    text->setPos(x, y - 15);
    // 4. Das Text-Objekt zur Szene hinzufügen.
    scene.addItem(text);
}


// --- Getter-Implementierungen ---
// Diese Funktionen geben einfach den Wert der entsprechenden privaten Variable zurück.

QString City::getName() const
{
    return name;
}

int City::getX() const
{
    return x;
}

int City::getY() const
{
    return y;
}
