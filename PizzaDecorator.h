#ifndef PIZZADECORATOR_H
#define PIZZADECORATOR_H

class PizzaDecorator : Pizza {

public:
	Pizza pizza;

	double getPrice();

	String getName();
};

#endif
