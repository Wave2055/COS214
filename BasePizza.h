#ifndef BASEPIZZA_H
#define BASEPIZZA_H

#include <vector>

#include "Pizza.h"
#include "PizzaComponent.h"

class BasePizza : Pizza
{

public:
	PizzaComponent *toppings; // because of ToppingGroup being able to hold multiple toppings

	double getPrice();

	std::string getName(); // list all toppings before pizza name
};

#endif
