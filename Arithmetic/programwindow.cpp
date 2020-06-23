#include "programwindow.h"

ProgramWindow::ProgramWindow(QObject* parent): QObject(parent)
{
   authWindow = new AuthorizationWindow();
   regWindow = new RegistrationWindow();
   challWindow = new ChallengeWindow();
}

ProgramWindow::~ProgramWindow()
{

}
