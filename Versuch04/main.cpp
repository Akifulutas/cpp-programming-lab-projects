//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIV
// Versuch 04: Einführung Klasse
//
// Datei:  main.cpp
// Inhalt: Hauptprogramm zur Demonstration der Vektor-Klasse
//////////////////////////////////////////////////////////////////////////////

#include "Vektor.h"
#include <iostream>
#include <iomanip>
#include <cmath>

/**
 * @brief Start des Programms
 *
 * In dieser Funktion wird gezeigt, was man mit der Klasse `Vektor` machen kann:
 * - Vektoren anzeigen
 * - Länge von einem Vektor berechnen
 * - Vektoren voneinander abziehen
 * - Skalarprodukt berechnen
 * - Winkel zwischen Vektoren berechnen
 * - Einen Vektor um die Z-Achse drehen
 * - Sichtweite eines Menschen wegen der Erdkrümmung berechnen
 *
 * @return 0, wenn alles gut ist
 */
int main()
{
    // Wir machen ein paar Test-Vektoren
    Vektor vector1(1, 0, 0);
    Vektor vector2(0, 1, 0);
    Vektor vector3(1, 2, 3);
    Vektor vector4(4, 5, 6);

    // Zeige die Vektoren
    std::cout << "Vektor 1:" << std::endl;
    vector1.ausgabe();
    
    std::cout << "Vektor 2:" << std::endl;
    vector2.ausgabe();
    
    std::cout << "Vektor 3:" << std::endl;
    vector3.ausgabe();
    
    std::cout << "Vektor 4:" << std::endl;
    vector4.ausgabe();

    // Länge der Vektoren berechnen
    std::cout << std::fixed << std::setprecision(4);
    std::cout << "Laenge von Vektor 1: " << vector1.laenge() << std::endl;
    std::cout << "Laenge von Vektor 3: " << vector3.laenge() << std::endl;
    std::cout << std::endl;

    // Vektoren voneinander abziehen
    std::cout << "Vektor 4 - Vektor 3:" << std::endl;
    Vektor subtractResult = vector4.sub(vector3);
    subtractResult.ausgabe();

    // Skalarprodukt berechnen
    std::cout << "Skalarprodukt von Vektor 3 und Vektor 4: " 
              << vector3.skalarProd(vector4) << std::endl;
    std::cout << "Skalarprodukt von Vektor 1 und Vektor 2: " 
              << vector1.skalarProd(vector2) << std::endl;
    std::cout << std::endl;

    // Winkel zwischen Vektoren berechnen
    std::cout << "Winkel zwischen Vektor 1 und Vektor 2: " 
              << vector1.winkel(vector2) << " Grad" << std::endl;
    std::cout << "Winkel zwischen Vektor 3 und Vektor 4: " 
              << vector3.winkel(vector4) << " Grad" << std::endl;
    std::cout << std::endl;

    // Vektor um Z-Achse drehen
    std::cout << "Vektor 1 vor Rotation:" << std::endl;
    vector1.ausgabe();
    
    std::cout << "Vektor 1 nach Drehung um 90 Grad:" << std::endl;
    vector1.rotiereUmZ(M_PI/2);
    vector1.ausgabe();
    
    std::cout << "Vektor 1 nach weiterer Drehung um 90 Grad (insgesamt 180 Grad):" << std::endl;
    vector1.rotiereUmZ(M_PI/2);
    vector1.ausgabe();

    // ------------------------------------------------------------------------------
    // Sichtweite wegen Erdkrümmung berechnen
    // ------------------------------------------------------------------------------

    /// @brief Radius der Erde in km
    const double erdRadius = 6371.0;

    /// @brief Größe einer Person in Meter
    const double koerperGroesse = 1.70;

    /// @brief Höhe von der Plattform in Meter
    const double plattformHoehe = 555.7;

    /// @brief Gesamte Höhe des Beobachters in km
    const double gesamtHoehe = (plattformHoehe + koerperGroesse) / 1000.0;

    /// @brief Zählt die Schritte bei der Suche
    int anzahlSchritte = 0;

    /// @brief Ort des Beobachters als Vektor
    Vektor beobachter(erdRadius + gesamtHoehe, 0.0, 0.0);

    /// @brief Startwinkel in Grad
    const double startWinkel = 0.0;

    /// @brief Endwinkel in Grad
    const double endWinkel = 5.0;

    /// @brief Wie groß die Schritte beim Testen sind
    const double schrittGroesse = 0.000001;

    double beta = 0.0;
    Vektor resultVector(0,0,0);

    // Wir testen viele Winkel, bis wir einen passenden finden
    for (double testWinkel = startWinkel; testWinkel <= endWinkel; testWinkel += schrittGroesse)
    {
        anzahlSchritte++;
        double winkelRad = testWinkel * M_PI / 180.0;

        Vektor punktAufErde(erdRadius, 0.0, 0.0);
        punktAufErde.rotiereUmZ(winkelRad);

        Vektor sichtlinie = beobachter.sub(punktAufErde);
        double winkel = punktAufErde.winkel(sichtlinie);
        double abweichung = std::abs(winkel - 90.0);

        beta = testWinkel;
        resultVector = sichtlinie;

        if (abweichung < 0.000001)
        {
            break; // wir haben die beste Lösung gefunden
        }
    }

    // Ergebnis berechnen
    double distanz = beta * M_PI / 180.0 * erdRadius;
    double distanz2 = resultVector.laenge();

    // Ergebnis anzeigen
    std::cout << std::fixed << std::setprecision(4) << std::endl;
    std::cout << "Ergebnisse:" << std::endl;
    std::cout << "Sie koennen " << distanz << " Km weit sehen. (Erdkruemmung)" << std::endl;
    std::cout << "Sie koennen " << distanz2 << " Km weit sehen. (direkte Linie)" << std::endl;
    std::cout << "Sie sind " << (plattformHoehe + koerperGroesse) << " Meter hoch." << std::endl;
    std::cout << "Der Winkel betraegt " << beta << " Grad." << std::endl;
    std::cout << "Anzahl Schritte: " << anzahlSchritte << std::endl;

    return 0;
}
