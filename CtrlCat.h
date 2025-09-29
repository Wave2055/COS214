#ifndef CTRLCAT_H
#define CTRLCAT_H

#include "ChatRoom.h"
#include "ConcreteIterator.h"

class CtrlCat : public ChatRoom
{

public:
	CtrlCat();

	~CtrlCat();

	std::string getName()
	{
		return this->name;
	}

	virtual Iterator *createIterator() const
	{
		return new ConcreteIterator(this);
	}
};

#endif
