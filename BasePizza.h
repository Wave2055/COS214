#ifndef BASEPIZZA_H
#define BASEPIZZA_H

#include <vector>

#include "Pizza.h"
#include "PizzaComponent.h"
#include "Topping.h"
#include "ToppingGroup.h"

class BasePizza : public Pizza
{

public:
	PizzaComponent *toppings; // because of ToppingGroup being able to hold multiple toppings

	double getPrice();

	std::string getName(); // list all toppings before pizza name

	BasePizza(PizzaComponent *toppings);
	~BasePizza();
};

#endif
