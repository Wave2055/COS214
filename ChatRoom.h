#ifndef CHATROOM_H
#define CHATROOM_H

class ChatRoom : Aggregate {

private:
	Users* users;
	String* chatHistory;

public:
	virtual ~ChatRoom() = 0;

	virtual void registerUser(User user) = 0;

	virtual void sendMessage(String message, User fromUser) = 0;

	virtual void saveMessage(String message, User fromUser) = 0;

	virtual void removeUser(User user) = 0;
};

#endif
