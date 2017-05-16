#ifndef MYITEM_H
#define MYITEM_H

#include <QGraphicsItem>
#include <QRectF>
#include <QPainter>
#include <QCursor>

class myItem : public QGraphicsItem
{
public:
    myItem();
    ~myItem();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // MYITEM_H
