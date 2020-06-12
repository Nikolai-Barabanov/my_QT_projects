#ifndef DATA_BASE_H
#define DATA_BASE_H

#include <QtSql>
#include <QObject>

class dataBase
{
public:
    dataBase();
    ~dataBase();
    bool createDataBase();
    bool createTable();
    bool insertData();
    bool authorisation(QString* name, QString* pass);

private:
    QSqlDatabase base;
};
#endif // DATA_BASE_H
