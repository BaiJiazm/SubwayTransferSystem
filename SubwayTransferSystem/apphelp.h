#ifndef APPHELP_H
#define APPHELP_H

#include <QWidget>
#include <QPushButton>
#include <QTextBrowser>
#include <QStackedWidget>
#include <QListWidget>

class AppHelp : public QWidget
{
    Q_OBJECT
public:
    //构造函数
    explicit AppHelp(QWidget *parent = 0);
    //创建UI
    void createHelpUI();

private slots:
    //当前列表项变化
    void listWidgetChanged(QListWidgetItem*);

private:
    QListWidget *listWidget;
    QTextBrowser *textBrowser;
};

#endif // APPHELP_H
