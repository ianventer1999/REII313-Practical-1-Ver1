#ifndef OR_H
#define OR_H

#include "gate.h"

class clOR: public clGate
{
    public:
        clOR();
        virtual ~clOR();
        QRectF boundingRect() const;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    private:
};

#endif // OR_H
