/*!
 * Praktikum Informatik 1
 *
 * @file Magazin.cpp
 */

#include "Magazin.h"
#include <iostream>

/*!
 * @brief Konstruktor-Implementierung für Magazin
 *
 * Nutzt die Initialisierungsliste, um zuerst die Basisklasse `Medium`
 * und danach die eigenen Member `datumAusgabe` und `sparte` zu initialisieren.
 */
Magazin::Magazin(std::string initTitel, Datum initDatumAusgabe, std::string initSparte)
    : Medium(initTitel), datumAusgabe(initDatumAusgabe), sparte(initSparte)
{
    // Der Konstruktor-Körper bleibt leer.
}


/*!
 * @brief Implementierung der überschriebenen `ausgabe`-Funktion für Magazin
 */
void Magazin::ausgabe(std::ostream& out) const
{
    // Zuerst die allgemeinen Daten durch Aufruf der Basis-Implementierung ausgeben.
    Medium::ausgabe(out);

    // Danach die spezifischen Daten für ein Magazin ausgeben.
    out << "Ausgabe: " << this->datumAusgabe << std::endl;
    out << "Sparte: " << this->sparte << std::endl;
}


/*!
 * @brief Implementierung der überschriebenen `ausleihen`-Funktion mit spezieller Logik
 */
bool Magazin::ausleihen(Person person, Datum ausleihdatum)
{
    // Anforderung aus Aufgabe 8.7.2:
    // Ein Magazin darf nicht ausgeliehen werden, wenn es sich um die neueste Ausgabe handelt.
    // Annahme: "Neueste Ausgabe" bedeutet, dass es im selben Monat wie das Ausleihdatum erschienen ist.
    // Der überladene Subtraktions-Operator der Klasse Datum (`operator-`) gibt die
    // Differenz zwischen zwei Daten in ganzen Monaten zurück.
    if ((ausleihdatum - this->datumAusgabe) < 1)
    {
        // Wenn die Differenz weniger als ein Monat beträgt, ist es die aktuelle Ausgabe.
        std::cout << "FEHLER: Das Magazin \"" << this->titel << "\" ist eine aktuelle Ausgabe und kann nicht ausgeliehen werden." << std::endl;
        return false; // Ausleihe nicht erfolgreich.
    }
    else
    {
        // Wenn es sich nicht um die neueste Ausgabe handelt, kann die normale
        // Ausleih-Logik der Basisklasse `Medium` verwendet werden.
        return Medium::ausleihen(person, ausleihdatum);
    }
}
