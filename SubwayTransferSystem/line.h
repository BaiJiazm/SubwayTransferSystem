#ifndef LINE_H
#define LINE_H

#include <QString>
#include <QColor>
#include <QPair>
#include <QSet>
#include <QVector>

typedef QPair<int,int> Edge;

class SubwayGraph;
class QTextStream;

class Line
{
protected:
    int id;
    QString name;
    QColor color;
    QVector <QString> fromTo;
    QSet<int> stationsSet;
    QSet<Edge> edges;

public:
    Line();

    friend class SubwayGraph;
    friend class QTextStream;
};

#endif // LINE_H
