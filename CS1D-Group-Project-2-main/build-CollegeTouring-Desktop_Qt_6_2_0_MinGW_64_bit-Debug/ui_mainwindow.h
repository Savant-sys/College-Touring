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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionCustom_Trip_to_Any;
    QAction *actionCustrom_Dijkstra;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *UnderSelected;
    QPushButton *UnderAll;
    QPushButton *UnderInitial;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QPushButton *openCA;
    QPushButton *sortStateStart;
    QPushButton *sortStart;
    QPushButton *sortStates;
    QListWidget *campusList;
    QPushButton *adminPop;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_3;
    QPushButton *openAll;
    QPushButton *allFromSaddleback;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout;
    QLabel *textBrowser_2;
    QLabel *textBrowser;
    QWidget *tab_2;
    QPushButton *pushButton_4;
    QTableWidget *Cart;
    QLabel *label_2;
    QPushButton *CustomConvert;
    QPushButton *AddToCart;
    QPushButton *pushButton_2;
    QLineEdit *GrandTotal;
    QListWidget *CustomTripPrices;
    QLabel *label;
    QSpinBox *spinBox;
    QTableWidget *SelectedCollegesList;
    QListWidget *CustomTripList;
    QPushButton *pushButton;
    QListWidget *CustomTripSouvs;
    QLineEdit *TotalDistCR;
    QWidget *tab_4;
    QListWidget *listWidget;
    QLabel *label_9;
    QListWidget *listWidget_2;
    QPushButton *addStateD;
    QPushButton *pushButton_5;
    QPushButton *CustomConvert_2;
    QListWidget *CustomDijkstraList;
    QWidget *tab_9;
    QLabel *label_4;
    QPushButton *addStateD_2;
    QLabel *label_3;
    QPushButton *CustomConvert_3;
    QTableWidget *SelectedCollegesList_2;
    QPushButton *SaddlbackFinish;
    QTableWidget *CartSaddleback;
    QPushButton *AddToCartSA;
    QLineEdit *TotalDistSA;
    QListWidget *SaddlebackTripSouvs;
    QListWidget *SaddlebackTripPrices;
    QListWidget *AllSaddlebackList;
    QSpinBox *spinBoxSA;
    QLineEdit *GrandTotalSA;
    QWidget *tab_10;
    QListWidget *MichTripPrices;
    QListWidget *MichTripSouvs;
    QPushButton *AddToCartM;
    QLineEdit *TotalDistM;
    QTableWidget *CartMich;
    QPushButton *MichFinish;
    QPushButton *CustomConvert_4;
    QSpinBox *spinBoxM;
    QLabel *label_5;
    QLabel *label_6;
    QTableWidget *SelectedCollegesList_3;
    QPushButton *StartMich;
    QLineEdit *GrandTotalM;
    QListWidget *MichSpecificList;
    QWidget *tab_3;
    QListWidget *menuAdminList;
    QPushButton *pushButton_3;
    QLabel *label_8;
    QTextEdit *itemnameText;
    QLineEdit *priceText;
    QLabel *label_7;
    QMenuBar *menubar;
    QMenu *menuTrips;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1272, 733);
        actionCustom_Trip_to_Any = new QAction(MainWindow);
        actionCustom_Trip_to_Any->setObjectName(QString::fromUtf8("actionCustom_Trip_to_Any"));
        actionCustrom_Dijkstra = new QAction(MainWindow);
        actionCustrom_Dijkstra->setObjectName(QString::fromUtf8("actionCustrom_Dijkstra"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        layoutWidget = new QWidget(tab);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(500, 450, 252, 171));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        UnderSelected = new QPushButton(layoutWidget);
        UnderSelected->setObjectName(QString::fromUtf8("UnderSelected"));

        verticalLayout->addWidget(UnderSelected);

        UnderAll = new QPushButton(layoutWidget);
        UnderAll->setObjectName(QString::fromUtf8("UnderAll"));

        verticalLayout->addWidget(UnderAll);

        UnderInitial = new QPushButton(layoutWidget);
        UnderInitial->setObjectName(QString::fromUtf8("UnderInitial"));

        verticalLayout->addWidget(UnderInitial);

        layoutWidget1 = new QWidget(tab);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 450, 231, 171));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        openCA = new QPushButton(layoutWidget1);
        openCA->setObjectName(QString::fromUtf8("openCA"));

        verticalLayout_2->addWidget(openCA);

        sortStateStart = new QPushButton(layoutWidget1);
        sortStateStart->setObjectName(QString::fromUtf8("sortStateStart"));

        verticalLayout_2->addWidget(sortStateStart);

        sortStart = new QPushButton(layoutWidget1);
        sortStart->setObjectName(QString::fromUtf8("sortStart"));

        verticalLayout_2->addWidget(sortStart);

        sortStates = new QPushButton(layoutWidget1);
        sortStates->setObjectName(QString::fromUtf8("sortStates"));

        verticalLayout_2->addWidget(sortStates);

        campusList = new QListWidget(tab);
        campusList->setObjectName(QString::fromUtf8("campusList"));
        campusList->setGeometry(QRect(0, 0, 1241, 441));
        adminPop = new QPushButton(tab);
        adminPop->setObjectName(QString::fromUtf8("adminPop"));
        adminPop->setGeometry(QRect(1130, 580, 94, 29));
        layoutWidget2 = new QWidget(tab);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(250, 450, 241, 171));
        verticalLayout_3 = new QVBoxLayout(layoutWidget2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        openAll = new QPushButton(layoutWidget2);
        openAll->setObjectName(QString::fromUtf8("openAll"));

        verticalLayout_3->addWidget(openAll);

        allFromSaddleback = new QPushButton(layoutWidget2);
        allFromSaddleback->setObjectName(QString::fromUtf8("allFromSaddleback"));

        verticalLayout_3->addWidget(allFromSaddleback);

        layoutWidget3 = new QWidget(tab);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(770, 520, 200, 25));
        horizontalLayout = new QHBoxLayout(layoutWidget3);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        textBrowser_2 = new QLabel(layoutWidget3);
        textBrowser_2->setObjectName(QString::fromUtf8("textBrowser_2"));
        textBrowser_2->setEnabled(true);
        QFont font;
        font.setFamilies({QString::fromUtf8("Mongolian Baiti")});
        font.setPointSize(16);
        textBrowser_2->setFont(font);

        horizontalLayout->addWidget(textBrowser_2);

        textBrowser = new QLabel(layoutWidget3);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setEnabled(true);
        textBrowser->setFont(font);

        horizontalLayout->addWidget(textBrowser);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        pushButton_4 = new QPushButton(tab_2);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(920, 410, 80, 22));
        Cart = new QTableWidget(tab_2);
        Cart->setObjectName(QString::fromUtf8("Cart"));
        Cart->setGeometry(QRect(920, 30, 301, 371));
        label_2 = new QLabel(tab_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(1010, 410, 81, 16));
        CustomConvert = new QPushButton(tab_2);
        CustomConvert->setObjectName(QString::fromUtf8("CustomConvert"));
        CustomConvert->setGeometry(QRect(30, 90, 91, 22));
        AddToCart = new QPushButton(tab_2);
        AddToCart->setObjectName(QString::fromUtf8("AddToCart"));
        AddToCart->setGeometry(QRect(660, 60, 91, 22));
        pushButton_2 = new QPushButton(tab_2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(30, 60, 80, 22));
        GrandTotal = new QLineEdit(tab_2);
        GrandTotal->setObjectName(QString::fromUtf8("GrandTotal"));
        GrandTotal->setGeometry(QRect(1010, 430, 113, 21));
        CustomTripPrices = new QListWidget(tab_2);
        CustomTripPrices->setObjectName(QString::fromUtf8("CustomTripPrices"));
        CustomTripPrices->setGeometry(QRect(540, 30, 111, 211));
        label = new QLabel(tab_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(730, 110, 101, 16));
        spinBox = new QSpinBox(tab_2);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(660, 30, 42, 22));
        spinBox->setMaximum(10);
        SelectedCollegesList = new QTableWidget(tab_2);
        SelectedCollegesList->setObjectName(QString::fromUtf8("SelectedCollegesList"));
        SelectedCollegesList->setGeometry(QRect(400, 250, 301, 181));
        CustomTripList = new QListWidget(tab_2);
        CustomTripList->setObjectName(QString::fromUtf8("CustomTripList"));
        CustomTripList->setGeometry(QRect(130, 30, 251, 401));
        pushButton = new QPushButton(tab_2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(30, 30, 80, 22));
        CustomTripSouvs = new QListWidget(tab_2);
        CustomTripSouvs->setObjectName(QString::fromUtf8("CustomTripSouvs"));
        CustomTripSouvs->setGeometry(QRect(400, 30, 131, 211));
        TotalDistCR = new QLineEdit(tab_2);
        TotalDistCR->setObjectName(QString::fromUtf8("TotalDistCR"));
        TotalDistCR->setGeometry(QRect(730, 130, 113, 21));
        tabWidget->addTab(tab_2, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        listWidget = new QListWidget(tab_4);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(400, 30, 256, 251));
        label_9 = new QLabel(tab_4);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(140, 430, 211, 81));
        listWidget_2 = new QListWidget(tab_4);
        listWidget_2->setObjectName(QString::fromUtf8("listWidget_2"));
        listWidget_2->setGeometry(QRect(410, 290, 256, 192));
        addStateD = new QPushButton(tab_4);
        addStateD->setObjectName(QString::fromUtf8("addStateD"));
        addStateD->setGeometry(QRect(30, 30, 91, 22));
        pushButton_5 = new QPushButton(tab_4);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(30, 60, 91, 22));
        CustomConvert_2 = new QPushButton(tab_4);
        CustomConvert_2->setObjectName(QString::fromUtf8("CustomConvert_2"));
        CustomConvert_2->setGeometry(QRect(30, 90, 91, 22));
        CustomDijkstraList = new QListWidget(tab_4);
        CustomDijkstraList->setObjectName(QString::fromUtf8("CustomDijkstraList"));
        CustomDijkstraList->setGeometry(QRect(140, 30, 251, 391));
        tabWidget->addTab(tab_4, QString());
        tab_9 = new QWidget();
        tab_9->setObjectName(QString::fromUtf8("tab_9"));
        label_4 = new QLabel(tab_9);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(730, 100, 101, 16));
        addStateD_2 = new QPushButton(tab_9);
        addStateD_2->setObjectName(QString::fromUtf8("addStateD_2"));
        addStateD_2->setGeometry(QRect(20, 20, 91, 22));
        label_3 = new QLabel(tab_9);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(1010, 400, 81, 16));
        CustomConvert_3 = new QPushButton(tab_9);
        CustomConvert_3->setObjectName(QString::fromUtf8("CustomConvert_3"));
        CustomConvert_3->setGeometry(QRect(20, 50, 91, 22));
        SelectedCollegesList_2 = new QTableWidget(tab_9);
        SelectedCollegesList_2->setObjectName(QString::fromUtf8("SelectedCollegesList_2"));
        SelectedCollegesList_2->setGeometry(QRect(400, 240, 301, 181));
        SaddlbackFinish = new QPushButton(tab_9);
        SaddlbackFinish->setObjectName(QString::fromUtf8("SaddlbackFinish"));
        SaddlbackFinish->setGeometry(QRect(920, 400, 80, 22));
        CartSaddleback = new QTableWidget(tab_9);
        CartSaddleback->setObjectName(QString::fromUtf8("CartSaddleback"));
        CartSaddleback->setGeometry(QRect(920, 20, 301, 371));
        AddToCartSA = new QPushButton(tab_9);
        AddToCartSA->setObjectName(QString::fromUtf8("AddToCartSA"));
        AddToCartSA->setGeometry(QRect(660, 50, 91, 22));
        TotalDistSA = new QLineEdit(tab_9);
        TotalDistSA->setObjectName(QString::fromUtf8("TotalDistSA"));
        TotalDistSA->setGeometry(QRect(730, 120, 113, 21));
        SaddlebackTripSouvs = new QListWidget(tab_9);
        SaddlebackTripSouvs->setObjectName(QString::fromUtf8("SaddlebackTripSouvs"));
        SaddlebackTripSouvs->setGeometry(QRect(400, 20, 131, 211));
        SaddlebackTripPrices = new QListWidget(tab_9);
        SaddlebackTripPrices->setObjectName(QString::fromUtf8("SaddlebackTripPrices"));
        SaddlebackTripPrices->setGeometry(QRect(540, 20, 111, 211));
        AllSaddlebackList = new QListWidget(tab_9);
        AllSaddlebackList->setObjectName(QString::fromUtf8("AllSaddlebackList"));
        AllSaddlebackList->setGeometry(QRect(130, 20, 251, 391));
        spinBoxSA = new QSpinBox(tab_9);
        spinBoxSA->setObjectName(QString::fromUtf8("spinBoxSA"));
        spinBoxSA->setGeometry(QRect(660, 20, 42, 22));
        spinBoxSA->setMaximum(10);
        GrandTotalSA = new QLineEdit(tab_9);
        GrandTotalSA->setObjectName(QString::fromUtf8("GrandTotalSA"));
        GrandTotalSA->setGeometry(QRect(1010, 420, 113, 21));
        tabWidget->addTab(tab_9, QString());
        tab_10 = new QWidget();
        tab_10->setObjectName(QString::fromUtf8("tab_10"));
        MichTripPrices = new QListWidget(tab_10);
        MichTripPrices->setObjectName(QString::fromUtf8("MichTripPrices"));
        MichTripPrices->setGeometry(QRect(540, 30, 111, 211));
        MichTripSouvs = new QListWidget(tab_10);
        MichTripSouvs->setObjectName(QString::fromUtf8("MichTripSouvs"));
        MichTripSouvs->setGeometry(QRect(400, 30, 131, 211));
        AddToCartM = new QPushButton(tab_10);
        AddToCartM->setObjectName(QString::fromUtf8("AddToCartM"));
        AddToCartM->setGeometry(QRect(660, 60, 91, 22));
        TotalDistM = new QLineEdit(tab_10);
        TotalDistM->setObjectName(QString::fromUtf8("TotalDistM"));
        TotalDistM->setGeometry(QRect(730, 130, 113, 21));
        CartMich = new QTableWidget(tab_10);
        CartMich->setObjectName(QString::fromUtf8("CartMich"));
        CartMich->setGeometry(QRect(920, 30, 301, 371));
        MichFinish = new QPushButton(tab_10);
        MichFinish->setObjectName(QString::fromUtf8("MichFinish"));
        MichFinish->setGeometry(QRect(920, 410, 80, 22));
        CustomConvert_4 = new QPushButton(tab_10);
        CustomConvert_4->setObjectName(QString::fromUtf8("CustomConvert_4"));
        CustomConvert_4->setGeometry(QRect(20, 60, 91, 22));
        spinBoxM = new QSpinBox(tab_10);
        spinBoxM->setObjectName(QString::fromUtf8("spinBoxM"));
        spinBoxM->setGeometry(QRect(660, 30, 42, 22));
        spinBoxM->setMaximum(10);
        label_5 = new QLabel(tab_10);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(730, 110, 101, 16));
        label_6 = new QLabel(tab_10);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(1010, 410, 81, 16));
        SelectedCollegesList_3 = new QTableWidget(tab_10);
        SelectedCollegesList_3->setObjectName(QString::fromUtf8("SelectedCollegesList_3"));
        SelectedCollegesList_3->setGeometry(QRect(400, 250, 301, 181));
        StartMich = new QPushButton(tab_10);
        StartMich->setObjectName(QString::fromUtf8("StartMich"));
        StartMich->setGeometry(QRect(20, 30, 91, 22));
        GrandTotalM = new QLineEdit(tab_10);
        GrandTotalM->setObjectName(QString::fromUtf8("GrandTotalM"));
        GrandTotalM->setGeometry(QRect(1010, 430, 113, 21));
        MichSpecificList = new QListWidget(tab_10);
        MichSpecificList->setObjectName(QString::fromUtf8("MichSpecificList"));
        MichSpecificList->setGeometry(QRect(130, 30, 251, 391));
        tabWidget->addTab(tab_10, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        menuAdminList = new QListWidget(tab_3);
        menuAdminList->setObjectName(QString::fromUtf8("menuAdminList"));
        menuAdminList->setGeometry(QRect(0, 10, 1231, 511));
        pushButton_3 = new QPushButton(tab_3);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(10, 560, 151, 31));
        label_8 = new QLabel(tab_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(290, 540, 31, 16));
        itemnameText = new QTextEdit(tab_3);
        itemnameText->setObjectName(QString::fromUtf8("itemnameText"));
        itemnameText->setGeometry(QRect(170, 560, 111, 31));
        priceText = new QLineEdit(tab_3);
        priceText->setObjectName(QString::fromUtf8("priceText"));
        priceText->setGeometry(QRect(170, 530, 111, 31));
        label_7 = new QLabel(tab_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(290, 570, 71, 16));
        tabWidget->addTab(tab_3, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1272, 21));
        menuTrips = new QMenu(menubar);
        menuTrips->setObjectName(QString::fromUtf8("menuTrips"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuTrips->menuAction());
        menuTrips->addAction(actionCustom_Trip_to_Any);
        menuTrips->addAction(actionCustrom_Dijkstra);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionCustom_Trip_to_Any->setText(QCoreApplication::translate("MainWindow", "Custom Trip to Any", nullptr));
        actionCustrom_Dijkstra->setText(QCoreApplication::translate("MainWindow", "Custrom Dijkstra", nullptr));
        UnderSelected->setText(QCoreApplication::translate("MainWindow", "Undergraduates for selected college", nullptr));
        UnderAll->setText(QCoreApplication::translate("MainWindow", "Undergraduates for all colleges", nullptr));
        UnderInitial->setText(QCoreApplication::translate("MainWindow", "Undergraduates for initial colleges", nullptr));
        openCA->setText(QCoreApplication::translate("MainWindow", "Sort CA Colleges", nullptr));
        sortStateStart->setText(QCoreApplication::translate("MainWindow", "Sort State + Start Colleges", nullptr));
        sortStart->setText(QCoreApplication::translate("MainWindow", "Sort College Names", nullptr));
        sortStates->setText(QCoreApplication::translate("MainWindow", "Sort State", nullptr));
        adminPop->setText(QCoreApplication::translate("MainWindow", "Admin Login", nullptr));
        openAll->setText(QCoreApplication::translate("MainWindow", "Display Original List", nullptr));
        allFromSaddleback->setText(QCoreApplication::translate("MainWindow", "Display all from Saddleback College", nullptr));
        textBrowser_2->setText(QCoreApplication::translate("MainWindow", "Undergrads:", nullptr));
        textBrowser->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "All Colleges Information", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Finish", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Total Cost:", nullptr));
        CustomConvert->setText(QCoreApplication::translate("MainWindow", "ConvertToMap", nullptr));
        AddToCart->setText(QCoreApplication::translate("MainWindow", "AddSouvenir", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "AddSelected", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Total Distance:", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "AddStart", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Make a custom trip", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Please select the start of the<br/> trip and click &quot;Add Start&quot;<br/><br/>Then select the other colleges in the order<br/> you wish to visit and click &quot;Find Selected&quot;</p></body></html>", nullptr));
        addStateD->setText(QCoreApplication::translate("MainWindow", "Add Start", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "Find Selected", nullptr));
        CustomConvert_2->setText(QCoreApplication::translate("MainWindow", "ConvertToMap", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("MainWindow", "Make a custom trip with Dijkstra", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Total Distance:", nullptr));
        addStateD_2->setText(QCoreApplication::translate("MainWindow", "Add Start", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Total Cost:", nullptr));
        CustomConvert_3->setText(QCoreApplication::translate("MainWindow", "ConvertToMap", nullptr));
        SaddlbackFinish->setText(QCoreApplication::translate("MainWindow", "Finish", nullptr));
        AddToCartSA->setText(QCoreApplication::translate("MainWindow", "AddSouvenir", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_9), QCoreApplication::translate("MainWindow", "All From Saddleback", nullptr));
        AddToCartM->setText(QCoreApplication::translate("MainWindow", "AddSouvenir", nullptr));
        MichFinish->setText(QCoreApplication::translate("MainWindow", "Finish", nullptr));
        CustomConvert_4->setText(QCoreApplication::translate("MainWindow", "ConvertToMap", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Total Distance:", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Total Cost:", nullptr));
        StartMich->setText(QCoreApplication::translate("MainWindow", "Add Start", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_10), QCoreApplication::translate("MainWindow", "Michigan To Specific", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Add New Colleges", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Price", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Item Name", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainWindow", "Maintenance", nullptr));
        menuTrips->setTitle(QCoreApplication::translate("MainWindow", "Trips", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
