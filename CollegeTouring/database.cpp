#include "database.h"

Database::Database()
{
    QDir::setCurrent(QCoreApplication::applicationDirPath());
    QDir tempDir = QDir::currentPath();
    qDebug() << tempDir;
    tempDir.cdUp();
    tempDir.cdUp();

    QString s = tempDir.path() + "/db";

    QDir::setCurrent(s);
    filePath = s + "/CollegeTouring.db";

    infile = s + "/New Campuses.csv";
    infileS = s + "/New Souvenirs.csv";

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

    QFile q_file(infile);
    QFile q_fileS(infileS);

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

//    for(int i = 0; i < rows.size(); i++)
//    {
//        qInfo() << rows[i] << "\n";
//    }
//    qInfo() << "TEST FOR READ: " << rows[1];
//qInfo() << "\nTEST FOR ROWS:\n";


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
//    for (int i =0; i < rowsS.size(); i++){
//        qInfo() << rowsS[i] << "\n";
//    }

    //for (int i = 0; i < .size(); i++)
        //qInfo() << "Test for souvrowsS: " << rowsS[i];

    QString startCollege;
    QString start = rows[1][0];
    vector<QString> endCollege;
    vector<double> distances;
    QString state;
    int undergrads;

    Souvenir menu;
    vector<Souvenir> menuVector;


    for (int i = 1; i < rows.size(); i++)
    {
        if (rows[i][0] == "Arizona State University")
                {
                    for (int s = i; s < rows.size(); s++)
                    {
                    startCollege = rows[s][0];
                    endCollege.push_back(rows[s][1]);
                    endCollege.push_back(rows[s+1][1]);
                    distances.push_back(rows[s][2].toDouble());
                    distances.push_back(rows[s+1][2].toDouble());


                    state = "";
                    undergrads = 0;
                    menuVector.clear();
                    qInfo () << startCollege;
                    for (int k = 0; k < endCollege.size(); k++)
                        qInfo () << "\ntest for new new distances: " << endCollege[k];
                    Campus campus(startCollege, endCollege, distances, state, undergrads, menuVector);
                    newCampuses.push_back(campus);
                    s++;

                    endCollege.clear();
                    distances.clear();
                    }
                    break;
                }
//        for (int k = 0; k < rows[i].size(); k++)
//        {
            startCollege = rows[i][0];
            endCollege.push_back(rows[i][1]);
            distances.push_back(rows[i][2].toDouble());
            if (rows[i][3] != "")
            {
                state = rows[i][3];
            }
            if (rows[i][4] != "")
            {
                undergrads = rows[i][4].toInt();
            }
            if (i + 1 == rows.size())
            {
                for (int j = 0; j < rowsS.size(); j++)
                {
                    if (startCollege == rowsS[j][0])
                    {
                        for (int k = j + 1; k < rowsS.size(); k++)
                        {
                            if (rowsS[k][0] == "")
                            {
                                menu.name = rowsS[k][1];
                                QVector<QStringList> sp;
                                QRegularExpression separatorm("[$| ]");
                                sp.push_back(rowsS[k][2].split(separatorm));
                                menu.price = sp[0][1].toDouble();
    //                            qInfo() << "TEST MENU PRICE: " /*<< menu.price << " - " */<< sp[0] << "\n";
                                sp.clear();
    //                              menu.price = rowsS[k][1];
                                menuVector.push_back(menu);
                            }
                            else break;
                        }
                    }
                }
                Campus campus(startCollege, endCollege, distances, state, undergrads, menuVector);
                newCampuses.push_back(campus);
//                for (int k = 0; k < endCollege.size(); k++)
//                    qInfo () << "\n" << endCollege[k].split("\"");
                menuVector.clear();
                endCollege.clear();
                distances.clear();
                break;
            }
//        }
        if(rows[i+1][0] != start)
        {
            for (int j = 0; j < rowsS.size(); j++)
            {
                if (startCollege == rowsS[j][0])
                {
                    for (int k = j + 1; k < rowsS.size(); k++)
                    {
                        if (rowsS[k][0] == "")
                        {
                            menu.name = rowsS[k][1];
                            QVector<QStringList> sp;
                            QRegularExpression separatorm("[$| ]");
                            sp.push_back(rowsS[k][2].split(separatorm));
                            menu.price = sp[0][1].toDouble();
//                            qInfo() << "TEST MENU PRICE: " /*<< menu.price << " - " */<< sp[0] << "\n";
                            sp.clear();
//                              menu.price = rowsS[k][1];
                            menuVector.push_back(menu);
                        }
                        else
                            break;
                    }
                }
            }
            start = rows[i + 1][0];
            Campus campus(startCollege, endCollege, distances, state, undergrads, menuVector);
            newCampuses.push_back(campus);
//            for (int k = 0; k < endCollege.size(); k++)
//                qInfo () << "\n" << endCollege[k].split("\"");
            menuVector.clear();
            endCollege.clear();
            distances.clear();
        }
    }

//    qInfo() << "\nTEST TO PRINT NEW COLLEGES:" << newCampuses.size();
//    for (int i = 0; i < newCampuses.size(); i++){
//        Campus campus(newCampuses[i]);
//        qInfo() << "\n" << campus.getStartCollege() << ", " << campus.getState() << ", " << campus.getUndergrads();
//        qInfo() << "\nTEST NUMBER OF MENU: " << campus.getMenu().size() << "\n";
//        for (int k = 0; k < campus.getMenu().size(); k++)
//        {
//            vector<Souvenir> s = campus.getMenu();
//            qInfo() << "\n" << s[k].name;

//        }
//        qInfo () << "\nTEST NUMBER OF END COLLEGE: ";// << campus.getEndCollege().size();
////        for (int j = 0; campus.getEndCollege().size(); j++)
////        {
////            vector<QString> q = campus.getEndCollege();
////            //qInfo() << q.size();
////            //qInfo () << "\n" << q[j];
////        }
//    }

//    for (int i = 0; i < newCampuses.size();i++)
//    {
//        qInfo () <<"\nTEST new campuses: " << newCampuses[i].getStartCollege() << " : " << i;
//    }
    return newCampuses;
}

void Database::addCampuses(vector<Campus> campuses)
{


    for(int i = 0; i < campuses.size(); i++)
    {
        Campus currCampus = campuses[i];
//qInfo () << "\nTEST CAMPUSES COUNT FOR NEW: " << campuses[0].getStartCollege();
        if (i > 1)
        {
//            QJsonArray endCollege;
//            endCollege.push_back(campuses[2].getEndCollege()[0]);
//            endCollege.push_back(campuses[2].getEndCollege()[1]);
//            QString id = campuses[i].getStartCollege();
//            //int id = campus.getId();
//            //QString idToString = QString::number(id);

//            QSqlQuery query;

//            QJsonDocument endCollegeDoc(endCollege);

//            query.prepare("UPDATE campuses SET Ending_College = :newendcollege WHERE Starting_College = :idediting");
//            query.bindValue(":newendcollege", endCollegeDoc.toJson());
//            query.bindValue(":idediting", id);

//            if (query.exec()){
//                qInfo() << "Inserted";
//            } else {
//                qInfo() << "Error, " << query.lastError();
//            }
            break;

        }else{

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

//        qInfo() << "\nDb open? " << this->db.open();
//        qInfo() << "Menu 1: " << distances.at(1);

        QJsonDocument endCollegeDoc(endCollege);
        QJsonDocument distancesDoc(distances);
        QJsonDocument menusDoc(menu);
        qInfo() << "START CAMPUS: " << startCampus;
        qInfo () << "STATE: " << state;
        qInfo () << "UNDERGRADS: " << undergrads;

        query.prepare("INSERT INTO campuses (Starting_College, Ending_College, Distance_Between, State, Number_of_undergrads, Souvenirs)" "VALUES(:Starting_College, :Ending_College, :Distance_Between, :State, :Number_of_undergrads, :Souvenirs)");
        query.bindValue(":Starting_College", startCampus);
        query.bindValue(":Ending_College", endCollegeDoc.toJson());
        query.bindValue(":Distance_Between", distancesDoc.toJson());
        query.bindValue(":State", state);
        query.bindValue(":Number_of_undergrads", undergrads);
        query.bindValue(":Souvenirs", menusDoc.toJson());

        //qInfo() << query.boundValues().size();
        if (query.exec())
            qInfo() << "\nInserted";
        else
            qInfo() << "\nError, " << query.lastError() << "\n";

    }
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

        QJsonDocument jsonD = QJsonDocument::fromJson(distances.toUtf8());
        QJsonDocument jsonE = QJsonDocument::fromJson(endCollege.toUtf8());

        QJsonArray jsonArrayD = jsonD.array();
        QJsonArray jsonArrayE = jsonE.array();

        for (int i = 0; i < jsonArrayE.size(); i++){
            endCollegeVector.push_back(jsonArrayE.at(i).toString());
//            qInfo () << "\n" << endCollegeVector[i];
        }
//        qInfo() << "\ndone";

        for (int i = 0; i < jsonArrayD.size(); i++)
            distancesVector.push_back(jsonArrayD.at(i).toDouble());


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

        //make our new campus
        Campus newCampus(startCollege, endCollegeVector, distancesVector, state, undergrads, menuVector);
        campuses.push_back(newCampus);
    }
    //qInfo() << "\ntest for getCampuses function\n";
    return true;

}

void Database::modifySouvenir(Campus campus, vector<Souvenir> menu)
{
    //modify menu given restaurant
        //function will serialize menu with json and save as TEXT/STRING in 'menu' columns where restaurant is passed in restaurant
        //find proper restaurant by looking at restaurant id then query sql database based on that

        //returns true if operation is completed

        QJsonArray menuItems;

        for (int i = 0; i < menu.size(); i++)
        {
            auto item = QJsonObject(
            {
            qMakePair(QString("name"), QJsonValue(menu[i].name)),
            qMakePair(QString("price"), QJsonValue(menu[i].price))
            });

            menuItems.push_back(QJsonValue(item));

        }
        QString id = campus.getStartCollege();
        //int id = campus.getId();
        //QString idToString = QString::number(id);

        QSqlQuery query;

        QJsonDocument menuDoc(menuItems);

        query.prepare("UPDATE campuses SET Souvenirs = :newmenu WHERE Starting_College = :idediting");
        query.bindValue(":newmenu", menuDoc.toJson());
        query.bindValue(":idediting", id);

        if (query.exec()){
            qInfo() << "Inserted";
        } else {
            qInfo() << "Error, " << query.lastError();
        }
}

void Database::updateNewColleges(Campus campus, vector<QString> endCollegeVector, vector<double> distancesVector)
{
    QJsonArray endCollege;

    for (int i = 0; i < endCollegeVector.size(); i++)
    {
        endCollege.push_back(endCollegeVector[i]);
    }

    QJsonArray distances;

    for (int i = 0; i < distancesVector.size(); i++)
    {
        distances.push_back(distancesVector[i]);
    }

    QString id = campus.getStartCollege();
    //int id = campus.getId();
    //QString idToString = QString::number(id);

    QSqlQuery query;

    QJsonDocument endCollegeDoc(endCollege);
    QJsonDocument distancesDoc(distances);

    query.prepare("UPDATE campuses SET Ending_College = :newendcollege, Distance_Between = :newdistance WHERE Starting_College = :idediting");
    query.bindValue(":newendcollege", endCollegeDoc.toJson());
    query.bindValue(":newdistance", distancesDoc.toJson());
    query.bindValue(":idediting", id);

    if (query.exec()){
        qInfo() << "Inserted";
    } else {
        qInfo() << "Error, " << query.lastError();
    }

}
