#include "nextwindow.h"

nextWindow::nextWindow(QWidget* parent):QWidget(parent)
{
    QPushButton* quit = new QPushButton("Выход");
    connect(quit, &QPushButton::clicked, this, &nextWindow::exit);
    QVBoxLayout* box = new QVBoxLayout();
    box->addWidget(quit);
    setLayout(box);
}

nextWindow::~nextWindow()
{

}

void nextWindow::exit()
{
    QApplication::quit();
}
