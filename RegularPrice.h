#ifndef REGULARPRICE_H
#define REGULARPRICE_H
#include "DiscountStrategy.h"

class RegularPrice : public DiscountStrategy {
    public:

    RegularPrice();
    ~RegularPrice();
    double applyDiscount(double originalPrice, int quantity) override ;
    
};

#endif
