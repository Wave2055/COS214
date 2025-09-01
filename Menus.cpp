#include "Menus.h"

Menus::Menus(int time)
{
	this->observes = {};

	this->menu = nullptr;

	// switchState(time);
}

Menus::~Menus()
{
	for (Observer *o : this->observes)
	{
		if (o)
		{
			delete o;
		}
	}

	delete menu;
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
