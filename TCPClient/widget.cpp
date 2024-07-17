#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    socket = new QTcpSocket;//创建socket对象
}

Widget::~Widget()
{
    delete ui;
}
void Widget::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return)
    {
        on_LJButton_clicked();
    }
}
void Widget::on_LJButton_clicked()
{
    QString ipdata=ui->ipEdit->text();//获取IP地址
    QString dkdata=ui->dkEdit->text();//获取端口号
    socket->connectToHost(QHostAddress(ipdata),dkdata.toShort());
    connect(socket,&QTcpSocket::connected,[this]()
            {
                QMessageBox::information(this,"连接提示","连接成功");
                this->hide();
                chat * c= new chat(socket);
                c->show();

            });//连接成功
    connect(socket,&QTcpSocket::disconnected,[this]()
            {
                QMessageBox::information(this,"连接提示","连接失败");
            });//连接失败
}

