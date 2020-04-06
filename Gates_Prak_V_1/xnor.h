#ifndef XNOR_H
#define XNOR_H

#include "gate.h"

class clXNOR: public clGate
{
    public:
        clXNOR(int iXval,int iYval,int iInputCount);
        virtual ~clXNOR();
        QRectF boundingRect() const;

    private:

    protected:
        bool    fDetermineOuptut();
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
};

#endif // XNOR_H
