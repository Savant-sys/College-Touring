#include "adminwindow.h"
#include "ui_adminwindow.h"

AdminWindow::AdminWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminWindow)
{
    ui->setupUi(this);
    connect(this,SIGNAL(showMain()), parent, SLOT(show()));
    connect(this,SIGNAL(showMain()), parent, SLOT(Update()));

    //ui->NewName->setVisible(false);
    //ui->NewPrice->setVisible(false);

    if(db.getCampuses(this->campuses))
        qInfo() << "Got all campuses list";

    QListWidget *campusList = ui->CollegeList;

    for (int i =0; i < this->campuses.size(); i++)
    {
        campusList->addItem(campuses.at(i).getStartCollege());
//        CampusWidget *campusItem = new CampusWidget(campuses[i], this->parentWidget());
//        QListWidgetItem *item = new QListWidgetItem(campusList);
//        campusList->addItem(item);
//        item->setSizeHint(campusItem->minimumSizeHint());
//        campusList->setItemWidget(item, campusItem);
    }
    ui->CollegeList->setCurrentRow(0);
    on_CollegeList_itemClicked(ui->CollegeList->currentItem());

}

AdminWindow::~AdminWindow()
{
    delete ui;
}

void AdminWindow::on_pushButton_4_clicked()
{
    hide();
    emit showMain();
}


void AdminWindow::on_CollegeList_itemClicked(QListWidgetItem *item)
{
    ui->SouvenirList->clear();
    ui->PriceList->clear();

        for(int j = 0; j < this->campuses.at(ui->CollegeList->currentRow()).getMenu().size(); j++)
        {
//            QTableWidgetItem *souvenir1 = new QTableWidgetItem(tr("name"));
            QString name = this->campuses.at(ui->CollegeList->currentRow()).getMenu().at(j).name;
//            souvenir1->setText(name);
//            if(ui->SouvenirList->rowCount() <= j)
//            ui->SouvenirList->insertRow(j);
            ui->SouvenirList->addItem(name);
//            ui->SouvenirList->setItem(j,0, souvenir1);
//            souvenir1 = nullptr;

//            QTableWidgetItem *souvenirPrice = new QTableWidgetItem(tr("price"));
            QString price = QString::number(this->campuses.at(ui->CollegeList->currentRow()).getMenu().at(j).price);
//            souvenirPrice->setText(price);
            ui->PriceList->addItem(price);
//            ui->SouvenirList->setItem(j,1, souvenirPrice);
//            souvenirPrice = nullptr;
        }
//        while(this->campuses.at(ui->CollegeList->currentRow()).getMenu().size() < ui->SouvenirList->rowCount())
//        {
//            ui->SouvenirList->removeRow(ui->SouvenirList->rowCount()-1);
//        }

}


void AdminWindow::on_Add_clicked()
{
    int collegeNum = ui->CollegeList->currentRow();
    if(this->campuses.at(collegeNum).getMenu().size() >= 7)
    {
        qWarning() << "Already 7 items, can not exceed max";
        return;
    }
    QString name = ui->NewName->text();
    QString price = ui->NewPrice->text();
    if(name == "" || price == "" || price == " " || name == " ")
    {
        qWarning() << "empty field";
        return;
    }
    int decimal = 0;
    if(price.contains('.'))
    {
    for(int i = 0; i < price.size(); i++)
    {
        if(price[i].isDigit() == false)
        {
            decimal++;
        }
        if(price[i].isSpace() || price[i].isLetter() || price[i].isSymbol() || price.isEmpty())
        {
            qWarning() << "incorrect entry in price field";
            return;
        }
    }
    if(decimal > 1)
    {
        qWarning() << "incorrect entry in price field (noDigit)";
        return;
    }
    }
    else
    {
        qWarning() << "no Decimal";
        return;
    }
//    if(price[0].isLetter() || price[0].isSymbol())
//    {
//        qWarning() << "price can not be text";
//        return;
//    }
//    if(name[0].isNumber() || name[0].isSymbol())
//    {
//        qWarning() << "Name can not be number";
//        return;
//    }
    int Space = 0;
    for(int i = 0; i < name.size(); i++)
    {
        if(name[i].isLetter() == false)
        {
            if(name[i].isSpace() == false)
            {
                qWarning() << "incorrect entry";
                return;
            }
            Space++;
        }
//        if(name[i].isDigit() || name.isEmpty() || name[i].isSymbol() ||name[i].isMark())
//        {
//            qWarning() << "incorrect entry in name field";
//            return;
//        }
    }
    if(Space > 1)
    {
        qWarning() << "incorrect entry in name field (Spaces)";
        return;
    }

//    QTableWidgetItem *souvenirs = new QTableWidgetItem(tr("name"));
//    souvenirs->setText(name);


    //int souvenirNum = ui->SouvenirList->currentRow();
qWarning() << "campuses" << this->campuses.at(collegeNum).getStartCollege() << "campuses" << campuses.at(collegeNum).getMenu().size();
vector<Souvenir> currSouvenirs = this->campuses.at(collegeNum).getMenu();
    Souvenir newSouvenir;
    newSouvenir.name = name;
    newSouvenir.price = price.toDouble();
    currSouvenirs.push_back(newSouvenir);
    this->campuses.at(collegeNum).setMenu(currSouvenirs);
    ui->SouvenirList->addItem(name);
    ui->PriceList->addItem(price);
    //qWarning() << "rowcount" << ui->SouvenirList->count();
    //ui->SouvenirList->insertRow(ui->SouvenirList->rowCount()+1);
    //qWarning() << "rowcount" << ui->SouvenirList->rowCount();
   // ui->SouvenirList->setItem(ui->SouvenirList->rowCount(),0, souvenirs);
    //QTableWidgetItem *souvenirs2 = new QTableWidgetItem(tr("price"));
    //souvenirs2->setText(price);
    //ui->SouvenirList->setItem(ui->SouvenirList->rowCount(),1,souvenirs2);

    qWarning() << "campuses" << this->campuses.at(collegeNum).getStartCollege() << "campuses" << campuses.at(collegeNum).getMenu().size();
    db.modifySouvenir(campuses.at(collegeNum), currSouvenirs);
   /*
    const QString DRIVER("QSQLITE");
    if (QSqlDatabase::isDriverAvailable(DRIVER))
       {QSqlDatabase db = QSqlDatabase::addDatabase(DRIVER);
        QDir::setCurrent(QCoreApplication::applicationDirPath());
        QDir tempDir = QDir::currentPath();
        qDebug() << tempDir;
        tempDir.cdUp();
        tempDir.cdUp();

        QString s = tempDir.path() + "/db";

        QDir::setCurrent(s);

    QString dbPath = s + "/CollegeTouring.db";
    db.setDatabaseName(dbPath);
    db.open();
vector<Souvenir> souvenirs;
for(int i = 0; i < campuses.at(collegeNum).getMenu().size(); i++)
{
    souvenirs.push_back(campuses.at(collegeNum).getMenu().at(i));
}
     QSqlQuery qry(db);

    QString stringQry = "UPDATE campuses SET souvenirs = '" + souvenirs + "' WHERE Starting College = '" + ui->CollegeList->currentItem()->text() + "';
    qry.prepare(stringQry);
    if(!qry.exec(stringQry))
        qWarning() << "ERROR: UPDATING menu" << qry.lastError().text();

db.close();
QString connectionName = db.connectionName();
db = QSqlDatabase();
QSqlDatabase::removeDatabase(connectionName);
       }
*/

}


void AdminWindow::on_Remove_clicked()
{
    if(ui->SouvenirList->currentItem() == nullptr)
    {
        qWarning() << "No item selected";
        return;
//        ui->SouvenirList->setCurrentRow(0);
//        ui->PriceList->setCurrentRow(0);
    }

    int CollegeNum = ui->CollegeList->currentRow();
    if(campuses.at(CollegeNum).getMenu().size() < 1)
    {
        qWarning() << "No more items in list";
        return;
    }
    qWarning() << "campuses" << campuses.at(CollegeNum).getMenu().size();
    vector<Souvenir> currSouvenirs = this->campuses.at(CollegeNum).getMenu();
    //currSouvenirs.at(ui->SouvenirList->currentRow());
    qWarning() << "vector" << currSouvenirs.size();
    currSouvenirs.erase(currSouvenirs.begin() + ui->SouvenirList->currentRow());
    qWarning() << "vector" << currSouvenirs.size();
    //campuses.
    this->campuses.at(CollegeNum).setMenu(currSouvenirs);
    ui->SouvenirList->removeItemWidget(ui->SouvenirList->currentItem());
    int currRow = ui->SouvenirList->currentRow();
    ui->PriceList->setCurrentRow(currRow);
    ui->PriceList->removeItemWidget(ui->PriceList->currentItem());
    ui->SouvenirList->currentItem()->setHidden(true);
    ui->SouvenirList->currentItem()->setText("");
    ui->PriceList->currentItem()->setHidden(true);
    ui->PriceList->currentItem()->setText("");
    db.modifySouvenir(campuses.at(CollegeNum), currSouvenirs);
    qWarning() << "campuses" << this->campuses.at(CollegeNum).getMenu().size();
}


void AdminWindow::on_Change_clicked()
{
    if(ui->SouvenirList->currentItem() == nullptr)
    {
        ui->SouvenirList->setCurrentRow(0);
        ui->PriceList->setCurrentRow(0);
    }
    ui->PriceList->setCurrentRow(ui->SouvenirList->currentRow());

    QString price = ui->NewPrice->text();
    QString souvenirToEdit = ui->SouvenirList->currentItem()->text();
    QString currCollege = ui->CollegeList->currentItem()->text();
    int collegeNum = ui->CollegeList->currentRow();

    if(price == "" || price == " ")
    {
        qWarning() << "empty field";
        return;
    }
    int decimal = 0;

        if(price.contains('.'))
        {
    for(int i = 0; i < price.size(); i++)
    {
        if(price[i].isDigit() == false)
        {
            decimal++;

        }
        if(price[i].isSpace() || price[i].isLetter() || price[i].isSymbol() || price.isEmpty())
        {
            qWarning() << "incorrect entry in price field";
            return;
        }
    }
    if(decimal > 1)
    {
        qWarning() << "incorrect entry in price field (noDigit)";
        return;
    }
        }
        else{
            qWarning() << "no Decimal";
            return;
        }

    qWarning() << "campuses" << this->campuses.at(collegeNum).getStartCollege() << "campuses" << campuses.at(collegeNum).getMenu().at(ui->SouvenirList->currentRow()).price;
    vector<Souvenir> currSouvenirs = this->campuses.at(collegeNum).getMenu();
    Souvenir newSouvenir;
    newSouvenir.name = ui->SouvenirList->currentItem()->text();
    newSouvenir.price = price.toDouble();
    //currSouvenirs.push_back(newSouvenir);
    //currSouvenirs.swap()
    currSouvenirs.at(ui->SouvenirList->currentRow()).price = price.toDouble();
    qWarning() << "price" << currSouvenirs.at(ui->SouvenirList->currentRow()).price << "NUM" << collegeNum;
    this->campuses.at(collegeNum).setMenu(currSouvenirs);
    //ui->SouvenirList->addItem(name);
    //ui->PriceList->addItem(price);
    ui->PriceList->currentItem()->setText(price);
    db.modifySouvenir(campuses.at(collegeNum), currSouvenirs);

}


void AdminWindow::on_PriceList_itemClicked(QListWidgetItem *item)
{
    ui->SouvenirList->setCurrentRow(ui->PriceList->currentRow());
}


void AdminWindow::on_SouvenirList_itemClicked(QListWidgetItem *item)
{
    ui->PriceList->setCurrentRow(ui->SouvenirList->currentRow());
}

