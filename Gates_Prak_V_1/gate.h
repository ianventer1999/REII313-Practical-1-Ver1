#ifndef GATE_H
#define GATE_H

#include <QGraphicsItem>
#include <QKeyEvent>
#include <QPainter>
#include <QList>
#include <QGraphicsSceneMouseEvent>
#include <math.h>

class clGate: public QGraphicsItem
{
    public:
        clGate();
        virtual ~clGate();
        double  DistanceFromObject(QPointF OtherObject);
        int     iInputCount = 0;
        int     iMaxInput = 5;
        int     iActiveInputs = 0;
        bool    bActiveInputs[5] = {false};
        QList<bool> bInputs;
        void update(float x,float y);
        virtual bool fDetermineOutput()=0;
        virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr)=0;
        bool    bConnectedOut = false; // Has a connector been attached to the output
        bool    bConnectedIn = false;
    public:
        bool    bOutput = false;
    protected:
        void    pUpdateInputCount(int);
};

#endif // GATE_H
