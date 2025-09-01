#include "RegularPrice.h"

RegularPrice::RegularPrice() {
    
}

RegularPrice::~RegularPrice() {
    
}

double RegularPrice::applyDiscount(double originalPrice, int quantity) {
    return originalPrice * quantity; //there arent any discounts so you gotta pay the actual price man.
}