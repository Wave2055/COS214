#include "LogMessageCommand.h"

/**
 * @brief Executes the logging command for a chat room.
 *
 * This method writes the message from a user to the corresponding
 * chat room log file. If the log file does not exist, it will be created.
 * If it exists, the message will be appended.
 *
 * The log entry is timestamped in the format YYYY-MM-DD HH:MM:SS.
 *
 * @note The method allocates a new ofstream and deletes it at the end.
 */

void LogMessageCommand::execute()
{
	std::ifstream checkFile(this->room->getName() + ".log");
	std::ofstream *outFile;

	if (checkFile.good())
	{
		outFile = new std::ofstream(this->room->getName() + ".log", std::ios::app);
	}
	else
	{
		outFile = new std::ofstream(this->room->getName() + ".log");
	} // opens the file in append mode or creates a new file if it doesn't exist

	std::time_t now = std::time(nullptr);
	char buf[64];
	std::strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", std::localtime(&now));

	*outFile << "[" << buf << "] " << this->fromUser->getName() << ": " << this->message << std::endl;

	delete outFile;
}
