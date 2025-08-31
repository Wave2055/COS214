#ifndef PIZZADECORATOR_H
#define PIZZADECORATOR_H

#include <string>

#include "Pizza.h"

class PizzaDecorator : Pizza
{

public:
	virtual double getPrice();

	virtual std::string getName();

protected:
	Pizza *pizza;
};

#endif
