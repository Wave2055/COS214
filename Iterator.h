#ifndef ITERATOR_H
#define ITERATOR_H

#include <string>

/**
 * @class Iterator
 * @brief Abstract interface for iterators in the Iterator design pattern
 * @details The Iterator class defines the common interface that all concrete
 * iterators must implement. This allows client code to traverse different
 * types of collections using a uniform interface, promoting code reuse and
 * making algorithms collection-agnostic.
 *
 * The iterator follows the typical sequence: first() to start, next() to advance,
 * isDone() to check completion, and currentItem() to access the current element.
 *
 * @see ConcreteIterator
 */
class Iterator
{

public:
    /**
     * @brief Sets the iterator to the first element in the collection
     * @details Resets the iterator position to point to the first element.
     * After calling first(), currentItem() will return the first element
     * and isDone() will return false if the collection is not empty.
     */
    virtual void first() = 0;

    /**
     * @brief Advances the iterator to the next element in the collection
     * @details Moves the iterator to the next position in the sequence.
     * Behavior when called after isDone() returns true is implementation-defined.
     * Typically, iterators either do nothing or throw an exception in this case.
     */
    virtual void next() = 0;

    /**
     * @brief Checks if the iterator has reached the end of the collection
     * @return bool True if there are no more elements to iterate over, false otherwise
     * @details Returns true when the iterator has advanced beyond the last element
     * of the collection. This method should be checked before calling currentItem()
     * to ensure valid access.
     */
    virtual bool isDone() const = 0;

    /**
     * @brief Returns the current element in the iteration sequence
     * @return std::string The current element as a string representation
     * @details Returns a string representation of the element at the current
     * iterator position. The exact format depends on what is being iterated over.
     *
     * @warning Calling this method when isDone() returns true may result in
     * undefined behavior or exceptions, depending on the concrete implementation.
     */
    virtual std::string currentItem() const = 0;

public:
    /**
     * @brief Virtual destructor for proper cleanup of derived classes
     * @details Ensures that derived iterator classes can be properly destroyed
     * through base class pointers, allowing for correct resource cleanup in
     * polymorphic usage scenarios.
     */
    virtual ~Iterator() {};
};

#endif