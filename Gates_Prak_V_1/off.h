#ifndef OFF_H
#define OFF_H

#include "gate.h"

class clOFF : public clGate
{
    public:
        clOFF(int X,int Y);
        double DistanceFromObject(QPointF OtherObject);
        void update(float x,float y);
        QRectF boundingRect() const;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    protected:
        bool    fDetermineOutput();
};
#endif // OFF_H
