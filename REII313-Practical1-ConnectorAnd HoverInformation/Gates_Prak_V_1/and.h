#ifndef AND_H
#define AND_H

#include "gate.h"

class clAND: public clGate
{
    public:
        clAND(int iXval,int iYval,int iInputCount);
         ~clAND() override;
        QRectF boundingRect() const override;

    private:

    protected:
        bool    fDetermineOutput() override;
        void    paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
        QString GetClassName() override;
};

#endif // AND_H
