#include "SendMessageCommmand.h"

/**
 * @brief Executes the command to send a message in a chat room
 *
 * This method performs two actions:
 * Saves the message to the chat room's message history
 * Sends the message to all users currently in the chat room
 *
 * @note Assumes that `room` and `fromUser` are valid pointers
 */

void SendMessageCommmand::execute()
{
	this->room->saveMessage(this->message, this->fromUser);
	this->room->sendMessage(this->message, this->fromUser);
}
