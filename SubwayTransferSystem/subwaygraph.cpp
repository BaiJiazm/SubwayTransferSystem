#include "subwaygraph.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>

SubwayGraph::SubwayGraph()
{

}

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
        QChar qch;
        double d1=0, d2=0;
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
    updateMinMaxLongiLati();
    makeGraph();
    return true;
}

void SubwayGraph::clearData()
{
    stations.clear();
    lines.clear();
    stationsHash.clear();
    linesHash.clear();
    edges.clear();
    graph.clear();
}

void SubwayGraph::makeGraph()
{
    graph=QVector<QVector<Node>>(stations.size(), QVector<Node>());
    for (auto &a : edges)
    {
        graph[a.first].push_back(Node(a.second, stations[a.first].distance(stations[a.second])));
    }
}

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

QPointF SubwayGraph::getMinCoord()
{
    return QPointF(Station::minLongitude, Station::minLatitude);
}

QPointF SubwayGraph::getMaxCoord()
{
    return QPointF(Station::maxLongitude, Station::maxLatitude);
}

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

bool SubwayGraph::insertEdge(int n1, int n2)
{
    if (edges.contains(Edge(n1, n2)) || edges.contains(Edge(n2, n1)))
    {
        return false;
    }
    edges.insert(Edge(n1, n2));
    return true;
}

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

QColor SubwayGraph::getLineColor(int l)
{
    return lines[l].color;
}

QString SubwayGraph::getLineName(int l)
{
    return lines[l].name;
}

void SubwayGraph::debug()
{
    for (int i=0; i<stations.size(); ++i)
    {
        qDebug()<<stations[i].name<<" lon="<<stations[i].longitude<<" lat="<<stations[i].latitude<<" \n";
    }
}

QString SubwayGraph::getStationName(int s)
{
    return stations[s].name;
}

QPointF SubwayGraph::getStationCoord(int s)
{
    return QPointF(stations[s].longitude, stations[s].latitude);
}

QList<int> SubwayGraph::getStationLinesInfo(int s)
{
    return stations[s].linesInfo.toList();
}
