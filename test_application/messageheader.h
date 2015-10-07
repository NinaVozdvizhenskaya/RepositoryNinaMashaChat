#ifndef MESSAGEHEADER_H
#define MESSAGEHEADER_H

#include <QUuid>


class Message
{
public:
    enum class Type: quint8
    {
        TEXT_MESSAGE  = 0, //текстовое сообщение
        WARNING_MESSAGE =1,
        ERROR_MESSAGE =2,
        NOTIFICATION_MESSAGE  =3,// уведомление
        SYSTEM_MESSAGE =4,
        AUTHORIZATION =5,
        HEARTBEAT = 6
    };




    explicit Message(const Type _type = Type::TEXT_MESSAGE,
                     const QByteArray &_payload = "",
                     const quint32 _partCount = 1,
                     const quint32 _part = 0);
    explicit Message(const QByteArray &_serialized);
    QByteArray serialize() const;

    const QByteArray &getPayload() const {
        return payload;
    }
    const Type& getType() const {
        return type;
    }

private:
    Type type;
    QUuid uuid;
    quint32 partCount;
    quint32 part;

    QByteArray payload;
};

#endif // MESSAGEHEADER_H
