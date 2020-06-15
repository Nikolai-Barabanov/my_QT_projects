#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql>
#include <QObject>

class DataBase
{
public:
    DataBase();
    ~DataBase();
    void createDataBase();
    void createTable();
    bool insertData(QMap<QString, QString> fields);
    bool findData(QString field, QString value);
private:
    QSqlDatabase base;
};

#endif // DATABASE_H
