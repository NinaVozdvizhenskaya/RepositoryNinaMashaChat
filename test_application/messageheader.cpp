#include "messageheader.h"
#include <iostream>
#include <QDataStream>
#include <QtEndian>
#include <cstring>

Message::Message(const Message::Type _type, const QByteArray &_payload, const quint32 _partCount, const quint32 _part)
    : type{_type},
      uuid{QUuid::createUuid()},
      partCount{_partCount},
      part{_part},
      payload{_payload}
{

}

Message::Message(const QByteArray &_serialized)
    :payload{_serialized.size() - 1 - 16 - 4 - 4, 0},
      partCount{0},
      part{0},
      type{Type::ERROR_MESSAGE}
{
    quint8 typeByte{0};
    std::memcpy(&typeByte, _serialized.data(), 1);
    type = static_cast<Type>(typeByte);
    QByteArray uuidArray{16, 0};
    std::memcpy(uuidArray.data(), _serialized.data() + 1, 16);
    uuid = QUuid::fromRfc4122(uuidArray);
    quint32 partCountBig{0};
    std::memcpy(&partCountBig, _serialized.data() + 1 + 16, 4);
    partCount = qFromBigEndian(partCountBig);
    quint32 partBig{0};
    std::memcpy(&partBig, _serialized.data() + 1 + 16 + 4, 4);
    part = qFromBigEndian(partBig);
    std::memcpy(payload.data(), _serialized.data() + 1 + 16 + 4 + 4, payload.size());
}

QByteArray Message::serialize() const
{
    QByteArray serialized{1 + 16 + 4 + 4 + payload.size(), 0};
    auto typeByte = static_cast<quint8>(type);
    std::memcpy(serialized.data(), &typeByte, sizeof(typeByte));
    const auto uuidArray = uuid.toRfc4122();
    std::memcpy(serialized.data() + 1, uuidArray.data(), uuidArray.size());
    const auto partCountBig = qToBigEndian(partCount);
    std::memcpy(serialized.data() + 1 + 16, &partCountBig, sizeof(partCountBig));
    const auto partBig = qToBigEndian(part);
    std::memcpy(serialized.data() + 1 + 16 + 4, &partBig, sizeof(partBig));
    std::memcpy(serialized.data() + 1 + 16 + 4 + 4, payload.data(), payload.size());
    return serialized;
}
