/**
 * Praktikum Informatik 1 
 * 
 *
 * @file othelloKI.cpp
 *
 * Stellt eine KI fuer das Spiel Othello zur Verfuegung
 */

#include "othelloKI.h"
#include <iostream>


extern int moeglicheZuege(const int spielfeld[GROESSE_Y][GROESSE_X], const int aktuellerSpieler);
extern void zugAusfuehren(int spielfeld[GROESSE_Y][GROESSE_X], const int aktuellerSpieler, const int posX, const int posY);
extern bool zugGueltig(const int spielfeld[GROESSE_Y][GROESSE_X], const int aktuellerSpieler, const int posX, const int posY);

bool computerZug(int spielfeld[GROESSE_Y][GROESSE_X], const int aktuellerSpieler)
{
    if (moeglicheZuege(spielfeld,aktuellerSpieler) == 0)
    {
        return false;
    }
    int voraussehen[GROESSE_Y][GROESSE_X];
    int min_x = 0;
    int min_y = 0;
    int min = GROESSE_X * GROESSE_Y;

    for (int j = 0 ; j < GROESSE_Y; j++)
    {
        for (int i = 0; i < GROESSE_X; i++)
        {
            // Spielfeld zuruecksetzen
            for (int cj = 0; cj < GROESSE_Y; cj++)
            {
                for (int ci = 0; ci < GROESSE_X; ci++)
                {
                    voraussehen[cj][ci]=spielfeld[cj][ci];
                }
            }

            if (zugGueltig(voraussehen, aktuellerSpieler, i, j))
            {
                zugAusfuehren(voraussehen, aktuellerSpieler, i, j);
                if (moeglicheZuege(voraussehen, 3 - aktuellerSpieler) < min)
                {
                    min=moeglicheZuege(voraussehen, 3 - aktuellerSpieler);
                    min_x = i;
                    min_y = j;
                }
            }
        }
    }

    zugAusfuehren(spielfeld, aktuellerSpieler, min_x, min_y);
    std::cout << std::endl << "Spieler " << aktuellerSpieler << " setzt auf " << (char) (min_x + 65) << (min_y + 1) << std::endl;

    return true;
}


// computerZug fonksiyonu, bilgisayarın hamle yapmasını sağlar. İki parametre alır:
// spielfeld: Oyun tahtası
// aktuellerSpieler: Mevcut oyuncu (1 veya 2)
// İlk olarak, mevcut oyuncu için olası hamle olup olmadığını kontrol eder. Eğer hamle yoksa, false döndürür.
// Eğer hamle varsa, bilgisayar en iyi hamleyi bulmaya çalışır. Buradaki strateji, rakibe en az sayıda hamle bırakacak hamleyi seçmektir.
// Algoritma şöyle çalışır:
// Tüm tahtayı tarar
// Her geçerli hamle için:
// Hamleyi geçici bir tahtada simüle eder
// Bu hamleden sonra rakibin kaç hamle yapabileceğini hesaplar
// Rakibe en az hamle bırakan hamleyi seçer
// En iyi hamle bulunduktan sonra, bu hamleyi gerçek oyun tahtasında uygular ve ekrana hangi hamlenin yapıldığını yazdırır.
// Başarılı bir hamle yapıldığı için true döndürür.
// Bu, "minimax" algoritmasının basit bir versiyonudur ve sadece bir hamle ileriye bakar. Daha gelişmiş bir AI, birkaç hamle ileriye bakabilir ve her hamlenin değerini daha karmaşık bir şekilde hesaplayabilir.

