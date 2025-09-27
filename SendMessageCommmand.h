#ifndef SENDMESSAGECOMMMAND_H
#define SENDMESSAGECOMMMAND_H

#include "Command.h"

class SendMessageCommmand : public Command
{

public:
	SendMessageCommmand(ChatRoom *room, std::string message, User *fromUser) : Command(room, message, fromUser) {};
	void execute();
};

#endif
