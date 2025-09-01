#include "Order.h"

Order::Order(double price, int qty, DiscountStrategy* strategy) 
    : pizzaPrice(price), quantity(qty), discountStrategy(strategy) {
    if (price <= 0 || qty <= 0) {
        valid = false;
    }
}

Order::~Order() {
    delete discountStrategy; 

}

void Order::setDiscountStrategy(DiscountStrategy* strategy) {
    delete discountStrategy; 
    discountStrategy = strategy;
}

double Order::calculateTotal() const {
    if (!discountStrategy || !valid) {
        return -1.0;
    }
    return discountStrategy->applyDiscount(pizzaPrice, quantity);
}
