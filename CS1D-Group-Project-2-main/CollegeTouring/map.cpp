#include "map.h"

//Map::Map()
void Map::insertHash(pair<int,double> key, QString origin, QString dest)
{
    for (int i = 0; i < TABLE_SIZE; i++) ///currently replaces duplicate key
    {
        if (hashTable[i].num == key.first && hashTable[i].dist == key.second)
        {
            hashTable[i].origin = origin;
            hashTable[i].dest = dest;
            hashTable[i].select = false;
            return;
        }
    }
    int index;

    index = hash1(key);

    if (hashTable[index].num == -1)
    {
        hashTable[index].num = key.first;
        hashTable[index].origin = origin;
        hashTable[index].dest = dest;
        hashTable[index].dist = key.second;
        hashTable[index].select = false;
        return;
    }
    int index2;
    index2 = hash2(key);
    int i = 0;
    while (i >= 0)
    {
        int newIndex = (index + (i * index2)) % TABLE_SIZE;
        if (hashTable[newIndex].num == -1)
        {
            hashTable[newIndex].num = key.first;
            hashTable[newIndex].origin = origin;
            hashTable[newIndex].dest = dest;
            hashTable[newIndex].dist = key.second;
            hashTable[newIndex].select = false;
            break;
        }
        i++;
    }
}

void Map::deleteKey(pair<int,double> key)
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (hashTable[i].num == key.first && hashTable[i].dist == key.second)
        {
        hashTable[i].num = -1;
        hashTable[i].origin = "";
        hashTable[i].dest = "";
        hashTable[i].dist = -1;
        hashTable[i].select = false;
        break;
        }
    }
}

void Map::putVectorinHere(vector<Campus> campuses)
{
    int j =0;
    vector<QString> endColleges;
    vector<double> dist;
    for(int i = 0; i < campuses.size(); i++)
    {
        endColleges = campuses[i].getEndCollege();
        dist = campuses.at(i).getDistances();

        for(j = 0; j < endColleges.size(); j++)
        {   pair<int,double> key;
            key.first = i;
            key.second = dist.at(j);
            insertHash(key, campuses.at(i).getStartCollege(), endColleges.at(j));
        }
    }
}

int Map::getDist(QString origin, QString dest)
{
    for(int i = 0; i < TABLE_SIZE; i++)
    {
        if(hashTable[i].origin == origin && hashTable[i].dest == dest)
        {
            return hashTable[i].num;
        }
    }
    return -1;
}

QString Map::getOrigin(pair<int,double> key)
{
    for(int i = 0; i < TABLE_SIZE; i++)
    {
        if(hashTable[i].num == key.first && hashTable[i].dist == key.second)
        {
            return hashTable[i].origin;
        }
    }
    return "None Found";
}

QString Map::getDest(pair<int,double> key)
{
    for(int i = 0; i < TABLE_SIZE; i++)
    {
        if(hashTable[i].num == key.first && hashTable[i].dist == key.second)
        {
            return hashTable[i].dest;
        }
    }
    return "None Found";
}

void Map::selected(vector<QString> selec, int size)
{
    s = size;
    for(int i = 0; i < TABLE_SIZE; i++)
    {
        for(int j = 0; j < selec.size(); j++)
        {
            if(hashTable[i].origin == selec.at(j))
            {
                hashTable[i].select = true;
            }
        }
    }
}

void Map::recurSelec(pair<int,double> key) //recursion on selected for custom to any (deselects branches)
{

    double smallest = 99999;
    int j = 0;
    int p = 0;
    pair<int,double> found;
    double branchDist = 999;
    bool check = false;
    for(int i = 0; i < TABLE_SIZE; i++)
    {
        if(hashTable[i].num == key.first && hashTable[i].select == true)
        {
            branchDist = hashTable[i].dist;
            for(int l = 0; l < TABLE_SIZE; l++)
            {
                for(int m = 0; m < ans.size(); m++)
                {
                    if((hashTable[i].origin == hashTable[l].dest || hashTable[l].dest == ans.at(m).origin) && hashTable[i].dest == hashTable[l].origin )
                    {
                        hashTable[i].select = false;
                    }

                }
                if(hashTable[i].dest == hashTable[l].origin && hashTable[l].select == true && branchDist <= smallest)
                {
                    smallest = branchDist;
                    check = true;
                    j = l;
                    p = i;
                    found.first = hashTable[l].num;
                }
                else
                {
                    p = i;
                    hashTable[i].select = false;
                }

            }

        }
    }
    if(ans.size() >= s)
    {
        return;
    }

    if(ans.size() == 0)
    {
        ans.push_back(hashTable[p]);
        ans.at(ans.size()-1).dest = hashTable[j].origin;
        ans.at(ans.size()-1).dist = smallest;
        recurSelec(found);
    }
    else if(check == true)
    {
        ans.push_back(hashTable[p]);
        ans.at(ans.size()-1).dest = hashTable[j].origin;
        ans.at(ans.size()-1).dist = smallest;
        recurSelec(found);
    }
    else
    {   HashStruct end;
        end.origin = ans.at(ans.size()-1).dest;
        ans.push_back(end);
        return;
    }
}

void Map::dijkstra(pair<int, double> key)
{
    bool found = false;
    bool one = true;
    bool sck = true;
    double smallest = 999999;
    int edge = 0;
    int curr = 0;
    int saveI = 0;

    for(int j = 0; j < pathDists.size(); j++)
    {
        if(pathDists.at(j).second != INFINITY)
        {
            one = false;
        }
    }
    if(one == true)
    {
        HashStruct first;
       for(int j = 0; j < pathDists.size(); j++)
       {
           if(pathDists.at(j).first == key.first)
             {
               pathDists.at(j).second = 0; //set start

               first.num = key.first;

           }

       }
       ans.push_back(first);
    }
// go through visited branches and update pathDists with smallest for each
    //for(int p = 0; p < ans.size(); p++)
    {
    for(int i = 0; i < TABLE_SIZE; i++) //go through map to find current vertex
    {
        if(hashTable[i].num == key.first && hashTable[i].visited == false && hashTable[i].select == true) //Now at the branches of key college
        {
                saveI = i; //for hashtable
                bool check = false;
                for(int j = 0; j < pathDists.size(); j++) //0-10
                {

                    if(pathDists.at(j).first == hashTable[i].num)
                    {
                        curr = j; //index of pathdists where hashtable is at current vertex

                    }
                }
                //if(parent.at(curr) == -1)
                //{
                for(int f = 0; f < TABLE_SIZE; f++) //go through list of colleges again to find end key
                {
                   if(hashTable[i].dest == hashTable[f].origin) //now at i's dest
                   {
                       if(hashTable[f].visited == false && hashTable[f].select == true)
                           check = true;
                       //hashTable[f].visited = true;
                       for(int j = 0; j < pathDists.size(); j++)
                       {

                           if(pathDists.at(j).first == hashTable[f].num && check == true)//for each branch of key, find corresponding pathDist
                           {
                               if(pathDists.at(j).second > (hashTable[i].dist + pathDists.at(curr).second))
                               {   edge = j;//parent.at(curr) = hashTable[saveI].num;
                                   pathDists.at(edge).second = pathDists.at(curr).second + hashTable[i].dist; //only gives dist to start
                                   if(parent.at(edge) == -1)
                                   {
                                       parent.at(edge) = curr; //first run gives inital index
                                   }
                                   else
                                   {/*need ohio edge*/
                                       parent.at(edge) = curr; //if(hashTable[f].num == j+1)
                                   }
//s = hashTable[saveI].num; //save index of current for prev
                                   //{

                                   //}
                                   //update pathDists.second to total distance from start
                               }
                           }
                       }

                    }
                   }
                }
                if(!ans.empty())
                {
                for(int g = 0; g < ans.size(); g++)
                {
                     if(ans.at(g).num == curr)
                         sck = false;
                }
                //}
                if(smallest > pathDists.at(edge).second && smallest != pathDists.at(curr).second && sck == true)
                smallest = pathDists.at(edge).second;
hashTable[saveI].visited = true;
//hashTable[saveI].select = false;
        }
    }
    }
//    for(int i = 0; i < TABLE_SIZE; i++)
//    {
//        if(hashTable[i].visited != true)
//            end = true;
//    }
bool notFirst = false;
for(int i =0; i < parent.size(); i++)
{
    if(parent.at(i) != -1)
    {
        notFirst = true;
    }
}
    /*if(notFirst == true)
    parent.at(curr) = s;//hashTable[saveI].num; //set current parent index to prev
    else*/
if(notFirst == false)
        parent.at(curr) = -2; //start has no parent

    if(coll == 0)
        return;
    coll--;
    //find smallest pathDist from startvertex to set as current
    curr = 0;
    double small = 9999;
    if(one == false)
    {
    HashStruct ansCheck;
    ansCheck.num = hashTable[saveI].num;
    ans.push_back(ansCheck);
    }
    bool proceed = true;
    for(int i = 0; i < pathDists.size(); i++)
    {
        for(int j = 0; j < ans.size(); j++)
        {
             if(ans.at(j).num == i)
                 proceed = false;
        }
        if(pathDists.at(i).second <= small && pathDists.at(i).first != key.first && pathDists.at(i).second != 0 && proceed == true)
        {
            found = true;
            curr = i;

            small = pathDists.at(i).second;
        }
        proceed = true;

    }
    //smallest = 99999;
    if(found == true)
    {
        //coll = hashTable[curr].num;

        dijkstra(pathDists.at(curr));
    }
    else
        return;//{
        /*for(int i = 0; i < pathDists.size(); i++)
        {
            if(pathDists.at(i).second == 10)
                curr = i;
        }
        dijkstra(pathDists.at(curr));
    }*/
        //return;//pathsInAns(curr);
}

void Map::initPathDist(vector<QString> sel) // for dijkstra
{
    coll = sel.size();
    pair<int, double> OOnly;
    int par = -1;
    bool contains = false;
    OOnly.first = -1;
    OOnly.second = INFINITY;
    for(int i = 0; i < sel.size(); i++)
    {
        for(int j = 0; j < TABLE_SIZE; j++)
        {
            if(hashTable[j].origin == sel.at(i))
            {
                for(int m = 0; m < pathDists.size(); m++)
                {
                    if(pathDists.at(m).first == hashTable[j].num)
                        contains = true;
                }
                //par = i;
                if(contains == false)
                {
                    parent.push_back(par);
                    OOnly.first = hashTable[j].num;
                    OOnly.second = INFINITY;
                    pathDists.push_back(OOnly); //vertex and inf
                }
                contains = false;
            }
        }
    }
}

void Map::pathsInAns(int j)
{
    if(parent.at(j) == -1)
        return;

    HashStruct CollNum;
    CollNum.num = parent.at(j);
    CollNum.origin = "";
    CollNum.dest = "";
    CollNum.dist = j;
    ans.push_back(CollNum);
    pathsInAns(parent.at(j));


}

void Map::BFS(pair<int, double> key)
{
    bool found = false;
    bool one = true;
    bool sck = true;
    double smallest = 999999;
    int edge = 0;
    int curr = 0;
    int saveI = 0;

    for(int j = 0; j < pathDists.size(); j++)
    {
        if(pathDists.at(j).second != INFINITY)
        {
            one = false;
        }
    }
    if(one == true)
    {
       for(int j = 0; j < pathDists.size(); j++)
       {
           if(pathDists.at(j).first == key.first)
               pathDists.at(j).second = 0; //set start
       }
    }

    for(int i = 0; i < TABLE_SIZE; i++) //go through map to find current vertex
    {
        if(hashTable[i].num == key.first && hashTable[i].visited == false /*&& hashTable[i].num != */) //Now at the branches of key college
        {
                saveI = i; //for hashtable
                bool check = false;
                for(int j = 0; j < pathDists.size(); j++) //0-10
                {

                    if(pathDists.at(j).first == hashTable[i].num)
                    {
                        curr = j; //index of pathdists where hashtable is at current vertex

                    }
                }
                //if(parent.at(curr) == -1)
                //{
                for(int f = 0; f < TABLE_SIZE; f++) //go through list of colleges again to find end key
                {
                   if(hashTable[i].dest == hashTable[f].origin) //now at i's dest
                   {
                       if(hashTable[f].visited == false)
                           check = true;
                       //hashTable[f].visited = true;
                       for(int j = 0; j < pathDists.size(); j++)
                       {

                           if(pathDists.at(j).first == hashTable[f].num && check == true)//for each branch of key, find corresponding pathDist
                           {
                               if(pathDists.at(j).second > (hashTable[i].dist + pathDists.at(curr).second))
                               {   edge = j;//parent.at(curr) = hashTable[saveI].num;
                                   pathDists.at(edge).second = pathDists.at(curr).second + hashTable[i].dist; //only gives dist to saddlback(start)
                                   if(parent.at(edge) == -1)
                                   {
                                       parent.at(edge) = curr; //first run gives inital index
                                   }
                                   else
                                   {/*need ohio edge*/
                                       parent.at(edge) = curr; //if(hashTable[f].num == j+1)
                                   }
//s = hashTable[saveI].num; //save index of current for prev
                                   //{

                                   //}
                                   //update pathDists.second to total distance from start
                               }
                           }
                       }

                    }
                   //}
                }
                if(!ans.empty())
                {
                for(int g = 0; g < ans.size(); g++)
                {
                     if(ans.at(g).num == curr)
                         sck = false;
                }
                }
                if(smallest > pathDists.at(edge).second && smallest != pathDists.at(curr).second && sck == true)
                smallest = pathDists.at(edge).second;
hashTable[saveI].visited = true;
        }
    }
    bool det = false;
    for(int i =0; i < parent.size(); i++)
    {
        if(parent.at(i) != -1)
        {
            det = true;
        }
    }
    vector<bool> visited;
    visited.resize(saveI,false);
    list<int> queue;
    visited[curr] = true;
    queue.push_back(curr);
    while(!queue.empty()){
        curr = queue.front();
        queue.pop_front();

        }
}

void Map::DFS(int q)//start at UCI
{
    //check if hash been viisted

        double firstDistance = 0;
        double comparedDistance = 0;
        int key = 0;

        bool check = true;


        //qInfo() << "DFS:";
       for (int t = 0; t < TABLE_SIZE; t++)
        {

            if(hashTable[t].visited == false && hashTable[t].num != -1)
            check = false;



        }

        if(check != true)
        {

        for(int i = 0; i < TABLE_SIZE; i++)
        {

             if(hashTable[i].num ==  q && hashTable[i].visited == false && hashTable[i].num != -1)
             {
                // qInfo() << "DFS:";
                 hashTable[i].visited = true;

                 if(firstDistance == 0)
                 {
                     firstDistance = hashTable[i].dist;
                 }
                 comparedDistance = hashTable[i].dist;
                 if(comparedDistance < firstDistance)
                 {
                     //comparedDistance = firstDistance;
                    firstDistance = comparedDistance;

                 }


                /*for(int j = 0; j < TABLE_SIZE; j++)
                 {
                    if(hashTable[i].origin == hashTable[j].dest && hashTable[j].num != -1)
                        hashTable[j].visited = true;

                 }*/
               }


         }// end I forloop

         for(int u = 0; u < TABLE_SIZE; u++)
         {
             if(firstDistance == hashTable[u].dist && hashTable[u].num == q  && hashTable[u].num != -1)
             {
                    /*listWidgetOrigin -> addItem(hashTable[u].origin);
                    listWidgetDist -> addItem(hashTable[u].dist);
                    listWidgetDest -> addItem(hashTable[u].dest);*/


                        hashTable2[incr].num = hashTable[u].num;
                        hashTable2[incr].origin = hashTable[u].origin;
                        hashTable2[incr].dist = hashTable[u].dist;
                        hashTable2[incr].dest = hashTable[u].dest;
                        incr=incr+1;

                        totalDistanceDFS = hashTable[u].dist + totalDistanceDFS;

                         /*
                        qInfo() << hashTable[u].num;
                        qInfo() << hashTable[u].origin;
                        qInfo() << hashTable[u].dist;
                        qInfo() << hashTable[u].dest;
                        qInfo() << hashTable[u].visited;
                        qInfo() << " ";
                        */

                        for(int o = 0; o < TABLE_SIZE; o++)
                        {
                            if( hashTable[u].origin == hashTable[o].dest  )
                            {
                                hashTable[o].visited = true;
                            }
                         }

                        for(int p = 0; p < TABLE_SIZE; p++)
                        {
                            if(hashTable[p].origin == hashTable[u].dest && hashTable[p].num != -1 && hashTable[u].num != -1)
                                key = hashTable[p].num;
                        }
               }
          }//end U forloop
//         bool stop = true;
//         for (int t = 0; t < TABLE_SIZE; t++)
//          {

//              if(hashTable[t].visited == false)
//              stop = false;



//          }
//         if(stop == true)
         coll--;
         if(coll == 0)
             return;
     DFS(key);
    }//end visit if
}//end function


void Map::print()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        qInfo() << hashTable[i].num;
        qInfo() << hashTable[i].origin;
        qInfo() << hashTable[i].dist;
        qInfo() << hashTable[i].dest;
        qInfo() << hashTable[i].visited;
        qInfo() << " ";
    }
}

void Map::dijkstraNext(int pathIndex)
{
    int ind = 0;
    pair<int, double> key;
    key.first = pathIndex;
    key.second = 999;
    ans.clear();
    dijkstra(key);
    numToPrint.push_back(pathIndex);
    for(int i = 0; i < pathDists.size(); i++)
    {
        if(pathIndex == pathDists.at(i).first)
            ind = i;
    }
    pathDists.erase(pathDists.begin() + ind);
    double smallest = 9999;
    int Index = 0;
    for(int i = 0; i < pathDists.size(); i++)
    {
        if(smallest > pathDists.at(i).second)
        {
            Index = pathDists.at(i).first;
            smallest = pathDists.at(i).second;
        }
    }

    if(smallest != 9999)
    dist.push_back(smallest);
    for(int i = 0; i < pathDists.size(); i++)
    {
        pathDists.at(i).second = INFINITY;
    }
    for(int i = 0; i < TABLE_SIZE; i++)
    {
        hashTable[i].visited = false;
    }
    if(pathDists.size() != 0)
    {
        dijkstraNext(Index);
    }
    else
        return;
}
void Map::MST()
{
    double dist = 9999;
    HashStruct branch;
    bool checked = false;
    int index = 999;
    double destNum = 999;
    double branchNum = 999;
    for(int i = 0; i < TABLE_SIZE; i++)
    {
        checked = false;
        if(!ans.empty())
        {
            for(int j = 0; j < ans.size(); j++)
            {
                if((ans[j].origin == hashTable[i].origin && ans[j].dest == hashTable[i].dest) || (ans[j].origin == hashTable[i].dest && ans[j].dest == hashTable[i].origin))
                    checked = true;
            }
        }
        if(hashTable[i].dist < dist && checked == false && hashTable[i].num != -1 && hashTable[i].visited == false)
        {
            index = i;
            dist = hashTable[i].dist;
            branch.dist = hashTable[i].dist;
            branch.num = hashTable[i].num;
            branchNum = hashTable[i].num;
            branch.origin = hashTable[i].origin;
            branch.dest = hashTable[i].dest;
            for(int m = 0; m < TABLE_SIZE; m++)
            {
                if(branch.dest == hashTable[m].origin)
                    destNum = hashTable[m].num;
            }

        }
    }
    if(branch.num == -1)
        return;
    hashTable[index].visited = true;
    if(index != 999)
    {
//        for(int i = 0; i < TABLE_SIZE; i++)
//        {
//            if(hashTable[i].num == hashTable[index].num)
//
//        }
    }
    if(checked == false)
    {
        forMST.push_back({branchNum,destNum,branch.dist});
        //ans.push_back(branch);
    }
    if(coll > 0)
    {
        MST();
        coll--;
    }
}

