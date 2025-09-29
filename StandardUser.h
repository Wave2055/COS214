#ifndef STANDARDUSER_H
#define STANDARDUSER_H

#include "User.h"

class StandardUser : public User
{

public:
	StandardUser(std::string name);

	~StandardUser();
};

#endif
