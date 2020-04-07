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
        bool    fDetermineOuptut();
        void    paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
        QString GetClassName();
};

#endif // NOR_H
