//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1
//
// Versuch 1.1: Datentypen und Typumwandlung
//
// Datei:  Variablen.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

using namespace std;

int main()
{
    int iErste = 0;
    int iZweite = 0;

    // Schritt 1: Zwei ganze Zahlen einlesen und als int ausgeben
    int iSumme    = 0;
    int iQuotient = 0;
    cout << "Schritt 1: Bitte geben Sie die erste ganze Zahl ein: ";
    cin  >> iErste;
    cout << "Schritt 1: Bitte geben Sie die zweite ganze Zahl ein: ";
    cin  >> iZweite;
    if (iZweite != 0) {
        iSumme    = iErste + iZweite;
        iQuotient = iErste / iZweite;
    } else {
        cout << "\nAchtung: Division durch null nicht erlaubt!" << endl;
    }
    cout << "\nErgebnisse Schritt 1 (int):\n"
         << "  iSumme    = "    << iSumme    << "\n"
         << "  iQuotient = "    << iQuotient << "\n";

    // Schritt 2: Summe und Quotient in double (ohne Cast)
    double dSumme    = iErste + iZweite;
    double dQuotient = 0.0;
    if (iZweite != 0) {
        dQuotient = iErste / iZweite;
    }
    cout << "\nErgebnisse Schritt 2 (double ohne Cast):\n"
         << "  dSumme    = "    << dSumme    << "\n"
         << "  dQuotient = "    << dQuotient << "\n";

    // Schritt 3: Summe und Quotient mit explizitem Cast zu double
    double dSummeCast    = (double)(iErste)
                         + static_cast<double>(iZweite);
    double dQuotientCast = 0.0;
    if (iZweite != 0) {
        dQuotientCast = (double)(iErste)
                      / static_cast<double>(iZweite);
    }
    cout << "\nErgebnisse Schritt 3 (double mit Cast):\n"
         << "  dSummeCast    = " << dSummeCast    << "\n"
         << "  dQuotientCast = " << dQuotientCast << "\n";

    // Erklärung:
    // Ohne Cast wird bei dQuotient zuerst eine Ganzzahldivision durchgeführt
    // und dann ins double konvertiert. Mit Cast findet die Gleitkomma-Division statt.

    // Schritt 4: Vor- und Nachnamen einlesen und kombinieren
    string sVorname, sNachname;
    cout << "\nSchritt 4: Bitte geben Sie Ihren Vornamen ein: ";
    cin  >> sVorname;
    cout << "Schritt 4: Bitte geben Sie Ihren Nachnamen ein: ";
    cin  >> sNachname;
    string sVornameName = sVorname + " " + sNachname;
    string sNameVorname = sNachname + ", " + sVorname;
    cout << "\nErgebnisse Schritt 4 (Namen):\n"
         << "  Vorname Nachname : " << sVornameName  << "\n"
         << "  Nachname, Vorname: " << sNameVorname << "\n";

    // Schritt 5a: Feld mit 2 Elementen
    {
        int iFeld[2] = {1, 2};
        cout << "\nSchritt 5a: iFeld[0] = " << iFeld[0]
             << ", iFeld[1] = " << iFeld[1] << "\n";
    }

    // Schritt 5b: 2×3-Feld
    {
        int spielfeld[2][3] = {{1,2,3}, {4,5,6}};
        cout << "\nSchritt 5b: spielfeld:\n";
        for (int z = 0; z < 2; ++z) {
            for (int s = 0; s < 3; ++s) {
                cout << spielfeld[z][s] << " ";
            }
            cout << "\n";
        }
    }

    // Schritt 5c: Konstante iZweite innerhalb eines Blocks
    {
        const int iZweite = 1;
        cout << "\nSchritt 5c: Konstanten-iZweite im Block = "
             << iZweite << "\n";
    }
    cout << "Schritt 5c: Ursprüngliche iZweite nach Block = "
         << iZweite << "\n";

    // Schritt 6: ASCII-Werte der ersten beiden Buchstaben im Vornamen
    {
        int iName1 = static_cast<int>(sVorname[0]);
        int iName2 = static_cast<int>(sVorname[1]);
        cout << "\nSchritt 6: ASCII-Werte:\n"
             << "  '" << sVorname[0] << "' -> " << iName1 << "\n"
             << "  '" << sVorname[1] << "' -> " << iName2 << "\n";
    }

    // Schritt 7: Position im Alphabet (A/a=1 … Z/z=26) per % 32
    {
        int iPos1 = static_cast<int>(sVorname[0]) % 32;
        int iPos2 = static_cast<int>(sVorname[1]) % 32;
        cout << "\nSchritt 7: Position im Alphabet:\n"
             << "  '" << sVorname[0] << "' = " << iPos1 << "\n"
             << "  '" << sVorname[1] << "' = " << iPos2 << "\n";
    }

    return 0;
}
