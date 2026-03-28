/*!
 * Praktikum Informatik 1
 *
 * @file Medium.cpp
 */

#include "Medium.h"
#include <string>
#include <iostream>

// Initialisierung der statischen Klassenvariable 'currentID'.
// Diese sorgt für eine fortlaufende, eindeutige ID für jedes neue Medium.
unsigned int Medium::currentID = 1;


// Konstruktor
Medium::Medium(std::string initTitel)
    : titel(initTitel), status(false), personAusgeliehen() // personAusgeliehen wird mit Standardkonstruktor initialisiert
{
    this->ID = currentID++;
    // datumAusgeliehen wird ebenfalls mit dem Standardkonstruktor initialisiert,
    // der Wert wird aber erst bei einer tatsächlichen Ausleihe relevant und überschrieben.
}

// Virtueller Destruktor
// Die Implementierung ist hier leer, aber die Deklaration in der .h-Datei
// als 'virtual' ist entscheidend.
Medium::~Medium(void)
{
}

// Implementierung der Basis-Ausgabefunktion.
// Obwohl die Funktion in der .h als rein virtuell ('= 0') deklariert ist,
// muss sie hier eine Implementierung haben, damit die abgeleiteten Klassen
// sie mit 'Medium::ausgabe(out)' aufrufen können.
void Medium::ausgabe(std::ostream& out) const
{
    out << "ID: " << this->ID << std::endl;
    out << "Titel: " << this->titel << std::endl;

    if (this->status)
    {
        out << "Status: Das Medium ist seit dem " << this->datumAusgeliehen
            << " an " << this->personAusgeliehen.getName() << " ausgeliehen." << std::endl;
    }
    else
    {
        out << "Status: Medium ist zurzeit nicht verliehen." << std::endl;
    }
}


// Die Standard-Implementierung der ausleihen-Funktion.
// Sie wird aufgerufen, wenn eine abgeleitete Klasse keine eigene
// Ausleih-Logik implementiert (z.B. die Klasse Buch).
bool Medium::ausleihen(Person person, Datum ausleihdatum)
{
    if (this->status)
    {
        std::cout << "Das Medium \"" << this->titel << "\" ist bereits verliehen!" << std::endl;
        return false;
    }
    else
    {
        this->status = true;
        this->personAusgeliehen = person;
        this->datumAusgeliehen = ausleihdatum;
        std::cout << "Das Medium \"" << this->titel << "\" wird an " << person.getName() << " verliehen." << std::endl;
        return true;
    }
}


// Implementierung der zurueckgeben-Funktion.
void Medium::zurueckgeben()
{
    if (this->status)
    {
        this->status = false;
        std::cout << "Das Medium \"" << this->titel << "\" wurde zurueckgegeben." << std::endl;
    }
    else
    {
        std::cout << "Das Medium \"" << this->titel << "\" ist nicht verliehen!" << std::endl;
    }
}


// Implementierung des Getters für die ID.
unsigned int Medium::getID() const
{
    return this->ID;
}

// Implementierung des Getters für den Status (benötigt für Aufgabe 8.7.4)
bool Medium::getStatus() const
{
    return this->status;
}


// Implementierung des überladenen Ausgabeoperators (Aufgabe 8.7.4)
std::ostream& operator<<(std::ostream& out, const Medium& medium)
{
    // Ruft die virtuelle ausgabe-Methode auf.
    // Abhängig vom tatsächlichen Objekttyp (Buch, DVD, etc.) wird die
    // korrekte, überschriebene Methode ausgeführt. Dies ist Polymorphie in Aktion.
    medium.ausgabe(out);
    return out;
}
