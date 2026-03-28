//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXV
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "Student.h"

/**
 * @brief Konstruktor: Macht einen neuen Studenten mit Daten
 *
 * @param matNr Die Matrikelnummer
 * @param name Der Name
 * @param geburtstag Der Geburtstag
 * @param adresse Die Adresse
 */
Student::Student(unsigned int matNr, std::string name, std::string geburtstag, std::string adresse) :
matNr(matNr), name(name), geburtstag(geburtstag), adresse(adresse)
{ }

/**
 * @brief Macht einen leeren Studenten
 */
Student::Student() : matNr(0), name(""), geburtstag(""), adresse("")
{ }

/**
 * @brief Holt die Matrikelnummer vom Studenten
 *
 * @return Die Matrikelnummer
 */
unsigned int Student::getMatNr() const
{
    return matNr;
}

/**
 * @brief Holt den Namen vom Studenten
 *
 * @return Der Name
 */
std::string Student::getName() const
{
    return name;
}

/**
 * @brief Holt den Geburtstag vom Studenten
 *
 * @return Der Geburtstag
 */
std::string Student::getGeburtstag() const
{
    return geburtstag;
}

/**
 * @brief Holt die Adresse vom Studenten
 *
 * @return Die Adresse
 */
std::string Student::getAdresse() const
{
    return adresse;
}

/**
 * @brief Zeigt alle Daten vom Studenten in einer Zeile
 */
void Student::ausgabe() const
{
    std::cout << name << ", MatNr. " << matNr << ", geb. am "
              << geburtstag << ", wohnhaft in " << adresse
              << std::endl;
}
