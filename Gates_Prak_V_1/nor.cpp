#include "nor.h"

clNOR::clNOR(int iXval,int iYval,int iInputCount)
{
    this->setX(iXval);
    this->setY(iYval);
    this->iInputCount = iInputCount;
}

clNOR::~clNOR()
{

}

QRectF clNOR::boundingRect() const
{
    return QRectF(0,0,50,60);
}

void clNOR::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawArc(QRect(5,0,30,50),90*16,-180*16);
    painter->drawArc(QRect(-40,0,120,50),90*16,-90*16);
    painter->drawArc(QRect(-40,0,120,50),-90*16,90*16);
    painter->drawArc(QRect(80,20,10,10),0,360*16);
    painter->drawLine(QLine(90,25,100,25));

    switch (iInputCount)
    {
        case 1:
        {
            painter->drawLine(QLine(0,25,35,25));
        }break;
        case 2:
        {
            painter->drawLine(QLine(0,10,32,10));
            painter->drawLine(QLine(0,40,32,40));
        }break;
        case 3:
        {
            painter->drawLine(QLine(0,10,32,10));
            painter->drawLine(QLine(0,25,35,25));
            painter->drawLine(QLine(0,40,32,40));
        }break;
        case 4:
        {
            painter->drawLine(QLine(0,10,32,10));
            painter->drawLine(QLine(0,20,34,20));
            painter->drawLine(QLine(0,30,34,30));
            painter->drawLine(QLine(0,40,32,40));
        }break;
        case 5:
        {
            painter->drawLine(QLine(0,5,29,5));
            painter->drawLine(QLine(0,15,33,15));
            painter->drawLine(QLine(0,25,35,25));
            painter->drawLine(QLine(0,35,33,35));
            painter->drawLine(QLine(0,45,29,45));
        }break;
    }
}
