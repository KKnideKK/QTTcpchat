#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //监听
    server=new QTcpServer;
    server->listen(QHostAddress::AnyIPv4,FDK);
    //初始化ip，端口表
    model = new QStandardItemModel(0, 2, ui->tableView);
    model->setHorizontalHeaderLabels(QStringList() << "IP" << "Port");
    ui->tableView->setModel(model);
    ui->tableView->setColumnWidth(0, 110); // 设置第一列的宽度为100
    ui->tableView->setColumnWidth(1, 70); // 设置第二列的宽度为200
    //有客户端连接则触发
    connect(server,&QTcpServer::newConnection,this,&Widget::servernewget);
}
Widget::~Widget()
{
    server->close();
    qDeleteAll(connectedSockets.begin(), connectedSockets.end());
    delete ui;
}
void Widget::servernewget()
{
    QTcpSocket *socket=server->nextPendingConnection();
    //显示连接时间
    QDateTime current = QDateTime::currentDateTime();
    QString currentDateTimeString = "客户端"+socket->peerAddress().toString()+"："+current.toString("yyyy-MM-dd hh:mm:ss")+"连接";
    ui->gettextEdit->append(currentDateTimeString);
    //connect(socket,&QTcpSocket::readyRead,this,&Widget::gettext);
    // 将新连接的socket添加到列表中
    QMutexLocker locker(&socketMutex);
    connectedSockets.append(socket);
    //启动线程
    myThread *t=new myThread(socket,model);//创建线程对象
    t->start();
    connect(t,&myThread::gettosocket,this,&Widget::threadget);
    connect(socket, &QTcpSocket::disconnected, this, [this, socket]() {//客户端断开
        QDateTime current = QDateTime::currentDateTime();
        QString currentDateTimeString = "客户端"+socket->peerAddress().toString()+"："+current.toString("yyyy-MM-dd hh:mm:ss")+"断开";
        ui->gettextEdit->append(currentDateTimeString);
        QMutexLocker locker(&socketMutex);
        connectedSockets.removeAll(socket);
    });

}

void Widget::threadget(QByteArray b)
{
    ui->gettextEdit->append(QString(b));
    // 广播数据给所有客户端
    broadcastData(b);
}
void Widget::broadcastData(const QByteArray &data)
{
    QMutexLocker locker(&socketMutex);
    for (QTcpSocket *socket : connectedSockets) {
        if (socket->state() == QAbstractSocket::ConnectedState) {
            socket->write(data);
        }
    }
}
