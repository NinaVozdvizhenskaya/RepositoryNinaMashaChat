// myudp.cpp

#include "myudp.h"
#include <QThread>
#define  IP "172.18.15.46"
#include <QAbstractSocket>

MyUDP::MyUDP(QObject *parent) :
    QObject(parent)
{

  socket = new QUdpSocket(this);

  socket->bind(1235);
  connect(socket,SIGNAL(readyRead()),this,SLOT(readPendingDatagrams()));

}

void MyUDP::HelloUDP()
{
    int counter=0;
    QHostAddress adr("172.18.15.46");
    QByteArray Data;
    Data.append(counter + ": Hello from NinaLOH");

    QThread::sleep(10);
    socket->writeDatagram(Data,  adr, 1234);
}

void MyUDP::readPendingDatagrams()
{

    while(socket->hasPendingDatagrams())
    {
        qDebug()<<"loh/n";
        QByteArray buffer;
        buffer.resize(socket->pendingDatagramSize());
        QHostAddress sender;
        quint16 senderPort;

        socket->readDatagram(buffer.data(), buffer.size(),&sender, &senderPort);

        qDebug() << "Message from: " << sender.toString();
        qDebug() << "Message port: " << senderPort;
        qDebug() << "Message: " << buffer;
    }

}
