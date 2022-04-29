/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionCustom_Trip_to_Any;
    QWidget *centralwidget;
    QListWidget *customList;
    QListWidget *menuList;
    QPushButton *sortStateCollege;
    QPushButton *adminPop;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QTabWidget *tabWidget;
    QWidget *tab;
    QListWidget *campusList;
    QWidget *tab_2;
    QPushButton *pushButton;
    QListWidget *CustomTripList;
    QPushButton *pushButton_2;
    QListWidget *CustomTripSouvs;
    QListWidget *CustomTripPrices;
    QSpinBox *spinBox;
    QTableWidget *Cart;
    QPushButton *AddToCart;
    QWidget *page_2;
    QTextBrowser *textBrowser;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QPushButton *UnderSelected;
    QPushButton *UnderAll;
    QPushButton *UnderInitial;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_2;
    QPushButton *openTheList;
    QPushButton *sortState;
    QPushButton *sortCollege;
    QPushButton *openCA;
    QMenuBar *menubar;
    QMenu *menuTrips;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1341, 710);
        actionCustom_Trip_to_Any = new QAction(MainWindow);
        actionCustom_Trip_to_Any->setObjectName(QString::fromUtf8("actionCustom_Trip_to_Any"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        customList = new QListWidget(centralwidget);
        customList->setObjectName(QString::fromUtf8("customList"));
        customList->setGeometry(QRect(480, 460, 256, 192));
        menuList = new QListWidget(centralwidget);
        menuList->setObjectName(QString::fromUtf8("menuList"));
        menuList->setGeometry(QRect(740, 460, 256, 192));
        sortStateCollege = new QPushButton(centralwidget);
        sortStateCollege->setObjectName(QString::fromUtf8("sortStateCollege"));
        sortStateCollege->setGeometry(QRect(10, 620, 121, 21));
        adminPop = new QPushButton(centralwidget);
        adminPop->setObjectName(QString::fromUtf8("adminPop"));
        adminPop->setGeometry(QRect(140, 620, 80, 21));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(10, 10, 1271, 441));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        tabWidget = new QTabWidget(page);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(30, 0, 1241, 441));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        campusList = new QListWidget(tab);
        campusList->setObjectName(QString::fromUtf8("campusList"));
        campusList->setGeometry(QRect(0, 0, 1231, 411));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        pushButton = new QPushButton(tab_2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 10, 80, 22));
        CustomTripList = new QListWidget(tab_2);
        CustomTripList->setObjectName(QString::fromUtf8("CustomTripList"));
        CustomTripList->setGeometry(QRect(110, 10, 251, 401));
        pushButton_2 = new QPushButton(tab_2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(10, 40, 80, 22));
        CustomTripSouvs = new QListWidget(tab_2);
        CustomTripSouvs->setObjectName(QString::fromUtf8("CustomTripSouvs"));
        CustomTripSouvs->setGeometry(QRect(380, 10, 131, 211));
        CustomTripPrices = new QListWidget(tab_2);
        CustomTripPrices->setObjectName(QString::fromUtf8("CustomTripPrices"));
        CustomTripPrices->setGeometry(QRect(520, 10, 111, 211));
        spinBox = new QSpinBox(tab_2);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(640, 10, 42, 22));
        spinBox->setMaximum(10);
        Cart = new QTableWidget(tab_2);
        Cart->setObjectName(QString::fromUtf8("Cart"));
        Cart->setGeometry(QRect(900, 10, 251, 371));
        AddToCart = new QPushButton(tab_2);
        AddToCart->setObjectName(QString::fromUtf8("AddToCart"));
        AddToCart->setGeometry(QRect(640, 40, 91, 22));
        tabWidget->addTab(tab_2, QString());
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        stackedWidget->addWidget(page_2);
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(360, 470, 71, 31));
        textBrowser->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textBrowser->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(150, 460, 201, 80));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        UnderSelected = new QPushButton(widget);
        UnderSelected->setObjectName(QString::fromUtf8("UnderSelected"));

        verticalLayout->addWidget(UnderSelected);

        UnderAll = new QPushButton(widget);
        UnderAll->setObjectName(QString::fromUtf8("UnderAll"));

        verticalLayout->addWidget(UnderAll);

        UnderInitial = new QPushButton(widget);
        UnderInitial->setObjectName(QString::fromUtf8("UnderInitial"));

        verticalLayout->addWidget(UnderInitial);

        widget1 = new QWidget(centralwidget);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(20, 500, 82, 108));
        verticalLayout_2 = new QVBoxLayout(widget1);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        openTheList = new QPushButton(widget1);
        openTheList->setObjectName(QString::fromUtf8("openTheList"));

        verticalLayout_2->addWidget(openTheList);

        sortState = new QPushButton(widget1);
        sortState->setObjectName(QString::fromUtf8("sortState"));

        verticalLayout_2->addWidget(sortState);

        sortCollege = new QPushButton(widget1);
        sortCollege->setObjectName(QString::fromUtf8("sortCollege"));

        verticalLayout_2->addWidget(sortCollege);

        openCA = new QPushButton(widget1);
        openCA->setObjectName(QString::fromUtf8("openCA"));

        verticalLayout_2->addWidget(openCA);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1341, 21));
        menuTrips = new QMenu(menubar);
        menuTrips->setObjectName(QString::fromUtf8("menuTrips"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuTrips->menuAction());
        menuTrips->addAction(actionCustom_Trip_to_Any);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionCustom_Trip_to_Any->setText(QCoreApplication::translate("MainWindow", "Custom Trip to Any", nullptr));
        sortStateCollege->setText(QCoreApplication::translate("MainWindow", "Sort State + College", nullptr));
        adminPop->setText(QCoreApplication::translate("MainWindow", "Admin Login", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "MainTab", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "AddStart", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "AddSelected", nullptr));
        AddToCart->setText(QCoreApplication::translate("MainWindow", "AddSouvenir", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "CustomToAny", nullptr));
        UnderSelected->setText(QCoreApplication::translate("MainWindow", "Undergraduates for selected college", nullptr));
        UnderAll->setText(QCoreApplication::translate("MainWindow", "Undergraduates for all colleges", nullptr));
        UnderInitial->setText(QCoreApplication::translate("MainWindow", "Undergraduates for initial colleges", nullptr));
        openTheList->setText(QCoreApplication::translate("MainWindow", "Open the List", nullptr));
        sortState->setText(QCoreApplication::translate("MainWindow", "Sort State", nullptr));
        sortCollege->setText(QCoreApplication::translate("MainWindow", "Sort College", nullptr));
        openCA->setText(QCoreApplication::translate("MainWindow", "Open CA", nullptr));
        menuTrips->setTitle(QCoreApplication::translate("MainWindow", "Trips", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
