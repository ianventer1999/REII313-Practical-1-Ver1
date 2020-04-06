#ifndef NOT_H
#define NOT_H

#include "gate.h"

class clNOT: public clGate
{
    public:
        clNOT(int iXval,int iYval,int iInputCount);
        virtual ~clNOT();
        QRectF boundingRect() const;
    private:

    protected:
        bool    fDetermineOuptut();
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
};

#endif // NOT_H
