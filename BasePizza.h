#ifndef BASEPIZZA_H
#define BASEPIZZA_H

class BasePizza : Pizza {

public:
	PizzaComponent toppings;

	double getPrice();

	String getName();
};

#endif
