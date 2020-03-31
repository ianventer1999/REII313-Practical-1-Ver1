#ifndef NAND_H
#define NAND_H


#include <QGraphicsItem>
#include <QKeyEvent>
#include <QPainter>

#include "gate.h"

class clNAND: public clGate
{
    public:
        clNAND();
        virtual ~clNAND();
        QRectF boundingRect() const;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    private:
};

#endif // NAND_H
