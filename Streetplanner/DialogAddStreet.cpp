///////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXV
// Versuch 9
//////////////////////////////////////////////////////////////////////////////
#include "DialogAddStreet.h"
#include "ui_DialogAddStreet.h" // UI-Definitionen
#include "city.h"               // Nötig für den Umgang mit City-Objekten

/**
 * @brief Konstruktor für den Dialog zum Hinzufügen einer Straße.
 * @param map Referenz auf das Haupt-Map-Objekt, um die Städteliste zu erhalten.
 * @param parent Eltern-Widget für die Speicherverwaltung.
 */
DialogAddStreet::DialogAddStreet(Map& map, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAddStreet)
{
    // 1. Standard-UI-Setup durchführen.
    ui->setupUi(this);
    this->setWindowTitle("Straße hinzufügen");

    // 2. Eine Liste aller existierenden Städte von der Karte abfragen.
    QVector<City*> cities = map.getCities();

    // 3. Schleife durch alle Städte...
    for (City* city : cities) {
        // ...und füge den Namen jeder Stadt zu beiden Dropdown-Menüs hinzu.
        ui->comboBox_city1->addItem(city->getName());
        ui->comboBox_city2->addItem(city->getName());
    }
}

/**
 * @brief Destruktor.
 */
DialogAddStreet::~DialogAddStreet()
{
    // Gibt den Speicher für die UI frei.
    delete ui;
}


// --- Getter-Implementierungen ---
// Geben den Text des aktuell vom Benutzer ausgewählten Eintrags in der jeweiligen ComboBox zurück.

QString DialogAddStreet::getCity1Name() const
{
    return ui->comboBox_city1->currentText();
}

QString DialogAddStreet::getCity2Name() const
{
    return ui->comboBox_city2->currentText();
}
