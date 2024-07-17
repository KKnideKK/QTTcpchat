#include "mythread.h"

myThread::myThread(QTcpSocket *s,QStandardItemModel *m)
{
    socket=s;
    model=m;
}
void myThread::run()
{
    connect(socket,&QTcpSocket::readyRead,this,&myThread::infothread);
    //将客户端ip，端口显示在表上
    ipItem = new QStandardItem(socket->peerAddress().toString());
    portItem = new QStandardItem(QString::number(socket->peerPort()));
    model->appendRow({ipItem, portItem});
    connect(socket, &QTcpSocket::disconnected, this,&myThread::onDisconnected);//断开清除IP，端口
}
void myThread::onDisconnected()
{

    int rowIndex = -1; // 初始化行索引为-1，表示尚未找到

    for (int i = 0; i < model->rowCount(); ++i) {
        for (int j = 0; j < model->columnCount(); ++j) {
            QStandardItem *item = model->item(i, j); // 获取第i行第j列的QStandardItem
            if (item == ipItem) {
                rowIndex = i; // 找到ipItem所在的行
                break; // 找到后退出内层循环
            }
            if (rowIndex != -1) break; // 如果已经找到ipItem，则退出外层循环（可选）
        }
        if (rowIndex != -1) break; // 同上
    }
    if (rowIndex != -1) {
        // 删除找到的行
        model->removeRow(rowIndex);
    }
}
void myThread::infothread()
{
    QByteArray be=socket->readAll();
    emit myThread::gettosocket(be);
}
