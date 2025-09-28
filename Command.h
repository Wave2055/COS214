#ifndef COMMAND_H
#define COMMAND_H

#include "ChatRoom.h"
#include "User.h"

/**
 * @class Command
 * @brief Abstract base class for all commands in the chat application.
 *
 * Each command operates on a chat room and a message from a user.
 * Derived classes must implement the execute() method.
 */
class Command
{

protected:
	ChatRoom *room;		 ///< Pointer to the chat room where the command applies
	std::string message; ///< The message associated with this command
	User *fromUser;		 ///< Pointer to the user who issued the command

	/**
	 * @brief Constructs a Command object.
	 *
	 * @param room Pointer to the chat room where the command applies
	 * @param message The message associated with the command
	 * @param fromUser Pointer to the user issuing the command
	 */
	Command(ChatRoom *room, std::string message, User *fromUser)
	{
		this->room = room;
		this->message = message;
		this->fromUser = fromUser;
	}

public:
	/**
	 * @brief Pure virtual function to execute the command.
	 *
	 * Derived classes must implement this method to define the behavior
	 * of the command.
	 */
	virtual void execute() = 0;
};

#endif
