#ifndef STATION_H
#define STATION_H

#include <QString>
#include <QPointF>
#include <QSet>

class SubwayGraph;
class QTextStream;

class Station
{
protected:
    int id;
    QString name;
    double longitude, latitude;
    QSet<int> linesInfo;

    static double minLongitude, minLatitude, maxLongitude, maxLatitude;

public:
    Station();

protected:
    int distance(Station other);

    friend class SubwayGraph;
    friend class QTextStream;
};

#endif // STATION_H
