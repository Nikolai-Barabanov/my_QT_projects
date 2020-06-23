#ifndef PROGRAMWINDOW_H
#define PROGRAMWINDOW_H

#include <QObject>
#include <QMap>
#include "authorizationwindow.h"
#include "registrationwindow.h"
#include "challengewindow.h"
#include "programcontroller.h"

class ProgramWindow : public QObject
{
    Q_OBJECT
    friend class ProgramController;
public:
    explicit ProgramWindow(QObject* parent = nullptr);
    ~ProgramWindow();
private:
    AuthorizationWindow* authWindow;
    RegistrationWindow* regWindow;
    ChallengeWindow* challWindow;
};

#endif // PROGRAMWINDOW_H
