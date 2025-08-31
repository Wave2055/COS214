#include "ExtraCheese.h"

double ExtraCheese::getPrice()
{
	return this->pizza->getPrice() + this->price;
}

String ExtraCheese::getName()
{
	// TODO - implement ExtraCheese::getName
	throw "Not yet implemented";
}
