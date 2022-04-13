#include "Database.h"

Database::Database()
{
    filePath = "C:/Users/Michael/Desktop/Project 2/db/CollegeTouring.db";

    infile = "C:/Users/Michael/Desktop/Project 2/db/New Campuses.csv";
    infileS = "C:/Users/Michael/Desktop/Project 2/db/New Souvenirs.csv";

    //connects to "Campuses.csv" and "Souvenirs.csv"
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(filePath);

    if (db.open())
        qInfo() << "Database connection established!";
    else
        qInfo() << "Database connection error occured.";
}

vector<Campus> Database::readFile()
{
    vector<Campus> newCampuses;

    QFile q_file(filePath);
    QFile q_fileS(filePathS);

    QString data;
    QStringList rawRows;
    QVector<QStringList> rows;

    QString dataS;
    QStringList rawRowsS;
    QVector<QStringList> rowsS;

    QRegularExpression separator("[\n|\r]");

    if(q_file.open(QFile::ReadOnly))
    {
        data = q_file.readAll();
        rawRows = data.split(separator);
        q_file.close();
        for (int i = 0; i < rawRows.size(); i++)
        {
            if(rawRows[i] != "")
               rows.push_back(rawRows[i].split(","));
        }
    }
    else
        qInfo() << "error open Campuses";

    for (int i = 0; i < rows.size(); i++)
        qInfo() << rows[i];

    if(q_fileS.open(QFile::ReadOnly))
    {
        dataS = q_fileS.readAll();
        rawRowsS = dataS.split(separator);
        q_fileS.close();
        for (int i = 0; i < rawRowsS.size(); i++)
        {
            if(rawRowsS[i] != "")
               rowsS.push_back(rawRowsS[i].split(","));
        }
    }
    else
        qInfo() << "error open Souvenirs";


    //for (int i = 0; i < rowsS.size(); i++)
        //qInfo() << "Test for souv: " << rowsS[i];

    QString startCollege;
    vector<QString> endCollege;
    vector<double> distances;
    double stringToDouble;
    QString state;
    int undergrads;
    QString word;

    Souvenir menu;
    vector<Souvenir> menuVector;

    int extra = 0;
    word = rows[1][0];
    if (word[1] == '\"')
    {
        word += ", " + rows[1][1];
        startCollege = word;

        extra = 1;
    }
    else
        startCollege = rows[1][0];
    state = rows[1][3];
    undergrads = rows[1][4].toInt();

//    menu.item = rowsS[1][1];
//    menu.price = rowsS[1][2].toDouble();
//    menuVector.push_back(menu);

    for (int i = 1 + extra; i < rows.size(); i++)
    {
        extra = 0;
//        for (int k = 0; k < rowsS.size(); k++)
//        {
//            if (startCollege == rowsS[k][0])
//            {
//                for (int j = 0; j < rowsS.size(); j++)
//                {
//                    if (rowsS[j][0] == "")
//                    {
//                        menu.item = rowsS[j][1];
//                        menu.price = rowsS[j][2].toDouble();
//                        menuVector.push_back(menu);
//                        break;
//                    }
//                }
//                break;
//            }
//        }
        if (startCollege == rows[i][0] || startCollege == rows[i][0]+ ", " + rows[i][1])
        {


            word = rows[i][1];
            if (word[0] == '\"')
            {
                word += ", " + rows[i][2];
                extra = 1;
                endCollege.push_back(word);
            }
            else
                endCollege.push_back(rows[i][1]);

            stringToDouble = rows[i][2+extra].toDouble();
            distances.push_back(stringToDouble);

//            menu.item = rowsS[i][1];
//            menu.price = rowsS[i][2].toDouble();
//            menuVector.push_back(menu);

            if (i == rows.size()-1)
            {
                Campus campus(startCollege, endCollege, distances, state, undergrads, menuVector);
                newCampuses.push_back(campus);
                endCollege.clear();
                menuVector.clear();
            }
         }
         else
         {
            Campus campus(startCollege, endCollege, distances, state, undergrads, menuVector);
            newCampuses.push_back(campus);
            endCollege.clear();
            menuVector.clear();

            word = rows[i][0];
            if (word[0] == '\"')
            {
                word += ", " + rows[i][1];
                extra = 1;
                startCollege = word;
             }
             else
                startCollege = rows[i][0];
             state = rows[i][3+extra];
             undergrads = rows[i][4+extra].toInt();

             word = rows[i][1];
             if (word[0] == '\"')
             {
                word += ", " + rows[i][2];
                extra = 1;
                endCollege.push_back(word);
             }
             else
                endCollege.push_back(rows[i][1]);

              stringToDouble = rows[i][2+extra].toDouble();
              distances.push_back(stringToDouble);

//              menu.item = rowsS[i][1];
//              menu.price = rowsS[i][2].toDouble();
//              menuVector.push_back(menu);
        }
    }

//    for (int i = 0; i < rowsS.size(); i++)
//    {
//        if (rowsS[i][0] == "")
//        {
//            menu.item = rowsS[i][1];
//            menu.price = rowsS[i][2].toDouble();
//            menuVector.push_back(menu);
//            break;
//        }
//    }

//    for (int i = 0; i < newCampuses.size(); i++)
//    {
//        vector<Souvenir> menuList = newCampuses[i].getMenu();
//        for (int j = 0; j < menuList.size(); j++)
//        {
//            Souvenir test = menuList[j];
//            qInfo() << test.item << " - $" << test.price << "\n";
//        }

//    }
    return newCampuses;
}

void Database::addCampuses(vector<Campus> campuses)
{
    for(int i = 0; i < campuses.size(); i++)
    {
        Campus currCampus = campuses[i];

        QString startCampus = currCampus.getStartCollege();
        vector<QString> endCollegeVector = currCampus.getEndCollege();
        vector<double> distancesVector = currCampus.getDistances();
        QString state = currCampus.getState();
        int undergrads = currCampus.getUndergrads();
        vector<Souvenir> menuVector = currCampus.getMenu();

        QJsonArray endCollege;
        for (int i = 0; i < endCollegeVector.size(); i++)
            endCollege.push_back(endCollegeVector[i]);

        QJsonArray distances;
        for (int i = 0; i < distancesVector.size(); i++)
            distances.push_back(distancesVector[i]);

        QJsonArray menu;
        for (int i = 0; i < menuVector.size(); i++)
        {
            auto item = QJsonObject
                    ({
                         qMakePair(QString("name"), QJsonValue(menuVector[i].name)),
                         qMakePair(QString("price"), QJsonValue(menuVector[i].price))
                     });
            menu.push_back(QJsonValue(item));
        }

        QSqlQuery query;

        qInfo() << "Db open? " << this->db.open();
        qInfo() << "Menu 1: " << distances.at(1);

        QJsonDocument endCollegeDoc(endCollege);
        QJsonDocument distancesDoc(distances);
        QJsonDocument menusDoc(menu);

        query.prepare("INSERT INTO CollegeTouring (Starting College, Ending College, Distance Between, State, Number of undergrads, Souvenirs" "VALUES(:Starting College, :Ending College, :Distance Between, :State, :Number of undergrads, :Souvenirs)");
        query.bindValue(":Starting College", startCampus);
        query.bindValue(":Ending College", endCollegeDoc.toJson());
        query.bindValue(":Distance Between", distancesDoc.toJson());
        query.bindValue(":State", state);
        query.bindValue(":Number of undergrads", undergrads);
        query.bindValue(":Souvenirs", menusDoc.toJson());

        qInfo() << query.boundValues().size();
        if (query.exec())
            qInfo() << "Inserted";
        else
            qInfo() << "Error, " << query.lastError();
    }
}

bool Database::getCampuses(vector<Campus>& campuses)
{
    if (campuses.size() > 0)
    {
        campuses.clear();
    }
    //modified passed in campuses vector

    //query all campuses in campuses table
    QSqlQuery query("select * from campuses");
    QSqlRecord rec = query.record();
    while (query.next())
    {
        vector<double> distancesVector;
        vector<QString> endCollegeVector;
        vector<Souvenir> menuVector;

        //Putting column data into variables
        QString startCollege = query.value(0).toString();
        QString endCollege = query.value(1).toString();
        QString distances = query.value(2).toString();
        QString state = query.value(3).toString();
        int undergrads = query.value(4).toInt();
        QString menu = query.value(5).toString();

        QJsonDocument json = QJsonDocument::fromJson(distances.toUtf8());
        QJsonArray jsonArray = json.array();

        for (int i = 0; i < jsonArray.size(); i++)
           endCollegeVector.push_back(jsonArray.at(i).toString());

        for (int i = 0; i < jsonArray.size(); i++)
            distancesVector.push_back(jsonArray.at(i).toDouble());


        QJsonDocument jsonDoc = QJsonDocument::fromJson(menu.toUtf8());
                QJsonArray jsonarray = jsonDoc.array();

                for (int i = 0; i < jsonarray.size(); i++)
                {
                    QJsonObject jsonObject = jsonarray.at(i).toObject();
                    if(jsonObject.isEmpty())
                    {
                        qInfo() << "Json is empty";
                    }
                    else
                    {
                        Souvenir item;
                        item.name = jsonObject.value("name").toString();
                        item.price = jsonObject.value("price").toDouble();
                        menuVector.push_back(item);

                    }
                }

        //make our new restaurant
        Campus newCampus(id, name, menuVector, distancesVector, saddlebackDistance);
        campuses.push_back(newCampus);
    }
    qInfo() << "\ntest for getCampuses function\n";
    return true;

}
