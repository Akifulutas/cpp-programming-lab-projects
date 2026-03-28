/**
 * Praktikum Informatik 1 MMXXV
 *
 * @file config.h
 *
 * Enthält Einstellungen für das ganze Programm.
 */

#ifndef CONFIG_H_
#define CONFIG_H_


/** Anzahl der Spalten im Spielfeld */
const int GROESSE_X = 8;

/** Anzahl der Zeilen im Spielfeld */
const int GROESSE_Y = 8;

/** Sollen die Tests gemacht werden? 1 = Ja, 0 = Nein */
const int TEST = 1;

/** Sollen die Test-Ausgaben genau gezeigt werden? */
const int AUSFUEHRLICH = 1;

/** Art von Spieler: Mensch oder Computer */
const int MENSCH = 1;
const int COMPUTER = 2;

#endif /* CONFIG_H_ */
