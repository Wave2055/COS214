#ifndef MENUS_H
#define MENUS_H

#include <iostream>
#include <vector>

#include "Observer.h"
#include "Pizza.h"

class Menus
{

protected:
	std::vector<Observer *> observes;
	std::vector<Pizza *> pizzas;

public:
	Menus();
	virtual ~Menus();

	void addObserver(Observer *observer);

	void removeObserver(int index);

	void addPizza(Pizza *pizza);

	void removePizza(int index);

	virtual void notifyObservers(std::string message) = 0;
};

#endif
