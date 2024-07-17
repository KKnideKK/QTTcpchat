/********************************************************************************
** Form generated from reading UI file 'chat.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHAT_H
#define UI_CHAT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_chat
{
public:
    QLabel *label;
    QPushButton *toButton;
    QTextEdit *textEdit;
    QTextEdit *sendserverdata;

    void setupUi(QWidget *chat)
    {
        if (chat->objectName().isEmpty())
            chat->setObjectName("chat");
        chat->resize(569, 457);
        label = new QLabel(chat);
        label->setObjectName("label");
        label->setGeometry(QRect(230, 10, 111, 41));
        toButton = new QPushButton(chat);
        toButton->setObjectName("toButton");
        toButton->setGeometry(QRect(430, 420, 111, 31));
        textEdit = new QTextEdit(chat);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(10, 330, 541, 81));
        sendserverdata = new QTextEdit(chat);
        sendserverdata->setObjectName("sendserverdata");
        sendserverdata->setGeometry(QRect(10, 59, 541, 261));

        retranslateUi(chat);

        QMetaObject::connectSlotsByName(chat);
    } // setupUi

    void retranslateUi(QWidget *chat)
    {
        chat->setWindowTitle(QCoreApplication::translate("chat", "Form", nullptr));
        label->setText(QCoreApplication::translate("chat", "<html><head/><body><p align=\"center\"><span style=\" font-size:18pt; font-weight:700;\">\350\201\212\345\244\251\347\225\214\351\235\242</span></p></body></html>", nullptr));
        toButton->setText(QCoreApplication::translate("chat", "\345\217\221\351\200\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class chat: public Ui_chat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHAT_H
