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
        DefaultOn.append(new On(-3570,-975));
        DefaultOff.append(new clOFF(-3370,-975));
        for (auto b :this->GatesDefault)
        {
            this->addItem(b);
        }
        this->addItem(DefaultOn.first());
        this->addItem(DefaultOff.first());
        QList <QGraphicsTextItem*> text ;
        text.append(addText("Hotkey Shift 1 + Click"));
        text.append(addText("Hotkey Shift 2 + Click"));
        text.append(addText("Hotkey 3 + Click"));
        text.append(addText("Hotkey 4 + Click"));
        text.append(addText("Hotkey 5 + Click"));
        text.append(addText("Hotkey 6 + Click"));
        text.append(addText("Hotkey 7 + Click"));
        text.append(addText("Hotkey 8 + Click"));
        text.append(addText("Hotkey 9 + Click"));
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
    QPointF p1;
    p1 = event->scenePos();
    p1.rx()-=50;
    p1.ry()+=25;

    for (int I = 0;I < this->Gates.size();I++)
    {
        if (this->Gates[I]->DistanceFromObject(p1)<25)
        {
            if ((this->Gates[I]->iInputCount < this->Gates[I]->iMaxInput) && ((event->button() == Qt::LeftButton)) && (event->modifiers() ==Qt::ALT))
            {
                this->Gates[I]->iInputCount++;
            }
            else if ((this->Gates[I]->iInputCount > 0) && ((event->button() == Qt::RightButton)) && (event->modifiers() ==Qt::ALT))
            {
                this->Gates[I]->iInputCount--;
            }

            Gates.append(this->Gates[I]);
            Environment::removeItem(this->Gates[I]);
            Environment::addItem(Gates.last());
            Environment::update();
            break;
        }

    }

    if((event->button() == Qt::LeftButton)&&(event->modifiers() ==Qt::ShiftModifier))
    {
        switch(iGatePlace)
        {
            case 1:
            {
                Gates.append(new clAND(static_cast<int>(event->scenePos().x()),static_cast<int>(event->scenePos().y()),0));
                Environment::addItem(Gates.last());
            }break;
            case 2:
            {
                Gates.append(new clNAND(static_cast<int>(event->scenePos().x()),static_cast<int>(event->scenePos().y()),0));
                Environment::addItem(Gates.last());
            }break;
            case 3:
            {
                Gates.append(new clOR(static_cast<int>(event->scenePos().x()),static_cast<int>(event->scenePos().y()),0));
                Environment::addItem(Gates.last());
            }break;
            case 4:
            {
                Gates.append(new clNOR(static_cast<int>(event->scenePos().x()),static_cast<int>(event->scenePos().y()),0));
                Environment::addItem(Gates.last());
            }break;
            case 5:
            {
                Gates.append(new clXOR(static_cast<int>(event->scenePos().x()),static_cast<int>(event->scenePos().y()),0));
                Environment::addItem(Gates.last());
            }break;
            case 6:
            {
                Gates.append(new clXNOR(static_cast<int>(event->scenePos().x()),static_cast<int>(event->scenePos().y()),0));
                Environment::addItem(Gates.last());
            }break;
            case 7:
            {
                Gates.append(new clNOT(static_cast<int>(event->scenePos().x()),static_cast<int>(event->scenePos().y()),0));
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
    }
    else
    {
        if(bConditionMove)
        {
            bConditionMove =false;
        }
    }
    //Determine the output of the gate after each mouse release event
    for (auto b :this->Gates)
    {
        if ((b->iActiveInputs==b->iInputCount) && (b->iInputCount != 0))
        {
          if (b->fDetermineOuptut())
          {
              OnList.append(new On(static_cast<int>(b->scenePos().x()+100),static_cast<int>(b->scenePos().y()+22)));
              this->addItem(OnList.last());
          }else
          {
              OffList.append(new clOFF(static_cast<int>(b->scenePos().x()+100),static_cast<int>(b->scenePos().y()+22)));
              this->addItem(OffList.last());
          }
        }

    }
}
//Update Inputs are used to determine if a inputclass is moving and if it is in the region of a gates input add it to the gate
//Also set the gates input boolean value to the appropiate true/false
void Environment::UpdateInputs(QGraphicsSceneMouseEvent *event)
{
    for (auto b:this->Gates)
    {
        if (bGateMove == true)
        {
            if(b->DistanceFromObject(event->scenePos())<25)
            {
                b->update(static_cast<float>(event->scenePos().x()),static_cast<float>(event->scenePos().y()));
                Environment::update();
            }

            for (auto g:this->Gates)
            {
                QList<QPointF> Points;

                for (int I = 0;I < 5;I++)
                {
                    Points.append(g->scenePos());
                }

                switch (g->iInputCount)
                {
                    case 1:
                    {
                        Points[0].rx()-=7;
                        Points[0].ry()+=22;

                        for (int I = 1;I < 5;I++)
                        {
                            Points[I].rx()-=10000;
                            Points[I].ry()+=10000;
                        }
                    }break;

                    case 2:
                    {
                        Points[0].rx()-=7;
                        Points[0].ry()+=7;

                        Points[1].rx()-=7;
                        Points[1].ry()+=37;

                        for (int I = 2;I < 5;I++)
                        {
                            Points[I].rx()-=10000;
                            Points[I].ry()+=10000;
                        }
                    }break;

                    case 3:
                    {
                        Points[0].rx()-=7;
                        Points[0].ry()+=7;

                        Points[1].rx()-=7;
                        Points[1].ry()+=22;

                        Points[2].rx()-=7;
                        Points[2].ry()+=37;

                        for (int I = 3;I < 5;I++)
                        {
                            Points[I].rx()-=10000;
                            Points[I].ry()+=10000;
                        }
                    }break;

                    case 4:
                    {
                        Points[0].rx()-=7;
                        Points[0].ry()+=7;

                        Points[1].rx()-=7;
                        Points[1].ry()+=17;

                        Points[2].rx()-=7;
                        Points[2].ry()+=27;

                        Points[3].rx()-=7;
                        Points[3].ry()+=37;

                        Points[4].rx()-=10000;
                        Points[4].ry()+=10000;
                    }break;

                    case 5:
                    {
                        Points[0].rx()-=7;
                        Points[0].ry()+=2;

                        Points[1].rx()-=7;
                        Points[1].ry()+=12;

                        Points[2].rx()-=7;
                        Points[2].ry()+=22;

                        Points[3].rx()-=7;
                        Points[3].ry()+=32;

                        Points[4].rx()-=7;
                        Points[4].ry()+=42;
                    }break;
                }

                for (int J = 0; J < g->iInputCount;J++)
                {
                    if(b->DistanceFromObject(Points[J])<5)
                    {
                        b->update(static_cast<float>(Points[J].x() - 100),static_cast<float>(Points[J].y()) + 25);
                        //Check if all inputs are used then check if the input is already occupied

                        if(g->bActiveInputs[J]==false)
                        {
                            g->bActiveInputs[J] = true;
                            g->iActiveInputs++;
                            g->bInputs.append(true);
                        }
                    }
                }
            }
        }
    }


    for (auto b:this->OnList)
    {
        if (bConditionMove == true)
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
                QList<QPointF> Points;

                for (int I = 0;I < 5;I++)
                {
                    Points.append(g->scenePos());
                }

                switch (g->iInputCount)
                {
                    case 1:
                    {
                        Points[0].rx()-=7;
                        Points[0].ry()+=22;

                        for (int I = 1;I < 5;I++)
                        {
                            Points[I].rx()-=10000;
                            Points[I].ry()+=10000;
                        }
                    }break;

                    case 2:
                    {
                        Points[0].rx()-=7;
                        Points[0].ry()+=7;

                        Points[1].rx()-=7;
                        Points[1].ry()+=37;

                        for (int I = 2;I < 5;I++)
                        {
                            Points[I].rx()-=10000;
                            Points[I].ry()+=10000;
                        }
                    }break;

                    case 3:
                    {
                        Points[0].rx()-=7;
                        Points[0].ry()+=7;

                        Points[1].rx()-=7;
                        Points[1].ry()+=22;

                        Points[2].rx()-=7;
                        Points[2].ry()+=37;

                        for (int I = 3;I < 5;I++)
                        {
                            Points[I].rx()-=10000;
                            Points[I].ry()+=10000;
                        }
                    }break;

                    case 4:
                    {
                        Points[0].rx()-=7;
                        Points[0].ry()+=7;

                        Points[1].rx()-=7;
                        Points[1].ry()+=17;

                        Points[2].rx()-=7;
                        Points[2].ry()+=27;

                        Points[3].rx()-=7;
                        Points[3].ry()+=37;

                        Points[4].rx()-=10000;
                        Points[4].ry()+=10000;
                    }break;

                    case 5:
                    {
                        Points[0].rx()-=7;
                        Points[0].ry()+=2;

                        Points[1].rx()-=7;
                        Points[1].ry()+=12;

                        Points[2].rx()-=7;
                        Points[2].ry()+=22;

                        Points[3].rx()-=7;
                        Points[3].ry()+=32;

                        Points[4].rx()-=7;
                        Points[4].ry()+=42;
                    }break;
                }

                for (int J = 0; J < g->iInputCount;J++)
                {
                    if(b->DistanceFromObject(Points[J])<5)
                    {
                        b->update(static_cast<float>(Points[J].x()),static_cast<float>(Points[J].y()));
                        //Check if all inputs are used then check if the input is already occupied

                        if(g->bActiveInputs[J]==false)
                        {
                            g->bActiveInputs[J] = true;
                            g->iActiveInputs++;
                            g->bInputs.append(true);
                        }
                    }
                }
            }
        }
    }

    for (auto b:this->OffList)
    {
        if (bConditionMove == true)
        {
            if(b->DistanceFromObject(event->scenePos())<25)
            {
                b->update(static_cast<float>(event->scenePos().x()),static_cast<float>(event->scenePos().y()));
                Environment::update();
            }
            for (auto g:this->Gates)
            {
                QList<QPointF> Points;

                for (int I = 0;I < 5;I++)
                {
                    Points.append(g->scenePos());
                }

                switch (g->iInputCount)
                {
                    case 1:
                    {
                        Points[0].rx()-=7;
                        Points[0].ry()+=22;

                        for (int I = 1;I < 5;I++)
                        {
                            Points[I].rx()-=10000;
                            Points[I].ry()+=10000;
                        }
                    }break;

                    case 2:
                    {
                        Points[0].rx()-=7;
                        Points[0].ry()+=7;

                        Points[1].rx()-=7;
                        Points[1].ry()+=37;

                        for (int I = 2;I < 5;I++)
                        {
                            Points[I].rx()-=10000;
                            Points[I].ry()+=10000;
                        }
                    }break;

                    case 3:
                    {
                        Points[0].rx()-=7;
                        Points[0].ry()+=7;

                        Points[1].rx()-=7;
                        Points[1].ry()+=22;

                        Points[2].rx()-=7;
                        Points[2].ry()+=37;

                        for (int I = 3;I < 5;I++)
                        {
                            Points[I].rx()-=10000;
                            Points[I].ry()+=10000;
                        }
                    }break;

                    case 4:
                    {
                        Points[0].rx()-=7;
                        Points[0].ry()+=7;

                        Points[1].rx()-=7;
                        Points[1].ry()+=17;

                        Points[2].rx()-=7;
                        Points[2].ry()+=27;

                        Points[3].rx()-=7;
                        Points[3].ry()+=37;

                        Points[4].rx()-=10000;
                        Points[4].ry()+=10000;
                    }break;

                    case 5:
                    {
                        Points[0].rx()-=7;
                        Points[0].ry()+=2;

                        Points[1].rx()-=7;
                        Points[1].ry()+=12;

                        Points[2].rx()-=7;
                        Points[2].ry()+=22;

                        Points[3].rx()-=7;
                        Points[3].ry()+=32;

                        Points[4].rx()-=7;
                        Points[4].ry()+=42;
                    }break;
                }

                for (int J = 0; J < g->iInputCount;J++)
                {
                    if(b->DistanceFromObject(Points[J])<5)
                    {
                        b->update(static_cast<float>(Points[J].x()),static_cast<float>(Points[J].y()));
                        if(g->bActiveInputs[J]==false)
                        {
                            g->bActiveInputs[J] = true;
                            g->iActiveInputs++;
                            g->bInputs.append(false);
                        }
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
        if (bGateMove == true)
        {
            if(b->DistanceFromObject(event->scenePos())<50)
            {
                b->update(static_cast<float>(event->scenePos().x()),static_cast<float>(event->scenePos().y()));
                Environment::update();
                break;
            }
        }
    }

   if (!bGateMove)
   {
        this->UpdateInputs(event);
   }

}


