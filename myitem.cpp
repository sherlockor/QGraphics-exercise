#include "myitem.h"

myItem::myItem()
{
    setToolTip("Click and drag me!");   //提示
    setCursor(Qt::OpenHandCursor);      //改变光标

    setFlag(QGraphicsItem::ItemIsFocusable);    //图形项可以获得焦点
    setFlag(QGraphicsItem::ItemIsMovable);      //图形项是可移动的，可以代替鼠标事件拖动
}
myItem::~myItem()
{

}

QRectF myItem::boundingRect() const
{
    qreal penWidth = 1;
    return QRectF(0 - penWidth/2, 0 - penWidth/2,
                  20 + penWidth, 20 + penWidth);
}

void myItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);   //表明该参数没有使用
    Q_UNUSED(widget);
    painter->setBrush(Qt::red);
    painter->drawRect(0, 0, 20, 20);
}

void myItem::keyPressEvent(QKeyEvent *event)
{
    moveBy(0, 10);  //相对现在的位置移动
}

void myItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    moveBy(10, 0);
}
