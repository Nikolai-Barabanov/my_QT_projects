#ifndef CIRCLE_H
#define CIRCLE_H

#include "figures.h"

class Circle : public Figures
{
public:

    explicit Circle();
    ~Circle();
    QRectF draw() override;
    QPolygon drawPolygon() override;
    QString getName() override;
};

#endif // CIRCLE_H
