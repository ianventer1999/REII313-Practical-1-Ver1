#ifndef NOR_H
#define NOR_H


#include "gate.h"

class clNOR: public clGate
{
    public:
        clNOR();
        virtual ~clNOR();
        QRectF boundingRect() const;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    private:
};

#endif // NOR_H
