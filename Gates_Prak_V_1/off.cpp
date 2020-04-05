#include "off.h"
#include <math.h>
clOFF::clOFF(int X, int Y)
{
    this->setX(X);
    this->setY(Y);

}
double clOFF::DistanceFromObject(QPointF OtherObject)
{
    return sqrt(pow((OtherObject.x()-this->scenePos().x()),2) + pow((OtherObject.y()-this->scenePos().y()),2));
}

void clOFF::update(float x, float y)
{
    this->setX(static_cast<double>(x));
    this->setY(static_cast<double>(y));
}

QRectF clOFF::boundingRect() const
{
    return QRectF(0,0,10,10);
}

void clOFF::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //painter->setBrush(Qt::black);
    //painter->drawEllipse(0,0, 10, 10);
    painter->drawRect(0,0,10,10);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}
