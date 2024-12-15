/********************************************************************************
** Form generated from reading UI file 'edit.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDIT_H
#define UI_EDIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_EditDialog
{
public:
    QLineEdit *lineEdit_name;
    QLineEdit *lineEdit_plate;
    QLineEdit *lineEdit_home;
    QLineEdit *lineEdit_phone;
    QPushButton *pushButton_prev;
    QPushButton *pushButton_edit;
    QLabel *label_title;
    QLabel *label_name;
    QLabel *label_plate;
    QLabel *label_home;
    QLabel *label_phone;

    void setupUi(QDialog *EditDialog)
    {
        if (EditDialog->objectName().isEmpty())
            EditDialog->setObjectName("EditDialog");
        EditDialog->resize(480, 480);
        EditDialog->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 255, 255);\n"
"border:2px solid rgb(243,115,33);"));
        lineEdit_name = new QLineEdit(EditDialog);
        lineEdit_name->setObjectName("lineEdit_name");
        lineEdit_name->setGeometry(QRect(150, 150, 251, 31));
        lineEdit_name->setStyleSheet(QString::fromUtf8("	color:  rgb(0, 0, 0);\n"
"	background:white;\n"
"	border:1px solid rgb(243,115,33);\n"
"	font: 500 12pt \"Quicksand Medium\";"));
        lineEdit_plate = new QLineEdit(EditDialog);
        lineEdit_plate->setObjectName("lineEdit_plate");
        lineEdit_plate->setGeometry(QRect(150, 200, 251, 31));
        lineEdit_plate->setStyleSheet(QString::fromUtf8("	color:  rgb(0, 0, 0);\n"
"	background:white;\n"
"	border:1px solid rgb(243,115,33);\n"
"	font: 500 12pt \"Quicksand Medium\";"));
        lineEdit_home = new QLineEdit(EditDialog);
        lineEdit_home->setObjectName("lineEdit_home");
        lineEdit_home->setGeometry(QRect(150, 250, 251, 31));
        lineEdit_home->setStyleSheet(QString::fromUtf8("	color:  rgb(0, 0, 0);\n"
"	background:white;\n"
"	border:1px solid rgb(243,115,33);\n"
"	font: 500 12pt \"Quicksand Medium\";"));
        lineEdit_phone = new QLineEdit(EditDialog);
        lineEdit_phone->setObjectName("lineEdit_phone");
        lineEdit_phone->setGeometry(QRect(150, 300, 251, 31));
        lineEdit_phone->setStyleSheet(QString::fromUtf8("	color:  rgb(0, 0, 0);\n"
"	background:white;\n"
"	border:1px solid rgb(243,115,33);\n"
"	font: 500 12pt \"Quicksand Medium\";"));
        pushButton_prev = new QPushButton(EditDialog);
        pushButton_prev->setObjectName("pushButton_prev");
        pushButton_prev->setGeometry(QRect(80, 360, 150, 30));
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
        pushButton_edit = new QPushButton(EditDialog);
        pushButton_edit->setObjectName("pushButton_edit");
        pushButton_edit->setGeometry(QRect(240, 360, 150, 30));
        pushButton_edit->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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
        label_title = new QLabel(EditDialog);
        label_title->setObjectName("label_title");
        label_title->setGeometry(QRect(0, 50, 481, 61));
        label_title->setStyleSheet(QString::fromUtf8("	color:  rgb(243,115,33);\n"
"	background-color: rgba(243,115,33,0.3);\n"
"	border:none;\n"
"	font: 500 9pt \"Quicksand Medium\";"));
        label_title->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_name = new QLabel(EditDialog);
        label_name->setObjectName("label_name");
        label_name->setGeometry(QRect(70, 150, 71, 31));
        label_name->setStyleSheet(QString::fromUtf8("	color:  rgb(243,115,33);\n"
"	background-color: none;\n"
"	border:none;\n"
"	font: 500 9pt \"Quicksand Medium\";"));
        label_plate = new QLabel(EditDialog);
        label_plate->setObjectName("label_plate");
        label_plate->setGeometry(QRect(70, 200, 71, 31));
        label_plate->setStyleSheet(QString::fromUtf8("	color:  rgb(243,115,33);\n"
"	background-color: none;\n"
"	border:none;\n"
"	font: 500 9pt \"Quicksand Medium\";"));
        label_home = new QLabel(EditDialog);
        label_home->setObjectName("label_home");
        label_home->setGeometry(QRect(70, 250, 71, 31));
        label_home->setStyleSheet(QString::fromUtf8("	color:  rgb(243,115,33);\n"
"	background-color: none;\n"
"	border:none;\n"
"	font: 500 9pt \"Quicksand Medium\";"));
        label_phone = new QLabel(EditDialog);
        label_phone->setObjectName("label_phone");
        label_phone->setGeometry(QRect(60, 300, 81, 31));
        label_phone->setStyleSheet(QString::fromUtf8("	color:  rgb(243,115,33);\n"
"	background-color: none;\n"
"	border:none;\n"
"	font: 500 9pt \"Quicksand Medium\";"));

        retranslateUi(EditDialog);

        QMetaObject::connectSlotsByName(EditDialog);
    } // setupUi

    void retranslateUi(QDialog *EditDialog)
    {
        EditDialog->setWindowTitle(QCoreApplication::translate("EditDialog", "Dialog", nullptr));
        lineEdit_name->setPlaceholderText(QCoreApplication::translate("EditDialog", "type your name", nullptr));
        lineEdit_plate->setPlaceholderText(QCoreApplication::translate("EditDialog", "type your plate number", nullptr));
        lineEdit_home->setPlaceholderText(QCoreApplication::translate("EditDialog", "type your home address", nullptr));
        lineEdit_phone->setPlaceholderText(QCoreApplication::translate("EditDialog", "type your phone number", nullptr));
        pushButton_prev->setText(QCoreApplication::translate("EditDialog", "PREV", nullptr));
        pushButton_edit->setText(QCoreApplication::translate("EditDialog", "EDIT", nullptr));
        label_title->setText(QCoreApplication::translate("EditDialog", "<html><head/><body><p><span style=\" font-size:26pt; font-weight:700;\">EDIT</span></p></body></html>", nullptr));
        label_name->setText(QCoreApplication::translate("EditDialog", "<html><head/><body><p><span style=\" font-size:18pt; font-weight:700;\">NAME</span></p></body></html>", nullptr));
        label_plate->setText(QCoreApplication::translate("EditDialog", "<html><head/><body><p><span style=\" font-size:18pt; font-weight:700;\">PLATE</span></p></body></html>", nullptr));
        label_home->setText(QCoreApplication::translate("EditDialog", "<html><head/><body><p><span style=\" font-size:18pt; font-weight:700;\">HOME</span></p></body></html>", nullptr));
        label_phone->setText(QCoreApplication::translate("EditDialog", "<html><head/><body><p><span style=\" font-size:18pt; font-weight:700;\">PHONE</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EditDialog: public Ui_EditDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDIT_H
