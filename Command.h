#ifndef COMMAND_H
#define COMMAND_H

class Command {

protected:
	ChatRoom room;
	String message;
	User fromUser;

public:
	virtual void execute() = 0;
};

#endif
