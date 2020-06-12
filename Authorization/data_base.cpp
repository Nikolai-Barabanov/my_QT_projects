#include "data_base.h"

dataBase::dataBase()
{

}

dataBase::~dataBase()
{

}

bool dataBase::createDataBase()
{
   base = QSqlDatabase::addDatabase("QSQLITE");
   base.setDatabaseName("Users");

   if(!base.open())
   {
       qDebug() << "Data base not open" << base.lastError() << endl;
       return false;
   }
   return true;
}

bool dataBase::createTable()
{
    QSqlQuery query;
    QString text = "CREATE TABLE Users "
                   "(User_ID INTEGER PRIMARY KEY AUTOINCREMENT,"
                   " Name TEXT NOT NULL,"
                   " Login TEXT NOT NULL UNIQUE,"
                   " Surname TEXT NOT NULL,"
                   " Email TEXT UNIQUE,"
                   " Phone TEXT UNIQUE CHECK(LENGTH(Phone)=11),"
                   " Password TEXT NOT NULL CHECK(LENGTH(Password)>7))";
    if(!query.exec(text))
    {
        qDebug() << "Can not create table" << query.lastError() << endl;
        return false;
    }
    return true;
}

bool dataBase::insertData()
{
    QSqlQuery query;
    QString text = "INSERT INTO Users (Name, Login, Surname, Email, Phone, Password) "
                   "VALUES ('Ivan', 'Ivan', 'Ivanov', 'Ivan@mail.ru', '00000000000', '12345678')";
    if(!query.exec(text))
    {
        qDebug() << "Cannot insert data" << query.lastError() << endl;
        return false;
    }
    return true;
}

bool dataBase::authorisation(QString* login, QString* pass)
{
    QSqlQuery query;
    QSqlRecord record;
    QString text = "SELECT * FROM Users "
                   "WHERE Login = '%1' "
                   "AND Password = '%2' ";
    text = text.arg(*login)
               .arg(*pass);

    if(!query.exec(text))
    {
        qDebug() << "User not found " << query.lastError() << endl;
        return false;
    }
    record = query.record();
    query.first();
    QString l = query.value(record.indexOf("Login")).toString();
    QString p = query.value(record.indexOf("Password")).toString();
    if(l == *login && p == *pass && login->size() > 0)
        return true;

    return false;
}
