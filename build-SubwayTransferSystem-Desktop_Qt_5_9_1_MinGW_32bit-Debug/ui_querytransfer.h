/********************************************************************************
** Form generated from reading UI file 'querytransfer.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUERYTRANSFER_H
#define UI_QUERYTRANSFER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_QueryTransfer
{
public:
    QLabel *labelTransferRoute;
    QTextBrowser *textBrowserRoute;
    QPushButton *pushButtonTransfer;
    QGroupBox *groupBox;
    QRadioButton *radioButtonMinTime;
    QRadioButton *radioButtonMinTransfer;
    QComboBox *comboBoxDstLine;
    QComboBox *comboBoxDstStation;
    QLabel *labelDestination;
    QLabel *labelStart;
    QComboBox *comboBoxStartLine;
    QComboBox *comboBoxStartStation;

    void setupUi(QDialog *QueryTransfer)
    {
        if (QueryTransfer->objectName().isEmpty())
            QueryTransfer->setObjectName(QStringLiteral("QueryTransfer"));
        QueryTransfer->resize(320, 570);
        QIcon icon;
        icon.addFile(QStringLiteral(":/icon/icon/query.png"), QSize(), QIcon::Normal, QIcon::Off);
        QueryTransfer->setWindowIcon(icon);
        labelTransferRoute = new QLabel(QueryTransfer);
        labelTransferRoute->setObjectName(QStringLiteral("labelTransferRoute"));
        labelTransferRoute->setGeometry(QRect(10, 170, 300, 20));
        labelTransferRoute->setMinimumSize(QSize(280, 20));
        QFont font;
        font.setFamily(QStringLiteral("Consolas"));
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        labelTransferRoute->setFont(font);
        textBrowserRoute = new QTextBrowser(QueryTransfer);
        textBrowserRoute->setObjectName(QStringLiteral("textBrowserRoute"));
        textBrowserRoute->setGeometry(QRect(10, 200, 300, 360));
        textBrowserRoute->setMinimumSize(QSize(0, 0));
        QFont font1;
        font1.setFamily(QStringLiteral("Consolas"));
        textBrowserRoute->setFont(font1);
        pushButtonTransfer = new QPushButton(QueryTransfer);
        pushButtonTransfer->setObjectName(QStringLiteral("pushButtonTransfer"));
        pushButtonTransfer->setGeometry(QRect(220, 110, 80, 30));
        pushButtonTransfer->setMinimumSize(QSize(70, 30));
        pushButtonTransfer->setFont(font1);
        groupBox = new QGroupBox(QueryTransfer);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 80, 190, 60));
        groupBox->setMinimumSize(QSize(0, 0));
        radioButtonMinTime = new QRadioButton(groupBox);
        radioButtonMinTime->setObjectName(QStringLiteral("radioButtonMinTime"));
        radioButtonMinTime->setGeometry(QRect(0, 20, 180, 16));
        radioButtonMinTime->setMinimumSize(QSize(0, 0));
        radioButtonMinTime->setFont(font1);
        radioButtonMinTransfer = new QRadioButton(groupBox);
        radioButtonMinTransfer->setObjectName(QStringLiteral("radioButtonMinTransfer"));
        radioButtonMinTransfer->setGeometry(QRect(0, 40, 180, 20));
        radioButtonMinTransfer->setMinimumSize(QSize(0, 0));
        radioButtonMinTransfer->setFont(font1);
        comboBoxDstLine = new QComboBox(QueryTransfer);
        comboBoxDstLine->setObjectName(QStringLiteral("comboBoxDstLine"));
        comboBoxDstLine->setGeometry(QRect(110, 50, 90, 20));
        comboBoxDstLine->setMinimumSize(QSize(90, 20));
        comboBoxDstLine->setFont(font1);
        comboBoxDstStation = new QComboBox(QueryTransfer);
        comboBoxDstStation->setObjectName(QStringLiteral("comboBoxDstStation"));
        comboBoxDstStation->setGeometry(QRect(210, 50, 90, 22));
        comboBoxDstStation->setMinimumSize(QSize(90, 20));
        comboBoxDstStation->setFont(font1);
        labelDestination = new QLabel(QueryTransfer);
        labelDestination->setObjectName(QStringLiteral("labelDestination"));
        labelDestination->setGeometry(QRect(10, 50, 90, 20));
        labelDestination->setMinimumSize(QSize(70, 20));
        labelDestination->setFont(font1);
        labelStart = new QLabel(QueryTransfer);
        labelStart->setObjectName(QStringLiteral("labelStart"));
        labelStart->setGeometry(QRect(10, 20, 90, 20));
        labelStart->setMinimumSize(QSize(70, 20));
        labelStart->setFont(font1);
        comboBoxStartLine = new QComboBox(QueryTransfer);
        comboBoxStartLine->setObjectName(QStringLiteral("comboBoxStartLine"));
        comboBoxStartLine->setGeometry(QRect(110, 20, 90, 20));
        comboBoxStartLine->setMinimumSize(QSize(90, 20));
        comboBoxStartLine->setFont(font1);
        comboBoxStartStation = new QComboBox(QueryTransfer);
        comboBoxStartStation->setObjectName(QStringLiteral("comboBoxStartStation"));
        comboBoxStartStation->setGeometry(QRect(210, 20, 90, 22));
        comboBoxStartStation->setMinimumSize(QSize(90, 20));
        comboBoxStartStation->setFont(font1);
#ifndef QT_NO_SHORTCUT
        labelDestination->setBuddy(comboBoxDstLine);
        labelStart->setBuddy(comboBoxStartLine);
#endif // QT_NO_SHORTCUT

        retranslateUi(QueryTransfer);

        comboBoxDstLine->setCurrentIndex(0);
        comboBoxDstStation->setCurrentIndex(-1);
        comboBoxStartLine->setCurrentIndex(0);
        comboBoxStartStation->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(QueryTransfer);
    } // setupUi

    void retranslateUi(QDialog *QueryTransfer)
    {
        QueryTransfer->setWindowTitle(QApplication::translate("QueryTransfer", "\346\215\242\344\271\230\346\214\207\345\215\227", Q_NULLPTR));
        labelTransferRoute->setText(QApplication::translate("QueryTransfer", "\346\215\242\344\271\230\350\267\257\347\272\277\357\274\232", Q_NULLPTR));
        pushButtonTransfer->setText(QApplication::translate("QueryTransfer", "\346\215\242\344\271\230", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("QueryTransfer", "\345\207\272\350\241\214\347\255\226\347\225\245", Q_NULLPTR));
        radioButtonMinTime->setText(QApplication::translate("QueryTransfer", "\346\211\200\351\234\200\346\227\266\351\227\264\346\234\200\347\237\255", Q_NULLPTR));
        radioButtonMinTransfer->setText(QApplication::translate("QueryTransfer", "\346\215\242\344\271\230\346\254\241\346\225\260\346\234\200\345\260\221", Q_NULLPTR));
        comboBoxDstLine->clear();
        comboBoxDstLine->insertItems(0, QStringList()
         << QApplication::translate("QueryTransfer", "\351\200\211\346\213\251\350\267\257\347\272\277", Q_NULLPTR)
        );
        comboBoxDstStation->clear();
        comboBoxDstStation->insertItems(0, QStringList()
         << QApplication::translate("QueryTransfer", "\351\200\211\346\213\251\347\253\231\347\202\271", Q_NULLPTR)
        );
        labelDestination->setText(QApplication::translate("QueryTransfer", "\347\273\210\347\202\271\347\253\231(&D)\357\274\232", Q_NULLPTR));
        labelStart->setText(QApplication::translate("QueryTransfer", "\350\265\267\347\202\271\347\253\231(&S)\357\274\232", Q_NULLPTR));
        comboBoxStartLine->clear();
        comboBoxStartLine->insertItems(0, QStringList()
         << QApplication::translate("QueryTransfer", "\351\200\211\346\213\251\350\267\257\347\272\277", Q_NULLPTR)
        );
        comboBoxStartLine->setCurrentText(QApplication::translate("QueryTransfer", "\351\200\211\346\213\251\350\267\257\347\272\277", Q_NULLPTR));
        comboBoxStartStation->clear();
        comboBoxStartStation->insertItems(0, QStringList()
         << QApplication::translate("QueryTransfer", "\351\200\211\346\213\251\347\253\231\347\202\271", Q_NULLPTR)
        );
    } // retranslateUi

};

namespace Ui {
    class QueryTransfer: public Ui_QueryTransfer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUERYTRANSFER_H
