#include "Pizza.h"

Pizza::Pizza()
{
}

Pizza::~Pizza()
{
}

void Pizza::printPizzza()
{
	std::cout << "Pizza: " << this->getName() << " at price: " << this->getPrice();
}
