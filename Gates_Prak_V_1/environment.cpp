#include "environment.h"

static  int     iGatePlace;
static  bool    bGateMove = false;
static  bool    bConditionMove =false;

Environment::Environment()
{
        GatesDefault.append(new clAND(-5000,-1000,2));                                  //Add Gates with instructions on how to use
        GatesDefault.append(new clNAND(-4800,-1000,2));
        GatesDefault.append(new clOR(-4600,-1000,2));
        GatesDefault.append(new clNOR(-4400,-1000,2));
        GatesDefault.append(new clXOR(-4200,-1000,2));
        GatesDefault.append(new clXNOR(-4000,-1000,2));
        GatesDefault.append(new clNOT(-3800,-1000,2));
        DefaultOn.append(new On(-3600,-1000));
        DefaultOff.append(new clOFF(-3400,-1000));
        for (auto b :this->GatesDefault)
        {
            this->addItem(b);
        }
        this->addItem(DefaultOn.first());
        this->addItem(DefaultOff.first());
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
    this->update_timer->start(10);
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
        case Qt::Key_8:
        {
            iGatePlace = 8;
        }break;
        case Qt::Key_9:
        {
            iGatePlace = 9;
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

        b->update(static_cast<float>(b->pos().x()),static_cast<float>(b->pos().y()));
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
                Gates.append(new clAND(static_cast<int>(event->scenePos().x()),static_cast<int>(event->scenePos().y()),2));
                Environment::addItem(Gates.last());
            }break;
            case 2:
            {
                Gates.append(new clNAND(static_cast<int>(event->scenePos().x()),static_cast<int>(event->scenePos().y()),2));
                Environment::addItem(Gates.last());
            }break;
            case 3:
            {
                Gates.append(new clOR(static_cast<int>(event->scenePos().x()),static_cast<int>(event->scenePos().y()),2));
                Environment::addItem(Gates.last());
            }break;
            case 4:
            {
                Gates.append(new clNOR(static_cast<int>(event->scenePos().x()),static_cast<int>(event->scenePos().y()),2));
                Environment::addItem(Gates.last());
            }break;
            case 5:
            {
                Gates.append(new clXOR(static_cast<int>(event->scenePos().x()),static_cast<int>(event->scenePos().y()),2));
                Environment::addItem(Gates.last());
            }break;
            case 6:
            {
                Gates.append(new clXNOR(static_cast<int>(event->scenePos().x()),static_cast<int>(event->scenePos().y()),2));
                Environment::addItem(Gates.last());
            }break;
            case 7:
            {
                Gates.append(new clNOT(static_cast<int>(event->scenePos().x()),static_cast<int>(event->scenePos().y()),2));
                Environment::addItem(Gates.last());
            }break;
            case 8:
            {
               OnList.append(new On(static_cast<int>(event->scenePos().x()),static_cast<int>(event->scenePos().y())));
               Environment::addItem(OnList.last());
            }break;
            case 9:
            {
               OffList.append(new clOFF(static_cast<int>(event->scenePos().x()),static_cast<int>(event->scenePos().y())));
               Environment::addItem(OffList.last());
            }break;
        }     
    }

    if((event->button() == Qt::LeftButton)&&(bGateMove == false)&&(iGatePlace<8))
    {
        bGateMove = true;
    }
    if((event->button() == Qt::LeftButton)&&(bConditionMove == false)&&(iGatePlace>=8))
    {
        bConditionMove = true;
    }


}
void Environment::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if((event->button() == Qt::LeftButton)&&(bGateMove == true))
    {
        bGateMove = false;
    }else
    {
        if(bConditionMove)
        {
            bConditionMove =false;
        }
    }
    //Determine the output of the gate after each mouse release event
    for (auto b :this->Gates)
    {
        if (b->iActiveInputs==b->iInputCount)
        {
          if (b->fDetermineOuptut())
          {
              OnList.append(new On(static_cast<int>(b->scenePos().x()+85),static_cast<int>(b->scenePos().y()+20)));
              this->addItem(OnList.last());
          }else
          {
              OffList.append(new clOFF(static_cast<int>(b->scenePos().x()+85),static_cast<int>(b->scenePos().y()+20)));
              this->addItem(OffList.last());
          }
        }

    }


}
//Update Inputs are used to determine if a inputclass is moving and if it is in the region of a gates input add it to the gate
//Also set the gates input boolean value to the appropiate true/false
void Environment::UpdateInputs(QGraphicsSceneMouseEvent *event)
{
    for (auto b:this->OnList)
    {
        if (bConditionMove ==true)
        {

            if(b->DistanceFromObject(event->scenePos())<25)
            {
                b->update(static_cast<float>(event->scenePos().x()),static_cast<float>(event->scenePos().y()));
                Environment::update();
            }
            //If the On class is near the input point 1 of the gates input, add the Onclass position to the Point 1 position
            //Same concept applies to point 2 for the second input of the Gate
            //This also applies for the Off class
            for (auto g:this->Gates)
            {
                QPointF p1;
                p1 = g->scenePos();
                p1.rx()-=10;
                p1.ry()+=5;
                if(b->DistanceFromObject(p1)<20)
                {
                    b->update(static_cast<float>(p1.x()),static_cast<float>(p1.y()));
                    //Secondary flag to check if the input is already occupied
                    if(g->bActiveInputs[0]==false)
                    {
                        g->bActiveInputs[0] = true;
                        g->iActiveInputs++;
                        g->bInputs.append(true);
                    }
                }
                QPointF p2;
                p2 = g->scenePos();
                p2.rx()-=10;
                p2.ry()+=35;
                if(b->DistanceFromObject(p2)<20)
                {
                    b->update(static_cast<float>(p2.x()),static_cast<float>(p2.y()));
                    if(g->bActiveInputs[1]==false)
                    {
                        g->bActiveInputs[1] = true;
                        g->iActiveInputs++;
                        g->bInputs.append(true);
                    }
                }
            }
        }
    }
    for (auto b:this->OffList)
    {
        if (bConditionMove ==true)
        {
            QPointF p1;
            if(b->DistanceFromObject(event->scenePos())<25)
            {
                b->update(static_cast<float>(event->scenePos().x()),static_cast<float>(event->scenePos().y()));
                Environment::update();
            }
            for (auto g:this->Gates)
            {
                p1 = g->scenePos();
                p1.rx()-=10;
                p1.ry()+=5;
                if(b->DistanceFromObject(p1)<20)
                {
                    b->update(static_cast<float>(p1.x()),static_cast<float>(p1.y()));
                    if(g->bActiveInputs[0]==false)
                    {
                        g->bActiveInputs[0] = true;
                        g->iActiveInputs++;
                        g->bInputs.append(false);
                    }
                }
                QPointF p2;
                p2 = g->scenePos();
                p2.rx()-=10;
                p2.ry()+=35;
                if(b->DistanceFromObject(p2)<20)
                {
                    b->update(static_cast<float>(p2.x()),static_cast<float>(p2.y()));
                    if(g->bActiveInputs[1]==false)
                    {
                        g->bActiveInputs[1] = true;
                        g->iActiveInputs++;
                        g->bInputs.append(false);
                    }
                }
            }
        }
    }
}


void Environment::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    for (auto b:this->Gates)
    {
        if (bGateMove ==true)
        {
            if(b->DistanceFromObject(event->scenePos())<50)
            {
                b->update(static_cast<float>(event->scenePos().x()),static_cast<float>(event->scenePos().y()));
                Environment::update();
            }
        }
    }
    this->UpdateInputs(event);
}


