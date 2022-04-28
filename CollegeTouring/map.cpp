#include "map.h"

//Map::Map()
void Map::insertHash(pair<int,double> key, QString origin, QString dest)
{
    for (int i = 0; i < TABLE_SIZE; i++) ///currently replaces duplicate dist
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

void Map::displayHash()
{
    //QString text = "";
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (hashTable[i].num != -1)
        {
        //qWarning() << QString::number(i) << " --> " << hashTable[i].num << ". " <<
        //hashTable[i].origin << " -> " << hashTable->dest;
        }
    }
}

void Map::putVectorinHere(vector<Campus> campuses)
{
    //string start = "";
    //string end = "";
    //TABLE_SIZE = campuses.size();
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

            //qWarning() << dist << "from: " << campuses.at(i).getStartCollege() << "To: " << endColleges;
        }
    }
    /*for(int i = 0; i < campuses.size(); i++)
    {
        for(int j = 0; j < campuses.at(i).getEndCollege().size(); j++)
        {
            insertHash(campuses.at(i).getDistances().at(j), campuses.at(i).getStartCollege(), campuses.at(i).getEndCollege().at(j));
        }
    }*/
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
                //s++;
            }
        }
    }
}

void Map::recurSelec(pair<int,double> key)
{


    QString curr = "";
    double smallest = 99999;
    int j = 0;
    pair<int,double> found;
    HashStruct newAns;
    QString ansOrigin;
    QString ansDest;
    if(ans.size() == 0)
    {
        int p = 0;
        for(int i = 0; i < TABLE_SIZE; i++)
        {
            if(hashTable[i].num == key.first && hashTable[i].select == true && hashTable[i].num != -1)
            {

                if(smallest > hashTable[i].dist)
                {
                   smallest = hashTable[i].dist;
                   curr = hashTable[i].dest;
                    p = i;
                   //j++;
                }


            }
        }
        ans.push_back(hashTable[p]);
    }
    for(int i = 0; i < TABLE_SIZE; i++)
    {
        for(int m = 0; m < ans.size(); m++)
        {
            ansOrigin = ans.at(m).origin;
            ansDest = ans.at(m).dest;
            QString hashDest = hashTable[i].dest;
        if(hashTable[i].num == key.first && hashTable[i].select == true && hashTable[i].num != -1 && ansOrigin != hashDest && ansDest == hashTable[i].origin && ansDest != hashDest && smallest > hashTable[i].dist)
        {

                  smallest = hashTable[i].dist;
                  curr = hashDest;
                  j = i;
                 // j = i;
               }
            }


        }
   // }


    //smallest found, now go through map to find origin of smallest dist.

    for(int i = 0; i < TABLE_SIZE; i++)
    {
        for(int m = 0; m < ans.size(); m++)
        {
            ansOrigin = ans.at(m).origin;
            ansDest = ans.at(m).dest;
            if(hashTable[i].origin == curr && hashTable[i].select == true && ansDest != hashTable[i].dest && hashTable[i].num != -1 && ansOrigin != hashTable[i].dest)
            {
                found.first = hashTable[i].num;
                found.second = hashTable[i].dist;
               /* newAns.num = j;
                newAns.dist = found.second;
                newAns.origin = hashTable[j].origin;
                newAns.dest = hashTable[j].dest;
                newAns.select = hashTable[j].select;*/
                //go to the smallest
            }
        }
    }
   /* if(ans.size() == 0)
    {
        ans.push_back(hashTable[j]); //for start of trip
        recurSelec(found);
    }*/
    //found.first = hashTable[j].num;
    //found.second = hashTable[j].dist;
    if(ans.size() >= s)
    {
        return;
    }
    if(found.first != key.first && ans.size() >= 1)
    {   // ans.push_back(hashTable[j]);
    ans.push_back(hashTable[j]); //insert smallest branch into answer

    }
    bool check = false;
    for(int m = 0; m < ans.size(); m++)
    {
            if(ans.at(m).dest == curr)
                check = true;
    }
    if(check == true)
    recurSelec(found);
    else
    recurSelec(key);
    smallest = 99999;

}
