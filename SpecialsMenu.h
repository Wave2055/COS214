#ifndef SPECIALSMENU_H
#define SPECIALSMENU_H

#include "Menus.h"

class SpecialsMenu : public Menus
{

public:
	SpecialsMenu(int time);
	void notifyObservers(std::string message);
	void switchState(int time);
};

#endif
