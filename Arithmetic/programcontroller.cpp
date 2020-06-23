#include "programcontroller.h"

ProgramController::ProgramController(QObject* parent): QObject(parent)
{
    currentWindow = new ProgramWindow();
    actions = new ProgramActions();
    connectSignals();
}

ProgramController::~ProgramController()
{

}

void ProgramController::start()
{
    currentWindow->authWindow->show();
}

void ProgramController::connectSignals()
{
   connect(currentWindow->authWindow, &AuthorizationWindow::quit,
           this, &ProgramController::quit);
   connect(currentWindow->authWindow, &AuthorizationWindow::registration,
           this, &ProgramController::moveToRegWindow);
   connect(currentWindow->authWindow, &AuthorizationWindow::authorization,
           this, &ProgramController::authorization);

   connect(currentWindow->regWindow, &RegistrationWindow::quit,
           this, &ProgramController::quit);
   connect(currentWindow->regWindow, &RegistrationWindow::back,
           this, &ProgramController::moveToAuthWindow);
   connect(currentWindow->regWindow, &RegistrationWindow::registration,
           this, &ProgramController::registration);

   connect(currentWindow->challWindow, &ChallengeWindow::back,
           this, &ProgramController::moveToAuthWindow);
   connect(currentWindow->challWindow, &ChallengeWindow::check,
           this, &ProgramController::checkTasks);
   connect(currentWindow->challWindow, &ChallengeWindow::refresh,
           this, &ProgramController::refreshTasks);
}

void ProgramController::quit()
{
    QApplication::quit();
}

void ProgramController::moveToRegWindow()
{
    actions->clearFields(currentWindow->authWindow->getLineEdits());
    currentWindow->regWindow->show();
}

void ProgramController::moveToAuthWindow()
{
    actions->clearFields(currentWindow->regWindow->getLineEdits());
    actions->clearFields(currentWindow->challWindow->getLineEdits());
    actions->clearTaskList(currentWindow->challWindow->getResult());
    actions->clearAnswers();
    currentWindow->authWindow->show();
}

void ProgramController::moveToChallengeWindow()
{
    actions->clearFields(currentWindow->authWindow->getLineEdits());
    actions->clearTaskList(currentWindow->challWindow->getLabels());
    actions->setTasks(currentWindow->challWindow->getLabels());
    currentWindow->challWindow->show();
}

void ProgramController::authorization()
{
    if(actions->authorization(currentWindow->authWindow->getLineEdits()))
    {       
        currentWindow->authWindow->close();
        moveToChallengeWindow();
    }
}

void ProgramController::registration()
{
    if(actions->registration(currentWindow->regWindow->getLineEdits()))
    {
        currentWindow->regWindow->close();
        moveToAuthWindow();
        QMessageBox* box = new QMessageBox();
        box->setText("Registration complete");
        box->show();
    }
}

void ProgramController::checkTasks()
{
    actions->checkAnswers(currentWindow->challWindow->getLineEdits(),
                          currentWindow->challWindow->getLabels());
    actions->setResult(currentWindow->challWindow->getResult(),
                       currentWindow->challWindow->getLabels());
}

void ProgramController::refreshTasks()
{
    actions->clearAnswers();
    actions->clearFields(currentWindow->challWindow->getLineEdits());
    actions->clearTaskList(currentWindow->challWindow->getLabels());
    actions->setTasks(currentWindow->challWindow->getLabels());
    actions->clearTaskList(currentWindow->challWindow->getResult());
}
