#include "querytransfer.h"
#include "ui_querytransfer.h"

QueryTransfer::QueryTransfer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QueryTransfer)
{
    ui->setupUi(this);
}

QueryTransfer::~QueryTransfer()
{
    delete ui;
}
