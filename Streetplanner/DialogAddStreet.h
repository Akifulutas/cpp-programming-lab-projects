///////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXV
// Versuch 9
//////////////////////////////////////////////////////////////////////////////
#ifndef DIALOGADDSTREET_H
#define DIALOGADDSTREET_H

#include <QDialog>
#include "map.h"

// Standard Qt-Code für die .ui-Datei Anbindung.
QT_BEGIN_NAMESPACE
namespace Ui { class DialogAddStreet; }
QT_END_NAMESPACE

/**
 * @class DialogAddStreet
 * @brief Definiert das Pop-up-Fenster zum Hinzufügen einer Straße zwischen zwei Städten.
 */
class DialogAddStreet : public QDialog
{
    Q_OBJECT // Notwendig für Qt's Signal & Slot Funktionalität.

public:
    /**
     * @brief Konstruktor, der eine Referenz auf die Karte entgegennimmt.
     * @param map Die Referenz wird genutzt, um die Dropdown-Menüs (ComboBoxen) mit den
     * aktuell verfügbaren Städten zu füllen.
     * @param parent Das übliche Eltern-Widget.
     */
    explicit DialogAddStreet(Map& map, QWidget *parent = nullptr);

    // Destruktor: Räumt die UI-Ressourcen auf.
    ~DialogAddStreet();

    // --- Getter-Funktionen ---
    // Geben die Namen der zwei vom Benutzer ausgewählten Städte zurück.
    QString getCity1Name() const;
    QString getCity2Name() const;

private:
    // Zeiger auf die UI-Klasse, die Zugriff auf die Elemente der .ui-Datei bietet,
    // insbesondere auf die beiden ComboBoxen für die Stadtauswahl.
    Ui::DialogAddStreet *ui;
};

#endif // DIALOGADDSTREET_H
