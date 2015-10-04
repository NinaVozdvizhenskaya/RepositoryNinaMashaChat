#include "messageheader.h"



MessageHeader::MessageHeader(unsigned char mID, typeMessage type, int numPart, int tempPart)
    : mesID(mID),
      numberPart(numPart),
      tempPart(tempPart),
      type(type)
{

}


Message::Message(MessageHeader _header, QTime _time, QString _data)
    : mesHeader( _header ),
    currentTime(_time),
    data(_data)

    {


    }
