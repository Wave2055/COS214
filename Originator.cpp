#include "Memento.h"
#include "Originator.h"
#include "ChatRoom.h"
#include "User.h"
#include <iostream>
#include <memory>
#include <string>
using std::string;

Originator::Originator(ChatRoom *chatRoom, const std::string &chatRoomName)
    : room(chatRoom), ChatRoomName(chatRoomName)
{
    currentMessage = "";
}

std::shared_ptr<Memento> Originator::saveMessageToMemento(const std::string &message, User *sender)
{

    currentMessage = message; // Store the message content internally
    currentSender = sender;   // Store the sender's name internally

    std::time_t now = std::time(nullptr);
    char buf[64];
    std::strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", std::localtime(&now));

    // Create a new memento object with the current state
    return std::make_shared<Memento>(currentMessage, currentSender, buf, ChatRoomName);
}

void Originator::restoreMessageFromMemento(const std::shared_ptr<Memento> &memento)
{
    if (memento)
    {
        currentMessage = memento->getContext(); // Restore the message content from the memento
        currentSender = memento->getSender();   // Restore the sender's name from the memento
    }
    else
    {
        std::cout << "Error: Invalid memento provided for restoration." << std::endl;
    }
}
std::string Originator::displayCurrentMessage() const
{
    return currentMessage;
}
User *Originator::displayCurrentSender() const
{
    return currentSender;
}
std::string Originator::displayChatRoomName() const
{
    return ChatRoomName;
}
void Originator::resendRestoredMessage()
{
    if (room)
    {
        room->sendMessage(currentMessage, currentSender); // method gotta be implemented in chatroom;
    }
    else
    {
        std::cout << "Error: No chat room associated with this originator." << std::endl;
    }
}