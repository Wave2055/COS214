#include "ExtraCheese.h"

ExtraCheese::ExtraCheese(Pizza *p, double price)
{
	this->pizza = p;
	this->price = price;
}

ExtraCheese::~ExtraCheese()
{
	// we dont wanna delete the pizza with the decorator it should be deallocated seperately
}

double ExtraCheese::getPrice()
{
	return this->pizza->getPrice() + this->price;
}

std::string ExtraCheese::getName()
{
	return "Extra Cheese " + this->pizza->getName();
}
