#ifndef MENUS_H
#define MENUS_H

#include <iostream>
#include <vector>

#include "Observer.h"
#include "Pizza.h"
#include "MenuTypes.h"

#include "BreakfastMenu.h"
#include "LunchMenu.h"
#include "DinnerMenu.h"

class Menus
{

protected:
	std::vector<Observer *> observes;
	MenuTypes *menu;

public:
	Menus(int time); // hour of time in 24hr time
	virtual ~Menus();

	void addObserver(Observer *observer);

	void removeObserver(int index);

	virtual void notifyObservers(std::string message) = 0;

	virtual void switchState(int time) = 0;
};

#endif
