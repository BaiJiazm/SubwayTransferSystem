#ifndef SUBWAYGRAPH_H
#define SUBWAYGRAPH_H

#include "station.h"
#include "line.h"
#include <QString>
#include <QPoint>
#include <QVector>
#include <QHash>

class Node{
public:
    int stationID;
    double distance;

    Node(){};
    Node(int s, double dist) :stationID(s), distance(dist)
    {};

    bool operator > (const Node& n) const
    {
        return this->distance>n.distance;
    }
};

class SubwayGraph
{
protected:
    QVector<Station> stations;
    QVector<Line> lines;
    QHash<QString, int> stationsHash;
    QHash<QString, int> linesHash;
    QSet<Edge> edges;
    QVector<QVector<Node>> graph;

public:
    SubwayGraph();
    bool readFileData(QString fileName);

    QString getLineName(int l);
    QColor getLineColor(int l);
    int getLineHash(QString lineName);
    QList<int> getLinesHash(QList<QString> linesList);
    QList<QString> getLinesNameList();
    QList<QString> getLineStationsList(int l);

    QString getStationName(int s);
    QPointF getStationCoord(int s);
    QPointF getMinCoord();
    QPointF getMaxCoord();
    QList<int> getStationLinesInfo(int s);
    QList<int> getCommonLines(int s1, int s2);
    int getStationHash(QString stationName);
    QList<QString> getStationsNameList();

    void addLine(QString lineName, QColor color);
    void addStation(Station s);
    void addConnection(int s1, int s2, int l);
    bool insertEdge(int s1, int s2);

    void getGraph(QList<int>&stationsList, QList<Edge>&edgesList);
    bool queryTransferMinTime(int s1, int s2, QList<int>&stationsList, QList<Edge>&edgesList);
    bool queryTransferMinTransfer(int s1, int s2, QList<int>&stationsList, QList<Edge>&edgesList);

    void debug();

private:
    void clearData();
    void makeGraph();
    void updateMinMaxLongiLati();
};

#endif // SUBWAYGRAPH_H
