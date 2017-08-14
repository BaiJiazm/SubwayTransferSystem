#ifndef MYVIEW_H
#define MYVIEW_H

#include <QGraphicsView>
#include <QWheelEvent>
#include <QGraphicsItem>

class MyView : public QGraphicsView
{
public:
    explicit MyView(QWidget *parent = 0);
protected:
    void wheelEvent(QWheelEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);

signals:

public slots:

};

#endif // MYVIEW_H
