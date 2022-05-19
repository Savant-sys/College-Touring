#ifndef MAP_H
#define MAP_H

#include <vector>
#include <QObject>
#include <QDebug>
#include "campus.h"

#define TABLE_SIZE 400 //entries plus 1

#define PRIME 13

/*!
 *\brief HashStruct - struct to hold each branch data
 */
struct HashStruct
{
    QString origin = "";
    QString dest = "";
    int num = -1;
    double dist = 0;
    bool select = false;
    bool visited = false;
};

/*!
 *\brief Map class - for holding sorting through the edge data
 */
class Map
{
public:
    //! Constructor
    //! \brief Initializes all elements with empty or -1.
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

    int hash1(pair<int,double> key) /*!< function to help store branches correctly using hash*/
    {
        return(key.first % TABLE_SIZE);
    };


    int hash2(pair<int,double> key)
    {
        return (PRIME - (key.first % PRIME));   /*!< function to help store branches correctly using hash*/
    };

    //! insertHash
    /*!
     * \brief inserts branch info into hashMap
     * \param key - index and distance for college. origin - start college string. dest - destination college string
     * \return Returns boolean of whether operation was successful
     */
    void insertHash(pair<int,double> key, QString origin, QString dest);

    //! deleteKey
    /*!
     * \brief removes branch from hashMap
     * \param key - index and distance for college
     * \return Returns boolean of whether operation was successful
     */
    void deleteKey(pair<int,double> key);

    //! putVectorinHere
    /*!
     * \brief stores branch info in hashMap using insertHash taking campuses vector as parameter
     * \param campuses - vector storing infomation for each college
     * \return Returns boolean of whether operation was successful
     */
    void putVectorinHere(vector<Campus> campuses);

    //! getDist
    /*!
     * \brief returns distance for specified branch
     * \param origin - start college string. dest - destination college string
     * \return Returns distance of branch
     */
    int getDist(QString origin, QString dest);

    //! getOrigin
    /*!
     * \brief returns origin string for specified branch
     * \param key - index and distance for college.
     * \return Returns string of origin of key index
     */
    QString getOrigin(pair<int,double> key);

    //! getDest
    /*!
     * \brief returns destination string for specified branch
     * \param key - index and distance for college
     * \return Returns string of destination of key index
     */
    QString getDest(pair<int,double> key);

    //! selected
    /*!
     * \brief sets the select attribute to true for each branch selected in UI
     * \param selec - vector of selected colleges. size - size of selec vector
     * \return Returns boolean of whether operation was successful
     */
    void selected(vector<QString> selec, int size);

    //! recurSelec
    /*!
     * \brief function to recursively search for the shortest route of selected colleges
     * \param key - index and distance for college
     * \return Returns boolean of whether operation was successful
     */
    void recurSelec(pair<int,double> key);

    //! dijkstra
    /*!
     * \brief function to run a dijkstra search on given key
     * \param key - index and distance for college
     * \return Returns boolean of whether operation was successful
     */
    void dijkstra(pair<int,double> key);

    //! initPathDist
    /*!
     * \brief function to initialize parent and pathDists for Dijkstra
     * \param sel - vector of all selected colleges
     * \return Returns boolean of whether operation was successful
     */
    void initPathDist(vector<QString> Sel);

    //! pathsInAns
    /*!
     * \brief function to find the parent of given college and put the resulting path in ans vector
     * \param j - index for parent to find path
     * \return Returns boolean of whether operation was successful
     */
    void pathsInAns(int j);

    //! BFS
    /*!
     * \brief function to run BFS search starting from ASU
     * \param key - index and distance for college
     * \return Returns boolean of whether operation was successful
     */
    void BFS(pair<int, double> key);

    //! DFS
    /*!
     * \brief function to run DFS search starting from UCI
     * \param q - key of college to run BFS on
     * \return Returns boolean of whether operation was successful
     */
    void DFS(int q);

    //! print
    /*!
     * \brief function to print search values
     * \return Returns boolean of whether operation was successful
     */
    void print();

    //! DijkstraNext
    /*!
     * \brief function to run dijkstra on each selected college
     * \param pathIndex - index of college from paths
     * \return Returns boolean of whether operation was successful
     */
    void dijkstraNext(int pathIndex);

    //! MST
    /*!
     * \brief function to store branch values for MST format
     * \return Returns boolean of whether operation was successful
     */
    void MST();


    HashStruct hashTable[TABLE_SIZE]; /*!< Map to store branch data */

    HashStruct hashTable2[TABLE_SIZE]; /*!< Map to store branch data specifically for DFS*/

    vector<HashStruct> ans; /*!< vector to store answer values to output in UI */

    vector<pair<int,double>> pathDists; /*!< vector to store the distances and college indexes for dijkstra */

    vector<int> parent; /*!< vector of parent vertexes for each college */
    vector<int> numToPrint; /*!< vector to store seperate college indexes in order */
    vector<double> dist; /*!< vector to store distances to colleges */

    vector<vector<double>> forMST; /*!< vector to store correct format branch data */
    double totalDistanceDFS = 0;
    int incr = 0; /*!< number of colleges in hashTable2 */

    int coll = 0; /*!< number of colleges in map */
private:


    int s = 0; /*!< number of selected items */


};

#endif // MAP_H
