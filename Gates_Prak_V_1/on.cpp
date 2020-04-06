#include "on.h"
#include <math.h>
On::On(int X, int Y)
{
    this->setX(X);
    this->setY(Y);

}
double On::DistanceFromObject(QPointF OtherObject)
{
    return sqrt(pow((OtherObject.x()-this->scenePos().x()),2) + pow((OtherObject.y()-this->scenePos().y()),2));
}

void On::update(float x, float y)
{
    this->setX(x);
    this->setY(y);
}

QRectF On::boundingRect() const
{
    return QRectF(0,0,10,10);
}

void On::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::black);
    //painter->drawEllipse(0,0, 10, 10);
    painter->drawRect(0,0,10,10);
}
