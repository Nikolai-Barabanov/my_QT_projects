#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "figures.h"

class Triangle : public Figures
{
public:
    explicit Triangle();
    ~Triangle();
    QRectF draw() override;
    QPolygon drawPolygon() override;
    QString getName() override;
};

#endif // TRIANGLE_H
