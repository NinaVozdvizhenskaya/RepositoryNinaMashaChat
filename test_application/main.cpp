#include <QCoreApplication>
#include "clientudp.h"
#include "serverudp.h"


class A{
public:
    A() = default;
    A(const A&) = delete;
};


int main(int argc, char* argv[])
{
QCoreApplication a(argc, argv);

    qDebug()<<argv[1];

    if(*argv[1] == '1')
    {
        qDebug()<<"client";
        ClientUDP client;
        client.sendDatagrams();
    }else
    {
        qDebug()<<"server";
        ServerUDP server;
        server.readPendingDatagrams();

    }

    return a.exec();
}
