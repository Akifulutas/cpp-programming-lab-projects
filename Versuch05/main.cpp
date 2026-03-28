/** @mainpage
 *
 * Praktikum Informatik 1 MMXXV <BR>
 * Versuch 5: Dynamische Datenstrukturen
 *
 */

#include <iostream>
#include <string>

#include "Liste.h"
#include "Student.h"

/**
 * @brief Hauptprogramm: Liste mit Studenten
 *
 * Dieses Programm liest Eingaben vom Benutzer.
 * Man kann Studenten in eine doppelte Liste einfügen, löschen oder zeigen.
 *
 * @return int Gibt 0 zurück, wenn alles gut ist
 */
int main()
{
    Liste studentenListe;   // Die Liste ist jetzt leer
    Student student;        // Ein Student-Objekt zum Speichern

    char abfrage;           // Hier speichern wir, was der Nutzer im Menü wählt
    std::cout << "Wollen Sie die Liste selbst fuellen? (j)/(n) ";
    std::string eingabe;
    std::getline(std::cin, eingabe);
    abfrage = eingabe.empty() ? ' ' : eingabe[0];  // Wir nehmen den ersten Buchstaben

    // Wenn Benutzer nicht 'j' sagt, fügen wir Beispiel-Studenten hinzu
    if (abfrage != 'j')
    {
        student = Student(34567, "Harro Simoneit", "19.06.1971", "Am Markt 1");
        studentenListe.pushBack(student);
        student = Student(74567, "Vera Schmitt", "23.07.1982", "Gartenstr. 23");
        studentenListe.pushBack(student);
        student = Student(12345, "Siggi Baumeister", "23.04.1983", "Ahornst.55");
        studentenListe.pushBack(student);
        student = Student(64567, "Paula Peters", "9.01.1981", "Weidenweg 12");
        studentenListe.pushBack(student);
        student = Student(23456, "Walter Rodenstock", "15.10.1963", "W llnerstr.9");
        studentenListe.pushBack(student);
    }

    // Menü läuft, bis der Benutzer '0' drückt
    do
    {
        std::cout << "\nMenue:" << std::endl
                  << "-----------------------------" << std::endl
                  << "(1): Student hinten zur Liste" << std::endl
                  << "(2): Student vorne zur Liste" << std::endl
                  << "(3): Ersten Student löschen" << std::endl
                  << "(4): Liste zeigen" << std::endl
                  << "(5): Liste rückwärts zeigen" << std::endl
                  << "(6): Student mit Nummer löschen" << std::endl
                  << "(0): Beenden" << std::endl;
        std::cin >> abfrage;
        std::cin.ignore(10, '\n'); // Rest ignorieren

        switch (abfrage)
        {
            case '1':
                {
                    // Neuer Student hinten zur Liste
                    unsigned int matNr = 0;
                    std::string name, geburtstag, adresse;

                    std::cout << "Bitte geben Sie die Daten ein.\nName: ";
                    std::getline(std::cin, name);
                    std::cout << "Geburtsdatum: ";
                    std::getline(std::cin, geburtstag);
                    std::cout << "Adresse: ";
                    std::getline(std::cin, adresse);
                    std::cout << "Matrikelnummer: ";
                    std::cin >> matNr;
                    std::cin.ignore(10, '\n');

                    student = Student(matNr, name, geburtstag, adresse);
                    studentenListe.pushBack(student);
                }
                break;

            case '2':
                {
                    // Neuer Student vorne zur Liste
                    unsigned int matNr = 0;
                    std::string name, geburtstag, adresse;

                    std::cout << "Bitte geben Sie die Daten ein.\nName: ";
                    std::getline(std::cin, name);
                    std::cout << "Geburtsdatum: ";
                    std::getline(std::cin, geburtstag);
                    std::cout << "Adresse: ";
                    std::getline(std::cin, adresse);
                    std::cout << "Matrikelnummer: ";
                    std::cin >> matNr;
                    std::cin.ignore(10, '\n');

                    student = Student(matNr, name, geburtstag, adresse);
                    studentenListe.pushFront(student);
                }
                break;

            case '3':
                {
                    // Ersten Student löschen
                    if (!studentenListe.empty())
                    {
                        student = studentenListe.dataFront();
                        std::cout << "Dieser Student wurde gelöscht:" << std::endl;
                        student.ausgabe(); // Student zeigen
                        studentenListe.popFront();
                    }
                    else
                    {
                        std::cout << "Die Liste ist leer!\n";
                    }
                }
                break;

            case '4':
                {
                    // Liste von vorne zeigen
                    if (!studentenListe.empty())
                    {
                        std::cout << "Alle Studenten in der Liste:" << std::endl;
                        studentenListe.ausgabeVorwaerts();
                    }
                    else
                    {
                        std::cout << "Die Liste ist leer!\n\n";
                    }
                }
                break;

            case '5':
                {
                    // Liste rückwärts zeigen
                    if (!studentenListe.empty())
                    {
                        std::cout << "Alle Studenten von hinten nach vorne:" << std::endl;
                        studentenListe.ausgabeRueckwaerts();
                    }
                    else
                    {
                        std::cout << "Die Liste ist leer!\n\n";
                    }
                }
                break;

            case '6':
                {
                    // Student mit bestimmter Nummer löschen
                    if (!studentenListe.empty())
                    {
                        unsigned int matNr;
                        std::cout << "Geben Sie bitte die Matrikelnummer ein: ";
                        std::cin >> matNr;
                        std::cin.ignore(10, '\n');

                        if (studentenListe.deleteNode(matNr))
                        {
                            std::cout << "Student mit Nummer " << matNr << " wurde gelöscht." << std::endl;
                        }
                        else
                        {
                            std::cout << "Student mit Nummer " << matNr << " nicht gefunden!" << std::endl;
                        }
                    }
                    else
                    {
                        std::cout << "Die Liste ist leer!\n";
                    }
                }
                break;

            case '0':
                std::cout << "Programm beendet";
                break;

            default:
                std::cout << "Falsche Eingabe, bitte nochmal";
                break;
        }
    }
    while (abfrage != '0'); // Wiederholen, bis der Benutzer '0' eingibt

    return 0; // Programm endet erfolgreich
}
