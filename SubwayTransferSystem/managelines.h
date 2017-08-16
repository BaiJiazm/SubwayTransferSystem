#ifndef MANAGELINES_H
#define MANAGELINES_H

#include <QDialog>
#include <QVector>
#include <QTabWidget>
#include <QListWidget>
#include <QListWidgetItem>
#include <QIcon>
#include <QString>

class MainWindow;

namespace Ui {
class ManageLines;
}

class ManageLines : public QDialog
{
    Q_OBJECT

public:
    explicit ManageLines(QWidget *parent = 0);
    ~ManageLines();
    void setAllVisible();
    void setAddLineVisible();
    void setAddStationVisible();
    void setAddConnectionVisible();
    void setAddByTextVisible();

    void updateLinesListWidget();
    void updateComboBox();

    Ui::ManageLines *ui;
    QVector<QWidget*> tabWigetsVector;
    QVector<QIcon> tabIconVector;
    QVector<QString> tabTextVector;

    QString lineName;
    QColor lineColor;
    QString stationName;
    double longitude;
    double latitude;
    QList<QString> linesNameList;
    QList<QString> linesSelected;
    QList<QString> stationsNameList;

    friend class MainWindow;

private slots:
    void on_lineEditLineName_textChanged(const QString &arg1);
    void on_pushButtonChooseColor_clicked();
    void on_lineEditStationName_textChanged(const QString &arg1);
    void on_doubleSpinBoxLatitude_valueChanged(double arg1);
    void on_doubleSpinBoxLongitude_valueChanged(double arg1);
    void on_listWidget_itemClicked(QListWidgetItem *item);
};

#endif // MANAGELINES_H
