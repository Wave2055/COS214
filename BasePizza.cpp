#include "BasePizza.h"

BasePizza::BasePizza(PizzaComponent *toppings) : Pizza()
{
	if (toppings->getType() == 0)
	{
		this->toppings = new Topping(toppings->getName(), toppings->getPrice());
	}
	else if (toppings->getType() == 1)
	{
		ToppingGroup *temp = dynamic_cast<ToppingGroup *>(toppings);

		this->toppings = new ToppingGroup(temp->getName(), temp->getPrice(), temp->getToppings());
	}
	else
	{
		// throw an exception of some kind to notify them that an unrecognized object type is in the param toppings array
		// possibly illegalStateException
	}
}

BasePizza::~BasePizza()
{
	delete this->toppings;
}

double BasePizza::getPrice()
{
	return toppings->getPrice();
}

std::string BasePizza::getName()
{
	return toppings->getName();
}

int BasePizza::getType()
{
	return 0;
}
