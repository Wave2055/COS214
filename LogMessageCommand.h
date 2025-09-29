#ifndef LONGMESSAGECOMMAND_H
#define LONGMESSAGECOMMAND_H

#include "ChatRoom.h"
#include "Command.h"
#include <fstream>
#include <ctime>

/**
 * @class LogMessageCommand
 * @brief Command that logs a user's message to a chat room log file
 * @details The LogMessageCommand class implements the Command pattern to encapsulate
 * the functionality of writing chat messages to a persistent log file. Each message
 * is timestamped and written to a file named after the chat room, providing a
 * permanent record of chat activity for auditing or historical purposes.
 *
 * @inherits Command
 * @see Command, ChatRoom, User
 */
class LogMessageCommand : public Command
{

public:
	/**
	 * @brief Constructs a LogMessageCommand with the specified parameters
	 * @param room Pointer to the ChatRoom where the message was sent
	 * @param message The message content to be logged
	 * @param fromUser Pointer to the User who sent the message
	 * @details Initializes the command with all necessary context for logging
	 * the message. The command captures the chat room, message content, and
	 * sender information to create a comprehensive log entry.
	 */
	LogMessageCommand(ChatRoom *room, std::string message, User *fromUser) : Command(room, message, fromUser) {};

	/**
	 * @brief Executes the message logging operation
	 * @details Writes the message to a log file named after the chat room.
	 * Each log entry includes a timestamp, the sender's information, and the
	 * message content. The log file is created if it doesn't exist, and new
	 * entries are appended to existing files.
	 *
	 * The log file format is typically:
	 * [timestamp] User: message content
	 *
	 */
	void execute();
};

#endif