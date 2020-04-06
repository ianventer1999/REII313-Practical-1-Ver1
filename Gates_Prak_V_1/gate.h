#ifndef GATE_H
#define GATE_H


#include <QGraphicsItem>
#include <QKeyEvent>
#include <QPainter>
#include <QList>
class clGate: public QGraphicsItem
{
    public:
        clGate();
        virtual ~clGate();
        double DistanceFromObject(QPointF OtherObject);
        int     iInputCount;
        int     iActiveInputs =0;
        bool    bActiveInputs[2] = {false};
        QList<bool> bInputs;
        void update(float x,float y);
        virtual bool fDetermineOuptut()=0;
    private:
        bool    bOutput;
        //QList<bool*> bInputs;
    protected:
        void    pUpdateInputCount(int);


};

#endif // GATE_H
