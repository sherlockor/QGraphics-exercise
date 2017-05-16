#include "mainwindow.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsView>
#include <myitem.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    QGraphicsScene* scene = new QGraphicsScene; //场景
    myItem* item = new myItem;  //自定义项
    scene->addItem(item);   //添加项目到场景
    QGraphicsView* view = new QGraphicsView;    //视图
    view->setScene(scene);  //视图关联场景
    view->show();   //显示视图

    return a.exec();
}
