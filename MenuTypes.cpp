#include "MenuTypes.h"

MenuTypes::MenuTypes(std::vector<Pizza *> menu)
{
    for (Pizza *pizza : menu)
    {
        this->addPizza(pizza);
        delete pizza;
    }
}

MenuTypes::~MenuTypes()
{
    for (Pizza *p : menu)
    {
        if (p)
        {
            delete p;
        }
    }

    this->menu.clear();
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
        else if (pizza->getType() == 1)
        {
            ExtraCheese *temp = dynamic_cast<ExtraCheese *>(pizza);
            this->menu.push_back(new ExtraCheese(temp->getPizza(), temp->getPrice()));
        }
        else if (pizza->getType() == 2)
        {
            StuffedCrust *temp = dynamic_cast<StuffedCrust *>(pizza);
            this->menu.push_back(new StuffedCrust(temp->getPizza(), temp->getPrice()));
        }
    }
}