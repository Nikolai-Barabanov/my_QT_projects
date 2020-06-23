#include "programmodel.h"

ProgramModel::ProgramModel()
{
    createDatabase();
    createTables();
}

ProgramModel::~ProgramModel()
{

}

void ProgramModel::createDatabase()
{
    QSqlDatabase myDatabase = QSqlDatabase::addDatabase("QSQLITE");
    myDatabase.setDatabaseName("Users");

    if(!myDatabase.open())
        qDebug() << "Cannot open database" << myDatabase.lastError() << endl;
}

void ProgramModel::createTables()
{
    QSqlQuery query;
    QString text = "CREATE TABLE Users "
                   "(User_ID INTEGER PRIMARY KEY AUTOINCREMENT,"
                   " Name Text NOT NULL, "
                   " Login TEXT NOT NULL UNIQUE, "
                   " Password TEXT NOT NULL CHECK(LENGTH(Password) > 7))";
    if(!query.exec(text))
        qDebug() << "Cannot create users table  " << query.lastError() << endl;

    text = "CREATE TABLE Tasks "
           "(Task_ID INTEGER PRIMARY KEY AUTOINCREMENT, "
           " DescriptionOfTask TEXT NOT NULL, "
           " Answer INTEGER NOT NULL)";
    if(!query.exec(text))
        qDebug() << "Cannot create tasks table  " << query.lastError() << endl;
}

bool ProgramModel::authorization(QMap<QString, QString> fields)
{
    QSqlQuery query;
    QSqlRecord record;
    QString text = "SELECT * FROM Users "
                   "WHERE Login = '%1' "
                   "AND Password = '%2'";
    text = text.arg(fields["login"])
               .arg(fields["password"]);

    if(!query.exec(text))
        qDebug() << "Cannot execute query  " << query.lastError() << endl;
    else
    {
        query.first();
        record = query.record();
        QString myLogin = record.value("Login").toString();
        QString myPass = record.value("Password").toString();
        if(myLogin == fields["login"] && myPass == fields["password"])
            return true;
    }
    return false;
}

bool ProgramModel::registration(QMap<QString, QString> fields)
{
    QString name = "Users (Name, Login, Password)";
    QString values = "('%1', '%2', '%3')";
    values = values.arg(fields["name"])
                   .arg(fields["login"])
                   .arg(fields["password"]);
    if(insertData(&name, &values))
        return true;
    return false;
}

bool ProgramModel::insertData(QString* name, QString* values)
{
    QSqlQuery query;
    QString text = "INSERT INTO " + *name + " VALUES " + *values ;
    if(!query.exec(text))
    {
        qDebug() << "Cannot insert data  " << query.lastError() << endl;
        return false;
    }
    return true;
}

bool ProgramModel::findData(QString field, QString value)
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
