#ifndef SUBWAYGRAPH_H
#define SUBWAYGRAPH_H

#include "station.h"
#include "line.h"
#include <QString>
#include <QPoint>
#include <QVector>
#include <QHash>

//图的邻接点结构
class Node{
public:
    int stationID;      //邻接点ID
    double distance;    //两点距离

    //构造函数
    Node(){};
    Node(int s, double dist) :stationID(s), distance(dist)
    {};

    //">"运算重载，用于小顶堆
    bool operator > (const Node& n) const
    {
        return this->distance>n.distance;
    }
};

//后端管理类
class SubwayGraph
{
protected:
    QVector<Station> stations;          //存储所有站点
    QVector<Line> lines;                //存储所有线路
    QHash<QString, int> stationsHash;   //站点名到存储位置的hash
    QHash<QString, int> linesHash;      //线路名到存储位置的hash
    QSet<Edge> edges;                   //所有边的集合
    QVector<QVector<Node>> graph;       //地铁线路网络图

public:
    //构造函数
    SubwayGraph();

    //获取线路名
    QString getLineName(int l);
    //获取线路颜色
    QColor getLineColor(int l);
    //获取线路hash值
    int getLineHash(QString lineName);
    //获取线路集合hash值
    QList<int> getLinesHash(QList<QString> linesList);
    //获取线路名集合
    QList<QString> getLinesNameList();
    //获取线路的所有包含站点
    QList<QString> getLineStationsList(int l);

    //获取站点名
    QString getStationName(int s);
    //获取站点地理坐标
    QPointF getStationCoord(int s);
    //获取站点最小坐标
    QPointF getMinCoord();
    //获取站点最大坐标
    QPointF getMaxCoord();
    //获取站点所属线路信息
    QList<int> getStationLinesInfo(int s);
    //获取两个站点的公共所属线路
    QList<int> getCommonLines(int s1, int s2);
    //获取站点hash值
    int getStationHash(QString stationName);
    //获取站点集合hash值
    QList<QString> getStationsNameList();

    //添加新线路
    void addLine(QString lineName, QColor color);
    //添加新站点
    void addStation(Station s);
    //添加站点连接关系
    void addConnection(int s1, int s2, int l);

    //获取网络结构，用于前端显示
    void getGraph(QList<int>&stationsList, QList<Edge>&edgesList);
    //获取最少时间的线路
    bool queryTransferMinTime(int s1, int s2,
                              QList<int>&stationsList,
                              QList<Edge>&edgesList);
    //获取最少换乘的线路
    bool queryTransferMinTransfer(int s1, int s2,
                                  QList<int>&stationsList,
                                  QList<Edge>&edgesList);
    //从文件读取数据
    bool readFileData(QString fileName);

private:
    //清空数据
    void clearData();
    //插入一条边
    bool insertEdge(int s1, int s2);
    //更新边界经纬度
    void updateMinMaxLongiLati();
    //生成图结构
    void makeGraph();
};

#endif // SUBWAYGRAPH_H
