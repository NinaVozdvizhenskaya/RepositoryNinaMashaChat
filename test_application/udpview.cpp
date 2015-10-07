#include "udpview.h"
#include "ui_udpview.h"
#include <QTime>

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

void UDPView::set_input_message(QString mesa)
{
    QString mes;
    mes.append(QTime::currentTime().toString());
    mes.append(" ");
    mes.append(mesa);
    ui->ChatEdit->append(mes);

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
            client->sendDatagrams(message);
        }

        ui->ChatEdit->append(mes);
    }




}



void UDPView::show_(QHostAddress _server, int _port, QString _nick_name)
{
    client = new ClientUDP(_server,_port,_nick_name);
    QObject::connect(client, &ClientUDP::get_message, this, &UDPView::set_input_message);
    adr = _server;
    port = _port;
    nick_name = _nick_name;
    this->show();
    QString welcome;
    welcome.append(QTime::currentTime().toString());
    welcome.append(" ");
    welcome.append(_nick_name);
    welcome.append(" появился в сети");
    ui->ChatEdit->setPlainText(welcome);
    ui->Users->setPlainText(_nick_name);
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
    }
}
