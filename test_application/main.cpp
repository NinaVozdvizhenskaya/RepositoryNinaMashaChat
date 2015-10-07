
#include "clientudp.h"
#include "serverudp.h"
#include <QApplication>
#include "udpview.h"
#include "autorizationwindows.h"
#include "messageheader.h"
#include <QDebug>

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
//chat_window.show();
QObject::connect( &autorization_window, &AutorizationWindows::exit_,  &chat_window, &UDPView::show_);
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

//    }*/

//----------------------------------------------------------------------------------------------------
//    Message message{Message::Type::TEXT_MESSAGE, QByteArray(QString{"Hello chat"}.toUtf8())};
//    QByteArray serialized{message.serialize()};

//    Message deserialized{serialized};

//    qDebug() <<QString::fromUtf8(deserialized.getPayload().data(), deserialized.getPayload().size());
//------------------------------------------------------------------------------------------------------
 //   return 0;
}
