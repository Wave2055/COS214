#ifndef DISCOUNTSTRATEGY_H
#define DISCOUNTSTRATEGY_H

class DiscountStrategy {


public:
	virtual double applyDiscount(double originalPrice, int quantity) = 0;
	virtual ~DiscountStrategy() = default;	
};

#endif
