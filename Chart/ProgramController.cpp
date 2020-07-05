#include "ProgramController.h"

ProgramController::ProgramController(QObject* parent)
    : QObject(parent)
{
    myWindow = new ProgramWindows();
    action = new ProgramAction();
    myWindow->moveToThread(&thread);
    thread.start();
    connectSlots();
}

ProgramController::~ProgramController()
{

}

void ProgramController::startProgram()
{
    myWindow->setModelQuery(action->getQueryModel(myWindow->getTableName()));
    action->createChart();
    thread.quit();
}

void ProgramController::connectSlots()
{
    connect(myWindow, &ProgramWindows::quit, this, &ProgramController::quit);    
    connect(myWindow, &ProgramWindows::comboBoxActiv, this, &ProgramController::comboBoxActiv);
    connect(&thread, &QThread::started, myWindow, &ProgramWindows::show);
    connect(&thread, &QThread::quit, &thread, &QObject::deleteLater);
    connect(action, &ProgramAction::update, this, &ProgramController::update);
}

void ProgramController::quit()
{
    QApplication::quit();
}

void ProgramController::comboBoxActiv(QString name)
{
    if(action->getTableName() != name)
    {
        myWindow->setModelQuery(action->getQueryModel(myWindow->getTableName()));
        action->createChart();
    }
}

void ProgramController::update(QChart *chart)
{
    myWindow->setChartView(chart);
}
