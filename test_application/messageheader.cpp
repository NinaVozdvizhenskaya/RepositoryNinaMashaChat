#include "messageheader.h"



/**/

MessageHeader::MessageHeader(unsigned char mID , typeMessage type , int numPart , int tempPart )
    : mesID(mID),
      numberPart(numPart),
      tempPart(tempPart),
      type(type)
{

}

QDataStream &operator <<(QDataStream &s, const MessageHeader &message)
{

     return s << message.mesID
              << message.numberPart
             << message.tempPart
            << static_cast<int>(message.type);
}


Message::Message(MessageHeader _header, QTime _time, QString _data)
    : mesHeader( _header ),
      currentTime(_time),
      data(_data)


{
       //mesHeader  = new MessageHeader();

}

QDataStream &operator <<(QDataStream &s, const Message &message)
{
     return s<<message.mesHeader<<message.currentTime<<message.data;
}
