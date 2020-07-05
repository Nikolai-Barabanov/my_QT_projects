#include "ProgramModel.h"

ProgramModel::ProgramModel()
{
    openDatabase();    
    queryModel = new QSqlQueryModel();
}

ProgramModel::~ProgramModel()
{

}

void ProgramModel::openDatabase()
{
    QSqlDatabase myDatabase = QSqlDatabase::addDatabase("QSQLITE");
    myDatabase.setDatabaseName("sample.db");

    if(!myDatabase.open())
        qDebug() << "Cannot open database" << myDatabase.lastError() << endl;
}

QSqlQueryModel *ProgramModel::getQueryModel(QString tableName)
{
    QSqlQuery query;
    QString text = "SELECT DATETIME(Time, 'unixepoch') AS Time, "
                   "Value, Number FROM %1 ";
    text = text.arg(tableName);
    query.exec(text);
    queryModel->setQuery(query);
    if(queryModel->lastError().isValid())
        qDebug() << queryModel->lastError();
    return queryModel;
}

QDateTime ProgramModel::getData(int rowNumber)
{    
    QSqlRecord rec = queryModel->record(rowNumber);
    //qDebug() << rec.value(0).toDateTime() << endl;
    return rec.value(0).toDateTime();
}

double ProgramModel::getValue(int rowNumber)
{
    QSqlRecord rec = queryModel->record(rowNumber);   
    return rec.value(1).toDouble();
}

double ProgramModel::getGroup(int rowNumber)
{
    QSqlRecord rec = queryModel->record(rowNumber);
    return rec.value(2).toDouble();
}

int ProgramModel::getMaximum(QString tableName)
{
    QSqlQuery query;
    QString text = "SELECT COUNT(Time) FROM %1 ";
    text = text.arg(tableName);
    query.exec(text);
    query.first();
    count = query.value(0).toInt();
    return count;
}
