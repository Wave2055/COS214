#ifndef CHATROOM_H
#define CHATROOM_H

#include "User.h"
#include <string>

class User;

class ChatRoom
{

private:
	User *users;
	std::string *chatHistory;

public:
	virtual ~ChatRoom() = 0;

	virtual void registerUser(User user) = 0;

	virtual void sendMessage(std::string message, User fromUser) = 0;

	virtual void saveMessage(std::string message, User fromUser) = 0;

	virtual void removeUser(User user) = 0;
};

#endif
