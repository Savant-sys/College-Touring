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
    //qWarning() << this->campuses.at(0).getMenu().at(0).name;
    QListWidget *campusList = ui->campusList;

    for (int i =0; i < this->campuses.size(); i++)
    {
        CampusWidget *campusItem = new CampusWidget(campuses[i], this);
        QListWidgetItem *item = new QListWidgetItem(campusList);
        campusList->addItem(item);
        item->setSizeHint(campusItem->minimumSizeHint());
        campusList->setItemWidget(item, campusItem);
    }

}


void MainWindow::on_UnderSelected_clicked()
{
    if(ui->campusList->currentItem() == nullptr)
    {
        qWarning() << "No College Selected";
        return;
    }

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
    int c =0;
    vector<QString> endColleges;
    vector<double> dist;
    for(int i = 0; i < campuses.size(); i++)
    {
        endColleges = campuses[i].getEndCollege();
        dist = campuses.at(i).getDistances();

        for(int j = 0; j < endColleges.size(); j++)
        {
            //qWarning() << dist.at(j) << " " << endColleges.at(j);
            c++;
            //qWarning() << dist << "from: " << campuses.at(i).getStartCollege() << "To: " << endColleges;
        }
    }
    if(index == 1) //custom trip
    {
        ui->Cart->clear();
        ui->Cart->setColumnCount(0);
        ui->Cart->setRowCount(0);
        ui->Cart->insertColumn(0);
        ui->Cart->insertColumn(1);
        ui->Cart->insertColumn(2);
        ui->Cart->setColumnWidth(0,120);
        ui->Cart->setColumnWidth(1,50);
        ui->Cart->setColumnWidth(2, 2);
        ui->CustomTripList->clear();
        ui->CustomTripSouvs->clear();
        ui->CustomTripPrices->clear();
        ui->SelectedCollegesList->clear();
        ui->pushButton->setEnabled(true);
        ui->pushButton_2->setEnabled(false);

        /*qWarning() << "Switching from vec to map";

        collegeMap.putVectorinHere(this->campuses);
        qWarning() << "Done putting";

        pair<int, double> key;
        QString add = "";
        for(int i = 0; i < campuses.size(); i++)
        {
             dist = campuses.at(i).getDistances();
             key.first = i;
             for(int j = 0; j < dist.size(); j++)
             {
                 key.second = dist.at(j);
             }
             ui->CustomTripList->addItem(collegeMap.getOrigin(key));
        }*/

    }
    if(index == 0)
    {
        qWarning() << "Display Page";
    }
    if(index == 2)
    {
        ui->CustomDijkstraList->clear();
        ui->listWidget->clear();
       /* qWarning() << "Switching from vec to map";

        collegeMap.putVectorinHere(this->campuses);
        qWarning() << "Done putting";
        pair<int, double> key;
        QString add = "";
        for(int i = 0; i < campuses.size(); i++)
        {
             dist = campuses.at(i).getDistances();
             key.first = i;
             for(int j = 0; j < dist.size(); j++)
             {
                 key.second = dist.at(j);
             }
             ui->CustomDijkstraList->addItem(collegeMap.getOrigin(key));
        }*/
    }
    //else
        //qWarning() << "Not implemented";
}


void MainWindow::on_pushButton_clicked()
{
    if(ui->CustomTripList->selectedItems().size() != 0)
    {
        qWarning() << "Start of Trip Added";
        QString start = ui->CustomTripList->currentItem()->text();
       // ui->CustomTripList->currentItem()->setSelected(false);
        //ui->CustomTripList->removeItemWidget(ui->CustomTripList->currentItem());
        ui->SelectedCollegesList->addItem(start);
        ui->CustomTripList->currentItem()->setHidden(true);
        ui->pushButton->setEnabled(false);
        ui->CustomTripList->setSelectionMode(QAbstractItemView::MultiSelection);
        ui->pushButton_2->setEnabled(true);
    }
}


void MainWindow::on_pushButton_2_clicked() //add selected
{
    collegeMap.ans.clear();
    vector<QString> selected;
    pair<int,double> startKey;
    if(ui->CustomTripList->selectedItems().size() > 1)
    {
        for(int i = 0; i < ui->CustomTripList->selectedItems().size(); i++)
        {
            if(i != 0)
                ui->SelectedCollegesList->addItem(ui->CustomTripList->selectedItems().at(i)->text());
            selected.push_back(ui->CustomTripList->selectedItems().at(i)->text());
        }
        ui->CustomTripList->clear();
        for(int g = 0; g < selected.size(); g++)
        {
            ui->CustomTripList->addItem(selected.at(g)); //added current trip to customTripList, now recursive search on selected map values

        }
        for(int i = 0; i < campuses.size(); i++)
        {
            if(selected.at(0) == campuses.at(i).getStartCollege())
            {
                startKey.first = i;
                startKey.second = campuses.at(i).getDistances().at(0);
            }
        }

        collegeMap.selected(selected, selected.size());
        qWarning() << "Beginning sort on: " << startKey.first << " " << startKey.second;
        collegeMap.recurSelec(startKey);
        ui->CustomTripList->clear();
        for(int i = 0; i < collegeMap.ans.size(); i++)
        {
            ui->CustomTripList->addItem(collegeMap.ans.at(i).origin/* + " -> " + collegeMap.ans.at(i).dest + " Dist: " + QString::number(collegeMap.ans.at(i).dist)*/);
            qWarning() << collegeMap.ans.at(i).origin << " -> " << collegeMap.ans.at(i).dest;
        }
        ui->CustomTripList->setSelectionMode(QAbstractItemView::SingleSelection);
        ui->pushButton_2->setEnabled(false);
       // selected
    }
    else
    {
        qWarning() << "None selected";
    }
}


void MainWindow::on_CustomTripList_itemClicked(QListWidgetItem *item)
{
    if(!ui->pushButton_2->isEnabled())
    {
        ui->CustomTripPrices->clear();
        ui->CustomTripSouvs->clear();
       QString selected = ui->CustomTripList->currentItem()->text();
       vector<Souvenir> menu;
       for(int i = 0; i < campuses.size(); i++)
       {
           if(selected == campuses.at(i).getStartCollege())
           {
              menu = campuses.at(i).getMenu();
              for(int j = 0; j < menu.size(); j++)
              {
                 ui->CustomTripSouvs->addItem(menu.at(j).name);
                 ui->CustomTripPrices->addItem(QString::number(menu.at(j).price));
              }
           }
       }
    }
}


void MainWindow::on_AddToCart_clicked() //not in final state, working on sort
{
    if(ui->CustomTripSouvs->selectedItems().size() != 0 && ui->spinBox->text() != "0")
    {
        QString name = ui->CustomTripSouvs->currentItem()->text();

        QString price = ui->CustomTripPrices->currentItem()->text();

        QString quantity = ui->spinBox->text();

        ui->Cart->insertRow (ui->Cart->rowCount());

        ui->Cart->setItem (ui->Cart->rowCount()-1, 0, new QTableWidgetItem(name));

        ui->Cart->setItem (ui->Cart->rowCount()-1, 1, new QTableWidgetItem(price));

        ui->Cart->setItem (ui->Cart->rowCount()-1, 2, new QTableWidgetItem(quantity));

    }

}


void MainWindow::on_CustomTripPrices_itemClicked(QListWidgetItem *item)
{
    int row = ui->CustomTripPrices->currentRow();
    ui->CustomTripSouvs->setCurrentRow(row);
}


void MainWindow::on_CustomTripSouvs_itemClicked(QListWidgetItem *item)
{
    int row = ui->CustomTripSouvs->currentRow();
    ui->CustomTripPrices->setCurrentRow(row);
}


void MainWindow::on_actionCustomDijkstra_triggered()
{
    ui->tabWidget->setCurrentIndex(2);
}


void MainWindow::on_pushButton_3_clicked() //customDijkstra add start
{

    pair<int,double> startKey;
    for(int i = 0; i < TABLE_SIZE; i++)
    {
        if(ui->CustomDijkstraList->currentItem()->text() == collegeMap.hashTable[i].origin)
        {
            startKey.first = collegeMap.hashTable[i].num;
            startKey.second = 0;
        }
    }
    qWarning() << "starting Dijkstra";
    collegeMap.ans.clear();
    collegeMap.initPathDist(campuses.size());
    collegeMap.dijkstra(startKey);
    collegeMap.ans.clear();
    qWarning() << "Coll: " << collegeMap.coll;
    //for(int i = 0; i < collegeMap.coll; i++)
        //qWarning() << QString::number(collegeMap.parent.at(i));
    for(int i = 0; i < collegeMap.parent.size(); i++)/*campuses.size()*/
    {
        collegeMap.pathsInAns(i);
        if(collegeMap.ans.size() > i)
        qWarning() << "num " + QString::number(i) + ": " + QString::number(collegeMap.ans.at(i).num) << " " << QString::number(collegeMap.ans.at(i).dist);
    }
    qWarning() << "Dijkstra complete";
    for(int i = 0; i < collegeMap.pathDists.size(); i++)
    {
        ui->listWidget->addItem(QString::number(collegeMap.pathDists.at(i).first) + "  " + QString::number(collegeMap.pathDists.at(i).second));
    }
//    for(int i = 0; i < collegeMap.ans.size(); i++)
//    {
//        qWarning() << "num " + QString::number(i) + ": " + QString::number(collegeMap.ans.at(i).num) << " " << QString::number(collegeMap.ans.at(i).dist);
//    }
}


void MainWindow::on_CustomConvert_clicked()
{
    db.getCampuses(this->campuses);
    //switch from vector to map
    int c =0;
    vector<QString> endColleges;
    vector<double> dist;
    for(int i = 0; i < campuses.size(); i++)
    {
        endColleges = campuses[i].getEndCollege();
        dist = campuses.at(i).getDistances();
    }
    qWarning() << "Switching from vec to map";

            collegeMap.putVectorinHere(this->campuses);
            qWarning() << "Done putting";

            pair<int, double> key;
            QString add = "";
            for(int i = 0; i < campuses.size(); i++)
            {
                 dist = campuses.at(i).getDistances();
                 key.first = i;
                 for(int j = 0; j < dist.size(); j++)
                 {
                     key.second = dist.at(j);
                 }
                 ui->CustomTripList->addItem(collegeMap.getOrigin(key));
            }
}


void MainWindow::on_CustomConvert_2_clicked()
{
    db.getCampuses(this->campuses);
    //switch from vector to map
    int c =0;
    vector<QString> endColleges;
    vector<double> dist;
    for(int i = 0; i < campuses.size(); i++)
    {
        endColleges = campuses[i].getEndCollege();
        dist = campuses.at(i).getDistances();
    }
    qWarning() << "Switching from vec to map";

            collegeMap.putVectorinHere(this->campuses);
            qWarning() << "Done putting";
            pair<int, double> key;
            QString add = "";
            for(int i = 0; i < campuses.size(); i++)
            {
                 dist = campuses.at(i).getDistances();
                 key.first = i;
                 for(int j = 0; j < dist.size(); j++)
                 {
                     key.second = dist.at(j);
                 }
                 ui->CustomDijkstraList->addItem(collegeMap.getOrigin(key));
            }
}

