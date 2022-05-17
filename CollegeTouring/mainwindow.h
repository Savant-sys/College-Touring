#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include "campus.h"
#include "database.h"
#include "login.h"
#include <QListWidget>
#include "campus_widget.h"
#include "map.h"
#include "menuwidget.h"
#include "allfromsaddleback.h"

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void addCampus(Campus campus);
    vector<QString> getMenuList() const { return menuList; }
    void addMenuItem(Campus restaurant, Souvenir item);
    void addItem(Campus campus, vector<Souvenir> newMenu);
    void deleteItem(Campus campus, vector<Souvenir> newMenu);
    void editItem(Campus campus, int index);
    void updateEndColleges(Campus campus);
    Database db;
    vector<Campus> campuses;

public slots:
    void unlockTab();
    vector<QString> getEndCollegesFromSaddleback() { return campuses[4].getEndCollege(); }
    vector<double> getDistancesFromSaddleback() { return campuses[4].getDistances(); }
private slots:
    void on_openCA_clicked();

    void on_adminPop_clicked();

    void Update();

    void on_UnderSelected_clicked();

    void on_UnderAll_clicked();

    void on_UnderInitial_clicked();

    void on_actionCustom_Trip_to_Any_triggered();

    void on_tabWidget_currentChanged(int index);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_CustomTripList_itemClicked(QListWidgetItem *item);

    void on_AddToCart_clicked();

    void on_CustomTripPrices_itemClicked(QListWidgetItem *item);

    void on_CustomTripSouvs_itemClicked(QListWidgetItem *item);

    void on_pushButton_3_clicked();

    void on_openAll_clicked();

    void on_sortStateStart_clicked();

    void on_actionCustrom_Dijkstra_triggered();

    void on_addStateD_clicked();

    void on_CustomConvert_clicked();

    void on_CustomConvert_2_clicked();

    void on_sortStates_clicked();

    void on_sortStart_clicked();

    void on_allFromSaddleback_clicked();
    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_addStateD_2_clicked();
    void on_CustomConvert_3_clicked();

    void on_AllSaddlebackList_itemClicked(QListWidgetItem *item);

    void on_SaddlebackTripSouvs_itemClicked(QListWidgetItem *item);

    void on_SaddlebackTripPrices_itemClicked(QListWidgetItem *item);

    void on_AddToCartSA_clicked();

    void on_SaddlbackFinish_clicked();

    void on_actionAll_from_Saddleback_triggered();

    void on_StartMich_clicked();

    void on_CustomConvert_4_clicked();

    void on_MichTripSouvs_itemClicked(QListWidgetItem *item);

    void on_MichTripPrices_itemClicked(QListWidgetItem *item);

    void on_AddToCartM_clicked();

    void on_MichSpecificList_itemClicked(QListWidgetItem *item);

    void on_MichFinish_clicked();
private:
    Ui::MainWindow *ui;

//    Database db;

    bool log;
    Login* loginpopup;
    Allfromsaddleback* saddlebackTablepopup;
bool added;
    Map collegeMap;

    vector<QString> nameList;
    vector<QString> menuList;
    std::multimap<int, Souvenir> selectedItems;
    std::vector<Campus> selectedCampus; /*!< Vector of selected campuses */


};
#endif // MAINWINDOW_H
