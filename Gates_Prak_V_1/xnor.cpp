#include "xnor.h"

clXNOR::clXNOR(int iXval,int iYval,int iInputCount)
{
    this->setX(iXval);
    this->setY(iYval);
    this->iInputCount = iInputCount;
}

clXNOR::~clXNOR()
{

}

QRectF clXNOR::boundingRect() const
{
    return QRectF(0,0,20,20);
}

void clXNOR::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawArc(QRect(5,0,30,50),90*16,-180*16);
    painter->drawArc(QRect(0,0,30,50),90*16,-180*16);
    painter->drawArc(QRect(-40,0,120,50),90*16,-90*16);
    painter->drawArc(QRect(-40,0,120,50),-90*16,90*16);

    painter->drawArc(QRect(80,20,10,10),0,360*16);
    painter->drawLine(QLine(90,25,100,25));

    switch (iInputCount)
    {
        case 1:
        {
            painter->drawLine(QLine(0,25,30,25));
        }break;
        case 2:
        {
            painter->drawLine(QLine(0,10,27,10));
            painter->drawLine(QLine(0,40,27,40));
        }break;
        case 3:
        {
            painter->drawLine(QLine(0,10,27,10));
            painter->drawLine(QLine(0,25,30,25));
            painter->drawLine(QLine(0,40,27,40));
        }break;
        case 4:
        {
            painter->drawLine(QLine(0,10,27,10));
            painter->drawLine(QLine(0,20,29,20));
            painter->drawLine(QLine(0,30,29,30));
            painter->drawLine(QLine(0,40,27,40));
        }break;
        case 5:
        {
            painter->drawLine(QLine(0,5,24,5));
            painter->drawLine(QLine(0,15,28,15));
            painter->drawLine(QLine(0,25,30,25));
            painter->drawLine(QLine(0,35,28,35));
            painter->drawLine(QLine(0,45,24,45));
        }break;
    }

    Q_UNUSED(option);
    Q_UNUSED(widget);
}

bool clXNOR::fDetermineOuptut()
{
    int  iTrueCounter = 0;

    for(auto b:clGate::bInputs)
    {
        if (b == true)
        {
             iTrueCounter++;
        }
    }

    if (iTrueCounter == 1) //Opposite of XOR
    {
        return false;
    }
    else
    {
         return true;
    }
}


