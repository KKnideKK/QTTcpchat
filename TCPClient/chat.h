#ifndef CHAT_H
#define CHAT_H

#include <QWidget>
#include <QTcpSocket>
#include <QKeyEvent>

namespace Ui {
class chat;
}

class chat : public QWidget
{
    Q_OBJECT

public:
    explicit chat(QTcpSocket *s,QWidget *parent = nullptr);
    ~chat();

    void keyPressEvent(QKeyEvent *event);

private slots:
    void on_toButton_clicked();
    void on_sendserverdata_copyAvailable();

private:
    Ui::chat *ui;
    QTcpSocket *socket;
};

#endif // CHAT_H
