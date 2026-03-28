//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXV
//////////////////////////////////////////////////////////////////////////////
/**
 * @file Student.cpp
 * @brief Implementierung der Methoden der Student-Klasse.
 *
 * Diese Datei enthält die Definitionen für die Konstruktoren und
 * Member-Funktionen der Klasse Student.
 *
 * @author akifulutas
 */

#include "Student.h"
#include <iostream>

/**
 * @brief Standardkonstruktor der Klasse Student.
 *
 * Initialisiert ein neues Studenten-Objekt mit Standardwerten (0 für die
 * Matrikelnummer und leere Strings für die Textfelder).
 * Dies geschieht über eine Initialisiererliste (`:`), was die effizienteste
 * Methode zur Initialisierung von Member-Variablen ist.
 */
Student::Student()
    : matNr(0), name(""), geburtstag(""), adresse("") {}

/**
 * @brief Überladener Konstruktor zum Erstellen eines spezifischen Studenten.
 *
 * Erstellt ein Studenten-Objekt und initialisiert es direkt mit den
 * übergebenen Werten. Auch hier wird eine Initialisiererliste für
 * maximale Effizienz verwendet.
 *
 * @param m Die Matrikelnummer des Studenten.
 * @param n Der Name des Studenten.
 * @param g Das Geburtsdatum des Studenten.
 * @param a Die Adresse des Studenten.
 */
Student::Student(unsigned int m, const std::string &n,
                 const std::string &g, const std::string &a)
    : matNr(m), name(n), geburtstag(g), adresse(a) {}


// --- Getter-Methoden ---
// Getter sind einfache Funktionen, die nur den Wert einer privaten Member-Variable
// zurückgeben. Sie sind als `const` deklariert, weil sie den Zustand des
// Objekts nicht verändern.

/**
 * @brief Gibt die Matrikelnummer zurück.
 * @return Die Matrikelnummer des Studenten.
 */
unsigned int Student::getMatNr() const { return matNr; }

/**
 * @brief Gibt den Namen zurück.
 * @return Der Name des Studenten.
 */
std::string Student::getName() const { return name; }

/**
 * @brief Gibt das Geburtsdatum zurück.
 * @return Das Geburtsdatum des Studenten.
 */
std::string Student::getGeburtstag() const { return geburtstag; }

/**
 * @brief Gibt die Adresse zurück.
 * @return Die Adresse des Studenten.
 */
std::string Student::getAdresse() const { return adresse; }


/**
 * @brief Gibt alle Daten des Studenten formatiert auf der Konsole aus.
 *
 * Diese Methode ist als `const` deklariert, da sie die Daten des Studenten
 * nur liest und nicht verändert. Dies ist gute Praxis für alle Funktionen,
 * die keine Schreibvorgänge auf Member-Variablen durchführen.
 */
void Student::ausgabe() const {
    std::cout << name
              << ", MatNr. " << matNr
              << ", geb. am " << geburtstag
              << ", wohnhaft in " << adresse
              << "\n";
}
