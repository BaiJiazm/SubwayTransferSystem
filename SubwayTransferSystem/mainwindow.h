#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "graphics_view_zoom.h"
#include "subwaygraph.h"
#include "managelines.h"
#include "querytransfer.h"

#include <QMainWindow>
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

private slots:
    void on_toolEnlarge_triggered();

    void on_toolShrink_triggered();

    void on_actionAddAll_triggered();

    void on_actionAddLine_triggered();

    void on_actionAddStation_triggered();

    void on_actionAddConnect_triggered();

    void on_actionAddByText_triggered();

    void on_actionTransfer_triggered();

    void tabWidgetCurrentChanged(int index);
    void addLine();
    void addStation();
    void addConnection();
    void addByText();
    void transferStartLineChanged(QString lineName);
    void transferDstLineChanged(QString lineNames);
    void transferQuery();

protected:
    Ui::MainWindow *ui;
    Graphics_view_zoom *myView;
    QGraphicsScene *scene;
    SubwayGraph* subwayGraph;
    ManageLines* manageLines;
    QueryTransfer* queryTransfer;

    void test();
    QColor getLinesColor(const QList<int>& linesList);
    QString getLinesName(const QList<int>& linesList);
    QPointF transferCoord(QPointF coord);
    void drawEdges (const QList<Edge>& edgesList);
    void drawStations (const QList<int>& stationsList);
    void myConnect();
};

#define LINE_INFO_WIDTH 100
#define MARGIN 30
#define NET_WIDTH 2000
#define NET_HEIGHT 2000
#define SCENE_WIDTH (LINE_INFO_WIDTH+MARGIN*2+NET_WIDTH)
#define SCENE_HEIGHT (MARGIN*2+NET_HEIGHT)

#define EDGE_PEN_WIDTH 2
#define NODE_HALF_WIDTH 3

#endif // MAINWINDOW_H
