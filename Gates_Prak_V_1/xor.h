#ifndef XOR_H
#define XOR_H

#include "gate.h"

class clXOR: public clGate
{
    public:
        clXOR();
        virtual ~clXOR();
        QRectF boundingRect() const;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    private:
};

#endif // XOR_H
