#include "ProgramAction.h"

ProgramAction::ProgramAction(QObject* parent)
    : QObject(parent)
{
    myDatabase = new ProgramModel();
    chart = new QChart();
    lineSeries = new QLineSeries(chart);
    axisX = new QDateTimeAxis();
    axisY = new QValueAxis();
}

ProgramAction::~ProgramAction()
{

}

QSqlQueryModel* ProgramAction::getQueryModel(QString tableName)
{
    this->tableName = tableName;
    return myDatabase->getQueryModel(tableName);
}

void ProgramAction::createChart()
{
    maxY = 0;
    minY = 0;
    chart->removeAxis(axisX);
    chart->removeAxis(axisY);
    chart->removeSeries(lineSeries);

    createSeries();
    createAxis();

    chart->setTitle(tableName);
    chart->addSeries(lineSeries);
    chart->addAxis(axisX, Qt::AlignBottom);
    chart->addAxis(axisY, Qt::AlignLeft);

    lineSeries->attachAxis(axisX);
    lineSeries->attachAxis(axisY);
    emit update(chart);
}

QString ProgramAction::getTableName()
{
    return tableName;
}

void ProgramAction::createAxis()
{
    axisX->setFormat("dd-MM-yyyy h:mm:ss");
    axisX->setTitleText("Date");
    axisX->setMin(minDateTime);
    axisX->setMax(maxDateTime);

    axisY->setLabelFormat("%f");
    axisY->setTitleText("Value");
    axisY->setMin(minY);
    axisY->setMax(maxY);
}

void ProgramAction::createSeries()
{
    lineSeries->detachAxis(axisX);
    lineSeries->detachAxis(axisY);
    lineSeries->clear();

    QDateTime time;
    double value = 0;
    double copy = 0;

    int countNumber = myDatabase->getMaximum(tableName);

    for(int i = 0; i < countNumber; ++i)
    {
        value = myDatabase->getValue(i);
        maxY = fmax(maxY, value);
        minY = fmin(minY, value);

        minDateTime = maxDateTime = myDatabase->getData(i);

        if( copy != value)
        {
            time = myDatabase->getData(i);
            compareTime(time);

            lineSeries->append(time.toMSecsSinceEpoch(), value);
            copy = value;
        }
    }
}

void ProgramAction::compareTime(QDateTime time)
{
    if(maxDateTime < time)
        maxDateTime = time;
    if(minDateTime > time)
        minDateTime = time;
}
