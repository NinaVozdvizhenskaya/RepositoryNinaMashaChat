
#include "clientudp.h"
#include "serverudp.h"
#include <QApplication>
#include "udpview.h"
#include "autorizationwindows.h"

class A{
public:
    A() = default;
    A(const A&) = delete;
};


int main(int argc, char* argv[])
{

QApplication a(argc, argv);


AutorizationWindows autorization_window;
UDPView chat_window;
autorization_window.show();
QObject::connect( &autorization_window, &AutorizationWindows::exit_,  &chat_window, &UDPView::show_);








return a.exec();

//    qDebug()<<argv[1];

//    if(*argv[1] == '1')
//    {
//        qDebug()<<"client";
//        ClientUDP client;
//        client.sendDatagrams();
//    }else
//    {
//        qDebug()<<"server";
//        ServerUDP server;
//        server.readPendingDatagrams();

//    }

 //   return a.exec();
}
