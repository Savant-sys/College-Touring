#ifndef CAMPUSWIDGET_H
#define CAMPUSWIDGET_H

class MainWindow;

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include "Campus.h"
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QComboBox>
#include <QMessageBox>
#include <QSpinBox>
#include "mainwindow.h"
#include "ui_mainwindow.h"

/*!
 * \brief CampusWidget class - inherits from QWidget
 */

class CampusWidget : public QWidget
{
    Q_OBJECT
public:

    //! CampusWidget
        /*!
         * \brief Initializes all UI elements with passed in campus object data
         *
         */
    explicit CampusWidget(Campus campusPassed, MainWindow *parent = nullptr);

    ~CampusWidget();

private:
    QHBoxLayout *layout; /*!< QHBoxLayout object */
    QLabel *nameLabel; /*!< Campus name - QLabel  object */
    QPushButton *addButton; /*!< Add campus to trip - QPushButton  object */
    QComboBox *menuItems; /*!< QComboBox of menu items */
    QSpinBox *itemsToAdd; /*!< QSpinBox that lets user pick number of items to add */
    QPushButton *addItemButton; /*!< QPushButton to add a menu item to trip */

    //campus that this ui element represents
    Campus campus; /*!< Campus associated with widget */
    MainWindow *parent; /*!< Reference to the main application */

private slots:
    //these call methods in mainwindow.cpp
   void on_AddCampusClicked();
   void on_AddMenuItemClicked();


};

#endif // CAMPUSWIDGET_H
