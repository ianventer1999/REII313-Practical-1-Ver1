#include "on.h"

clOn::clOn(int X, int Y)
{
    this->setX(X);
    this->setY(Y);
    this->bOutput = true;
}

double clOn::DistanceFromObject(QPointF OtherObject)
{
    return sqrt(pow((OtherObject.x()-this->scenePos().x()),2) + pow((OtherObject.y()-this->scenePos().y()),2));
}

void clOn::update(float x, float y)
{
    this->setX(static_cast<double>(x));
    this->setY(static_cast<double>(y));
}

QRectF clOn::boundingRect() const
{
    return QRectF(0,0,5,5);
}

void clOn::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::black);
    painter->drawRect(0,0,6,6);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

bool clOn::fDetermineOutput()
{
    bOutput = true;
    return true;
}
