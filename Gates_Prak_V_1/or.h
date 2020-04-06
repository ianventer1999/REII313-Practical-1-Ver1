#ifndef OR_H
#define OR_H

#include "gate.h"

class clOR: public clGate
{
    public:
        clOR(int iXval,int iYval,int iInputCount);
        virtual ~clOR();
        QRectF boundingRect() const;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    private:

protected:
        bool    fDetermineOuptut();
};

#endif // OR_H
