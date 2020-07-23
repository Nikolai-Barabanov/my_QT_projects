#include "rectangle.h"

Rectangle::Rectangle()
{

}

Rectangle::~Rectangle()
{

}

QRectF Rectangle::draw()
{
    return QRectF(0, -100, 100, 100);
}

QPolygon Rectangle::drawPolygon()
{
    QPolygon polygon;
    return polygon;
}

QString Rectangle::getName()
{
    QString name = "It is a rectangle";
    return name;
}
