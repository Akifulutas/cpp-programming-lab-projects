//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 
// 
// Versuch 04: Einführung Klasse
//
// Datei:  Vektor.h
// Inhalt: Kopfdatei der Klasse Vektor
//////////////////////////////////////////////////////////////////////////////

#ifndef Vektor_H
#define Vektor_H

#include <iostream>
#include <cmath>
#include <iomanip>

/**
 * @class Vektor
 * @brief Diese Klasse beschreibt einen Vektor mit x-, y- und z-Werten.
 */
class Vektor
{
public:
    /**
     * @brief Macht einen Vektor mit bestimmten Werten
     * @param x Wert für X
     * @param y Wert für Y
     * @param z Wert für Z
     */
    Vektor(double x, double y, double z);

    /**
     * @brief Zerstört den Vektor (wird am Ende automatisch aufgerufen)
     */
    ~Vektor();

    /**
     * @brief Zeigt die x-, y- und z-Werte des Vektors
     */
    void ausgabe() const;

    /**
     * @brief Zieht einen anderen Vektor von diesem ab
     * @param input Der Vektor, der abgezogen wird
     * @return Das Ergebnis als neuer Vektor
     */
    Vektor sub(const Vektor& input) const;

    /**
     * @brief Rechnet die Länge (Betrag) vom Vektor
     * @return Die Länge
     */
    double laenge() const;

    /**
     * @brief Rechnet das Skalarprodukt mit einem anderen Vektor
     * @param input Der andere Vektor
     * @return Das Ergebnis vom Skalarprodukt
     */
    double skalarProd(const Vektor& input) const;

    /**
     * @brief Rechnet den Winkel zwischen zwei Vektoren (in Grad)
     * @param input Der andere Vektor
     * @return Der Winkel in Grad
     */
    double winkel(const Vektor& input) const;

    /**
     * @brief Dreht den Vektor um die Z-Achse
     * @param rad Der Winkel in Bogenmaß (Radiant)
     */
    void rotiereUmZ(const double rad);

private:
    double x; ///< Wert für X
    double y; ///< Wert für Y
    double z; ///< Wert für Z
};

#endif
