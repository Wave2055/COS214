#ifndef ORDER_H
#define ORDER_H

#include "DiscountStrategy.h"

class Order {
private:
    DiscountStrategy* discountStrategy;
    double pizzaPrice;
    int quantity;
    bool valid;

public:
    Order(double price, int qty, DiscountStrategy* strategy);
    ~Order(); // Need destructor now!
    
    void setDiscountStrategy(DiscountStrategy* strategy);
    double calculateTotal() const;
};

#endif