///////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXV
// Versuch 1.2: Strukturen
//
// Datei:  Strukturen.cpp
// Inhalt: Hauptprogramm
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

using namespace std;

// Definition der Struktur Person
struct Person
{
    string sNachname;
    string sVorname;
    int iGeburtsjahr;
    int iAlter;
};

int main()
{
    // 1. Schritt: Variable nBenutzer anlegen und Daten einlesen
    Person nBenutzer;
    cout << "Bitte geben Sie Ihren Nachnamen ein: ";
    cin >> nBenutzer.sNachname;
    cout << "Bitte geben Sie Ihren Vornamen ein: ";
    cin >> nBenutzer.sVorname;
    cout << "Bitte geben Sie Ihr Geburtsjahr ein: ";
    cin >> nBenutzer.iGeburtsjahr;
    cout << "Bitte geben Sie Ihr Alter ein: ";
    cin >> nBenutzer.iAlter;

    // Ausgabe von nBenutzer
    cout << "\nDaten von nBenutzer:" << endl;
    cout << "  Nachname:    " << nBenutzer.sNachname    << endl;
    cout << "  Vorname:     " << nBenutzer.sVorname     << endl;
    cout << "  Geburtsjahr: " << nBenutzer.iGeburtsjahr << endl;
    cout << "  Alter:       " << nBenutzer.iAlter       << endl;

    // 2. Schritt: Kopier-Variablen anlegen
    // a) Jedes Element einzeln kopieren
    Person nKopieEinzeln;
    nKopieEinzeln.sNachname    = nBenutzer.sNachname;
    nKopieEinzeln.sVorname     = nBenutzer.sVorname;
    nKopieEinzeln.iGeburtsjahr = nBenutzer.iGeburtsjahr;
    nKopieEinzeln.iAlter       = nBenutzer.iAlter;

    // b) Gesamte Struktur kopieren
    Person nKopieGesamt = nBenutzer;

    // Ausgabe von nKopieEinzeln
    cout << "\nDaten von nKopieEinzeln:" << endl;
    cout << "  Nachname:    " << nKopieEinzeln.sNachname    << endl;
    cout << "  Vorname:     " << nKopieEinzeln.sVorname     << endl;
    cout << "  Geburtsjahr: " << nKopieEinzeln.iGeburtsjahr << endl;
    cout << "  Alter:       " << nKopieEinzeln.iAlter       << endl;

    // Ausgabe von nKopieGesamt
    cout << "\nDaten von nKopieGesamt:" << endl;
    cout << "  Nachname:    " << nKopieGesamt.sNachname    << endl;
    cout << "  Vorname:     " << nKopieGesamt.sVorname     << endl;
    cout << "  Geburtsjahr: " << nKopieGesamt.iGeburtsjahr << endl;
    cout << "  Alter:       " << nKopieGesamt.iAlter       << endl;

    return 0;
}
