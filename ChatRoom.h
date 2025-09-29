#ifndef CHATROOM_H
#define CHATROOM_H

#include "User.h"
#include "Originator.h"
#include "Caretaker.h"
#include "Memento.h"
#include <string>
#include <vector>
#include "Aggregate.h"

class User;

/**
 * @class ChatRoom
 * @brief Abstract base class representing a chat room that manages users and chat history
 * @details The ChatRoom class provides functionality for user management, message sending,
 * and chat history preservation using the Memento pattern. It also implements the Aggregate
 * interface for the Iterator pattern. Derived classes must implement specific chat room behaviors.
 *
 * @inherits Aggregate
 * @see Originator, Caretaker, Memento, User
 */
class ChatRoom : public Aggregate
{

private:
	std::vector<User *> users;			  ///< List of users currently registered in the chat room
	std::vector<std::string> chatHistory; ///< Complete history of chat messages in chronological order

protected:
	std::string name; ///< Name of the chat room

	// Memento pattern components
	std::string chatRoomName;	  ///< Additional name identifier for the chat room
	Originator messageOriginator; ///< Originator for creating and restoring message mementos
	Caretaker messageCaretaker;	  ///< Caretaker for managing message history and undo/redo operations

public:
	/**
	 * @brief Virtual destructor for proper cleanup of derived classes
	 */
	virtual ~ChatRoom();

	/**
	 * @brief Sends a message to all other users in the chat room
	 * @param message The message content to send
	 * @param user Pointer to the user sending the message
	 * @details Delivers the message to all registered users except the sender.
	 * Also adds the message to the chat history and creates a memento for undo/redo functionality.
	 */
	virtual void sendMessage(const std::string &message, User *user);

	/**
	 * @brief Saves a message to chat history using Memento pattern
	 * @param message The message content to save
	 * @param user Pointer to the user who sent the message
	 * @details Creates a memento of the message state and stores it in the caretaker
	 * for future undo/redo operations and history tracking.
	 */
	virtual void saveMessage(std::string message, User *user);

	/**
	 * @brief Removes a user from the chat room
	 * @param user Pointer to the user to remove
	 * @details Removes the specified user from the users list and performs
	 * any necessary cleanup. Does not delete the user object itself.
	 */
	virtual void removeUser(User *user);

	/**
	 * @brief Constructs a ChatRoom with the specified name
	 * @param roomName The name of the chat room
	 */
	ChatRoom(const std::string &roomName);

	/**
	 * @brief Restores a message from history to current state
	 * @param index The index of the message in history to restore
	 * @details Uses the Memento pattern to restore a previously saved message state.
	 * The restored message becomes the current state and can be modified or resent.
	 */
	void restoreMessage(size_t index);

	/**
	 * @brief Displays the complete message history
	 * @details Outputs all stored messages in chronological order with their
	 * respective indices for restoration purposes.
	 */
	void displayMessageHistory() const;

	/**
	 * @brief Undoes the last message operation
	 * @details reverts the chat to the state before the last message was sent
	 */
	void undoLastMessage();

	/**
	 * @brief Redoes a previously undone message operation
	 * @details Restores the most recently undone message operation using the
	 * Memento pattern.
	 */
	void redoMessage();

	/**
	 * @brief Searches for messages containing specific keywords
	 * @param keyword The search term to look for in message history
	 * @details Searches through all chat history and displays messages that
	 * contain the specified keyword. Uses the Caretaker's search functionality.
	 */
	void searchMessages(const std::string &keyword) const;

	/**
	 * @brief Gets the name of the chat room
	 * @return std::string The name of the chat room
	 */
	std::string getName() const { return name; }

	/**
	 * @brief Gets the list of registered users
	 * @return const std::vector<User*>& Reference to the vector of registered users
	 */
	const std::vector<User *> &getUsers() const { return users; }

	/**
	 * @brief Creates an iterator for traversing chat room elements
	 * @return Iterator* Pointer to a newly created iterator object
	 * @details Implements the Aggregate interface to provide iterator access
	 * to chat room contents (users or messages). Caller is responsible for
	 * deleting the returned iterator.
	 */
	virtual Iterator *createIterator() const;

	/**
	 * @brief Gets the complete chat history
	 * @return const std::vector<std::string>& Reference to the vector of chat messages
	 */
	const std::vector<std::string> &getChatHistory() const { return chatHistory; }

	/**
	 * @brief Registers a new user with the chat room
	 * @param user Pointer to the user to register
	 * @details Adds the user to the chat room's user list and performs
	 * any necessary initialization for the user to participate in the chat.
	 */
	virtual void registerUser(User *user);
};

#endif