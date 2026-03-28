///////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXV
// Versuch 9
//////////////////////////////////////////////////////////////////////////////
#include "map.h"
#include <QDebug>
#include <cmath>

Map::Map()
{
}

void Map::addCity(City* city)
{
    qDebug() << "Added city to map:" << city->getName();
    cities.append(city);
}

bool Map::addStreet(Street* street)
{
    City* city1 = street->getCity1();
    City* city2 = street->getCity2();

    bool city1_found = false;
    bool city2_found = false;

    for (City* c : cities) {
        if (c == city1) city1_found = true;
        if (c == city2) city2_found = true;
        if (city1_found && city2_found) break;
    }

    if (city1_found && city2_found) {
        streets.append(street);
        return true;
    }
    return false;
}

// Zeichnet alle Straßen und Städte in der Szene
void Map::draw(QGraphicsScene& scene)
{
    // Erst die Straßen, damit sie unter den Städten liegen
    for (Street* street : streets) {
        street->draw(scene);
    }
    // Dann die Städte
    for (City* city : cities) {
        city->draw(scene);
    }
}

// Sucht nach einer Stadt mit gegebenem Namen
City* Map::findCity(const QString cityName) const
{
    for (City* city : cities) {
        if (city->getName() == cityName) {
            return city;
        }
    }
    return nullptr;
}
// Liefert alle Straßen, die an einer gegebenen Stadt anliegen
QVector<Street*> Map::getStreetList(const City* city) const
{
    QVector<Street*> found;
    for (Street* street : streets) {
        if (street->getCity1() == city || street->getCity2() == city) {
            found.append(street);
        }
    }
    return found;

}
// Gibt die gegenüberliegende Stadt einer Straße zurück
City* Map::getOppositeCity(const Street* street, const City* city) const
{
    if (street->getCity1() == city) {
        return street->getCity2();
    } else if (street->getCity2() == city) {
        return street->getCity1();
    }
    return nullptr;
}


// Berechnet die euklidische Distanz zwischen den beiden Städten einer Straße
double Map::getLength(const Street* street) const
{
    City* c1 = street->getCity1();
    City* c2 = street->getCity2();
    double dx = c1->getX() - c2->getX();
    double dy = c1->getY() - c2->getY();
    return std::sqrt(dx * dx + dy * dy);
}

// Gibt alle Städte in der Karte zurück
QVector<City*> Map::getCities() const
{
    return cities;
}
