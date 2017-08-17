#include "ui_managelines.h"
#include "managelines.h"

#include <QPixmap>
#include <QColorDialog>
#include <QFile>
#include <QTextStream>
#include <QDebug>

ManageLines::ManageLines(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ManageLines)
{
    ui->setupUi(this);
    tabWigetsVector.push_back(ui->tabAddLine);
    tabWigetsVector.push_back(ui->tabAddStation);
    tabWigetsVector.push_back(ui->tabAddConnection);
    tabWigetsVector.push_back(ui->tabAddByText);

    tabIconVector.push_back(QIcon(QPixmap(":/icon/icon/subway.png")));
    tabIconVector.push_back(QIcon(QPixmap(":/icon/icon/station.png")));
    tabIconVector.push_back(QIcon(QPixmap(":/icon/icon/connect.png")));
    tabIconVector.push_back(QIcon(QPixmap(":/icon/icon/text.png")));

    tabTextVector.push_back("线路(&L)");
    tabTextVector.push_back("站点(&S)");
    tabTextVector.push_back("连接(&C)");
    tabTextVector.push_back("文本方式(&T)");

    QString demoText=tr("请参照以下demo（注意格式需完全一样）\n");
    demoText+=tr("- - - - - - - - - - demo.txt- - - - - - - - - - ");

    QFile file(":/data/data/demo.txt");
    if(!file.open(QIODevice::ReadOnly))
    {
        demoText=file.errorString();
    }
    else
    {
        QTextStream in(&file);
        while(!in.atEnd())
        {
            QString str=in.readLine();
            demoText+="\n";
            demoText+=str;
        }
        file.close();
        ui->textEdit->setPlaceholderText(demoText);
    }
}

ManageLines::~ManageLines()
{
    delete ui;
}

void ManageLines::setAllVisible()
{
    ui->tabWidget->clear();
    ui->tabWidget->addTab(tabWigetsVector[0],tabIconVector[0],tabTextVector[0]);
    ui->tabWidget->addTab(tabWigetsVector[1],tabIconVector[1],tabTextVector[1]);
    ui->tabWidget->addTab(tabWigetsVector[2],tabIconVector[2],tabTextVector[2]);
    ui->tabWidget->addTab(tabWigetsVector[3],tabIconVector[3],tabTextVector[3]);
}

void ManageLines::setAddLineVisible()
{
    ui->tabWidget->clear();
    ui->tabWidget->addTab(tabWigetsVector[0],tabIconVector[0],tabTextVector[0]);
}

void ManageLines::setAddStationVisible()
{
    ui->tabWidget->clear();
    ui->tabWidget->addTab(tabWigetsVector[1],tabIconVector[1],tabTextVector[1]);
}

void ManageLines::setAddConnectionVisible()
{
    ui->tabWidget->clear();
    ui->tabWidget->addTab(tabWigetsVector[2],tabIconVector[2],tabTextVector[2]);
}

void ManageLines::setAddByTextVisible()
{
    ui->tabWidget->clear();
    ui->tabWidget->addTab(tabWigetsVector[3],tabIconVector[3],tabTextVector[3]);
}

void ManageLines::on_lineEditLineName_textChanged(const QString &arg1)
{
    lineName=arg1;
    ui->textBrowserAddLine->setText(tr("线路：")+lineName+"\n"
                                    +tr("颜色：")+QString::number(lineColor.rgb()-0xff000000,16));
}

void ManageLines::on_pushButtonChooseColor_clicked()
{
    QColorDialog colorDialog;
    colorDialog.setOptions(QColorDialog::ShowAlphaChannel);
    colorDialog.exec();
    lineColor=colorDialog.currentColor();
    ui->textBrowserAddLine->setText(tr("线路：")+lineName+"\n"
                                    +tr("颜色：")+QString::number(lineColor.rgb()-0xff000000,16));
    return ;
}

void ManageLines::on_lineEditStationName_textChanged(const QString &arg1)
{
    stationName=arg1;
    ui->textBrowserAddStaiton->setText(tr("站名：")+stationName+"\n"+
                                       tr("经度：")+QString::number(longitude, 'f', 7)+"\n"+
                                       tr("纬度：")+QString::number(latitude, 'f', 7));
}

void ManageLines::on_doubleSpinBoxLatitude_valueChanged(double arg1)
{
    latitude=arg1;
    ui->textBrowserAddStaiton->setText(tr("站名：")+stationName+"\n"+
                                       tr("经度：")+QString::number(longitude, 'f', 7)+"\n"+
                                       tr("纬度：")+QString::number(latitude, 'f', 7));
}

void ManageLines::on_doubleSpinBoxLongitude_valueChanged(double arg1)
{
    longitude=arg1;
    ui->textBrowserAddStaiton->setText(tr("站名：")+stationName+"\n"+
                                       tr("经度：")+QString::number(longitude, 'f', 7)+"\n"+
                                       tr("纬度：")+QString::number(latitude, 'f', 7));
}

void ManageLines::updateLinesListWidget()
{
    QListWidget* listWidget=ui->listWidget;
    for(int i=0; i<linesNameList.size(); ++i)
    {
        QListWidgetItem *item =listWidget->takeItem(i);
        delete item;
    }
    listWidget->clear();
    linesSelected.clear();
    ui->textBrowserLinesSelected->clear();

    for(int i=0; i<linesNameList.size(); ++i)
    {
        QListWidgetItem *item=new QListWidgetItem(linesNameList[i]);
        item->setFlags(item->flags()|Qt::ItemIsUserCheckable);
        item->setCheckState(Qt::Unchecked);
        listWidget->addItem(item);
    }
}

void ManageLines::on_listWidget_itemClicked(QListWidgetItem *item)
{
    QString str;
    linesSelected.clear();

    for (int i=0; i<ui->listWidget->count(); ++i)
    {
        QListWidgetItem* item=ui->listWidget->item(i);
        if(item->checkState()==Qt::Checked)
        {
            linesSelected.push_back(item->text());
            str+=item->text();
            str+="\n";
        }
    }
    ui->textBrowserLinesSelected->setText(str);
}

void ManageLines::updateComboBox()
{
    ui->comboBoxConnectStation1->clear();
    ui->comboBoxConnectStation2->clear();
    ui->lineEditStationName->clear();

    for (auto &a: stationsNameList)
    {
        ui->comboBoxConnectStation1->addItem(a);
        ui->comboBoxConnectStation2->addItem(a);
    }
    for (auto &a: linesNameList)
    {
        ui->comboBoxConnectLine->addItem(a);
    }
}
