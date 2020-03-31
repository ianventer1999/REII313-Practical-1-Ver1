#include "environment.h"

Environment::Environment()
{
    this->iInputs = 0;

    this->Gates[0]     =   new clAND();
    this->Gates[0]->setX(0);
    this->Gates[0]->setY(0);
    this->Gates[0]->iInputCount = this->iInputs;
    this->addItem(Gates[0]);

    this->Gates[1]     =   new clOR();
    this->Gates[1]->setX(0);
    this->Gates[1]->setY(100);
    this->Gates[1]->iInputCount = this->iInputs;
    this->addItem(Gates[1]);

    this->Gates[2]     =   new clNOT();
    this->Gates[2]->setX(0);
    this->Gates[2]->setY(200);
    this->Gates[2]->iInputCount = this->iInputs;
    this->addItem(Gates[2]);

    this->Gates[3]     =   new clNAND();
    this->Gates[3]->setX(0);
    this->Gates[3]->setY(300);
    this->Gates[3]->iInputCount = this->iInputs;
    this->addItem(Gates[3]);

    this->Gates[4]     =   new clNOR();
    this->Gates[4]->setX(0);
    this->Gates[4]->setY(400);
    this->Gates[4]->iInputCount = this->iInputs;
    this->addItem(Gates[4]);

    this->Gates[5]     =   new clXOR();
    this->Gates[5]->setX(0);
    this->Gates[5]->setY(500);
    this->Gates[5]->iInputCount = this->iInputs;
    this->addItem(Gates[5]);

    this->Gates[6]     =   new clXNOR();
    this->Gates[6]->setX(0);
    this->Gates[6]->setY(600);
    this->Gates[6]->iInputCount = this->iInputs;
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

    for (int I = 0; I < 7; I++)
    {
        this->Gates[I]->iInputCount = this->iInputs;
        this->removeItem(Gates[I]);
        this->addItem(Gates[I]);
    }
}
