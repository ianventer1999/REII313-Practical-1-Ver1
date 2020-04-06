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
    this->setX(static_cast<double>(x));
    this->setY(static_cast<double>(y));
}

QRectF On::boundingRect() const
{
    return QRectF(0,0,5,5);
}

void On::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::black);
    painter->drawRect(0,0,6,6);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}
