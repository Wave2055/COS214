#ifndef WEBSITE_H
#define WEBSITE_H
#include "Observer.h"
#include <iostream>

class Website : public Observer
{

public:
	void update(std::string message);
};

#endif
