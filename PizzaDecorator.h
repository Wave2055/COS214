#ifndef PIZZADECORATOR_H
#define PIZZADECORATOR_H

#include <string>

#include "Pizza.h"

class PizzaDecorator : public Pizza
{

public:
	virtual double getPrice();

	virtual std::string getName();

protected:
	Pizza *pizza;
	double price;
};

#endif
