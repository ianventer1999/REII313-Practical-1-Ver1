#ifndef ON_H
#define ON_H

#include "gate.h"

class clOn : public clGate
{
    public:
        clOn(int X,int Y);
        double DistanceFromObject(QPointF OtherObject);
        void update(float x,float y);
        QRectF boundingRect() const override;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    protected:
        bool    fDetermineOutput() override;
        QString GetClassName() override;
};

#endif // ON_H
