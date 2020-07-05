#include "ProgramController.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);    
    ProgramController controller;    
    controller.startProgram();
    return app.exec();
}
