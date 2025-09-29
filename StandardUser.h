#ifndef STANDARDUSER_H
#define STANDARDUSER_H

#include "User.h"

/**
 * @class StandardUser
 * @brief Represents a standard user with regular system privileges
 * @details The StandardUser class extends the base User class to provide
 * functionality for regular users with standard access rights. Standard users
 * typically have the ability to send messages, participate in chat rooms,
 * and perform common user operations, but may lack administrative privileges
 * or have limitations compared to guest users.
 *
 * This class represents the most common type of user in the system and
 * provides the baseline functionality expected for normal system operation.
 *
 * @inherits User
 */
class StandardUser : public User
{

public:
	/**
	 * @brief Constructs a StandardUser with the specified name
	 * @param name The name of the standard user
	 * @details Initializes a StandardUser object with the given name and
	 * sets up any standard user-specific properties. The name is used to
	 * identify the user within the system and for display purposes in
	 * chat rooms and user lists.
	 */
	StandardUser(std::string name);

	/**
	 * @brief Destroys the StandardUser object
	 * @details Cleans up any resources allocated by the StandardUser and
	 * performs any necessary standard user-specific cleanup operations.
	 * This may include logging user session termination, updating user
	 * status, or cleaning up temporary data associated with the user.
	 */
	~StandardUser();
};

#endif