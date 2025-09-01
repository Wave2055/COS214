#include "SpecialsMenu.h"

SpecialsMenu::SpecialsMenu(int time) : Menus(time)
{
}

void SpecialsMenu::notifyObservers(std::string message)
{

	for (Observer *o : this->observes)
	{
		o->update(message);
	}
}

void SpecialsMenu::switchState(int time)
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