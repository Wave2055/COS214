#include "PizzaComponent.h"

PizzaComponent::PizzaComponent(std::string name, double price)
{
    this->name = name;
    this->price = price;
}

PizzaComponent::~PizzaComponent()
{
    // no dynamic memory used
}

std::string PizzaComponent::getName()
{
    return this->name;
}

double PizzaComponent::getPrice()
{
    return this->price;
}