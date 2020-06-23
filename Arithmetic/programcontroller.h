#ifndef PROGRAMCONTROLLER_H
#define PROGRAMCONTROLLER_H

#include <QObject>
#include <QApplication>
#include <QMessageBox>
#include <QDebug>
#include "programwindow.h"
#include "programactions.h"

class ProgramWindow;

class ProgramController : public QObject
{
    Q_OBJECT
public:
    explicit ProgramController(QObject* parent = nullptr);
    ~ProgramController();
    void start();

private slots:
    void quit();
    void moveToRegWindow();
    void moveToAuthWindow();
    void moveToChallengeWindow();
    void authorization();
    void registration();
    void checkTasks();
    void refreshTasks();

private:
    void connectSignals();

    ProgramWindow* currentWindow;
    ProgramActions* actions;
};

#endif // PROGRAMCONTROLLER_H
