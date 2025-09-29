#ifndef AYUSH_H
#define AYUSH_H

#include "User.h"

class StandardUser : public User
{

public:
	StandardUser(std::string name);

	~StandardUser();
};

#endif
