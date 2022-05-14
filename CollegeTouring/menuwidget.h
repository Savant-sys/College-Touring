#ifndef MENUWIDGET_H
#define MENUWIDGET_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QDebug>
#include <vector>

#include "mainwindow.h"

#include <QHBoxLayout>
#include <QLabel>
#include <QComboBox>
#include <QPushButton>

#include "campus.h"

/*!
 * \brief Widget class used for editing restaurant menus. Inherits from QWidget.
 */

class MenuWidget : public QWidget
{
    Q_OBJECT
public:
    //! Constructor
    //! \brief Initializes all ui elements with restaurant passed into the constructor.
    explicit MenuWidget(Campus campus, MainWindow *parent = nullptr);

private:
    QHBoxLayout *layout; /*!< Layout to hold all ui elements */
    QLabel *nameLabel; /*!< Restaurant name */
    QComboBox *menuItems; /*!< Combobox of menu items */
    QPushButton *addNewItemButton; /*!< Button to add a new item */
    QPushButton *deleteItemButton; /*!< Button to delete an item */
    QPushButton *editItemButton; /*!< Button to edit an item */
    MainWindow *parent; /*!< Main application reference */
    QLabel *stateLabel;

    Campus campus; /*!< Restaurant associated with the widget */

private slots:

    void on_AddMenuItemClicked();

    void on_DeleteMenuItemClicked();

    void on_EditMenuItemClicked();

signals:

};

#endif // MENUWIDGET_H
