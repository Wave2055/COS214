#ifndef EXTRACHEESE_H
#define EXTRACHEESE_H

#include <string>

#include "PizzaDecorator.h"
#include "Pizza.h"

class ExtraCheese : public PizzaDecorator
{

public:
	ExtraCheese(Pizza *p, double price);
	~ExtraCheese();
	double getPrice();
	int getType();
	Pizza *getPizza();

	std::string getName();
};

#endif
