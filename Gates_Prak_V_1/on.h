#ifndef ON_H
#define ON_H

#include <QGraphicsItem>
#include <QKeyEvent>
#include <QPainter>

class On : public QGraphicsItem
{
public:
    On(int X,int Y);
    double DistanceFromObject(QPointF OtherObject);
    void update(float x,float y);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);





};

#endif // ON_H
