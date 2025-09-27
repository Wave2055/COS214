#ifndef AYUSH_H
#define AYUSH_H

#include "User.h"

class Ayush : public User
{

public:
	Ayush(ChatRoom *chatRooms, std::string name, Command *commandQueue);

	~Ayush();
};

#endif
