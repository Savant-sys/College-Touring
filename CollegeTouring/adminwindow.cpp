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

    QString name = ui->NewName->text();
    QString price = ui->NewPrice->text();

//    QTableWidgetItem *souvenirs = new QTableWidgetItem(tr("name"));
//    souvenirs->setText(name);

    int collegeNum = ui->CollegeList->currentRow();
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
    int CollegeNum = ui->CollegeList->currentRow();
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
    ui->PriceList->setCurrentRow(ui->SouvenirList->currentRow());
    QString price = ui->NewPrice->text();
    QString souvenirToEdit = ui->SouvenirList->currentItem()->text();
    QString currCollege = ui->CollegeList->currentItem()->text();
    int collegeNum = ui->CollegeList->currentRow();

    qWarning() << "campuses" << this->campuses.at(collegeNum).getStartCollege() << "campuses" << campuses.at(collegeNum).getMenu().at(ui->SouvenirList->currentRow()).price;
    vector<Souvenir> currSouvenirs = this->campuses.at(collegeNum).getMenu();
    Souvenir newSouvenir;
    newSouvenir.name = ui->SouvenirList->currentItem()->text();
    newSouvenir.price = price.toDouble();
    //currSouvenirs.push_back(newSouvenir);
    //currSouvenirs.swap()
    currSouvenirs.at(ui->SouvenirList->currentRow()).price = price.toDouble();
    qWarning() << "price" << currSouvenirs.at(ui->SouvenirList->currentRow()).price;
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

