#ifndef CONCRETEITERATOR_H
#define CONCRETEITERATOR_H

#include "Iterator.h"
#include "ChatRoom.h"

/**
 * @class ConcreteIterator
 * @brief Concrete iterator implementation for traversing ChatRoom elements
 * @details The ConcreteIterator class implements the Iterator interface to provide
 * sequential access to the elements of a ChatRoom without exposing its underlying
 * representation. It can iterate over users, messages, or other ChatRoom contents
 * depending on the implementation.
 *
 * @inherits Iterator
 * @see Iterator, ChatRoom
 */
class ConcreteIterator : public Iterator
{

private:
    const ChatRoom *chatRoom; ///< Pointer to the ChatRoom being iterated over
    size_t currentIndex;      ///< Current position in the iteration sequence

public:
    /**
     * @brief Constructs a ConcreteIterator for the specified ChatRoom
     * @param room Pointer to the ChatRoom to iterate over
     * @details Initializes the iterator to point before the first element
     * of the ChatRoom. The iterator must be advanced to access elements.
     */
    ConcreteIterator(const ChatRoom *room);

    /**
     * @brief Destroys the ConcreteIterator object
     * @details Cleans up the iterator resources. Note that this does not
     * affect the underlying ChatRoom being iterated over.
     */
    ~ConcreteIterator();

    /**
     * @brief Resets the iterator to the first element
     * @details Sets the current position to point to the first element
     * in the ChatRoom. Subsequent calls to currentItem() will return
     * the first element.
     */
    void first() override;

    /**
     * @brief Advances the iterator to the next element
     * @details Moves the current position to the next element in the sequence.
     * If the iterator is already at the end, behavior depends on implementation.
     * Typically, isDone() will return true after advancing past the last element.
     */
    void next() override;

    /**
     * @brief Checks if the iterator has reached the end of the sequence
     * @return bool True if there are no more elements to iterate over, false otherwise
     * @details Returns true when the iterator has advanced beyond the last element
     * of the ChatRoom collection.
     */
    bool isDone() const override;

    /**
     * @brief Returns the current element in the iteration sequence
     * @return std::string The current element as a string representation
     * @throws std::out_of_range if called when isDone() returns true
     * @details Returns a string representation of the current element. The exact
     * format depends on what is being iterated over (users, messages, etc.).
     */
    std::string currentItem() const override;
};

#endif