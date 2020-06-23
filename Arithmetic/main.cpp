#include "programcontroller.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    ProgramController controller;
    controller.start();    
    return app.exec();
}
