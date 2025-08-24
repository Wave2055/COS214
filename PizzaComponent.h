#ifndef PIZZACOMPONENT_H
#define PIZZACOMPONENT_H

class PizzaComponent {

private:
	double price;
	String name;

public:
	virtual String getName() = 0;

	virtual double getPrice() = 0;
};

#endif
