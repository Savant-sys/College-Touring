#ifndef MST_H
#define MST_H
#include <vector>
#include <QtAlgorithms>
//#include <bits/stdc++.h>
using namespace std;

/*!
 *\brief DSU class for ensuring correct mst output
 */
class DSU {
    int* parent;
    int* rank;

public:
    //! Constructor
    //! \brief initializes DSU class for mst search.
    DSU(int n);


    //! find
    /*!
     * \brief uses parent array to find the path
     * \param i - index of college for parent
     * \return Returns index of found college index
     */
    int find(int i)
    {
        if (parent[i] == -1)
        {
            return i;
        }

        return parent[i] = find(parent[i]);
    }

    //! unite
    /*!
     * \brief unites the origin and destination vertexes
     * \param x - origin college. y - destination college
     * \return Returns boolean of whether operation was successful
     */
    void unite(int x, int y);

};

/*!
 *\brief Graph class to store and sort branches for mst
 */
class Graph
{
    vector<vector<double>> edgelist; /*!< vector of vectors to store branch data for mst */
    int V;

public:

    //! Constructor
    //! \brief Initializes graph with max size
    Graph(int V) { this->V = V; }

    //! addEdge
    /*!
     * \brief inserts branch info into edgeList
     * \param x - start college. y - end college. w - weight of branch(dist)
     * \return Returns boolean of whether operation was successful
     */
    void addEdge(double x, double y, double w)
    {
        edgelist.push_back({ w, round(x), round(y) });
    }

    //! kruskals_mst
    /*!
     * \brief performs mst search on edges
     * \param N/A
     * \return Returns boolean of whether operation was successful
     */
    void kruskals_mst();
    double ans = 0;
    vector<vector<double>> ansList; /*!< vector of vectors to store answer of mst */
};

#endif // MST_H
