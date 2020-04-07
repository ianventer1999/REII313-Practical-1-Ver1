#include "connector.h"

clConnector::clConnector(int X, int Y, int X2, int Y2, bool bTouch, bool bDir, int iClosest, int iSmallestPos, bool bX, bool bY)
{
    this->iStartX = X;
    this->iStartY = Y;
    this->iDisX  = X2;
    this->iDisY  = Y2;

    this->setX(iStartX);
    this->setY(iStartY);

    this->bValue    = bTouch;
    this->bUp_Down  = bDir;

    this->iClosestType  = iClosest;
    this->iClosestListPos = iSmallestPos;

    this->bDirX = bX;
    this->bDirY = bY;
}

clConnector::~clConnector()
{

}

void clConnector::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::black);

    if (this->bUp_Down)
    {
        painter->drawLine(QLine(0,0,iDisX/2,0));
        painter->drawLine(QLine(iDisX/2,0,iDisX/2,iDisY));
        painter->drawLine(QLine(iDisX/2,iDisY,iDisX,iDisY));
    }
    else
    {
        painter->drawLine(QLine(0,iDisY,iDisX/2,iDisY));
        painter->drawLine(QLine(iDisX/2,0,iDisX/2,iDisY));
        painter->drawLine(QLine(iDisX/2,0,iDisX,0));
    }

    Q_UNUSED(option);
    Q_UNUSED(widget);
}

double clConnector::DistanceFromObject(QPointF OtherObject)
{
    return sqrt(pow((OtherObject.x()-this->scenePos().x()),2) + pow((OtherObject.y()-this->scenePos().y()),2));
}

QRectF clConnector::boundingRect() const
{
    return QRectF(0,0,iDisX,iDisY);
}
