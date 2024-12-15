/********************************************************************************
** Form generated from reading UI file 'enroll.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENROLL_H
#define UI_ENROLL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_EnrollDialog
{
public:
    QLineEdit *lineEdit_name;
    QLineEdit *lineEdit_plate;
    QLineEdit *lineEdit_home;
    QLineEdit *lineEdit_phone;
    QPushButton *pushButton_prev;
    QPushButton *pushButton_enroll;
    QLabel *label_title;
    QLabel *label_name;
    QLabel *label_plate;
    QLabel *label_home;
    QLabel *label_phone;

    void setupUi(QDialog *EnrollDialog)
    {
        if (EnrollDialog->objectName().isEmpty())
            EnrollDialog->setObjectName("EnrollDialog");
        EnrollDialog->resize(480, 480);
        EnrollDialog->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 255, 255);\n"
"border:2px solid rgb(243,115,33);"));
        lineEdit_name = new QLineEdit(EnrollDialog);
        lineEdit_name->setObjectName("lineEdit_name");
        lineEdit_name->setGeometry(QRect(140, 140, 271, 31));
        lineEdit_name->setStyleSheet(QString::fromUtf8("	color:  rgb(0, 0, 0);\n"
"	background:white;\n"
"	border:1px solid rgb(243,115,33);\n"
"	font: 500 12pt \"Quicksand Medium\";"));
        lineEdit_plate = new QLineEdit(EnrollDialog);
        lineEdit_plate->setObjectName("lineEdit_plate");
        lineEdit_plate->setGeometry(QRect(140, 190, 271, 31));
        lineEdit_plate->setStyleSheet(QString::fromUtf8("	color:  rgb(0, 0, 0);\n"
"	background:white;\n"
"	border:1px solid rgb(243,115,33);\n"
"	font: 500 12pt \"Quicksand Medium\";"));
        lineEdit_home = new QLineEdit(EnrollDialog);
        lineEdit_home->setObjectName("lineEdit_home");
        lineEdit_home->setGeometry(QRect(140, 240, 271, 31));
        lineEdit_home->setStyleSheet(QString::fromUtf8("	color:  rgb(0, 0, 0);\n"
"	background:white;\n"
"	border:1px solid rgb(243,115,33);\n"
"	font: 500 12pt \"Quicksand Medium\";"));
        lineEdit_phone = new QLineEdit(EnrollDialog);
        lineEdit_phone->setObjectName("lineEdit_phone");
        lineEdit_phone->setGeometry(QRect(140, 290, 271, 31));
        lineEdit_phone->setStyleSheet(QString::fromUtf8("	color:  rgb(0, 0, 0);\n"
"	background:white;\n"
"	border:1px solid rgb(243,115,33);\n"
"	font: 500 12pt \"Quicksand Medium\";"));
        pushButton_prev = new QPushButton(EnrollDialog);
        pushButton_prev->setObjectName("pushButton_prev");
        pushButton_prev->setGeometry(QRect(80, 370, 150, 30));
        pushButton_prev->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	font: 300 bold 13pt \"Quicksand Light\";\n"
"	color:  rgb(243,115,33);\n"
"	background:rgba(243,115,33,0.2);\n"
"	border:1px solid rgb(243,115,33);\n"
"}\n"
"QPushButton:hover {\n"
"	color:  rgb(255, 255, 255);\n"
"	background-color:rgba(243,115,33,0.3);\n"
"	border:1px solid rgb(243,115,33);\n"
"	font: 500 12pt \"Quicksand Medium\";\n"
"}"));
        pushButton_enroll = new QPushButton(EnrollDialog);
        pushButton_enroll->setObjectName("pushButton_enroll");
        pushButton_enroll->setGeometry(QRect(240, 370, 151, 31));
        pushButton_enroll->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	font: 300 bold 13pt \"Quicksand Light\";\n"
"	color:  rgb(243,115,33);\n"
"	background:rgba(243,115,33,0.2);\n"
"	border:1px solid rgb(243,115,33);\n"
"}\n"
"QPushButton:hover {\n"
"	color:  rgb(255, 255, 255);\n"
"	background-color:rgba(243,115,33,0.3);\n"
"	border:1px solid rgb(243,115,33);\n"
"	font: 500 12pt \"Quicksand Medium\";\n"
"}"));
        label_title = new QLabel(EnrollDialog);
        label_title->setObjectName("label_title");
        label_title->setGeometry(QRect(0, 40, 481, 51));
        label_title->setStyleSheet(QString::fromUtf8("	color:  rgb(243,115,33);\n"
"	background-color: rgba(243,115,33,0.3);\n"
"	border:none;\n"
"	font: 500 9pt \"Quicksand Medium\";"));
        label_title->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_name = new QLabel(EnrollDialog);
        label_name->setObjectName("label_name");
        label_name->setGeometry(QRect(60, 140, 71, 31));
        label_name->setStyleSheet(QString::fromUtf8("	color:  rgb(243,115,33);\n"
"	background-color: none;\n"
"	border:none;\n"
"	font: 500 9pt \"Quicksand Medium\";"));
        label_plate = new QLabel(EnrollDialog);
        label_plate->setObjectName("label_plate");
        label_plate->setGeometry(QRect(60, 190, 71, 31));
        label_plate->setStyleSheet(QString::fromUtf8("	color:  rgb(243,115,33);\n"
"	background-color: none;\n"
"	border:none;\n"
"	font: 500 9pt \"Quicksand Medium\";"));
        label_home = new QLabel(EnrollDialog);
        label_home->setObjectName("label_home");
        label_home->setGeometry(QRect(60, 240, 71, 31));
        label_home->setStyleSheet(QString::fromUtf8("	color:  rgb(243,115,33);\n"
"	background-color: none;\n"
"	border:none;\n"
"	font: 500 9pt \"Quicksand Medium\";"));
        label_phone = new QLabel(EnrollDialog);
        label_phone->setObjectName("label_phone");
        label_phone->setGeometry(QRect(50, 290, 81, 31));
        label_phone->setStyleSheet(QString::fromUtf8("	color:  rgb(243,115,33);\n"
"	background-color: none;\n"
"	border:none;\n"
"	font: 500 9pt \"Quicksand Medium\";"));

        retranslateUi(EnrollDialog);

        QMetaObject::connectSlotsByName(EnrollDialog);
    } // setupUi

    void retranslateUi(QDialog *EnrollDialog)
    {
        EnrollDialog->setWindowTitle(QCoreApplication::translate("EnrollDialog", "Dialog", nullptr));
        lineEdit_name->setPlaceholderText(QCoreApplication::translate("EnrollDialog", "type your name", nullptr));
        lineEdit_plate->setPlaceholderText(QCoreApplication::translate("EnrollDialog", "type your plate number", nullptr));
        lineEdit_home->setPlaceholderText(QCoreApplication::translate("EnrollDialog", "type your home address", nullptr));
        lineEdit_phone->setPlaceholderText(QCoreApplication::translate("EnrollDialog", "type your phone number", nullptr));
        pushButton_prev->setText(QCoreApplication::translate("EnrollDialog", "prev", nullptr));
        pushButton_enroll->setText(QCoreApplication::translate("EnrollDialog", "enroll", nullptr));
        label_title->setText(QCoreApplication::translate("EnrollDialog", "<html><head/><body><p><span style=\" font-size:26pt; font-weight:700;\">ENROLL</span></p></body></html>", nullptr));
        label_name->setText(QCoreApplication::translate("EnrollDialog", "<html><head/><body><p><span style=\" font-size:18pt; font-weight:700;\">NAME</span></p></body></html>", nullptr));
        label_plate->setText(QCoreApplication::translate("EnrollDialog", "<html><head/><body><p><span style=\" font-size:18pt; font-weight:700;\">PLATE</span></p></body></html>", nullptr));
        label_home->setText(QCoreApplication::translate("EnrollDialog", "<html><head/><body><p><span style=\" font-size:18pt; font-weight:700;\">HOME</span></p></body></html>", nullptr));
        label_phone->setText(QCoreApplication::translate("EnrollDialog", "<html><head/><body><p><span style=\" font-size:18pt; font-weight:700;\">PHONE</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EnrollDialog: public Ui_EnrollDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENROLL_H
