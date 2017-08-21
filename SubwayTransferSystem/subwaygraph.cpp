#include "subwaygraph.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <queue>

//构造函数
SubwayGraph::SubwayGraph()
{

}

//从文件读取数据
bool SubwayGraph::readFileData(QString fileName)
{
    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly))
        return false;
    QTextStream in(&file);
    while(!in.atEnd())
    {
        Line line;
        QString id, name, colour, fromTo, totalStations;
        QString color, froms, tos;
        bool ok;
        int total;
        Station station;
        int lvIndex, svIndex1, svIndex2;

        in>>id>>line.id;
        in>>name>>line.name;
        in>>colour>>color;
        line.color.setRgba(color.remove(0,1).toUInt(&ok, 16));
        in>>fromTo>>froms>>tos;
        in>>totalStations>>total;

        line.fromTo.push_back(froms);
        line.fromTo.push_back(tos);
        if (linesHash.count(line.name))
        {
            lvIndex = linesHash[line.name];
            lines[lvIndex].fromTo.push_back(froms);
            lines[lvIndex].fromTo.push_back(tos);
        }
        else
        {
            lvIndex = linesHash[line.name] = lines.size();
            lines.push_back(line);
        }

        QString longlat;
        QStringList strList;
        for (int i=0; !in.atEnd()&&i<total; ++i)
        {
            in>>station.id>>station.name>>longlat;
            strList=longlat.split(QChar(','));
            station.longitude=strList.first().toDouble();
            station.latitude=strList.last().toDouble();

//            qDebug()<<station.longitude<<" "<<station.latitude<<"\n";
//            d1=station.longitude;
//            if(fabs(d1-d2)<1e-8)
//            {
//                qDebug()<<line.name<<" "<<station.id<<" "<<station.name<<"经度数据有误"<<"\n";
//            }
//            d2=d1;

            if (stationsHash.count(station.name))
            {
                svIndex2 = stationsHash[station.name];
            }
            else
            {
                svIndex2 = stationsHash[station.name] = stations.size();
                stations.push_back(station);
            }

            stations[svIndex2].linesInfo.insert(lvIndex);
            lines[lvIndex].stationsSet.insert(svIndex2);

            if (i)
            {
                lines[lvIndex].edges.insert(Edge(svIndex1, svIndex2));
                lines[lvIndex].edges.insert(Edge(svIndex2, svIndex1));
                insertEdge(svIndex1, svIndex2);
            }
            svIndex1 = svIndex2;
        }

        bool flag = id=="id:" && name=="name:" && colour=="colour:" && fromTo=="fromTo:"
                && totalStations=="totalStations:" && ok && !in.atEnd();

//        qDebug()<< "ok="<<ok<<" flag="<<flag<<line.id<< " "<<station.name<< "\n";

        if(flag==false)
        {
            file.close();
            clearData();
            return false ;
        }
        in.readLine();
    }
    file.close();

    updateMinMaxLongiLati();

    return true;
}

//清空数据
void SubwayGraph::clearData()
{
    stations.clear();
    lines.clear();
    stationsHash.clear();
    linesHash.clear();
    edges.clear();
    graph.clear();
}

//插入一条边
bool SubwayGraph::insertEdge(int n1, int n2)
{
    if (edges.contains(Edge(n1, n2)) || edges.contains(Edge(n2, n1)))
    {
        return false;
    }
    edges.insert(Edge(n1, n2));
    return true;
}

//生成图结构
void SubwayGraph::makeGraph()
{
    graph.clear();
    graph=QVector<QVector<Node>>(stations.size(), QVector<Node>());
    for (auto &a : edges)
    {
        double dist=stations[a.first].distance(stations[a.second]);
        graph[a.first].push_back(Node(a.second, dist));
        graph[a.second].push_back(Node(a.first, dist));
    }
}


//获取线路颜色
QColor SubwayGraph::getLineColor(int l)
{
    return lines[l].color;
}

//获取线路名
QString SubwayGraph::getLineName(int l)
{
    return lines[l].name;
}

//获取线路hash值
int SubwayGraph::getLineHash(QString lineName)
{
    if(linesHash.contains(lineName))
    {
        return linesHash[lineName];
    }
    return -1;
}

//获取线路集合hash值
QList<int> SubwayGraph::getLinesHash(QList<QString> linesList)
{
    QList<int> hashList;
    for (auto &a:linesList)
    {
        hashList.push_back(getLineHash(a));
    }
    return hashList;
}

//获取线路名集合
QList<QString> SubwayGraph::getLinesNameList()
{
    QList<QString> linesNameList;
    for (auto a:lines)
    {
        linesNameList.push_back(a.name);
    }
    return linesNameList;
}

//获取线路的所有包含站点
QList<QString> SubwayGraph::getLineStationsList(int l)
{
    QList<QString> stationsList;
    for (auto &a:lines[l].stationsSet)
    {
        stationsList.push_back(stations[a].name);
    }
    return stationsList;
}



//更新边界经纬度
void SubwayGraph::updateMinMaxLongiLati()
{
    double minLongitude=200, minLatitude=200;
    double maxLongitude=0, maxLatitude=0;

    for (auto &s : stations)
    {
        minLongitude = qMin(minLongitude, s.longitude);
        minLatitude = qMin(minLatitude, s.latitude);
        maxLongitude = qMax(maxLongitude, s.longitude);
        maxLatitude = qMax(maxLatitude, s.latitude);
    }
    Station::minLongitude = minLongitude;
    Station::minLatitude = minLatitude;
    Station::maxLongitude = maxLongitude;
    Station::maxLatitude = maxLatitude;

//    qDebug("minLon=%.10lf, minLat=%.10lf\n", minLongitude, minLatitude);
//    qDebug("maxLon=%.10lf, maxLat=%.10lf\n", maxLongitude, maxLatitude);
}

 //获取站点最小坐标
QPointF SubwayGraph::getMinCoord()
{
    return QPointF(Station::minLongitude, Station::minLatitude);
}

//获取站点最大坐标
QPointF SubwayGraph::getMaxCoord()
{
    return QPointF(Station::maxLongitude, Station::maxLatitude);
}

//获取两个站点的公共所属线路
QList<int> SubwayGraph::getCommonLines(int s1, int s2)
{
    QList<int> linesList;
    for (auto &s : stations[s1].linesInfo)
    {
        if(stations[s2].linesInfo.contains(s))
            linesList.push_back(s);
    }
    return linesList;
}

//获取站点名
QString SubwayGraph::getStationName(int s)
{
    return stations[s].name;
}

//获取站点地理坐标
QPointF SubwayGraph::getStationCoord(int s)
{
    return QPointF(stations[s].longitude, stations[s].latitude);
}

//获取站点所属线路信息
QList<int> SubwayGraph::getStationLinesInfo(int s)
{
    return stations[s].linesInfo.toList();
}

//获取站点hash值
int SubwayGraph::getStationHash(QString stationName)
{
    if(stationsHash.contains(stationName))
    {
        return stationsHash[stationName];
    }
    return -1;
}

//获取站点集合hash值
QList<QString> SubwayGraph::getStationsNameList()
{
    QList<QString> list;
    for (auto &a: stations)
    {
        list.push_back(a.name);
    }
    return list;
}



//添加新线路
void SubwayGraph::addLine(QString lineName, QColor color)
{
    linesHash[lineName]=lines.size();
    lines.push_back(Line(lineName,color));
}

//添加新站点
void SubwayGraph::addStation(Station s)
{
    int hash=stations.size();
    stationsHash[s.name]=hash;
    stations.push_back(s);
    for (auto &a: s.linesInfo)
    {
        lines[a].stationsSet.insert(hash);
    }
    updateMinMaxLongiLati();
}

//添加站点连接关系
void SubwayGraph::addConnection(int s1, int s2, int l)
{
    insertEdge(s1,s2);
    lines[l].edges.insert(Edge(s1,s2));
    lines[l].edges.insert(Edge(s2,s1));
}



//获取网络结构，用于前端显示
void SubwayGraph::getGraph(QList<int>&stationsList, QList<Edge>&edgesList)
{
    stationsList.clear();
    for (int i=0; i<stations.size(); ++i)
    {
        stationsList.push_back(i);
    }
    edgesList=edges.toList();
    return ;
}

//获取最少时间的线路
bool SubwayGraph::queryTransferMinTime(int s1, int s2, QList<int>&stationsList, QList<Edge>&edgesList)
{
#define INF 999999999
    stationsList.clear();
    edgesList.clear();

    if(s1==s2)
    {
        stationsList.push_back(s2);
        stationsList.push_back(s1);
        return true;
    }
    makeGraph();

    std::vector<int> path(stations.size(), -1);
    std::vector<double> dist(stations.size(), INF);
    dist[s1]=0;
    std::priority_queue<Node, std::vector<Node>, std::greater<Node>> priQ;
    priQ.push(Node(s1, 0));
    while(!priQ.empty())
    {
        Node top=priQ.top();
        priQ.pop();
        if(top.stationID==s2)
        {
            break ;
        }

        for (int i=0; i<graph[top.stationID].size(); ++i)
        {
            Node &adjNode=graph[top.stationID][i];
            if(top.distance+adjNode.distance<dist[adjNode.stationID])
            {
                path[adjNode.stationID]=top.stationID;
                dist[adjNode.stationID]=top.distance+adjNode.distance;
                priQ.push(Node(adjNode.stationID, dist[adjNode.stationID]));
            }
        }
    }

    if(path[s2]==-1)
    {
        return false;
    }
    int p=s2;
    while(path[p]!=-1)
    {
        stationsList.push_front(p);
        edgesList.push_front(Edge(path[p],p));
        p=path[p];
    }
    stationsList.push_front(s1);

//    qDebug()<<"s1="<<s1<<" s2="<<s2<<" size= "<<stationsList.size()<<" "<<edgesList.size()<<"\n";
    return true;
}

//获取最少换乘的线路
bool SubwayGraph::queryTransferMinTransfer(int s1, int s2, QList<int>&stationsList, QList<Edge>&edgesList)
{
    stationsList.clear();
    edgesList.clear();

    if(s1==s2)
    {
        stationsList.push_back(s2);
        stationsList.push_back(s1);
        return true;
    }

    std::vector<bool> linesVisted(lines.size(),false);
    std::vector<int> path(stations.size(),-1);
    path[s1]=-2;
    std::queue<int> que;
    que.push(s1);

    while(!que.empty())
    {
        int top=que.front();
        que.pop();
        for (auto &l: stations[top].linesInfo)
        {
            if(!linesVisted[l])
            {
                linesVisted[l]=true;
                for (auto &s: lines[l].stationsSet)
                {
                    if(path[s]==-1)
                    {
                        path[s]=top;
                        que.push(s);
                    }
                }
            }
        }
    }

    if(path[s2]==-1)
    {
        return false;
    }
    int p=s2;
    while(path[p]!=-2)
    {
        stationsList.push_front(p);
        edgesList.push_front(Edge(path[p],p));
        p=path[p];
    }
    stationsList.push_front(s1);
    return true;
}
