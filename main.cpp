#include "mainwindow.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsView>
#include <myitem.h>
#include <QTime>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));    //设置随机秒数初值
    QGraphicsScene* scene = new QGraphicsScene; //场景
    for(int i = 0; i < 5; i++)
    {
        myItem* item = new myItem;  //自定义项
        item->setPos(i*50+20, 100);
        scene->addItem(item);   //添加项目到场景
    }
    RectItem* rect = new RectItem;  //新建矩形
    rect->setPos(100, 200);
    scene->addItem(rect);

    QGraphicsView* view = new QGraphicsView;    //视图
    view->setScene(scene);  //视图关联场景
    view->resize(400,300);  //设置视图大小
    view->show();   //显示视图

    return a.exec();
}
