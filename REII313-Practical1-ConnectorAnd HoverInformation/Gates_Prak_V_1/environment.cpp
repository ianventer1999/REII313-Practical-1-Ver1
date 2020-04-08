#include "environment.h"

static  int     iGatePlace;
static  bool    bItemMove = false;
QList <QGraphicsTextItem*> Info ;

Environment::Environment()
{
    GatesDefault.append(new clAND(-5000,-1000,2));                                  //Add Gates with instructions on how to use
    GatesDefault.append(new clNAND(-4800,-1000,2));
    GatesDefault.append(new clOR(-4600,-1000,2));
    GatesDefault.append(new clNOR(-4400,-1000,2));
    GatesDefault.append(new clXOR(-4200,-1000,2));
    GatesDefault.append(new clXNOR(-4000,-1000,2));
    GatesDefault.append(new clNOT(-3800,-1000,2));
    DefaultOn.append(new clOn(-3570,-975));
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


    Info.append(addText("AND Gate: \nProduces an output which is true only if all its inputs are true"));
    Info.append(addText("NAND Gate: \nProduces an output which is false only if all its inputs are true"));
    Info.append(addText("OR Gate \nProduces an output which is true if only one inputs are true" ));
    Info.append(addText("NOR Gate \nProduces an output which is true if all the inputs are true"));
    Info.append(addText("XOR Gate \nProduces an output which is true if one, and only one, of the inputs to the gate is true"));
    Info.append(addText("XNOR Gate \nProduces an output which is false if only one of the inputs to the gate is true"));
    Info.append(addText("NOT Gate \nInverts the input to the gate"));

    for(auto & i : Info)
    {
        this->addItem(i);
    }


    for(int i=0;i<Info.size();++i)
    {
        Info[i]->setTextWidth(150);
        Info[i]->setPos(GatesDefault[i]->scenePos());
        Info[i]->moveBy(0,-100);
        Info[i]->setVisible(false);
    }

    iLastPositions[0] = -10000; //Have not clicked for connector yet

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
//Function Used to Display More Information of the operation of each gate
void Environment::GateInformation(QGraphicsSceneMouseEvent *event)
{

    QString sGateClassType;
    for(auto g:this->GatesDefault)
    {
      sGateClassType = g->GetClassName();
      if (g->DistanceFromObject(event->scenePos())<80)
      {
         if(g->GetClassName()=="AND")
         {
            Info[0]->setVisible(true);
         }
         else
         {
           Info[0]->setVisible(false);
         }
         if(g->GetClassName()=="NAND")
         {
            Info[1]->setVisible(true);
         }
         else
         {
           Info[1]->setVisible(false);
         }
         if(g->GetClassName()=="OR")
         {
            Info[2]->setVisible(true);
         }
         else
         {
           Info[2]->setVisible(false);
         }
         if(g->GetClassName()=="NOR")
         {
            Info[3]->setVisible(true);
         }
         else
         {
           Info[3]->setVisible(false);
         }
         if(g->GetClassName()=="XOR")
         {
            Info[4]->setVisible(true);
         }
         else
         {
           Info[4]->setVisible(false);
         }
         if(g->GetClassName()=="XNOR")
         {
            Info[5]->setVisible(true);
         }
         else
         {
           Info[5]->setVisible(false);
         }
         if(g->GetClassName()=="NOT")
         {
            Info[6]->setVisible(true);
         }
         else
         {
           Info[6]->setVisible(false);
         }

      }
    }
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
    //****************************************************************************************************************************************************
    //When The MiddleButton(ScrollButton) Is pressed a conector is created between the first closest input
    if (event->button() == Qt::MiddleButton)                                                                                                                                //MiddlePress
    {
        if (this->Gates_IO.size() > 1)                                                                                          //Must have 2 things to conncet
        {
            if (iLastPositions[0] == -10000)
            {
                iLastPositions[0] = static_cast<int>(event->scenePos().x());
                iLastPositions[1] = static_cast<int>(event->scenePos().y());
            }
            else
            {
                int     iTemp           =   0;
                int     iScreenX        =   static_cast<int>(event->scenePos().x());
                int     iScreenY        =   static_cast<int>(event->scenePos().y());
                bool    bDir            =   true;
                bool    bDirX           =   true;
                bool    bDirY           =   true;
                int     iSmallest       =   1000;
                int     iSmallestPos    =   0;
                int     iClosest        =   0;                                                                                  //1 = G,2 = ON,3 = Off

                QPoint p1;                                                                                                      //First Click is Input Des, Second Click is Output
                p1.rx() = iLastPositions[0];
                p1.ry() = iLastPositions[1];

                for (int I = 0;I < this->Gates.size();I++)                                                                      //Determine if there is a Gate Obj closest to the mouse position
                {
                    if(static_cast<int>(this->Gates[I]->DistanceFromObject(p1)) < iSmallest)
                    {
                        iSmallest = static_cast<int>(this->Gates[I]->DistanceFromObject(p1));
                        iSmallestPos = I;                                                                                       //Saves the Gate Index position which is closest to the mouse event
                        iClosest = 1;                                                                                           //Save this variable in order to determine which class was closest to the mouse event
                    }
                }

                for (int I = 0;I < this->OnList.size();I++)                                                                     //Determine if the there is an On Obj closest to the mouse position
                {
                    if(static_cast<int>(this->OnList[I]->DistanceFromObject(p1)) < iSmallest)
                    {
                        iSmallest = static_cast<int>(this->OnList[I]->DistanceFromObject(p1));
                        iSmallestPos = I;                                                                                       //Saves the On obj Index position which is closest to the mouse event
                        iClosest = 2;                                                                                           //Save this variable in order to determine which class was closest to the mouse event
                    }
                }

                for (int I = 0;I < this->OffList.size();I++)                                                                    //Determine if the there is an Off Obj closest to the mouse position
                {
                    if(static_cast<int>(this->OffList[I]->DistanceFromObject(p1)) < iSmallest)
                    {
                        iSmallest = static_cast<int>(this->OffList[I]->DistanceFromObject(p1));
                        iSmallestPos = I;
                        iClosest = 3;
                    }
                }

                switch (iClosest)                                                                                               //Is necesary in order to determine if the mouse event is needed to derive input or to give input to a gate
                {
                    case 1:
                    {
                        iLastPositions[0] = static_cast<int>(this->Gates[iSmallestPos]->x()) + 100;
                        iLastPositions[1] = static_cast<int>(this->Gates[iSmallestPos]->y()) + 25;
                        this->Gates[iSmallestPos]->bConnectedOut = true;
                    }break;
                    case 2:
                    {
                        iLastPositions[0] = static_cast<int>(this->OnList[iSmallestPos]->x());
                        iLastPositions[1] = static_cast<int>(this->OnList[iSmallestPos]->y());
                    }break;
                    case 3:
                    {
                        iLastPositions[0] = static_cast<int>(this->OffList[iSmallestPos]->x());
                        iLastPositions[1] = static_cast<int>(this->OffList[iSmallestPos]->y());
                    }break;
                }
                //The folowing two if statement is used to determine how the line needs to be drawn should it go left/right up or down
                if (iScreenX < iLastPositions[0])
                {
                    iTemp = iScreenX;
                    iScreenX = iLastPositions[0];
                    iLastPositions[0] = iTemp;
                    bDir    = !bDir;
                    bDirX   = false;
                }

                if (iScreenY < iLastPositions[1])
                {
                    iTemp = iScreenY;
                    iScreenY = iLastPositions[1];
                    iLastPositions[1] = iTemp;
                    bDir    = !bDir;
                    bDirY   = false;
                }

                //Since all the neccessary information is obtained we can now create the connecter
                switch (iClosest)
                {
                    case 1:
                    {
                        this->Connectors.append(new clConnector(iLastPositions[0],iLastPositions[1],iScreenX - iLastPositions[0],iScreenY - iLastPositions[1],this->Gates[iSmallestPos]->bOutput,bDir,iClosest,iSmallestPos,bDirX,bDirY));
                    }break;
                    case 2:
                    {
                        this->Connectors.append(new clConnector(iLastPositions[0],iLastPositions[1],iScreenX - iLastPositions[0],iScreenY - iLastPositions[1],this->OnList[iSmallestPos]->bOutput,bDir,iClosest,iSmallestPos,bDirX,bDirY));
                    }break;
                    case 3:
                    {
                        this->Connectors.append(new clConnector(iLastPositions[0],iLastPositions[1],iScreenX - iLastPositions[0],iScreenY - iLastPositions[1],this->OffList[iSmallestPos]->bOutput,bDir,iClosest,iSmallestPos,bDirX,bDirY));
                    }break;
                }
                //Now Add the conecter to the GraphicsScene in order to make it visible
                Environment::addItem(this->Connectors.last());

                //Update the location of the last middle click button
                if (!bDirX)
                {
                    iScreenX = iLastPositions[0];
                }

                if (!bDirY)
                {
                    iScreenY = iLastPositions[1];
                }

                //Create a ON/OFF object at the end of the conector inorder for the gate to determine its input as usual
                if (this->Connectors.last()->bValue == true)
                {
                    OnList.append(new clOn(iScreenX,iScreenY));
                    ConnectList.append(OnList.last());
                    Environment::addItem(OnList.last());
                }
                else if (this->Connectors.last()->bValue == false)
                {
                    OffList.append(new clOFF(iScreenX,iScreenY));
                    ConnectList.append(OffList.last());
                    Environment::addItem(OffList.last());
                }

                iLastPositions[0] = -10000;
                Environment::update();
            }
        }
    }
    //****************************************************************************************************************************************************
    //When The Mouse Is clicked combined with holding alt and is in a 25 radius of the gate the number of inputs is increased by one
    else if (event->modifiers() == Qt::ALT)                                                                                                                                 //While holding ALT
    {
        QPointF p1;
        p1 = event->scenePos();
        p1.rx()-=50;
        p1.ry()-=25;

        for (int I = 0;I < this->Gates.size();I++)
        {
            if (this->Gates[I]->DistanceFromObject(p1)<25)
            {
                if ((this->Gates[I]->iInputCount < this->Gates[I]->iMaxInput) && (event->button() == Qt::LeftButton))
                {
                    this->Gates[I]->iInputCount++;
                }
                else if ((this->Gates[I]->iInputCount > 0) && (event->button() == Qt::RightButton))
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
    }
    //****************************************************************************************************************************************************
    //While Holding Shift and left clicking The gate that was selected on a keypressed event will be created at the location of the mouse cursor
    else if (event->modifiers() ==Qt::ShiftModifier)                                                                                                                        //While holding Shift
    {
        if (event->button() == Qt::LeftButton)
        {
            switch(iGatePlace)
            {
                case 1:
                {
                    Gates.append(new clAND(static_cast<int>(event->scenePos().x()),static_cast<int>(event->scenePos().y()),0));
                    Environment::addItem(Gates.last());
                    Gates_IO.append(Gates.last());
                }break;
                case 2:
                {
                    Gates.append(new clNAND(static_cast<int>(event->scenePos().x()),static_cast<int>(event->scenePos().y()),0));
                    Environment::addItem(Gates.last());
                    Gates_IO.append(Gates.last());
                }break;
                case 3:
                {
                    Gates.append(new clOR(static_cast<int>(event->scenePos().x()),static_cast<int>(event->scenePos().y()),0));
                    Environment::addItem(Gates.last());
                    Gates_IO.append(Gates.last());
                }break;
                case 4:
                {
                    Gates.append(new clNOR(static_cast<int>(event->scenePos().x()),static_cast<int>(event->scenePos().y()),0));
                    Environment::addItem(Gates.last());
                    Gates_IO.append(Gates.last());
                }break;
                case 5:
                {
                    Gates.append(new clXOR(static_cast<int>(event->scenePos().x()),static_cast<int>(event->scenePos().y()),0));
                    Environment::addItem(Gates.last());
                    Gates_IO.append(Gates.last());
                }break;
                case 6:
                {
                    Gates.append(new clXNOR(static_cast<int>(event->scenePos().x()),static_cast<int>(event->scenePos().y()),0));
                    Environment::addItem(Gates.last());
                    Gates_IO.append(Gates.last());
                }break;
                case 7:
                {
                    Gates.append(new clNOT(static_cast<int>(event->scenePos().x()),static_cast<int>(event->scenePos().y()),0));
                    Environment::addItem(Gates.last());
                    Gates_IO.append(Gates.last());
                }break;
                case 8:
                {
                   OnList.append(new clOn(static_cast<int>(event->scenePos().x()),static_cast<int>(event->scenePos().y())));
                   Environment::addItem(OnList.last());
                   Gates_IO.append(OnList.last());
                }break;
                case 9:
                {
                   OffList.append(new clOFF(static_cast<int>(event->scenePos().x()),static_cast<int>(event->scenePos().y())));
                   Environment::addItem(OffList.last());
                   Gates_IO.append(OffList.last());
                }break;
            }
        }
    }
    //****************************************************************************************************************************************************
    //A Normal left click will only make it possible for an item to move if the mouse is in close enough proximaty of an object (See the mousemove event)
    else if (event->button() == Qt::LeftButton)                                                                                                                             //Normal Left Click
    {
        if (bItemMove == false)
        {
            bItemMove = true;
        }
    }
    //****************************************************************************************************************************************************
    //On a normal right click event the closest item to that right click will be deleted
    else if (event->button() == Qt::RightButton)                                                                                                                            //Normal Right Click
    {
        int     iSmallest       =   1000;
        int     iSmallestPos    =   0;
        int     iClosest        =   0; //1 = G/IO,2 = Connector


        for (int I = 0;I < this->Gates_IO.size();I++)
        {
            if(static_cast<int>(this->Gates_IO[I]->DistanceFromObject(event->scenePos())) < iSmallest)
            {
                iSmallest = static_cast<int>(this->Gates_IO[I]->DistanceFromObject(event->scenePos()));
                iSmallestPos = I;
                iClosest = 1;
            }
        }

        for (int I = 0;I < this->Connectors.size();I++)
        {
            if(static_cast<int>(this->Connectors[I]->DistanceFromObject(event->scenePos())) < iSmallest)
            {
                iSmallest = static_cast<int>(this->Connectors[I]->DistanceFromObject(event->scenePos()));
                iSmallestPos = I;
                iClosest = 2;
            }
        }

        for (int I = 0;I < this->ConnectList.size();I++)
        {
            if(static_cast<int>(this->ConnectList[I]->DistanceFromObject(event->scenePos())) < iSmallest)
            {
                iSmallest = static_cast<int>(this->ConnectList[I]->DistanceFromObject(event->scenePos()));
                iSmallestPos = I;
                iClosest = 3;
            }
        }

        switch (iClosest)
        {
            case 1:
            {
                bool bRemove = false; //Checks if item was removed form other list like gates

                for (int I = 0; I < this->Gates.size();I++)
                {
                    if ((static_cast<int>(this->Gates[I]->x()) == static_cast<int>(this->Gates_IO[iSmallestPos]->x())) &&
                                                (static_cast<int>(this->Gates[I]->y()) == static_cast<int>(this->Gates_IO[iSmallestPos]->y())))
                    {
                        this->Gates.removeAt(I);
                        bRemove = true;
                    }
                }

                if (!bRemove)
                {
                    for (int I = 0; I < this->OnList.size();I++)
                    {
                        if ((static_cast<int>(this->OnList[I]->x()) == static_cast<int>(this->Gates_IO[iSmallestPos]->x())) &&
                                                    (static_cast<int>(this->OnList[I]->y()) == static_cast<int>(this->Gates_IO[iSmallestPos]->y())))
                        {
                            this->OnList.removeAt(I);
                            bRemove = true;
                        }
                    }
                }

                if (!bRemove)
                {
                    for (int I = 0; I < this->OffList.size();I++)
                    {
                        if ((static_cast<int>(this->OffList[I]->x()) == static_cast<int>(this->Gates_IO[iSmallestPos]->x())) &&
                                                    (static_cast<int>(this->OffList[I]->y()) == static_cast<int>(this->Gates_IO[iSmallestPos]->y())))
                        {
                            this->OffList.removeAt(I);
                            bRemove = true;
                        }
                    }
                }

                Environment::removeItem(this->Gates_IO[iSmallestPos]);
                this->Gates_IO.removeAt(iSmallestPos);
            }break;
            case 2:
            {
                Environment::removeItem(this->Connectors[iSmallestPos]);
                this->Connectors.removeAt(iSmallestPos);
            }break;
            case 3:
            {
                Environment::removeItem(this->ConnectList[iSmallestPos]);
                this->ConnectList.removeAt(iSmallestPos);
            }break;
        }

        Environment::update();
    }
    //****************************************************************************************************************************************************
}
void Environment::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    //Delete all outputs first

    for (int J = 0;J < OutList.size();J++)
    {
        Environment::removeItem(this->OutList[J]);

       for (int I = 0; I < this->OnList.size();I++)
        {
            if ((static_cast<int>(this->OnList[I]->x()) == static_cast<int>(this->OutList[J]->x())) &&
                                        (static_cast<int>(this->OnList[I]->y()) == static_cast<int>(this->OutList[J]->y())))
            {
                this->OnList.removeAt(I);
            }
        }

        for (int I = 0; I < this->OffList.size();I++)
        {
            if ((static_cast<int>(this->OffList[I]->x()) == static_cast<int>(this->OutList[J]->x())) &&
                                        (static_cast<int>(this->OffList[I]->y()) == static_cast<int>(this->OutList[J]->y())))
            {
                this->OffList.removeAt(I);
            }
        }

        this->OutList.removeAt(J);
    }

    iLastMoved = 0;//On release no item is being moved

    if((event->button() == Qt::LeftButton)&&(bItemMove == true))
    {
        bItemMove = false;
    }

    //Determine the output of the gate after each mouse release event

    bool bOut = false;
    for (int J = 0;J < this->Gates.size();J++)
    {
        if ((this->Gates[J]->iActiveInputs == this->Gates[J]->iInputCount) && (this->Gates[J]->iActiveInputs > 0))
        {
            bOut = this->Gates[J]->fDetermineOutput();

            if (!this->Gates[J]->bConnectedOut)
            {
                if (bOut)
                {
                    OnList.append(new clOn(static_cast<int>(this->Gates[J]->scenePos().x()+100),static_cast<int>(this->Gates[J]->scenePos().y() + 22)));
                    OutList.append(OnList.last());
                    Environment::addItem(OnList.last());
                    Environment::update();
                }
                else
                {
                    OffList.append(new clOFF(static_cast<int>(this->Gates[J]->scenePos().x()+100),static_cast<int>(this->Gates[J]->scenePos().y() + 22)));
                    OutList.append(OffList.last());
                    Environment::addItem(OffList.last());
                    Environment::update();
                }
            }
            else
            {
                for (int I = 0; I < this->Connectors.size();I++)
                {
                    if ((this->Connectors[I]->iClosestType == 1) && (this->Connectors[I]->iClosestListPos == J))
                    {
                        this->Connectors[I]->bValue = this->Gates[J]->bOutput;

                        int   X3    =   this->Connectors[I]->iStartX;
                        int   Y3    =   this->Connectors[I]->iStartY;

                        if (this->Connectors[I]->bDirX)
                        {
                            X3 = this->Connectors[I]->iStartX + this->Connectors[I]->iDisX;
                        }

                        if (this->Connectors[I]->bDirY)
                        {
                            Y3 = this->Connectors[I]->iStartY + this->Connectors[I]->iDisY;
                        }

                        if (this->Connectors[I]->bValue == true)
                        {
                            OnList.append(new clOn(X3,Y3));
                            OutList.append(OnList.last());
                            Environment::addItem(OnList.last());
                        }
                        else if (this->Connectors[I]->bValue == false)
                        {
                            OffList.append(new clOFF(X3,Y3));
                            OutList.append(OffList.last());
                            Environment::addItem(OffList.last());
                        }
                    }
                }
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
        if (bItemMove == true)
        {
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
                            g->bConnectedIn = true;
                        }
                    }
                }
            }
        }
    }

    for (auto b:this->OffList)
    {
        if (bItemMove == true)
        {
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
                            g->bConnectedIn= true;
                        }
                    }
                }
            }
        }
    }
    Q_UNUSED(event);
}

void Environment::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{    
    GateInformation(event);
    if (bItemMove)
    {
        if(iLastMoved == 0)
        {
            int iSmallest = 1000;
            for (int I = 0;I < this->Gates_IO.size();I++)
            {
                if(static_cast<int>(this->Gates_IO[I]->DistanceFromObject(event->scenePos())) < iSmallest)
                {
                    iSmallest = static_cast<int>(this->Gates_IO[I]->DistanceFromObject(event->scenePos()));
                    iLastMoved = I;
                }
            }
        }
        if (!(this->Gates_IO[iLastMoved]->bConnectedIn) && !(this->Gates_IO[iLastMoved]->bConnectedOut))
        this->Gates_IO[iLastMoved]->update(static_cast<float>(event->scenePos().x()),static_cast<float>(event->scenePos().y()));
        Environment::update();
        this->UpdateInputs(event);
    }
}


