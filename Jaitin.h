#ifndef JAITIN_H
#define JAITIN_H

#include "User.h"

class Jaitin : public User
{

public:
	Jaitin(ChatRoom *chatRooms, std::string name, Command *commandQueue);

	~Jaitin();
};

#endif
