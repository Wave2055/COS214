#ifndef MEMENTO_H
#define MEMENTO_H
#include <iostream>
#include <string>

class Memento {
private:
    std::string contextOfMessage;
    std::string senderOfMessage;
    std::string timeStampOfMessage;
    std::string nameOfChatRoom;

public:
    Memento(std::string context, std::string sender, std::string timeStamp, std::string chatRoomName);
    std::string getContext() const ;
    std::string getSender() const ;
    std::string getTimeStamp() const ;
    std::string getChatRoomName() const;
    std::string toString() const;
};

#endif
