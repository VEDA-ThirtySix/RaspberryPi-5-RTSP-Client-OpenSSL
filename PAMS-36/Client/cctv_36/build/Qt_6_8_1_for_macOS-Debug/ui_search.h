/********************************************************************************
** Form generated from reading UI file 'search.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCH_H
#define UI_SEARCH_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Search
{
public:
    QPushButton *pushButton_edit;
    QPushButton *pushButton_delete;
    QPushButton *pushButton_enroll;
    QTabWidget *searchTabWidget;
    QWidget *customerTab;
    QTableView *customerTable;
    QFrame *frame;
    QLabel *imageLabel;
    QLabel *textLabel;
    QLabel *plateTitle;
    QLabel *plateTitle_2;
    QPushButton *searchButton;
    QLineEdit *searchInput;
    QPushButton *filterButton;
    QLabel *plateTitle_5;
    QWidget *videoTab;
    QTableView *videoTable;
    QCalendarWidget *calendarWidget;
    QLabel *plateTitle_3;
    QLabel *imageLabel_2;
    QLabel *plateTitle_4;
    QLabel *calendarFrame;
    QPushButton *calendarButton;
    QLabel *teamLogo;

    void setupUi(QWidget *Search)
    {
        if (Search->objectName().isEmpty())
            Search->setObjectName("Search");
        Search->resize(1052, 616);
        pushButton_edit = new QPushButton(Search);
        pushButton_edit->setObjectName("pushButton_edit");
        pushButton_edit->setGeometry(QRect(900, 310, 101, 25));
        pushButton_edit->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"        font: 300 bold 9pt \"Quicksand Light\";\n"
"        color: black;\n"
"        background-color: rgba(67,188,205,0.5);\n"
"        border:1px solid rgb(67,188,205);\n"
"}\n"
"QPushButton::hover{\n"
"        font: 300 8pt \"Quicksand Light\";\n"
"        color: white;\n"
"        background-color: rgb(209, 209, 209);\n"
"        border:1px solid rgb(67,188,205);\n"
"}"));
        pushButton_delete = new QPushButton(Search);
        pushButton_delete->setObjectName("pushButton_delete");
        pushButton_delete->setGeometry(QRect(900, 350, 101, 25));
        pushButton_delete->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"        font: 300 bold 9pt \"Quicksand Light\";\n"
"        color: black;\n"
"        background-color: rgba(67,188,205,0.1);\n"
"        border:1px solid rgb(67,188,205);\n"
"}\n"
"QPushButton::hover{\n"
"        font: 300 8pt \"Quicksand Light\";\n"
"        color: white;\n"
"        background-color: rgb(209, 209, 209);\n"
"        border:1px solid rgb(67,188,205);\n"
"}"));
        pushButton_enroll = new QPushButton(Search);
        pushButton_enroll->setObjectName("pushButton_enroll");
        pushButton_enroll->setGeometry(QRect(900, 270, 101, 25));
        pushButton_enroll->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"        font: 300 bold 9pt \"Quicksand Light\";\n"
"        color: black;\n"
"        background-color: rgba(67,188,205,0.7);\n"
"        border:1px solid rgb(67,188,205);\n"
"}\n"
"QPushButton::hover{\n"
"        font: 300 8pt \"Quicksand Light\";\n"
"        color: white;\n"
"        background-color: rgb(209, 209, 209);\n"
"        border:1px solid rgb(67,188,205);\n"
"}"));
        searchTabWidget = new QTabWidget(Search);
        searchTabWidget->setObjectName("searchTabWidget");
        searchTabWidget->setGeometry(QRect(10, 20, 881, 521));
        searchTabWidget->setStyleSheet(QString::fromUtf8("QTabWidget#searchTabWidget::pane {\n"
"    background-color: rgb(255, 255, 255);\n"
"    border: 1px solid rgb(67,188,205);\n"
"}\n"
"\n"
"QTabWidget#searchTabWidget > QTabBar::tab {\n"
"    font: 10pt \"Sans Serif\";\n"
"    background-color: rgba(67,188,205,0.5);\n"
"    color: black;\n"
"    padding: 0px;\n"
"    margin-right: 5px;\n"
"    width: 120px;\n"
"    height: 30px;\n"
"    background-repeat: no-repeat;\n"
"    background-position: center;\n"
"}\n"
"\n"
"QTabWidget#searchTabWidget > QTabBar::tab:first {\n"
"    background-color: rgba(67,188,205,0.5);\n"
"    color: white;\n"
"	/*margin-left: 320px;	*/\n"
"	border-top-right-radius: 10px; /* Apply border radius to top-left corner */\n"
"	border-top-left-radius: 10px; /* Apply border radius to top-left corner */\n"
"}\n"
"\n"
"QTabWidget#searchTabWidget > QTabBar::tab:first:selected {\n"
"    background: none;\n"
"    background-color: rgba(67,188,205,0.8);\n"
"    background-image:none;\n"
"    color: rgb(0, 0, 0);\n"
"    font: 500 12pt \"Quicksand "
                        "Medium\";\n"
"}\n"
"\n"
"QTabWidget#searchTabWidget > QTabBar::tab:last {\n"
"    background-color: rgba(67,188,205,0.5);\n"
"    color: white;\n"
"	border-top-right-radius: 10px; /* Apply border radius to top-left corner */\n"
"border-top-left-radius: 10px; /* Apply border radius to top-left corner */\n"
"}\n"
"\n"
"QTabWidget#searchTabWidget > QTabBar::tab:last:selected {\n"
"    background: none;\n"
"    background-color: rgba(67,188,205,0.8);\n"
"    background-image: none;\n"
"    color: rgb(0, 0, 0);\n"
"    font: 500 12pt \"Quicksand Medium\";\n"
"}\n"
"\n"
"QTabWidget#searchTabWidget > QTabBar::tab:hover {\n"
"    background: none;\n"
"    background-color:rgb(209, 209, 209);\n"
"    background-image: none;\n"
"    color: rgb(255, 255, 255);\n"
"    font: 500 10pt \"Quicksand Medium\";\n"
"}"));
        customerTab = new QWidget();
        customerTab->setObjectName("customerTab");
        customerTable = new QTableView(customerTab);
        customerTable->setObjectName("customerTable");
        customerTable->setGeometry(QRect(10, 50, 491, 421));
        customerTable->setStyleSheet(QString::fromUtf8("QTableView {\n"
"    color: rgb(0, 0, 0);\n"
"    background-color: white;\n"
"    border: 1px solid rgb(67, 188, 205);\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background-color:rgba(67,188,205,0.5);/* \355\227\244\353\215\224 \353\260\260\352\262\275 \354\203\211\354\203\201 */\n"
"    border: 1px solid rgb(67,188,205);\n"
"    padding: 3px;\n"
"    font-weight: bold;\n"
"    text-align: center;\n"
"    color: rgb(0, 0, 0); /* \355\227\244\353\215\224 \355\205\215\354\212\244\355\212\270 \354\203\211\354\203\201 */\n"
"        font: 9pt \"Sans Serif\";\n"
"}\n"
""));
        frame = new QFrame(customerTab);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(510, 50, 361, 421));
        frame->setFrameShape(QFrame::NoFrame);
        imageLabel = new QLabel(frame);
        imageLabel->setObjectName("imageLabel");
        imageLabel->setGeometry(QRect(0, 30, 361, 181));
        imageLabel->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"border:1px solid rgb(67,188,205);\n"
"color: rgb(67,188,205);"));
        textLabel = new QLabel(frame);
        textLabel->setObjectName("textLabel");
        textLabel->setGeometry(QRect(0, 250, 361, 171));
        textLabel->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"color:rgb(67,188,205);\n"
"border:1px solid rgb(67,188,205);\n"
"font: 12pt \"Sans Serif\";"));
        plateTitle = new QLabel(frame);
        plateTitle->setObjectName("plateTitle");
        plateTitle->setGeometry(QRect(0, 0, 361, 31));
        plateTitle->setStyleSheet(QString::fromUtf8("font: 300 bold 12pt \"Quicksand Light\";\n"
"color:rgb(67,188,205);\n"
"background-color: rgba(67,188,205,0.3);\n"
"border:1px solid rgb(67,188,205);"));
        plateTitle_2 = new QLabel(frame);
        plateTitle_2->setObjectName("plateTitle_2");
        plateTitle_2->setGeometry(QRect(0, 220, 361, 31));
        plateTitle_2->setStyleSheet(QString::fromUtf8("font: 300 bold 12pt \"Quicksand Light\";\n"
"color: rgb(67,188,205);\n"
"background-color: rgba(67,188,205,0.3);\n"
"border:1px solid rgb(67,188,205);"));
        searchButton = new QPushButton(customerTab);
        searchButton->setObjectName("searchButton");
        searchButton->setGeometry(QRect(420, 10, 81, 31));
        searchButton->setStyleSheet(QString::fromUtf8("color:  rgb(255, 255, 255);\n"
"font: 500 8pt \"Quicksand Medium\";\n"
"background-color: rgba(67,188,205,0.7);\n"
"border:1px solid rgb(67,188,205);"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/search.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        searchButton->setIcon(icon);
        searchInput = new QLineEdit(customerTab);
        searchInput->setObjectName("searchInput");
        searchInput->setGeometry(QRect(10, 10, 361, 31));
        searchInput->setStyleSheet(QString::fromUtf8("color:  rgb(67,188,205);\n"
"font: 500 bold 9pt \"Quicksand Medium\";\n"
"background-color: white;\n"
"border:1px solid rgb(67,188,205);"));
        filterButton = new QPushButton(customerTab);
        filterButton->setObjectName("filterButton");
        filterButton->setGeometry(QRect(370, 10, 51, 31));
        filterButton->setStyleSheet(QString::fromUtf8("color:  rgb(255, 255, 255);\n"
"font: 500 8pt \"Quicksand Medium\";\n"
"background-color: rgba(67,188,205,0.3);\n"
"border:1px solid rgb(67,188,205);"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/list.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        filterButton->setIcon(icon1);
        plateTitle_5 = new QLabel(customerTab);
        plateTitle_5->setObjectName("plateTitle_5");
        plateTitle_5->setGeometry(QRect(600, 10, 171, 31));
        plateTitle_5->setStyleSheet(QString::fromUtf8("font: 300 bold 12pt \"Quicksand Light\";\n"
"color:rgb(67,188,205);\n"
"background-color: none;\n"
"border:none;"));
        searchTabWidget->addTab(customerTab, QString());
        videoTab = new QWidget();
        videoTab->setObjectName("videoTab");
        videoTable = new QTableView(videoTab);
        videoTable->setObjectName("videoTable");
        videoTable->setGeometry(QRect(10, 10, 501, 461));
        videoTable->setStyleSheet(QString::fromUtf8("QTableView {\n"
"    color: rgb(0, 0, 0);\n"
"    background-color: white;\n"
"    border: 1px solid rgb(67, 188, 205);\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background-color:rgba(67,188,205,0.5);/* \355\227\244\353\215\224 \353\260\260\352\262\275 \354\203\211\354\203\201 */\n"
"    border: 1px solid rgb(67,188,205);\n"
"    padding: 3px;\n"
"    font-weight: bold;\n"
"    text-align: center;\n"
"        font: 9pt \"Sans Serif\";\n"
"    color: rgb(0, 0, 0); /* \355\227\244\353\215\224 \355\205\215\354\212\244\355\212\270 \354\203\211\354\203\201 */\n"
"}\n"
""));
        calendarWidget = new QCalendarWidget(videoTab);
        calendarWidget->setObjectName("calendarWidget");
        calendarWidget->setGeometry(QRect(530, 50, 331, 212));
        calendarWidget->setStyleSheet(QString::fromUtf8("/* \354\272\230\353\246\260\353\215\224 \354\240\204\354\262\264 */\n"
"QCalendarWidget {\n"
"    background-color: rgba(255, 255, 255);\n"
"    color: black;\n"
"    selection-color: rgb(0, 0, 0);\n"
"        border:1px solid  rgb(67, 188, 205);\n"
" /* \355\201\254\352\270\260 \354\240\234\355\225\234 \354\204\244\354\240\225 */\n"
"    min-width: 300px;\n"
"    max-width: 340px; /* \352\260\200\353\241\234 \355\201\254\352\270\260 \354\240\234\355\225\234 */\n"
"    min-height: 210px;\n"
"    max-height: 220px; /* \354\204\270\353\241\234 \355\201\254\352\270\260 \354\240\234\355\225\234 */\n"
"}\n"
"\n"
"/* \353\204\244\353\271\204\352\262\214\354\235\264\354\205\230 \353\260\224 */\n"
"QCalendarWidget QWidget#qt_calendar_navigationbar {\n"
"    background-color: rgba(67, 188, 205, 0.3);\n"
"\n"
"        border: none; /* \353\266\210\355\225\204\354\232\224\355\225\234 \355\205\214\353\221\220\353\246\254 \354\240\234\352\261\260 */\n"
"    height: 40px; /* \353\204\244\353\271\204\352\262\214\354\235\264\354"
                        "\205\230 \353\260\224 \353\206\222\354\235\264 */\n"
"    padding: 0 10px; /* \354\226\221\354\252\275 \354\227\254\353\260\261 \354\266\224\352\260\200 */\n"
"}\n"
"\n"
"/* \353\204\244\353\271\204\352\262\214\354\235\264\354\205\230 \353\262\204\355\212\274\n"
"QCalendarWidget QToolButton {\n"
"    width: 20px;\n"
"    height: 20px;\n"
"    color: black;\n"
"    icon-size: 16px, 16px;\n"
"    background-color: rgba(255, 255, 255, 0);\n"
"}\n"
"*/\n"
"\n"
"/* \354\235\264\354\240\204/\353\213\244\354\235\214 \353\262\204\355\212\274 */\n"
"QCalendarWidget QToolButton#qt_calendar_prevmonth,\n"
"QCalendarWidget QToolButton#qt_calendar_nextmonth {\n"
"    width: 20px; /* \353\262\204\355\212\274 \355\201\254\352\270\260 */\n"
"    height: 20px;\n"
"    color: black; /* \355\205\215\354\212\244\355\212\270 \354\203\211\354\203\201 */\n"
"    icon-size: 16px, 16px; /* \354\225\204\354\235\264\354\275\230 \355\201\254\352\270\260 */\n"
"    background-color: transparent; /* \353\260\260\352\262\275 \355\210\254\353"
                        "\252\205 */\n"
"    border: none; /* \355\205\214\353\221\220\353\246\254 \354\240\234\352\261\260 */\n"
"    margin: 0 5px; /* \353\262\204\355\212\274 \354\202\254\354\235\264 \352\260\204\352\262\251 \354\266\224\352\260\200 */\n"
"}\n"
"\n"
"/* \354\244\221\354\225\231\354\235\230 \354\233\224/\353\205\204\353\217\204 \353\262\204\355\212\274 */\n"
"QCalendarWidget QToolButton#qt_calendar_monthbutton,\n"
"QCalendarWidget QToolButton#qt_calendar_yearbutton {\n"
"    color: rgb(81, 100, 166);\n"
"        font: bold 13pt \"Sans Serif\";\n"
"    background-color: transparent; /* \353\260\260\352\262\275 \355\210\254\353\252\205 */\n"
"    border: none; /* \355\205\214\353\221\220\353\246\254 \354\240\234\352\261\260 */\n"
"    margin: 0 10px; /* \354\233\224\352\263\274 \353\205\204\353\217\204 \354\202\254\354\235\264 \352\260\204\352\262\251 */\n"
"    text-align: center; /* \355\205\215\354\212\244\355\212\270 \352\260\200\354\232\264\353\215\260 \354\240\225\353\240\254 */\n"
"}\n"
"\n"
"/* \354\233\224/\353"
                        "\205\204\353\217\204 \352\260\204 \352\260\204\352\262\251 \354\266\224\352\260\200\353\245\274 \354\234\204\355\225\234 \353\240\210\354\235\264\354\225\204\354\233\203 \354\204\244\354\240\225 */\n"
"QCalendarWidget QWidget#qt_calendar_navigationbar QHBoxLayout {\n"
"    spacing: 20px; /* \354\233\224\352\263\274 \353\205\204\353\217\204 \354\202\254\354\235\264 \352\260\204\352\262\251 */\n"
"}\n"
"\n"
"/* \353\213\254\353\240\245 \352\267\270\353\246\254\353\223\234 */\n"
"QCalendarWidget QTableView {\n"
"    background-color: white;\n"
"    selection-background-color: rgba(67, 188, 205, 0.3);\n"
"    selection-color: black;\n"
"}\n"
"\n"
"/* \353\213\254\353\240\245 \354\205\200 */\n"
"QCalendarWidget QTableView QTableCornerButton::section {\n"
"    color: black;\n"
"    background-color: white;\n"
"}\n"
"\n"
"/* \354\232\224\354\235\274 \355\227\244\353\215\224 */\n"
"QCalendarWidget QHeaderView {\n"
"    background-color: white;\n"
"}\n"
"\n"
"QCalendarWidget QHeaderView::section {\n"
"    color: black;"
                        "\n"
"    background-color: rgba(67, 188, 205, 0.1);\n"
"    padding: 1px;\n"
"    border: none;\n"
"}\n"
"\n"
"/* \354\235\274\353\260\230 \353\202\240\354\247\234 */\n"
"QCalendarWidget QAbstractItemView:enabled {\n"
"    color: black;\n"
"    background-color: white;\n"
"    selection-background-color: rgba(67, 188, 205, 0.3);\n"
"    selection-color: black;\n"
"}\n"
"\n"
"/* \353\271\204\355\231\234\354\204\261\355\231\224\353\220\234 \353\202\240\354\247\234 (\354\235\264\354\240\204/\353\213\244\354\235\214 \353\213\254) */\n"
"QCalendarWidget QAbstractItemView:disabled {\n"
"    color: rgb(169, 169, 169);\n"
"}"));
        plateTitle_3 = new QLabel(videoTab);
        plateTitle_3->setObjectName("plateTitle_3");
        plateTitle_3->setGeometry(QRect(520, 280, 351, 31));
        plateTitle_3->setStyleSheet(QString::fromUtf8("font: 300 bold 12pt \"Quicksand Light\";\n"
"color:rgb(67,188,205);\n"
"background-color: rgba(67,188,205,0.3);\n"
"border:1px solid rgb(67,188,205);"));
        imageLabel_2 = new QLabel(videoTab);
        imageLabel_2->setObjectName("imageLabel_2");
        imageLabel_2->setGeometry(QRect(520, 310, 351, 161));
        imageLabel_2->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"border:1px solid rgb(67,188,205);"));
        plateTitle_4 = new QLabel(videoTab);
        plateTitle_4->setObjectName("plateTitle_4");
        plateTitle_4->setGeometry(QRect(520, 10, 351, 31));
        plateTitle_4->setStyleSheet(QString::fromUtf8("font: 300 bold 12pt \"Quicksand Light\";\n"
"color:rgb(67,188,205);\n"
"background-color: rgba(67,188,205,0.3);\n"
"border:1px solid rgb(67,188,205);"));
        calendarFrame = new QLabel(videoTab);
        calendarFrame->setObjectName("calendarFrame");
        calendarFrame->setGeometry(QRect(520, 40, 351, 231));
        calendarFrame->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"border:1px solid rgb(67,188,205);\n"
"color:rgb(67,188,205);\n"
"font: 14pt \"Sans Serif\";"));
        calendarButton = new QPushButton(videoTab);
        calendarButton->setObjectName("calendarButton");
        calendarButton->setGeometry(QRect(820, 10, 51, 31));
        calendarButton->setStyleSheet(QString::fromUtf8("color:  rgb(255, 255, 255);\n"
"background-color:none;\n"
"border-left:1px solid rgb(67,188,205);\n"
"font: 500 8pt \"Quicksand Medium\";"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/calendar.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        calendarButton->setIcon(icon2);
        searchTabWidget->addTab(videoTab, QString());
        imageLabel_2->raise();
        calendarFrame->raise();
        videoTable->raise();
        calendarWidget->raise();
        plateTitle_3->raise();
        plateTitle_4->raise();
        calendarButton->raise();
        teamLogo = new QLabel(Search);
        teamLogo->setObjectName("teamLogo");
        teamLogo->setGeometry(QRect(900, 190, 101, 61));
        teamLogo->setStyleSheet(QString::fromUtf8("background:none;\n"
"border:1px dashed rgbrgb(162, 162, 162);"));
        teamLogo->setPixmap(QPixmap(QString::fromUtf8(":/images/PAMS1.png")));
        teamLogo->setScaledContents(true);

        retranslateUi(Search);

        searchTabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Search);
    } // setupUi

    void retranslateUi(QWidget *Search)
    {
        Search->setWindowTitle(QCoreApplication::translate("Search", "Form", nullptr));
        pushButton_edit->setText(QCoreApplication::translate("Search", "EDIT", nullptr));
        pushButton_delete->setText(QCoreApplication::translate("Search", "DELETE", nullptr));
        pushButton_enroll->setText(QCoreApplication::translate("Search", "ENROLL", nullptr));
        imageLabel->setText(QString());
        textLabel->setText(QString());
        plateTitle->setText(QCoreApplication::translate("Search", "\354\260\250\353\237\211\353\262\210\355\230\270\355\214\220", nullptr));
        plateTitle_2->setText(QCoreApplication::translate("Search", "\352\263\240\352\260\235\354\240\225\353\263\264", nullptr));
        searchButton->setText(QString());
        filterButton->setText(QString());
        plateTitle_5->setText(QCoreApplication::translate("Search", " -- Customer info tab --", nullptr));
        searchTabWidget->setTabText(searchTabWidget->indexOf(customerTab), QCoreApplication::translate("Search", "Customer", nullptr));
        plateTitle_3->setText(QCoreApplication::translate("Search", "\354\260\250\353\237\211\353\262\210\355\230\270\355\214\220", nullptr));
        imageLabel_2->setText(QString());
        plateTitle_4->setText(QCoreApplication::translate("Search", "\353\202\240\354\247\234\354\204\240\355\203\235", nullptr));
        calendarFrame->setText(QCoreApplication::translate("Search", "Select Calender Button", nullptr));
        calendarButton->setText(QString());
        searchTabWidget->setTabText(searchTabWidget->indexOf(videoTab), QCoreApplication::translate("Search", "Video", nullptr));
        teamLogo->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Search: public Ui_Search {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCH_H
