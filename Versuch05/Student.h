//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXV
//////////////////////////////////////////////////////////////////////////////

#ifndef STUDENT_H_
#define STUDENT_H_

#include <string>

/**
 * @brief Klasse für einen Studenten
 *
 * Diese Klasse speichert Infos über einen Studenten:
 * Nummer, Name, Geburtstag und Adresse.
 */
class Student
{
public:
    /**
     * @brief Macht einen leeren Studenten
     */da
    Student();

    /**
     * @brief Macht einen Studenten mit allen Daten
     *
     * @param matNr Die Matrikelnummer
     * @param name Der Name
     * @param geburtstag Der Geburtstag (z. B. "01.01.2000")
     * @param address Die Adresse
     */
    Student(unsigned int matNr, std::string name, std::string geburtstag, std::string address);

    /**
     * @brief Holt die Matrikelnummer
     *
     * @return Die Matrikelnummer
     */
    unsigned int getMatNr() const;

    /**
     * @brief Holt den Namen
     *
     * @return Der Name
     */
    std::string getName() const;

    /**
     * @brief Holt den Geburtstag
     *
     * @return Der Geburtstag
     */
    std::string getGeburtstag() const;

    /**
     * @brief Holt die Adresse
     *
     * @return Die Adresse
     */
    std::string getAdresse() const;

    /**
     * @brief Zeigt alle Daten vom Studenten
     *
     * Schreibt Name, Nummer, Geburtstag und Adresse auf den Bildschirm.
     */
    void ausgabe() const;

private:
    unsigned int matNr;       ///< Die Matrikelnummer
    std::string name;         ///< Der Name
    std::string geburtstag;   ///< Der Geburtstag
    std::string adresse;      ///< Die Adresse
};

#endif // STUDENT_H_
