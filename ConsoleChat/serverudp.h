// serverudp.h

#ifndef SERVERUDP_H
#define SERVERUDP_H

#include <QObject>
#include <QUdpSocket>
#include <QMap>
//#include "messageheader.h"
struct MessageHeader;
struct Message;

class ServerUDP : public QObject
{
    Q_OBJECT
    typedef QMap <QString, QHostAddress> ClientMap;
private:
    void ClientCheck();
public:
    explicit ServerUDP(QObject *parent = 0);
    void respondToClient(QHostAddress &sender, quint16 port, MessageHeader &message);
    friend QDataStream &operator <<(QDataStream &s, const MessageHeader &message);
    friend QDataStream &operator <<(QDataStream &s, const Message &message);
signals:

public slots:
    void readPendingDatagrams();

private:
    QUdpSocket *socket;
    ClientMap ClientList;


};

#endif // MYUDP_H
