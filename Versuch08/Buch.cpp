/*!
 * Praktikum Informatik 1
 *
 * @file Buch.cpp
 */

#include "Buch.h"
#include <iostream> // Nötig für std::ostream, std::endl

/*!
 * @brief Konstruktor-Implementierung für Buch
 *
 * Wichtig ist hier die Initialisierungsliste (nach dem Doppelpunkt).
 * Zuerst wird der Konstruktor der Basisklasse `Medium` mit dem Titel aufgerufen.
 * Danach wird das eigene Attribut `autor` der Klasse `Buch` initialisiert.
 */
Buch::Buch(std::string initTitel, std::string initAutor)
    : Medium(initTitel), autor(initAutor)
{
    // Der Körper des Konstruktors kann leer bleiben, da die gesamte
    // Initialisierungsarbeit in der Initialisierungsliste erledigt wird.
}


/*!
 * @brief Implementierung der überschriebenen `ausgabe`-Funktion für Buch.
 */
void Buch::ausgabe(std::ostream& out) const
{
    // Schritt 1: Rufe die `ausgabe`-Methode der Basisklasse `Medium` auf.
    // Dies stellt sicher, dass alle allgemeinen Informationen (ID, Titel, Status)
    // zuerst ausgegeben werden. So vermeiden wir Code-Duplizierung.
    Medium::ausgabe(out);

    // Schritt 2: Gib die zusätzlichen, nur für ein Buch spezifischen Informationen aus.
    out << "Autor: " << this->autor << std::endl;
}
