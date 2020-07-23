#ifndef FIGURES_H
#define FIGURES_H

#include <QDebug>
#include <QGraphicsItem>
#include <QPainter>

class Figures
{
public:

    explicit Figures(){};
    virtual ~Figures(){};
    virtual QRectF draw() = 0;
    virtual QPolygon drawPolygon() = 0;
    virtual QString getName() = 0;
};

#endif // FIGURES_H
