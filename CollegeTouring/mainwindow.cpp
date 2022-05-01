#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->loginpopup = nullptr;
    log = false;
    bool result = false;
    if (result == false)
    {
      ui->tabWidget->setTabEnabled(2, false);
    }
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
        //Campus this menu items belongs to has been added to trip already. Safe to add menu item.
        selectedItems.insert(std::pair<int, Souvenir>(0, item));
    }
    else
    {
        QMessageBox popup;
        popup.critical(0, "Error", "Cannot add menu item before adding campus to trip.");
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
        qInfo() << "Cannot add Menu Item without adding Campus to trip!";
}

void MainWindow::on_openTheList_clicked()
{
//    db.readFile();
}



void MainWindow::on_sortState_clicked()
{

}


void MainWindow::on_sortCollege_clicked()
{

}


void MainWindow::on_openCA_clicked()
{
    //does not update mainwindow from admin changes yet
    ui->campusList->clear();
    db.getCampuses(this->campuses);
        qInfo() << "Got all campuses list";
    qWarning() << this->campuses.at(0).getMenu().at(0).name;
    QListWidget *campusList = ui->campusList;

    for (int i =0; i < this->campuses.size(); i++)
    {
        if (campuses[i].getState() == "California")
        {
            CampusWidget *campusItem = new CampusWidget(campuses[i], this);
            QListWidgetItem *item = new QListWidgetItem(campusList);
            campusList->addItem(item);
            item->setSizeHint(campusItem->minimumSizeHint());
            campusList->setItemWidget(item, campusItem);
        }
    }
}


void MainWindow::on_sortStateCollege_clicked()
{

}

void MainWindow::addCampus(Campus campus)
{
    if(std::find(nameList.begin(), nameList.end(), campus.getStartCollege()) == nameList.end() )
    {
        //Campus hasn't been added yet, good to add
        selectedCampus.push_back(campus);
    } else {
        QMessageBox popup;
        popup.critical(0, "Error", "Cannot add the same campus twice.");
    }}

void MainWindow::on_adminPop_clicked()
{
        if (log != true)
        {
            this->loginpopup = new Login(this);
            loginpopup->show();
            log = true;
        }
        else
        {
            QMessageBox popup;
            popup.critical(0, "Error", "You already logged in");
        }
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
        ui->pushButton->setEnabled(true);
        ui->pushButton_2->setEnabled(false);

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
    if(index == 0)
    {
        qWarning() << "Display Page";
    }
    else
        qWarning() << "Not implemented";
}


void MainWindow::on_pushButton_clicked()
{
    if(ui->CustomTripList->selectedItems().size() != 0)
    {
        qWarning() << "Start of Trip Added";
        QString start = ui->CustomTripList->currentItem()->text();
       // ui->CustomTripList->currentItem()->setSelected(false);
        //ui->CustomTripList->removeItemWidget(ui->CustomTripList->currentItem());
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

void MainWindow::unlockTab()
{
    ui->tabWidget->setTabEnabled(2, true);
    //loop through colleges and create a MenuWidget for each one
    QListWidget *menuList = ui->menuAdminList;
    menuList->clear();

    for (int i = 0; i < campuses.size(); i++)
    {
        MenuWidget *menuItem = new MenuWidget(this->campuses[i], this);
        QListWidgetItem *item = new QListWidgetItem(menuList);
        menuList->addItem(item);
        item->setSizeHint(menuItem->minimumSizeHint());
        menuList->setItemWidget(item, menuItem);
    }

}


void MainWindow::addItem(Campus campus, vector<Souvenir> newMenu){
    QString name = ui->itemnameText->toPlainText();
    double price = std::stod(ui->priceText->text().toStdString());

    Souvenir newItem;
    newItem.name = name;
    newItem.price = price;

    std::vector<Souvenir> menu = campus.getMenu();
    menu.push_back(newItem);
    this->db.modifySouvenir(campus, menu);
//    for (int i = 0; i < campuses.size(); i++)
//    {
//        if (campus.getStartCollege() == campuses[i].getStartCollege())
//        {
//            this->db.modifySouvenir(campus, menu, i);
//            break;
//        }
//    }

    //update campuses
    this->db.getCampuses(this->campuses);

    //update ui
    QListWidget *campusList = ui->campusList;
    campusList->clear();

    //Create a CampusWidget object for each campus and add it to the campusList list widget.
    for (int i = 0; i < this->campuses.size(); i++)
    {
        CampusWidget *campusItem = new CampusWidget(campuses[i], this);
        QListWidgetItem *item = new QListWidgetItem(campusList);
        campusList->addItem(item);
        item->setSizeHint(campusItem->minimumSizeHint());
        campusList->setItemWidget(item, campusItem);
    }

    //loop through campuses and create a MenuWidget for each one
    QListWidget *menuList = ui->menuAdminList;
    menuList->clear();

    for (int i = 0; i < campuses.size(); i++){
        MenuWidget *menuItem = new MenuWidget(this->campuses[i], this);
        QListWidgetItem *item = new QListWidgetItem(menuList);
        menuList->addItem(item);
        item->setSizeHint(menuItem->minimumSizeHint());
        menuList->setItemWidget(item, menuItem);
    }
}

void MainWindow::deleteItem(Campus campus, vector<Souvenir> newMenu){
    //menu is already updated for this function call
    this->db.modifySouvenir(campus, newMenu);

    //update campuses
    this->db.getCampuses(this->campuses);

    //update ui
    vector<Souvenir> test = campuses[0].getMenu();
    qInfo() << "TESTMENU" << test[0].name;

    QListWidget *campusList = ui->campusList;
    campusList->clear();

    //Create a CampusWidget object for each campus and add it to the campusList list widget.
    for (int i = 0; i < this->campuses.size(); i++)
    {
        CampusWidget *campusItem = new CampusWidget(campuses[i], this);
        QListWidgetItem *item = new QListWidgetItem(campusList);
        campusList->addItem(item);
        item->setSizeHint(campusItem->minimumSizeHint());
        campusList->setItemWidget(item, campusItem);
    }

    //loop through campuses and create a MenuWidget for each one
    QListWidget *menuList = ui->menuAdminList;
    menuList->clear();

    for (int i = 0; i < campuses.size(); i++){
        MenuWidget *menuItem = new MenuWidget(this->campuses[i], this);
        QListWidgetItem *item = new QListWidgetItem(menuList);
        menuList->addItem(item);
        item->setSizeHint(menuItem->minimumSizeHint());
        menuList->setItemWidget(item, menuItem);
    }
}

void MainWindow::editItem(Campus campus, int index){
    vector<Souvenir> newMenu = campus.getMenu();
    Souvenir editing = campus.getMenu()[index];
    newMenu.erase(newMenu.begin() + index);
    double newPrice = std::stod(ui->priceText->text().toStdString());
    editing.price = newPrice;

    newMenu.push_back(editing);

    this->db.modifySouvenir(campus, newMenu);

    //update campuses
    this->db.getCampuses(this->campuses);

    //update ui

    QListWidget *campusList = ui->campusList;
    campusList->clear();

    //Create a CampusWidget object for each campus and add it to the campusList list widget.
    for (int i = 0; i < this->campuses.size(); i++)
    {
        CampusWidget *campusItem = new CampusWidget(campuses[i], this);
        QListWidgetItem *item = new QListWidgetItem(campusList);
        campusList->addItem(item);
        item->setSizeHint(campusItem->minimumSizeHint());
        campusList->setItemWidget(item, campusItem);
    }

    //loop through campuses and create a MenuWidget for each one
    QListWidget *menuList = ui->menuAdminList;
    menuList->clear();

    for (int i = 0; i < campuses.size(); i++){
        qInfo() << "edit";
        MenuWidget *menuItem = new MenuWidget(this->campuses[i], this);
        QListWidgetItem *item = new QListWidgetItem(menuList);
        menuList->addItem(item);
        item->setSizeHint(menuItem->minimumSizeHint());
        menuList->setItemWidget(item, menuItem);
    }
}
