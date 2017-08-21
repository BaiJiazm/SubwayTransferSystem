#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "graphics_view_zoom.h"
#include "subwaygraph.h"
#include "managelines.h"
#include "apphelp.h"

#include <QMainWindow>
#include <QLabel>
#include <QGraphicsScene>
#include <QGraphicsView>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    //视图放大槽函数
    void on_toolEnlarge_triggered();
    //动作视图缩小槽函数
    void on_toolShrink_triggered();
    //动作添加所有槽函数
    void on_actionAddAll_triggered();
    //动作添加线路槽函数
    void on_actionAddLine_triggered();
    //动作添加站点槽函数
    void on_actionAddStation_triggered();
    //动作添加连接槽函数
    void on_actionAddConnect_triggered();
    //动作文本方式添加槽函数
    void on_actionAddByText_triggered();
    //动作查看所有线路图槽函数
    void on_actionLineMap_triggered();
    //动作是否显示状态栏槽函数
    void on_actionstatusBar_triggered(bool checked);
    //动作是否显示工具栏槽函数
    void on_actiontoolBar_triggered(bool checked);
    //动作关于Qt槽函数
    void on_actionQt_triggered();
    //动作关于作者槽函数
    void on_actionAuthor_triggered();
    //动作帮助菜单槽函数
    void on_actionuseHelp_triggered();
    //动作关闭程序槽函数
    void on_actionClose_triggered();

    //时间更新槽函数
    void timerUpdate();
    //添加列表视图部件变化槽函数
    void tabWidgetCurrentChanged(int index);
    //添加线路功能函数
    void addLine();
    //添加站点功能函数
    void addStation();
    //添加连接功能函数
    void addConnection();
    //文本方式添加功能函数
    void addByText();
    //更新换乘选择信息
    void updateTranserQueryInfo();
    //换乘出发线路改变槽函数
    void transferStartLineChanged(QString lineName);
    //换乘目的线路改变槽函数
    void transferDstLineChanged(QString lineNames);
    //换乘查询槽函数
    void transferQuery();


protected:
    Ui::MainWindow *ui;             //主窗口UI
    Graphics_view_zoom *myView;     //自定义视图，用于鼠标缩放
    QGraphicsScene *scene;          //场景
    SubwayGraph* subwayGraph;       //后端管理类
    ManageLines* manageLines;       //添加功能前端管理类
    AppHelp* appHelp;               //帮助显示类

    //由线路表计算混合颜色
    QColor getLinesColor(const QList<int>& linesList);
    //获得线路表的名字集
    QString getLinesName(const QList<int>& linesList);
    //将站点的经纬度地理坐标转为视图坐标
    QPointF transferCoord(QPointF coord);
    //绘制网络图的边
    void drawEdges (const QList<Edge>& edgesList);
    //绘制网络图的站点节点
    void drawStations (const QList<int>& stationsList);

private:
    QLabel* statusLabel1, *statusLabel2, *statusLabel3;     //状态栏三个文本
    //连接信号和槽函数
    void myConnect();
    //初始状态栏
    void initStatusBar();
};

#define LINE_INFO_WIDTH 0   //预留边框用于信息展示
#define MARGIN 30           //视图左边距
#define NET_WIDTH 2000      //网络图最大宽度
#define NET_HEIGHT 2000     //网络图最大高度
#define SCENE_WIDTH (LINE_INFO_WIDTH+MARGIN*2+NET_WIDTH)    //视图宽度
#define SCENE_HEIGHT (MARGIN*2+NET_HEIGHT)                  //视图高度

#define EDGE_PEN_WIDTH 2    //线路边宽
#define NODE_HALF_WIDTH 3   //节点大小

#endif // MAINWINDOW_H
