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

#include "and.h"
#include "or.h"
#include "not.h"
#include "nand.h"
#include "nor.h"
#include "xor.h"
#include "xnor.h"
#include "on.h"
#include "gate.h"

class Environment : public QGraphicsScene
{
    Q_OBJECT
    public:
        Environment();
        ~Environment();
        void keyPressEvent(QKeyEvent *event);
        void keyReleaseEvent(QKeyEvent *event);
        void mousePressEvent(QGraphicsSceneMouseEvent *event);
        void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
        void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
        void UpdateInputs(QGraphicsSceneMouseEvent *event);
    public slots:
        void update_scene();
    private:
        QList<clGate*> Gates;
        QList<clGate*> GatesDefault;
        QList<On*> DefaultOn;
        QList<On*> OnList;
        QTimer  *update_timer;
        int     iInputs;
};

#endif // ENVIRONMENT_H
