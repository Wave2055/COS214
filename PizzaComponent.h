#ifndef PIZZACOMPONENT_H
#define PIZZACOMPONENT_H

#include <string>
class PizzaComponent
{

private:
	double price;
	std::string name;

public:
	virtual ~PizzaComponent(); // virtual destructor so that child destructors are called first

	virtual std::string getName();
	virtual double getPrice();
	virtual int getType();

protected:
	PizzaComponent(std::string name, double price);
};

#endif
