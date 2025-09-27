#ifndef COMMAND_H
#define COMMAND_H

#include "ChatRoom.h"
#include "User.h"

class Command
{

protected:
	ChatRoom *room;
	std::string message;
	User *fromUser;

public:
	virtual void execute() = 0;
};

#endif
