#include "udpview.h"
#include "ui_udpview.h"
#include <QTime>
#include "messageheader.h"

UDPView::UDPView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UDPView)

{
    ui->setupUi(this);

}

UDPView::~UDPView()
{
    delete ui;
}

void UDPView::set_input_message(QByteArray mesa, QString sender)
{
    QString mes;
    mes.append(QTime::currentTime().toString());
    mes.append(" ");
    mes.append(sender);
    mes.append(" ");
    qDebug()<<
    mes.append(QString::fromUtf8(mesa.data()));
    ui->ChatEdit->append(mes);

}

void UDPView::set_new_user(QString messa, QString sender)
{
    QString new_user;
    new_user.append(messa);
    new_user.append("  <");
    new_user.append(sender);
    new_user.append(" >");
    ui->Users->append(new_user);

    new_user.append( " появился в сети");

    QString msg;
    msg.append(QTime::currentTime().toString());
    msg.append(new_user);
    ui->ChatEdit->append(msg);

}

void UDPView::on_SendButton_2_clicked()
{

    QString message;
    message.append( ui->MessagelineEdit_2->text());
    if(message.size())
    {
        ui->MessagelineEdit_2->clear();

        QString mes;
        mes.append(QTime::currentTime().toString());
        mes.append(" ");
        mes.append(nick_name);
        mes.append(message);
        if(!ui->checkBox_2->isChecked())
        {
            client->sendDatagrams(QByteArray(message.toUtf8()));
        }

        ui->ChatEdit->append(mes);
    }




}



void UDPView::show_(QHostAddress _server, int _port, QByteArray _nick_name)
{
    client = new ClientUDP(_server,_port,_nick_name);
    QObject::connect(client, &ClientUDP::get_message, this, &UDPView::set_input_message);
    adr = _server;
    port = _port;
    nick_name = _nick_name;
    //Message authorization {Message::Type::AUTHORIZATION,_nick_name};
    //client->sendDatagrams(authorization.serialize());
    this->show();
    QString welcome;
    welcome.append(QTime::currentTime().toString());
    welcome.append(" ");
    welcome.append(QString::fromUtf8(_nick_name.data(),_nick_name.size()));
    welcome.append(" появился в сети ");
    ui->ChatEdit->setPlainText(welcome);
    ui->Users->setPlainText(QString::fromUtf8(_nick_name.data(),_nick_name.size()));
    QPalette palette;
    palette.setColor(QPalette::Text,Qt::gray);
    ui->SendButton_2->setPalette(palette);
    ui->MessagelineEdit_2->setText(QString(" Enter your message ..."));

}

void UDPView::on_MessagelineEdit_2_textChanged(const QString &arg1)
{
    QPalette palette;
    palette.setColor(QPalette::Text,Qt::black);
    ui->MessagelineEdit_2->setPalette(palette);

    if(arg1.size()) ui->SendButton_2->setEnabled(true);
}

void UDPView::on_MessagelineEdit_2_textEdited(const QString &arg1)
{
    QPalette palette;
    palette.setColor(QPalette::Text,Qt::black);
    ui->MessagelineEdit_2->setPalette(palette);
    if(arg1.size()) ui->SendButton_2->setEnabled(true);

}



void UDPView::on_checkBox_2_clicked(bool checked)
{
    if(checked)
    {
        server = new ServerUDP(port);
        QObject::connect(server, &ServerUDP::get_message, this, &UDPView::set_input_message);
        QObject::connect(server, &ServerUDP::add_user, this, &UDPView::set_new_user);
    }
}
