//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 
// 
// Versuch 04: Einführung Klasse
//
// Datei:  Vektor.cpp
// Inhalt: Quellcode für die Klasse Vektor
//////////////////////////////////////////////////////////////////////////////

#include "Vektor.h"
#include <cmath>

// Konstruktor mit Werten für x, y, z
Vektor::Vektor(double inX, double inY, double inZ) : x(inX), y(inY), z(inZ)
{

}

// Destruktor (tut hier nichts)
Vektor::~Vektor()
{

}

/**
 * @brief Zeigt die Werte vom Vektor
 */
void Vektor::ausgabe() const
{
    std::cout << "X-Komponente: " << x << std::endl;
    std::cout << "Y-Komponente: " << y << std::endl;
    std::cout << "Z-Komponente: " << z << std::endl << std::endl;
}

/**
 * @brief Berechnet die Länge vom Vektor
 * @return Die Länge
 */
double Vektor::laenge() const
{
    return std::sqrt(x*x + y*y + z*z);
}

/**
 * @brief Zieht einen anderen Vektor von diesem ab
 * @param input Der andere Vektor
 * @return Das Ergebnis als neuer Vektor
 */
Vektor Vektor::sub(const Vektor& input) const
{
    return Vektor(x - input.x, y - input.y, z - input.z);
}

/**
 * @brief Rechnet das Skalarprodukt mit einem anderen Vektor
 * @param input Der andere Vektor
 * @return Das Skalarprodukt (eine Zahl)
 */
double Vektor::skalarProd(const Vektor& input) const
{
    return x * input.x + y * input.y + z * input.z;
}

/**
 * @brief Rechnet den Winkel zwischen zwei Vektoren (in Grad)
 * @param input Der andere Vektor
 * @return Der Winkel in Grad
 */
double Vektor::winkel(const Vektor& input) const
{
    double cosAlpha = skalarProd(input) / (laenge() * input.laenge());
    // Korrigiert kleine Rechenfehler bei Kommazahlen
    if (cosAlpha > 1.0) cosAlpha = 1.0;
    if (cosAlpha < -1.0) cosAlpha = -1.0;
    return std::acos(cosAlpha) * 180.0 / M_PI;

    // Erklärung zum Skalarprodukt: siehe Wikipedia
}

/**
 * @brief Dreht den Vektor um die Z-Achse
 * @param rad Der Winkel in Bogenmaß (Radiant)
 */
void Vektor::rotiereUmZ(const double rad)
{
    double newX = x * std::cos(rad) - y * std::sin(rad);
    double newY = x * std::sin(rad) + y * std::cos(rad);
    x = newX;
    y = newY;
    // z bleibt gleich
}
