#include "environment.h"
#include <QDrag>

int     iGatePlace;
bool    bMove = false;

Environment::Environment()
{
        GatesDefault.append(new clAND(-5000,-1000,2));                                  //Add Gates with instructions on how to use
        GatesDefault.append(new clNAND(-4800,-1000,2));
        GatesDefault.append(new clOR(-4600,-1000,2));
        GatesDefault.append(new clNOR(-4400,-1000,2));
        GatesDefault.append(new clXOR(-4200,-1000,2));
        GatesDefault.append(new clXNOR(-4000,-1000,2));
        GatesDefault.append(new clNOT(-3800,-1000,2));

        for (auto b :this->GatesDefault)
        {
            this->addItem(b);
        }

        QList <QGraphicsTextItem*> text ;//= addText("Hotkey =1");
        text.append(addText("Hotkey Shift 1 + Click"));
        text.append(addText("Hotkey Shift 2 + Click"));
        text.append(addText("Hotkey 3 + Click"));
        text.append(addText("Hotkey 4 + Click"));
        text.append(addText("Hotkey 5 + Click"));
        text.append(addText("Hotkey 6 + Click"));
        text.append(addText("Hotkey 7 + Click"));
        for(int i=0;i<text.size();++i)
        {
            text[i]->setPos(-5000+200*i,-950);
        }

    this->update_timer = new QTimer(this);
    connect(this->update_timer, SIGNAL(timeout()),this,SLOT(update_scene()));
    this->update_timer->start(1000);
}

Environment::~Environment()
{

}

void Environment ::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
        case Qt::Key_1:
        {
            iGatePlace = 1;
        }break;
        case Qt::Key_2:
        {
            iGatePlace = 2;
        }break;
        case Qt::Key_3:
        {
            iGatePlace = 3;
        }break;
        case Qt::Key_4:
        {
            iGatePlace = 4;
        }break;
        case Qt::Key_5:
        {
            iGatePlace = 5;
        }break;
        case Qt::Key_6:
        {
            iGatePlace = 6;
        }break;
        case Qt::Key_7:
        {
            iGatePlace = 7;
        }break;
    }
}

void Environment ::keyReleaseEvent(QKeyEvent *event)
{
    Q_UNUSED(event)
}

void Environment ::update_scene()
{
    for (auto b :this->Gates)
    {

        b->update(b->pos().x(),b->pos().y());
        b->show();
    }
}

void Environment::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    // qDebug() << event->scenePos() ;


    if((event->button() == Qt::LeftButton)&&(event->modifiers() ==Qt::ShiftModifier))
    {
        switch(iGatePlace)
        {
            case 1:
            {
                Gates.append(new clAND(event->scenePos().x(),event->scenePos().y(),2));
                Environment::addItem(Gates.last());
            }break;

            case 2:
            {
                Gates.append(new clNAND(event->scenePos().x(),event->scenePos().y(),2));
                Environment::addItem(Gates.last());
            }break;
            case 3:
            {
                Gates.append(new clOR(event->scenePos().x(),event->scenePos().y(),2));
                Environment::addItem(Gates.last());
            }break;
            case 4:
            {
                Gates.append(new clNOR(event->scenePos().x(),event->scenePos().y(),2));
                Environment::addItem(Gates.last());
            }break;
            case 5:
            {
                Gates.append(new clXOR(event->scenePos().x(),event->scenePos().y(),2));
                Environment::addItem(Gates.last());
            }break;
            case 6:
            {
                Gates.append(new clXNOR(event->scenePos().x(),event->scenePos().y(),2));
                Environment::addItem(Gates.last());
            }break;
            case 7:
            {
                Gates.append(new clNOT(event->scenePos().x(),event->scenePos().y(),2));
                Environment::addItem(Gates.last());
            }break;
        }     
    }


    if((event->button() == Qt::LeftButton)&&(bMove == false))
    {
        bMove = true;
    }

}
void Environment::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if((event->button() == Qt::LeftButton)&&(bMove == true))
    {
        bMove = false;
    }
}


void Environment::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    for (auto b:this->Gates)
    {

        if (bMove ==true)
        {
            if(b->DistanceFromObject(event->scenePos())<50)
            {
                b->update(event->scenePos().x(),event->scenePos().y());
                Environment::update();
            }

            /*
            if ((event->scenePos().x() >= b->pos().x()-50)&&(event->scenePos().x())<=b->pos().x()+50)
            {
                if ((event->scenePos().y() >= b->pos().y()-50)&&(event->scenePos().y())<=b->pos().y()+50)
                {
                    b->update(event->scenePos().x(),event->scenePos().y());
                    Environment::update();

                }
            }*/
        }

    }

}


