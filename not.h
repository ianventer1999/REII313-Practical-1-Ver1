#ifndef NOT_H
#define NOT_H

#include "gate.h"

class clNOT: public clGate
{
    public:
        clNOT(int iXval,int iYval,int iInputCount);
         ~clNOT() override;
        QRectF boundingRect() const override;
    private:

    protected:
        bool    fDetermineOutput() override;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
        QString GetClassName() override;
};

#endif // NOT_H
