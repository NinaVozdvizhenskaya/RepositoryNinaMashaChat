#ifndef MESSAGEHEADER_H
#define MESSAGEHEADER_H
#include <QTime>

struct MessageHeader
{
    enum class typeMessage: int
    {
        TEXT_MESSAGE  = 0, //текстовое сообщение
        WARNING_MESSAGE =1,
        ERROR_MESSAGE =2,
        NOTIFICATION_MESSAGE  =3,// уведомление
        SYSTEM_MESSAGE =4,
        AUTHORIZATION =5,
        HEARTBEAT = 6
    };


    unsigned char mesID;
    int numberPart;
    int tempPart;
    typeMessage type;



    explicit MessageHeader(unsigned char mID = 0,
                  typeMessage type = typeMessage::TEXT_MESSAGE,
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
