#include "myitem.h"

myItem::myItem()
{
    setToolTip("Click and drag me!");   //提示
    setCursor(Qt::OpenHandCursor);      //改变光标

    setFlag(QGraphicsItem::ItemIsFocusable);    //图形项可以获得焦点
    setFlag(QGraphicsItem::ItemIsMovable);      //图形项是可移动的，可以代替鼠标事件拖动
    QGraphicsItemAnimation* anim = new QGraphicsItemAnimation;  //新建动画类对象
    anim->setItem(this);//讲该图形项加入动画对象中
    QTimeLine* timeLine = new QTimeLine(1000);  //新建长为1秒的时间线
    timeLine->setLoopCount(0);  //动画循环次数为0，表示无线循环
    anim->setTimeLine(timeLine);//将时间线加入动画类对象中
    anim->setRotationAt(0.5,180);//在动画执行一半的时候,图形项旋转180度
    anim->setRotationAt(1,360); //动画执行完时，图形项旋转360度
    timeLine->start();//开始动画
}
myItem::~myItem()
{

}

QRectF myItem::boundingRect() const
{
    qreal penWidth = 1;
    /*return QRectF(0 - penWidth/2, 0 - penWidth/2,
                  20 + penWidth, 20 + penWidth);*/
    return QRectF(0 - penWidth/2, 0 - penWidth/2,
                  50 + penWidth, 50 + penWidth);
}

void myItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);   //表明该参数没有使用
    Q_UNUSED(widget);

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

QPainterPath myItem::shape() const
{
    QPainterPath path;
    path.addRect(0,0,20,20);    //图形项的真实大小
    return path;
}

void myItem::advance(int phase)
{
    /********************************************
     * 对于图形项的移动，有很多办法可以实现，也可以在很多层面上进行控制，
     * 比如：在view上控制或者在scene上控制，但是对于大量的不同类型的
     * 图形项，如何一起控制呢？
     * 在图形视图框架中提供了advance()槽函数，在QGraphicsScene和QGraphicsItem
     * 中都有，在图形项类中，原型是advance(int phase)。
     * 实现流程：利用QGraphicsScene类的对象调用QGraphicsItem的
     * advance()函数，会执行两次该场景的advance(int phaase)函数，第一次的
     * phase为0，告诉所有图形项即将要移动，第二次phase为1，开始执行移动
     * *******************************************/
    if(!phase)
    {
        return;
    }
    moveBy(0,10);
}
