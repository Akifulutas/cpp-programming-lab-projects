/**
 * @file main.cpp
 * @brief Hauptanwendung zur Verwaltung von Studierendendaten.
 *
 * Dieses Programm ermöglicht das Hinzufügen, Löschen, Anzeigen und Speichern
 * von Studierendendaten über ein textbasiertes Menü. Die Daten werden in einem
 * std::vector<Student> gespeichert.
 *
 * @author akifulutas
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <limits>
#include "Student.h"

/**
 * @brief Einstiegspunkt der Anwendung.
 *
 * Zeigt ein textbasiertes Menü an, über das Studierendendaten verwaltet werden können.
 * Die möglichen Aktionen umfassen Einfügen, Löschen, Ausgeben und Dateizugriff.
 *
 * @return int Rückgabewert des Programms (0 bei erfolgreichem Lauf).
 */
int main()
{
    /// Vektor zur Speicherung aller Student-Objekte
    std::vector<Student> studenten;

    /// Speichert die Auswahl des Benutzers aus dem Menü
    char auswahl = '\0';

    do {
        std::cout << "\nMenue:\n"
                  << "1: Student hinten anhaengen\n"
                  << "2: Student vorne einfuegen\n"
                  << "3: Erstes Element loeschen\n"
                  << "4: Letztes Element loeschen\n"
                  << "5: Per Matrikelnummer loeschen\n"
                  << "6: Vorwaerts ausgeben\n"
                  << "7: Rueckwaerts ausgeben\n"
                  << "8: Daten aus Datei einlesen\n"
                  << "9: Daten in Datei sichern\n"
                  << "0: Beenden\n"
                  << "Waehlen: ";

        std::cin >> auswahl;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (auswahl) {
            case '1': {  /**
                         * @brief Hängt einen neuen Studenten am Ende des Vektors an.
                         *
                         * Fragt Name, Geburtstag, Adresse und Matrikelnummer ab und
                         * fügt den neuen Studenten mittels emplace_back hinzu.
                         */
                unsigned int m;
                std::string n, g, a;
                std::cout << "Name: "; std::getline(std::cin, n);
                std::cout << "Geburtstag: "; std::getline(std::cin, g);
                std::cout << "Adresse: "; std::getline(std::cin, a);
                std::cout << "Matrikelnummer: "; std::cin >> m;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                studenten.emplace_back(m, n, g, a);
            } break;

            case '2': {  /**
                         * @brief Fügt einen neuen Studenten am Anfang des Vektors ein.
                         *
                         * Fragt erforderliche Daten ab und verwendet insert(studenten.begin()).
                         */
                unsigned int m;
                std::string n, g, a;
                std::cout << "Name: "; std::getline(std::cin, n);
                std::cout << "Geburtstag: "; std::getline(std::cin, g);
                std::cout << "Adresse: "; std::getline(std::cin, a);
                std::cout << "Matrikelnummer: "; std::cin >> m;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                studenten.insert(studenten.begin(), Student(m, n, g, a));
            } break;

            case '3': {  /**
                         * @brief Löscht das erste Element im Vektor.
                         *
                         * Gibt zuerst den zu löschenden Studenten aus und entfernt ihn via erase(begin()).
                         * Prüft, ob der Vektor leer ist.
                         */
                if (!studenten.empty()) {
                    std::cout << "Loesche: ";
                    studenten.front().ausgabe();
                    studenten.erase(studenten.begin());
                } else {
                    std::cout << "Vektor ist leer\n";
                }
            } break;

            case '4': {  /**
                         * @brief Löscht das letzte Element im Vektor.
                         *
                         * Gibt zuerst den zu löschenden Studenten aus und entfernt ihn via pop_back().
                         * Prüft, ob der Vektor leer ist.
                         */
                if (!studenten.empty()) {
                    std::cout << "Loesche: ";
                    studenten.back().ausgabe();
                    studenten.pop_back();
                } else {
                    std::cout << "Vektor ist leer\n";
                }
            } break;

            case '5': {
                          /**
                           * @brief Löscht einen Studenten anhand der Matrikelnummer (manuelle Suche).
                           *
                           * Sucht das erste Element mit der angegebenen Matrikelnummer mittels einer
                           * for-Schleife und löscht es.
                           */
                          if (studenten.empty()) {
                              std::cout << "Vektor ist leer\n";
                              break;
                          }
                          unsigned int m;
                          std::cout << "Zu loeschende Matrikelnummer: "; std::cin >> m;
                          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                          // 1. Iterator zum Speichern der Fundstelle. Initial auf .end() gesetzt (= "nicht gefunden").
                          auto iteratorZumLoeschen = studenten.end();

                          // 2. Manuelle Schleife, um den Vektor von Anfang bis Ende zu durchlaufen.
                          for (auto it = studenten.begin(); it != studenten.end(); ++it) {
                              // 3. Prüfen, ob die Matrikelnummer des aktuellen Studenten übereinstimmt.
                              if (it->getMatNr() == m) {
                                  iteratorZumLoeschen = it; // 4a. Fundstelle im Ergebnis-Iterator speichern.
                                  break;                    // 4b. Schleife sofort beenden, da wir gefunden haben, was wir suchen.
                              }
                          }

                          // 5. Prüfen, ob der Ergebnis-Iterator verändert wurde (ob also etwas gefunden wurde).
                          if (iteratorZumLoeschen != studenten.end()) {
                              std::cout << "Loesche: ";
                              iteratorZumLoeschen->ausgabe();
                              studenten.erase(iteratorZumLoeschen); // Gefundenen Studenten löschen.
                          } else {
                              std::cout << "Nicht gefunden\n";
                          }
                      } break;


            case '6': {  /**
                         * @brief Gibt alle Studenten vorwärts aus.
                         *
                         * Durchläuft den Vektor mit einer range-based for-Schleife.
                         */
                if (!studenten.empty()) {
                    std::cout << "Vorwaerts:\n";
                    for (const auto &s : studenten)
                    	s.ausgabe();
                } else {
                    std::cout << "Vektor ist leer\n";
                }
            } break;

            case '7': {  /**
                         * @brief Gibt alle Studenten rückwärts aus.
                         *
                         * Verwendet reverse_iterator von rbegin() bis rend().
                         */
                if (!studenten.empty()) {
                    std::cout << "Rueckwaerts:\n";
                    for (auto it = studenten.rbegin(); it != studenten.rend(); ++it)
                        it->ausgabe();
                } else {
                    std::cout << "Vektor ist leer\n";
                }
            } break;

            case '8': {  /**
                         * @brief Liest Studierendaten aus einer Datei ein.
                         *
                         * Dateiname wird abgefragt, vorhandene Vektordaten werden gelöscht.
                         * Jeder Datensatz wird mittels while-Schleife eingelesen.
                         * @note Format: Matrikelnummer, Name, Geburtstag, Adresse je in einer Zeile.
                         */
                std::cout << "Dateiname zum Einlesen: ";
                std::string fn; std::getline(std::cin, fn);
                std::ifstream eingabe(fn);
                if (!eingabe) { std::cout << "Oeffnen fehlgeschlagen\n"; break; }

                studenten.clear();
                unsigned int m;
                std::string n, g, a;
                while (eingabe >> m) {
                    eingabe.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::getline(eingabe, n);
                    std::getline(eingabe, g);
                    std::getline(eingabe, a);
                    Student newstudent(m,n,g,a);
                    studenten.push_back(newstudent);
                }
                std::cout << "Eingelesen: " << studenten.size() << " Datensaetze\n";
            } break;

            case '9': {  /**
                         * @brief Speichert aktuelle Studierendaten in eine Datei.
                         *
                         * Dateiname wird abgefragt, jeder Student wird zeilenweise geschrieben.
                         */
                if (studenten.empty()) {
                    std::cout << "Keine Daten zum Sichern vorhanden\n"; break;
                }
                std::cout << "Dateiname zum Sichern: ";
                std::string fn; std::getline(std::cin, fn);
                std::ofstream ausgabe(fn);
                if (!ausgabe) { std::cout << "Oeffnen fehlgeschlagen\n"; break; }

                for (const auto &s : studenten) {
                    ausgabe << s.getMatNr() << "\n"
                            << s.getName() << "\n"
                            << s.getGeburtstag() << "\n"
                            << s.getAdresse() << "\n";
                }
                std::cout << "Gespeichert\n";
            } break;

            case '0':
                std::cout << "Beende...\n";  ///< Beendet die Anwendung
                break;

            default:
                std::cout << "Ungueltige Wahl\n";  ///< Ungültige Eingabe
        }

    } while (auswahl != '0');

    return 0;
}
