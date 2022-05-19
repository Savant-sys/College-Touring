#ifndef ALLFROMSADDLEBACK_H
#define ALLFROMSADDLEBACK_H

#include <QDialog>
using namespace std;

namespace Ui {
class Allfromsaddleback;
}

/*!
 * \brief List of Allfromsaddleback class
 * Serves as a UI for the popup Allfromsaddleback list, with from Saddleback to all ending colleges
 */
class Allfromsaddleback : public QDialog
{
    Q_OBJECT

public:
    explicit Allfromsaddleback(QWidget *parent = nullptr);
    ~Allfromsaddleback();

    //! print
    /*!
     * \brief Method to print the list of Saddleback Colleges to all colleges
     */
    void print();
signals:
    vector<QString> getEndCollegesFromSaddleback();
    vector<double> getDistancesFromSaddleback();

private:
    Ui::Allfromsaddleback *ui; /*!< UI of popup window */
    vector<QString> endColleges; /*!< vector of endColleges object */
    vector<double> distances; /*!< vector of distances object */
};

#endif // ALLFROMSADDLEBACK_H
