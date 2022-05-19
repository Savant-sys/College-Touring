#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include "campus.h"
#include "database.h"
#include "login.h"
#include <QListWidget>
#include "campus_widget.h"
#include "map.h"
#include "menuwidget.h"
#include "allfromsaddleback.h"
#include "mst.h"

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/*!
 * \brief Main application page and class
 *  Has many methods for internal workings of program
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    //! Constructor
    //! \brief Initializes database object and loads UI with campuses in the database.
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    //! addCampus
    /*!
     * \brief Adds campus to selected campuses, which we need for creating a trip.
     */
    void addCampus(Campus campus);

    //! getMenuList
    /*!
     * \brief Accessor function that returns list of selected campuses
     */
    vector<QString> getMenuList() const { return menuList; }

    //! addToMenuList
    /*!
     * \brief Adds item to selected items UI list
     */
    void addMenuItem(Campus restaurant, Souvenir item);

    //! addItem
    /*!
     * \brief Adds item to menu and reloads UI (updates database as well)
     */
    void addItem(Campus campus, vector<Souvenir> newMenu);

    //! deleteItem
    /*!
     * \brief Deletes item from menu and reloads UI (updates database as well)
     */
    void deleteItem(Campus campus, vector<Souvenir> newMenu);

    //! editItem
    /*!
     * \brief Edits item from menu and reloads UI (updates database as well)
     */
    void editItem(Campus campus, int index);


    Database db; /*!< Database backend object */
    vector<Campus> campuses; /*!< Every campus in the database */

public slots:
    void unlockTab();
    vector<QString> getEndCollegesFromSaddleback() { return campuses[4].getEndCollege(); }
    vector<double> getDistancesFromSaddleback() { return campuses[4].getDistances(); }
private slots:
    void on_openCA_clicked();

    void on_adminPop_clicked();

    void Update();

    void on_UnderSelected_clicked();

    void on_UnderAll_clicked();

    void on_UnderInitial_clicked();

    void on_actionCustom_Trip_to_Any_triggered();

    void on_tabWidget_currentChanged(int index);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_CustomTripList_itemClicked(QListWidgetItem *item);

    void on_AddToCart_clicked();

    void on_CustomTripPrices_itemClicked(QListWidgetItem *item);

    void on_CustomTripSouvs_itemClicked(QListWidgetItem *item);

    void on_pushButton_3_clicked();

    void on_openAll_clicked();

    void on_sortStateStart_clicked();

    void on_actionCustrom_Dijkstra_triggered();

    void on_addStateD_clicked();

    //void on_CustomConvert_clicked();

    //void on_CustomConvert_2_clicked();

    void on_sortStates_clicked();

    void on_sortStart_clicked();

    void on_allFromSaddleback_clicked();
    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_addStateD_2_clicked();
    //void on_CustomConvert_3_clicked();

    void on_AllSaddlebackList_itemClicked(QListWidgetItem *item);

    void on_SaddlebackTripSouvs_itemClicked(QListWidgetItem *item);

    void on_SaddlebackTripPrices_itemClicked(QListWidgetItem *item);

    void on_AddToCartSA_clicked();

    void on_SaddlbackFinish_clicked();

    void on_actionAll_from_Saddleback_triggered();

    void on_StartMich_clicked();

    //void on_CustomConvert_4_clicked();

    void on_MichTripSouvs_itemClicked(QListWidgetItem *item);

    void on_MichTripPrices_itemClicked(QListWidgetItem *item);

    void on_AddToCartM_clicked();

    void on_MichSpecificList_itemClicked(QListWidgetItem *item);

    void on_MichFinish_clicked();
    void on_CustomDTripSouvs_itemClicked(QListWidgetItem *item);

    void on_CustomDTripPrices_itemClicked(QListWidgetItem *item);

    void on_AddToCartCD_clicked();

    void on_CusomDFinish_clicked();

    void on_CustomDijkstraList_itemClicked(QListWidgetItem *item);

    void on_actionMich_to_Specific_triggered();

    void on_actionMST_triggered();

    void on_actionDFS_triggered();

    void on_actionBFS_triggered();

private:
    Ui::MainWindow *ui; /*!< UI of main window */

    bool log; /*!< bool setup for admin authentication */
    Login* loginpopup; /*!< Pointer to popup page for admin authentication */
    Allfromsaddleback* saddlebackTablepopup; /*!< Pointer to popup page for displaying all colleges from Saddleback College */
    bool added; /*!< bool setup for adding new colleges */
    Map collegeMap; /*!< Pointer to current Map object */

    vector<QString> nameList; /*!< Selected restaurant names */
    vector<QString> menuList; /*!< Selected menu items */
    std::multimap<int, Souvenir> selectedItems; /*!< Map of selected items, with the key being a campus of start*/
    std::vector<Campus> selectedCampus; /*!< Vector of selected campuses */


};
#endif // MAINWINDOW_H
