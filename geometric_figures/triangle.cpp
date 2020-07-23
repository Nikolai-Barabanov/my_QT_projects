#include "triangle.h"

Triangle::Triangle()
{

}

Triangle::~Triangle()
{

}

QRectF Triangle::draw()
{    
    return QRectF();    
}

QPolygon Triangle::drawPolygon()
{
    QPolygon polygon;
    polygon << QPoint(0,0) << QPoint(50,100) << QPoint(-50,100);
    return polygon;
}

QString Triangle::getName()
{
    QString name = "It is a triangle";
    return name;
}
