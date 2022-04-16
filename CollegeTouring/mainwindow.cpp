#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->loginPopup = nullptr;

    Update();
//    if(db.getCampuses(this->campuses))
//        qInfo() << "Got all campuses list";

//    QListWidget *campusList = ui->campusList;

//    for (int i =0; i < this->campuses.size(); i++)
//    {
//        CampusWidget *campusItem = new CampusWidget(campuses[i], this);
//        QListWidgetItem *item = new QListWidgetItem(campusList);
//        campusList->addItem(item);
//        item->setSizeHint(campusItem->minimumSizeHint());
//        campusList->setItemWidget(item, campusItem);
//    }

//    //ui->priceText->setValidator(new QDoubleValidator(0, 100, 2, this));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addToList(QString name)
{
    QListWidget* customList = ui->customList;

    if(std::find(nameList.begin(), nameList.end(), name) == nameList.end())
    {
       customList->addItem(name);
       nameList.push_back(name);
    }
    else
        qInfo() << "Cannot add same Campus to the trip!";
}

void MainWindow::addMenuItem(Campus campus, Souvenir item){

    if(std::find(nameList.begin(), nameList.end(), campus.getStartCollege()) != nameList.end())
    {
        //Restaurant this menu items belongs to has been added to trip already. Safe to add menu item.
        selectedItems.insert(std::pair<int, Souvenir>(0, item));
    }
    else
    {
        QMessageBox popup;
        popup.critical(0, "Error", "Cannot add menu item before adding restaurant to trip.");
    }
}

void MainWindow::addToMenuList(QString name, QString campusName)
{
    QListWidget* customList = ui->menuList;

    if(std::find(nameList.begin(), nameList.end(), campusName) != nameList.end())
    {
        customList->addItem(name);
        menuList.push_back(name);
    }
    else
        qInfo() << "Cannot add Menu Item without adding Restaurant to trip!";
}

void MainWindow::on_openTheList_clicked()
{

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

void MainWindow::addCampus(Campus campus)
{
    if(std::find(nameList.begin(), nameList.end(), campus.getStartCollege()) == nameList.end() )
    {
        //Restaurant hasn't been added yet, good to add
        selectedCampus.push_back(campus);
    } else {
        QMessageBox popup;
        popup.critical(0, "Error", "Cannot add the same restaurant twice.");
    }}

void MainWindow::on_adminPop_clicked()
{
    this->loginPopup = new Login(this);
    loginPopup->show();

}

void MainWindow::Admin()
{
    hide();
    this->adminWindow = new AdminWindow(this);
    adminWindow->show();
}

void MainWindow::Update()
{
    //does not update mainwindow from admin changes yet
    ui->campusList->clear();
    if(db.getCampuses(this->campuses));
        qInfo() << "Got all campuses list";

    QListWidget *campusList = ui->campusList;

    for (int i =0; i < this->campuses.size(); i++)
    {
        CampusWidget *campusItem = new CampusWidget(campuses[i], this);
        QListWidgetItem *item = new QListWidgetItem(campusList);
        campusList->addItem(item);
        item->setSizeHint(campusItem->minimumSizeHint());
        campusList->setItemWidget(item, campusItem);
    }

    //ui->priceText->setValidator(new QDoubleValidator(0, 100, 2, this));


}
