#include "LunchMenu.h"
#include "BasePizza.h"
#include "ExtraCheese.h"
#include "StuffedCrust.h"
#include "Topping.h"

LunchMenu::LunchMenu()
{
    std::vector<Pizza*> pizzaVector;

    PizzaComponent* bbqChickenTopping = new Topping("BBQ Chicken", 70.0);
    PizzaComponent* veggieTopping = new Topping("Veggie", 65.0);
    PizzaComponent* meatLoversTopping = new Topping("Meat Lovers", 80.0);

    Pizza* bbqChicken = new BasePizza(bbqChickenTopping);
    Pizza* veggie = new BasePizza(veggieTopping);
    Pizza* meatLovers = new BasePizza(meatLoversTopping);

    pizzaVector.push_back(bbqChicken);
    pizzaVector.push_back(new ExtraCheese(veggie, 15.0));
    pizzaVector.push_back(new StuffedCrust(meatLovers, 25.0));

    this->MenuTypes::MenuTypes( pizzaVector);
}