#ifndef DATABASE_H
#define DATABASE_H

#include "campus.h"

#include <QSqlDatabase>
#include <QObject>
#include <QWidget>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include <QStandardPaths>
#include <QDir>
#include <QRegularExpression>

/*!
 *\brief Database class
 */
class Database
{
public:
    //!Constructor
    //! \brief Establishes connection to .db file
    Database();

    //! readFile
     /*! unordered_map qstring
     * \brief Method to generate vector of campuses and souvenirs from input files (given in project zip)
     * \return Returns vector which is populated with new campuses and souvenirs from input file
     */
    vector<Campus> readFile();

    //! addCampuses
    /*!
     * \brief Method to add a new campus to the database
     * \param campuses - Vector of campuses to add to database
     * \return Returns boolean of whether operation was successful
     */
    void addCampuses(vector<Campus> campuses);

    //! modifySouvenir
    /*!
     * \brief Method to modify a campuses's items in database
     * \param campus - Campus object that we're trying to modify.
     * \param items - Vector of MenuItems, which represents our updated menu state.
     * \return - Returns boolean of whether operation was successful
     */
    void modifySouvenir(Campus campus, vector<Souvenir> items);

    //! getCampuses
    /*!
     * \brief Method to receive all campuses in database
     * \param campuses - Vector of campuses by reference to modify
     * \return Returns true or false of successful/not successful operation
     */
    bool getCampuses(vector<Campus>& campuses);
private:
    QSqlDatabase db; /*!< QTSqlite database object for Campuses*/
    QSqlDatabase dbS; /*!< QTSqlite database object for Souvenirs*/
    QString filePath;
    QString infile;
    QString filePathS;
    QString infileS;
};




#endif // DATABASE_H
