#include "Memento.h"
#include <string>


Memento(string context, string sender, string timeStamp, string chatRoomName) 
: contextOfMessage(context), senderOfMessage(sender), timeStampOfMessage(timeStamp), nameOfChatRoom(chatRoomName) 
{

    time_t now = time(0);
    // Convert time to readable string format
    timestamp = ctime(&now);
    
    // Remove the newline character that ctime() adds at the end
    if (!timestamp.empty() && timestamp.back() == '\n') 
    {
        timestamp.pop_back();  // Remove the last character (newline)
    }

}

string getContext() const 
{

    return contextOfMessage;
}

string getSender() const 
{
    return senderOfMessage;
}

string getTimeStamp() const 
{
    return timeStampOfMessage;
}

string getChatRoomName() const 
{
    return nameOfChatRoom;
}

std::string MessageMemento::toString() const 
{
    return "[" + timestampOfMessage + "] " + senderOfMessage + " in " + nameOfChatRoom + ": " + contextOfMessage;
}