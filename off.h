#ifndef OFF_H
#define OFF_H

#include "gate.h"

class clOFF : public clGate
{
    public:
        clOFF(int X,int Y);
        double DistanceFromObject(QPointF OtherObject);
        void update(float x,float y);
        QRectF boundingRect() const override;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    protected:
        bool    fDetermineOutput() override;
        QString GetClassName() override;
};
#endif // OFF_H
