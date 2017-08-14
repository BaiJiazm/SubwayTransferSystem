#include "myview.h"

MyView::MyView(QWidget *parent) : QGraphicsView(parent)
{
//    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
//    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
//    setRenderHint(QPainter::Antialiasing);
//    setCursor(Qt::PointingHandCursor);

//    centerOn(0,0);
}

void MyView::wheelEvent(QWheelEvent *event)
{
    if(event->delta()>0)
        scale(0.5,0.5);
    else
        scale(2,2);
}

void MyView::mousePressEvent(QMouseEvent *event)
{
    rotate(90);  //视图旋转顺时针90度
}

void MyView::keyPressEvent(QKeyEvent *event)
{
    items().at(1)->setPos(400,400);
}
