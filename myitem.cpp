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
    /**********************************************
    QGraphicsItem类中有三个碰撞检测函数，分别是：
    collidesWithItem()、collidesWithPath()collidingItems()
    collidesWithItem():该图形是否与指定的图形碰撞
    collidesWithPath():该图形是否与指定的路径碰撞
    collidingItems():返回与该图形碰撞的图形项列表
    这三个函数都有一个共同的参数Qt::ItemSelectionMode，指定如何去检测碰撞
    这是一个枚举变量，有四个值：分别是：
    Qt::ContainsItemShape:只有图形象的shape被完全包围时；
    Qt::IntersectsItemShape:当图形项的shape被完全包含时，或者图形项与其边界相交，默认；
    Qt::ContainsItemBoundingRect:只有图形象的bounding rectangle被完全包含时；
    Qt::IntersectsItemBoundingRect:图形项的bounding rectangle被完全包含时，或者图形项与其边界相交
    shape():返回一个QPainterPath对象，可以确定图形形状
    boundingRect():返回矩形的形状
    ************************************************/
    //与其他图形碰撞则显示red，否则显示green
    if(!collidingItems().isEmpty())
    {
        painter->setBrush(Qt::red);
    }
    else
    {
        painter->setBrush(Qt::green);
    }

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
