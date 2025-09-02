#include "BreakfastMenu.h"
#include "BasePizza.h"
#include "ExtraCheese.h"
#include "StuffedCrust.h"
#include "Topping.h"

BreakfastMenu::BreakfastMenu() : MenuTypes({new BasePizza(new Topping("Margherita", 50.0)),
                                            new ExtraCheese(new BasePizza(new Topping("Pepperoni", 60.0)), 15.0),
                                            new StuffedCrust(new BasePizza(new Topping("Hawaiian", 55.0)), 20.0)})
{
}

BreakfastMenu::~BreakfastMenu()
{
    // {
    //     for (Pizza *p : menu)
    //     {
    //         if (p)
    //         {
    //             delete p;
    //         }
    //     }
    // }
}
