#include "chat.h"
#include "ui_chat.h"

chat::chat(QTcpSocket *s, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::chat)
{
    ui->setupUi(this);
    socket=s;
    connect(socket, &QTcpSocket::readyRead, this,&chat::on_sendserverdata_copyAvailable);
    ui->sendserverdata->setReadOnly(true);
}

chat::~chat()
{
    delete ui;
}
void chat::on_toButton_clicked()
{
    QByteArray buffer;
    buffer.append(ui->textEdit->toPlainText().toUtf8());
    socket->write(buffer);
    ui->textEdit->clear();
}
void chat::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return)
    {
        on_toButton_clicked();
    }
}
void chat::on_sendserverdata_copyAvailable()
{
    QByteArray data = socket->readAll(); // 读取所有待处理的数据
    ui->sendserverdata->append(data);
    // 在这里处理接收到的数据
}

