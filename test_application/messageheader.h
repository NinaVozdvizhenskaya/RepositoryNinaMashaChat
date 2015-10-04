#ifndef MESSAGEHEADER_H
#define MESSAGEHEADER_H
#include <QTime>

struct MessageHeader
{
    enum typeMessage
    {
        TEXT_MESSAGE , //текстовое сообщение
        WARNING_MESSAGE,
        ERROR_MESSAGE,
        NOTIFICATION_MESSAGE,// уведомление
        SYSTEM_MESSAGE,
        AUTHORIZATION,
        HEARTBEAT
    };


    unsigned char mesID;
    int numberPart;
    int tempPart;
    typeMessage type;



    explicit MessageHeader(unsigned char mID = 0,
                  typeMessage type = TEXT_MESSAGE,
                  int numPart = 0,
                  int tempPart = 0 );


     friend QDataStream &operator <<(QDataStream &s, const MessageHeader &message);


};

struct Message
{
    MessageHeader mesHeader;
    QTime currentTime;
    QString data;
    explicit Message(MessageHeader _header, QTime _time, QString _data = "");
    friend QDataStream &operator <<(QDataStream &s, const Message &m);

};

#endif // MESSAGEHEADER_H
