#include "nand.h"

clNAND::clNAND(int iXval,int iYval,int iInputCount)
{
    this->setX(iXval);
    this->setY(iYval);
    this->iInputCount = iInputCount;
}

clNAND::~clNAND()
{

}

QRectF clNAND::boundingRect() const
{
    return QRectF(0,0,50,100);
}

void clNAND::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawLine(QLine(20,0,50,0));
    painter->drawLine(QLine(20,0,20,50));
    painter->drawLine(QLine(20,50,50,50));
    painter->drawArc(QRect(30,0,40,50),90*16,-180*16);

    painter->drawLine(QLine(80,25,100,25));
    painter->drawArc(QRect(70,20,10,10),0,360*16);

    switch (iInputCount)
    {
        case 1:
        {
            painter->drawLine(QLine(0,25,20,25));
        }break;
        case 2:
        {
            painter->drawLine(QLine(0,10,20,10));
            painter->drawLine(QLine(0,40,20,40));
        }break;
        case 3:
        {
            painter->drawLine(QLine(0,10,20,10));
            painter->drawLine(QLine(0,25,20,25));
            painter->drawLine(QLine(0,40,20,40));
        }break;
        case 4:
        {
            painter->drawLine(QLine(0,10,20,10));
            painter->drawLine(QLine(0,20,20,20));
            painter->drawLine(QLine(0,30,20,30));
            painter->drawLine(QLine(0,40,20,40));
        }break;
        case 5:
        {
            painter->drawLine(QLine(0,5,20,5));
            painter->drawLine(QLine(0,15,20,15));
            painter->drawLine(QLine(0,25,20,25));
            painter->drawLine(QLine(0,35,20,35));
            painter->drawLine(QLine(0,45,20,45));
        }break;
    }
}

