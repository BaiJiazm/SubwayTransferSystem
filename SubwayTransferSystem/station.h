#ifndef STATION_H
#define STATION_H

#include <QString>
#include <QPointF>
#include <QSet>

class SubwayGraph;
class QTextStream;

//地铁站点类定义
class Station
{
protected:
    int id;                     //站点ID
    QString name;               //站点名称
    double longitude, latitude; //站点经纬度
    QSet<int> linesInfo;        //站点所属线路

    //所有站点的边界位置
    static double minLongitude, minLatitude, maxLongitude, maxLatitude;

public:
    //构造函数
    Station();
    Station(QString nameStr, double longi, double lati, QList<int> linesList);

protected:
    //求取站点间实地直线距离
    int distance(Station other);

    //声明友元
    friend class SubwayGraph;
    friend class QTextStream;
};

#endif // STATION_H
