#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include "campus.h"
#include "database.h"
#include "login.h"
#include <QListWidget>
#include "adminwindow.h"
#include "campus_widget.h"
#include "map.h"


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
    void addToList(QString name);
    vector<QString> getMenuList() const { return menuList; }
    void addMenuItem(Campus restaurant, Souvenir item);
    void addToMenuList(QString name, QString campusName);
private slots:
    void on_openTheList_clicked();

    void on_sortState_clicked();

    void on_sortCollege_clicked();

    void on_openCA_clicked();

    void on_sortStateCollege_clicked();

    void on_adminPop_clicked();

    void Admin();

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

    void on_actionCustomDijkstra_triggered();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;

    Database db;

    Login* loginPopup;
    AdminWindow* adminWindow;

    Map collegeMap;
    vector<Campus> campuses;
    vector<QString> nameList;
    vector<QString> menuList;
    std::multimap<int, Souvenir> selectedItems;
    std::vector<Campus> selectedCampus; /*!< Vector of selected campuses */


};
#endif // MAINWINDOW_H
