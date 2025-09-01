#include "Menus.h"

Menus::Menus(int time)
{
	this->observes = {};

	this->menu = nullptr;

	switchState(time);
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

void Menus::switchState(int time)
{
	if (time < 0 || time > 24)
	{
		return;
	}

	if (this->menu)
	{
		delete menu;
	}

	if (time > 5 && time <= 10)
	{
		menu = new BreakfastMenu();
		notifyObservers("Breakfast Menu is now available");
	}
	else if (time > 10 && time <= 17)
	{
		menu = new LunchMenu();
		notifyObservers("Lunch Menu is now available");
	}
	else if ((time > 17 && time <= 24) || time > 0 && time <= 5)
	{
		menu = new DinnerMenu();
		notifyObservers("Dinner Menu is now available");
	}
}
