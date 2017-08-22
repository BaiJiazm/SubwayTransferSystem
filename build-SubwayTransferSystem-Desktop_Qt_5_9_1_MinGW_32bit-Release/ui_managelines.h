/********************************************************************************
** Form generated from reading UI file 'managelines.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANAGELINES_H
#define UI_MANAGELINES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ManageLines
{
public:
    QTabWidget *tabWidget;
    QWidget *tabAddLine;
    QLabel *label;
    QLabel *label_3;
    QLineEdit *lineEditLineName;
    QPushButton *pushButtonAddLine;
    QLabel *label_8;
    QPushButton *pushButtonChooseColor;
    QTextBrowser *textBrowserAddLine;
    QLabel *label_21;
    QWidget *tabAddStation;
    QDoubleSpinBox *doubleSpinBoxLatitude;
    QLabel *labelLatitude;
    QLabel *labelLongitude;
    QDoubleSpinBox *doubleSpinBoxLongitude;
    QLineEdit *lineEditStationName;
    QTextBrowser *textBrowserLinesSelected;
    QLabel *label_4;
    QLabel *label_9;
    QLabel *label_10;
    QPushButton *pushButtonAddStation;
    QLabel *label_11;
    QLabel *label_22;
    QTextBrowser *textBrowserAddStaiton;
    QLabel *label_23;
    QListWidget *listWidget;
    QWidget *tabAddConnection;
    QComboBox *comboBoxConnectStation1;
    QLabel *label_5;
    QLabel *label_6;
    QComboBox *comboBoxConnectStation2;
    QPushButton *pushButtonConnect;
    QLabel *label_7;
    QComboBox *comboBoxConnectLine;
    QLabel *label_2;
    QWidget *tabAddByText;
    QTextEdit *textEdit;
    QPushButton *pushButtonAddByText;

    void setupUi(QDialog *ManageLines)
    {
        if (ManageLines->objectName().isEmpty())
            ManageLines->setObjectName(QStringLiteral("ManageLines"));
        ManageLines->setEnabled(true);
        ManageLines->resize(600, 400);
        QFont font;
        font.setFamily(QStringLiteral("Consolas"));
        ManageLines->setFont(font);
        QIcon icon;
        icon.addFile(QStringLiteral(":/icon/icon/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        ManageLines->setWindowIcon(icon);
        tabWidget = new QTabWidget(ManageLines);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setEnabled(true);
        tabWidget->setGeometry(QRect(0, 0, 600, 400));
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setElideMode(Qt::ElideNone);
        tabAddLine = new QWidget();
        tabAddLine->setObjectName(QStringLiteral("tabAddLine"));
        tabAddLine->setFont(font);
        label = new QLabel(tabAddLine);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 20, 560, 160));
        label->setFont(font);
        label_3 = new QLabel(tabAddLine);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 200, 80, 20));
        lineEditLineName = new QLineEdit(tabAddLine);
        lineEditLineName->setObjectName(QStringLiteral("lineEditLineName"));
        lineEditLineName->setGeometry(QRect(120, 200, 80, 20));
        pushButtonAddLine = new QPushButton(tabAddLine);
        pushButtonAddLine->setObjectName(QStringLiteral("pushButtonAddLine"));
        pushButtonAddLine->setGeometry(QRect(440, 320, 80, 30));
        pushButtonAddLine->setMinimumSize(QSize(0, 0));
        pushButtonAddLine->setFont(font);
        label_8 = new QLabel(tabAddLine);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(20, 240, 80, 20));
        pushButtonChooseColor = new QPushButton(tabAddLine);
        pushButtonChooseColor->setObjectName(QStringLiteral("pushButtonChooseColor"));
        pushButtonChooseColor->setGeometry(QRect(120, 240, 80, 20));
        pushButtonChooseColor->setMinimumSize(QSize(0, 0));
        pushButtonChooseColor->setMaximumSize(QSize(16777215, 16777215));
        pushButtonChooseColor->setFont(font);
        textBrowserAddLine = new QTextBrowser(tabAddLine);
        textBrowserAddLine->setObjectName(QStringLiteral("textBrowserAddLine"));
        textBrowserAddLine->setEnabled(false);
        textBrowserAddLine->setGeometry(QRect(400, 200, 140, 60));
        label_21 = new QLabel(tabAddLine);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(400, 180, 80, 20));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icon/icon/subway.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(tabAddLine, icon1, QString());
        tabAddStation = new QWidget();
        tabAddStation->setObjectName(QStringLiteral("tabAddStation"));
        doubleSpinBoxLatitude = new QDoubleSpinBox(tabAddStation);
        doubleSpinBoxLatitude->setObjectName(QStringLiteral("doubleSpinBoxLatitude"));
        doubleSpinBoxLatitude->setGeometry(QRect(70, 160, 88, 20));
        doubleSpinBoxLatitude->setMinimumSize(QSize(85, 20));
        doubleSpinBoxLatitude->setDecimals(7);
        doubleSpinBoxLatitude->setMinimum(30.9);
        doubleSpinBoxLatitude->setMaximum(31.45);
        doubleSpinBoxLatitude->setSingleStep(0.1);
        doubleSpinBoxLatitude->setValue(30.9);
        labelLatitude = new QLabel(tabAddStation);
        labelLatitude->setObjectName(QStringLiteral("labelLatitude"));
        labelLatitude->setGeometry(QRect(20, 160, 35, 20));
        labelLatitude->setMinimumSize(QSize(35, 20));
        labelLatitude->setFont(font);
        labelLongitude = new QLabel(tabAddStation);
        labelLongitude->setObjectName(QStringLiteral("labelLongitude"));
        labelLongitude->setGeometry(QRect(20, 130, 35, 20));
        labelLongitude->setMinimumSize(QSize(35, 20));
        labelLongitude->setFont(font);
        doubleSpinBoxLongitude = new QDoubleSpinBox(tabAddStation);
        doubleSpinBoxLongitude->setObjectName(QStringLiteral("doubleSpinBoxLongitude"));
        doubleSpinBoxLongitude->setGeometry(QRect(70, 130, 89, 20));
        doubleSpinBoxLongitude->setMinimumSize(QSize(85, 20));
        doubleSpinBoxLongitude->setDecimals(7);
        doubleSpinBoxLongitude->setMinimum(121);
        doubleSpinBoxLongitude->setMaximum(122);
        doubleSpinBoxLongitude->setSingleStep(0.1);
        doubleSpinBoxLongitude->setValue(121);
        lineEditStationName = new QLineEdit(tabAddStation);
        lineEditStationName->setObjectName(QStringLiteral("lineEditStationName"));
        lineEditStationName->setGeometry(QRect(20, 50, 80, 20));
        lineEditStationName->setMinimumSize(QSize(0, 0));
        lineEditStationName->setMaximumSize(QSize(16777215, 16777215));
        lineEditStationName->setFont(font);
        textBrowserLinesSelected = new QTextBrowser(tabAddStation);
        textBrowserLinesSelected->setObjectName(QStringLiteral("textBrowserLinesSelected"));
        textBrowserLinesSelected->setEnabled(false);
        textBrowserLinesSelected->setGeometry(QRect(440, 50, 140, 140));
        label_4 = new QLabel(tabAddStation);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 20, 80, 20));
        label_9 = new QLabel(tabAddStation);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(20, 100, 80, 20));
        label_10 = new QLabel(tabAddStation);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(440, 20, 80, 20));
        pushButtonAddStation = new QPushButton(tabAddStation);
        pushButtonAddStation->setObjectName(QStringLiteral("pushButtonAddStation"));
        pushButtonAddStation->setGeometry(QRect(440, 330, 80, 30));
        pushButtonAddStation->setMinimumSize(QSize(0, 0));
        pushButtonAddStation->setFont(font);
        label_11 = new QLabel(tabAddStation);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(200, 20, 200, 20));
        label_22 = new QLabel(tabAddStation);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(440, 200, 80, 20));
        textBrowserAddStaiton = new QTextBrowser(tabAddStation);
        textBrowserAddStaiton->setObjectName(QStringLiteral("textBrowserAddStaiton"));
        textBrowserAddStaiton->setEnabled(false);
        textBrowserAddStaiton->setGeometry(QRect(440, 230, 140, 91));
        label_23 = new QLabel(tabAddStation);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(20, 200, 160, 80));
        listWidget = new QListWidget(tabAddStation);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(200, 50, 200, 270));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/icon/icon/station.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(tabAddStation, icon2, QString());
        tabAddConnection = new QWidget();
        tabAddConnection->setObjectName(QStringLiteral("tabAddConnection"));
        tabAddConnection->setEnabled(true);
        comboBoxConnectStation1 = new QComboBox(tabAddConnection);
        comboBoxConnectStation1->setObjectName(QStringLiteral("comboBoxConnectStation1"));
        comboBoxConnectStation1->setEnabled(true);
        comboBoxConnectStation1->setGeometry(QRect(100, 170, 100, 20));
        comboBoxConnectStation1->setMinimumSize(QSize(0, 0));
        comboBoxConnectStation1->setMaximumSize(QSize(16777215, 16777215));
        comboBoxConnectStation1->setFont(font);
        comboBoxConnectStation1->setEditable(true);
        label_5 = new QLabel(tabAddConnection);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 170, 80, 20));
        label_6 = new QLabel(tabAddConnection);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(20, 210, 80, 20));
        comboBoxConnectStation2 = new QComboBox(tabAddConnection);
        comboBoxConnectStation2->setObjectName(QStringLiteral("comboBoxConnectStation2"));
        comboBoxConnectStation2->setGeometry(QRect(100, 210, 100, 20));
        comboBoxConnectStation2->setMinimumSize(QSize(0, 0));
        comboBoxConnectStation2->setMaximumSize(QSize(16777215, 16777215));
        comboBoxConnectStation2->setFont(font);
        comboBoxConnectStation2->setEditable(true);
        pushButtonConnect = new QPushButton(tabAddConnection);
        pushButtonConnect->setObjectName(QStringLiteral("pushButtonConnect"));
        pushButtonConnect->setGeometry(QRect(100, 290, 80, 30));
        pushButtonConnect->setMinimumSize(QSize(0, 0));
        pushButtonConnect->setFont(font);
        label_7 = new QLabel(tabAddConnection);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(20, 250, 80, 20));
        comboBoxConnectLine = new QComboBox(tabAddConnection);
        comboBoxConnectLine->setObjectName(QStringLiteral("comboBoxConnectLine"));
        comboBoxConnectLine->setGeometry(QRect(100, 250, 100, 20));
        comboBoxConnectLine->setMinimumSize(QSize(0, 0));
        comboBoxConnectLine->setMaximumSize(QSize(16777215, 16777215));
        comboBoxConnectLine->setFont(font);
        comboBoxConnectLine->setEditable(true);
        label_2 = new QLabel(tabAddConnection);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 20, 560, 100));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/icon/icon/connect.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(tabAddConnection, icon3, QString());
        tabAddByText = new QWidget();
        tabAddByText->setObjectName(QStringLiteral("tabAddByText"));
        textEdit = new QTextEdit(tabAddByText);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(20, 20, 560, 300));
        pushButtonAddByText = new QPushButton(tabAddByText);
        pushButtonAddByText->setObjectName(QStringLiteral("pushButtonAddByText"));
        pushButtonAddByText->setGeometry(QRect(440, 330, 80, 30));
        pushButtonAddByText->setMinimumSize(QSize(0, 0));
        pushButtonAddByText->setFont(font);
        tabWidget->addTab(tabAddByText, QString());
#ifndef QT_NO_SHORTCUT
        label_3->setBuddy(lineEditLineName);
        label_8->setBuddy(pushButtonChooseColor);
        labelLatitude->setBuddy(doubleSpinBoxLatitude);
        labelLongitude->setBuddy(doubleSpinBoxLongitude);
        label_4->setBuddy(lineEditStationName);
        label_9->setBuddy(doubleSpinBoxLongitude);
        label_5->setBuddy(comboBoxConnectStation1);
        label_6->setBuddy(comboBoxConnectStation2);
        label_7->setBuddy(comboBoxConnectLine);
#endif // QT_NO_SHORTCUT

        retranslateUi(ManageLines);

        tabWidget->setCurrentIndex(1);
        pushButtonAddLine->setDefault(true);
        pushButtonAddStation->setDefault(true);
        comboBoxConnectStation1->setCurrentIndex(-1);
        pushButtonConnect->setDefault(true);
        pushButtonAddByText->setDefault(true);


        QMetaObject::connectSlotsByName(ManageLines);
    } // setupUi

    void retranslateUi(QDialog *ManageLines)
    {
        ManageLines->setWindowTitle(QApplication::translate("ManageLines", "\346\267\273\345\212\240", Q_NULLPTR));
        label->setText(QApplication::translate("ManageLines", "<html><head/><body><p><span style=\" font-weight:600;\">\346\217\220\347\244\272\357\274\232</span>\346\226\260\345\242\236\347\272\277\350\267\257\346\226\271\346\263\225</p><p>1.\345\205\210\346\267\273\345\212\240\346\226\260\347\272\277\350\267\257\344\277\241\346\201\257\357\274\233</p><p>2.\347\204\266\345\220\216\345\234\250\345\267\245\345\205\267\343\200\220\347\253\231\347\202\271\343\200\221\344\270\255\346\267\273\345\212\240\347\272\277\350\267\257\347\253\231\347\202\271\357\274\233</p><p>3.\346\234\200\345\220\216\345\234\250\345\267\245\345\205\267\343\200\220\350\277\236\346\216\245\343\200\221\344\270\255\347\241\256\345\256\232\347\253\231\347\202\271\350\277\236\346\216\245\345\205\263\347\263\273\357\274\233</p><p>4.\344\271\237\345\217\257\344\273\245\347\224\250\346\226\207\346\234\254\346\226\271\345\274\217\347\256\200\345\215\225\345\277\253\346\215\267\346\267\273\345\212\240\357\274\214\346\240\274\345\274\217\351\234\200\350\247\204\350\214\203\343\200\202</p></body></html>", Q_NULLPTR));
        label_3->setText(QApplication::translate("ManageLines", "\347\272\277\350\267\257\345\220\215\347\247\260(&N)\357\274\232", Q_NULLPTR));
        lineEditLineName->setPlaceholderText(QApplication::translate("ManageLines", "\350\257\267\350\276\223\345\205\245\347\272\277\350\267\257\345\220\215", Q_NULLPTR));
        pushButtonAddLine->setText(QApplication::translate("ManageLines", "\346\267\273\345\212\240\347\272\277\350\267\257", Q_NULLPTR));
        label_8->setText(QApplication::translate("ManageLines", "\347\272\277\350\267\257\351\242\234\350\211\262(&C)\357\274\232", Q_NULLPTR));
        pushButtonChooseColor->setText(QApplication::translate("ManageLines", "\346\213\276\345\217\226\351\242\234\350\211\262", Q_NULLPTR));
        label_21->setText(QApplication::translate("ManageLines", "\346\267\273\345\212\240\344\277\241\346\201\257\357\274\232", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tabAddLine), QApplication::translate("ManageLines", "\347\272\277\350\267\257(&L)", Q_NULLPTR));
        labelLatitude->setText(QApplication::translate("ManageLines", "\345\214\227\347\272\254&N", Q_NULLPTR));
        labelLongitude->setText(QApplication::translate("ManageLines", "\344\270\234\347\273\217&E", Q_NULLPTR));
        lineEditStationName->setText(QString());
        lineEditStationName->setPlaceholderText(QApplication::translate("ManageLines", "\346\267\273\345\212\240\347\253\231\347\202\271\345\220\215", Q_NULLPTR));
        label_4->setText(QApplication::translate("ManageLines", "\347\253\231\347\202\271\345\220\215\347\247\260(&N)\357\274\232", Q_NULLPTR));
        label_9->setText(QApplication::translate("ManageLines", "\345\234\260\347\220\206\345\235\220\346\240\207(&P)\357\274\232", Q_NULLPTR));
        label_10->setText(QApplication::translate("ManageLines", "\345\267\262\351\200\211\346\213\251\357\274\232", Q_NULLPTR));
        pushButtonAddStation->setText(QApplication::translate("ManageLines", "\346\267\273\345\212\240\347\253\231\347\202\271", Q_NULLPTR));
        label_11->setText(QApplication::translate("ManageLines", "\351\200\211\346\213\251 \346\267\273\345\212\240\345\210\260\347\272\277\350\267\257\357\274\232", Q_NULLPTR));
        label_22->setText(QApplication::translate("ManageLines", "\346\267\273\345\212\240\344\277\241\346\201\257\357\274\232", Q_NULLPTR));
        label_23->setText(QApplication::translate("ManageLines", "<html><head/><body><p>\346\234\211\346\225\210\350\214\203\345\233\264:</p><p>min [ 121.0 , 30.9 ]</p><p>max [ 122.0 , 31.5 ]</p><p><br/></p></body></html>", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tabAddStation), QApplication::translate("ManageLines", "\347\253\231\347\202\271(&S)", Q_NULLPTR));
        label_5->setText(QApplication::translate("ManageLines", "\347\253\231\347\202\2711(&O)\357\274\232", Q_NULLPTR));
        label_6->setText(QApplication::translate("ManageLines", "\347\253\231\347\202\2712(&T)\357\274\232", Q_NULLPTR));
        pushButtonConnect->setText(QApplication::translate("ManageLines", "\350\277\236\346\216\245", Q_NULLPTR));
        label_7->setText(QApplication::translate("ManageLines", "\346\211\200\345\261\236\347\272\277\350\267\257(&L)\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("ManageLines", "<html><head/><body><p><span style=\" font-weight:600;\">\346\217\220\347\244\272\357\274\232</span>\350\277\236\346\216\245\347\253\231\347\202\271</p><p>1.\350\277\236\346\216\245\342\200\234\347\253\231\347\202\2711\342\200\235\345\222\214\342\200\234\347\253\231\347\202\2712\342\200\235\344\270\272\344\270\200\346\235\241\350\276\271\357\274\233</p><p>2.\342\200\234\347\253\231\347\202\2711\342\200\235\345\222\214\342\200\234\347\253\231\347\202\2712\342\200\235\345\261\236\344\272\216\345\220\214\344\270\200\346\235\241\347\272\277\350\267\257\344\270\255\347\232\204\344\270\215\345\220\214\347\253\231\347\202\271\357\274\233</p><p>3.\347\253\231\347\202\271\345\217\212\347\272\277\350\267\257\351\200\211\346\213\251\345\217\257\344\273\245\351\200\211\346\213\251\344\271\237\345\217\257\347\233\264\346\216\245\350\276\223\345\205\245\343\200\202</p></body></html>", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tabAddConnection), QApplication::translate("ManageLines", "\350\277\236\346\216\245(&C)", Q_NULLPTR));
        pushButtonAddByText->setText(QApplication::translate("ManageLines", "\346\267\273\345\212\240", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tabAddByText), QApplication::translate("ManageLines", "\346\226\207\346\234\254\346\226\271\345\274\217", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ManageLines: public Ui_ManageLines {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGELINES_H
