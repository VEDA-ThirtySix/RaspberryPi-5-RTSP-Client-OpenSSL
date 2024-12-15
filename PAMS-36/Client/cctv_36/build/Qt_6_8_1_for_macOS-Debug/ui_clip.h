/********************************************************************************
** Form generated from reading UI file 'clip.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIP_H
#define UI_CLIP_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_VideoClipDialog
{
public:
    QVBoxLayout *mainLayout;
    QVBoxLayout *videoLayout;
    QLabel *ffmpegLabel;
    QSlider *positionSlider;
    QHBoxLayout *timeLayout;
    QLabel *currentTimeLabel;
    QLabel *label;
    QPushButton *playPauseButton;
    QPushButton *stopButton;
    QLabel *label_2;
    QLabel *totalTimeLabel;

    void setupUi(QDialog *VideoClipDialog)
    {
        if (VideoClipDialog->objectName().isEmpty())
            VideoClipDialog->setObjectName("VideoClipDialog");
        VideoClipDialog->resize(800, 605);
        mainLayout = new QVBoxLayout(VideoClipDialog);
        mainLayout->setObjectName("mainLayout");
        videoLayout = new QVBoxLayout();
        videoLayout->setObjectName("videoLayout");
        ffmpegLabel = new QLabel(VideoClipDialog);
        ffmpegLabel->setObjectName("ffmpegLabel");
        ffmpegLabel->setMinimumSize(QSize(640, 480));
        ffmpegLabel->setStyleSheet(QString::fromUtf8("background-color: black;"));
        ffmpegLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        videoLayout->addWidget(ffmpegLabel);


        mainLayout->addLayout(videoLayout);

        positionSlider = new QSlider(VideoClipDialog);
        positionSlider->setObjectName("positionSlider");
        positionSlider->setOrientation(Qt::Orientation::Horizontal);

        mainLayout->addWidget(positionSlider);

        timeLayout = new QHBoxLayout();
        timeLayout->setObjectName("timeLayout");
        currentTimeLabel = new QLabel(VideoClipDialog);
        currentTimeLabel->setObjectName("currentTimeLabel");
        currentTimeLabel->setMinimumSize(QSize(60, 0));
        currentTimeLabel->setStyleSheet(QString::fromUtf8("font: 500 bold 13pt \"Quicksand Medium\";"));

        timeLayout->addWidget(currentTimeLabel);

        label = new QLabel(VideoClipDialog);
        label->setObjectName("label");

        timeLayout->addWidget(label);

        playPauseButton = new QPushButton(VideoClipDialog);
        playPauseButton->setObjectName("playPauseButton");
        playPauseButton->setMinimumSize(QSize(80, 30));
        playPauseButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: rgb(243,115,33);\n"
"    background: none;\n"
"    border: none;\n"
"    border-radius: 15px;  /* \355\205\214\353\221\220\353\246\254 \353\221\245\352\270\200\352\262\214 */\n"
"    font: 500 9pt 'Quicksand Medium';\n"
"    icon-size: 24px;  /* \354\225\204\354\235\264\354\275\230 \355\201\254\352\270\260 \354\246\235\352\260\200 */\n"
"    padding: 5px;  /* \353\262\204\355\212\274 \353\202\264\353\266\200 \354\227\254\353\260\261 */\n"
"}\n"
"QPushButton:hover {\n"
"    color: white;\n"
"    background-color: rgba(243,115,33,0.5);\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/play.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        playPauseButton->setIcon(icon);

        timeLayout->addWidget(playPauseButton);

        stopButton = new QPushButton(VideoClipDialog);
        stopButton->setObjectName("stopButton");
        stopButton->setMinimumSize(QSize(80, 30));
        stopButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: rgb(243,115,33);\n"
"    background: none;\n"
"    border: none;\n"
"    border-radius: 15px;  /* \355\205\214\353\221\220\353\246\254 \353\221\245\352\270\200\352\262\214 */\n"
"    font: 500 9pt 'Quicksand Medium';\n"
"    icon-size: 24px;  /* \354\225\204\354\235\264\354\275\230 \355\201\254\352\270\260 \354\246\235\352\260\200 */\n"
"    padding: 5px;  /* \353\262\204\355\212\274 \353\202\264\353\266\200 \354\227\254\353\260\261 */\n"
"}\n"
"QPushButton:hover {\n"
"    color: white;\n"
"    background-color: rgba(243,115,33,0.5);\n"
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/stop.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        stopButton->setIcon(icon1);

        timeLayout->addWidget(stopButton);

        label_2 = new QLabel(VideoClipDialog);
        label_2->setObjectName("label_2");

        timeLayout->addWidget(label_2);

        totalTimeLabel = new QLabel(VideoClipDialog);
        totalTimeLabel->setObjectName("totalTimeLabel");
        totalTimeLabel->setMinimumSize(QSize(60, 0));
        totalTimeLabel->setStyleSheet(QString::fromUtf8("font: 500 bold 13pt \"Quicksand Medium\";"));
        totalTimeLabel->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        timeLayout->addWidget(totalTimeLabel);


        mainLayout->addLayout(timeLayout);


        retranslateUi(VideoClipDialog);

        QMetaObject::connectSlotsByName(VideoClipDialog);
    } // setupUi

    void retranslateUi(QDialog *VideoClipDialog)
    {
        VideoClipDialog->setWindowTitle(QCoreApplication::translate("VideoClipDialog", "Video Clip Player", nullptr));
        ffmpegLabel->setText(QString());
        currentTimeLabel->setText(QCoreApplication::translate("VideoClipDialog", "00:00", nullptr));
        label->setText(QString());
        playPauseButton->setText(QString());
        stopButton->setText(QString());
        label_2->setText(QString());
        totalTimeLabel->setText(QCoreApplication::translate("VideoClipDialog", "00:00", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VideoClipDialog: public Ui_VideoClipDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIP_H
