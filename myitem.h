#ifndef MYITEM_H
#define MYITEM_H

#include <QGraphicsItem>
#include <QRectF>
#include <QPainter>
#include <QCursor>
#include <QKeyEvent>
#include <QGraphicsSceneMouseEvent>
#include <QPainterPath>

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

};

#endif // MYITEM_H
