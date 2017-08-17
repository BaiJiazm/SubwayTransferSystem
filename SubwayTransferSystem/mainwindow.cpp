#include "ui_mainwindow.h"
#include "ui_managelines.h"
#include "ui_querytransfer.h"
#include "mainwindow.h"

#include <QGraphicsItem>
#include <QMessageBox>
#include <QColorDialog>
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

    manageLines=new ManageLines;
    subwayGraph=new SubwayGraph;
    queryTransfer=new QueryTransfer;

    bool flag = subwayGraph->readFileData(":/data/data/outLine.txt");
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

    myConnect();

    updateTranserQueryInfo();

    QList<int> stationsList;
    QList<Edge> edgesList;
    subwayGraph->getGraph(stationsList,edgesList);

//    qDebug()<<"stations.size()="<<stationsList.size()<<" edges.size()="<<edgesList.size();

    drawEdges(edgesList);
    drawStations(stationsList);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::myConnect()
{
    connect(manageLines->ui->tabWidget, SIGNAL(currentChanged(int)), this, SLOT(tabWidgetCurrentChanged(int)));
    connect(manageLines->ui->pushButtonAddLine, SIGNAL(clicked()), this, SLOT(addLine()));
    connect(manageLines->ui->pushButtonAddStation, SIGNAL(clicked()), this, SLOT(addStation()));
    connect(manageLines->ui->pushButtonConnect, SIGNAL(clicked()), this, SLOT(addConnection()));
    connect(manageLines->ui->pushButtonAddByText, SIGNAL(clicked()), this, SLOT(addByText()));
    connect(ui->comboBoxStartLine, SIGNAL(currentIndexChanged(QString)),
            this, SLOT(transferStartLineChanged(QString)));
    connect(ui->comboBoxDstLine, SIGNAL(currentIndexChanged(QString)),
            this, SLOT(transferDstLineChanged(QString)));
    connect(ui->pushButtonTransfer, SIGNAL(clicked()), this, SLOT(transferQuery()));
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
        color2=subwayGraph->getLineColor(linesList[i]);
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
        str+=subwayGraph->getLineName(linesList[i]);
    }
//    qDebug()<<"tip="<<str<<"\n";
    return str;
}

QPointF MainWindow::transferCoord(QPointF coord)
{
    QPointF minCoord=subwayGraph->getMinCoord();
    QPointF maxCoord=subwayGraph->getMaxCoord();
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

        QList<int> linesList=subwayGraph->getCommonLines(s1, s2);
        QColor color=getLinesColor(linesList);
        QString tip="途经： "+subwayGraph->getStationName(s1)+"--"+subwayGraph->getStationName(s2)+"\n线路：";
        tip+=getLinesName(linesList);
        QPointF s1Pos=transferCoord(subwayGraph->getStationCoord(s1));
        QPointF s2Pos=transferCoord(subwayGraph->getStationCoord(s2));

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
        QString name=subwayGraph->getStationName(s);
        QList<int> linesList=subwayGraph->getStationLinesInfo(s);
        QString tip="站名： "+name+"\n线路："+getLinesName(linesList);
        QColor color=getLinesColor(linesList);
        QPointF coord=transferCoord(subwayGraph->getStationCoord(s));

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

void MainWindow::on_actionAddAll_triggered()
{
    manageLines->setAllVisible();
    manageLines->show();
}

void MainWindow::on_actionAddLine_triggered()
{
    manageLines->setAddLineVisible();
    manageLines->show();
}

void MainWindow::on_actionAddStation_triggered()
{
    manageLines->setAddStationVisible();
    manageLines->show();
}

void MainWindow::on_actionAddConnect_triggered()
{
    manageLines->setAddConnectionVisible();
    manageLines->show();
}

void MainWindow::on_actionAddByText_triggered()
{
    manageLines->setAddByTextVisible();
    manageLines->show();
}

void MainWindow::updateTranserQueryInfo()
{
    QComboBox* comboL1=ui->comboBoxStartLine;
    QComboBox* comboL2=ui->comboBoxDstLine;

    comboL1->clear();
    comboL2->clear();
    QList<QString> linesList=subwayGraph->getLinesNameList();
    for(auto &a:linesList)
    {
        comboL1->addItem(a);
        comboL2->addItem(a);
    }
    transferStartLineChanged(comboL1->itemText(0));
    transferDstLineChanged(comboL2->itemText(0));
}

void MainWindow::transferStartLineChanged(QString lineName)
{
    QComboBox* comboS1=ui->comboBoxStartStation;
    comboS1->clear();

    int lineHash=subwayGraph->getLineHash(lineName);
    if(lineHash==-1)
    {
        return ;
    }

    QList<QString> stationsList=subwayGraph->getLineStationsList(lineHash);
    for(auto &a:stationsList)
    {
        comboS1->addItem(a);
    }
}

void MainWindow::transferDstLineChanged(QString lineName)
{
    QComboBox* comboS2=ui->comboBoxDstStation;
    comboS2->clear();

    int lineHash=subwayGraph->getLineHash(lineName);
    if(lineHash==-1)
    {
        return ;
    }

    QList<QString> stationsList=subwayGraph->getLineStationsList(lineHash);
    for(auto &a:stationsList)
    {
        comboS2->addItem(a);
    }
}

void MainWindow::transferQuery()
{
    int s1=subwayGraph->getStationHash(ui->comboBoxStartStation->currentText());
    int s2=subwayGraph->getStationHash(ui->comboBoxDstStation->currentText());
    int way=ui->radioButtonMinTime->isChecked()?1:2;

    QMessageBox box;
    box.setWindowTitle(tr("换乘查询"));
    box.setWindowIcon(QIcon(":/icon/icon/query.png"));

    if(s1==-1||s2==-1)
    {
        box.setIcon(QMessageBox::Warning);
        box.setText(tr("请选择有站点的线路"));
    }
    else
    {
        QList<int> stationsList;
        QList<Edge> edgesList;
        bool flag=true;
        if(way==1)
        {
            flag=subwayGraph->queryTransferMinTime(s1, s2, stationsList, edgesList);
        }
        else
        {
            flag=subwayGraph->queryTransferMinTransfer(s1, s2, stationsList, edgesList);
        }

        if(flag)
        {
            scene->clear();
            drawEdges(edgesList);
            drawStations(stationsList);
            QString text;
            for(int i=0; i<stationsList.size(); ++i)
            {
                text+=subwayGraph->getStationName(stationsList[i]);
                text+="\n";
            }
            QTextBrowser* browser=ui->textBrowserRoute;
            browser->clear();
            browser->setText(text);
        }
        else
        {
            box.setIcon(QMessageBox::Warning);
            box.setText(tr("您选择的起始和终止站点暂时无法到达！"));
        }
    }

    box.addButton(tr("确定"),QMessageBox::AcceptRole);
    if(box.exec()==QMessageBox::Accepted)
    {
        box.close();
    }
}

void MainWindow::tabWidgetCurrentChanged(int index)
{
    QWidget* widget=manageLines->ui->tabWidget->currentWidget();

    if(widget==manageLines->tabWigetsVector[1])
    {
        manageLines->linesNameList=subwayGraph->getLinesNameList();
        manageLines->updateLinesListWidget();
    }
    else if(widget==manageLines->tabWigetsVector[2])
    {
        manageLines->linesNameList=subwayGraph->getLinesNameList();
        manageLines->stationsNameList=subwayGraph->getStationsNameList();
        manageLines->ui->comboBoxConnectStation1->setMaxCount(manageLines->stationsNameList.size());
        manageLines->ui->comboBoxConnectStation2->setMaxCount(manageLines->stationsNameList.size());
        manageLines->ui->comboBoxConnectLine->setMaxCount(manageLines->linesNameList.size());
        manageLines->updateComboBox();
    }
}

void MainWindow::addLine()
{
    QMessageBox box;
    box.setWindowTitle(tr("添加线路"));
    box.setWindowIcon(QIcon(":/icon/icon/subway.png"));

    if(manageLines->lineName.isEmpty())
    {
        box.setIcon(QMessageBox::Warning);
        box.setText(tr("请输入线路名称！"));
    }
    else if(subwayGraph->getLineHash(manageLines->lineName)==-1)
    {
        box.setIcon(QMessageBox::Information);
        box.setText(tr("线路：")+manageLines->lineName+tr(" 添加成功！"));
        subwayGraph->addLine(manageLines->lineName, manageLines->lineColor);
        updateTranserQueryInfo();
    }
    else
    {
        box.setIcon(QMessageBox::Critical);
        box.setText(tr("添加失败！\n错误原因：线路名已存在！"));
    }

    box.addButton(tr("确定"),QMessageBox::AcceptRole);
    if(box.exec()==QMessageBox::Accepted)
    {
        box.close();
    }
}

void MainWindow::addStation()
{
    QMessageBox box;
    box.setWindowTitle(tr("添加站点"));
    box.setWindowIcon(QIcon(":/icon/icon/station.png"));

    if(manageLines->stationName.isEmpty())
    {
        box.setIcon(QMessageBox::Warning);
        box.setText(tr("请输入站点名称！"));
    }
    else if(manageLines->linesSelected.isEmpty())
    {
        box.setIcon(QMessageBox::Warning);
        box.setText(tr("请选择站点所属线路！"));
    }
    else
    {
        if(subwayGraph->getStationHash(manageLines->stationName)!=-1)
        {
            box.setIcon(QMessageBox::Critical);
            box.setText(tr("添加失败！\n错误原因：站点已存在！"));
        }
        else
        {
            Station s(manageLines->stationName, manageLines->longitude, manageLines->latitude,
                      subwayGraph->getLinesHash(manageLines->linesSelected));
            subwayGraph->addStation(s);
            box.setText(tr("站点：")+manageLines->stationName+tr(" 添加成功！"));
            updateTranserQueryInfo();
        }
    }

    box.addButton(tr("确定"),QMessageBox::AcceptRole);
    if(box.exec()==QMessageBox::Accepted)
    {
        box.close();
    }
}

void MainWindow::addConnection()
{
    QString station1=manageLines->ui->comboBoxConnectStation1->currentText();
    QString station2=manageLines->ui->comboBoxConnectStation2->currentText();
    int s1=subwayGraph->getStationHash(station1);
    int s2=subwayGraph->getStationHash(station2);
    int l=subwayGraph->getLineHash(manageLines->ui->comboBoxConnectLine->currentText());

    QMessageBox box;
    box.setWindowTitle(tr("添加连接"));
    box.setWindowIcon(QIcon(":/icon/icon/connect.png"));

    if(s1==-1||s2==-1||l==-1)
    {
        box.setIcon(QMessageBox::Warning);
        box.setText(tr("请选择已有的站点和线路！"));
    }
    else if(s1==s2)
    {
        box.setIcon(QMessageBox::Warning);
        box.setText(tr("同一站点不需要连接！"));
    }
    else if(!subwayGraph->getStationLinesInfo(s1).contains(l))
    {
        box.setIcon(QMessageBox::Critical);
        box.setText(tr("连接失败！\n错误原因：所属线路不包含站点1"));
    }
    else if(!subwayGraph->getStationLinesInfo(s2).contains(l))
    {
        box.setIcon(QMessageBox::Critical);
        box.setText(tr("连接失败！\n错误原因：所属线路不包含站点2"));
    }
    else
    {
        box.setIcon(QMessageBox::Information);
        box.setText(tr("添加连接成功！"));
        subwayGraph->addConnection(s1,s2,l);
    }
    if(box.exec()==QMessageBox::Accepted)
    {
        box.close();
    }
}

void MainWindow::addByText()
{

}
