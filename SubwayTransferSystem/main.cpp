#include "mainwindow.h"
#include <QApplication>
#include <QSplashScreen>
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QPixmap pixmap(":/icon/icon/splash.png");
    QSplashScreen splash(pixmap);//程序启动画面
    for(qint64 i=5555555;i>0;i--)
        splash.show();

    MainWindow w;
    w.show();

    splash.finish(&w);

    return a.exec();
}
