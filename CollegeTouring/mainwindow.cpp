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
    db.readFile();
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
    db.getCampuses(this->campuses);
        qInfo() << "Got all campuses list";
    qWarning() << this->campuses.at(0).getMenu().at(0).name;
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


void MainWindow::on_UnderSelected_clicked()
{
    if(ui->campusList->currentItem() == nullptr)
    {
        qWarning() << "No College Selected";
        return;
    }
    //ui->customList->setCurrentRow(ui->campusList->currentRow());
    QString undergrads = QString::number(this->campuses.at(ui->campusList->currentRow()).getUndergrads());
    ui->textBrowser->setText(undergrads);
}


void MainWindow::on_UnderAll_clicked()
{
    int count = this->campuses.size();
    QString undergrads = 0;
    int temp = 0;
    for(int i = 0; i < count; i++)
    {
        qWarning() << this->campuses.at(i).getUndergrads();
        temp = undergrads.toInt();
        undergrads = QString::number(this->campuses.at(i).getUndergrads());
        undergrads = undergrads + QString::number(temp);

    }
    ui->textBrowser->setText(undergrads);
}


void MainWindow::on_UnderInitial_clicked()
{
    QString undergrads = 0;
    int temp = 0;
    for(int i = 0; i < 11; i++)
    {
        qWarning() << this->campuses.at(i).getUndergrads();
        temp = undergrads.toInt();
        undergrads = QString::number(this->campuses.at(i).getUndergrads());
        undergrads = undergrads + QString::number(temp);

    }
    ui->textBrowser->setText(undergrads);
}


void MainWindow::on_actionCustom_Trip_to_Any_triggered()
{
    ui->tabWidget->setCurrentIndex(1);
}


void MainWindow::on_tabWidget_currentChanged(int index)
{
    db.getCampuses(this->campuses);
    //switch from vector to map
    int j =0;
    vector<QString> endColleges;
    vector<double> dist;
    for(int i = 0; i < campuses.size(); i++)
    {
        endColleges = campuses[i].getEndCollege();
        dist = campuses.at(i).getDistances();

        for(j = 0; j < endColleges.size(); j++)
        {
            qWarning() << dist.at(j) << " " << endColleges.at(j);

            //qWarning() << dist << "from: " << campuses.at(i).getStartCollege() << "To: " << endColleges;
        }
    }
    Map collegeMap(j);
    qWarning() << "Switching from vec to map";

    collegeMap.putVectorinHere(this->campuses);
    qWarning() << "Done putting";
    if(index == 1) //custom trip
    {
        pair<int, double> key;
        QString add = "";
        for(int i = 0; i < campuses.size(); i++)
        {
             dist = campuses.at(i).getDistances();
             key.first = i;
             for(int j = 0; j < dist.size(); j++)
             {
                 key.second = dist.at(j);
                 add = collegeMap.getOrigin(key) + " -> " + collegeMap.getDest(key);
                 ui->CustomTripList->addItem(add);
             }
             /*for(int i = 0; i < 150; i++)
             {
                 if(collegeMap.hashTable[i].num != -1)
                 {
                  //get from map instead

                     ui->CustomTripList->addItem(collegeMap.getOrigin(key));
                 //ui->CustomTripList->addItem(this->campuses.at(i).getStartCollege());
                 }
             }*/
        }





    }
    else
        qWarning() << "Not implemented";
}

