/**
 * Praktikum Informatik 1 
 * 
 *
 * @file main.cpp
 *
 * Die Funktionen fuer das Spiel Othello
 */

/**
* @mainpage Othello
*
* Dokumentation des Spiels Othello im Rahmen des Praktikums Informatik 1.
*
*/

#include <iostream>
#include <string>
#include "config.h"
#include "test.h"
#include "othelloKI.h"


/**
 * @brief Funktion zur ersten Initialisierung eines neuen Spielfelds
 *
 * Diese Funktion fuellt ein existierendes Spielfeld mit Nullen und erzeugt die Startaufstellung.
 *
 * @param spielfeld Spielfeld, das initialisiert wird
 */
void initialisiereSpielfeld(int spielfeld[GROESSE_Y][GROESSE_X])
{
    for (int j = 0; j < GROESSE_Y; j++)
        {
            for(int i = 0; i < GROESSE_X; i++)
            {
                spielfeld[j][i] = 0;
            }
        }
        spielfeld[GROESSE_Y / 2 - 1][GROESSE_X / 2 - 1] = 1;
        spielfeld[GROESSE_Y / 2][GROESSE_X / 2 - 1] = 2;
        spielfeld[GROESSE_Y / 2 - 1][GROESSE_X / 2] = 2;
        spielfeld[GROESSE_Y / 2][GROESSE_X / 2] = 1;
}



/**
* @brief Ausgabe des Spielfelds auf der Konsole
*
* Ausgabe des aktuellen Spielfelds, 0 bedeutet leeres Feld, 1 ist Spieler 1 und 2 ist Spieler2
* Kreuze symbolisieren Spieler 1, waehrend Kreise Spieler 2 symbolisieren
*
*  @param spielfeld  Spielfeld, das ausgeben wird
*/
void zeigeSpielfeld(const int spielfeld[GROESSE_Y][GROESSE_X])
{
    std::cout << "   | ";

    //Start bei ASCII 65 = A
    for (int i = 65; i < 65 + GROESSE_X; ++i)
        std::cout << ((char) i) << " | " ;

    std::cout << std::endl;

    for (int j = 0; j < GROESSE_Y; ++j)
    {
        for(int i = 0; i < GROESSE_X; ++i)
        {
            std::cout << "---+";
        }
        std::cout << "---+" << std::endl;

        std::cout << " " << j + 1 << " |";
        for (int i = 0; i < GROESSE_X; ++i)
        {
            switch (spielfeld[j][i])
            {
                case 0:
                    std::cout << "   " ;
                    break;
                case 1:
                    std::cout << " X ";
                    break;
                case 2:
                    std::cout << " O ";
                    break;
                default:
                    std::cout << "Unzulaessige Daten im Spielfeld!" << std::endl;
                    std::cout << "Abbruch .... " << std::endl;
                    exit(0);
                    break;
            }
            std::cout << "|";
        };  //for i
        std::cout <<  std::endl;
    }  //for j
}

/**
 * @brief Prueft, wer Gewinner ist
 *
 * Zaehlt alle Steine auf dem Feld
 *
 * @param spielfeld Aktuelles Spielfeld, fuer das der Gewinner ermittelt wird
 * @return winner
 */
int gewinner(const int spielfeld[GROESSE_Y][GROESSE_X])
{
    int zaehlerSpieler1 = 0;
    int zaehlerSpieler2 = 0;

    for (int j = 0; j < GROESSE_Y; ++j)
    {
        for (int i = 0; i < GROESSE_X; ++i)
        {
            if (spielfeld[j][i] == 1)
            {
                ++zaehlerSpieler1;
            }
            if (spielfeld[j][i] == 2)
            {
                ++zaehlerSpieler2;
            }

        }
    }

    if (zaehlerSpieler1 == zaehlerSpieler2)
    {
        return 0;
    }
    if (zaehlerSpieler1 < zaehlerSpieler2)
    {
        return 2;
    }
    else
    {
        return 1;
    }
}

/**
* @brief Ueberprueft fuer zwei Indizes, ob sie auf dem Spielfeld sind
*
* @param posX Index fuer die Spalte
* @param posY Index fuer die Zeile
* @return true, wenn Spalte und Zeile innerhalb des Spielfelds sind, sonst false
*/
bool aufSpielfeld(const int posX, const int posY)
{
    // Prüfen, ob die Position innerhalb der Grenzen des Spielfelds liegt
    if (posX >= 0 && posX < GROESSE_X && posY >= 0 && posY < GROESSE_Y)
    {
        return true;
    }
    return false;
}


/**
 * @brief Ueberprueft fuer zwei Indizes, ob der Zug gueltig ist
 *
 *  Ueberprueft, ob auf einem benachbarten Feld ein gegnerischer Stein liegt.
 *  Wenn ja, wird diese Richtung solange untersucht, bis ein eigener Stein
 *  gefunden wird. Wird vorher der Spielfeldrand erreicht oder ein leeres Feld
 *  gefunden, wird false zurueckgegeben, sonst true
 *
 * @param spielfeld Das aktuelle Spielfeld
 * @param aktuellerSpieler Der aktuelle Spieler
 * @param posX Zu ueberpruefende Spalte
 * @param posY Zu ueberpruefende Zeile
 * @return true, wenn der Zug gültig ist, sonst false
 */
bool zugGueltig(const int spielfeld[GROESSE_Y][GROESSE_X], const int aktuellerSpieler, const int posX, const int posY)
{
    int gegner;
    if (aktuellerSpieler == 1) 
    {
        gegner = 2;
    }
    else // aktuellerSpieler == 2 olduğunda
    {
        gegner = 1;
    }

    // Prüfen, ob die Position auf dem Spielfeld ist
    if (!aufSpielfeld(posX, posY))
    {
        return false;
    }

    if (spielfeld[posY][posX] != 0) // ist das Feld leer?
    {
        return false;
    }

    // Alle Richtungen ueberpruefen bis erster gueltiger Zug gefunden
    for (int j = -1; j <= 1; j++)
    {
        for (int i = -1; i <= 1; i++)
        {
            // Überspringen, wenn i und j beide 0 sind (das wäre die Position selbst)
            if (i == 0 && j == 0)
            {
                continue;
            }
            
            int currentX = posX + i;
            int currentY = posY + j;
            
            // Prüfen, ob die Nachbarposition auf dem Spielfeld ist und einen gegnerischen Stein enthält
            if (aufSpielfeld(currentX, currentY) && spielfeld[currentY][currentX] == gegner)
            {
                // Wir haben einen gegnerischen Stein gefunden, jetzt in dieser Richtung weitergehen
                int stepX = i;
                int stepY = j;
                currentX += stepX;
                currentY += stepY;
                
                // Solange weitergehen, bis wir nicht mehr auf dem Spielfeld sind oder ein leeres Feld finden
                while (aufSpielfeld(currentX, currentY) && spielfeld[currentY][currentX] != 0)
                {
                    // Wenn wir einen eigenen Stein finden, ist der Zug gültig
                    if (spielfeld[currentY][currentX] == aktuellerSpieler)
                    {
                        return true;
                    }
                    
                    // Weitergehen in die gleiche Richtung
                    currentX += stepX;
                    currentY += stepY;
                }
            }
        }
    }
    return false;
}


/**
 * @brief Funktion, die einen Zug ausfuehrt
 *
 * Diese Funktion setzt einen Stein an die angegebene Position und kehrt alle eingeschlossenen gegnerischen Steine um.
 *
 * @param spielfeld Das aktuelle Spielfeld
 * @param aktuellerSpieler Der aktuelle Spieler
 * @param posX Die aktuelle Spalte
 * @param posY Die aktuelle Zeile
 */
void zugAusfuehren(int spielfeld[GROESSE_Y][GROESSE_X], const int aktuellerSpieler, const int posX, const int posY)
{
    int gegner;
    if (aktuellerSpieler == 1) 
    {
        gegner = 2;
    }
    else // aktuellerSpieler == 2 olduğunda
    {
        gegner = 1;
    }

    // Stein an die angegebene Position setzen
    spielfeld[posY][posX] = aktuellerSpieler;

    //Alle Richtungen bearbeiten
    for (int j = -1; j <= 1; j++)
    {
        for (int i = -1; i <= 1; i++)
        {
            // aehnlich wie die Funktion zugGueltig(), aber stellen Sie sicher, das alle gegnerischen Steine in
            // allen Richtungen in Ihre eigenen Steine umgewandelt werden
            //
            // Hier erfolgt jetzt Ihre Implementierung ...

            // Überspringen, wenn i und j beide 0 sind (das wäre die Position selbst)
            if (i == 0 && j == 0)
            {
                continue;
            }
            
            int currentX = posX + i;
            int currentY = posY + j;
            
            // Prüfen, ob die Nachbarposition auf dem Spielfeld ist und einen gegnerischen Stein enthält
            if (aufSpielfeld(currentX, currentY) && spielfeld[currentY][currentX] == gegner)
            {
                // Speichern der Richtung
                int stepX = i;
                int stepY = j;
                
                // Wir gehen in der Richtung weiter, bis wir entweder das Spielfeld verlassen,
                // ein leeres Feld treffen oder einen eigenen Stein finden
                int nextX = currentX + stepX;
                int nextY = currentY + stepY;
                
                // Temporäre Liste der zu ändernden Positionen
                int umzudrehendePositionenX[GROESSE_X * GROESSE_Y]; // Kann nicht mehr Positionen als das Spielfeld haben
                int umzudrehendePositionenY[GROESSE_X * GROESSE_Y];
                int anzahlUmzudrehendePositionen = 0;
                
                // Erste Position merken
                umzudrehendePositionenX[anzahlUmzudrehendePositionen] = currentX;
                umzudrehendePositionenY[anzahlUmzudrehendePositionen] = currentY;
                anzahlUmzudrehendePositionen++;
                
                bool gueltigeRichtung = false;
                
                // Weitergehen, bis wir nicht mehr auf dem Spielfeld sind oder ein leeres Feld finden
                while (aufSpielfeld(nextX, nextY) && spielfeld[nextY][nextX] != 0)
                {
                    // Wenn wir einen eigenen Stein finden, ist die Richtung gültig
                    if (spielfeld[nextY][nextX] == aktuellerSpieler)
                    {
                        gueltigeRichtung = true;
                        break;
                    }
                    
                    // Position merken
                    umzudrehendePositionenX[anzahlUmzudrehendePositionen] = nextX;
                    umzudrehendePositionenY[anzahlUmzudrehendePositionen] = nextY;
                    anzahlUmzudrehendePositionen++;
                    
                    // Weitergehen in die gleiche Richtung
                    nextX += stepX;
                    nextY += stepY;
                }
                
                // Wenn die Richtung gültig ist, drehen wir alle Steine um
                if (gueltigeRichtung)
                {
                    for (int k = 0; k < anzahlUmzudrehendePositionen; k++)
                    {
                        spielfeld[umzudrehendePositionenY[k]][umzudrehendePositionenX[k]] = aktuellerSpieler;
                    }
                }
            }
        }
    }
}

/**
 * @brief Berechnet die Anzahl der möglichen Züge für einen Spieler
 *
 * Durchläuft das gesamte Spielfeld und prüft für jede leere Position, 
 * ob ein gültiger Zug für den angegebenen Spieler möglich ist.
 *
 * @param spielfeld Das aktuelle Spielfeld
 * @param aktuellerSpieler Der Spieler, für den die möglichen Züge gezählt werden sollen
 * @return Anzahl der möglichen Züge
 */
int moeglicheZuege(const int spielfeld[GROESSE_Y][GROESSE_X], const int aktuellerSpieler)
{
    int anzahlZuege = 0;
    
    // Durchlaufen des gesamten Spielfelds
    for (int y = 0; y < GROESSE_Y; y++)
    {
        for (int x = 0; x < GROESSE_X; x++)
        {
            // Prüfen, ob an dieser Position ein gültiger Zug möglich ist
            if (zugGueltig(spielfeld, aktuellerSpieler, x, y))
            {
                anzahlZuege++;
            }
        }
    }
    
    return anzahlZuege;
}


bool menschlicherZug(int spielfeld[GROESSE_Y][GROESSE_X], const int aktuellerSpieler)
{
    if (moeglicheZuege(spielfeld, aktuellerSpieler) == 0)
    {
        return false;
    }

    int posX;
    int posY;
    std::string symbolSpieler;
    if (aktuellerSpieler == 1)
    {
        symbolSpieler = "X";
    }
    else
    {
        symbolSpieler = "O";
    }

    while (true)
    {
        std::string eingabe;
        std::cout << std::endl << "Du bist " << symbolSpieler << ". Dein Zug (z.B. A1, a1): " ;
        std::cin >> eingabe;
        posX = (int) eingabe[0] % 32 -1;
        posY = (int) eingabe[1] - 49;

        if (zugGueltig(spielfeld, aktuellerSpieler, posX, posY))
        {
            //accept turn;
            break;
        }
        else
        {
            std::cout << std::endl << "Ungueltige Eingabe !" << std::endl;
        }
    }

    zugAusfuehren(spielfeld, aktuellerSpieler, posX, posY);
    std::cout << std::endl << "Spieler " << aktuellerSpieler << " setzt auf " << (char) (posX + 65) << (posY + 1) << std::endl;

    return true;
}


void spielen(const int spielerTyp[2])
{
    int spielfeld[GROESSE_Y][GROESSE_X];

    //Erzeuge Startaufstellung
    initialisiereSpielfeld(spielfeld);

    int aktuellerSpieler = 1;
    zeigeSpielfeld(spielfeld);

    // solange noch Zuege bei einem der beiden Spieler moeglich sind
    bool spielerKannZiehen[2] = {true, true}; // Index 0 für Spieler 1, Index 1 für Spieler 2
    bool spielLaeuft = true;
    
    while (spielLaeuft)
    {
        std::cout << std::endl << "Spieler " << aktuellerSpieler << " ist am Zug." << std::endl;
        
        // Prüfen, ob der aktuelle Spieler einen Zug machen kann
        if (moeglicheZuege(spielfeld, aktuellerSpieler) == 0)
        {
            std::cout << "Spieler " << aktuellerSpieler << " kann keinen Zug machen und muss aussetzen." << std::endl;
            spielerKannZiehen[aktuellerSpieler - 1] = false;
            // aktueller Spieler kann nicht mehr ziehen, da er keinen Zug machen kann! Das wird in der nächsten Schleife überprüft
            // Wenn beide Spieler keinen Zug machen können, endet das Spiel
        }
        else
        {
            // Zug ausführen je nach Spielertyp
            bool zugErfolgreich = false;
            
            if (spielerTyp[aktuellerSpieler - 1] == MENSCH)
            {
                zugErfolgreich = menschlicherZug(spielfeld, aktuellerSpieler);
            }
            else // COMPUTER, Künstliche Intelligenz, die uns bereitgestellt wurde
            {
                zugErfolgreich = computerZug(spielfeld, aktuellerSpieler);
            }
            
            if (zugErfolgreich)
            {
                spielerKannZiehen[aktuellerSpieler - 1] = true;
                zeigeSpielfeld(spielfeld);
            }
        }
        
        // Spielerwechsel
        aktuellerSpieler = (aktuellerSpieler == 1) ? 2 : 1;
        
        // Prüfen, ob das Spiel beendet ist (beide Spieler können nicht mehr ziehen)
        if (!spielerKannZiehen[0] && !spielerKannZiehen[1])
        {
            spielLaeuft = false;
        }
    }
    
    // Gewinner ermitteln und ausgeben
    switch (gewinner(spielfeld))
    {
        case 0:
            std::cout << std::endl << "Das Spiel endet unentschieden!" << std::endl;
            break;
        case 1:
            std::cout << std::endl << "Spieler 1 gewinnt das Spiel!" << std::endl;
            break;
        case 2:
            std::cout << std::endl << "Spieler 2 gewinnt das Spiel!" << std::endl;
            break;
    }
}

int main()
{
    if (TEST == 1)
    {
        bool gesamtErgebnis = ganzenTestAusfuehren();
        if (gesamtErgebnis == true)
        {
            std::cout << "ALLE TESTS BESTANDEN!" << std::endl;
        }
        else
        {
            std::cout << "MINDESTENS EIN TEST IST FEHLGESCHLAGEN!" << std::endl;
            exit(1);
        }
        std::cout << std::endl << std::endl;
    }
    
    // Die folgenden drei Zeilen werden auskommentiert oder geloescht, nachdem Sie die Funktion spielen()
    // implementiert haben (waeren sonst doppelt)
    // int spielfeld[GROESSE_Y][GROESSE_X];

    // initialisiereSpielfeld(spielfeld);

    // zeigeSpielfeld(spielfeld);

    // int spielerTyp[2] = { COMPUTER, COMPUTER };  // Feld, das Informationen ueber den Typ des Spielers enthaelt. MENSCH(=1) oder COPMUTER(=2)
    // spielen(spielerTyp);
    //
    // Hier erfolgt jetzt Ihre Implementierung ...

    // Spielermodus wählen
    int spielerTyp[2] = { MENSCH, MENSCH };  // Standardeinstellung: zwei menschliche Spieler
    
    char auswahl;
    std::cout << "Willkommen zu Othello!" << std::endl;
    std::cout << "Wählen Sie den Spielmodus:" << std::endl;
    std::cout << "1: Mensch gegen Mensch" << std::endl;
    std::cout << "2: Mensch gegen Computer" << std::endl;
    std::cout << "3: Computer gegen Mensch" << std::endl;
    std::cout << "4: Computer gegen Computer" << std::endl;
    std::cout << "Ihre Wahl: ";
    std::cin >> auswahl;
    
    switch (auswahl)
    {
        case '1':
            spielerTyp[0] = MENSCH;
            spielerTyp[1] = MENSCH;
            break;
        case '2':
            spielerTyp[0] = MENSCH;
            spielerTyp[1] = COMPUTER;
            break;
        case '3':
            spielerTyp[0] = COMPUTER;
            spielerTyp[1] = MENSCH;
            break;
        case '4':
            spielerTyp[0] = COMPUTER;
            spielerTyp[1] = COMPUTER;
            break;
        default:
            std::cout << "Ungültige Eingabe. Es wird Mensch gegen Mensch gespielt." << std::endl;
            spielerTyp[0] = MENSCH;
            spielerTyp[1] = MENSCH;
    }
    
    // Spiel starten
    spielen(spielerTyp);
    
    return 0;
}
