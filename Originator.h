#ifndef ORIGINATOR_H
#define ORIGINATOR_H

#include <iostream>
#include <memory>
#include <string>

class Memento;  // Forward declaration
class ChatRoom; // Forward declaration
class User;

/**
 * @class Originator
 * @brief Creates and restores Memento objects for chat message state management
 * @details The Originator class is a key component of the Memento design pattern.
 * It is responsible for creating Memento objects that capture the current state
 * of chat messages and can restore its state from previously created Mementos.
 * This enables undo/redo functionality and state history management for chat messages.
 *
 * @see Memento, Caretaker, ChatRoom
 */
class Originator
{
private:
    ChatRoom *room;             ///< Pointer to the associated ChatRoom
    std::string currentMessage; ///< Current message content being managed
    User *currentSender;        ///< Current user who sent the message
    std::string ChatRoomName;   ///< Name of the chat room for context

public:
    /**
     * @brief Constructs an Originator for a specific chat room
     * @param chatRoom Pointer to the ChatRoom this Originator is associated with
     * @param chatRoomName Name of the chat room for state tracking
     * @details Initializes the Originator with a specific chat room context.
     * The Originator will manage message states within this chat room environment.
     */
    Originator(ChatRoom *chatRoom, const std::string &chatRoomName);

    /**
     * @brief Saves the current message state to a Memento object
     * @param message The message content to save in the Memento
     * @param sender Pointer to the User who is sending the message
     * @return std::shared_ptr<Memento> Shared pointer to the created Memento object
     * @details Creates a Memento object containing a snapshot of the current message
     * state, including the message content, sender information, timestamp, and
     * chat room context. The Memento can be stored by a Caretaker for later restoration.
     *
     * @note This method generates a timestamp automatically when creating the Memento.
     */
    std::shared_ptr<Memento> saveMessageToMemento(const std::string &message, User *sender);

    /**
     * @brief Restores message state from a previously saved Memento
     * @param memento Shared pointer to the Memento containing the state to restore
     * @details Extracts the state information from the provided Memento and
     * applies it to the current Originator state. This typically involves
     * updating the current message content and sender information, and may
     * trigger notifications or updates in the associated ChatRoom.
     *
     * @warning The Memento must have been created by this Originator or a
     * compatible one to ensure proper state restoration.
     */
    void restoreMessageFromMemento(const std::shared_ptr<Memento> &memento);
};

#endif