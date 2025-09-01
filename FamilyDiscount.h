#ifndef FAMILYDISCOUNT_H
#define FAMILYDISCOUNT_H
#include "DiscountStrategy.h"

class FamilyDiscount : public DiscountStrategy {
    public:

    FamilyDiscount();
    ~FamilyDiscount();
    double applyDiscount(double originalPrice, int quantity) override;
};

#endif
