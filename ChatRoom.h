#ifndef CHATROOM_H
#define CHATROOM_H

#include "User.h"
#include <string>
#include <vector>

class User;

/**
 * @class ChatRoom
 * @brief Abstract base class representing a chat room.
 *
 * A ChatRoom manages registered users and a chat history.
 * Derived classes must implement the getName() method and the destructor.
 */

class ChatRoom
{

private:
	std::vector<User *> users;			  ///< List of users currently in the chat room
	std::vector<std::string> chatHistory; ///< Stored chat messages

protected:
	std::string name; ///< Name of the chat room

public:
	virtual ~ChatRoom() = 0;

	/**
	 *@brief Notifies other users in the chat room of a new message
	 *
	 *@param message Message that was sent
	 *@param fromUser User who sent the message
	 *
	 *@note Assumes fromUser is a valid reference
	 *@note Does not notify user that sent message
	 **/

	virtual void sendMessage(std::string message, User *fromUser);

	/**
	 *@brief Saves message to chat history
	 *
	 *@param message Message to be saved
	 *@param fromUser User who sent the message
	 *
	 *@note Assumes fromUser is a valid reference
	 **/

	virtual void saveMessage(std::string message, User *fromUser);

	/**
	 * @brief Removes a user from the chat room
	 *
	 * @param user Pointer to the user to be removed
	 *
	 * @note Assumes user is a valid pointer
	 */

	virtual void removeUser(User *user);

	/**
	 * @brief Registers a user to the chat room
	 *
	 * @param user Pointer to the user to be registered
	 *
	 * @note Assumes user is a valid pointer
	 */

	virtual void registerUser(User *user);

	/**
	 * @brief Gets the name of the chat room
	 */

	virtual std::string getName() = 0;
};

#endif
