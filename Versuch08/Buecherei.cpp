//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXV
// Versuch 08: Vererbung und Polymorphie
//
// Datei:  Buecherei.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

/*
 * Durch Setzen dieser Variable auf 'true' werden die abgeleiteten Klassen
 * (Buch, DVD, Magazin) verwendet.
 */
#define UNTERKLASSENVORHANDEN true

#include <iostream>
#include <string>
#include <vector>
#include "Datum.h"
#include "Medium.h" // Die Basisklasse wird immer benötigt

#if UNTERKLASSENVORHANDEN
#include "Magazin.h"
#include "Buch.h"
#include "DVD.h"
#endif

// Vorwärtsdeklarationen aller vorhandenen Funktionen
void fuelleDatenbank(std::vector<Medium*>& medien);
void mediumHinzufuegen(std::vector<Medium*>& medien);
void mediumEntfernen(std::vector<Medium*>& medien);
void mediumAusleihen(std::vector<Medium*>& medien, Datum aktuellesDatum);
void mediumZurueckgeben(std::vector<Medium*>& medien);
void alleMedienAusgeben(const std::vector<Medium*>& medien);
// Neue Funktion für Aufgabe 8.7.4
void alleAusgeliehenenAusgeben(const std::vector<Medium*>& medien);

///////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    // Vektor mit allen Medien der Bücherei (als Zeiger auf die Basisklasse)
    std::vector<Medium*> medien;

    // Aktuelles Datum
    Datum aktuellesDatum;
    std::cout << "Aktuelles Datum: " << aktuellesDatum << std::endl;

    // Datenbank mit Beispieldaten füllen
    fuelleDatenbank(medien);

    char abfrage;
    do // Anzeige des Menüs
    {
        std::cout << std::endl
                  << "Menue:" << std::endl
                  << "-----------------------------" << std::endl
                  << "(1): Medium hinzufuegen" << std::endl
                  << "(2): Medium loeschen" << std::endl
                  << "(3): Datenbank ausgeben" << std::endl
                  << "(4): Ein Medium ausleihen" << std::endl
                  << "(5): Ein Medium zuruecknehmen" << std::endl
                  << "(6): Alle ausgeliehenen Medien anzeigen" << std::endl // Neuer Menüpunkt
                  << "(7): Beenden" << std::endl;

        // Einlesen der Abfrage
        std::cin >> abfrage;
        std::cin.ignore(10, '\n');

        switch (abfrage)
        {
        case '1':
            mediumHinzufuegen(medien);
            break;
        case '2':
            mediumEntfernen(medien);
            break;
        case '3':
            alleMedienAusgeben(medien);
            break;
        case '4':
            mediumAusleihen(medien, aktuellesDatum);
            break;
        case '5':
            mediumZurueckgeben(medien);
            break;
        case '6': // Neuer case für Aufgabe 8.7.4
            alleAusgeliehenenAusgeben(medien);
            break;
        case '7':
            std::cout << "Das Programm wird nun beendet." << std::endl;
            break;
        default:
            std::cout << "Falsche Eingabe, bitte nochmal versuchen." << std::endl;
            break;
        }
    } while (abfrage != '7');

    // Beim Beenden des Programms sämtliche Medien löschen, um Speicherlecks zu vermeiden
    for (std::vector<Medium*>::iterator it = medien.begin(); it != medien.end(); it++)
    {
        delete (*it);
    }
    medien.clear(); // Vektor leeren

    return 0;
}

/////////////////////////////////////////////////////////////
// Definition aller deklarierten Funktionen
/////////////////////////////////////////////////////////////

// Funktion füllt die Datenbank der Bücherei automatisch mit Beispieldaten
void fuelleDatenbank(std::vector<Medium*>& medien)
{
#if UNTERKLASSENVORHANDEN
    // Die Datenbank wird mit konkreten Medien (Buch, Magazin, DVD) gefüllt
    medien.push_back(new Buch("Das Parfum", "Patrick Suskind"));
    medien.push_back(new Buch("Harry Potter und der Stein der Weisen", "J. K. Rowling"));
    medien.push_back(new Buch("Tom Sawyer", "Mark Twain"));
    // Ein aktuelles Magazin, um die Ausleih-Sperre zu testen
    medien.push_back(new Magazin("Chip", Datum(1, 6, 2025), "Computer"));
    medien.push_back(new DVD("Fluch der Karibik", 12, "Actionkomödie"));
    medien.push_back(new Buch("Huckleberry Finn", "Mark Twain"));
#else
    // Dieser Block ist nicht mehr erreichbar, da Medium eine abstrakte Klasse ist
    // und 'new Medium(...)' einen Compiler-Fehler erzeugen würde.
#endif
}

// Funktion fügt ein vom Benutzer definiertes Medium zur Datenbank hinzu
void mediumHinzufuegen(std::vector<Medium*>& medien)
{
#if UNTERKLASSENVORHANDEN
    std::cout << "Geben Sie die Art des Mediums ein: " << std::endl
              << "(1): Buch" << std::endl
              << "(2): Magazin" << std::endl
              << "(3): DVD" << std::endl;

    char abfrage;
    std::cin >> abfrage;
    std::cin.ignore(10, '\n');

    std::string titel;
    std::cout << "Bitte geben Sie den Titel ein: " << std::endl;
    std::getline(std::cin, titel);

    switch (abfrage)
    {
    case '1': // Buch
    {
        std::string autor;
        std::cout << "Bitte geben sie den Autor des Buchs ein: " << std::endl;
        std::getline(std::cin, autor);
        medien.push_back(new Buch(titel, autor));
        break;
    }
    case '2': // Magazin
    {
        std::string sparte;
        std::cout << "Geben Sie die Sparte an:" << std::endl;
        std::getline(std::cin, sparte);
        Datum datumAusgabe;
        std::cout << "Geben Sie das Erscheinungsdatum der Ausgabe an (Format TT.MM.JJJJ):" << std::endl;
        std::cin >> datumAusgabe;
        std::cin.ignore(10, '\n');
        medien.push_back(new Magazin(titel, datumAusgabe, sparte));
        break;
    }
    case '3': // DVD
    {
        std::string genre;
        std::cout << "Geben Sie das Genre an:" << std::endl;
        std::getline(std::cin, genre);
        int altersfreigabe;
        std::cout << "Geben Sie die Altersfreigabe ein:" << std::endl;
        std::cin >> altersfreigabe;
        std::cin.ignore(10, '\n');
        medien.push_back(new DVD(titel, altersfreigabe, genre));
        break;
    }
    default:
        std::cout << "Ungueltige Eingabe!" << std::endl;
        break;
    }
#else
    std::string titel;
    std::cout << "Bitte geben sie den Titel des Mediums ein:\n";
    getline(std::cin, titel);
    // Erzeugen eines 'Medium' nicht mehr möglich!
#endif
}

// Funktion entfernt ein Medium aus der Datenbank
void mediumEntfernen(std::vector<Medium*>& medien)
{
    unsigned int id;
    std::cout << "Geben Sie die ID des Mediums ein, welches geloescht werden soll: ";
    std::cin >> id;
    std::cin.ignore(10, '\n');

    bool success = false;
    for (std::vector<Medium*>::iterator it = medien.begin(); it != medien.end(); it++)
    {
        if ((*it)->getID() == id)
        {
            delete (*it);      // Objekt löschen (ruft virtuellen Destruktor auf)
            medien.erase(it);  // Zeiger aus dem Vektor entfernen
            success = true;
            std::cout << "Medium mit ID " << id << " wurde geloescht." << std::endl;
            break;
        }
    }
    if (!success)
    {
        std::cout << "Keine gueltige ID!" << std::endl;
    }
}

// Funktion leiht ein Medium aus der Datenbank aus
void mediumAusleihen(std::vector<Medium*>& medien, Datum aktuellesDatum)
{
    unsigned int id;
    std::cout << "Geben Sie die ID des Mediums ein:" << std::endl;
    std::cin >> id;
    std::cin.ignore(10, '\n');

    // Personendaten einlesen
    std::string name;
    std::cout << "Geben Sie den Namen der Person ein: ";
    getline(std::cin, name);
    Datum geburtsdatum;
    std::cout << "Geben Sie das Geburtsdatum der Person ein (Format TT.MM.JJJJ): ";
    std::cin >> geburtsdatum;
    std::cin.ignore(10, '\n');
    Person person(name, geburtsdatum);

    bool id_vorhanden = false;
    for (std::vector<Medium*>::iterator it = medien.begin(); it != medien.end(); it++)
    {
        if ((*it)->getID() == id)
        {
            // Polymorpher Aufruf: Ruft die korrekte 'ausleihen'-Methode auf
            (*it)->ausleihen(person, aktuellesDatum);
            id_vorhanden = true;
            break;
        }
    }
    if (!id_vorhanden)
    {
        std::cout << "Keine gueltige ID!" << std::endl;
    }
}

// Funktion gibt ein ausgeliehenes Medium zurück
void mediumZurueckgeben(std::vector<Medium*>& medien)
{
    unsigned int id;
    std::cout << "Geben Sie die ID des Mediums ein: ";
    std::cin >> id;
    std::cin.ignore(10, '\n');

    bool id_vorhanden = false;
    for (std::vector<Medium*>::iterator it = medien.begin(); it != medien.end(); it++)
    {
        if ((*it)->getID() == id)
        {
            (*it)->zurueckgeben();
            id_vorhanden = true;
            break;
        }
    }
    if (!id_vorhanden)
    {
        std::cout << "Keine gueltige ID!" << std::endl;
    }
}

// Funktion gibt alle Medien in der Datenbank aus
void alleMedienAusgeben(const std::vector<Medium*>& medien)
{
    std::cout << "Vorhandene Medien in der Buecherei:" << std::endl;
    if (medien.empty())
    {
        std::cout << "Die Buecherei ist derzeit leer." << std::endl;
        return;
    }
    for (unsigned int index = 0; index < medien.size(); index++)
    {
        std::cout << "*************************************************************" << std::endl;
        // Benutzung des überladenen '<<' Operators (Aufgabe 8.7.4)
        std::cout << *(medien[index]);
    }
    std::cout << "*************************************************************" << std::endl;
}

// Neue Funktion gibt NUR die ausgeliehenen Medien aus (Aufgabe 8.7.4)
void alleAusgeliehenenAusgeben(const std::vector<Medium*>& medien)
{
    std::cout << "Derzeit ausgeliehene Medien:" << std::endl;
    bool found = false;
    for (unsigned int i = 0; i < medien.size(); i++)
    {
        // Getter verwenden, um den Status zu prüfen
        if (medien[i]->getStatus())
        {
            std::cout << "*************************************************************" << std::endl;
            // Benutzung des überladenen '<<' Operators
            std::cout << *(medien[i]);
            found = true;
        }
    }

    if (!found)
    {
        std::cout << "Aktuell sind keine Medien ausgeliehen." << std::endl;
    }
    else
    {
        std::cout << "*************************************************************" << std::endl;
    }
}
