#ifndef MST_H
#define MST_H
#include <vector>
#include <QtAlgorithms>
//#include <bits/stdc++.h>
using namespace std;
//class MST
//{
//public:
//    MST();
//};

class DSU {
    int* parent;
    int* rank;

public:
    DSU(int n);


    // Find function
    int find(int i)
    {
        if (parent[i] == -1)
        {
            return i;
        }

        return parent[i] = find(parent[i]);
    }
    // union function
    void unite(int x, int y);

};

class Graph
{
    vector<vector<double>> edgelist;
    int V;

public:

    vector<vector<double>> ansList;
    Graph(int V) { this->V = V; }

    void addEdge(double x, double y, double w)
    {
        edgelist.push_back({ w, round(x), round(y) });
    }

    void kruskals_mst();
    double ans = 0;
};

#endif // MST_H
