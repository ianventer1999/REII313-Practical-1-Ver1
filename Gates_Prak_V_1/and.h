#ifndef AND_H
#define AND_H

#include <QGraphicsItem>
#include <QKeyEvent>

#include "gate.h"

class clAND: public clGate
{
    public:
        clAND(int iXval,int iYval,int iInputCount);
        virtual ~clAND();
        QRectF boundingRect() const;

    private:

    protected:
        bool    fDetermineOuptut();
        QString GetClassName();
        void    paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
};

#endif // AND_H
