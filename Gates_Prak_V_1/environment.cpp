#include "environment.h"
#include <QDrag>
int GatePlace;
bool bmove = false;
Environment::Environment()
{

    //Add Gates with instructions on how to use

        GatesDefault.append(new clAND(-5000,-1000,2));
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


    if (event->key() ==Qt::Key_1)
    {
      GatePlace = 1;
    }
    if (event->key() ==Qt::Key_2)
    {
      GatePlace = 2;
    }
    if (event->key() ==Qt::Key_3)
    {
      GatePlace = 3;
    }
    if (event->key() ==Qt::Key_4)
    {
      GatePlace = 4;
    }
    if (event->key() ==Qt::Key_5)
    {
      GatePlace = 5;
    }
    if (event->key() ==Qt::Key_6)
    {
      GatePlace = 6;
    }
    if (event->key() ==Qt::Key_7)
    {
      GatePlace = 7;
    }



}




void Environment ::keyReleaseEvent(QKeyEvent *event)
{

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
        switch(GatePlace)
        {
            case 1:
            {
                Gates.append(new clAND(event->scenePos().x(),event->scenePos().y(),2));
                Environment::addItem(Gates.last());
                //this->addItem();
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


   if((event->button() == Qt::LeftButton)&&( bmove == false))
    {
        bmove = true;
    }

}
void Environment::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if((event->button() == Qt::LeftButton)&&( bmove == true))
    {
        bmove = false;

    }
}


void Environment::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    for (auto b:this->Gates)
    {

        if (bmove ==true)
        {

            if ((event->scenePos().x() >= b->pos().x()-50)&&(event->scenePos().x())<=b->pos().x()+50)
            {
                if ((event->scenePos().y() >= b->pos().y()-50)&&(event->scenePos().y())<=b->pos().y()+50)
                {
                    b->update(event->scenePos().x(),event->scenePos().y());
                    Environment::update();

                }
            }
        }

    }

}


