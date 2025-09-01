#include "SpecialsMenu.h"

void SpecialsMenu::notifyObservers(std::string message)
{

	for (Observer *o : this->observes)
	{
		o->update(message);
	}
}
