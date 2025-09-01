#ifndef MENUTYPES_H
#define MENUTYPES_H

#include <vector>

#include "Pizza.h"
#include "BasePizza.h"
#include "ExtraCheese.h"
#include "StuffedCrust.h"

class MenuTypes
{

protected:
    std::vector<Pizza *> menu;

public:
    MenuTypes(std::vector<Pizza *>);
    void addPizza(Pizza *);
    void removePizza(Pizza *);
};

#endif
