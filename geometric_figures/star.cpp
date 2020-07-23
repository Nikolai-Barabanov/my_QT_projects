#include "star.h"

Star::Star()
{

}

Star::~Star()
{

}

QRectF Star::draw()
{
    return QRectF();
}

QPolygon Star::drawPolygon()
{
    QPolygon polygon;
    polygon << QPoint(0, 85) << QPoint(75, 75)
            << QPoint(100, 10) << QPoint(125, 75)
            << QPoint(200, 85) << QPoint(150, 125)
            << QPoint(160, 190) << QPoint(100, 150)
            << QPoint(40, 190) << QPoint(50, 125)\
            << QPoint(0, 85);
    return polygon;
}

QString Star::getName()
{
    QString name = "It is a star";
    return name;
}
