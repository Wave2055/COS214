#include "Caretaker.h"
#include "Memento.h"
#include <iostream>

Caretaker::Caretaker(size_t maxSize) : maxHistorySize(maxSize) 
{

}

void Caretaker::addMemento(std::shared_ptr<Memento> memento) 
{
    if (messageHistory.size() >= maxHistorySize) 
    {
        messageHistory.erase(messageHistory.begin()); // Remove oldest if at max size
    }
    messageHistory.push_back(memento);
    undoStack.push(memento);
    // Clear redo stack on new action
    while (!redoStack.empty()) 
    {
        redoStack.pop();
    }

    std::cout << "Message saved to history. Total messages: " << messageHistory.size() << std::endl;
    
}

std::shared_ptr<Memento> Caretaker::getMemento(size_t index) const 
{
    if (index < messageHistory.size()) 
    {
        return messageHistory[index];
    }
    std::cout << "Invalid message index: " << index << std::endl;
    return nullptr; // Invalid index
}
std::shared_ptr<Memento> Caretaker::getLatestMemento() const 
{
    if (!messageHistory.empty()) 
    {
        return messageHistory.back();
    }
    std::cout << "No messages in history." << std::endl;
    return nullptr; // No mementos stored
}
std::vector<std::shared_ptr<Memento>> Caretaker::getAllMementos() const 
{
    return messageHistory;
}
std::shared_ptr<Memento> Caretaker::undo() 
{
    if (undoStack.size() > 1) 
    {
        // Pop current state to redo stack
        redoStack.push(undoStack.top());
        undoStack.pop();
        std::cout << "Undo performed. Current state: " 
                  << undoStack.top()->toString() << std::endl;
        return undoStack.top(); // Return previous state
    }
    std::cout << "No more actions to undo." << std::endl;
    return nullptr; // No more undos available
}

std::shared_ptr<Memento> Caretaker::redo() 
{
    if (!redoStack.empty()) 
    {
        // Move state back to undo stack
        std::shared_ptr<Memento> memento = redoStack.top();
        redoStack.pop();
        undoStack.push(memento);
        std::cout << "Redo performed. Current state: " 
                  << memento->toString() << std::endl;
        return memento; // Return redone state
    }
    std::cout << "No more actions to redo." << std::endl;
    return nullptr; // No more redos available
}

size_t Caretaker::getHistorySize() const 
{
    return messageHistory.size();
}

std::vector<std::shared_ptr<Memento>> Caretaker::searchMementos(const std::string& keyword) const 
{
    std::vector<std::shared_ptr<Memento>> results;
    for (const auto& memento : messageHistory) 
    {
        if (memento->toString().find(keyword) != std::string::npos) 
        {
            results.push_back(memento);
        }
    }
    if (results.empty()) 
    {
        std::cout << "No messages found containing keyword: " << keyword << std::endl;
    } 
    else 
    {
        std::cout << results.size() << " messages found containing keyword: " << keyword << std::endl;
    }
    return results;
}

void Caretaker::displayHistory() const 
{
    if (messageHistory.empty()) 
    {
        std::cout << "No messages in history." << std::endl;
        return;
    }
    std::cout << "Message History:" << std::endl;
    for (size_t i = 0; i < messageHistory.size(); ++i) 
    {
        std::cout << i + 1 << ": " << messageHistory[i]->toString() << std::endl;
    }
}
