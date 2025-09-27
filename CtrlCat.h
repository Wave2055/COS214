#ifndef CTRLCAT_H
#define CTRLCAT_H

#include "ChatRoom.h"

class CtrlCat : public ChatRoom
{

public:
	CtrlCat();

	~CtrlCat();

	std::string getName()
	{
		return this->name;
	}
};

#endif
