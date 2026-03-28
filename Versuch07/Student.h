#ifndef STUDENT_H_
#define STUDENT_H_

#include <string>
#include <iostream>

/**
 * @class Student
 * @brief Repräsentiert die Daten eines einzelnen Studenten.
 */
class Student
{
public:
    /** @brief Standardkonstruktor. */
    Student();

    /** @brief Initialisierungskonstruktor. */
    Student(unsigned int matNr,
            const std::string &name,
            const std::string &geburtstag,
            const std::string &adresse);
    /** @brief Liefert die Matrikelnummer. */
    unsigned int getMatNr() const;
    /** @brief Liefert den Namen. */
    std::string  getName() const;
    /** @brief Liefert den Geburtstag. */
    std::string  getGeburtstag() const;
    /** @brief Liefert die Adresse. */
    std::string  getAdresse() const;

    /** @brief Schreibt formatierte Daten in einen ostream (Ausgabestrom). */
    void ausgabe(std::ostream& out) const;
    /** @brief Vergleicht auf "kleiner als" (für std::sort). */
    bool operator<(const Student& other) const;
    /** @brief Vergleicht auf "größer als". */
    bool operator>(const Student& other) const;
    /** @brief Vergleicht auf Gleichheit (für std::find). */
    bool operator==(const Student& other) const;

private:
    unsigned int matNr;
    std::string  name;
    std::string  geburtstag;
    std::string  adresse;
};

/** @brief Globale Überladung von operator<< für einfache Ausgabe (z.B. `cout << student`). */
std::ostream& operator<<(std::ostream& out, const Student& s);

#endif // STUDENT_H_
