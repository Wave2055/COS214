#include "FamilyDiscount.h"

double FamilyDiscount::applyDiscount(double originalPrice, int quantity)
{
    return (originalPrice * quantity) * 0.85; //100-15/100 = 0.85

}