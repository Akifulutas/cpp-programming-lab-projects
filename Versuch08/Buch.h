/*!
 * Praktikum Informatik 1
 *
 * @file Buch.h
 */

#ifndef BUCH_H_
#define BUCH_H_

#include "Medium.h" // Die Basisklasse muss eingebunden werden
#include <string>

/*!
 * @brief Die Klasse Buch ist eine konkrete Ableitung der abstrakten Klasse Medium.
 *
 * Sie repräsentiert ein Buch mit einem Titel und einem Autor.
 */
class Buch : public Medium
{
public:
    /*!
     * @brief Konstruktor für ein Buch
     *
     * @param initTitel Der Titel des Buches
     * @param initAutor Der Autor des Buches
     */
    Buch(std::string initTitel, std::string initAutor);

    /*!
     * @brief Überschreibt die rein virtuelle Ausgabefunktion der Basisklasse.
     *
     * Gibt alle Informationen des Buches (inkl. der geerbten von Medium)
     * in den übergebenen Ausgabestrom aus. Das Schlüsselwort 'override'
     * stellt sicher, dass wir tatsächlich eine virtuelle Funktion der
     * Basisklasse überschreiben, was die Fehleranfälligkeit reduziert.
     *
     * @param out Der Ausgabestrom (z.B. std::cout)
     */
    void ausgabe(std::ostream& out) const override;

private:
    /*!
     * @brief Zusätzliches, spezifisches Attribut für die Klasse Buch.
     */
    std::string autor;
};

#endif /* BUCH_H_ */
