#ifndef PROGRAMMODEL_H
#define PROGRAMMODEL_H

#include <QtSql>

class ProgramModel
{
public:
    ProgramModel();
    ~ProgramModel();
    bool authorization(QMap<QString, QString> fields);
    bool registration(QMap<QString, QString> fields);
    bool findData(QString field, QString value);

private:
    void createDatabase();
    void createTables();
    bool insertData(QString* name, QString* values);
};

#endif // PROGRAMMODEL_H
