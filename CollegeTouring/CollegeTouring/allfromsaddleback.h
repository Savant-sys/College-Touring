#ifndef ALLFROMSADDLEBACK_H
#define ALLFROMSADDLEBACK_H

#include <QDialog>

using namespace std;

namespace Ui {
class Allfromsaddleback;
}

class Allfromsaddleback : public QDialog
{
    Q_OBJECT

public:
    explicit Allfromsaddleback(QWidget *parent = nullptr);
    ~Allfromsaddleback();
    void print();
signals:
    vector<QString> getEndCollegesFromSaddleback();
    vector<double> getDistancesFromSaddleback();

private:
    Ui::Allfromsaddleback *ui;
    vector<QString> endColleges;
    vector<double> distances;
};

#endif // ALLFROMSADDLEBACK_H
