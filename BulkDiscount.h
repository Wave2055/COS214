#ifndef BULKDISCOUNT_H
#define BULKDISCOUNT_H

#include "DiscountStrategy.h"

class BulkDiscount : DiscountStrategy {

    double applyDiscount(double originalPrice, int quantity) override;

};

#endif
