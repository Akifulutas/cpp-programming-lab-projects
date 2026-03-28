///////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXV
// Versuch 9
//////////////////////////////////////////////////////////////////////////////
#ifndef DIALOGADDCITY_H
#define DIALOGADDCITY_H

#include <QDialog>

// Qt-Boilerplate für die Verknüpfung mit der .ui-Datei
QT_BEGIN_NAMESPACE
namespace Ui { class DialogAddCity; }
QT_END_NAMESPACE

/**
 * @class DialogAddCity
 * @brief Definiert das Pop-up-Fenster zur Eingabe der Daten für eine neue Stadt.
 */
class DialogAddCity : public QDialog
{
    Q_OBJECT // Notwendig für Qt's Signal & Slot Funktionalität

public:
    // Konstruktor: Initialisiert das Fenster und seine UI-Elemente.
    explicit DialogAddCity(QWidget *parent = nullptr);

    // Destruktor: Gibt den Speicher der UI-Elemente frei.
    ~DialogAddCity();

    // --- Getter-Funktionen ---
    // Damit kann das Hauptfenster die eingegebenen Daten nach dem Klick auf "OK" auslesen.
    QString getCityName() const;
    int getX() const;
    int getY() const;

public slots:
    /**
     * @brief Überschreibt die Standard-accept()-Methode (der "OK"-Button).
     * Wird genutzt, um die Eingaben des Benutzers zu validieren, bevor der Dialog geschlossen wird.
     */
    void accept() override;

private:
    // Zeiger auf die automatisch generierte UI-Klasse aus "DialogAddCity.ui".
    // Bietet Zugriff auf alle UI-Elemente (LineEdit, Buttons etc.).
    Ui::DialogAddCity *ui;
};
#endif // DIALOGADDCITY_H
