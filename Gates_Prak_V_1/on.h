#ifndef ON_H
#define ON_H

#include "gate.h"

class clOn : public clGate
{
    public:
        clOn(int X,int Y);
        double DistanceFromObject(QPointF OtherObject);
        void update(float x,float y);
        QRectF boundingRect() const;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    protected:
        bool    fDetermineOutput();
};

#endif // ON_H
