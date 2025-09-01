#ifndef PIZZAMENU_H
#define PIZZAMENU_H

#include "Menus.h"

class PizzaMenu : public Menus
{

public:
	void notifyObservers(std::string message);

	PizzaMenu(int time);

	void switchState(int time);
};

#endif
