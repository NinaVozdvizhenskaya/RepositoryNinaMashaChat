#include <QCoreApplication>
#include "serverudp.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ServerUDP server;

    server.readPendingDatagrams();

    return a.exec();
}
