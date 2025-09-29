#ifndef GUESTUSER_H
#define GUESTUSER_H

#include "User.h"

/**
 * @class GuestUser
 * @brief Represents a guest user with limited privileges or temporary access
 * @details The GuestUser class extends the base User class to provide
 * functionality for users with restricted permissions. Guest users typically
 * have limited access to system features, may have time-restricted sessions,
 * or cannot perform certain privileged operations that regular or admin users can.
 *
 * @inherits User
 */
class GuestUser : public User
{

public:
	/**
	 * @brief Constructs a GuestUser with the specified name
	 * @param name The name of the guest user
	 * @details Initializes a GuestUser object with the given name and
	 * sets up any guest-specific properties or restrictions. The name
	 * is used to identify the guest user within the system.
	 */
	GuestUser(std::string name);

	/**
	 * @brief Destroys the GuestUser object
	 * @details Cleans up any resources allocated by the GuestUser and
	 * performs any necessary guest-specific cleanup operations, such as
	 * logging guest session termination or cleaning up temporary data.
	 */
	~GuestUser();
};

#endif