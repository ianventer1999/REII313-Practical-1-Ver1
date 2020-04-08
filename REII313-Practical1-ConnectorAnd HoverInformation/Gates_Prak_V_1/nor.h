#ifndef NOR_H
#define NOR_H

#include "gate.h"

class clNOR: public clGate
{
    public:
        clNOR(int iXval,int iYval,int iInputCount);
         ~clNOR() override;
        QRectF boundingRect() const override;
    private:

    protected:
        bool    fDetermineOutput() override;
        void    paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
        QString GetClassName() override;
};

#endif // NOR_H
