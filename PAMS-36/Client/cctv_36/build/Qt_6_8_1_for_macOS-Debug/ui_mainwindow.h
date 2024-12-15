/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QLabel *guideLabel;
    QLabel *teamLogo;
    QLabel *hanwhaLogo;
    QLineEdit *lineEdit_host;
    QPushButton *pushButton_apply;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1052, 711);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(20, 60, 1021, 631));
        tabWidget->setStyleSheet(QString::fromUtf8("QTabWidget#tabWidget::pane {\n"
"    background-color: rgb(255, 255, 255);\n"
"    /*border: none;*/\n"
"	border:1px dashed rgb(243,115,33);\n"
"	\n"
"}\n"
"\n"
"QTabWidget#tabWidget > QTabBar::tab {\n"
"    font: 9pt \"Sans Serif\";\n"
"    background-color: rgba(243,115,33,0.5);\n"
"    color: transparent;\n"
"    padding: 0px;\n"
"    margin-right: 5px;\n"
"    width: 120px;\n"
"    height: 30px;\n"
"    background-repeat: no-repeat;\n"
"    background-position: center;\n"
"}\n"
"\n"
"QTabWidget#tabWidget > QTabBar::tab:first {\n"
"    background-color: rgba(243,115,33,0.1);\n"
"    background-image: url(:/images/video2.png);\n"
"    color: transparent;\n"
"}\n"
"\n"
"QTabWidget#tabWidget > QTabBar::tab:first:selected {\n"
"    background: none;\n"
"    background-color: rgba(243,115,33,0.5);\n"
"    background-image: transparent;\n"
"    color: rgb(0, 0, 0);\n"
"    font: 500 12pt \"Quicksand Medium\";\n"
"    padding: 0px;\n"
"}\n"
"\n"
"QTabWidget#tabWidget > QTabBar::tab:last {\n"
"    background-color:"
                        " rgba(243,115,33,0.1);\n"
"    background-image: url(:/images/search5.png);\n"
"    color: transparent;\n"
"}\n"
"\n"
"QTabWidget#tabWidget > QTabBar::tab:last:selected {\n"
"    background: none;\n"
"    background-color: rgba(243,115,33,0.5);\n"
"    background-image: none;\n"
"    color: rgb(0, 0, 0);\n"
"    font: 500 12pt \"Quicksand Medium\";\n"
"    padding: 0px;\n"
"}\n"
"\n"
"QTabWidget#tabWidget > QTabBar::tab:hover {\n"
"    background: none;\n"
"    background-color: rgb(223, 223, 223);\n"
"    background-image: none;\n"
"    color: rgb(255, 255, 255);\n"
"    font: 500 10pt \"Quicksand Medium\";\n"
"}"));
        tabWidget->setTabPosition(QTabWidget::North);
        guideLabel = new QLabel(centralwidget);
        guideLabel->setObjectName("guideLabel");
        guideLabel->setGeometry(QRect(0, 0, 1051, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("Quicksand Medium")});
        font.setPointSize(13);
        font.setBold(true);
        font.setItalic(false);
        guideLabel->setFont(font);
        guideLabel->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 500 bold 13pt \"Quicksand Medium\";\n"
"background-color: rgba(243,115,33,0.5);\n"
"border-bottom:2px solid rgb(243,115,33);\n"
"text-align: center; /* \354\210\230\355\217\211 \354\244\221\354\225\231 \354\240\225\353\240\254 */"));
        guideLabel->setAlignment(Qt::AlignCenter);
        teamLogo = new QLabel(centralwidget);
        teamLogo->setObjectName("teamLogo");
        teamLogo->setEnabled(true);
        teamLogo->setGeometry(QRect(900, 0, 151, 31));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("UnDotum")});
        font1.setPointSize(9);
        font1.setBold(true);
        font1.setItalic(false);
        teamLogo->setFont(font1);
        teamLogo->setStyleSheet(QString::fromUtf8("background-color:transparent;\n"
"color: rgb(255, 255, 255);\n"
"\n"
"font: bold 9pt \"UnDotum\";"));
        hanwhaLogo = new QLabel(centralwidget);
        hanwhaLogo->setObjectName("hanwhaLogo");
        hanwhaLogo->setEnabled(true);
        hanwhaLogo->setGeometry(QRect(0, 0, 161, 31));
        hanwhaLogo->setFont(font1);
        hanwhaLogo->setStyleSheet(QString::fromUtf8("background-color:transparent;\n"
"color: rgb(255, 255, 255);\n"
"\n"
"font: bold 9pt \"UnDotum\";"));
        lineEdit_host = new QLineEdit(centralwidget);
        lineEdit_host->setObjectName("lineEdit_host");
        lineEdit_host->setGeometry(QRect(710, 60, 221, 25));
        lineEdit_host->setStyleSheet(QString::fromUtf8("	color:  rgb(243,115,33);\n"
"	background-color:white;\n"
"	border:1px solid rgb(243,115,33);\n"
"	font: 500 9pt \"Quicksand Medium\";\n"
""));
        pushButton_apply = new QPushButton(centralwidget);
        pushButton_apply->setObjectName("pushButton_apply");
        pushButton_apply->setGeometry(QRect(930, 60, 111, 25));
        pushButton_apply->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color:rgba(243,115,33,0.5);\n"
"border:1px solid rgb(243,115,33);\n"
"font: 500 bold 10pt \"Quicksand Medium\";"));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        guideLabel->setText(QCoreApplication::translate("MainWindow", "LicensePlate Detection CCTV App", nullptr));
        teamLogo->setText(QCoreApplication::translate("MainWindow", "Thirty-Six Stratagems ", nullptr));
        hanwhaLogo->setText(QCoreApplication::translate("MainWindow", " HanwhaVision", nullptr));
        lineEdit_host->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter HOST IP Address", nullptr));
        pushButton_apply->setText(QCoreApplication::translate("MainWindow", "APPLY", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
