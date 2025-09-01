#include "LunchMenu.h"
#include "BasePizza.h"
#include "ExtraCheese.h"
#include "StuffedCrust.h"
#include "Topping.h"

LunchMenu::LunchMenu() : MenuTypes({new BasePizza(new Topping("BBQ Chicken", 70.0)),
                                    new ExtraCheese(new BasePizza(new Topping("Veggie", 65.0)), 15.0),
                                    new StuffedCrust(new BasePizza(new Topping("Meat Lovers", 80.0)), 25.0)})
{
}
