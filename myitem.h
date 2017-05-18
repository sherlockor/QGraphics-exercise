#ifndef MYITEM_H
#define MYITEM_H

#include <QGraphicsItem>
#include <QRectF>
#include <QPainter>
#include <QCursor>
#include <QKeyEvent>
#include <QGraphicsSceneMouseEvent>

class myItem : public QGraphicsItem
{
public:
    myItem();
    ~myItem();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

protected:
    void keyPressEvent(QKeyEvent* event);

    void mousePressEvent(QGraphicsSceneMouseEvent* event);

};

#endif // MYITEM_H
