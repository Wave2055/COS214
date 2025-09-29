#ifndef ADMINUSER_H
#define ADMINUSER_H

#include "User.h"

/**
 * @class AdminUser
 * @brief Represents an administrative user with elevated privileges
 * @details The AdminUser class extends the base User class to provide
 * administrative capabilities. Admin users typically have permissions to
 * manage system settings, other users, and perform administrative tasks.
 *
 * @inherits User
 */
class AdminUser : public User
{

public:
	/**
	 * @brief Constructs an AdminUser with the specified name
	 * @param name The name of the administrative user
	 * @details Initializes an AdminUser object with the given name and
	 * sets up any administrative-specific properties
	 */
	AdminUser(std::string name);

	/**
	 * @brief Destroys the AdminUser object
	 * @details Cleans up any resources allocated by the AdminUser and
	 * performs any necessary administrative cleanup operations
	 */
	~AdminUser();
};

#endif