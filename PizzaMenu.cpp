#include "PizzaMenu.h"

void PizzaMenu::notifyObservers(std::string message)
{

	for (Observer *o : this->observes)
	{
		o->update(message);
	}
}
