#include "DinnerMenu.h"
#include "BasePizza.h"
#include "ExtraCheese.h"
#include "StuffedCrust.h"
#include "Topping.h"

DinnerMenu::DinnerMenu() : MenuTypes({new BasePizza(new Topping("Four Cheese", 75.0)),
                                      new ExtraCheese(new BasePizza(new Topping("Supreme", 85.0)), 20.0),
                                      new StuffedCrust(new BasePizza(new Topping("Buffalo Chicken", 90.0)), 30.0)})
{
    // nothing else needed
}
