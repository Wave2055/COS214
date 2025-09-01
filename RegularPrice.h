#ifndef REGULARPRICE_H
#define REGULARPRICE_H
#include "DiscountStrategy.h"

class RegularPrice : DiscountStrategy {
    RegularPrice();
    ~RegularPrice();
    double applyDiscount(double originalPrice, int quantity) override {
        return originalPrice * quantity;
    }
};

#endif
