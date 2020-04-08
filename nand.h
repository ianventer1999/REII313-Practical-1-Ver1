#ifndef NAND_H
#define NAND_H

#include "gate.h"

class clNAND: public clGate
{
    public:
        clNAND(int iXval,int iYval,int iInputCount);
         ~clNAND() override;
        QRectF boundingRect() const override;

    private:

    protected:
        bool    fDetermineOutput() override;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
        QString GetClassName() override;
};

#endif // NAND_H
