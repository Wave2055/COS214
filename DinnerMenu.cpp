#include "DinnerMenu.h"
#include "BasePizza.h"
#include "ExtraCheese.h"
#include "StuffedCrust.h"
#include "Topping.h"

DinnerMenu::DinnerMenu()
{
    std::vector<Pizza*> pizzaVector;

    PizzaComponent* fourCheeseTopping = new Topping("Four Cheese", 75.0);
    PizzaComponent* supremeTopping = new Topping("Supreme", 85.0);
    PizzaComponent* buffaloChickenTopping = new Topping("Buffalo Chicken", 90.0);

    Pizza* fourCheese = new BasePizza(fourCheeseTopping);
    Pizza* supreme = new BasePizza(supremeTopping);
    Pizza* buffaloChicken = new BasePizza(buffaloChickenTopping);

    pizzaVector.push_back(fourCheese);
    pizzaVector.push_back(new ExtraCheese(supreme, 20.0));
    pizzaVector.push_back(new StuffedCrust(buffaloChicken, 30.0));

    this->MenuTypes::MenuTypes( pizzaVector);
}