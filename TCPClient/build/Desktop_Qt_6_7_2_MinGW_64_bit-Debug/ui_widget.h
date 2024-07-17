/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *label;
    QLineEdit *ipEdit;
    QLineEdit *dkEdit;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *LJButton;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(493, 386);
        label = new QLabel(Widget);
        label->setObjectName("label");
        label->setGeometry(QRect(190, 10, 111, 51));
        ipEdit = new QLineEdit(Widget);
        ipEdit->setObjectName("ipEdit");
        ipEdit->setGeometry(QRect(200, 120, 211, 41));
        dkEdit = new QLineEdit(Widget);
        dkEdit->setObjectName("dkEdit");
        dkEdit->setGeometry(QRect(200, 190, 211, 41));
        label_2 = new QLabel(Widget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(90, 130, 101, 21));
        label_3 = new QLabel(Widget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(90, 200, 91, 21));
        LJButton = new QPushButton(Widget);
        LJButton->setObjectName("LJButton");
        LJButton->setGeometry(QRect(10, 260, 481, 41));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        label->setText(QCoreApplication::translate("Widget", "<html><head/><body><p align=\"center\"><span style=\" font-size:18pt; font-weight:700;\">\345\256\242\346\210\267\347\253\257</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "<html><head/><body><p align=\"center\"><span style=\" font-size:11pt;\">\346\234\215\345\212\241\345\231\250IP\345\234\260\345\235\200</span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "<html><head/><body><p align=\"center\"><span style=\" font-size:11pt;\">\346\234\215\345\212\241\345\231\250\347\253\257\345\217\243\345\217\267</span></p></body></html>", nullptr));
        LJButton->setText(QCoreApplication::translate("Widget", "\350\277\236\346\216\245", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
