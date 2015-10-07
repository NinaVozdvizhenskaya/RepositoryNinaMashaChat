#include "autorizationwindows.h"
#include "ui_autorizationwindows.h"
#include "ui_udpview.h"
#include <QHostInfo>


AutorizationWindows::AutorizationWindows(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AutorizationWindows)

{
    parent = new QWidget;

    port = 0;
    ui->setupUi(this);

}

AutorizationWindows::~AutorizationWindows()
{
    delete ui;
}

QHostAddress AutorizationWindows::get_server()
{
    return server;
}

int AutorizationWindows::get_port()
{
    return port;
}

QString AutorizationWindows::get_nickneme()
{
    return nick_name;
}







void AutorizationWindows::on_server_editingFinished()
{
    QHostInfo hostInfo = QHostInfo::fromName(ui->server->text());
    QPalette palette;
    if (hostInfo.error() != QHostInfo::NoError)
    {
        palette.setColor(QPalette::Text,Qt::red);
        ui->server->setPalette(palette);
        isServer  = false;
        ui->connect->setEnabled(false);

    }
    if(hostInfo.error() == QHostInfo::NoError)
    {
        palette.setColor(QPalette::Text,Qt::black);
        ui->server->setPalette(palette);
        server = hostInfo.addresses().first();
        ui->server->setPlaceholderText(server.toString());
        qDebug()<<server.toString();
        isServer =  true;
        if(port>100) ui->connect->setEnabled(true);
    }

}

void AutorizationWindows::on_nickname_editingFinished()
{
    nick_name = QString(ui->nickname->text());
}

void AutorizationWindows::on_spinBox_editingFinished()
{
    port= ui->spinBox->text().toInt();
    if(port>100 && isServer) {
        qDebug()<<"set enable";
        ui->connect->setEnabled(true);
    }

}

void AutorizationWindows::on_connect_clicked()
{
    exit_(server,port,nick_name);
    this->close();
}
