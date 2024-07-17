#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QObject>
#include <QThread>
#include <QTcpSocket>
#include <QDebug>
#include <QStandardItemModel>

class myThread : public QThread
{
    Q_OBJECT
public:
    explicit myThread(QTcpSocket *s,QStandardItemModel *m);
    void run();
signals:
    void gettosocket(QByteArray b);
private slots:
    void infothread();
    void onDisconnected();
private:
    QTcpSocket *socket ;
    QStandardItemModel *model;
    QStandardItem *ipItem;
    QStandardItem *portItem;
};

#endif // MYTHREAD_H
