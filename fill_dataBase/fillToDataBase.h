#ifndef FILLTODATABASE_H
#define FILLTODATABASE_H

#include <QFile>
#include <QTextStream>
#include <QtSql>

class FillToDataBase
{
public:
    explicit FillToDataBase();
    void fillDataBase(QString name);
private:
    int insertData(QString request, QString firstQuery);
    int searchWord(QString query);
    void createDataBase();
    void createTable();
};

#endif // FILLTODATABASE_H
