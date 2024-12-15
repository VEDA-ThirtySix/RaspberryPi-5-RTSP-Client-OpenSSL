/********************************************************************************
** Form generated from reading UI file 'streaming.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STREAMING_H
#define UI_STREAMING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Streaming
{
public:
    QFrame *streamingFrame;
    QLabel *streamingLabel;
    QLabel *dateTimeLabel;
    QLabel *licensetitleLabel;
    QPushButton *startButton;
    QPushButton *stopButton;
    QLabel *label_url;
    QFrame *licensePlateframe;
    QVBoxLayout *verticalLayout;
    QLabel *number1;
    QFrame *stateArea;
    QVBoxLayout *verticalLayout_2;
    QFrame *stateFrame;
    QLabel *gate_state;
    QLabel *alarm_state;
    QLabel *label;
    QLabel *VehicleEntry;

    void setupUi(QWidget *Streaming)
    {
        if (Streaming->objectName().isEmpty())
            Streaming->setObjectName("Streaming");
        Streaming->resize(1052, 587);
        streamingFrame = new QFrame(Streaming);
        streamingFrame->setObjectName("streamingFrame");
        streamingFrame->setGeometry(QRect(-10, 0, 1051, 581));
        streamingFrame->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border:none;"));
        streamingFrame->setFrameShape(QFrame::NoFrame);
        streamingLabel = new QLabel(streamingFrame);
        streamingLabel->setObjectName("streamingLabel");
        streamingLabel->setGeometry(QRect(20, 100, 671, 461));
        streamingLabel->setStyleSheet(QString::fromUtf8("font: 300 bold 13pt \"Quicksand Light\";\n"
"color:  rgb(243,115,33);\n"
"background:rgba(243,115,33,0.2);\n"
"border:1px solid rgb(243,115,33);"));
        dateTimeLabel = new QLabel(streamingFrame);
        dateTimeLabel->setObjectName("dateTimeLabel");
        dateTimeLabel->setGeometry(QRect(20, 10, 671, 31));
        dateTimeLabel->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 500 12pt \"Quicksand Medium\";\n"
"background-color: rgba(243,115,33,0.5);\n"
"border:1px solid rgb(243,115,33);\n"
"text-align: center; /* \354\210\230\355\217\211 \354\244\221\354\225\231 \354\240\225\353\240\254 */"));
        licensetitleLabel = new QLabel(streamingFrame);
        licensetitleLabel->setObjectName("licensetitleLabel");
        licensetitleLabel->setGeometry(QRect(700, 350, 321, 31));
        licensetitleLabel->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 500 13pt \"Quicksand Medium\";\n"
"background-color: rgba(243,115,33,0.5);\n"
"border:1px solid rgb(243,115,33);"));
        startButton = new QPushButton(streamingFrame);
        startButton->setObjectName("startButton");
        startButton->setGeometry(QRect(20, 70, 341, 31));
        startButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"        color:  rgb(243,115,33);\n"
"        background:white;\n"
"        border:1px solid rgb(243,115,33);\n"
"        font: 500 10pt \"Quicksand Medium\";\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"        color:  rgb(255, 255, 255);\n"
"        background-color:rgba(243,115,33,0.3);\n"
"        border:1px solid rgb(243,115,33);\n"
"        font: 500 8pt \"Quicksand Medium\";\n"
"}"));
        startButton->setIconSize(QSize(20, 20));
        stopButton = new QPushButton(streamingFrame);
        stopButton->setObjectName("stopButton");
        stopButton->setGeometry(QRect(360, 70, 331, 31));
        stopButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"        color:  rgb(243,115,33);\n"
"        background:white;\n"
"        border:1px solid rgb(243,115,33);\n"
"        font: 500 10pt \"Quicksand Medium\";\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"        color:  rgb(255, 255, 255);\n"
"        background-color:rgba(243,115,33,0.3);\n"
"        border:1px solid rgb(243,115,33);\n"
"        font: 500 8pt \"Quicksand Medium\";\n"
"}"));
        label_url = new QLabel(streamingFrame);
        label_url->setObjectName("label_url");
        label_url->setGeometry(QRect(20, 40, 671, 31));
        label_url->setStyleSheet(QString::fromUtf8("	color:  rgb(154, 154, 154);\n"
"        background:white;\n"
"        border:1px solid rgb(243,115,33);\n"
"        font: 500 10pt \"Quicksand Medium\";\n"
""));
        licensePlateframe = new QFrame(streamingFrame);
        licensePlateframe->setObjectName("licensePlateframe");
        licensePlateframe->setGeometry(QRect(700, 380, 321, 181));
        licensePlateframe->setStyleSheet(QString::fromUtf8("color:  rgb(243,115,33);\n"
"background:white;\n"
"border:1px solid rgb(243,115,33);"));
        licensePlateframe->setFrameShape(QFrame::NoFrame);
        verticalLayout = new QVBoxLayout(licensePlateframe);
        verticalLayout->setObjectName("verticalLayout");
        number1 = new QLabel(licensePlateframe);
        number1->setObjectName("number1");
        number1->setStyleSheet(QString::fromUtf8("background:none;\n"
"border:1px solid rgb(243,115,33);\n"
"font: 300 bold 13pt \"Quicksand Light\";\n"
"color:  rgb(243,115,33);"));

        verticalLayout->addWidget(number1);

        stateArea = new QFrame(streamingFrame);
        stateArea->setObjectName("stateArea");
        stateArea->setGeometry(QRect(700, 40, 321, 301));
        stateArea->setStyleSheet(QString::fromUtf8("color:  rgb(243,115,33);\n"
"background:white;\n"
"border:1px solid rgb(243,115,33);"));
        stateArea->setFrameShape(QFrame::NoFrame);
        verticalLayout_2 = new QVBoxLayout(stateArea);
        verticalLayout_2->setObjectName("verticalLayout_2");
        stateFrame = new QFrame(stateArea);
        stateFrame->setObjectName("stateFrame");
        stateFrame->setFrameShape(QFrame::StyledPanel);
        stateFrame->setFrameShadow(QFrame::Raised);
        gate_state = new QLabel(stateFrame);
        gate_state->setObjectName("gate_state");
        gate_state->setGeometry(QRect(160, 10, 131, 111));
        gate_state->setStyleSheet(QString::fromUtf8("background:white;\n"
"border:1px dashed rgbrgb(162, 162, 162);"));
        gate_state->setScaledContents(true);
        alarm_state = new QLabel(stateFrame);
        alarm_state->setObjectName("alarm_state");
        alarm_state->setGeometry(QRect(10, 10, 131, 111));
        alarm_state->setStyleSheet(QString::fromUtf8("background:white;\n"
"border:1px dashed rgbrgb(162, 162, 162);"));
        alarm_state->setScaledContents(true);

        verticalLayout_2->addWidget(stateFrame);

        label = new QLabel(stateArea);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8("font: 10pt \"Sans Serif\";"));

        verticalLayout_2->addWidget(label);

        VehicleEntry = new QLabel(streamingFrame);
        VehicleEntry->setObjectName("VehicleEntry");
        VehicleEntry->setGeometry(QRect(700, 10, 321, 31));
        VehicleEntry->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 500 13pt \"Quicksand Medium\";\n"
"background-color: rgba(243,115,33,0.5);\n"
"border:1px solid rgb(243,115,33);"));

        retranslateUi(Streaming);

        QMetaObject::connectSlotsByName(Streaming);
    } // setupUi

    void retranslateUi(QWidget *Streaming)
    {
        Streaming->setWindowTitle(QCoreApplication::translate("Streaming", "Form", nullptr));
        streamingLabel->setText(QCoreApplication::translate("Streaming", "Streaming Video", nullptr));
        dateTimeLabel->setText(QCoreApplication::translate("Streaming", "Date - Time", nullptr));
        licensetitleLabel->setText(QCoreApplication::translate("Streaming", "LicensePlate", nullptr));
        startButton->setText(QCoreApplication::translate("Streaming", "Start", nullptr));
        stopButton->setText(QCoreApplication::translate("Streaming", "Stop", nullptr));
        label_url->setText(QCoreApplication::translate("Streaming", "RTSP Server IP Address", nullptr));
        number1->setText(QCoreApplication::translate("Streaming", "Vehicle2", nullptr));
        gate_state->setText(QString());
        alarm_state->setText(QString());
        label->setText(QCoreApplication::translate("Streaming", "Customer Information", nullptr));
        VehicleEntry->setText(QCoreApplication::translate("Streaming", "Vehicle Entry", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Streaming: public Ui_Streaming {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STREAMING_H
