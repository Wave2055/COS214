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
 * @brief Represents a user in a chat system.
 *
 * Each User can send and receive messages, queue commands, and execute them.
 */

class User
{

protected:
	std::vector<ChatRoom *> chatRooms;	 ///< Vector of chat rooms the user is part of
	std::string name;					 ///< Name of the user
	std::vector<Command *> commandQueue; ///< Queue of commands to execute

public:
	/**
	 * @brief Constructs a User with a given chat room and name.
	 * @param chatRooms Pointer to the chat rooms the user belongs to
	 * @param name Name of the user
	 */
	User(std::string name);
	User(ChatRoom* chatRooms, std::string name, Command* commandQueue); 
	~User();

	/**
	 * @brief Sends a message to a chat room.
	 * @param message The message content
	 * @param room Pointer to the ChatRoom to send the message to
	 */

	void send(std::string message, ChatRoom *room);

	/**
	 * @brief Receives a message from another user.
	 * @param messagee The message content
	 * @param fromUser Pointer to the User who sent the message
	 * @param room Pointer to the ChatRoom where the message was sent
	 */

	void receive(std::string message, User *fromUser, ChatRoom *room);

	/**
	 * @brief Adds a command to the user's command queue.
	 * @param command Pointer to the command to add
	 */

	void addCommand(Command *command);

	/**
	 * @brief Executes all commands in the queue and then clears it.
	 */

	void executeAll();

	/**
	 * @brief Gets the name of the user.
	 * @return The user's name as a string
	 */

	std::string getName()
	{
		return this->name;
	}

	/**
	 * @brief Registers a chat room to the user's list of chat rooms.
	 * @param room Pointer to the ChatRoom to register
	 */

	void registerChatRoom(ChatRoom *room)
	{
		this->chatRooms.push_back(room);
	}
};

#endif
