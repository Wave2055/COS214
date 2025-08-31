#ifndef FAMILYDISCOUNT_H
#define FAMILYDISCOUNT_H
#include "DiscountStrategy.h"

class FamilyDiscount : DiscountStrategy {
    double applyDiscount(double originalPrice, int quantity) override;
};

#endif
