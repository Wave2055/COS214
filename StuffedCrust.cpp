#include "StuffedCrust.h"

double StuffedCrust::getPrice()
{
	return this->pizza->getPrice() + this->price;
}

std::string StuffedCrust::getName()
{
	return "Stuffed Crust " + this->pizza->getName();
}
