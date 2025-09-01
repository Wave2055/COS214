#include "BreakfastMenu.h"

BreakfastMenu::BreakfastMenu()
{
    std::vector<Pizza*> pizzaVector;
      pizzaVector.push_back(new BasePizza("Margherita"));
    pizzaVector.push_back(new ExtraCheese(new BasePizza("Pepperoni")));
    pizzaVector.push_back(new StuffedCrust(new BasePizza("Hawaiian")));

    this->menuTypes = pizzaVector;
}