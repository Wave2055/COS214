#ifndef CTRLCAT_H
#define CTRLCAT_H

#include "ChatRoom.h"
#include "ConcreteIterator.h"

/**
 * @class CtrlCat
 * @brief Concrete implementation of a ChatRoom with specific functionality
 * @details The CtrlCat class is a specialized chat room that inherits from
 * the abstract ChatRoom base class. It provides concrete implementations
 * for the pure virtual methods and may include additional CtrlCat-specific
 * behavior. The name "CtrlCat" suggests this may be a control or moderated
 * chat room category.
 *
 * @inherits ChatRoom
 * @see ChatRoom, ConcreteIterator
 */
class CtrlCat : public ChatRoom
{

public:
	/**
	 * @brief Default constructor for CtrlCat
	 * @details Initializes a new CtrlCat chat room with default settings.
	 * The specific initialization behavior may include setting the chat room
	 * name and preparing the underlying ChatRoom components.
	 */
	CtrlCat();

	/**
	 * @brief Destructor for CtrlCat
	 * @details Cleans up resources specific to the CtrlCat implementation.
	 * Ensures proper destruction of any CtrlCat-specific resources while
	 * maintaining the base ChatRoom cleanup.
	 */
	~CtrlCat();

	/**
	 * @brief Gets the name of the CtrlCat chat room
	 * @return std::string The name of this chat room
	 * @details Returns the name identifier for this specific CtrlCat instance.
	 * The name is typically set during construction and identifies the
	 * chat room within the system.
	 */
	std::string getName()
	{
		return this->name;
	}

	/**
	 * @brief Creates an iterator for traversing CtrlCat elements
	 * @return Iterator* Pointer to a newly created ConcreteIterator for this CtrlCat
	 * @details Implements the factory method from the Aggregate interface to
	 * create a ConcreteIterator specifically for this CtrlCat instance. The
	 * iterator can be used to traverse users, messages, or other contents
	 * of the chat room.
	 *
	 * @note The caller is responsible for deleting the returned iterator
	 * when it is no longer needed to prevent memory leaks.
	 */
	virtual Iterator *createIterator() const
	{
		return new ConcreteIterator(this);
	}
};

#endif