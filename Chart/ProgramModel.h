#ifndef PROGRAMMODEL_H
#define PROGRAMMODEL_H

#include <QtSql>
#include <QDateTime>

class ProgramModel
{
public:
    ProgramModel();
    ~ProgramModel();    
    QSqlQueryModel* getQueryModel(QString tableName);
    QDateTime getData(int rowNumber);
    double getValue(int rowNumber);
    double getGroup(int rowNumber);
    int getMaximum(QString tableName);
private:
    int count = 0;
    QSqlQueryModel* queryModel;
    void openDatabase();
};

#endif // PROGRAMMODEL_H
