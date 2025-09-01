#ifndef BULKDISCOUNT_H
#define BULKDISCOUNT_H

#include "DiscountStrategy.h"

class BulkDiscount : DiscountStrategy {
    BulkDiscount();
    ~BulkDiscount();
    double applyDiscount(double originalPrice, int quantity) override;

};

#endif
