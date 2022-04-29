/********************************************************************************
** Form generated from reading UI file 'adminwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINWINDOW_H
#define UI_ADMINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdminWindow
{
public:
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton_4;
    QLineEdit *NewName;
    QLineEdit *NewPrice;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QPushButton *Add;
    QPushButton *Remove;
    QPushButton *Change;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QListWidget *CollegeList;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_4;
    QListWidget *SouvenirList;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_5;
    QListWidget *PriceList;

    void setupUi(QDialog *AdminWindow)
    {
        if (AdminWindow->objectName().isEmpty())
            AdminWindow->setObjectName(QString::fromUtf8("AdminWindow"));
        AdminWindow->resize(733, 598);
        label = new QLabel(AdminWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(300, 10, 131, 41));
        label_2 = new QLabel(AdminWindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(250, 50, 241, 71));
        pushButton_4 = new QPushButton(AdminWindow);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(630, 550, 80, 22));
        NewName = new QLineEdit(AdminWindow);
        NewName->setObjectName(QString::fromUtf8("NewName"));
        NewName->setGeometry(QRect(500, 220, 113, 21));
        NewName->setEchoMode(QLineEdit::Normal);
        NewPrice = new QLineEdit(AdminWindow);
        NewPrice->setObjectName(QString::fromUtf8("NewPrice"));
        NewPrice->setGeometry(QRect(500, 250, 113, 21));
        widget = new QWidget(AdminWindow);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(510, 120, 101, 80));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        Add = new QPushButton(widget);
        Add->setObjectName(QString::fromUtf8("Add"));

        verticalLayout->addWidget(Add);

        Remove = new QPushButton(widget);
        Remove->setObjectName(QString::fromUtf8("Remove"));

        verticalLayout->addWidget(Remove);

        Change = new QPushButton(widget);
        Change->setObjectName(QString::fromUtf8("Change"));

        verticalLayout->addWidget(Change);

        widget1 = new QWidget(AdminWindow);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(10, 110, 471, 431));
        horizontalLayout = new QHBoxLayout(widget1);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_3 = new QLabel(widget1);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_3->addWidget(label_3);

        CollegeList = new QListWidget(widget1);
        CollegeList->setObjectName(QString::fromUtf8("CollegeList"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CollegeList->sizePolicy().hasHeightForWidth());
        CollegeList->setSizePolicy(sizePolicy);

        verticalLayout_3->addWidget(CollegeList);


        horizontalLayout->addLayout(verticalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_4 = new QLabel(widget1);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_2->addWidget(label_4);

        SouvenirList = new QListWidget(widget1);
        SouvenirList->setObjectName(QString::fromUtf8("SouvenirList"));

        verticalLayout_2->addWidget(SouvenirList);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_5 = new QLabel(widget1);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_4->addWidget(label_5);

        PriceList = new QListWidget(widget1);
        PriceList->setObjectName(QString::fromUtf8("PriceList"));

        verticalLayout_4->addWidget(PriceList);


        horizontalLayout->addLayout(verticalLayout_4);


        retranslateUi(AdminWindow);

        QMetaObject::connectSlotsByName(AdminWindow);
    } // setupUi

    void retranslateUi(QDialog *AdminWindow)
    {
        AdminWindow->setWindowTitle(QCoreApplication::translate("AdminWindow", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("AdminWindow", "<html><head/><body><p><span style=\" font-size:12pt;\">Welcome Admin</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("AdminWindow", "<html><head/><body><p>Here, you may Add, Remove, and <br/>Change Prices of souvenirs for each restaurant </p></body></html>", nullptr));
        pushButton_4->setText(QCoreApplication::translate("AdminWindow", "Back", nullptr));
        NewName->setText(QString());
        NewName->setPlaceholderText(QCoreApplication::translate("AdminWindow", "New Name", nullptr));
        NewPrice->setPlaceholderText(QCoreApplication::translate("AdminWindow", "New Price", nullptr));
        Add->setText(QCoreApplication::translate("AdminWindow", "Add Souvenir", nullptr));
        Remove->setText(QCoreApplication::translate("AdminWindow", "Remove Souvenir", nullptr));
        Change->setText(QCoreApplication::translate("AdminWindow", "Change Price", nullptr));
        label_3->setText(QCoreApplication::translate("AdminWindow", "Colleges", nullptr));
        label_4->setText(QCoreApplication::translate("AdminWindow", "Souvenirs", nullptr));
        label_5->setText(QCoreApplication::translate("AdminWindow", "Price", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminWindow: public Ui_AdminWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINWINDOW_H
