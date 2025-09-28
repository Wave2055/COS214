#include "User.h"

User::User(std::string name)
{
	this->chatRooms = std::vector<ChatRoom *>();
	this->name = name;
	this->commandQueue = std::vector<Command *>();
}

User::~User()
{
	if (!this->commandQueue.empty())
	{
		executeAll();
	} // ensures that any queued commands are executed before a user is destroyed
}

void User::send(std::string message, ChatRoom *room)
{
	Command *sendCommand = new SendMessageCommmand(room, message, this);
	this->addCommand(sendCommand);

	Command *logCommand = new LogMessageCommand(room, message, this);
	this->addCommand(logCommand);

	executeAll();
}

void User::receive(std::string messagee, User *fromUser, ChatRoom *room)
{
	// TODO - implement Users::receive
	throw "Not yet implemented";
}

void User::addCommand(Command *command)
{
	this->commandQueue.push_back(command);
}

void User::executeAll()
{
	for (Command *cmd : this->commandQueue)
	{
		cmd->execute();
	}

	for (Command *cmd : this->commandQueue)
	{
		if (cmd)
		{
			delete cmd;
		}
	}

	this->commandQueue.clear();
}
