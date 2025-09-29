#ifndef MEMENTO_H
#define MEMENTO_H
#include <iostream>
#include <string>
#include "User.h"

class Memento
{
private:
    std::string contextOfMessage;
    User *senderOfMessage;
    std::string timeStampOfMessage;
    std::string nameOfChatRoom;

public:
    Memento(std::string context, User *sender, std::string timeStamp, std::string chatRoomName);
    std::string getContext();
    User *getSender();
    std::string getTimeStamp();
    std::string getChatRoomName();
    std::string toString();
};

#endif
