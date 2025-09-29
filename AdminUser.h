#ifndef JAITIN_H
#define JAITIN_H

#include "User.h"

class AdminUser : public User
{

public:
	AdminUser(std::string name);

	~AdminUser();
};

#endif
