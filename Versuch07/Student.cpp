/**
 * @file Student.cpp
 * @brief Implementierung der Student-Klasse.
 */
#include "Student.h"
#include <ostream>

/**
 * @brief Standardkonstruktor für einen leeren Studenten.
 */
Student::Student()
  : matNr(0), name(""), geburtstag(""), adresse("") {}

/**
 * @brief Konstruktor, um einen Studenten mit Daten zu initialisieren.
 * @param m Matrikelnummer
 * @param n Name
 * @param g Geburtstag
 * @param a Adresse
 */
Student::Student(unsigned int m, const std::string &n,
                 const std::string &g, const std::string &a)
  /// Initialisierungsliste: Effiziente Member-Initialisierung.
  : matNr(m), name(n), geburtstag(g), adresse(a) { }

/** @brief Gibt die Matrikelnummer zurück. */
unsigned int Student::getMatNr() const      { return matNr; }

/** @brief Gibt den Namen zurück. */
std::string  Student::getName() const        { return name; }

/** @brief Gibt das Geburtsdatum zurück. */
std::string  Student::getGeburtstag() const  { return geburtstag; }

/** @brief Gibt die Adresse zurück. */
std::string  Student::getAdresse() const     { return adresse; }

/**
 * @brief Schreibt formatierte Studentendaten auf einen Ausgabestrom.
 * @param out Der zu verwendende Ausgabestrom (z.B. std::cout).
 */
void Student::ausgabe(std::ostream& out) const {
    out << name
        << ", MatNr. " << matNr
        << ", geb. am " << geburtstag
        << ", wohnhaft in " << adresse
        << "\n";
}

/** @brief Vergleicht via Matrikelnummer (nötig für std::sort). */
bool Student::operator<(const Student& other) const { return matNr < other.matNr; }

/** @brief Vergleicht via Matrikelnummer. */
bool Student::operator>(const Student& other) const { return matNr > other.matNr; }

/** @brief Vergleicht via Matrikelnummer (nötig für std::find). */
bool Student::operator==(const Student& other) const { return matNr == other.matNr; }


/**
 * @brief Überlädt '<<' für die einfache Ausgabe von Studenten (z.B. `std::cout << s`).
 * @param out Ausgabestrom
 * @param s Student, der ausgegeben wird
 * @return Referenz auf den Stream, um Verkettung zu erlauben.
 */
std::ostream& operator<<(std::ostream& out, const Student& s) {
    /// Nutzt die 'ausgabe'-Methode für die eigentliche Formatierung.
    s.ausgabe(out);
    return out;
}
