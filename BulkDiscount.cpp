#include "BulkDiscount.h"

BulkDiscount::BulkDiscount() {
}

BulkDiscount::~BulkDiscount() {
}

double BulkDiscount::applyDiscount(double originalPrice, int quantity) 
{
    double discounted = originalPrice * quantity;
    if (quantity >= 5) //if they buy more than 5 pizzas hopefully not for themselves....
    {
        return discounted * 0.9; //then 10%(100-10/100) discount
    }

    return discounted;

}