//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 
// 
// Versuch 2.3: Felder
//
// Datei:  Verschuesselung.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

using namespace std;

// Verschlüsselt das gegebene Wort mithilfe der Lookup-Tabelle.
// schluessel[0][i] = Klartext-Buchstabe (A–Z)
// schluessel[1][i] = entsprechendes Geheimzeichen
string verschluesseln(char schluessel[2][26], const string& wort)
{
    string geheim = "";
    for (size_t k = 0; k < wort.length(); ++k)
    {
        char c = wort[k];
        bool gefunden = false;
        if (c >= 'A' && c <= 'Z')
        {
            // Suche in der ersten Zeile nach Klartext-Buchstabe
            for (int i = 0; i < 26; ++i)
            {
                if (schluessel[0][i] == c)
                {
                    geheim = geheim + schluessel[1][i];
                    gefunden = true;
                    break;
                }
            }
        }
        // Zeichen, die nicht A–Z sind, oder nicht gefunden: unverändert übernehmen
        if (!gefunden)
        {
            geheim += c;
        }
    }
    return geheim;
}

// Entschlüsselt das gegebene Wort mithilfe der Lookup-Tabelle.
// schluessel[1][i] = Geheimzeichen
// schluessel[0][i] = Klartext-Buchstabe
string entschluesseln(char schluessel[2][26], const string& wort)
{
    string klar = "";
    for (size_t k = 0; k < wort.length(); ++k)
    {
        char c = wort[k];
        bool gefunden = false;
        if (c >= 'A' && c <= 'Z')
        {
            // Suche in der zweiten Zeile nach Geheimzeichen
            for (int i = 0; i < 26; ++i)
            {
                if (schluessel[1][i] == c)
                {
                    klar += schluessel[0][i];
                    gefunden = true;
                    break;
                }
            }
        }
        if (!gefunden)
        {
            klar += c;
        }
    }
    return klar;
}

int main()
{
    // 1) Lookup-Tabelle anlegen
    //    Zeile 0: Klartext A–Z
    //    Zeile 1: Geheimtext, hier als Beispiel-Permutation
    char schluessel[2][26];
    for (int i = 0; i < 26; ++i)
    {
        schluessel[0][i] = 'A' + i;
    }
    const string perm = "QWERTZUIOPASDFGHJKLYXCVBNM";
    for (int i = 0; i < 26; ++i)
    {
        schluessel[1][i] = perm[i];
    }

    // 2) Benutzereingabe
    cout << "Bitte geben Sie ein WORT in GROSSBUCHSTABEN ein: ";
    string eingabe;
    cin >> eingabe;

    // 3) Verschlüsseln und ausgeben
    string geheim = verschluesseln(schluessel, eingabe);
    cout << "\nKlartext       : " << eingabe  << endl;
    cout << "Verschluesselt : " << geheim   << endl;

    // 4) Entschlüsseln und ausgeben
    string entsch = entschluesseln(schluessel, geheim);
    cout << "Entschluesselt : " << entsch  << endl;

    return 0;
}
