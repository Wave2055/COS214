#include "Memento.h"
#include <string>

using std::string;

Memento::Memento(string context, User *sender, string timeStamp, string chatRoomName)
    : contextOfMessage(context), senderOfMessage(sender), timeStampOfMessage(timeStamp), nameOfChatRoom(chatRoomName)
{

    time_t now = time(0);
    // Convert time to readable string format
    timeStamp = ctime(&now);

    // Remove the newline character that ctime() adds at the end
    if (!timeStamp.empty() && timeStamp.back() == '\n')
    {
        timeStamp.pop_back(); // Remove the last character (newline)
    }
}

string Memento::getContext()
{

    return contextOfMessage;
}

User *Memento::getSender()
{
    return senderOfMessage;
}

string Memento::getTimeStamp()
{
    return timeStampOfMessage;
}

string Memento::getChatRoomName()
{
    return nameOfChatRoom;
}

std::string Memento::toString()
{
    return "[" + timeStampOfMessage + "] " + senderOfMessage->getName() + " in " + nameOfChatRoom + ": " + contextOfMessage;
}