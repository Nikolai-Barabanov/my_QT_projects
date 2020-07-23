#include "circle.h"

Circle::Circle()
{

}

Circle::~Circle()
{

}

QRectF Circle::draw()
{
    return QRectF(0, -100, 100, 100);
}

QPolygon Circle::drawPolygon()
{
    QPolygon polygon;
    return polygon;
}

QString Circle::getName()
{
    QString name = "It is a circle";
    return name;
}
