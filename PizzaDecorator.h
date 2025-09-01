#ifndef PIZZADECORATOR_H
#define PIZZADECORATOR_H

#include <string>

#include "Pizza.h"

class PizzaDecorator : public Pizza
{

public:
	virtual double getPrice() = 0;

	virtual ~PizzaDecorator();

	virtual std::string getName() = 0;
	virtual int getType() = 0;

protected:
	Pizza *pizza;
	double price;
};

#endif
