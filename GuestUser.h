#ifndef GUESTUSER_H
#define GUESTUSER_H

#include "User.h"

class GuestUser : public User
{

public:
	GuestUser(std::string name);
	~GuestUser();
};

#endif
