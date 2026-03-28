/*!
 * Praktikum Informatik 1
 *
 * @file Magazin.h
 */

#ifndef MAGAZIN_H_
#define MAGAZIN_H_

#include "Medium.h" // Basisklasse
#include "Datum.h"  // Nötig, da 'datumAusgabe' ein Member ist
#include <string>

/*!
 * @brief Die Klasse Magazin ist eine konkrete Ableitung von Medium.
 *
 * Repräsentiert ein Magazin mit Titel, Erscheinungsdatum und Sparte.
 * Sie hat eine eigene Ausleihlogik.
 */
class Magazin : public Medium
{
public:
    /*!
     * @brief Konstruktor für ein Magazin
     *
     * @param initTitel Der Titel des Magazins
     * @param initDatumAusgabe Das Erscheinungsdatum des Magazins
     * @param initSparte Die Sparte/Kategorie des Magazins
     */
    Magazin(std::string initTitel, Datum initDatumAusgabe, std::string initSparte);

    /*!
     * @brief Überschreibt die Ausgabefunktion der Basisklasse.
     *
     * @param out Der Ausgabestrom
     */
    void ausgabe(std::ostream& out) const override;

    /*!
     * @brief Überschreibt die Ausleihfunktion der Basisklasse.
     *
     * Implementiert die spezielle Regel, dass die aktuellste Ausgabe
     * eines Magazins nicht ausgeliehen werden darf.
     *
     * @param person Die Person, die ausleihen möchte
     * @param ausleihdatum Das aktuelle Datum der Ausleihe
     * @return bool true, wenn die Ausleihe erfolgreich war, sonst false
     */
    bool ausleihen(Person person, Datum ausleihdatum) override;

private:
    /*!
     * @brief Spezifische Attribute für die Klasse Magazin.
     */
    Datum datumAusgabe;
    std::string sparte;
};

#endif /* MAGAZIN_H_ */
