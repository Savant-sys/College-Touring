#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_openTheList_clicked()
{
    vector<Campus> test = db.readFile();
    //this->ui->tableWidget->setRowCount(test.size());
    qInfo() << test.size();
    //QTableWidgetItem* temp = new QTableWidgetItem;


    for(int i = 0; i < test.size(); i++)
    {
        //qInfo() << "test: " << test[i].getStartCollege() << "\n";
        vector <QString> testString = test[i].getEndCollege();
        for (int k = 0; k < test[i].getEndCollege().size(); k++)
        {

           // qInfo() << "test for end: " << testString[k] << "\n";
        //temp->setText(test[i].getStartCollege());
        //this->ui->tableWidget->setItem(i, j, temp);
        }
    }
}



void MainWindow::on_sortState_clicked()
{

}


void MainWindow::on_sortCollege_clicked()
{

}


void MainWindow::on_openCA_clicked()
{

}


void MainWindow::on_sortStateCollege_clicked()
{

}

