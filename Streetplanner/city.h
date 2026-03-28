///////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXV
// Versuch 9
//////////////////////////////////////////////////////////////////////////////
#ifndef CITY_H
#define CITY_H

// Benötigte Qt-Header für den Namen (QString) und zum Zeichnen (QGraphics... Klassen).
#include <QString>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QPen>
#include <QBrush>

/**
 * @class City
 * @brief Repräsentiert eine einzelne Stadt mit Namen und 2D-Koordinaten.
 * Dies ist eine grundlegende Datenklasse für unsere Karte.
 */
class City
{
public:
    // Konstruktor: Erstellt ein neues City-Objekt mit den übergebenen Werten.
    City(QString name, int x, int y);

    // Zeichnet die Stadt (als Punkt und Text) in die angegebene Grafiszene.
    void draw(QGraphicsScene& scene);

    // --- Getter-Funktionen ---
    // Geben die privaten Daten der Stadt zurück. "const" versichert, dass sie nichts ändern.
    QString getName() const;
    int getX() const;
    int getY() const;

private:
    // Private Member-Variablen zur Speicherung der Stadtdaten.
    QString name; // Name der Stadt.
    int x;        // x-Koordinate für die grafische Darstellung.
    int y;        // y-Koordinate für die grafische Darstellung.
};

#endif // CITY_H
