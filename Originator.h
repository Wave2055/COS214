#ifndef ORIGINATOR_H
#define ORIGINATOR_H

#include <iostream>
#include <memory>
#include<string>

class Memento; // Forward declaration
class ChatRoom; // Forward declaration


class Originator {
private:
    ChatRoom* room;
    std::string currentMessage;
    std::string currentSender;
    std::string ChatRoomName;

public:
    Originator(ChatRoom* chatRoom, const string& chatRoomName);
    std::shared_ptr<Memento> saveMessageToMemento(const std::string& message, const std::string& sender);
    void restoreMessageFromMemento(const std::shared_ptr<Memento>& memento);
    std::string displayCurrentMessage() const;
    std::string displayCurrentSender() const;
    std::string displayChatRoomName() const;
    void resendRestoredMessage();

   
   
    
};

#endif
