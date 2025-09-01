#include "Menus.h"

Menus::Menus()
{
	this->observes = {};
	this->pizzas = {};
}

Menus::~Menus()
{
}

void Menus::addObserver(Observer *observer)
{
	if (observer)
	{
		this->observes.push_back(observer);
	}
}

void Menus::removeObserver(int index)
{
	if (index >= 0)
	{
		this->observes.erase(observes.begin() + index);
	}
}

void Menus::addPizza(Pizza *pizza)
{
	if (pizza)
	{
		this->pizzas.push_back(pizza);
	}
}

void Menus::removePizza(int index)
{
	if (index >= 0)
	{
		this->pizzas.erase(pizzas.begin() + index);
	}
}
