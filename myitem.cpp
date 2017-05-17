#include "myitem.h"

myItem::myItem()
{
    setToolTip("Click and drag me!");   //提示
    setCursor(Qt::OpenHandCursor);      //改变光标
    color = QColor(qrand() % 256, qrand() % 256, qrand() % 256);    //初始化随机颜色
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
    painter->setBrush(color);
    painter->drawRect(0, 0, 20, 20);
}

void myItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(Qt::LeftButton != event->button())
    {
        event->ignore();    //忽略事件
        return;
    }
    setCursor(Qt::ClosedHandCursor);
}

void myItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QLineF line(event->screenPos(), event->buttonDownScreenPos(Qt::LeftButton));
    //左键按下的电到当前点的距离小于程序默认的拖动距离，表明没有拖动，则返回
    if(line.length() < QApplication::startDragDistance())
    {
        return;
    }
    QDrag *drag = new QDrag(event->widget());   //为event所在的窗口部件新建拖动对象
    QMimeData* mime = new QMimeData;    //新建QMimeData对象，来存储拖动的数据
    drag->setMimeData(mime);    //关联
    mime->setColorData(color);  //放入颜色数据

    QPixmap pix(21, 21);    //新建QPixmap对象，用来绘制圆形，在拖动时显示
    pix.fill(Qt::white);
    QPainter painter(&pix);
    paint(&painter, 0, 0);
    drag->setPixmap(pix);

    drag->setHotSpot(QPoint(10, 15));   //让指针指向圆形的(10,15)点
    drag->exec();   //开始拖动
    setCursor(Qt::OpenHandCursor);  //改变光标
}

void myItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event);
    setCursor(Qt::OpenHandCursor);
}

RectItem::RectItem()
{
    setAcceptDrops(true);   //设置接受拖放
    color = QColor(Qt::lightGray);
}

QRectF RectItem::boundingRect() const
{
    return QRectF(0, 0, 50, 50);
}

void RectItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(dragOver? color.light(130): color);   //有拖动，颜色变亮
    painter->drawRect(0, 0, 50, 50);
}

void RectItem::dragEnterEvent(QGraphicsSceneDragDropEvent *event)
{
    if(event->mimeData()->hasColor())   //如果拖动颜色的数据中有颜色数据，便接收
    {
        event->setAccepted(true);
        dragOver = true;
        update();
    }
}

void RectItem::dragLeaveEvent(QGraphicsSceneDragDropEvent *event)
{
    Q_UNUSED(event);
    dragOver = false;
    update();
}

void RectItem::dropEvent(QGraphicsSceneDragDropEvent *event)
{
    dragOver = false;
    if(event->mimeData()->hasColor())
    {
        color = qvariant_cast<QColor>(event->mimeData()->colorData());
        update();
    }
}
