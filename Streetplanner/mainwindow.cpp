///////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXV
// Versuch 9
//////////////////////////////////////////////////////////////////////////////
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "city.h"
#include "street.h"
#include "mapionrw.h"
#include "dijkstra.h"
#include "DialogAddCity.h"
#include "DialogAddStreet.h"
#include <QDebug>
#include <QMessageBox>
#include <QRandomGenerator>

/**
 * @brief Konstruktor: Initialisiert das Hauptfenster.
 */
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , mapIo(nullptr)
{
    // 1. UI-Elemente aus der .ui-Datei erstellen.
    ui->setupUi(this);
    // 2. Die Zeichenfläche (scene) mit dem Anzeige-Widget (graphicsView) verbinden.
    ui->graphicsView->setScene(&scene);
    // 3. Das Objekt zum Laden der festen Kartendaten (NRW) erstellen.
    mapIo = new MapIoNrw();
}

/**
 * @brief Destruktor: Gibt belegten Speicher frei.
 */
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_checkBox_clicked()
{
    // Prüfen, ob die Checkbox angehakt ist
    bool checked = ui->checkBox->isChecked();

    if (checked)
    {
        // Alle Test-Buttons sichtbar machen
        ui->lineEdit_teste_was->hide();
        ui->pushButton_teste_was->hide();
        ui->pushButton_testDrawCity->hide();
        ui->pushButton_testDrawStreet->hide();
        ui->pushButton_testAddStreet->hide();
        ui->pushButton_testMapWithStreets->hide();
        ui->pushButton_testAbstractMap->hide();
        ui->pushButton_testDijkstra->hide();
        ui->label_2->hide();
        ui->label_3->hide();
        ui->comboBox_StartCity->hide();
        ui->comboBox_TargetCity->hide();

    }
    else
    {
        // Alle Test-Buttons unsichtbar machen
        ui->lineEdit_teste_was->show();
        ui->pushButton_teste_was->show();
        ui->pushButton_testDrawCity->show();
        ui->pushButton_testDrawStreet->show();
        ui->pushButton_testAddStreet->show();
        ui->pushButton_testMapWithStreets->show();
        ui->pushButton_testAbstractMap->show();
        ui->pushButton_testDijkstra->show();
        ui->label_2->show();
        ui->label_3->show();
        ui->comboBox_StartCity->show();
        ui->comboBox_TargetCity->show();

    }
}

/**
 * @brief Slot für einen allgemeinen Test-Button.
 */
void MainWindow::on_pushButton_teste_was_clicked()
{
    QString userInput = ui->lineEdit_teste_was->text();
    qDebug() << "Benutzereingabe:" << userInput;

    // Prüfen, ob die Eingabe eine Zahl ist und eine entsprechende Nachricht anzeigen.
    bool isNumber;
    int number = userInput.toInt(&isNumber);
    QMessageBox msgBox;
    if (isNumber) {
        msgBox.setText(QString("Die Zahl + 4 ist: %1").arg(number + 4));
    } else {
        msgBox.setText("Die Eingabe war keine gültige Zahl.");
    }
    msgBox.exec();

    // Ein zufälliges Rechteck auf die Szene zeichnen.
    int x = QRandomGenerator::global()->bounded(500);
    int y = QRandomGenerator::global()->bounded(500);
    scene.addRect(x, y, 50, 50);
}

/**
 * @brief Leert die gesamte Zeichenfläche.
 */
void MainWindow::on_actionClear_Scene_triggered()
{
    scene.clear();
}

/**
 * @brief Zeigt ein "Über"-Fenster mit Programminformationen.
 */
void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::about(this, "Über Streetplanner", "Erstellt im Praktikum Informatik 1.");
}

/**
 * @brief Test-Funktion, die zwei Städte erstellt, zur Karte hinzufügt und die Karte zeichnet.
 */
void MainWindow::on_pushButton_testDrawCity_clicked()
{
    // Städte mit "new" auf dem Heap erstellen, damit sie nicht am Funktionsende zerstört werden.
    City* aachen = new City("Aachen", 50, 100);
    City* koeln = new City("Köln", 250, 150);

    // Städte zur Karte hinzufügen und die Szene neu zeichnen.
    map.addCity(aachen);
    map.addCity(koeln);
    scene.clear();
    map.draw(scene);
}

/**
 * @brief Veraltete Test-Funktion, die eine Straße direkt zeichnet, ohne die Map-Klasse zu nutzen.
 */
void MainWindow::on_pushButton_testDrawStreet_clicked()
{
    City* stadt1 = new City("Stadt 1", 30, 400);
    City* stadt2 = new City("Stadt 2", 400, 450);
    Street strasse(stadt1, stadt2);

    // Zeichnet die Elemente direkt auf die Szene.
    stadt1->draw(scene);
    stadt2->draw(scene);
    strasse.draw(scene);
}

void MainWindow::on_pushButton_testAddStreet_clicked()
{
    // Test-Map anlegen
    Map testMap;

    // 1) Straße hinzufügen, bevor Städte in der Map sind → muss false liefern
    City* a = new City("A", 0, 0);
    City* b = new City("B", 10, 10);
    Street* s1 = new Street(a, b);

    qDebug() << "Test AddStreet: Ohne Städte in der Map";
    bool added1 = testMap.addStreet(s1);
    qDebug() << "  Erwartet: false, Tatsächlich:" << added1;

    // 2) Jetzt Städte hinzufügen und die selbe Straße anlegen → muss true liefern
    testMap.addCity(a);
    testMap.addCity(b);

    qDebug() << "Test AddStreet: Mit beiden Städten in der Map";
    bool added2 = testMap.addStreet(s1);
    qDebug() << "  Erwartet: true, Tatsächlich:" << added2;

    // (Optional) Szene leeren und Map zeichnen, um sichtbar zu machen, dass s1 jetzt drin ist
    scene.clear();
    testMap.draw(scene);
}
/**
 * @brief Testet die Logik von `map.addStreet()`.
 * Eine Straße sollte hinzugefügt werden, die andere nicht (da eine Stadt fehlt).
 */
void MainWindow::on_pushButton_testMapWithStreets_clicked()
{
    map = Map(); // Karte zurücksetzen

    City* aachen = new City("Aachen", 50, 100);
    City* koeln = new City("Köln", 250, 150);
    City* duesseldorf = new City("Düsseldorf", 280, 50); // Wird absichtlich NICHT zur Karte hinzugefügt

    map.addCity(aachen);
    map.addCity(koeln);

    Street* s1 = new Street(aachen, koeln);
    Street* s2 = new Street(koeln, duesseldorf); // Düsseldorf ist nicht in der Karte -> Fehler erwartet

    // Straßen hinzufügen und das Ergebnis prüfen.
    qDebug() << "Straße Aachen-Köln hinzugefügt:" << map.addStreet(s1); // Erwartet: true
    qDebug() << "Straße Köln-Düsseldorf hinzugefügt:" << map.addStreet(s2); // Erwartet: false

    scene.clear();
    map.draw(scene);
}
/**
 * @brief Eine private Funktion, die eine Reihe von Tests für die Map-Klasse ausführt.
 * Prüft, ob die Methoden wie erwartet funktionieren.
 */
void MainWindow::testAbstractMap()
{
    Map testMap;
    City *a = new City("a", 0, 0);
    City *b = new City("b", 0, 100);
    City *c = new City("c", 100, 300);
    Street *s = new Street(a, b);
    Street *s2 = new Street(b, c);

    qDebug() << "MapTest: Start Test of the Map";
    {
        qDebug() << "MapTest: adding wrong street";
        bool t1 = testMap.addStreet(s);
        if (t1) {
            qDebug() << "-Error: Street should not be added, if cities have not been added.";
        }
    }

    {
        qDebug() << "MapTest: adding correct street";
        testMap.addCity(a);
        testMap.addCity(b);
        bool t1 = testMap.addStreet(s);
        if (!t1) {
            qDebug() << "-Error: It should be possible to add this street.";
        }
    }

    {
        qDebug() << "MapTest: findCity";
        City* city = testMap.findCity("a");
        if (city != a)
            qDebug() << "-Error: City a could not be found.";

        city = testMap.findCity("b");
        if (city != b)
            qDebug() << "-Error: City b could not be found.";

        city = testMap.findCity("c");
        if (city != nullptr)
            qDebug() << "-Error: If city could not be found 0 should be returned.";
    }

    testMap.addCity(c);
    testMap.addStreet(s2);

    {
        qDebug() << "MapTest: getOppositeCity";
        const City *city = testMap.getOppositeCity(s, a);
        if (city != b)
            qDebug() << "-Error: Opposite city should be b.";

        city = testMap.getOppositeCity(s, c);
        if (city != nullptr)
            qDebug() << "-Error: Opposite city for a city which is not linked by given street should be 0.";
    }

    {
        qDebug() << "MapTest: streetLength";
        double l = testMap.getLength(s2);
        double expectedLength = 223.6;
        // compare doubles with 5% tolerance
        if (l < expectedLength * 0.95 || l > expectedLength * 1.05)
            qDebug() << "-Error: Street Length is not equal to the expected.";
    }

    {
        qDebug() << "MapTest: getStreetList";
        QVector<Street*> streetList1 = testMap.getStreetList(a);
        QVector<Street*> streetList2 = testMap.getStreetList(b);
        if (streetList1.size() != 1) {
            qDebug() << "-Error: One street should be found for city a.";
        }
        else if (*streetList1.begin() != s) {
            qDebug() << "-Error: The wrong street has been found for city a.";
        }

        if (streetList2.size() != 2)
            qDebug() << "-Error: Two streets should be found for city b.";
    }

    qDebug() << "MapTest: End Test of the Map.";

    scene.clear();
    testMap.draw(scene);

    // Benutzer informieren
    QMessageBox::information(
        this,
        tr("MapTest"),
        tr("AbstractMap-Tests abgeschlossen.\n"
           "Ergebnis wurde in der Szene gezeichnet und ins Debug-Protokoll ausgegeben.")
        );
}
/**
 * @brief Ruft die private Testfunktion für die Map-Methoden auf.
 */
void MainWindow::on_pushButton_testAbstractMap_clicked()
{
    testAbstractMap();
}

void MainWindow::on_pushButton_testDijkstra_clicked()
{
    // 1. Eingabe aus den beiden QLineEdits holen
    QString startCityName  = ui->comboBox_StartCity->currentText().trimmed();
    QString targetCityName = ui->comboBox_TargetCity->currentText().trimmed();

    // 2. Validierung: Felder nicht leer
    if (startCityName.isEmpty() || targetCityName.isEmpty()) {
        QMessageBox::warning(
            this,
            tr("Fehlerhafte Eingabe"),
            tr("Bitte geben Sie sowohl Start- als auch Zielstadt ein.")
            );
        return;
    }

    // 3. Validierung: Start ≠ Ziel
    if (startCityName == targetCityName) {
        QMessageBox::warning(
            this,
            tr("Fehlerhafte Eingabe"),
            tr("Start- und Zielstadt müssen unterschiedlich sein.")
            );
        return;
    }

    // 5. Dijkstra-Algorithmus aufrufen
    QVector<Street*> shortestPath =  Dijkstra::search(map, startCityName, targetCityName);

    // 6. Ergebnis auswerten und Wege rot zeichnen
    if (!shortestPath.isEmpty()) {
        for (Street* street : shortestPath) {
            street->drawRed(scene);
        }
        QMessageBox::information(
            this,
            tr("Weg gefunden"),
            tr("Kürzester Weg von %1 nach %2 wurde hervorgehoben.")
                .arg(startCityName, targetCityName)
            );
    } else {
        QMessageBox::information(
            this,
            tr("Kein Weg gefunden"),
            tr("Zwischen %1 und %2 existiert kein Pfad.")
                .arg(startCityName, targetCityName)
            );
    }
}

/**
 * @brief Füllt die Karte mit den vordefinierten Daten aus MapIoNrw.
 */
void MainWindow::on_pushButton_fillMap_clicked()
{
    // 1. Aktuelle Karte und Szene leeren.
    map = Map();
    scene.clear();

    // 2. Die fillMap-Methode aufrufen, um die Karte mit Städten/Straßen zu füllen.
    mapIo->fillMap(map);

    // 3. Die gefüllte Karte zeichnen.
    map.draw(scene);

    updateCityComboBoxes();
}


/**
 * @brief Öffnet den "Stadt hinzufügen"-Dialog und verarbeitet das Ergebnis.
 */
void MainWindow::on_pushButton_addCity_clicked()
{
    DialogAddCity dialog(this);
    int result = dialog.exec(); // Dialog anzeigen und auf Benutzereingabe warten.

    // Prüfen, ob der Benutzer auf "OK" geklickt hat.
    if (result == QDialog::Accepted)
    {
        // 1. Daten aus dem Dialog auslesen.
        QString name = dialog.getCityName();
        int x = dialog.getX();
        int y = dialog.getY();

        // 2. Neue Stadt erstellen und zur Karte hinzufügen.
        City* newCity = new City(name, x, y);
        map.addCity(newCity);

        // 3. Szene neu zeichnen, um die neue Stadt anzuzeigen.
        scene.clear();
        map.draw(scene);

          updateCityComboBoxes();
    }
}

/**
 * @brief Öffnet den "Straße hinzufügen"-Dialog und verarbeitet das Ergebnis.
 */
void MainWindow::on_pushButton_addStreet_clicked()
{
    DialogAddStreet dialog(map, this);
    int result = dialog.exec(); // Dialog anzeigen und warten.

    if (result == QDialog::Accepted)
    {
        // 1. Namen der ausgewählten Städte aus dem Dialog holen.
        QString name1 = dialog.getCity1Name();
        QString name2 = dialog.getCity2Name();

        // 2. Die zugehörigen City-Zeiger aus der Karte finden.
        City* city1 = map.findCity(name1);
        City* city2 = map.findCity(name2);

        // 3. Prüfen, ob beide Städte existieren und nicht identisch sind.
        if (city1 && city2 && city1 != city2)
        {
            // 4. Neue Straße erstellen und zur Karte hinzufügen.
            Street* newStreet = new Street(city1, city2);
            map.addStreet(newStreet);

            // 5. Karte neu zeichnen, um die neue Straße anzuzeigen.
            scene.clear();
            map.draw(scene);
              updateCityComboBoxes();
        }
    }
}

void MainWindow::updateCityComboBoxes()
{
    // Alte Einträge löschen
    ui->comboBox_StartCity->clear();
    ui->comboBox_TargetCity->clear();

    // Alle aktuell in der Map vorhandenen Städte hinzufügen
    for (City* city : map.getCities()) {
        ui->comboBox_StartCity->addItem(city->getName());
        ui->comboBox_TargetCity->addItem(city->getName());
    }
}

void MainWindow::on_comboBox_StartCity_activated(int index)
{
selectedStartCity = ui->comboBox_StartCity->itemText(index);
}


void MainWindow::on_comboBox_TargetCity_activated(int index)
{
selectedTargetCity = ui->comboBox_TargetCity->itemText(index);
}

