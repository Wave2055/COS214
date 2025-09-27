#include "ChatRoom.h"

/**
 *@brief Saves message to chat history

 *@param message Message to be saved
 *@param fromUser User who sent the message
 *
 *@note Assumes fromUser is a valid reference
 **/
void ChatRoom::saveMessage(std::string message, User *fromUser)
{
    this->chatHistory.push_back(fromUser->getName() + ": " + message);
}

/**
 *@brief Notifies other users in the chat room of a new message

 *@param message Message that was sent
 *@param fromUser User who sent the message
 *
 *@note Assumes fromUser is a valid reference
 *@note Does not notify user that sent message
 **/

void ChatRoom::sendMessage(std::string message, User *fromUser)
{
    for (User *user : this->users)
    {
        if (user != fromUser)
        {
            user->receive(message, fromUser, this);
        }
    }
}

void ChatRoom::registerUser(User *user)
{
    // TODO - implement ChatRoom::registerUser
    throw "Not yet implemented";
}

void ChatRoom::removeUser(User *user)
{
    // TODO - implement ChatRoom::removeUser
    throw "Not yet implemented";
}