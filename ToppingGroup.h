#ifndef TOPPINGGROUP_H
#define TOPPINGGROUP_H

#include "PizzaComponent.h"

#include <vector>

// my interpretation of topping group is a literal grouping of topings such as Vegetables, Meat, Cheese, etc
// Therefore we would use a Vector implementation to ensure that everything is managed correctly

class ToppingGroup : public PizzaComponent
{

private:
	std::vector<PizzaComponent *> toppings;
	int getType();

public:
	ToppingGroup(std::string name, double price, std::vector<PizzaComponent *> toppings = {});
	~ToppingGroup();
	void add(PizzaComponent *component);
};

#endif
