#include "ChatRoom.h"

void ChatRoom::saveMessage(std::string message, User *fromUser)
{
    this->chatHistory.push_back(fromUser->getName() + ": " + message);
}

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
    if (user)
    {
        for (User *u : this->users)
        {
            if (u == user)
            {
                return; // User already registered
            }
        }
    }
    else if (user == nullptr)
    {
        return; // Null pointer, do nothing
    }

    this->users.push_back(user);
    user->registerChatRoom(this);
}

void ChatRoom::removeUser(User *user)
{
    for (int i = 0; i < this->users.size(); ++i)
    {
        User *u = this->users[i];
        {
            if (u == user)
            {
                this->users.erase(this->users.begin() + i);
                return; // User found and removed
            }
        }
    }
}