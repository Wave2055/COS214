#include "BasePizza.h"

double BasePizza::getPrice()
{
	return toppings->getPrice();
}

std::string BasePizza::getName()
{
	return toppings->getName();
}
