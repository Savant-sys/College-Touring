#ifndef CAMPUS_H
#define CAMPUS_H

#include <QObject>
using namespace std;

struct Souvenir
{
    QString name;
    double price;
};

/*!
 *\brief Campus class
 */

class Campus
{
public:
    //!Constructor
    //! \brief Initializes all campus attributes
    Campus(QString startCollege, vector<QString> endCollege, vector<double> distances, QString state, int undergrads, vector<Souvenir> menu);

    //! getStartCollege
        /*!
         * \brief
         * \return Returns QString which is starting colleges
         */
    QString getStartCollege() const
    {
        return startCollege;
    }

    //! getEndCollege
        /*!
         * \brief
         * \return Returns vector of QString which is starting colleges's ending colleges
         */
    vector<QString> getEndCollege() const
    {
        return endCollege;
    }

    //! getDistances
        /*!
         * \brief
         * \return Returns vector of double which is the distances between starting colleges and all ending colleges
         */
    vector<double> getDistances() const
    {
        return distances;
    }

    //! getState
        /*!
         * \brief
         * \return Returns QString which is the state for the starting colleges
         */
    QString getState() const
    {
        return state;
    }

    //! getUndergrads
        /*!
         * \brief
         * \return Returns int which is the undergrads for the starting colleges
         */
    int getUndergrads() const
    {
        return undergrads;
    }

    //! getMenu
        /*!
         * \brief
         * \return Returns vector of Souvenir, which represents the menu of the starting campus
         */
    vector<Souvenir> getMenu() const
    {
        return menu;
    }

private:
    QString startCollege; /*!< Start College name - QString */
    vector<QString> endCollege; /*!< Campus ending collegs - vector of QString object */
    vector<double> distances; /*!< Campus distances - vector of double object */
    QString state; /*!< Campus state - QString */
    int undergrads; /*!< Campus undergrads - int */
    vector<Souvenir> menu; /*!< Campus menu - vector of Souvenir object */
};

#endif // CAMPUS_H
