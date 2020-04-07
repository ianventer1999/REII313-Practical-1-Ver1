#ifndef NOR_H
#define NOR_H

#include "gate.h"

class clNOR: public clGate
{
    public:
        clNOR(int iXval,int iYval,int iInputCount);
        virtual ~clNOR();
        QRectF boundingRect() const;
    private:

    protected:
        bool    fDetermineOutput();
        void    paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
};

#endif // NOR_H
