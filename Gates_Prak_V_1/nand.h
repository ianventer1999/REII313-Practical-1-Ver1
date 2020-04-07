#ifndef NAND_H
#define NAND_H

#include "gate.h"

class clNAND: public clGate
{
    public:
        clNAND(int iXval,int iYval,int iInputCount);
        virtual ~clNAND();
        QRectF boundingRect() const;

    private:

    protected:
        bool    fDetermineOutput();
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
        QString GetClassName();
};

#endif // NAND_H
