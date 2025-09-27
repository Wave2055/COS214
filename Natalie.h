#ifndef NATALIE_H
#define NATALIE_H

#include "User.h"

class Natalie : public User
{

public:
	Natalie(ChatRoom *chatRooms, std::string name, Command *commandQueue);

	~Natalie();
};

#endif
