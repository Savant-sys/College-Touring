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

    QString getStartCollege() const
    {
        return startCollege;
    }

    vector<QString> getEndCollege() const
    {
        return endCollege;
    }

    vector<double> getDistances() const
    {
        return distances;
    }

    QString getState() const
    {
        return state;
    }

    int getUndergrads() const
    {
        return undergrads;
    }

    vector<Souvenir> getMenu() const
    {
        return menu;
    }

private:
    QString startCollege;
    vector<QString> endCollege;
    vector<double> distances;
    QString state;
    int undergrads;
    vector<Souvenir> menu;
};

#endif // CAMPUS_H
