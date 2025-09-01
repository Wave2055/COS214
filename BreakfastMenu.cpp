#include "BreakfastMenu.h"
#include "BasePizza.h"
#include "ExtraCheese.h"
#include "StuffedCrust.h"
#include "Topping.h"

BreakfastMenu::BreakfastMenu()
{
    std::vector<Pizza*> pizzaVector;

    PizzaComponent* margheritaTopping = new Topping("Margherita", 50.0);
    PizzaComponent* pepperoniTopping = new Topping("Pepperoni", 60.0);
    PizzaComponent* hawaiianTopping = new Topping("Hawaiian", 55.0);

    Pizza* margherita = new BasePizza(margheritaTopping);
    Pizza* pepperoni = new BasePizza(pepperoniTopping);
    Pizza* hawaiian = new BasePizza(hawaiianTopping);

    pizzaVector.push_back(margherita);
    pizzaVector.push_back(new ExtraCheese(pepperoni, 15.0));
    pizzaVector.push_back(new StuffedCrust(hawaiian, 20.0));

    this->MenuTypes::MenuTypes( pizzaVector);
}

