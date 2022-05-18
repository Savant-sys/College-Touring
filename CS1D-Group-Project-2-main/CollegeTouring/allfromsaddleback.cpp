#include "allfromsaddleback.h"
#include "ui_allfromsaddleback.h"

Allfromsaddleback::Allfromsaddleback(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Allfromsaddleback)
{
    ui->setupUi(this);
    connect(this,SIGNAL(getEndCollegesFromSaddleback()), parent, SLOT(getEndCollegesFromSaddleback()));
    connect(this,SIGNAL(getDistancesFromSaddleback()), parent, SLOT(getDistancesFromSaddleback()));
    print();
}

Allfromsaddleback::~Allfromsaddleback()
{
    delete ui;
}

void Allfromsaddleback::print()
{
    QTableWidgetItem* temp;
    endColleges = getEndCollegesFromSaddleback();
    distances = getDistancesFromSaddleback();
    this->ui->saddlebackTable->setRowCount(endColleges.size());

    ui->saddlebackTable->setColumnWidth(0, 150);
    ui->saddlebackTable->setColumnWidth(1, 250);
    ui->saddlebackTable->setColumnWidth(2, 90);

    for (int i = 0; i < endColleges.size(); i++)
    {
        temp = new QTableWidgetItem;
        temp->setText("Saddleback College");
        this->ui->saddlebackTable->setItem(i,0,temp);

        temp = new QTableWidgetItem;
        temp->setText(endColleges[i]);
        this->ui->saddlebackTable->setItem(i,1,temp);

        temp = new QTableWidgetItem;
        temp->setText(QString::number(distances[i]));
        this->ui->saddlebackTable->setItem(i,2,temp);
    }
}
