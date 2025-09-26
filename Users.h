#ifndef USERS_H
#define USERS_H

class Users {

protected:
	ChatRoom* chatRooms;
	String name;
	Command* commandQueue;

public:
	Users(ChatRoom* chatRooms, String name, Command* commandQueue);

	~Users();

	void send(String message, ChatRoom room);

	void receive(String messagee, Users fromUser, ChatRoom room);

	void addCommand(Command command);

	void executeAll();
};

#endif
