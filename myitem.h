#ifndef MYITEM_H
#define MYITEM_H

#include <QGraphicsItem>
#include <QRectF>
#include <QPainter>
#include <QCursor>
#include <QKeyEvent>
#include <QGraphicsSceneMouseEvent>
#include <QPainterPath>
#include <QGraphicsItemAnimation>
#include <QTimeLine>

/*********************************************
 * 实现图形项的动画效果，也可以在不同的层面进行，如果只想
 * 控制一两个图形项的动画，一般在场景或视图中实现。但是，
 * 要是想让一个图形项类的多个对象都进行同样的动画，那么，
 * 就可以在图形项类中实现
 ********************************************/
class myItem : public QGraphicsItem
{
public:
    myItem();
    ~myItem();

    QRectF boundingRect() const;    //定义item的绘制范围
    //绘制图形项
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    QPainterPath shape() const;
protected:
    void keyPressEvent(QKeyEvent* event);

    void mousePressEvent(QGraphicsSceneMouseEvent* event);

    void advance(int phase);
};

#endif // MYITEM_H
