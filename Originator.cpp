#include "Memento.h"
#include "Originator.h"
#include "ChatRoom.h"
#include <iostream>
#include <memory>
#include <string>


Originator::Originator(ChatRoom* chatRoom, const std::string& chatRoomName)
    : room(chatRoom), ChatRoomName(chatRoomName)
{
    currentMessage = "";
    currentSender = "";
}

std::shared_ptr<Memento> Originator::saveMessageToMemento(const std::string& message, const std::string& sender) 
{
    
    currentMessage = message;  // Store the message content internally
    currentSender = sender;    // Store the sender's name internally
    
    // Create a new memento object with the current state
    return std::make_shared<Memento>(currentMessage, currentSender, chatRoomName);
}

void Originator::restoreMessageFromMemento(const std::shared_ptr<Memento>& memento) 
{
    if (memento) 
    {
        currentMessage = memento->getContext();  // Restore the message content from the memento
        currentSender = memento->getSender();    // Restore the sender's name from the memento
    }
    else 
    {
        std::cout << "Error: Invalid memento provided for restoration." << std::endl;
    }
}
string Originator::displayCurrentMessage() const 
{
    return currentMessage;
}
string Originator::displayCurrentSender() const 
{
    return currentSender;
}
string Originator::displayChatRoomName() const 
{
    return ChatRoomName;
}
void Originator::resendRestoredMessage() 
{
    if (room) 
    {
        room->sendMessage(currentMessage, currentSender);//method gotta be implemented in chatroom;
    } 
    else 
    {
        std::cout << "Error: No chat room associated with this originator." << std::endl;
    }
}