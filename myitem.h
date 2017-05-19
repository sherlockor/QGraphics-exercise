#ifndef MYITEM_H
#define MYITEM_H

#include <QGraphicsItem>
#include <QRectF>
#include <QPainter>
#include <QCursor>
#include <QGraphicsSceneContextMenuEvent>
#include <QMenu>
#include <QAction>

/***********************************************
 * 图形项支持右键菜单，不过QGraphicsItem类并不是从QObject类
 * 继承而来的，所以它默认不能使用信号槽机智，为了能使用信号槽，
 * 我们需要降myItem类进行多重继承
 ************************************************/

class myItem : public QObject, public QGraphicsItem
{
    Q_OBJECT    //进行宏定义
public:
    myItem();
    virtual ~myItem();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

public slots:
    void moveTo();

protected:
    void contextMenuEvent(QGraphicsSceneContextMenuEvent* event);    //右键菜单事件处理函数

};

#endif // MYITEM_H
