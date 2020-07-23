#ifndef STAR_H
#define STAR_H

#include "figures.h"

class Star : public Figures
{
public:

    explicit Star();
    ~Star();
    QRectF draw() override;
    QPolygon drawPolygon() override;
    QString getName() override;
};

#endif // STAR_H
