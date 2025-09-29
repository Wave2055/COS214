#ifndef AGGREGATE_H
#define AGGREGATE_H

#include "Iterator.h"

/**
 * @class Aggregate
 * @brief Abstract base class defining the interface for iterable collections
 * @details The Aggregate class is part of the Iterator design pattern.
 * It represents a collection of objects that can be traversed sequentially
 * without exposing its underlying representation. Concrete aggregate classes
 * should inherit from this class and implement the createIterator method.
 *
 * @see Iterator
 */
class Aggregate
{
public:
    /**
     * @brief Default constructor
     */
    Aggregate() {};

    /**
     * @brief Virtual destructor for proper cleanup of derived classes
     */
    virtual ~Aggregate() {};

    /**
     * @brief Creates an iterator for traversing the aggregate's elements
     * @return Iterator* A pointer to a newly created iterator object
     * @details This pure virtual method must be implemented by derived classes
     * to provide a way to iterate over the collection's elements. The caller
     * is responsible for deleting the returned iterator when it's no longer needed.
     *
     * @note The returned iterator should be initialized to point to the first
     * element of the collection.
     */
    virtual Iterator *createIterator() const = 0;
};

#endif