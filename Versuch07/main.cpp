//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXV
// Versuch 07
//////////////////////////////////////////////////////////////////////////////
/**
 * @file main.cpp
 * @brief Hauptanwendung zur Verwaltung von Studierendendaten.
 *
 * Diese Anwendung ermöglicht das Hinzufügen, Löschen, Anzeigen, Speichern und Laden
 * von Studentendatensätzen in einem Vektor.
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
 * @brief Hauptfunktion des Programms (Einstiegspunkt).
 *
 * Steuert den Hauptablauf des Programms: Menü anzeigen, Benutzereingaben verarbeiten
 * und die entsprechenden Aktionen zur Studentenverwaltung ausführen.
 * @return int Gibt 0 zurück, wenn das Programm erfolgreich beendet wurde.
 */
int main()
{
    /// Haupt-Datenstruktur zur Speicherung der Studenten.
    /// Ein Vektor wird verwendet, da er ein dynamisches Array ist, das einfach wachsen und schrumpfen kann.
    std::vector<Student> studenten;

    /// Variable zur Speicherung der Menüauswahl des Benutzers.
    char auswahl = '\0';

    /// Die Hauptschleife des Programms. Sie läuft so lange, bis der Benutzer '0' wählt.
    do {
        /// Gibt das Hauptmenü auf der Konsole aus, damit der Benutzer eine Aktion auswählen kann.
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
                  << "T: Studentenliste nach Matrikelnummer sortieren\n" // NEU
                  << "0: Beenden\n"
                  << "Waehlen: ";

        /// Lese die Auswahl des Benutzers ein (ein einzelnes Zeichen).
        std::cin >> auswahl;
        /// WICHTIG: Leert den Eingabepuffer. Nach der Eingabe von 'auswahl' und dem Drücken von Enter
        /// verbleibt das Zeilenumbruchzeichen ('\n') im Puffer. Ohne 'ignore' würde das nächste
        /// 'std::getline' dieses Zeichen sofort einlesen und eine leere Zeile zurückgeben.
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        /// Verzweigt das Programm basierend auf der Benutzereingabe.
        switch (auswahl) {
            case '1': {
                /// Block zum Anlegen und Anhängen eines neuen Studenten am Ende.
                unsigned int m;
                std::string n, g, a;
                std::cout << "Name: "; std::getline(std::cin, n);
                std::cout << "Geburtstag: "; std::getline(std::cin, g);
                std::cout << "Adresse: "; std::getline(std::cin, a);
                std::cout << "Matrikelnummer: "; std::cin >> m;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                /// Fügt einen neuen Studenten am Ende des Vektors hinzu. 'emplace_back' ist oft
                /// effizienter als 'push_back', da es das Objekt direkt im Vektor konstruiert
                /// und so eine zusätzliche Kopie vermeidet.
                studenten.emplace_back(m, n, g, a);
            } break;

            case '2': {
                /// Block zum Anlegen und Einfügen eines neuen Studenten am Anfang.
                unsigned int m;
                std::string n, g, a;
                std::cout << "Name: "; std::getline(std::cin, n);
                std::cout << "Geburtstag: "; std::getline(std::cin, g);
                std::cout << "Adresse: "; std::getline(std::cin, a);
                std::cout << "Matrikelnummer: "; std::cin >> m;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                /// Fügt einen neuen Studenten am Anfang des Vektors ein.
                /// 'studenten.begin()' ist ein Iterator, der auf die erste Position zeigt.
                studenten.insert(studenten.begin(), Student(m, n, g, a));
            } break;

            case '3': {
                /// Sicherheitsüberprüfung: Löschen ist nur möglich, wenn der Vektor nicht leer ist.
                if (!studenten.empty()) {
                    std::cout << "Loesche: ";
                    /// Gibt den ersten Studenten aus. 'front()' gibt eine Referenz auf das erste Element zurück.
                    std::cout << studenten.front();
                    /// Löscht das erste Element im Vektor. 'erase' benötigt einen Iterator auf das zu löschende Element.
                    studenten.erase(studenten.begin());
                } else {
                    std::cout << "Vektor ist leer\n";
                }
            } break;

            case '4': {
                /// Überprüfung, ob der Vektor Elemente enthält.
                if (!studenten.empty()) {
                    std::cout << "Loesche: ";
                    /// Gibt den letzten Studenten aus. 'back()' gibt eine Referenz auf das letzte Element zurück.
                    std::cout << studenten.back();
                    /// Entfernt das letzte Element aus dem Vektor. Dies ist eine sehr effiziente Operation.
                    studenten.pop_back();
                } else {
                    std::cout << "Vektor ist leer\n";
                }
            } break;

            case '5': {
                /// Wenn der Vektor leer ist, kann nichts gelöscht werden.
                if (studenten.empty()) {
                    std::cout << "Vektor ist leer\n";
                    break;
                }
                unsigned int userM;
                std::cout << "Zu loeschende Matrikelnummer: "; std::cin >> userM;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                /// Erstellt ein temporäres Student-Objekt nur für die Suche. Nur die Matrikelnummer
                /// ist hier relevant, da der 'operator==' (in Student.cpp definiert) nur diese vergleicht.
                Student suchStudent(userM, "", "", "");

                /// Verwendet den 'std::find'-Algorithmus aus <algorithm>, um den Studenten zu suchen.
                /// 'std::find' nutzt intern den überladenen 'operator==' der Student-Klasse.
                /// 'it' ist ein Iterator, der auf das gefundene Element zeigt.
                auto it = std::find(studenten.begin(), studenten.end(), suchStudent);

                /// Überprüft, ob der 'find'-Algorithmus erfolgreich war.
                /// Wenn 'it' ungleich 'studenten.end()' ist, wurde der Student gefunden.
                if (it != studenten.end()) {
                    std::cout << "Gefunden. Loesche: ";
                    std::cout << *it; // Dereferenzierung des Iterators, um das Student-Objekt auszugeben.

                    /// Löscht den Studenten an der Position, auf die der Iterator 'it' zeigt.
                    studenten.erase(it);

                    std::cout << "Restliche Elemente:\n";
                    for (const auto &s : studenten) {
                        std::cout << s; // Ausgabe mit dem überladenen 'operator<<'
                    }
                } else {
                    std::cout << "Student mit Matrikelnummer " << userM << " nicht gefunden.\n";
                }
            } break;

            case '6': {
                /// Gibt alle Studenten in der normalen Reihenfolge (von vorne nach hinten) aus.
                if (!studenten.empty()) {
                    std::cout << "Vorwaerts:\n";
                    /// Die Range-based for-Schleife ist die modernste und sicherste Methode,
                    /// um über alle Elemente eines Containers zu iterieren.
                    for (const auto &s : studenten) std::cout << s;
                } else {
                    std::cout << "Vektor ist leer\n";
                }
            } break;

            case '7': {
                /// Gibt alle Studenten in umgekehrter Reihenfolge aus.
                if (!studenten.empty()) {
                    std::cout << "Rueckwaerts:\n";
                    /// Dafür werden Reverse-Iteratoren verwendet. 'rbegin()' zeigt auf das letzte Element,
                    /// 'rend()' auf die Position *vor* dem ersten Element.
                    for (auto it = studenten.rbegin(); it != studenten.rend(); ++it)
                        std::cout << *it;
                } else {
                    std::cout << "Vektor ist leer\n";
                }
            } break;

            case '8': {
                /// Block zum Einlesen von Studentendaten aus einer Datei.
                std::cout << "Dateiname zum Einlesen: ";
                std::string fn; std::getline(std::cin, fn);

                /// Öffnet eine Datei zum Lesen (Input File Stream).
                std::ifstream eingabe(fn);

                /// Wichtige Fehlerbehandlung: Überprüft, ob die Datei erfolgreich geöffnet werden konnte.
                if (!eingabe) { std::cout << "Oeffnen fehlgeschlagen\n"; break; }

                /// Leert den Vektor, um Platz für die neuen Daten aus der Datei zu machen.
                studenten.clear();
                unsigned int m;
                std::string n, g, a;

                /// Schleife zum Einlesen der Datensätze. Die Bedingung 'eingabe >> m' liest die
                /// Matrikelnummer und prüft gleichzeitig, ob das Lesen erfolgreich war (und das
                /// Dateiende nicht erreicht ist).
                while (eingabe >> m) {
                    eingabe.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Konsumiert den restlichen Zeilenumbruch
                    std::getline(eingabe, n);
                    std::getline(eingabe, g);
                    std::getline(eingabe, a);
                    Student newstudent(m,n,g,a);
                    studenten.push_back(newstudent);
                }
                std::cout << "Eingelesen: " << studenten.size() << " Datensaetze\n";
            } break;

            case '9': {
                /// Block zum Sichern der aktuellen Studentendaten in eine Datei.
                if (studenten.empty()) {
                    std::cout << "Keine Daten zum Sichern vorhanden\n"; break;
                }
                std::cout << "Dateiname zum Sichern: ";
                std::string fn; std::getline(std::cin, fn);

                /// Öffnet eine Datei zum Schreiben (Output File Stream).
                std::ofstream ausgabe(fn);
                if (!ausgabe) { std::cout << "Oeffnen fehlgeschlagen\n"; break; }

                /// Iteriert durch alle Studenten im Vektor und schreibt deren Daten
                /// zeilenweise in die Datei.
                for (const auto &s : studenten) {
                    ausgabe << s.getMatNr() << "\n"
                            << s.getName() << "\n"
                            << s.getGeburtstag() << "\n"
                            << s.getAdresse() << "\n";
                }
                std::cout << "Gespeichert\n";
            } break;

            case 'T': {
                /// Block zum Sortieren des Vektors.
                if (studenten.empty()) {
                    std::cout << "Vektor ist leer, nichts zu sortieren.\n";
                } else {
                    std::cout << "Sortiere Studenten nach Matrikelnummer...\n";
                    /// Verwendet den 'std::sort'-Algorithmus. Standardmäßig benutzt 'std::sort'
                    /// den überladenen 'operator<' der Student-Klasse für die Vergleiche.
                    std::sort(studenten.begin(), studenten.end());
                    for(const Student& s : studenten )
                    {
                    	std::cout << s;
                    }
                    std::cout << "Sortierung abgeschlossen. Liste ausgeben (6):\n";
                }
            } break;

            case '0':
                /// Beendet die do-while-Schleife und damit das Programm.
                std::cout << "Beende...\n";
                break;

            default:
                /// Fallback für ungültige Menüoptionen.
                std::cout << "Ungueltige Wahl\n";
        }

    } while (auswahl != '0');

    return 0; /// Standard-Rückgabewert für eine erfolgreiche Ausführung.
}
