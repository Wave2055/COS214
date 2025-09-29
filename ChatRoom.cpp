#include "ChatRoom.h"
#include "Memento.h"
#include "ConcreteIterator.h"

ChatRoom::~ChatRoom()
{
}

void ChatRoom::saveMessage(std::string message, User *user)
{
    this->chatHistory.push_back(user->getName() + ": " + message);
}

void ChatRoom::registerUser(User *user)
{
    if (user)
    {
        for (User *u : this->users)
        {
            if (u == user)
            {
                return; // User already registered
            }
        }
    }
    else if (user == nullptr)
    {
        return; // Null pointer, do nothing
    }

    this->users.push_back(user);
    user->registerChatRoom(this);
}

void ChatRoom::removeUser(User *user)
{
    for (int i = 0; i < this->users.size(); ++i)
    {
        User *u = this->users[i];
        {
            if (u == user)
            {
                this->users.erase(this->users.begin() + i);
                return; // User found and removed
            }
        }
    }
}

/////////////////////////-c
ChatRoom::ChatRoom(const std::string &roomName)
    : name(roomName),
      messageOriginator(this, roomName),
      messageCaretaker(100)
{ // Max 100 messages in history
}

void ChatRoom::sendMessage(const std::string &message, User *user)
{

    // Save message to memento before sending (creates backup)
    auto memento = messageOriginator.saveMessageToMemento(message, user);
    messageCaretaker.addMemento(memento);

    // Original logic: deliver message to all other users in room
    std::cout << "[" << name << "] " << user->getName() << " sends: " << message << std::endl;

    for (User *user : users)
    {
        if (user != user)
        { // Don't send the message back to sender
            user->receive(message, user, this);
        }
    }

    // Save to regular chat history (existing functionality)
    saveMessage(message, user);
}

// void ChatRoom::saveMessage(const std::string& message, User* fromUser) {
//     std::string formattedMessage = "[" + fromUser->getName() + "]: " + message;
//     chatHistory.push_back(formattedMessage);
// }

void ChatRoom::restoreMessage(size_t index)
{
    auto memento = messageCaretaker.getMemento(index);
    if (memento)
    {
        std::cout << "Restoring message from history index " << index << ":" << std::endl;
        messageOriginator.restoreMessageFromMemento(memento);
    }
}

void ChatRoom::displayMessageHistory() const
{
    messageCaretaker.displayHistory();
}

void ChatRoom::undoLastMessage()
{
    auto memento = messageCaretaker.undo();
    if (memento)
    {
        std::cout << "Message undone: " << memento->toString() << std::endl;
    }
}

void ChatRoom::redoMessage()
{
    auto memento = messageCaretaker.redo();
    if (memento)
    {
        std::cout << "Message redone: " << memento->toString() << std::endl;
    }
}

void ChatRoom::searchMessages(const std::string &keyword) const
{
    auto results = messageCaretaker.searchMementos(keyword);
    if (!results.empty())
    {
        std::cout << "\n=== SEARCH RESULTS for '" << keyword << "' ===" << std::endl;
        for (const auto &memento : results)
        {
            std::cout << "• " << memento->toString() << std::endl;
        }
    }
}

Iterator *ChatRoom::createIterator()
{
    return new ConcreteIterator(this);
}