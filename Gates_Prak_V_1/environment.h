#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QDebug>
#include <QKeyEvent>
#include <QTimer>
#include <QPainter>

#include "and.h"
#include "or.h"
#include "not.h"
#include "nand.h"
#include "nor.h"
#include "xor.h"
#include "xnor.h"

#include "gate.h"

class Environment : public QGraphicsScene
{
    Q_OBJECT
    public:
        Environment();
        ~Environment();
        void keyPressEvent(QKeyEvent *event);
        void keyReleaseEvent(QKeyEvent *event);
    public slots:
        void update_scene();
    private:
        clGate  *Gates[10];
        QTimer  *update_timer;
        int     iInputs;
};

#endif // ENVIRONMENT_H
