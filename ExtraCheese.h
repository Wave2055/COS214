#ifndef EXTRACHEESE_H
#define EXTRACHEESE_H

#include <string>

#include "PizzaDecorator.h"
#include "Pizza.h"

class ExtraCheese : PizzaDecorator
{

public:
	ExtraCheese(Pizza *p, double price);
	double getPrice();

	std::string getName();

private:
	double price;
};

#endif
