#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "figures.h"

class Rectangle : public Figures
{
public:

    explicit Rectangle();
    ~Rectangle();
    QRectF draw() override;
    QPolygon drawPolygon() override;
    QString getName() override;
};

#endif // SQUARE_H
