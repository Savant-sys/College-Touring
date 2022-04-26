#ifndef MAP_H
#define MAP_H

//#include <iostream>
#include <vector>
#include <QObject>
//#include "string.h"
#include "campus.h"

//using namespace std;

#define TABLE_SIZE 150 //entries plus 1
//#define TABLE_SIZE2 29

#define PRIME 13

struct HashStruct
{
    QString origin = "";
    QString dest = "";
    int num = -1;
    double dist = 0;
};

class Map
{
public:
    Map(int size)
{
    //this->TABLE_SIZE = size;
    for(int i = 0; i < size; i++)
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

    void displayHash(); //not working

    void putVectorinHere(vector<Campus> campuses);

    int getDist(QString origin, QString dest);

    QString getOrigin(pair<int,double> key);

    QString getDest(pair<int,double> key);

    HashStruct hashTable[TABLE_SIZE];
private:
    //int TABLE_SIZE = 31;



   // int vecSize = 0;

};

#endif // MAP_H
