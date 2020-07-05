#ifndef PROGRAMACTION_H
#define PROGRAMACTION_H

#include <QObject>
#include <QChart>
#include <QLineSeries>
#include <QValueAxis>
#include <QDateTimeAxis>
#include "ProgramModel.h"


using namespace QtCharts;

class ProgramAction : public QObject
{
    Q_OBJECT
public:
    explicit ProgramAction(QObject* parent = nullptr);
    ~ProgramAction();    
    QSqlQueryModel* getQueryModel(QString tableName);
    void createChart();
    QString getTableName();

signals:
    void update(QChart* chart);

private:
    void createAxis();
    void createSeries();
    void compareTime(QDateTime time);

    ProgramModel* myDatabase;
    QLineSeries* lineSeries;
    QDateTimeAxis* axisX;
    QValueAxis* axisY;
    QChart* chart;
    QString tableName;

    double minY = 0;
    double maxY = 0;
    QDateTime maxDateTime;
    QDateTime minDateTime;
};

#endif // PROGRAMACTION_H
