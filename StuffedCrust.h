#ifndef STUFFEDCRUST_H
#define STUFFEDCRUST_H

#include "PizzaDecorator.h"

class StuffedCrust : public PizzaDecorator
{

public:
	double getPrice();
	int getType();

	std::string getName();
	StuffedCrust(Pizza *p, double price);
	Pizza *getPizza();
};

#endif
