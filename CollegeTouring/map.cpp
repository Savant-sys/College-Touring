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
