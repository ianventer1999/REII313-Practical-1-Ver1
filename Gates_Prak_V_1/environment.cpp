#include "environment.h"
int GatePlace;
Environment::Environment()
{

    //Add Gates with instructions on how to use

        GatesDefault.append(new clAND(-1000,-1000,2));
        GatesDefault.append(new clNAND(-800,-1000,2));
        GatesDefault.append(new clOR(-600,-1000,2));
        GatesDefault.append(new clNOR(-400,-1000,2));
        GatesDefault.append(new clXOR(-200,-1000,2));
        GatesDefault.append(new clXNOR(0,-1000,2));
        GatesDefault.append(new clNOT(200,-1000,2));

        for (auto b :this->GatesDefault)
        {
            this->addItem(b);
        }
        /*this->addItem(new clAND(-1000,-1000,2));
        this->addItem(new clNAND(-800,-1000,2));
        this->addItem(new clOR(-600,-1000,2));
        this->addItem(new clNOR(-400,-1000,2));
        this->addItem(new clXOR(-200,-1000,2));
        this->addItem(new clXNOR(0,-1000,2));
        this->addItem(new clNOT(200,-1000,2));*/
        QList <QGraphicsTextItem*> text ;//= addText("Hotkey =1");
        text.append(addText("Hotkey 1"));
        text.append(addText("Hotkey 2"));
        text.append(addText("Hotkey 3"));
        text.append(addText("Hotkey 4"));
        text.append(addText("Hotkey 5"));
        text.append(addText("Hotkey 6"));
        text.append(addText("Hotkey 7"));
        for(int i=0;i<text.size();++i)
        {
            text[i]->setPos(-1000+200*i,-950);
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
   /* if (this->iInputs < 6)
    {
        this->iInputs++;
    }
    else
    {
        this->iInputs = 0;
    }

    for (auto b :this->Gates)
    {
        b->iInputCount = this->iInputs;
        this->removeItem(b);
        this->addItem(b);
    }*/
}

void Environment::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    // qDebug() << event->scenePos() ;

    if(event->button() == Qt::LeftButton)
    {

        switch(GatePlace)
        {
            case 1:
            {
                Gates.append(new clAND(event->scenePos().x(),event->scenePos().y(),2));
                this->addItem(Gates.last());
            }break;

            case 2:
            {
                Gates.append(new clNAND(event->scenePos().x(),event->scenePos().y(),2));
                this->addItem(Gates.last());
            }break;
            case 3:
            {
                Gates.append(new clOR(event->scenePos().x(),event->scenePos().y(),2));
                this->addItem(Gates.last());
            }break;
            case 4:
            {
                Gates.append(new clNOR(event->scenePos().x(),event->scenePos().y(),2));
                this->addItem(Gates.last());
            }break;
            case 5:
            {
                Gates.append(new clXOR(event->scenePos().x(),event->scenePos().y(),2));
                this->addItem(Gates.last());
            }break;
            case 6:
            {
                Gates.append(new clXNOR(event->scenePos().x(),event->scenePos().y(),2));
                this->addItem(Gates.last());
            }break;
            case 7:
            {
                Gates.append(new clNOT(event->scenePos().x(),event->scenePos().y(),2));
                this->addItem(Gates.last());
            }break;


        }

    }
}
