#include "Topping.h"

Topping::Topping(std::string name, double price) : PizzaComponent(name, price)
{
}

Topping::~Topping()
{
}

int Topping::getType()
{
    return 0; // all toppings type == 0
}