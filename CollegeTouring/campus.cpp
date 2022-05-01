#include "campus.h"

Campus::Campus(QString startCollege, vector<QString> endCollege, vector<double> distances, QString state, int undergrads, vector<Souvenir> menu, int id)
{
    this->startCollege = startCollege;
    this->endCollege = endCollege;
    this->distances = distances;
    this->state = state;
    this->undergrads = undergrads;
    this->menu = menu;
    this->id = id;
}
