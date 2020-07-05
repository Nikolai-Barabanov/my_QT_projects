#ifndef PROGRAMCONTROLLER_H
#define PROGRAMCONTROLLER_H

#include <QObject>
#include <QApplication>
#include <QThread>
#include "ProgramWindows.h"
#include "ProgramAction.h"

class ProgramController : public QObject
{
    Q_OBJECT
public:
    explicit ProgramController(QObject* parent = nullptr);
    ~ProgramController();
    void startProgram();

private slots:
    void quit();    
    void comboBoxActiv(QString tableName);
    void update(QChart* chart);

private:
    QThread thread;
    ProgramWindows* myWindow;
    ProgramAction* action;
    void connectSlots();

};

#endif // PROGRAMCONTROLLER_H
