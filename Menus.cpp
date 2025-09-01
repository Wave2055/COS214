#include "Menus.h"

Menus::Menus()
{
	this->observes = {};
}

Menus::~Menus()
{
}

void Menus::addObserver(Observer *observer)
{
	if (observer)
	{
		this->observes.push_back(observer);
	}
}

void Menus::removeObserver(int index)
{
	if (index >= 0)
	{
		this->observes.erase(observes.begin() + index);
	}
}
