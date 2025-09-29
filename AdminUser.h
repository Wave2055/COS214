#ifndef ADMINUSER_H
#define ADMINUSER_H

#include "User.h"

class AdminUser : public User
{

public:
	AdminUser(std::string name);
	~AdminUser();
};

#endif
