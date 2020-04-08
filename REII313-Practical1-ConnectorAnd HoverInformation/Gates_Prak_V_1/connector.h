#ifndef CONNECTOR_H
#define CONNECTOR_H

#include <QGraphicsItem>
#include <QPainter>
#include <math.h>

class clConnector : public QGraphicsItem
{
    public:
        clConnector(int X, int Y, int X2, int Y2, bool bTouch, bool bDir, int iClosest, int iSmallestPos, bool bX, bool bY);
        virtual ~clConnector();
        QRectF  boundingRect() const;
        void    paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
        double  DistanceFromObject(QPointF OtherObject);
        int     iStartX;
        int     iStartY;
        int     iDisX;
        int     iDisY;
        bool    bValue;
        bool    bUp_Down;
        bool    bDirX;
        bool    bDirY;
        int     iClosestType;//1 = G,2 = ON,3 = Off
        int     iClosestListPos;//Postion of connected input in its list
};

#endif // CONNECTOR_H
