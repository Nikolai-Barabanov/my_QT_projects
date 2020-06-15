#include "database.h"

DataBase::DataBase()
{

}

DataBase::~DataBase()
{

}

void DataBase::createDataBase()
{
    base = QSqlDatabase::addDatabase("QSQLITE");
    base.setDatabaseName("Users");
    if(!base.open())
        qDebug() << "Database not open " << base.lastError() << endl;
}

void DataBase::createTable()
{
    QSqlQuery query;
    QString text = "CREATE TABLE Users "
                   "(User_ID INTEGER PRIMARY KEY AUTOINCREMENT,"
                   " Name TEXT NOT NULL, "
                   " Login TEXT UNIQUE NOT NULL, "
                   " Surname TEXT NOT NULL, "
                   " Email TEXT NOT NULL UNIQUE, "
                   " Phone TEXT NOT NULL UNIQUE CHECK(LENGTH(Phone) = 11), "
                   " Password TEXT NOT NULL CHECK(LENGTH(Password) > 7))";
    if(!query.exec(text))
        qDebug() << "Cannot create table " << query.lastError() << endl;
}

bool DataBase::insertData(QMap<QString, QString> fields)
{
    QSqlQuery query;
    QString text = "INSERT INTO Users (Name, Login, Surname, Email, Phone, Password) "
                   "VALUES ('%1', '%2', '%3', '%4', '%5', '%6')";
    text = text.arg(fields["name"])
            .arg(fields["login"])
            .arg(fields["surname"])
            .arg(fields["email"])
            .arg(fields["phone"])
            .arg(fields["password"]);
    if(!query.exec(text))
    {
        qDebug() << "Cannot execute query " << query.lastError() << endl;
        return false;
    }
    return true;
}

bool DataBase::findData(QString field, QString value)
{
    QSqlQuery query;
    QSqlRecord record;
    QString text = "SELECT * FROM Users "
                   "WHERE %1 = '%2'";
    text = text.arg(field)
               .arg(value);
    if(!query.exec(text))
    {
        qDebug() << "Query is not complete" << query.lastError();
        return false;
    }
    record = query.record();
    query.first();
    QString val = query.value(record.indexOf(field)).toString();
    if(val == value)
        return true;
    return false;
}
