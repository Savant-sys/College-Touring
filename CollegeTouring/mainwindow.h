#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include "Campus.h"
#include "Database.h"
#include "login.h"
#include <QListWidget>
#include "campusWidget.h"

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

private:
    Ui::MainWindow *ui;

    Database db;

    Login* loginPopup;

    vector<Campus> campuses;
    vector<QString> nameList;
    vector<QString> menuList;
    std::multimap<int, Souvenir> selectedItems;
    std::vector<Campus> selectedCampus; /*!< Vector of selected campuses */


};
#endif // MAINWINDOW_H
