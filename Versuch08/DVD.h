/*!
 * Praktikum Informatik 1
 *
 * @file DVD.h
 */

#ifndef DVD_H_
#define DVD_H_

#include "Medium.h" // Basisklasse einbinden
#include <string>

/*!
 * @brief Die Klasse DVD ist eine konkrete Ableitung von Medium.
 *
 * Repräsentiert eine DVD mit Titel, Altersfreigabe (FSK) und Genre.
 * Besitzt eine eigene Ausleihlogik basierend auf der Altersfreigabe.
 */
class DVD : public Medium
{
public:
    /*!
     * @brief Konstruktor für eine DVD
     *
     * @param initTitel Der Titel der DVD
     * @param initAltersfreigabe Die Altersfreigabe (z.B. 0, 6, 12, 16, 18)
     * @param initGenre Das Genre der DVD (z.B. Action, Komödie)
     */
    DVD(std::string initTitel, int initAltersfreigabe, std::string initGenre);

    /*!
     * @brief Überschreibt die Ausgabefunktion der Basisklasse.
     *
     * @param out Der Ausgabestrom
     */
    void ausgabe(std::ostream& out) const override;

    /*!
     * @brief Überschreibt die Ausleihfunktion der Basisklasse.
     *
     * Implementiert die Prüfung der Altersfreigabe der ausleihenden Person.
     *
     * @param person Die Person, die ausleihen möchte
     * @param ausleihdatum Das aktuelle Datum der Ausleihe
     * @return bool true, wenn die Ausleihe erfolgreich war, sonst false
     */
    bool ausleihen(Person person, Datum ausleihdatum) override;

private:
    /*!
     * @brief Spezifische Attribute für die Klasse DVD.
     */
    int altersfreigabe;
    std::string genre;
};

#endif /* DVD_H_ */
