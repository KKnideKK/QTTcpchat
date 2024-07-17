#ifndef WIDGET_H
#define WIDGET_H
#define FDK 8000//端口号
#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <mythread.h>
#include <QThread>
#include <QDateTime>
#include <QMutexLocker>
QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
private slots:
    void servernewget();
    //void gettext();
    void threadget(QByteArray b);
    void broadcastData(const QByteArray &data);

private:
    Ui::Widget *ui;
    QTcpServer *server;
    QStandardItemModel *model;
    QList<QTcpSocket*> connectedSockets; // 存储所有连接的socket
    QMutex socketMutex; // 用于保护connectedSockets的互斥锁
};
#endif // WIDGET_H
