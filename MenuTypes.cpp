#include "MenuTypes.h"

MenuTypes::MenuTypes(std::vector<Pizza *> menu)
{
    for (Pizza *pizza : menu)
    {
        this->addPizza(pizza);
    }
}

void MenuTypes::addPizza(Pizza *pizza)
{
    if (pizza)
    {
        if (pizza->getType() == 0)
        {
            BasePizza *temp = dynamic_cast<BasePizza *>(pizza);

            this->menu.push_back(new BasePizza(temp->getToppings()));
        }
    }
}