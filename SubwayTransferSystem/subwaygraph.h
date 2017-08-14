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
    void getGraph(QList<int>&stationsList, QList<Edge>&edgesList);
    bool insertEdge(int n1, int n2);
    QList<int> getCommonLines(int s1, int s2);
    QColor getLineColor(int l);
    QString getLineName(int l);

    QPointF getMinCoord();
    QPointF getMaxCoord();

    QString getStationName(int s);
    QPointF getStationCoord(int s);
    QList<int> getStationLinesInfo(int s);

    void debug();

private:
    void clearData();
    void makeGraph();
    void updateMinMaxLongiLati();
};

#endif // SUBWAYGRAPH_H
