#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsItem>
#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    myView = new Graphics_view_zoom(ui->graphicsView);
    myView->set_modifiers(Qt::NoModifier);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);

    scene=new QGraphicsScene;
    scene->setSceneRect(-LINE_INFO_WIDTH,0,SCENE_WIDTH,SCENE_HEIGHT);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setDragMode(QGraphicsView::ScrollHandDrag);

    bool flag = subwayGraph.readFileData(":/data/data/outLine.txt");
    if (!flag)
    {
        QMessageBox box;
        box.setWindowTitle(tr("error information"));
        box.setIcon(QMessageBox::Warning);
        box.setText("读取数据错误!\n将无法展示内置线路！");
        box.addButton(tr("确定"), QMessageBox::AcceptRole);
        if (box.exec() == QMessageBox::Accepted)
        {
            box.close();
        }
    }

    QList<int> stationsList;
    QList<Edge> edgesList;
    subwayGraph.getGraph(stationsList,edgesList);

//    qDebug()<<"stations.size()="<<stationsList.size()<<" edges.size()="<<edgesList.size();

    drawEdges(edgesList);
    drawStations(stationsList);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::test()
{
    QGraphicsRectItem* rectItem=new QGraphicsRectItem;
    rectItem->setRect(0,0,100,100);
    scene->addItem(rectItem);
    rectItem->setPos(0,0);


//    QGraphicsRectItem* rectItem2=new QGraphicsRectItem;
//    rectItem2->setRect(0,0,100,100);
//    scene->addItem(rectItem2);
//    rectItem2->setPos(100,100);

    QGraphicsEllipseItem * ellipseItem=new QGraphicsEllipseItem;
    ellipseItem->setRect(-5,-5,15,15);
    scene->addItem(ellipseItem);
    ellipseItem->setPos(100,100);
    ellipseItem->setBrush(QBrush(QColor(QRgb(0xffffff))));
    QPen pen(QRgb(0xaaaaaa));
    pen.setWidth(2);
    ellipseItem->setPen(pen);

    QPen linePen(QRgb(123456));
    linePen.setWidth(10);
    QGraphicsLineItem *lineItem=new QGraphicsLineItem;
    lineItem->setPen(linePen);
    scene->addItem(lineItem);
    lineItem->setPos(200, 200);
    QLineF line(QPointF(0,0),QPointF(100,-100));
    lineItem->setLine(line);
    lineItem->setZValue(0);

    QGraphicsEllipseItem * ellipseItem2=new QGraphicsEllipseItem;
    ellipseItem2->setRect(-10,-10,50,50);
    scene->addItem(ellipseItem2);
    ellipseItem2->setPos(200,200);
    QPixmap pixmap(":/images/images/transfer.png");
    ellipseItem2->setBrush(Qt::red);
    ellipseItem2->setToolTip("站点：虹桥\n经度：\n纬度：\n");
    ellipseItem2->setCursor(Qt::PointingHandCursor);
    ellipseItem2->setZValue(0);
//    ellipseItem2->setPen(pen);

    QGraphicsTextItem *textItem=new QGraphicsTextItem;
    textItem->setPos(205,205);
    textItem->setPlainText("123号线");
    scene->addItem(textItem);

    QList<QGraphicsItem*> itemList=textItem->collidingItems();

    qDebug()<<itemList.size()<<"\n";
}

QColor MainWindow::getLinesColor(const QList<int>& linesList)
{
    QColor color1=QColor(255,255,255);
    QColor color2;
    for (int i=0; i<linesList.size(); ++i)
    {
        color2=subwayGraph.getLineColor(linesList[i]);
        color1.setRed(color1.red()*color2.red()/255);
        color1.setGreen(color1.green()*color2.green()/255);
        color1.setBlue(color1.blue()*color2.blue()/255);
    }
    return color1;
}

QString MainWindow::getLinesName(const QList<int>& linesList)
{
    QString str;
    for (int i=0; i<linesList.size(); ++i)
    {
        str+=" ";
        str+=subwayGraph.getLineName(linesList[i]);
    }
//    qDebug()<<"tip="<<str<<"\n";
    return str;
}

QPointF MainWindow::transferCoord(QPointF coord)
{
    QPointF minCoord=subwayGraph.getMinCoord();
    QPointF maxCoord=subwayGraph.getMaxCoord();
    double x = (coord.x()-minCoord.x())/(maxCoord.x()-minCoord.x())*NET_WIDTH+MARGIN;
    double y = (maxCoord.y()-coord.y())/(maxCoord.y()-minCoord.y())*NET_HEIGHT+MARGIN;
    return QPointF(x,y);
}

void MainWindow::drawEdges(const QList<Edge>& edgesList)
{
    for(int i=0; i<edgesList.size(); ++i)
    {
        int s1=edgesList[i].first;
        int s2=edgesList[i].second;

        QList<int> linesList=subwayGraph.getCommonLines(s1, s2);
        QColor color=getLinesColor(linesList);
        QString tip="途经： "+subwayGraph.getStationName(s1)+"--"+subwayGraph.getStationName(s2)+"\n线路：";
        tip+=getLinesName(linesList);
        QPointF s1Pos=transferCoord(subwayGraph.getStationCoord(s1));
        QPointF s2Pos=transferCoord(subwayGraph.getStationCoord(s2));

        QGraphicsLineItem* edgeItem=new QGraphicsLineItem;
        edgeItem->setPen(QPen(color, EDGE_PEN_WIDTH));
        edgeItem->setCursor(Qt::PointingHandCursor);
        edgeItem->setToolTip(tip);
        edgeItem->setPos(s1Pos);
        edgeItem->setLine(0, 0, s2Pos.x()-s1Pos.x(), s2Pos.y()-s1Pos.y());
        scene->addItem(edgeItem);
    }
}

void MainWindow::drawStations (const QList<int>& stationsList)
{
    for (int i=0; i<stationsList.size(); ++i)
    {
        int s=stationsList[i];
        QString name=subwayGraph.getStationName(s);
        QList<int> linesList=subwayGraph.getStationLinesInfo(s);
        QString tip="站名： "+name+"\n线路："+getLinesName(linesList);
        QColor color=getLinesColor(linesList);
        QPointF coord=transferCoord(subwayGraph.getStationCoord(s));

        QGraphicsEllipseItem* stationItem=new QGraphicsEllipseItem;
        stationItem->setRect(-NODE_HALF_WIDTH, -NODE_HALF_WIDTH, NODE_HALF_WIDTH<<1, NODE_HALF_WIDTH<<1);
        stationItem->setPos(coord);
        stationItem->setPen(color);
        stationItem->setCursor(Qt::PointingHandCursor);
        stationItem->setToolTip(tip);

        if(linesList.size()>1)
        {
            QBrush brush(QColor(QRgb(0xbbbbbb)),QPixmap(":/images/images/transfer1.png"));
            stationItem->setBrush(brush);
        }
        else
        {
            stationItem->setBrush(QColor(QRgb(0xffffff)));
        }
        scene->addItem(stationItem);

        QGraphicsTextItem* textItem=new QGraphicsTextItem;
        textItem->setPlainText(name);
        textItem->setFont(QFont("consolas",4,1));
        textItem->setPos(coord.x(),coord.y()-NODE_HALF_WIDTH*2);
        scene->addItem(textItem);
    }
}

void MainWindow::on_toolEnlarge_triggered()
{
    ui->graphicsView->scale(1.5,1.5);
}

void MainWindow::on_toolShrink_triggered()
{
    ui->graphicsView->scale(2.0/3,2.0/3);
}
