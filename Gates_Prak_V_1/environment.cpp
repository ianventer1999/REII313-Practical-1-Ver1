#include "environment.h"

Environment::Environment()
{

    this->iInputs = 0;   
    this->Gates.append(new clAND(0,0,this->iInputs));
    this->addItem(Gates[0]);

    this->iInputs = 0;
    this->Gates.append(new clNAND(0,100,this->iInputs));
    //this->Gates[1]->iInputCount = this->iInputs;
    this->addItem(Gates[1]);

    this->iInputs = 0;
    this->Gates.append(new clOR(0,200,this->iInputs));
    this->addItem(Gates[2]);

    this->iInputs = 0;
    this->Gates.append(new clNOR(0,300,this->iInputs));
    this->addItem(Gates[3]);

    this->iInputs = 0;
    this->Gates.append(new clXNOR(0,400,this->iInputs));
    this->addItem(Gates[4]);

    this->iInputs = 0;
    this->Gates.append(new clXOR(0,500,this->iInputs));
    this->addItem(Gates[5]);


    this->iInputs = 0;
    this->Gates.append(new clNOT(0,600,this->iInputs));
    this->addItem(Gates[6]);


    this->update_timer = new QTimer(this);
    connect(this->update_timer, SIGNAL(timeout()),this,SLOT(update_scene()));
    this->update_timer->start(1000);
}

Environment::~Environment()
{

}

void Environment ::keyPressEvent(QKeyEvent *event)
{


}

void Environment ::keyReleaseEvent(QKeyEvent *event)
{

}

void Environment ::update_scene()
{
    if (this->iInputs < 6)
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
    }
}
