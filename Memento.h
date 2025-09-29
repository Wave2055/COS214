#ifndef MEMENTO_H
#define MEMENTO_H

#include <iostream>
#include <string>
#include "User.h"

/**
 * @class Memento
 * @brief Stores the state of a chat message for later restoration
 * @details The Memento class is a key component of the Memento design pattern.
 * It captures all relevant state information about a chat message including
 * content, sender, timestamp, and chat room context. This state can be used
 * to restore a message to a previous state, enabling undo/redo functionality
 * and message history management.
 *
 * @see Originator, Caretaker
 */
class Memento
{
private:
    std::string contextOfMessage;   ///< The actual content/text of the message
    User *senderOfMessage;          ///< Pointer to the User who sent the message
    std::string timeStampOfMessage; ///< Timestamp when the message was created
    std::string nameOfChatRoom;     ///< Name of the chat room where message was sent

public:
    /**
     * @brief Constructs a Memento with complete message state information
     * @param context The content/text of the message to store
     * @param sender Pointer to the User object who sent the message
     * @param timeStamp Timestamp string representing when message was created
     * @param chatRoomName Name of the chat room where the message was sent
     * @details Creates a Memento object that captures the complete state of
     * a chat message at a specific point in time. All parameters are stored
     * internally and can be retrieved later for state restoration.
     */
    Memento(std::string context, User *sender, std::string timeStamp, std::string chatRoomName);

    /**
     * @brief Retrieves the message content from the Memento
     * @return std::string The stored message text/content
     */
    std::string getContext();

    /**
     * @brief Retrieves the sender of the message from the Memento
     * @return User* Pointer to the User who sent the message
     * @note The returned User pointer should not be deleted by the caller
     * as the Memento does not own the User object.
     */
    User *getSender();

    /**
     * @brief Retrieves the timestamp from the Memento
     * @return std::string The timestamp when the message was created
     */
    std::string getTimeStamp();

    /**
     * @brief Retrieves the chat room name from the Memento
     * @return std::string The name of the chat room where message was sent
     */
    std::string getChatRoomName();

    /**
     * @brief Returns a string representation of the Memento's state
     * @return std::string Formatted string containing all Memento information
     * @details Creates a human-readable string that includes the timestamp,
     * sender name, chat room, and message content for display or logging purposes.
     * Format typically includes: [timestamp] sender@chatroom: message
     */
    std::string toString();
};

#endif