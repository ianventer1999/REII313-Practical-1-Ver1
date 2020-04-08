#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QDebug>
#include <QKeyEvent>
#include <QTimer>
#include <QPainter>
#include <QList>
#include <QGraphicsSceneMouseEvent>
#include <QDrag>
#include <math.h>

#include "and.h"
#include "or.h"
#include "not.h"
#include "nand.h"
#include "nor.h"
#include "xor.h"
#include "xnor.h"
#include "on.h"
#include "off.h"
#include "gate.h"
#include "connector.h"

class Environment : public QGraphicsScene
{
    Q_OBJECT
    public:
        Environment();
        ~Environment();
        void keyPressEvent(QKeyEvent *event);
        void keyReleaseEvent(QKeyEvent *event);
        void GateInformation(QGraphicsSceneMouseEvent *event);
        void mousePressEvent(QGraphicsSceneMouseEvent *event);
        void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
        void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
        void UpdateInputs(QGraphicsSceneMouseEvent *event);
        int  iLastMoved = 0;
    public slots:
        void update_scene();
    private:
        QList<clGate*> Gates;               //List of gates
        QList<clGate*> Gates_IO;            //List of gates and inputs
        QList<clConnector*> Connectors;     //List of connectors
        QList<clGate*> GatesDefault;        //Display Gates
        QList<clOn*> DefaultOn;             //Display On
        QList<clOFF*> DefaultOff;           //Display Off
        QList<clOn*> OnList;                //List of Ons
        QList<clOFF*> OffList;              //List of offs
        QList<clGate*> OutList;             //List of outputs
        QList<clGate*> ConnectList;
        QTimer  *update_timer;
        int     iInputs;
        int     iLastPositions[2];          //Stores the last x and y positions
};

#endif // ENVIRONMENT_H
