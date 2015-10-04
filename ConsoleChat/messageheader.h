#ifndef MESSAGEHEADER_H
#define MESSAGEHEADER_H
#include <QTime>
#include <QString>



struct MessageHeader
{
    enum typeMessage
    {
        TEXT_MESSAGE, //текстовое сообщение
        WARNING_MESSAGE,
        ERROR_MESSAGE,
        NOTIFICATION_MESSAGE,
        SYSTEM_MESSAGE,
        AUTHORIZATION,
        HEARTBEAT
    };

    unsigned char mesID;
    int numberPart;
    int tempPart;
    typeMessage type;


    MessageHeader(unsigned char mID = 0, typeMessage type = TEXT_MESSAGE,
                  int numPart  = 0, int tempPart = 0 );

};

struct Message
{
MessageHeader mesHeader;
QTime currentTime;
QString data;
Message(MessageHeader _header, QTime _time, QString _data = "");
};

#endif // MESSAGEHEADER_H
