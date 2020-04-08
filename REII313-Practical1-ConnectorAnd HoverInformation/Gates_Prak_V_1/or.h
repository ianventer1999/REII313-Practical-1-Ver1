#ifndef OR_H
#define OR_H

#include "gate.h"

class clOR: public clGate
{
    public:
        clOR(int iXval,int iYval,int iInputCount);
        virtual ~clOR();
        QRectF boundingRect() const override;

    private:

    protected:
        bool    fDetermineOutput() override;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
        QString GetClassName() override;
};

#endif // OR_H
