#include "StuffedCrust.h"

StuffedCrust::StuffedCrust(Pizza *p, double price)
{
	this->pizza = p;
	this->price = price;
}

double StuffedCrust::getPrice()
{
	return this->pizza->getPrice() + this->price;
}

std::string StuffedCrust::getName()
{
	return "Stuffed Crust " + this->pizza->getName();
}

int StuffedCrust::getType()
{
	return 2;
}
