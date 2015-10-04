// serverudp.cpp

#include "serverudp.h"
#include "messageheader.h"
#include <QString>
#include <QDataStream>
#include <QMap>
#include <iostream>



ServerUDP::ServerUDP(QObject *parent) :
    QObject(parent)
{
    socket = new QUdpSocket(this);  
    socket->bind(1234);
    connect(socket, SIGNAL(readyRead()), this, SLOT(readPendingDatagrams()));
}

QDataStream &operator <<(QDataStream &s, const MessageHeader &message)
{
    return s<<message.mesID<<message.numberPart<<message.tempPart<<message.type;
}

QDataStream &operator <<(QDataStream &s, const Message &message)
{
    return s<<message.mesHeader<<message.currentTime<<message.data;
}

void ServerUDP::respondToClient(QHostAddress &sender, quint16 port,MessageHeader &message)
{
    //message.type = NOTIFICATION_MESSAGE;
    QByteArray Data;
    QDataStream stream(&Data, QIODevice::WriteOnly);
    QTime time;
    Message mes(message, time.currentTime());
    stream << mes;
    socket->writeDatagram(Data, sender, port);
}



void ServerUDP::readPendingDatagrams()
{
    while(socket->hasPendingDatagrams())
    {
        qDebug()<<"readPendingDatagrams";
    QByteArray buffer;

    buffer.resize(socket->pendingDatagramSize());

    QHostAddress sender;
    quint16 senderPort;
    socket->readDatagram(buffer.data(), buffer.size(),&sender,&senderPort);

    Message *ClientMessage = reinterpret_cast<Message* >(buffer.data());
    qDebug()<<"1";
//    if(ClientMessage->mesHeader->type == AUTHORIZATION)
//    {
//        ClientMap::iterator iter = ClientList.insert(ClientMessage->data, sender);
//        if(iter == ClientList.end())
//             qDebug() <<"Error";
//    }
    qDebug()<<"2";
    qDebug() << "Message from: " << sender.toString();

    qDebug() << "Message port: " << senderPort;
    qDebug() << "Message: " << ClientMessage->mesHeader.mesID;
    qDebug() << "Message: " << ClientMessage->mesHeader.numberPart;
    qDebug() << "Message: " << ClientMessage->mesHeader.tempPart;
    qDebug() << "Message: " << ClientMessage->mesHeader.type;
    qDebug() << "Text " << ClientMessage->currentTime.hour()<<":"<<ClientMessage->currentTime.minute();
    respondToClient(sender, 1235, ClientMessage->mesHeader);

    }
}

void ServerUDP::ClientCheck()
{
    ClientMap::iterator iter = ClientList.begin();

    while (iter != ClientList.end())
    {
        QTime time;
        Message HBeatM(MessageHeader(1010, MessageHeader::HEARTBEAT), time.currentTime());
        QByteArray Data;
        QDataStream stream(&Data, QIODevice::WriteOnly);
        stream << HBeatM;
        socket->writeDatagram(Data, *iter, 1235);
        iter++;
    }
}
