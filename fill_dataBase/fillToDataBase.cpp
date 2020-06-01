#include "fillToDataBase.h"

FillToDataBase::FillToDataBase()
{
    createDataBase();
    createTable();
}

void FillToDataBase::createDataBase()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("words");
    if(!db.open())
    {
        qDebug() << "Cannot open database: " << db.lastError();
    }
}

void FillToDataBase::createTable()
{
    QSqlQuery query;
    QString str = "CREATE TABLE English_Words"
                  "(eng_ID INTEGER PRIMARY KEY AUTOINCREMENT,"
                  " eng_word TEXT NOT NULL UNIQUE)";
    if(!query.exec(str))
    {
        qDebug() << "Unable to create a table";
    }
    str = "CREATE TABLE Russian_Words"
          "(rus_ID INTEGER PRIMARY KEY AUTOINCREMENT,"
          " rus_word TEXT NOT NULL UNIQUE)";
    if(!query.exec(str))
    {
        qDebug() << "Unable to create a table";
    }
    str = "CREATE TABLE Rus_Eng_Words"
          "(rus_eng_ID INTEGER PRIMARY KEY AUTOINCREMENT,"
          " rus_ID INTEGER,"
          " eng_ID INTEGER)";
    if(!query.exec(str))
    {
        qDebug() << "Unable to create a table";
    }
}

int FillToDataBase::insertData(QString request, QString firstQuery)
{
    int ID = 0;
    QSqlQuery query;
    if(!query.exec(request))
        qDebug() << "Unable to make insert operation" << request << endl;
    QSqlQueryModel model;
    model.setQuery(firstQuery);
    ID = model.data(model.index(0, 0)).toInt();
    return ID;
}

int FillToDataBase::searchWord(QString query)
{
    int id = 0;
    QSqlQueryModel model;
    model.setQuery(query);
    id = model.data(model.index(0, 0)).toInt();
    return id;
}

void FillToDataBase::fillDataBase(QString name)
{
    QFile file(name);
    QTextStream in(&file);
    QString firstWord, secondWord;

    if (!file.open(QIODevice::ReadOnly)) {
        qWarning("Cannot open file for reading");
    }

    int eng_ID = 0;
    int rus_ID = 0;

    while(!in.atEnd())
    {
        firstWord = in.readLine();
        QString firstQuery = "SELECT eng_ID FROM English_Words "
                             "WHERE eng_word='%1'";
        firstQuery = firstQuery.arg(firstWord);

        secondWord = in.readLine();
        QString secondQuery = "SELECT rus_ID FROM Russian_Words "
                             "WHERE rus_word='%1'";
        secondQuery = secondQuery.arg(secondWord);

        eng_ID = searchWord(firstQuery);
        if(eng_ID == 0)
        {
            QString ins = "INSERT INTO English_Words (eng_word)"
                          "VALUES ('%1')";
            ins = ins.arg(firstWord);
            eng_ID = insertData(ins, firstQuery);
        }

        rus_ID = searchWord(secondQuery);
        if(rus_ID == 0)
        {
            QString ins = "INSERT INTO Russian_Words (rus_word)"
                          "VALUES ('%1')";
            ins = ins.arg(secondWord);
            rus_ID = insertData(ins, secondQuery);
        }

        QString request = "INSERT INTO Rus_Eng_Words (rus_ID, eng_ID)"
                          "VALUES ('%1', '%2')";
        request = request.arg(rus_ID)
                         .arg(eng_ID);
        insertData(request, firstQuery);

        eng_ID = 0;
        rus_ID = 0;
    }
    file.close();
}
