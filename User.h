#ifndef USERS_H
#define USERS_H

#include "ChatRoom.h"
#include "Command.h"
#include "SendMessageCommmand.h"
#include "LogMessageCommand.h"

#include <vector>
#include <string>
#include <iostream>

class Command;
class ChatRoom;

/**
 * @class User
 * @brief Base class representing a user in a chat system
 * @details The User class provides fundamental functionality for participants
 * in the chat system. Users can join multiple chat rooms, send and receive
 * messages, and queue commands for execution. This class serves as the base
 * for specialized user types like StandardUser, AdminUser, and GuestUser.
 *
 * The class implements the Command pattern for queuing and executing operations,
 * allowing for flexible and extensible user behavior.
 *
 * @see StandardUser, AdminUser, GuestUser, Command, ChatRoom
 */
class User
{

protected:
	std::vector<ChatRoom *> chatRooms;	 ///< List of chat rooms the user is currently participating in
	std::string name;					 ///< Unique identifier/display name for the user
	std::vector<Command *> commandQueue; ///< Queue of pending commands waiting to be executed

public:
	/**
	 * @brief Constructs a User with the specified name
	 * @param name The name of the user
	 * @details Initializes a User object with the given name. The user starts
	 * with no chat rooms registered and an empty command queue.
	 */
	User(std::string name);

	/**
	 * @brief Constructs a User with initial chat room and command
	 * @param chatRooms Pointer to the initial chat room for the user
	 * @param name The name of the user
	 * @param commandQueue Pointer to the initial command for the user
	 * @details Initializes a User object with pre-configured chat room
	 * and command. This constructor provides a way to create users that
	 * are immediately ready to participate in specific chat contexts.
	 */
	User(ChatRoom *chatRooms, std::string name, Command *commandQueue);

	/**
	 * @brief Destroys the User object
	 * @details Cleans up user resources and ensures proper cleanup of
	 * any pending commands in the queue. Derived classes should extend
	 * this destructor for user-specific cleanup.
	 */
	~User();

	/**
	 * @brief Sends a message to a specified chat room
	 * @param message The message content to send
	 * @param room Pointer to the ChatRoom where the message will be sent
	 * @details Creates and executes a SendMessageCommand to deliver the
	 * message to the specified chat room. The message will be broadcast
	 * to all other users in the chat room.
	 */
	void send(std::string message, ChatRoom *room);

	/**
	 * @brief Receives a message from another user in a chat room
	 * @param message The message content received
	 * @param fromUser Pointer to the User who sent the message
	 * @param room Pointer to the ChatRoom where the message was sent
	 * @details Handles incoming messages from other users. This method
	 * is typically called by the ChatRoom when broadcasting messages.
	 * Derived classes may override this method to implement custom
	 * message handling behavior.
	 */
	void receive(std::string message, User *fromUser, ChatRoom *room);

	/**
	 * @brief Adds a command to the user's command queue
	 * @param command Pointer to the Command object to add to the queue
	 * @details Queues a command for later execution. Commands are stored
	 * in the order they are added and executed sequentially when
	 * executeAll() is called.
	 *
	 * @note The User takes ownership of the Command pointer and is
	 * responsible for deleting it after execution.
	 */
	void addCommand(Command *command);

	/**
	 * @brief Executes all commands in the queue and clears it
	 * @details Processes all queued commands in first-in-first-out order.
	 * Each command's execute() method is called, and then the command
	 * is deleted. After execution, the command queue is empty.
	 *
	 * @warning If a command throws an exception during execution,
	 * subsequent commands in the queue may not be executed.
	 */
	void executeAll();

	/**
	 * @brief Gets the name of the user
	 * @return std::string The user's name as a string
	 */
	std::string getName()
	{
		return this->name;
	}

	/**
	 * @brief Registers a chat room to the user's list of chat rooms
	 * @param room Pointer to the ChatRoom to register
	 * @details Adds the specified chat room to the user's collection
	 * of participating chat rooms. The user will be able to send
	 * messages to this chat room and receive messages from it.
	 */
	void registerChatRoom(ChatRoom *room)
	{
		this->chatRooms.push_back(room);
	}
};

#endif