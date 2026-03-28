///////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXV
// Versuch 9
/////////////////////////////////////////////////////////////////////////////
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "map.h"
#include "mapio.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionClear_Scene_triggered();
    void on_actionAbout_triggered();
    void on_pushButton_teste_was_clicked();
    void on_pushButton_testDrawCity_clicked();
    void on_pushButton_testDrawStreet_clicked();
    void on_pushButton_testMapWithStreets_clicked();
    void on_pushButton_addCity_clicked();
    void on_pushButton_fillMap_clicked();
    void on_pushButton_testAbstractMap_clicked();
    void on_pushButton_testDijkstra_clicked();
    void on_pushButton_addStreet_clicked();
    void on_pushButton_testAddStreet_clicked();
    void on_checkBox_clicked();
    void on_comboBox_StartCity_activated(int index);
    void on_comboBox_TargetCity_activated(int index);
private:
    Ui::MainWindow *ui;
     QGraphicsScene scene;
     Map map;
     MapIo* mapIo;
     void testAbstractMap();
     void updateCityComboBoxes();
     QString selectedStartCity;
     QString selectedTargetCity;
};
#endif // MAINWINDOW_H
