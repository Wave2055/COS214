#ifndef PIZZA_H
#define PIZZA_H

#include <string>
#include <iostream>

class Pizza
{

public:
	virtual double getPrice() = 0;

	virtual std::string getName() = 0;

	void printPizzza();

	~Pizza();

protected:
	Pizza();
};

#endif
