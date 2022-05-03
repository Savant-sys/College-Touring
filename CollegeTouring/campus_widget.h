#ifndef CAMPUS_WIDGET_H
#define CAMPUS_WIDGET_H

class MainWindow;

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include "campus.h"
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
    QLabel *stateLabel;
    QLabel *nameLabel; /*!< Campus name - QLabel  object */
    QComboBox *menuItems; /*!< QComboBox of menu items */

    QComboBox *endC;
    //campus that this ui element represents
    Campus campus; /*!< Campus associated with widget */
    MainWindow *parent; /*!< Reference to the main application */

private slots:
    //these call methods in mainwindow.cpp



};

#endif // CAMPUS_WIDGET_H
