#ifndef USERS_H
#define USERS_H

#include "ChatRoom.h"
#include "Command.h"

class User
{

protected:
	ChatRoom *chatRooms;
	std::string name;
	Command *commandQueue;

public:
	User(ChatRoom *chatRooms, std::string name, Command *commandQueue);

	~User();

	void send(std::string message, ChatRoom *room);

	void receive(std::string messagee, User *fromUser, ChatRoom *room);

	void addCommand(Command *command);

	void executeAll();

	std::string getName()
	{
		return this->name;
	}
};

#endif
