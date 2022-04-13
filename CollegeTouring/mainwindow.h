#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Campus.h"
#include "Database.h"

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

private slots:
    void on_openTheList_clicked();

    void on_sortState_clicked();

    void on_sortCollege_clicked();

    void on_openCA_clicked();

    void on_sortStateCollege_clicked();

private:
    Ui::MainWindow *ui;
    Database db;
};
#endif // MAINWINDOW_H
