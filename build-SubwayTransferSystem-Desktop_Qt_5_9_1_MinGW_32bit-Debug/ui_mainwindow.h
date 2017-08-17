/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *toolEnlarge;
    QAction *toolShrink;
    QAction *actionTransfer;
    QAction *actionQueryInfo;
    QAction *actionAddAll;
    QAction *actionAddLine;
    QAction *actionAddStation;
    QAction *actionAddConnect;
    QAction *actionAddByText;
    QAction *actiontoolBar;
    QAction *actionstatusBar;
    QAction *actionLineMap;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QGraphicsView *graphicsView;
    QVBoxLayout *verticalLayout_2;
    QLabel *labelAdd;
    QLabel *labelTransferRoute_2;
    QSpacerItem *verticalSpacer;
    QLabel *labelTransfer;
    QHBoxLayout *horizontalLayout4;
    QLabel *labelStart;
    QComboBox *comboBoxStartLine;
    QComboBox *comboBoxStartStation;
    QHBoxLayout *horizontalLayout5;
    QLabel *labelDestination;
    QComboBox *comboBoxDstLine;
    QComboBox *comboBoxDstStation;
    QHBoxLayout *horizontalLayout6;
    QPushButton *pushButtonTransfer;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QRadioButton *radioButtonMinTransfer;
    QRadioButton *radioButtonMinTime;
    QLabel *labelTransferRoute;
    QTextBrowser *textBrowserRoute;
    QMenuBar *menuBar;
    QMenu *menuHelp;
    QMenu *menu;
    QMenu *menuTool;
    QMenu *menuAdd;
    QMenu *menuWatch;
    QMenu *menuView;
    QMenu *menu_H;
    QMenu *menu_A;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(1030, 699);
        MainWindow->setMinimumSize(QSize(1030, 695));
        MainWindow->setIconSize(QSize(24, 24));
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionOpen->setCheckable(true);
        toolEnlarge = new QAction(MainWindow);
        toolEnlarge->setObjectName(QStringLiteral("toolEnlarge"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icon/icon/enlarge.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolEnlarge->setIcon(icon);
        toolShrink = new QAction(MainWindow);
        toolShrink->setObjectName(QStringLiteral("toolShrink"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icon/icon/shrink.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolShrink->setIcon(icon1);
        actionTransfer = new QAction(MainWindow);
        actionTransfer->setObjectName(QStringLiteral("actionTransfer"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/icon/icon/query.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionTransfer->setIcon(icon2);
        actionQueryInfo = new QAction(MainWindow);
        actionQueryInfo->setObjectName(QStringLiteral("actionQueryInfo"));
        actionAddAll = new QAction(MainWindow);
        actionAddAll->setObjectName(QStringLiteral("actionAddAll"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/icon/icon/all.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAddAll->setIcon(icon3);
        actionAddLine = new QAction(MainWindow);
        actionAddLine->setObjectName(QStringLiteral("actionAddLine"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/icon/icon/subway.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAddLine->setIcon(icon4);
        actionAddStation = new QAction(MainWindow);
        actionAddStation->setObjectName(QStringLiteral("actionAddStation"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/icon/icon/station.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAddStation->setIcon(icon5);
        actionAddConnect = new QAction(MainWindow);
        actionAddConnect->setObjectName(QStringLiteral("actionAddConnect"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/icon/icon/connect.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAddConnect->setIcon(icon6);
        actionAddByText = new QAction(MainWindow);
        actionAddByText->setObjectName(QStringLiteral("actionAddByText"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/icon/icon/text.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAddByText->setIcon(icon7);
        actiontoolBar = new QAction(MainWindow);
        actiontoolBar->setObjectName(QStringLiteral("actiontoolBar"));
        actionstatusBar = new QAction(MainWindow);
        actionstatusBar->setObjectName(QStringLiteral("actionstatusBar"));
        actionLineMap = new QAction(MainWindow);
        actionLineMap->setObjectName(QStringLiteral("actionLineMap"));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/icon/icon/map.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionLineMap->setIcon(icon8);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setMinimumSize(QSize(1030, 620));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(10);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(10, 0, 10, 0);
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setMinimumSize(QSize(700, 600));

        horizontalLayout->addWidget(graphicsView);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        labelAdd = new QLabel(centralWidget);
        labelAdd->setObjectName(QStringLiteral("labelAdd"));
        labelAdd->setMinimumSize(QSize(280, 30));
        QFont font;
        font.setFamily(QStringLiteral("Consolas"));
        font.setPointSize(11);
        font.setBold(true);
        font.setItalic(false);
        font.setWeight(75);
        labelAdd->setFont(font);
        labelAdd->setTextFormat(Qt::AutoText);

        verticalLayout_2->addWidget(labelAdd);

        labelTransferRoute_2 = new QLabel(centralWidget);
        labelTransferRoute_2->setObjectName(QStringLiteral("labelTransferRoute_2"));
        labelTransferRoute_2->setMinimumSize(QSize(280, 20));
        QFont font1;
        font1.setFamily(QStringLiteral("Consolas"));
        font1.setPointSize(9);
        font1.setBold(false);
        font1.setWeight(50);
        labelTransferRoute_2->setFont(font1);

        verticalLayout_2->addWidget(labelTransferRoute_2);

        verticalSpacer = new QSpacerItem(20, 50, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        labelTransfer = new QLabel(centralWidget);
        labelTransfer->setObjectName(QStringLiteral("labelTransfer"));
        labelTransfer->setMinimumSize(QSize(280, 30));
        QFont font2;
        font2.setFamily(QStringLiteral("Consolas"));
        font2.setPointSize(11);
        font2.setBold(true);
        font2.setWeight(75);
        labelTransfer->setFont(font2);

        verticalLayout_2->addWidget(labelTransfer);

        horizontalLayout4 = new QHBoxLayout();
        horizontalLayout4->setSpacing(10);
        horizontalLayout4->setObjectName(QStringLiteral("horizontalLayout4"));
        labelStart = new QLabel(centralWidget);
        labelStart->setObjectName(QStringLiteral("labelStart"));
        labelStart->setMinimumSize(QSize(70, 20));
        QFont font3;
        font3.setFamily(QStringLiteral("Consolas"));
        labelStart->setFont(font3);

        horizontalLayout4->addWidget(labelStart);

        comboBoxStartLine = new QComboBox(centralWidget);
        comboBoxStartLine->setObjectName(QStringLiteral("comboBoxStartLine"));
        comboBoxStartLine->setMinimumSize(QSize(90, 20));
        comboBoxStartLine->setFont(font3);

        horizontalLayout4->addWidget(comboBoxStartLine);

        comboBoxStartStation = new QComboBox(centralWidget);
        comboBoxStartStation->setObjectName(QStringLiteral("comboBoxStartStation"));
        comboBoxStartStation->setMinimumSize(QSize(90, 20));
        comboBoxStartStation->setFont(font3);

        horizontalLayout4->addWidget(comboBoxStartStation);

        horizontalLayout4->setStretch(0, 7);
        horizontalLayout4->setStretch(1, 9);
        horizontalLayout4->setStretch(2, 9);

        verticalLayout_2->addLayout(horizontalLayout4);

        horizontalLayout5 = new QHBoxLayout();
        horizontalLayout5->setSpacing(10);
        horizontalLayout5->setObjectName(QStringLiteral("horizontalLayout5"));
        labelDestination = new QLabel(centralWidget);
        labelDestination->setObjectName(QStringLiteral("labelDestination"));
        labelDestination->setMinimumSize(QSize(70, 20));
        labelDestination->setFont(font3);

        horizontalLayout5->addWidget(labelDestination);

        comboBoxDstLine = new QComboBox(centralWidget);
        comboBoxDstLine->setObjectName(QStringLiteral("comboBoxDstLine"));
        comboBoxDstLine->setMinimumSize(QSize(90, 20));
        comboBoxDstLine->setFont(font3);

        horizontalLayout5->addWidget(comboBoxDstLine);

        comboBoxDstStation = new QComboBox(centralWidget);
        comboBoxDstStation->setObjectName(QStringLiteral("comboBoxDstStation"));
        comboBoxDstStation->setMinimumSize(QSize(90, 20));
        comboBoxDstStation->setFont(font3);

        horizontalLayout5->addWidget(comboBoxDstStation);

        horizontalLayout5->setStretch(0, 7);
        horizontalLayout5->setStretch(1, 9);
        horizontalLayout5->setStretch(2, 9);

        verticalLayout_2->addLayout(horizontalLayout5);

        horizontalLayout6 = new QHBoxLayout();
        horizontalLayout6->setSpacing(10);
        horizontalLayout6->setObjectName(QStringLiteral("horizontalLayout6"));
        pushButtonTransfer = new QPushButton(centralWidget);
        pushButtonTransfer->setObjectName(QStringLiteral("pushButtonTransfer"));
        pushButtonTransfer->setMinimumSize(QSize(70, 30));
        pushButtonTransfer->setFont(font3);

        horizontalLayout6->addWidget(pushButtonTransfer);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMinimumSize(QSize(190, 30));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        radioButtonMinTransfer = new QRadioButton(groupBox);
        radioButtonMinTransfer->setObjectName(QStringLiteral("radioButtonMinTransfer"));
        radioButtonMinTransfer->setMinimumSize(QSize(100, 15));
        radioButtonMinTransfer->setFont(font3);

        verticalLayout->addWidget(radioButtonMinTransfer);

        radioButtonMinTime = new QRadioButton(groupBox);
        radioButtonMinTime->setObjectName(QStringLiteral("radioButtonMinTime"));
        radioButtonMinTime->setMinimumSize(QSize(100, 15));
        radioButtonMinTime->setFont(font3);
        radioButtonMinTime->setChecked(true);

        verticalLayout->addWidget(radioButtonMinTime);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 1);

        horizontalLayout6->addWidget(groupBox);

        horizontalLayout6->setStretch(0, 7);
        horizontalLayout6->setStretch(1, 19);

        verticalLayout_2->addLayout(horizontalLayout6);

        labelTransferRoute = new QLabel(centralWidget);
        labelTransferRoute->setObjectName(QStringLiteral("labelTransferRoute"));
        labelTransferRoute->setMinimumSize(QSize(280, 20));
        QFont font4;
        font4.setFamily(QStringLiteral("Consolas"));
        font4.setPointSize(10);
        font4.setBold(true);
        font4.setWeight(75);
        labelTransferRoute->setFont(font4);

        verticalLayout_2->addWidget(labelTransferRoute);

        textBrowserRoute = new QTextBrowser(centralWidget);
        textBrowserRoute->setObjectName(QStringLiteral("textBrowserRoute"));
        textBrowserRoute->setMinimumSize(QSize(300, 320));
        textBrowserRoute->setFont(font3);

        verticalLayout_2->addWidget(textBrowserRoute);

        verticalLayout_2->setStretch(0, 3);
        verticalLayout_2->setStretch(1, 2);
        verticalLayout_2->setStretch(2, 3);
        verticalLayout_2->setStretch(3, 3);
        verticalLayout_2->setStretch(4, 2);
        verticalLayout_2->setStretch(5, 2);
        verticalLayout_2->setStretch(6, 5);
        verticalLayout_2->setStretch(7, 2);
        verticalLayout_2->setStretch(8, 32);

        horizontalLayout->addLayout(verticalLayout_2);

        horizontalLayout->setStretch(0, 11);
        horizontalLayout->setStretch(1, 3);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1030, 25));
        menuBar->setMinimumSize(QSize(0, 25));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        menu = new QMenu(menuHelp);
        menu->setObjectName(QStringLiteral("menu"));
        menuTool = new QMenu(menuBar);
        menuTool->setObjectName(QStringLiteral("menuTool"));
        menuAdd = new QMenu(menuTool);
        menuAdd->setObjectName(QStringLiteral("menuAdd"));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/icon/icon/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        menuAdd->setIcon(icon9);
        menuWatch = new QMenu(menuBar);
        menuWatch->setObjectName(QStringLiteral("menuWatch"));
        menuView = new QMenu(menuBar);
        menuView->setObjectName(QStringLiteral("menuView"));
        menu_H = new QMenu(menuBar);
        menu_H->setObjectName(QStringLiteral("menu_H"));
        menu_A = new QMenu(menuBar);
        menu_A->setObjectName(QStringLiteral("menu_A"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setMinimumSize(QSize(0, 0));
        mainToolBar->setIconSize(QSize(24, 24));
        mainToolBar->setToolButtonStyle(Qt::ToolButtonIconOnly);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        statusBar->setMinimumSize(QSize(0, 15));
        MainWindow->setStatusBar(statusBar);
#ifndef QT_NO_SHORTCUT
        labelStart->setBuddy(comboBoxStartLine);
        labelDestination->setBuddy(comboBoxDstLine);
#endif // QT_NO_SHORTCUT

        menuBar->addAction(menuHelp->menuAction());
        menuBar->addAction(menuTool->menuAction());
        menuBar->addAction(menuView->menuAction());
        menuBar->addAction(menuWatch->menuAction());
        menuBar->addAction(menu_H->menuAction());
        menuBar->addAction(menu_A->menuAction());
        menuHelp->addAction(actionOpen);
        menuHelp->addAction(menu->menuAction());
        menuTool->addAction(actionTransfer);
        menuTool->addAction(menuAdd->menuAction());
        menuTool->addSeparator();
        menuTool->addAction(actionQueryInfo);
        menuAdd->addAction(actionAddAll);
        menuAdd->addSeparator();
        menuAdd->addAction(actionAddLine);
        menuAdd->addAction(actionAddStation);
        menuAdd->addAction(actionAddConnect);
        menuAdd->addSeparator();
        menuAdd->addAction(actionAddByText);
        menuWatch->addAction(actiontoolBar);
        menuWatch->addAction(actionstatusBar);
        menuView->addAction(toolEnlarge);
        menuView->addAction(toolShrink);
        menuView->addAction(actionLineMap);
        mainToolBar->addSeparator();
        mainToolBar->addAction(toolEnlarge);
        mainToolBar->addAction(toolShrink);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionAddAll);
        mainToolBar->addAction(actionAddLine);
        mainToolBar->addAction(actionAddStation);
        mainToolBar->addAction(actionAddConnect);
        mainToolBar->addAction(actionAddByText);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionTransfer);
        mainToolBar->addAction(actionLineMap);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionOpen->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionOpen->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        toolEnlarge->setText(QApplication::translate("MainWindow", "\346\224\276\345\244\247", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        toolEnlarge->setToolTip(QApplication::translate("MainWindow", "\347\202\271\345\207\273\346\224\276\345\244\247", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        toolEnlarge->setShortcut(QApplication::translate("MainWindow", "Ctrl+L", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        toolShrink->setText(QApplication::translate("MainWindow", "\347\274\251\345\260\217", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        toolShrink->setToolTip(QApplication::translate("MainWindow", "\347\202\271\345\207\273\347\274\251\345\260\217", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        toolShrink->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionTransfer->setText(QApplication::translate("MainWindow", "\346\215\242\344\271\230\346\214\207\345\215\227", Q_NULLPTR));
        actionQueryInfo->setText(QApplication::translate("MainWindow", "\344\277\241\346\201\257\346\237\245\350\257\242", Q_NULLPTR));
        actionAddAll->setText(QApplication::translate("MainWindow", "\346\211\200\346\234\211(&A)", Q_NULLPTR));
        actionAddLine->setText(QApplication::translate("MainWindow", "\347\272\277\350\267\257(&L)", Q_NULLPTR));
        actionAddStation->setText(QApplication::translate("MainWindow", "\347\253\231\347\202\271(&S)", Q_NULLPTR));
        actionAddConnect->setText(QApplication::translate("MainWindow", "\350\277\236\346\216\245(&C)", Q_NULLPTR));
        actionAddByText->setText(QApplication::translate("MainWindow", "\346\226\207\346\234\254\346\226\271\345\274\217(&T)", Q_NULLPTR));
        actiontoolBar->setText(QApplication::translate("MainWindow", "toolBar", Q_NULLPTR));
        actionstatusBar->setText(QApplication::translate("MainWindow", "statusBar", Q_NULLPTR));
        actionLineMap->setText(QApplication::translate("MainWindow", "\347\272\277\350\267\257\345\233\276", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionLineMap->setToolTip(QApplication::translate("MainWindow", "\347\202\271\345\207\273\346\237\245\347\234\213\346\211\200\346\234\211\345\234\260\351\223\201\347\275\221\347\273\234\347\272\277\350\267\257\345\233\276", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        labelAdd->setText(QApplication::translate("MainWindow", "\345\212\250\346\200\201\346\267\273\345\212\240", Q_NULLPTR));
        labelTransferRoute_2->setText(QApplication::translate("MainWindow", "\357\274\210\350\257\267\344\273\216\345\267\245\345\205\267\346\240\217\344\270\255\351\200\211\346\213\251\357\274\211", Q_NULLPTR));
        labelTransfer->setText(QApplication::translate("MainWindow", "\346\215\242\344\271\230\346\214\207\345\215\227", Q_NULLPTR));
        labelStart->setText(QApplication::translate("MainWindow", "\350\265\267\347\202\271\347\253\231(&S)\357\274\232", Q_NULLPTR));
        comboBoxStartLine->clear();
        comboBoxStartLine->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\351\200\211\346\213\251\350\267\257\347\272\277", Q_NULLPTR)
        );
        comboBoxStartStation->clear();
        comboBoxStartStation->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\351\200\211\346\213\251\347\253\231\347\202\271", Q_NULLPTR)
        );
        labelDestination->setText(QApplication::translate("MainWindow", "\347\273\210\347\202\271\347\253\231(&D)\357\274\232", Q_NULLPTR));
        comboBoxDstLine->clear();
        comboBoxDstLine->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\351\200\211\346\213\251\350\267\257\347\272\277", Q_NULLPTR)
        );
        comboBoxDstStation->clear();
        comboBoxDstStation->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\351\200\211\346\213\251\347\253\231\347\202\271", Q_NULLPTR)
        );
        pushButtonTransfer->setText(QApplication::translate("MainWindow", "\346\215\242\344\271\230", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "\346\215\242\344\271\230\347\255\226\347\225\245", Q_NULLPTR));
        radioButtonMinTransfer->setText(QApplication::translate("MainWindow", "\346\215\242\344\271\230\346\254\241\346\225\260\346\234\200\345\260\221", Q_NULLPTR));
        radioButtonMinTime->setText(QApplication::translate("MainWindow", "\346\211\200\351\234\200\346\227\266\351\227\264\346\234\200\347\237\255", Q_NULLPTR));
        labelTransferRoute->setText(QApplication::translate("MainWindow", "\346\215\242\344\271\230\350\267\257\347\272\277\357\274\232", Q_NULLPTR));
        menuHelp->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266(&F)", Q_NULLPTR));
        menu->setTitle(QApplication::translate("MainWindow", "\346\234\200\350\277\221\346\211\223\345\274\200", Q_NULLPTR));
        menuTool->setTitle(QApplication::translate("MainWindow", "\345\267\245\345\205\267(&T)", Q_NULLPTR));
        menuAdd->setTitle(QApplication::translate("MainWindow", "\345\212\250\346\200\201\346\267\273\345\212\240", Q_NULLPTR));
        menuWatch->setTitle(QApplication::translate("MainWindow", "\346\237\245\347\234\213(&W)", Q_NULLPTR));
        menuView->setTitle(QApplication::translate("MainWindow", "\350\247\206\345\233\276(&V)", Q_NULLPTR));
        menu_H->setTitle(QApplication::translate("MainWindow", "\345\270\256\345\212\251(&H)", Q_NULLPTR));
        menu_A->setTitle(QApplication::translate("MainWindow", "\345\205\263\344\272\216(&A)", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
