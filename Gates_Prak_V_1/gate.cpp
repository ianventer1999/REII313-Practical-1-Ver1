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
    this->setX(static_cast<double>(x));
    this->setY(static_cast<double>(y));
}

void clGate::pUpdateInputCount(int)
{

}
