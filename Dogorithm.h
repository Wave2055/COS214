#ifndef DOGORITHM_H
#define DOGORITHM_H

#include "ChatRoom.h"
#include "ConcreteIterator.h"

class Dogorithm : public ChatRoom
{

public:
	Dogorithm();

	~Dogorithm();

	std::string getName()
	{
		return this->name;
	}

	Iterator *createIterator() const
	{
		return new ConcreteIterator(this);
	}
};

#endif
