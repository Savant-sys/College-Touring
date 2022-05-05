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
    HashStruct ansCheck;
    ansCheck.num = hashTable[saveI].num;
    ans.push_back(ansCheck);
    bool proceed = true;
    for(int i = 0; i < pathDists.size(); i++)
    {
        for(int j = 0; j < ans.size(); j++)
        {
             if(ans.at(j).num == i)
                 proceed = false;
}
        if(pathDists.at(i).second <= small && pathDists.at(i).first != key.first && pathDists.at(i).second != 0 && proceed == true)
        //if(pathDists.at(i).second == smallest && pathDists.at(i).first != key.first)
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

void Map::initPathDist(int size) // for dijkstra
{
    coll = size;
    pair<int, double> OOnly;
    int par = -1;
    OOnly.first = -1;
    OOnly.second = INFINITY;

               for(int i = 0; i < size; i++)
               {
                //par = i;
                parent.push_back(par);
                OOnly.first = i;
                OOnly.second = INFINITY;
                pathDists.push_back(OOnly); //vertex and inf
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
