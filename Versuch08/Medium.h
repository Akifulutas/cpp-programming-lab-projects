	/*!
	 * Praktikum Informatik 1
	 *
	 * @file Medium.h
	 */

	#ifndef MEDIUM_H_
	#define MEDIUM_H_

	#include "Datum.h"
	#include "Person.h"
	#include <string>
	#include <iostream> // Nötig für std::ostream

	/*!
	 * @brief Basisklasse für sämtliche Medien
	 *
	 * Diese Klasse stellt eine Basisklasse für Objekte dar, die Medien beschreiben.
	 * Von dieser Klasse werden alle anderen Medien, wie z.B. Buch oder DVD abgeleitet.
	 * Durch die rein virtuelle Funktion 'ausgabe' ist diese Klasse abstrakt.
	 */
	class Medium
	{
	public:
		/*!
		 * @brief Konstruktor
		 *
		 * @param std::string initTitel: Titel des Mediums
		 */
		Medium(std::string initTitel);

		/*!
		 * @brief virtueller Destruktor (Aufgabe 8.7.3)
		 * Wichtig, damit beim Löschen eines Objekts über einen Basisklassen-Zeiger
		 * der korrekte Destruktor der abgeleiteten Klasse aufgerufen wird.
		 */
		virtual ~Medium(void);

		/*!
		 * @brief Rein virtuelle Ausgabefunktion (Aufgabe 8.7.3 und 8.7.4)
		 *
		 * Macht die Klasse Medium zu einer abstrakten Klasse, es können keine
		 * reinen Medium-Objekte mehr erzeugt werden.
		 * Die Implementierung erfolgt in den abgeleiteten Klassen.
		 * Die Signatur wurde für die Operator-Überladung angepasst.
		 *
		 * @param std::ostream& out: Der Ausgabestream, in den geschrieben wird.
		 */
		virtual void ausgabe(std::ostream& out) const = 0;

		/*!
		 * @brief Virtuelle Ausleihen-Funktion (Aufgabe 8.7.2)
		 *
		 * Kann von abgeleiteten Klassen überschrieben werden, um spezifische
		 * Ausleihbeschränkungen (z.B. für DVD oder Magazin) zu implementieren.
		 *
		 * @param Person person: Person die das Medium ausleihen möchte
		 * @param Datum ausleihdatum: Datum an dem das Medium ausgeliehen wird
		 * @return bool: true, wenn Ausleihe erfolgreich, sonst false.
		 */
		virtual bool ausleihen(Person person, Datum ausleihdatum);

		/*!
		 * @brief Gibt ein Medium in die Bücherei zurück
		 */
		void zurueckgeben();

		/*!
		 * @brief ID des Mediums
		 *
		 * @return unsigned int: gibt die ID des Mediums zurück
		 */
		unsigned int getID() const;

		/*!
		 * @brief Status des Mediums (Aufgabe 8.7.4)
		 *
		 * Getter, um zu prüfen, ob ein Medium ausgeliehen ist.
		 * Wird für den neuen Menüpunkt benötigt.
		 *
		 * @return bool: gibt den Ausleihstatus zurück (true = ausgeliehen)
		 */
		bool getStatus() const;


	protected:
		/*!
		 * @brief Statische Variable zum Erzeugen der fortlaufenden IDs
		 */
		static unsigned int currentID;

		/*!
		 * @brief Eindeutige ID des Mediums
		 */
		unsigned int ID;

		/*!
		 * @brief Titel des Mediums
		 */
		std::string titel;

		/*!
		 * @brief Status des Mediums (true: ausgeliehen, false: nicht ausgeliehen)
		 */
		bool status;

		/*!
		 * @brief Datum seit dem das Medium ausgeliehen ist
		 */
		Datum datumAusgeliehen;

		/*!
		 * @brief Person, die das Medium ausgeliehen hat
		 */
		Person personAusgeliehen;

	};

	/*!
	 * @brief Überladung des Ausgabestream-Operators für die Klasse Medium (Aufgabe 8.7.4)
	 *
	 * Ruft polymorph die korrekte `ausgabe`-Methode des jeweiligen Mediums auf.
	 */
	std::ostream& operator<<(std::ostream& out, const Medium& medium);


	#endif /* MEDIUM_H_ */
