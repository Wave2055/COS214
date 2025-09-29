#ifndef CHATROOM_H
#define CHATROOM_H

#include "User.h"
#include "Originator.h"  
#include "Caretaker.h"
#include <string>
#include <vector>
#include "Aggregate.h"

class User;

/**
 * @class ChatRoom
 * @brief Abstract base class representing a chat room.
 *
 * A ChatRoom manages registered users and a chat history.
 * Derived classes must implement the getName() method and the destructor.
 */

class ChatRoom :public Aggregate
{

private:
	std::vector<User *> users;			  ///< List of users currently in the chat room
	std::vector<std::string> chatHistory; ///< Stored chat messages

protected:
	std::string name; ///< Name of the chat room

	//c's stuff
	std::string chatRoomName;
	Originator  messageOriginator;
	Caretaker messageCaretaker;

public:
	virtual ~ChatRoom();

	/**
	 *@brief Notifies other users in the chat room of a new message
	 *
	 *@param message Message that was sent
	 *@param fromUser User who sent the message
	 *
	 *@note Assumes fromUser is a valid reference
	 *@note Does not notify user that sent message
	 **/

	virtual void sendMessage(std::string message, User fromUser) ;

	virtual void saveMessage(std::string message, User fromUser) ;

	virtual void removeUser(User user) ;

	ChatRoom(const std::string& roomName) ;

	// Modified to use Memento pattern
    void sendMessage(const std::string& message, User* fromUser);
    void saveMessage(const std::string& message, User* fromUser);
    
    // Memento pattern functionality
    void restoreMessage(size_t index);
    void displayMessageHistory() const;
    void undoLastMessage();
    void redoMessage();
    void searchMessages(const std::string& keyword) const;
    
    // Getters
    std::string getName() const { return name; }
    const std::vector<User*>& getUsers() const { return users; }

	Iterator* createIterator() override;
    const std::vector<std::string>& getChatHistory() const { return chatHistory; }
};

#endif
