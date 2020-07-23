#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    rectangle = new Rectangle();
    circle = new Circle();
    triangle = new Triangle();
    star = new Star();

    this->resize(600,600);
    this->setFixedSize(600,600);

    QVBoxLayout* generalBox = new QVBoxLayout();

    QHBoxLayout* buttons = new QHBoxLayout();
    QHBoxLayout* title = new QHBoxLayout();

    labels.insert("title", new QLabel("It is a figure"));
    labels["title"]->setAlignment(Qt::AlignCenter);
    title->addWidget(labels["title"]);

    QGraphicsView* graphics = new QGraphicsView();
    scene = new QGraphicsScene();
    graphics->setScene(scene);

    QPushButton* pushTriangle = new QPushButton("Triangle");
    QPushButton* pushCircle = new QPushButton("Circle");
    QPushButton* pushRectangle = new QPushButton("Rectangle");
    QPushButton* pushStar = new QPushButton("Star");
    QPushButton* pushQuit = new QPushButton("Quit");

    buttons->addWidget(pushRectangle);
    buttons->addWidget(pushCircle);
    buttons->addWidget(pushTriangle);
    buttons->addWidget(pushStar);
    buttons->addWidget(pushQuit);

    connect(pushQuit, &QPushButton::clicked, this, &MainWindow::pushQuit);
    connect(pushTriangle, &QPushButton::clicked, this, &MainWindow::pushTriangle);
    connect(pushRectangle, &QPushButton::clicked, this, &MainWindow::pushRectangle);
    connect(pushStar, &QPushButton::clicked, this, &MainWindow::pushStar);
    connect(pushCircle, &QPushButton::clicked, this, &MainWindow::pushCircle);

    generalBox->addLayout(title);
    generalBox->addWidget(graphics);
    generalBox->addLayout(buttons);

    setLayout(generalBox);
}

MainWindow::~MainWindow()
{
}

void MainWindow::pushQuit()
{
    QApplication::quit();
}

void MainWindow::pushTriangle()
{
    changeLabels(triangle);
    paint("triangle");
}

void MainWindow::pushRectangle()
{
    changeLabels(rectangle);
    paint("rectangle");
}

void MainWindow::pushStar()
{
    changeLabels(star);
    paint("star");
}

void MainWindow::pushCircle()
{
    changeLabels(circle);
    paint("circle");
}

void MainWindow::changeLabels(Figures* figure)
{
    QMap<QString, QLabel*>::iterator iter;
    for(iter = labels.begin(); iter != labels.end(); ++iter)
    {
        iter.value()->setText(figure->getName());
    }
}

void MainWindow::paint(QString figure)
{
    scene->clear();
    QBrush greenBrush(Qt::green);
    QPen outlinePen;
    if(figure == "triangle")
        scene->addPolygon(triangle->drawPolygon(), outlinePen, greenBrush);
    if(figure == "star")
        scene->addPolygon(star->drawPolygon(), outlinePen, greenBrush);
    if(figure == "rectangle")
        scene->addRect(rectangle->draw(), outlinePen, greenBrush);
    if(figure == "circle")
        scene->addEllipse(circle->draw(), outlinePen, greenBrush);
}

