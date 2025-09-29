#ifndef CARETAKER_H
#define CARETAKER_H

#include <vector>
#include <memory>
#include <stack>
#include <string>

class Memento;

class Caretaker {
private:
    std::vector<std::shared_ptr<Memento>> messageHistory;  // All mementos in order
    std::stack<std::shared_ptr<Memento>> undoStack;        // Stack for undo
    std::stack<std::shared_ptr<Memento>> redoStack;        // Stack for redo
    size_t maxHistorySize;  // Maximum number of mementos to store
public:
    // Constructor - sets maximum history size
    Caretaker(size_t maxSize = 100);

    // Adds a new memento to the history
    void addMemento(std::shared_ptr<Memento> memento);

    // Retrieves a memento by its position in history
    std::shared_ptr<Memento> getMemento(size_t index) const;

    // Gets the most recent memento
    std::shared_ptr<Memento> getLatestMemento() const;

    // Returns all mementos in history
    std::vector<std::shared_ptr<Memento>> getAllMementos() const;

    // Undo operation - go back to previous state
    std::shared_ptr<Memento> undo();

    // Redo operation - go forward to next state
    std::shared_ptr<Memento> redo();

    // Returns how many mementos are stored
    size_t getHistorySize() const;

    // Searches mementos for specific keywords
    std::vector<std::shared_ptr<Memento>> searchMementos(const std::string& keyword) const;

    // Display entire message history
    void displayHistory() const;
};


#endif
