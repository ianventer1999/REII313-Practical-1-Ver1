#include "gate.h"
#include <math.h>

clGate::clGate()
{

}

clGate::~clGate()
{

}

double clGate::DistanceFromObject(QPointF OtherObject)
{
    return sqrt(pow((OtherObject.x()-this->scenePos().x()),2) + pow((OtherObject.y()-this->scenePos().y()),2));
}

void clGate::update(float x,float y)
{

    this->setX(x);
    this->setY(y);
}

void clGate::pUpdateInputCount(int)
{

}

bool clGate::fDetermineOuptut()
{

}

