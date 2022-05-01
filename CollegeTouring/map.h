#ifndef MAP_H
#define MAP_H

#include <vector>
#include <QObject>
#include "campus.h"

#define TABLE_SIZE 150 //entries plus 1

#define PRIME 13

struct HashStruct
{
    QString origin = "";
    QString dest = "";
    int num = -1;
    double dist = 0;
    bool select = false;
};

class Map
{
public:
    Map()
{
    //this->TABLE_SIZE = size;
    for(int i = 0; i < 150; i++)
    {
        hashTable[i].num = -1;
        hashTable[i].origin = "";
        hashTable[i].dest = "";
    }
};
    int hash1(pair<int,double> key)
{
    return(key.first % TABLE_SIZE);
};

    int hash2(pair<int,double> key)
{
    return (PRIME - (key.first % PRIME));
};

    void insertHash(pair<int,double> key, QString origin, QString dest);

    void deleteKey(pair<int,double> key);

    void putVectorinHere(vector<Campus> campuses);

    int getDist(QString origin, QString dest);

    QString getOrigin(pair<int,double> key);

    QString getDest(pair<int,double> key);

    void selected(vector<QString> selec, int size);

    void recurSelec(pair<int,double> key);

    HashStruct hashTable[TABLE_SIZE];

    vector<HashStruct> ans;
private:

    int s = 0; //number of selected items

};

#endif // MAP_H
