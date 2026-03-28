///////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXV
// Versuch 9
//////////////////////////////////////////////////////////////////////////////
#ifndef MAP_H
#define MAP_H
#include "street.h"
#include "abstractmap.h"
#include "city.h"
#include <QVector>
#include <QGraphicsScene>

class Map : public AbstractMap
{
public:
    Map();

    // --- Bestehende Funktionen ---
    void addCity(City* city) override;
    bool addStreet(Street* street) override;
    void draw(QGraphicsScene& scene);

    // --- NEUE FUNKTIONEN (aus AbstractMap) ---
    // Hier kommen die Deklarationen für die neuen Funktionen hin.
    // Das "const" am Ende bedeutet, dass diese Funktionen das Map-Objekt nicht verändern.
    // Das "override" bestätigt, dass wir die Funktionen aus der Basisklasse implementieren.
    City* findCity(const QString cityName) const override;
    QVector<Street*> getStreetList(const City* city) const override;
    City* getOppositeCity(const Street* street, const City* city) const override;
    double getLength(const Street* street) const override;
    QVector<City*> getCities() const;

private:
    QVector<City*> cities;
    QVector<Street*> streets;
};

#endif // MAP_H
