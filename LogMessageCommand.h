#ifndef LONGMESSAGECOMMAND_H
#define LONGMESSAGECOMMAND_H

#include "ChatRoom.h"
#include "Command.h"
#include <fstream>
#include <ctime>

/**
 * @class LogMessageCommand
 * @brief Command that logs a user's message to a chat room log file.
 *
 * This class inherits from Command and implements the execute() method
 * to write messages to a log file. The log file is named after the chat room
 * and each message is timestamped.
 */

class LogMessageCommand : public Command
{

public:
	LogMessageCommand(ChatRoom *room, std::string message, User *fromUser) : Command(room, message, fromUser) {};
	void execute();
};

#endif
