#ifndef SENDMESSAGECOMMMAND_H
#define SENDMESSAGECOMMMAND_H

#include "Command.h"
#include "ChatRoom.h"

/**
 * @class SendMessageCommand
 * @brief Command that sends a message to a chat room on behalf of a user
 * @details The SendMessageCommand class implements the Command pattern to encapsulate
 * the functionality of sending a message to a chat room. This command handles the
 * complete message delivery process including notifying other users in the chat room,
 * updating chat history, and potentially integrating with other systems like
 * message logging or state management through Memento pattern.
 *
 * @inherits Command
 * @see Command, ChatRoom, User
 */
class SendMessageCommmand : public Command
{

public:
	/**
	 * @brief Constructs a SendMessageCommand with the specified parameters
	 * @param room Pointer to the ChatRoom where the message will be sent
	 * @param message The message content to be sent
	 * @param fromUser Pointer to the User who is sending the message
	 * @details Initializes the command with all necessary context for sending
	 * the message. The command captures the target chat room, message content,
	 * and sender information to execute the message delivery.
	 */
	SendMessageCommmand(ChatRoom *room, std::string message, User *fromUser) : Command(room, message, fromUser) {};

	/**
	 * @brief Executes the message sending operation
	 * @details Performs the actual message delivery to the specified chat room.
	 * This typically includes:
	 * - Adding the message to the chat room's history
	 * - Notifying all other users in the chat room about the new message
	 * - Updating any relevant state management systems
	 * - Integrating with logging systems
	 */
	void execute();
};

#endif