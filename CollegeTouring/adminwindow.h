#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QDialog>
//#include <iostream>
#include "Campus.h"
#include "Database.h"
#include "QListWidgetItem"
//#include <QListWidget>
//#include "campusWidget.h"

namespace Ui {
class AdminWindow;
}

class AdminWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AdminWindow(QWidget *parent = nullptr);
    ~AdminWindow();

private slots:
    void on_pushButton_4_clicked();

    void on_CollegeList_itemClicked(QListWidgetItem *item);

    void on_Add_clicked();

    void on_Remove_clicked();

    void on_Change_clicked();

    void on_PriceList_itemClicked(QListWidgetItem *item);

signals:
    void showMain();
private:
    Ui::AdminWindow *ui;
    Database db;

    vector<Campus> campuses;
    vector<QString> nameList;
    vector<QString> menuList;
    std::multimap<int, Souvenir> selectedItems;
    std::vector<Campus> selectedCampus; /*!< Vector of selected campuses */
};

#endif // ADMINWINDOW_H
