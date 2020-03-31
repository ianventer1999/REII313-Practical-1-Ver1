#ifndef GATE_H
#define GATE_H


#include <QGraphicsItem>
#include <QKeyEvent>
#include <QPainter>

class clGate: public QGraphicsItem
{
    public:
        clGate();
        virtual ~clGate();

        int     iInputCount;
        bool    bInputs[10];
    private:
        bool    bOutput;
    protected:
        void    pUpdateInputCount(int);
        bool    fDetermineOuptut();
};

#endif // GATE_H
