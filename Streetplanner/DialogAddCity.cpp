///////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXV
// Versuch 9
//////////////////////////////////////////////////////////////////////////////
#include "DialogAddCity.h"
#include "ui_DialogAddCity.h" // Automatisch generierte Header-Datei, die die UI-Definitionen enthält.
#include <QMessageBox>       // Für das Anzeigen von Warnhinweisen.

/**
 * @brief Konstruktor für den Dialog.
 */
DialogAddCity::DialogAddCity(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAddCity) // Erstellt das Objekt, das die UI-Elemente verwaltet.
{
    // 1. Initialisiert die UI-Elemente (Buttons, LineEdits etc.) aus der .ui-Datei im Fenster.
    ui->setupUi(this);
    // 2. Setzt den Titel des Dialogfensters.
    this->setWindowTitle("Stadt hinzufügen");
}

/**
 * @brief Destruktor.
 */
DialogAddCity::~DialogAddCity()
{
    // Gibt den Speicher frei, der für das ui-Objekt mit 'new' reserviert wurde.
    // Verhindert Speicherlecks.
    delete ui;
}

// --- Getter-Implementierungen ---
// Lesen die aktuellen Werte aus den Eingabefeldern der UI aus.

QString DialogAddCity::getCityName() const
{
    return ui->lineEdit_name->text();
}

int DialogAddCity::getX() const
{
    return ui->lineEdit_x->text().toInt();
}

int DialogAddCity::getY() const
{
    return ui->lineEdit_y->text().toInt();
}

/**
 * @brief Überschreibt die accept()-Funktion, die beim Klick auf "OK" aufgerufen wird.
 * Führt eine Serie von Validierungsprüfungen durch, bevor der Dialog geschlossen wird.
 */
void DialogAddCity::accept() {
    // Holt die aktuellen Eingaben aus den Feldern.
    QString name = ui->lineEdit_name->text();
    QString xStr = ui->lineEdit_x->text();
    QString yStr = ui->lineEdit_y->text();

    // Validierung 1: Sind alle Felder ausgefüllt?
    if (name.isEmpty() || xStr.isEmpty() || yStr.isEmpty()) {
        QMessageBox::warning(this, "Fehlerhafte Eingabe", "Bitte füllen Sie alle Felder aus.");
        return; // -> return bricht die Funktion hier ab, der Dialog bleibt offen.
    }

    // Validierung 2: Sind die Koordinaten gültige Zahlen?
    bool xOk, yOk;
    xStr.toInt(&xOk);
    yStr.toInt(&yOk);
    if (!xOk || !yOk) {
        QMessageBox::warning(this, "Fehlerhafte Eingabe", "Die Koordinaten dürfen nur Zahlen enthalten.");
        return; // -> Abbruch, Dialog bleibt offen.
    }

    // Validierung 3: Enthält der Stadtname nur Buchstaben und Leerzeichen?
    for (char c : name.toStdString()) { // Konvertierung zu std::string für einfache Iteration
        if (!std::isalpha(c) && c != ' ') {
            QMessageBox::warning(this, "Fehlerhafte Eingabe", "Der Stadtname darf nur Buchstaben und Leerzeichen enthalten.");
            return; // -> Abbruch, Dialog bleibt offen.
        }
    }

    // Wenn alle Prüfungen bestanden wurden, rufe die ursprüngliche QDialog::accept() auf.
    // DIESER Aufruf schließt den Dialog und gibt das Signal "accepted" zurück.
    QDialog::accept();
}
