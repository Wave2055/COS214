#ifndef TOPPINGGROUP_H
#define TOPPINGGROUP_H

class ToppingGroup : PizzaComponent {

public:
	PizzaComponent* toppings;

	void add(PizzaComponent component);
};

#endif
