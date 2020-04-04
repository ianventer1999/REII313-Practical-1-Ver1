#ifndef OFF_H
#define OFF_H


#include <QGraphicsItem>
#include <QKeyEvent>
#include <QPainter>

class clOFF : public QGraphicsItem
{
public:
    clOFF(int X,int Y);
    double DistanceFromObject(QPointF OtherObject);
    void update(float x,float y);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);





};
#endif // OFF_H
