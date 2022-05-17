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
      ui->tabWidget->setTabEnabled(5, false);
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
            popup.warning(this, "Warning", "You already logged in!");
        }
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
        //qInfo() << campuses[i].getEndCollege()[1] << "\n";
        CampusWidget *campusItem = new CampusWidget(campuses[i], this);
        QListWidgetItem *item = new QListWidgetItem(campusList);
        campusList->addItem(item);
        item->setSizeHint(campusItem->minimumSizeHint());
        campusList->setItemWidget(item, campusItem);
    }

    ui->priceText->setValidator(new QDoubleValidator(0, 100, 2, this));
}


void MainWindow::on_UnderSelected_clicked()
{
    if(ui->campusList->currentItem() == nullptr)
    {
        qWarning() << "No College Selected";
        QMessageBox popup;
        popup.critical(0, "Error", "You must select one of the colleges!");
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
        ui->TotalDistCR->clear();
        ui->Cart->clear();
        ui->Cart->setColumnCount(0);
        ui->Cart->setRowCount(0);
        ui->Cart->insertColumn(0);
        ui->Cart->insertColumn(1);
        ui->Cart->insertColumn(2);
        ui->Cart->insertColumn(3);
        ui->Cart->setColumnWidth(0,120);
        ui->Cart->setColumnWidth(1,50);
        ui->Cart->setColumnWidth(2, 2);
        ui->Cart->setColumnWidth(3,200);
        ui->SelectedCollegesList->insertColumn(0);
        ui->SelectedCollegesList->insertColumn(1);
        ui->SelectedCollegesList->setColumnWidth(0, 230);
        ui->SelectedCollegesList->setColumnWidth(1, 50);
        ui->CustomTripList->clear();
        ui->CustomTripSouvs->clear();
        ui->CustomTripPrices->clear();
        ui->pushButton->setEnabled(true);
        ui->pushButton_2->setEnabled(false);
        ui->CustomConvert->setEnabled(true);
        ui->CustomTripList->setSelectionMode(QAbstractItemView::SingleSelection);

//        qWarning() << "Switching from vec to map";

//        collegeMap.putVectorinHere(this->campuses);
//        qWarning() << "Done putting";

//        pair<int, double> key;
//        QString add = "";
//        for(int i = 0; i < campuses.size(); i++)
//        {
//             dist = campuses.at(i).getDistances();
//             key.first = i;
//             for(int j = 0; j < dist.size(); j++)
//             {
//                 key.second = dist.at(j);
//             }
//             ui->CustomTripList->addItem(collegeMap.getOrigin(key));
//        }
       // collegeMap.DFS(6);

    }


    if(index == 0)
    {
        qWarning() << "Display Page";
    }

    if(index == 2) // Custom Dijkstra trip
    {
        ui->listWidget_2->clear();
        ui->pushButton_5->setEnabled(false);
        ui->CustomDijkstraList->clear();
        ui->listWidget->clear();
        ui->addStateD->setEnabled(true);
        ui->CustomConvert_2->setEnabled(true);
        collegeMap.numToPrint.clear();
        collegeMap.pathDists.clear();
        collegeMap.parent.clear();
        collegeMap.ans.clear();
    }
    if(index == 3) // Saddleback to all Dijkstra trip
    {
        ui->TotalDistSA->clear();
        ui->CartSaddleback->clear();
        ui->SelectedCollegesList_2->clear();
        ui->CartSaddleback->setColumnCount(0);
        ui->CartSaddleback->setRowCount(0);
        ui->CartSaddleback->insertColumn(0);
        ui->CartSaddleback->insertColumn(1);
        ui->CartSaddleback->insertColumn(2);
        ui->CartSaddleback->insertColumn(3);
        ui->CartSaddleback->setColumnWidth(0,120);
        ui->CartSaddleback->setColumnWidth(1,50);
        ui->CartSaddleback->setColumnWidth(2, 2);
        ui->CartSaddleback->setColumnWidth(3,200);
        ui->SelectedCollegesList_2->insertColumn(0);
        ui->SelectedCollegesList_2->insertColumn(1);
        ui->SelectedCollegesList_2->setColumnWidth(0, 230);
        ui->SelectedCollegesList_2->setColumnWidth(1, 50);
        //ui->CustomTripList->clear();
        ui->SaddlebackTripSouvs->clear();
        ui->SaddlebackTripPrices->clear();
        //ui->pushButton_5->setEnabled(true);
        //ui->pushButton_6->setEnabled(false);
        ui->CustomConvert_3->setEnabled(true);
        ui->AllSaddlebackList->setSelectionMode(QAbstractItemView::SingleSelection);
        //ui->pushButton_6->setEnabled(false);
        ui->AllSaddlebackList->clear();
        //ui->Sadd->clear();
        ui->addStateD_2->setEnabled(true);
        //ui->CustomConvert_3->setEnabled(true);
        collegeMap.numToPrint.clear();
        collegeMap.pathDists.clear();
        collegeMap.parent.clear();
        collegeMap.ans.clear();
    }
    if(index == 4) // Michigan to any Dijkstra trip
    {
        ui->SelectedCollegesList_3->clear();
        ui->TotalDistM->clear();
        ui->CartMich->clear();
        ui->SelectedCollegesList_3->clear();
        ui->CartMich->setColumnCount(0);
        ui->CartMich->setRowCount(0);
        ui->CartMich->insertColumn(0);
        ui->CartMich->insertColumn(1);
        ui->CartMich->insertColumn(2);
        ui->CartMich->insertColumn(3);
        ui->CartMich->setColumnWidth(0,120);
        ui->CartMich->setColumnWidth(1,50);
        ui->CartMich->setColumnWidth(2, 2);
        ui->CartMich->setColumnWidth(3,200);
        ui->SelectedCollegesList_3->insertColumn(0);
        ui->SelectedCollegesList_3->insertColumn(1);
        ui->SelectedCollegesList_3->setColumnWidth(0, 230);
        ui->SelectedCollegesList_3->setColumnWidth(1, 50);
        //ui->CustomTripList->clear();
        ui->MichTripSouvs->clear();
        ui->MichTripPrices->clear();
        //ui->pushButton_5->setEnabled(true);
        //ui->pushButton_7->setEnabled(false);
        ui->CustomConvert_4->setEnabled(true);
        ui->MichSpecificList->setSelectionMode(QAbstractItemView::SingleSelection);
        //ui->pushButton_6->setEnabled(false);
        ui->MichSpecificList->clear();
        //ui->Sadd->clear();
        ui->StartMich->setEnabled(true);
        //ui->CustomConvert_3->setEnabled(true);
        collegeMap.numToPrint.clear();
        collegeMap.pathDists.clear();
        collegeMap.parent.clear();
        collegeMap.ans.clear();
    }
}


void MainWindow::on_pushButton_clicked() // add start custom recursive
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


void MainWindow::on_pushButton_2_clicked() //add selected recursive custom trip
{
    if(ui->CustomTripList->selectedItems().count() == 0)
        return;
    for(int i = 0; i < TABLE_SIZE; i++)
    collegeMap.hashTable[i].select = false;
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
        double totDist = 0;
        for(int i = 0; i < collegeMap.ans.size(); i++)
        {
            totDist += collegeMap.ans.at(i).dist;
            ui->CustomTripList->addItem(collegeMap.ans.at(i).origin/* + " -> " + collegeMap.ans.at(i).dest + " Dist: " + QString::number(collegeMap.ans.at(i).dist)*/);
            qWarning() << collegeMap.ans.at(i).origin << " -> " << collegeMap.ans.at(i).dest;
        }
        ui->CustomTripList->setSelectionMode(QAbstractItemView::SingleSelection);
        ui->pushButton_2->setEnabled(false);
        ui->TotalDistCR->setText(QString::number(totDist));
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


void MainWindow::on_AddToCart_clicked() //adds current item from current college to cart or updates the quantity
{
    if(ui->CustomTripSouvs->selectedItems().size() != 0 && ui->spinBox->text() != "0" && ui->CustomTripList->selectedItems().size() != 0)
    {
        QString college = ui->CustomTripList->currentItem()->text();

        QString name = ui->CustomTripSouvs->currentItem()->text();

        QString price = ui->CustomTripPrices->currentItem()->text();

        QString quantity = ui->spinBox->text();

        QString collComp;

        bool check = false;
        int index = 0;
        if(ui->Cart->rowCount() != 0)
        {

           // QVector<QTableWidgetItem*> cartColl = ui->Cart->findItems(college, Qt::MatchFixedString);
          // QVector<QTableWidgetItem*> cartItems = ui->Cart->findItems(name, Qt::MatchFixedString);
           //for(int i = 0; i < cartItems.size(); i++)
           //{
               //collComp = cartColl.at(i)->text();
               for(int n = 0; n < ui->Cart->rowCount(); n++)
               {
                   if(ui->Cart->item(n,0)->text() == name && college == ui->Cart->item(n,3)->text())
                   {
                       index = n;
                       check = true;
                   }
               }
           // if(cartItems.at(i)->data(0).toString() == name && college == collComp)
               if(check == true)
            {
                int newquant = quantity.toInt()/* + cartItems.at(i)->data(2).toInt()*/;
                //cartItems.at(i)->data(2).setValue(newquant);

                ui->Cart->item(index,2)->setText(QString::number(newquant));
                //qWarning() << name;
                //check = true;
            }
           //}
        }
        if(check == false)
        {
            ui->Cart->insertRow(ui->Cart->rowCount());

            ui->Cart->setItem(ui->Cart->rowCount()-1, 0, new QTableWidgetItem(name));

            ui->Cart->setItem(ui->Cart->rowCount()-1, 1, new QTableWidgetItem(price));

            ui->Cart->setItem(ui->Cart->rowCount()-1, 2, new QTableWidgetItem(quantity));

            ui->Cart->setItem(ui->Cart->rowCount()-1, 3, new QTableWidgetItem(college));
        }
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
    ui->tabWidget->setTabEnabled(5, true);
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


void MainWindow::addItem(Campus campus, vector<Souvenir> newMenu)
{
    if (ui->itemnameText->toPlainText() != "")
    {
        if (ui->priceText->text().toStdString() != "")
        {
            QString name = ui->itemnameText->toPlainText();
            double price = stod(ui->priceText->text().toStdString());

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
            QListWidget* campusList = ui->campusList;
            campusList->clear();

            //Create a CampusWidget object for each campus and add it to the campusList list widget.
            for (int i = 0; i < this->campuses.size(); i++)
            {
                CampusWidget* campusItem = new CampusWidget(campuses[i], this);
                QListWidgetItem* item = new QListWidgetItem(campusList);
                campusList->addItem(item);
                item->setSizeHint(campusItem->minimumSizeHint());
                campusList->setItemWidget(item, campusItem);
            }

            //loop through campuses and create a MenuWidget for each one
            QListWidget* menuList = ui->menuAdminList;
            menuList->clear();

            for (int i = 0; i < campuses.size(); i++)
            {
                MenuWidget* menuItem = new MenuWidget(this->campuses[i], this);
                QListWidgetItem* item = new QListWidgetItem(menuList);
                menuList->addItem(item);
                item->setSizeHint(menuItem->minimumSizeHint());
                menuList->setItemWidget(item, menuItem);
            }
            QMessageBox::information(this, "Success", "Successfully inserted!");
        }
        else
        {
            QMessageBox popup;
            popup.critical(0, "Error", "You must enter the price!");
        }
    }
    else
    {
        QMessageBox popup;
        popup.critical(0, "Error", "You must enter an item name!");
    }
}

void MainWindow::deleteItem(Campus campus, vector<Souvenir> newMenu){
    //menu is already updated for this function call
    this->db.modifySouvenir(campus, newMenu);

    //update campuses
    this->db.getCampuses(this->campuses);

    //update ui
//    vector<Souvenir> test = campuses[0].getMenu();
//    qInfo() << "TESTMENU" << test[0].name;

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

void MainWindow::editItem(Campus campus, int index)
{
        if (ui->priceText->text().toStdString() != "")
        {
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

            QListWidget* campusList = ui->campusList;
            campusList->clear();

            //Create a CampusWidget object for each campus and add it to the campusList list widget.
            for (int i = 0; i < this->campuses.size(); i++)
            {
                CampusWidget* campusItem = new CampusWidget(campuses[i], this);
                QListWidgetItem* item = new QListWidgetItem(campusList);
                campusList->addItem(item);
                item->setSizeHint(campusItem->minimumSizeHint());
                campusList->setItemWidget(item, campusItem);
            }

            //loop through campuses and create a MenuWidget for each one
            QListWidget* menuList = ui->menuAdminList;
            menuList->clear();

            for (int i = 0; i < campuses.size(); i++)
            {
                MenuWidget* menuItem = new MenuWidget(this->campuses[i], this);
                QListWidgetItem* item = new QListWidgetItem(menuList);
                menuList->addItem(item);
                item->setSizeHint(menuItem->minimumSizeHint());
                menuList->setItemWidget(item, menuItem);
            }
        }
        else
        {
            QMessageBox popup;
            popup.critical(0, "Error", "You must enter the price!");
        }
}

void MainWindow::on_pushButton_3_clicked()
{
//    db.readFile();
    vector <QString> endCollege;
    std::vector<double> distances;
    std::vector<Souvenir> menu;

    vector<Campus> newCampuses = this->db.readFile();

    this->db.addCampuses(newCampuses);

    this->db.getCampuses(this->campuses);

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
//    qInfo() << newCampuses[1].getStartCollege();
//    qInfo() << newCampuses[1].getID();

//    distances = newCampuses[1].getDistances();
//    qInfo() << newCampuses[1].getSaddlebackDistance();
//    menu = newCampuses[1].getMenu();

//    for (auto i = distances.begin(); i != distances.end(); i++)
//    {
//        qInfo() << *i;
//    }

//    for (auto j = menu.begin(); j != menu.end(); j++)
//    {
//        qInfo() << j->name << " " << j->price;
//    }
}


void MainWindow::on_openAll_clicked()
{
    Update();
}


void MainWindow::on_sortStateEnd_clicked()
{
    ui->campusList->clear();
    db.getCampuses(this->campuses);
        qInfo() << "Got all campuses list";
    qWarning() << this->campuses.at(0).getMenu().at(0).name;
    QListWidget *campusList = ui->campusList;

    vector<Campus> sort = campuses;

        int j = 0;
        bool swap = true;


        while (swap)
        {
            swap = false;
            j++;
            for (int l = 0; l < sort.size() - j; l++)
            {
                qInfo () << "sorted state\n";
                if (sort[l].getState() > sort[l + 1].getState())
                {
                    Campus temp(sort[l]);
                    sort[l] = sort[l + 1];
                    sort[l + 1] = temp;
                    swap = true;
                }
            }
        }

        while (swap)
        {
            swap = false;
            j++;
            for (int l = 0; l < sort.size() - j; l++)
            {
                qInfo () << "sorted start\n";
                if (sort[l].getEndCollege() > sort[l + 1].getEndCollege())
                {
                    Campus temp(sort[l]);
                    sort[l] = sort[l + 1];
                    sort[l + 1] = temp;
                    swap = true;
                }
            }
        }



    for (int i =0; i < sort.size(); i++)
    {

            CampusWidget *campusItem = new CampusWidget(sort[i], this);
            QListWidgetItem *item = new QListWidgetItem(campusList);
            campusList->addItem(item);
            item->setSizeHint(campusItem->minimumSizeHint());
            campusList->setItemWidget(item, campusItem);

    }
}


void MainWindow::on_sortStateStart_clicked()
{
    ui->campusList->clear();
    db.getCampuses(this->campuses);
        qInfo() << "Got all campuses list";
    qWarning() << this->campuses.at(0).getMenu().at(0).name;
    QListWidget *campusList = ui->campusList;

    vector<Campus> sort = campuses;

        int j = 0;
        bool swap = true;


        while (swap)
        {
            swap = false;
            j++;
            for (int l = 0; l < sort.size() - j; l++)
            {
                qInfo () << "sorted state\n";
                if (sort[l].getState() > sort[l + 1].getState())
                {
                    Campus temp(sort[l]);
                    sort[l] = sort[l + 1];
                    sort[l + 1] = temp;
                    swap = true;
                }
            }
        }

        swap = true;
        while (swap)
        {
            swap = false;
            j++;
            for (int l = 0; l < sort.size() - j; l++)
            {
                qInfo () << "sorted start\n";
                if (sort[l].getStartCollege() > sort[l + 1].getStartCollege())
                {
                    Campus temp(sort[l]);
                    sort[l] = sort[l + 1];
                    sort[l + 1] = temp;
                    swap = true;
                }
            }
        }

    for (int i =0; i < sort.size(); i++)
    {

            CampusWidget *campusItem = new CampusWidget(sort[i], this);
            QListWidgetItem *item = new QListWidgetItem(campusList);
            campusList->addItem(item);
            item->setSizeHint(campusItem->minimumSizeHint());
            campusList->setItemWidget(item, campusItem);

    }
}


void MainWindow::on_actionCustrom_Dijkstra_triggered()
{
    ui->tabWidget->setCurrentIndex(2);
}


void MainWindow::on_addStateD_clicked() // add start dijkstra
{
    if(ui->CustomDijkstraList->selectedItems().size() != 0)
    {
        qWarning() << "Start of Trip Added";
        QString start = ui->CustomDijkstraList->currentItem()->text();
       // ui->CustomTripList->currentItem()->setSelected(false);
        //ui->CustomTripList->removeItemWidget(ui->CustomTripList->currentItem());
        ui->CustomDijkstraList->currentItem()->setHidden(true);
        //ui->pushButton->setEnabled(false);
        ui->CustomDijkstraList->setSelectionMode(QAbstractItemView::MultiSelection);
        ui->pushButton_5->setEnabled(true);
        ui->addStateD->setEnabled(false);
    }

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
            ui->CustomConvert->setEnabled(false);
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
            ui->CustomConvert_2->setEnabled(false);
}


void MainWindow::on_pushButton_5_clicked() // Dijkstra add selected and run
{
    if(ui->CustomDijkstraList->selectedItems().count() <= 1)
        return;
    for(int i = 0; i < TABLE_SIZE; i++)
    {
        collegeMap.hashTable[i].select = false;
        collegeMap.hashTable[i].visited = false;
    }
    pair<int,double> startKey;
    vector<QString> selected;
    vector<QString> toSelect;
    if(ui->CustomDijkstraList->selectedItems().size() > 1)
    {
        for(int i = 0; i < ui->CustomDijkstraList->selectedItems().size(); i++)
        {
            selected.push_back(ui->CustomDijkstraList->selectedItems().at(i)->text());
        }
        ui->CustomDijkstraList->selectAll();
        toSelect.push_back(selected.at(0));
        for(int i = 0; i < ui->CustomDijkstraList->selectedItems().size(); i++)
        {
            toSelect.push_back(ui->CustomDijkstraList->selectedItems().at(i)->text());
        }
        ui->CustomDijkstraList->clear();
        for(int g = 0; g < selected.size(); g++)
        {
            ui->CustomDijkstraList->addItem(selected.at(g)); //added current trip to TripList, now Dijkstra search on selected map values

        }
        for(int i = 0; i < campuses.size(); i++)
        {
            if(selected.at(0) == campuses.at(i).getStartCollege())
            {
                startKey.first = i;
                startKey.second = campuses.at(i).getDistances().at(0);
            }
        }

        collegeMap.selected(toSelect, toSelect.size());
        qWarning() << "Beginning sort on: " << startKey.first << " " << startKey.second;
//        collegeMap.dijkstra(startKey);
//        ui->CustomDijkstraList->clear();
//        for(int i = 0; i < collegeMap.ans.size(); i++)
//        {
//            ui->CustomTripList->addItem(collegeMap.ans.at(i).origin/* + " -> " + collegeMap.ans.at(i).dest + " Dist: " + QString::number(collegeMap.ans.at(i).dist)*/);
//            qWarning() << collegeMap.ans.at(i).origin << " -> " << collegeMap.ans.at(i).dest;
//        }
        ui->CustomDijkstraList->setSelectionMode(QAbstractItemView::SingleSelection);
        ui->pushButton_5->setEnabled(false);
       // selected
    }
    else
    {
        qWarning() << "None selected";
    }

//    if(ui->CustomDijkstraList->currentItem() == NULL)
//        return;
//    for(int i = 0; i < TABLE_SIZE; i++)
//    {
//        if(ui->CustomDijkstraList->currentItem()->text() == collegeMap.hashTable[i].origin)
//        {
//            startKey.first = collegeMap.hashTable[i].num;
//            startKey.second = 0;
//        }
//    }
    collegeMap.pathDists.clear();
    qWarning() << "starting Dijkstra";
    collegeMap.ans.clear();
    toSelect.clear();
    for(int i = 0; i < campuses.size(); i++)
    {
        toSelect.push_back(campuses.at(i).getStartCollege());
    }
    collegeMap.initPathDist(toSelect);
    collegeMap.dijkstra(startKey); //dijkstra on start complete, now find path to  next selected;
    int saveNum = 0;
    int endInd = 0;
    for(int t = 1; t < selected.size(); t++)
    {
        collegeMap.ans.clear();
        for(int j =0; j < TABLE_SIZE; j++)
        {
        if(selected.at(t) == collegeMap.hashTable[j].origin)
        {
            saveNum = collegeMap.hashTable[j].num;
        }
        }

    for(int i = 0; i < collegeMap.pathDists.size(); i++)
    {
        if(collegeMap.pathDists.at(i).first == saveNum)
            endInd = i;
    }
    HashStruct endd;
    endd.num = endInd;
    collegeMap.ans.push_back(endd);
    collegeMap.pathsInAns(endInd); //path from choice
    //collegeMap.numToPrint.push_back(collegeMap.pathDists.at(0).first);

    qWarning() << "Coll: " << collegeMap.coll;

    ui->MichSpecificList->clear();
    bool go = true;
    double totDist = 0;
    QString toDistplay = "";
    int corrIndex = 0;
    for(int i = collegeMap.ans.size()-1; i >= 0; i--)
    {
        bool checked = false;
        for(int n = 0; n < collegeMap.pathDists.size(); n++)
        {
            if(collegeMap.ans.at(i).num == collegeMap.pathDists.at(n).first)
                corrIndex = collegeMap.pathDists.at(n).first;
        }
        for(int m = 0; m < TABLE_SIZE; m++)
        {
            if(collegeMap.hashTable[m].num == corrIndex)
                toDistplay = collegeMap.hashTable[m].origin;
        }
        for(int p = 0; p < ui->listWidget_2->count(); p++)
        {
            if(ui->listWidget_2->item(p)->text() == toDistplay)
                checked = true;
        }
        for(int j = 0; j < campuses.size(); j++)
        {



            if(campuses.at(j).getStartCollege() == toDistplay && checked == false /*&& collegeMap.ans.at(i).num != 0*/)
            {
                ui->listWidget_2->addItem(campuses.at(j).getStartCollege());
            }
        }
//        for(int j = 0; j < toSelect.size(); j++)
//        {



//            if(toSelect.at(j) == toDistplay && checked == false && collegeMap.ans.at(i).num != 0)
//            {
//                ui->listWidget_2->addItem(toSelect.at(j));
//            }
//        }

    }
    collegeMap.ans.clear();
    pair<int, double> nextKey;
    for(int i = 0; i < collegeMap.pathDists.size(); i++)
        {
            collegeMap.pathDists.at(i).second = INFINITY;
        }
    for(int i = 0; i < TABLE_SIZE; i++)
        {
            collegeMap.hashTable[i].visited = false;
            if(collegeMap.hashTable[i].origin == selected.at(t))
                nextKey.first = collegeMap.hashTable[i].num;
        }
    for(int i = 0; i < collegeMap.parent.size(); i++)
    {
        collegeMap.parent.at(i) = -1;
    }
    collegeMap.coll = campuses.size();
    collegeMap.dijkstra(nextKey);
    } //inclue more

//    collegeMap.numToPrint.push_back(collegeMap.pathDists.at(0).first);

//    collegeMap.pathDists.erase(collegeMap.pathDists.begin()/* + startKey.first+1*/);
//    collegeMap.ans.clear();
//    qWarning() << "Coll: " << collegeMap.coll << " finding the rest";
//    double smallest = 9999;
//    int pathIndex = 0;
//    for(int i = 0; i < collegeMap.pathDists.size(); i++)
//    {
//        if(smallest > collegeMap.pathDists.at(i).second)
//        {
//            pathIndex = collegeMap.pathDists.at(i).first;
//            smallest = collegeMap.pathDists.at(i).second;
//        }

//    }
//    for(int i = 0; i < collegeMap.pathDists.size(); i++)
//    {
//        collegeMap.pathDists.at(i).second = INFINITY;
//    }
//    for(int i = 0; i < TABLE_SIZE; i++)
//    {
//        collegeMap.hashTable[i].visited = false;
//    }
//    collegeMap.dijkstraNext(pathIndex);
//    bool go = true;
//    for(int i = 0; i < collegeMap.numToPrint.size(); i++)
//    {
//        for(int j = 0; j < TABLE_SIZE; j++)
//        {
//            for(int l = 0; l < ui->listWidget->count(); l++)
//            {
//                if(ui->listWidget->item(l)->text() == collegeMap.hashTable[j].origin)
//                    go = false;
//            }
//            if(collegeMap.numToPrint.at(i) == collegeMap.hashTable[j].num && go == true)
//            {
//                ui->listWidget->addItem(collegeMap.hashTable[j].origin);
//            }
//         go = true;
//        }
//    }
   /* for(int i = 0; i < collegeMap.parent.size(); i++)*//*campuses.size()*/
    /*{
        collegeMap.pathsInAns(i);
        if(collegeMap.ans.size() > i)
        qWarning() << "num " + QString::number(i) + ": " + QString::number(collegeMap.ans.at(i).num) << " " << QString::number(collegeMap.ans.at(i).dist);
    }*/


    qWarning() << "Dijkstra complete";
}


void MainWindow::on_pushButton_4_clicked() //custom recur finish cart
{
    double grandTotal = 0;
    bool chk = false;
    int ind = 0;
    vector<pair<QString,double>> colleges;
    for(int i = 0; i < ui->Cart->rowCount(); i++)
    {
        pair<QString,double> col;
        col.first = ui->Cart->item(i,3)->text();
        double number = (ui->Cart->item(i, 1)->text().toDouble() * ui->Cart->item(i, 2)->text().toDouble());
        col.second = number;
        if(!colleges.empty())
        {
            //colleges.push_back(col);

        //else{


        for(int j = 0; j < colleges.size(); j++)
        {
            if(colleges.at(j).first == col.first)
            {
                ind = j;
                chk = true;
            }

        }

        if(chk == true)
        {
            double num = colleges.at(ind).second + (ui->Cart->item(i, 1)->text().toDouble() * ui->Cart->item(i, 2)->text().toDouble());
            colleges.at(ind).second = num;
            colleges.erase(colleges.begin() + ind);
            pair<QString, double> upd;
            upd.first = ui->Cart->item(i,3)->text();
            upd.second = num;
           colleges.push_back(upd);
           int savem = 0;
           if(ui->SelectedCollegesList->rowCount() != 0)
           {
           for(int m = 0; m < ui->SelectedCollegesList->rowCount(); m++)
           {
               if(ui->SelectedCollegesList->item(m,0)->text() == ui->Cart->item(i,3)->text())
                   savem = m;
           }
            col.second = ui->SelectedCollegesList->item(savem,1)->text().toDouble() + (ui->Cart->item(i, 1)->text().toDouble() * ui->Cart->item(i, 2)->text().toDouble());
            ui->SelectedCollegesList->removeRow(savem);
        }
        }
        }
        if(chk == false)
        {
            colleges.push_back(col);
        }

        chk = false;
        grandTotal += ui->Cart->item(i,1)->text().toDouble() * ui->Cart->item(i,2)->text().toDouble();
    }
    for(int i = 0; i < colleges.size(); i++)
    {
        ui->SelectedCollegesList->insertRow(ui->SelectedCollegesList->rowCount());
        ui->SelectedCollegesList->setItem(ui->SelectedCollegesList->rowCount()-1, 0, new QTableWidgetItem(colleges.at(i).first));
        ui->SelectedCollegesList->setItem(ui->SelectedCollegesList->rowCount()-1, 1, new QTableWidgetItem(QString::number(colleges.at(i).second)));
        //ui->SelectedCollegesList->addItem(colleges.at(i).first);
    }

    ui->GrandTotal->setText(QString::number(grandTotal));
}


void MainWindow::on_addStateD_2_clicked() // start Dijkstra Saddleback to all
{
    if(ui->AllSaddlebackList->count() == 0)
        return;
    vector<QString> selected;
    QString start;
    if(ui->AllSaddlebackList->count() != 0)
    {

        qWarning() << "Start of Trip Added";
        int savei = 0;
        for(int i = 0; i < ui->AllSaddlebackList->count(); i++)
        {
            if(ui->AllSaddlebackList->item(i)->text() == "Saddleback College")
            {
                start = ui->AllSaddlebackList->item(i)->text();
                savei = i;
            }
        }

       // ui->CustomTripList->currentItem()->setSelected(false);
        //ui->CustomTripList->removeItemWidget(ui->CustomTripList->currentItem());
        ui->AllSaddlebackList->item(savei)->setSelected(true);
        ui->AllSaddlebackList->item(savei)->setHidden(true);
        //ui->pushButton->setEnabled(false);
        ui->AllSaddlebackList->setSelectionMode(QAbstractItemView::MultiSelection);
        //ui->pushButton_6->setEnabled(true);
        ui->addStateD_2->setEnabled(false);
    }
//}
selected.push_back(start);

//void MainWindow::on_pushButton_6_clicked() // all from saddleback
//{
    for(int i = 0; i < TABLE_SIZE; i++)
    collegeMap.hashTable[i].select = false;
    pair<int,double> startKey;

    ui->AllSaddlebackList->selectAll();
    if(ui->AllSaddlebackList->selectedItems().size() > 1)
    {
        for(int i = 0; i < ui->AllSaddlebackList->selectedItems().size(); i++)
        {
            selected.push_back(ui->AllSaddlebackList->selectedItems().at(i)->text());
        }
        ui->AllSaddlebackList->clear();
        for(int g = 0; g < selected.size(); g++)
        {
            ui->AllSaddlebackList->addItem(selected.at(g)); //added current trip to TripList, now recursive search on selected map values

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
//        collegeMap.dijkstra(startKey);
//        ui->CustomDijkstraList->clear();
//        for(int i = 0; i < collegeMap.ans.size(); i++)
//        {
//            ui->CustomTripList->addItem(collegeMap.ans.at(i).origin/* + " -> " + collegeMap.ans.at(i).dest + " Dist: " + QString::number(collegeMap.ans.at(i).dist)*/);
//            qWarning() << collegeMap.ans.at(i).origin << " -> " << collegeMap.ans.at(i).dest;
//        }
        ui->AllSaddlebackList->setSelectionMode(QAbstractItemView::SingleSelection);
        //ui->pushButton_6->setEnabled(false);
       // selected
    }
    else
    {
        qWarning() << "None selected";
    }

//    if(ui->CustomDijkstraList->currentItem() == NULL)
//        return;
//    for(int i = 0; i < TABLE_SIZE; i++)
//    {
//        if(ui->CustomDijkstraList->currentItem()->text() == collegeMap.hashTable[i].origin)
//        {
//            startKey.first = collegeMap.hashTable[i].num;
//            startKey.second = 0;
//        }
//    }
    collegeMap.pathDists.clear();
    qWarning() << "starting Dijkstra";
    collegeMap.ans.clear();
    collegeMap.initPathDist(selected);
    collegeMap.dijkstra(startKey);
    collegeMap.numToPrint.push_back(collegeMap.pathDists.at(0).first);
    //ui->listWidget->addItem(QString::number(collegeMap.pathDists.at(0).first));
    collegeMap.pathDists.erase(collegeMap.pathDists.begin()/* + startKey.first+1*/);
    collegeMap.ans.clear();
    qWarning() << "Coll: " << collegeMap.coll << " finding the rest";
    double smallest = 9999;
    int pathIndex = 0;
    for(int i = 0; i < collegeMap.pathDists.size(); i++)
    {
        if(smallest > collegeMap.pathDists.at(i).second)
        {
            pathIndex = collegeMap.pathDists.at(i).first;
            smallest = collegeMap.pathDists.at(i).second;
        }
        //ui->listWidget->addItem(QString::number(collegeMap.pathDists.at(i).first) + "  " + QString::number(collegeMap.pathDists.at(i).second));
    }
    for(int i = 0; i < collegeMap.pathDists.size(); i++)
    {
        collegeMap.pathDists.at(i).second = INFINITY;
    }
    for(int i = 0; i < TABLE_SIZE; i++)
    {
        collegeMap.hashTable[i].visited = false;
    }
    collegeMap.dist.clear();
    collegeMap.dijkstraNext(pathIndex);

    ui->AllSaddlebackList->clear();
    bool go = true;
    double totDist = smallest;
    //int inde = 0;
    for(int i = 0; i < collegeMap.numToPrint.size(); i++)
    {
        for(int j = 0; j < TABLE_SIZE; j++)
        {
            for(int l = 0; l < ui->AllSaddlebackList->count(); l++)
            {
                if(ui->AllSaddlebackList->item(l)->text() == collegeMap.hashTable[j].origin)
                    go = false;
            }
            if(collegeMap.numToPrint.at(i) == collegeMap.hashTable[j].num && go == true)
            {
                ui->AllSaddlebackList->addItem(collegeMap.hashTable[j].origin);
            }
         go = true;
        }
    }
    for(int i = 0; i < collegeMap.dist.size(); i++)
    {
        totDist += collegeMap.dist.at(i);
    }
            ui->TotalDistSA->setText(QString::number(totDist));
   /* for(int i = 0; i < collegeMap.parent.size(); i++)*//*campuses.size()*/
    /*{
        collegeMap.pathsInAns(i);
        if(collegeMap.ans.size() > i)
        qWarning() << "num " + QString::number(i) + ": " + QString::number(collegeMap.ans.at(i).num) << " " << QString::number(collegeMap.ans.at(i).dist);
    }*/


    qWarning() << "Dijkstra complete";
}


void MainWindow::on_CustomConvert_3_clicked()
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
                 ui->AllSaddlebackList->addItem(collegeMap.getOrigin(key));
            }
            ui->CustomConvert_3->setEnabled(false);
}


void MainWindow::on_AllSaddlebackList_itemClicked(QListWidgetItem *item)
{
    if(!ui->addStateD_2->isEnabled())
    {
        ui->SaddlebackTripPrices->clear();
        ui->SaddlebackTripSouvs->clear();
       QString selected = ui->AllSaddlebackList->currentItem()->text();
       vector<Souvenir> menu;
       for(int i = 0; i < campuses.size(); i++)
       {
           if(selected == campuses.at(i).getStartCollege())
           {
              menu = campuses.at(i).getMenu();
              for(int j = 0; j < menu.size(); j++)
              {
                 ui->SaddlebackTripSouvs->addItem(menu.at(j).name);
                 ui->SaddlebackTripPrices->addItem(QString::number(menu.at(j).price));
              }
           }
       }
    }
}


void MainWindow::on_SaddlebackTripSouvs_itemClicked(QListWidgetItem *item)
{
    int row = ui->SaddlebackTripSouvs->currentRow();
    ui->SaddlebackTripPrices->setCurrentRow(row);
}


void MainWindow::on_SaddlebackTripPrices_itemClicked(QListWidgetItem *item)
{
    int row = ui->SaddlebackTripPrices->currentRow();
    ui->SaddlebackTripSouvs->setCurrentRow(row);
}


void MainWindow::on_AddToCartSA_clicked()
{
    if(ui->SaddlebackTripSouvs->selectedItems().size() != 0 && ui->spinBoxSA->text() != "0" && ui->AllSaddlebackList->selectedItems().size() != 0)
    {
        QString college = ui->AllSaddlebackList->currentItem()->text();

        QString name = ui->SaddlebackTripSouvs->currentItem()->text();

        QString price = ui->SaddlebackTripPrices->currentItem()->text();

        QString quantity = ui->spinBoxSA->text();

        QString collComp;

        bool check = false;
        int index = 0;
        if(ui->CartSaddleback->rowCount() != 0)
        {

           // QVector<QTableWidgetItem*> cartColl = ui->Cart->findItems(college, Qt::MatchFixedString);
          // QVector<QTableWidgetItem*> cartItems = ui->Cart->findItems(name, Qt::MatchFixedString);
           //for(int i = 0; i < cartItems.size(); i++)
           //{
               //collComp = cartColl.at(i)->text();
               for(int n = 0; n < ui->CartSaddleback->rowCount(); n++)
               {
                   if(ui->CartSaddleback->item(n,0)->text() == name && college == ui->CartSaddleback->item(n,3)->text())
                   {
                       index = n;
                       check = true;
                   }
               }
           // if(cartItems.at(i)->data(0).toString() == name && college == collComp)
               if(check == true)
            {
                int newquant = quantity.toInt()/* + cartItems.at(i)->data(2).toInt()*/;
                //cartItems.at(i)->data(2).setValue(newquant);

                ui->CartSaddleback->item(index,2)->setText(QString::number(newquant));
                //qWarning() << name;
                //check = true;
            }
           //}
        }
        if(check == false)
        {
            ui->CartSaddleback->insertRow(ui->CartSaddleback->rowCount());

            ui->CartSaddleback->setItem(ui->CartSaddleback->rowCount()-1, 0, new QTableWidgetItem(name));

            ui->CartSaddleback->setItem(ui->CartSaddleback->rowCount()-1, 1, new QTableWidgetItem(price));

            ui->CartSaddleback->setItem(ui->CartSaddleback->rowCount()-1, 2, new QTableWidgetItem(quantity));

            ui->CartSaddleback->setItem(ui->CartSaddleback->rowCount()-1, 3, new QTableWidgetItem(college));
        }
    }
}


void MainWindow::on_SaddlbackFinish_clicked()
{
    double grandTotal = 0;
    bool chk = false;
    int ind = 0;
    vector<pair<QString,double>> colleges;
    for(int i = 0; i < ui->CartSaddleback->rowCount(); i++)
    {
        pair<QString,double> col;
        col.first = ui->CartSaddleback->item(i,3)->text();
        double number = (ui->CartSaddleback->item(i, 1)->text().toDouble() * ui->CartSaddleback->item(i, 2)->text().toDouble());
        col.second = number;
        if(!colleges.empty())
        {
            //colleges.push_back(col);

        //else{


        for(int j = 0; j < colleges.size(); j++)
        {
            if(colleges.at(j).first == col.first)
            {
                ind = j;
                chk = true;
            }

        }

        if(chk == true)
        {
            double num = colleges.at(ind).second + (ui->CartSaddleback->item(i, 1)->text().toDouble() * ui->CartSaddleback->item(i, 2)->text().toDouble());
            colleges.at(ind).second = num;
            colleges.erase(colleges.begin() + ind);
            pair<QString, double> upd;
            upd.first = ui->CartSaddleback->item(i,3)->text();
            upd.second = num;
           colleges.push_back(upd);
           int savem = 0;
           if(ui->SelectedCollegesList_2->rowCount() != 0)
           {
           for(int m = 0; m < ui->SelectedCollegesList_2->rowCount(); m++)
           {
               if(ui->SelectedCollegesList_2->item(m,0)->text() == ui->CartSaddleback->item(i,3)->text())
                   savem = m;
           }
            col.second = ui->SelectedCollegesList_2->item(savem,1)->text().toDouble() + (ui->CartSaddleback->item(i, 1)->text().toDouble() * ui->CartSaddleback->item(i, 2)->text().toDouble());
            ui->SelectedCollegesList_2->removeRow(savem);
        }
        }
        }
        if(chk == false)
        {
            colleges.push_back(col);
        }

        chk = false;
        grandTotal += ui->CartSaddleback->item(i,1)->text().toDouble() * ui->CartSaddleback->item(i,2)->text().toDouble();
    }
    for(int i = 0; i < colleges.size(); i++)
    {
        ui->SelectedCollegesList_2->insertRow(ui->SelectedCollegesList_2->rowCount());
        ui->SelectedCollegesList_2->setItem(ui->SelectedCollegesList_2->rowCount()-1, 0, new QTableWidgetItem(colleges.at(i).first));
        ui->SelectedCollegesList_2->setItem(ui->SelectedCollegesList_2->rowCount()-1, 1, new QTableWidgetItem(QString::number(colleges.at(i).second)));
        //ui->SelectedCollegesList->addItem(colleges.at(i).first);
    }

    ui->GrandTotalSA->setText(QString::number(grandTotal));
}


void MainWindow::on_actionAll_from_Saddleback_triggered()
{
    ui->tabWidget->setCurrentIndex(3);
}


void MainWindow::on_StartMich_clicked() //start Michigan Dijkstra path
{
    if(ui->MichSpecificList->count() == 0)
        return;
    if(ui->MichSpecificList->selectedItems().count() == 0)
        return;
    QString end = ui->MichSpecificList->currentItem()->text();
    ui->MichSpecificList->currentItem()->setSelected(false);
    int endNum = 0;
    vector<QString> selected;
    QString start;
    int savei = 0;
    for(int i = 0; i < TABLE_SIZE; i++)
    {
        if(end == collegeMap.hashTable[i].origin)
            endNum = collegeMap.hashTable[i].num;
    }
    if(ui->MichSpecificList->count() != 0)
    {

        qWarning() << "Start of Trip Added";

        for(int i = 0; i < ui->MichSpecificList->count(); i++)
        {
            if(ui->MichSpecificList->item(i)->text() == "University of  Michigan") //test space or not
            {
                start = ui->MichSpecificList->item(i)->text();
                savei = i;
            }
        }

        ui->MichSpecificList->item(savei)->setSelected(false);
        ui->MichSpecificList->item(savei)->setHidden(true);

        ui->MichSpecificList->setSelectionMode(QAbstractItemView::MultiSelection);
        //ui->pushButton_6->setEnabled(true);
        ui->StartMich->setEnabled(false);
    }

selected.push_back(start);

    for(int i = 0; i < TABLE_SIZE; i++)
    {
        collegeMap.hashTable[i].select = false;
        collegeMap.hashTable[i].visited = false;
    }
    pair<int,double> startKey;

    //ui->MichSpecificList->clearSelection();
    ui->MichSpecificList->selectAll();
   // QListWidget* pointer = ui->MichSpecificList;
   // pointer->selectAll();
//    for(int n = 0; n < ui->MichSpecificList->count(); n++)
//    {
//        ui->MichSpecificList->item(n)->setSelected(true);
//    }
    if(ui->MichSpecificList->selectedItems().count() > 1)
    {
        for(int i = 0; i < ui->MichSpecificList->selectedItems().count(); i++)
        {
            selected.push_back(ui->MichSpecificList->selectedItems().at(i)->text());
        }
        ui->MichSpecificList->clear();
        for(int g = 0; g < selected.size(); g++)
        {
            ui->MichSpecificList->addItem(selected.at(g)); //added current trip to TripList, now recursive search on selected map values

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

        ui->MichSpecificList->setSelectionMode(QAbstractItemView::SingleSelection);
        ui->StartMich->setEnabled(false);
       // selected
    }
    else
    {
        qWarning() << "None selected";
    }
    startKey.first = savei;
    collegeMap.pathDists.clear();
    qWarning() << "starting Dijkstra";
    collegeMap.ans.clear();
    collegeMap.initPathDist(selected);
    collegeMap.dijkstra(startKey);
    collegeMap.ans.clear();
    int endInd = 0;
    for(int i = 0; i < collegeMap.parent.size(); i++)
    {
        if(collegeMap.pathDists.at(i).first == endNum)
            endInd = i;
    }
    HashStruct endd;
    endd.num = endInd;
    collegeMap.ans.push_back(endd);
    collegeMap.pathsInAns(endInd); //path from choice
    //collegeMap.numToPrint.push_back(collegeMap.pathDists.at(0).first);

    qWarning() << "Coll: " << collegeMap.coll;

    ui->MichSpecificList->clear();
    bool go = true;
    double totDist = 0;
    //int inde = 0;
    //for(int i = 0; i < collegeMap.numToPrint.size(); i++)
    //{
//        for(int j = 0; j < TABLE_SIZE; j++)
//        {
//            for(int l = 0; l < ui->MichSpecificList->count(); l++)
//            {
//                if(ui->MichSpecificList->item(l)->text() == collegeMap.hashTable[j].origin)
//                    go = false;
//            }
//            if(collegeMap.numToPrint.at(i) == collegeMap.hashTable[j].num && go == true)
//            {
//                ui->MichSpecificList->addItem(collegeMap.hashTable[j].origin);
//            }
//         go = true;
//        }
//    }

    for(int i = 0; i < collegeMap.ans.size(); i++)
    {
        for(int j = 0; j < selected.size(); j++)
        {
            bool checked = false;
            /*for(int l = 0; l < ui->SelectedCollegesList_3->rowCount(); l++)
            {
                if(ui->SelectedCollegesList_3->item(l,0)->text() == ui->SelectedCollegesList_3->item(j,0)->text())
                    checked = true;
            }*/
            if(j == collegeMap.ans.at(i).num && checked == false)
            {
                ui->MichSpecificList->addItem(selected.at(j));
                //QTableWidgetItem* ansNew = new QTableWidgetItem;
                //ansNew->setData(0,);
                //ui->SelectedCollegesList_3->setItem(ui->SelectedCollegesList_3->rowCount()-1, 0, ansNew);
//                ui->SelectedCollegesList_3->insertRow(ui->SelectedCollegesList_3->rowCount());
//                QTableWidgetItem* ansNew = new QTableWidgetItem;
//                ansNew->setData(0,selected.at(j));
//                ui->SelectedCollegesList_3->setItem(ui->SelectedCollegesList_3->rowCount()-1, 0, ansNew);
            }
        }

    }
    //int Index = 0;
   // int Index2 = 0;
    bool ck = false;
    vector<QString> destin;
    for(int i = 0; i < ui->MichSpecificList->count(); i++)
    {
        for(int j = 0; j < TABLE_SIZE; j++)
        {
             if(!destin.empty())
             {
            for(int n = 0; n < destin.size(); n++)
            {
                if(destin.at(destin.size()-1) == collegeMap.hashTable[j].dest && collegeMap.hashTable[j].origin == ui->MichSpecificList->item(i)->text())
                    ck = true;
            }
            if(collegeMap.hashTable[j].origin == ui->MichSpecificList->item(i)->text() && ck == true && destin.at(destin.size()-1) == collegeMap.hashTable[j].dest)
            {
                totDist += collegeMap.hashTable[j].dist;
                destin.push_back(collegeMap.hashTable[j].dest);
            }
             }
             else{
                 destin.push_back(ui->MichSpecificList->item(i)->text());
             }

        }
    }
    ui->TotalDistM->setText(QString::number(totDist));

    /*for(int i = 0; i < collegeMap.ans.size(); i++)
    {
        ui->SelectedCollegesList_3->insertRow(ui->SelectedCollegesList_3->rowCount());
        QTableWidgetItem* ansNew = new QTableWidgetItem;
        ansNew->setData(0,QString::number(collegeMap.ans.at(i).num));
        ui->SelectedCollegesList_3->setItem(ui->SelectedCollegesList_3->rowCount()-1, 0, ansNew);

    }
    ui->SelectedCollegesList_3->insertRow(ui->SelectedCollegesList_3->rowCount());
    QTableWidgetItem* ansNewEnd = new QTableWidgetItem;
    ansNewEnd->setData(0,QString::number(endNum));
    ui->SelectedCollegesList_3->setItem(ui->SelectedCollegesList_3->rowCount()-1, 0, ansNewEnd);*/
    /*for(int i = 0; i < TABLE_SIZE; i++)
    {
        if(collegeMap.hashTable[i].num == ui->SelectedCollegesList_3->item(0,0)->text().toInt() && ui->SelectedCollegesList_3->item(1,0)->text().toInt() == collegeMap.hashTable[i].dist)
        totDist += collegeMap.dist.at(i);
    }
            ui->TotalDistM->setText(QString::number(totDist));
*/

    qWarning() << "Dijkstra complete";
}



void MainWindow::on_CustomConvert_4_clicked()
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
                 ui->MichSpecificList->addItem(collegeMap.getOrigin(key));
            }
            ui->CustomConvert_4->setEnabled(false);
}


void MainWindow::on_MichTripSouvs_itemClicked(QListWidgetItem *item)
{
        int row = ui->MichTripSouvs->currentRow();
        ui->MichTripPrices->setCurrentRow(row);
}



void MainWindow::on_MichTripPrices_itemClicked(QListWidgetItem *item)
{
        int row = ui->MichTripPrices->currentRow();
        ui->MichTripSouvs->setCurrentRow(row);
}


void MainWindow::on_AddToCartM_clicked()
{
    if(ui->MichTripSouvs->selectedItems().size() != 0 && ui->spinBoxM->text() != "0" && ui->MichSpecificList->selectedItems().size() != 0)
    {
        QString college = ui->MichSpecificList->currentItem()->text();

        QString name = ui->MichTripSouvs->currentItem()->text();

        QString price = ui->MichTripPrices->currentItem()->text();

        QString quantity = ui->spinBoxM->text();

        QString collComp;

        bool check = false;
        int index = 0;
        if(ui->CartMich->rowCount() != 0)
        {

           // QVector<QTableWidgetItem*> cartColl = ui->Cart->findItems(college, Qt::MatchFixedString);
          // QVector<QTableWidgetItem*> cartItems = ui->Cart->findItems(name, Qt::MatchFixedString);
           //for(int i = 0; i < cartItems.size(); i++)
           //{
               //collComp = cartColl.at(i)->text();
               for(int n = 0; n < ui->CartMich->rowCount(); n++)
               {
                   if(ui->CartMich->item(n,0)->text() == name && college == ui->CartMich->item(n,3)->text())
                   {
                       index = n;
                       check = true;
                   }
               }
           // if(cartItems.at(i)->data(0).toString() == name && college == collComp)
               if(check == true)
            {
                int newquant = quantity.toInt()/* + cartItems.at(i)->data(2).toInt()*/;
                //cartItems.at(i)->data(2).setValue(newquant);

                ui->CartMich->item(index,2)->setText(QString::number(newquant));
                //qWarning() << name;
                //check = true;
            }
           //}
        }
        if(check == false)
        {
            ui->CartMich->insertRow(ui->CartMich->rowCount());

            ui->CartMich->setItem(ui->CartMich->rowCount()-1, 0, new QTableWidgetItem(name));

            ui->CartMich->setItem(ui->CartMich->rowCount()-1, 1, new QTableWidgetItem(price));

            ui->CartMich->setItem(ui->CartMich->rowCount()-1, 2, new QTableWidgetItem(quantity));

            ui->CartMich->setItem(ui->CartMich->rowCount()-1, 3, new QTableWidgetItem(college));
        }
    }
}


void MainWindow::on_MichSpecificList_itemClicked(QListWidgetItem *item)
{

    if(!ui->StartMich->isEnabled())
    {
        ui->MichSpecificList->setSelectionMode(QAbstractItemView::SingleSelection);
        ui->MichTripPrices->clear();
        ui->MichTripSouvs->clear();
       QString selected = ui->MichSpecificList->currentItem()->text();
       vector<Souvenir> menu;
       for(int i = 0; i < campuses.size(); i++)
       {
           if(selected == campuses.at(i).getStartCollege())
           {
              menu = campuses.at(i).getMenu();
              for(int j = 0; j < menu.size(); j++)
              {
                 ui->MichTripSouvs->addItem(menu.at(j).name);
                 ui->MichTripPrices->addItem(QString::number(menu.at(j).price));
              }
           }
       }
    }
}


void MainWindow::on_MichFinish_clicked()
{
    double grandTotal = 0;
    bool chk = false;
    int ind = 0;
    vector<pair<QString,double>> colleges;
    for(int i = 0; i < ui->CartMich->rowCount(); i++)
    {
        pair<QString,double> col;
        col.first = ui->CartMich->item(i,3)->text();
        double number = (ui->CartMich->item(i, 1)->text().toDouble() * ui->CartMich->item(i, 2)->text().toDouble());
        col.second = number;
        if(!colleges.empty())
        {
            //colleges.push_back(col);

        //else{


        for(int j = 0; j < colleges.size(); j++)
        {
            if(colleges.at(j).first == col.first)
            {
                ind = j;
                chk = true;
            }

        }

        if(chk == true)
        {
            double num = colleges.at(ind).second + (ui->CartMich->item(i, 1)->text().toDouble() * ui->CartMich->item(i, 2)->text().toDouble());
            colleges.at(ind).second = num;
            colleges.erase(colleges.begin() + ind);
            pair<QString, double> upd;
            upd.first = ui->CartMich->item(i,3)->text();
            upd.second = num;
           colleges.push_back(upd);
           int savem = 0;
           if(ui->SelectedCollegesList_3->rowCount() != 0)
           {
           for(int m = 0; m < ui->SelectedCollegesList_3->rowCount(); m++)
           {
               if(ui->SelectedCollegesList_3->item(m,0)->text() == ui->CartMich->item(i,3)->text())
                   savem = m;
           }
            col.second = ui->SelectedCollegesList_3->item(savem,1)->text().toDouble() + (ui->CartMich->item(i, 1)->text().toDouble() * ui->CartMich->item(i, 2)->text().toDouble());
            ui->SelectedCollegesList_3->removeRow(savem);
        }
        }
        }
        if(chk == false)
        {
            colleges.push_back(col);
        }

        chk = false;
        grandTotal += ui->CartMich->item(i,1)->text().toDouble() * ui->CartMich->item(i,2)->text().toDouble();
    }
    for(int i = 0; i < colleges.size(); i++)
    {
        ui->SelectedCollegesList_3->insertRow(ui->SelectedCollegesList_3->rowCount());
        ui->SelectedCollegesList_3->setItem(ui->SelectedCollegesList_3->rowCount()-1, 0, new QTableWidgetItem(colleges.at(i).first));
        ui->SelectedCollegesList_3->setItem(ui->SelectedCollegesList_3->rowCount()-1, 1, new QTableWidgetItem(QString::number(colleges.at(i).second)));
        //ui->SelectedCollegesList->addItem(colleges.at(i).first);
    }

    ui->GrandTotalM->setText(QString::number(grandTotal));
}

