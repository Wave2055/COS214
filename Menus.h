#ifndef MENUS_H
#define MENUS_H

class Menus {

private:
	Observer* observes;
	Pizza* pizzas;

public:
	virtual void addObserver(Observer* observer) = 0;

	void removeObserver(Oberver* observer);

	void addPizza(Pizza pizza);

	void removePizza(Pizza pizza);

	virtual void notifyObservers(String message) = 0;
};

#endif
