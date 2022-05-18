#ifndef ALLFROMSADDLEBACK_H
#define ALLFROMSADDLEBACK_H

#include <QDialog>
#include "campus.h"
#include "mainwindow.h"
#include "ui_allfromsaddleback.h"

namespace Ui{
class fromsaddleback ;
}

class fromsaddleback : public QDialog
{
    Q_OBJECT

public:
    explicit fromsaddleback(QWidget *parent = nullptr);
    ~fromsaddleback();

    void print();
signals:
    Campus getSaddleback();

private:
    Ui::fromsaddleback *ui;
    Campus campus;
};

#endif // ALLFROMSADDLEBACK_H
