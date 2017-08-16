#ifndef QUERYTRANSFER_H
#define QUERYTRANSFER_H

#include <QDialog>

namespace Ui {
class QueryTransfer;
}

class QueryTransfer : public QDialog
{
    Q_OBJECT

public:
    explicit QueryTransfer(QWidget *parent = 0);
    ~QueryTransfer();

public:
    Ui::QueryTransfer *ui;
};

#endif // QUERYTRANSFER_H
