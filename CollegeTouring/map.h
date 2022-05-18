#ifndef MAP_H
#define MAP_H

#include <vector>
#include <QObject>
#include <QDebug>
#include "campus.h"

#define TABLE_SIZE 400 //entries plus 1

#define PRIME 13

struct HashStruct
{
    QString origin = "";
    QString dest = "";
    int num = -1;
    double dist = 0;
    bool select = false;
    bool visited = false;
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

    void dijkstra(pair<int,double> key);

    void initPathDist(vector<QString> Sel);

    void pathsInAns(int j);

    void BFS(pair<int, double> key);

    void DFS(int q);//Starts at UCI

    void print();

    void dijkstraNext(int pathIndex);

    void MST();


    HashStruct hashTable[TABLE_SIZE];

    HashStruct hashTable2[TABLE_SIZE];

    vector<HashStruct> ans;

    vector<pair<int,double>> pathDists;

    vector<int> parent;
    vector<int> numToPrint;
    vector<double> dist;

    vector<vector<double>> forMST;
    double totalDistanceDFS = 0;
    int incr = 0;

    int coll = 0; //number of colleges in map (used in dijkstra setup)
private:


    int s = 0; //number of selected items


};

#endif // MAP_H
