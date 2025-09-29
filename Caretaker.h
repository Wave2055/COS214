#ifndef CARETAKER_H
#define CARETAKER_H

#include <vector>
#include <memory>
#include <stack>
#include <string>

class Memento;

/**
 * @class Caretaker
 * @brief Manages Memento objects to provide state history and undo/redo functionality
 * @details The Caretaker class is part of the Memento design pattern. It is responsible
 * for storing and retrieving Memento objects that capture the state of other objects.
 * It maintains a complete history of states, supports undo/redo operations, and provides
 * search capabilities through the history.
 *
 * @see Memento
 */
class Caretaker
{
private:
    std::vector<std::shared_ptr<Memento>> messageHistory; ///< All mementos in chronological order
    std::stack<std::shared_ptr<Memento>> undoStack;       ///< Stack for undo operations
    std::stack<std::shared_ptr<Memento>> redoStack;       ///< Stack for redo operations
    size_t maxHistorySize;                                ///< Maximum number of mementos to store in history

public:
    /**
     * @brief Constructs a Caretaker with specified maximum history size
     * @param maxSize Maximum number of mementos to store (default: 100)
     * @details Initializes the Caretaker with the given capacity. When the history
     * reaches this size, older mementos may be removed according to implementation.
     */
    Caretaker(size_t maxSize = 100);

    /**
     * @brief Adds a new memento to the history
     * @param memento Shared pointer to the Memento object to add
     * @details Stores the memento in the history and updates the undo stack.
     * Also clears the redo stack when a new memento is added after undo operations.
     */
    void addMemento(std::shared_ptr<Memento> memento);

    /**
     * @brief Retrieves a memento by its position in history
     * @param index Zero-based index of the memento to retrieve
     * @return std::shared_ptr<Memento> Shared pointer to the requested memento
     */
    std::shared_ptr<Memento> getMemento(size_t index) const;

    /**
     * @brief Gets the most recent memento from history
     * @return std::shared_ptr<Memento> Shared pointer to the latest memento
     */
    std::shared_ptr<Memento> getLatestMemento() const;

    /**
     * @brief Returns all mementos in history
     * @return std::vector<std::shared_ptr<Memento>> Copy of all mementos in chronological order
     */
    std::vector<std::shared_ptr<Memento>> getAllMementos() const;

    /**
     * @brief Performs undo operation - reverts to previous state
     * @return std::shared_ptr<Memento> Shared pointer to the previous state memento
     * @details Moves current state from undo stack to redo stack and returns
     * the previous state. Caller should apply this memento to restore state.
     */
    std::shared_ptr<Memento> undo();

    /**
     * @brief Performs redo operation - restores next state after undo
     * @return std::shared_ptr<Memento> Shared pointer to the next state memento
     * @details Moves state from redo stack back to undo stack and returns
     * the next state. Caller should apply this memento to restore state.
     */
    std::shared_ptr<Memento> redo();

    /**
     * @brief Returns the number of mementos currently stored in history
     * @return size_t Current number of mementos in history
     */
    size_t getHistorySize() const;

    /**
     * @brief Searches mementos for specific keywords
     * @param keyword The search term to look for in mementos
     * @return std::vector<std::shared_ptr<Memento>> Vector of mementos containing the keyword
     * @details Searches through all mementos for the given keyword. The exact
     * matching mechanism depends on the Memento implementation.
     */
    std::vector<std::shared_ptr<Memento>> searchMementos(const std::string &keyword) const;

    /**
     * @brief Displays the entire message history
     * @details Outputs all stored mementos in chronological order to standard output.
     * The format of display depends on the Memento implementation.
     */
    void displayHistory() const;
};

#endif