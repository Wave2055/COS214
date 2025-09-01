#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Observer.h"

#include <iostream>

class Customer : public Observer
{

public:
	void update(std::string message);
};

#endif
