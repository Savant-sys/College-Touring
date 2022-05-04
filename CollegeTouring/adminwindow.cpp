#include "adminwindow.h"
#include "ui_adminwindow.h"

AdminWindow::AdminWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminWindow)
{
    ui->setupUi(this);
    connect(this,SIGNAL(showMain()), parent, SLOT(show()));
    connect(this,SIGNAL(showMain()), parent, SLOT(Update()));

    ui->NewPrice->setValidator(new QDoubleValidator(0,100,2,this));

    if(db.getCampuses(this->campuses))
        qInfo() << "Got all campuses list";

    QListWidget *campusList = ui->CollegeList;

    for (int i = 0; i < this->campuses.size(); i++)
    {
        campusList->addItem(campuses.at(i).getStartCollege());

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

            QString name = this->campuses.at(ui->CollegeList->currentRow()).getMenu().at(j).name;

            ui->SouvenirList->addItem(name);

            QString price = QString::number(this->campuses.at(ui->CollegeList->currentRow()).getMenu().at(j).price);

            ui->PriceList->addItem(price);
        }
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
    }
    if(Space > 1)
    {
        qWarning() << "incorrect entry in name field (Spaces)";
        return;
    }

qWarning() << "campuses" << this->campuses.at(collegeNum).getStartCollege() << "campuses" << campuses.at(collegeNum).getMenu().size();
vector<Souvenir> currSouvenirs = this->campuses.at(collegeNum).getMenu();
    Souvenir newSouvenir;
    newSouvenir.name = name;
    newSouvenir.price = price.toDouble();
    currSouvenirs.push_back(newSouvenir);
    this->campuses.at(collegeNum).setMenu(currSouvenirs);
    ui->SouvenirList->addItem(name);
    ui->PriceList->addItem(price);

    qWarning() << "campuses" << this->campuses.at(collegeNum).getStartCollege() << "campuses" << campuses.at(collegeNum).getMenu().size();
    db.modifySouvenir(campuses.at(collegeNum), currSouvenirs);

}


void AdminWindow::on_Remove_clicked()
{
    if(ui->SouvenirList->currentItem() == nullptr)
    {
        qWarning() << "No item selected";
        return;

    }

    int CollegeNum = ui->CollegeList->currentRow();
    if(campuses.at(CollegeNum).getMenu().size() < 1)
    {
        qWarning() << "No more items in list";
        return;
    }
    qWarning() << "campuses" << campuses.at(CollegeNum).getMenu().size();
    vector<Souvenir> currSouvenirs = this->campuses.at(CollegeNum).getMenu();
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

    //db.updateSouv(campuses.at(CollegeNum), currSouvenirs);
    //db.modifySouvenir(campuses.at(CollegeNum), currSouvenirs);
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

    currSouvenirs.at(ui->SouvenirList->currentRow()).price = price.toDouble();
    qWarning() << "price" << currSouvenirs.at(ui->SouvenirList->currentRow()).price << "NUM" << collegeNum;
    this->campuses.at(collegeNum).setMenu(currSouvenirs);

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

