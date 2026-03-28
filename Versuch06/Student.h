//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXV
//////////////////////////////////////////////////////////////////////////////
/**
 * @file Student.h
 * @brief Deklaration der Klasse Student.
 *
 * Diese Header-Datei definiert die Schnittstelle der Klasse Student,
 * einschließlich ihrer Member-Variablen und Member-Funktionen.
 *
 * @author akifulutas
 */

#ifndef STUDENT_H_
#define STUDENT_H_

#include <string>

/**
 * @class Student
 * @brief Klasse zur Repräsentation eines Studenten.
 *
 * Diese Klasse dient als einfacher Datencontainer und speichert die
 * wesentlichen Informationen eines Studenten: Matrikelnummer, Name,
 * Geburtstag und Adresse.
 */
class Student
{
public:
    /**
     * @brief Standardkonstruktor.
     * Erstellt ein leeres Studenten-Objekt mit Standardwerten.
     */
    Student();

    /**
     * @brief Überladener Konstruktor.
     * Erstellt ein Studenten-Objekt mit spezifischen, übergebenen Daten.
     * @param matNr Matrikelnummer des Studenten.
     * @param name Vollständiger Name des Studenten.
     * @param geburtstag Geburtsdatum des Studenten.
     * @param adresse Adresse des Studenten.
     */
    Student(unsigned int matNr,
            const std::string &name,
            const std::string &geburtstag,
            const std::string &adresse);

    /**
     * @brief Gibt die Matrikelnummer des Studenten zurück.
     * @return Die Matrikelnummer als unsigned int.
     * @note Diese Funktion ist `const` und verändert das Objekt nicht.
     */
    unsigned int getMatNr() const;

    /**
     * @brief Gibt den Namen des Studenten zurück.
     * @return Der Name als std::string.
     * @note Diese Funktion ist `const` und verändert das Objekt nicht.
     */
    std::string getName() const;

    /**
     * @brief Gibt das Geburtsdatum des Studenten zurück.
     * @return Das Geburtsdatum als std::string.
     * @note Diese Funktion ist `const` und verändert das Objekt nicht.
     */
    std::string getGeburtstag() const;

    /**
     * @brief Gibt die Adresse des Studenten zurück.
     * @return Die Adresse als std::string.
     * @note Diese Funktion ist `const` und verändert das Objekt nicht.
     */
    std::string getAdresse() const;

    /**
     * @brief Gibt alle Daten des Studenten formatiert auf der Konsole aus.
     * @note Diese Funktion ist `const` und verändert das Objekt nicht.
     */
    void ausgabe() const;

private:
    //! @brief Die eindeutige Matrikelnummer des Studenten.
    unsigned int matNr;

    //! @brief Der vollständige Name des Studenten.
    std::string name;

    //! @brief Das Geburtsdatum des Studenten im Format TT.MM.JJJJ.
    std::string geburtstag;

    //! @brief Die Adresse des Studenten.
    std::string adresse;
};

#endif // STUDENT_H_
