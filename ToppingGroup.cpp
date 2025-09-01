#include "ToppingGroup.h"
#include "Topping.h"

ToppingGroup::ToppingGroup(std::string name, double price, std::vector<PizzaComponent *> toppings) : PizzaComponent(name, price)
{

	// uses get type function to deep copy the param toppings array should it exist
	if (toppings.size() > 0)
	{
		for (PizzaComponent *i : toppings)
		{
			if (i->getType() == 0)
			{
				this->toppings.push_back(new Topping(i->getName(), i->getPrice()));
			}
			else if (i->getType() == 1)
			{

				this->toppings.push_back(new ToppingGroup(name, price, toppings));
			}
			else
			{
				// throw an exception of some kind to notify them that an unrecognized object type is in the param toppings array
				// possibly illegalStateException
			}
		}
	}
}
ToppingGroup::~ToppingGroup()
{
	// Clean up all dynamically allocated toppings
	for (PizzaComponent *topping : toppings)
	{
		delete topping;
	}
	toppings.clear();
}

void ToppingGroup::add(PizzaComponent *component)
{
	if (component->getType() == 0)
	{
		this->toppings.push_back(new Topping(component->getName(), component->getPrice()));
	}
	else if (component->getType() == 1)
	{
		ToppingGroup *temp = dynamic_cast<ToppingGroup *>(component);

		if (temp != nullptr) // redundent null check
		{
			this->toppings.push_back(new ToppingGroup(temp->getName(), temp->getPrice(), temp->toppings));
		}
	}
	else
	{
		// throw an exception of some kind to notify them that an unrecognized object type is in the param toppings array
		// possibly illegalStateException
	}
}

int ToppingGroup::getType()
{
	return 1; // all topping group type =1;
}

double ToppingGroup::getPrice()
{
	double total = 0;

	for (PizzaComponent *c : this->toppings)
	{
		total += c->getPrice();
	}

	return total;
}

std::string ToppingGroup::getName()
{
	std::string out = "";

	for (PizzaComponent *c : this->toppings)
	{
		out += c->getName() + " ";
	}

	return out;
}

std::vector<PizzaComponent *> ToppingGroup::getToppings()
{
	return this->toppings;
}