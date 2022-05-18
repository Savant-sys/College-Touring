/********************************************************************************
** Form generated from reading UI file 'allfromsaddleback.ui'
**
** Created by: Qt User Interface Compiler version 6.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ALLFROMSADDLEBACK_H
#define UI_ALLFROMSADDLEBACK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_Allfromsaddleback
{
public:
    QGridLayout *gridLayout;
    QTableWidget *saddlebackTable;

    void setupUi(QDialog *Allfromsaddleback)
    {
        if (Allfromsaddleback->objectName().isEmpty())
            Allfromsaddleback->setObjectName(QString::fromUtf8("Allfromsaddleback"));
        Allfromsaddleback->resize(543, 418);
        gridLayout = new QGridLayout(Allfromsaddleback);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        saddlebackTable = new QTableWidget(Allfromsaddleback);
        if (saddlebackTable->columnCount() < 3)
            saddlebackTable->setColumnCount(3);
        QFont font;
        font.setBold(true);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font);
        saddlebackTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font);
        saddlebackTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font);
        saddlebackTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        saddlebackTable->setObjectName(QString::fromUtf8("saddlebackTable"));

        gridLayout->addWidget(saddlebackTable, 0, 0, 1, 1);


        retranslateUi(Allfromsaddleback);

        QMetaObject::connectSlotsByName(Allfromsaddleback);
    } // setupUi

    void retranslateUi(QDialog *Allfromsaddleback)
    {
        Allfromsaddleback->setWindowTitle(QCoreApplication::translate("Allfromsaddleback", "Dialog", nullptr));
        QTableWidgetItem *___qtablewidgetitem = saddlebackTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("Allfromsaddleback", "From Starting College", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = saddlebackTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("Allfromsaddleback", "To Ending Colleges", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = saddlebackTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("Allfromsaddleback", "Distances", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Allfromsaddleback: public Ui_Allfromsaddleback {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALLFROMSADDLEBACK_H
