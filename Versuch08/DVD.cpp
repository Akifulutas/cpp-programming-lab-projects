/*!
 * Praktikum Informatik 1
 *
 * @file DVD.cpp
 */

#include "DVD.h"
#include "Person.h" // Nötig für den Zugriff auf das Geburtsdatum der Person
#include "Datum.h"  // Nötig für die Datumsberechnung
#include <iostream>

/*!
 * @brief Konstruktor-Implementierung für DVD
 */
DVD::DVD(std::string initTitel, int initAltersfreigabe, std::string initGenre)
    : Medium(initTitel), altersfreigabe(initAltersfreigabe), genre(initGenre)
{
    // Der Körper des Konstruktors bleibt leer.
}


/*!
 * @brief Implementierung der überschriebenen `ausgabe`-Funktion für DVD
 */
void DVD::ausgabe(std::ostream& out) const
{
    // Zuerst die allgemeinen Daten durch Aufruf der Basis-Implementierung ausgeben.
    Medium::ausgabe(out);

    // Danach die spezifischen DVD-Daten ausgeben.
    out << "FSK: ab " << this->altersfreigabe << " Jahre" << std::endl;
    out << "Genre: " << this->genre << std::endl;
}


/*!
 * @brief Implementierung der überschriebenen `ausleihen`-Funktion mit Altersprüfung
 */
bool DVD::ausleihen(Person person, Datum ausleihdatum)
{
    // Anforderung aus Aufgabe 8.7.2:
    // Eine DVD darf nur von Personen ausgeliehen werden, die die Altersbeschränkung erfüllen.

    // Schritt 1: Berechne das Alter der Person zum Zeitpunkt der Ausleihe in Jahren.
    // Der überladene `operator-` für Datum gibt die Differenz in Monaten zurück,
    // daher wird das Ergebnis durch 12 geteilt, um die Jahre zu erhalten.
    int alter = (ausleihdatum - person.getGeburtsdatum()) / 12;

    // Schritt 2: Vergleiche das Alter der Person mit der Altersfreigabe der DVD.
    if (alter < this->altersfreigabe)
    {
        std::cout << "FEHLER: Person " << person.getName() << " (" << alter << " Jahre) ist zu jung fuer die DVD \""
                  << this->titel << "\" (FSK " << this->altersfreigabe << ")." << std::endl;
        return false; // Ausleihe nicht erfolgreich.
    }
    else
    {
        // Wenn die Person alt genug ist, wird die normale Ausleih-Logik
        // der Basisklasse `Medium` verwendet (diese prüft nur, ob das Medium verfügbar ist).
        return Medium::ausleihen(person, ausleihdatum);
    }
}
