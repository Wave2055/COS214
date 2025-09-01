#ifndef BULKDISCOUNT_H
#define BULKDISCOUNT_H

#include "DiscountStrategy.h"

class BulkDiscount : public DiscountStrategy {
    public:
    BulkDiscount();
    ~BulkDiscount();
    double applyDiscount(double originalPrice, int quantity) override;

};

#endif
