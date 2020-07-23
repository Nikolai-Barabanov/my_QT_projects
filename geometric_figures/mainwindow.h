#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>
#include <QMap>
#include <QApplication>

#include "figures.h"
#include "rectangle.h"
#include "circle.h"
#include "triangle.h"
#include "star.h"

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void pushQuit();
    void pushTriangle();
    void pushRectangle();
    void pushStar();
    void pushCircle();

private:
    QMap<QString, QLabel*> labels;
    QGraphicsScene* scene;

    Figures* triangle;
    Figures* rectangle;
    Figures* circle;
    Figures* star;

    void changeLabels(Figures* figure);
    void paint(QString figure);
};
#endif // MAINWINDOW_H
