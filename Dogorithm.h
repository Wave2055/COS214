#ifndef DOGORITHM_H
#define DOGORITHM_H

#include "ChatRoom.h"
#include "ConcreteIterator.h"

/**
 * @class Dogorithm
 * @brief Concrete implementation of a ChatRoom with algorithmic or dog-themed functionality
 * @details The Dogorithm class is a specialized chat room that inherits from
 * the abstract ChatRoom base class. The name "Dogorithm" suggests a playful
 * combination of "dog" and "algorithm," potentially indicating a chat room
 * with themed features or algorithmic message processing capabilities.
 * It provides concrete implementations for the pure virtual methods required
 * by the ChatRoom interface.
 *
 * @inherits ChatRoom
 * @see ChatRoom, ConcreteIterator
 */
class Dogorithm : public ChatRoom
{

public:
	/**
	 * @brief Default constructor for Dogorithm
	 * @details Initializes a new Dogorithm chat room with default settings.
	 * Sets up the chat room name and prepares the underlying ChatRoom components
	 * for message handling and user management with Dogorithm-specific behavior.
	 */
	Dogorithm();

	/**
	 * @brief Destructor for Dogorithm
	 * @details Cleans up resources specific to the Dogorithm implementation.
	 * Ensures proper destruction of any Dogorithm-specific resources while
	 * maintaining the base ChatRoom cleanup sequence.
	 */
	~Dogorithm();

	/**
	 * @brief Gets the name of the Dogorithm chat room
	 * @return std::string The name of this chat room
	 * @details Returns the name identifier for this specific Dogorithm instance.
	 * The name is typically set during construction and identifies the
	 * chat room within the system, potentially reflecting the "Dogorithm" theme.
	 */
	std::string getName()
	{
		return this->name;
	}

	/**
	 * @brief Creates an iterator for traversing Dogorithm elements
	 * @return Iterator* Pointer to a newly created ConcreteIterator for this Dogorithm
	 * @details Implements the factory method from the Aggregate interface to
	 * create a ConcreteIterator specifically for this Dogorithm instance. The
	 * iterator can be used to traverse users, messages, or other contents
	 * of the Dogorithm chat room in a sequential manner.
	 *
	 * @note The caller is responsible for deleting the returned iterator
	 * when it is no longer needed to prevent memory leaks.
	 */
	Iterator *createIterator() const
	{
		return new ConcreteIterator(this);
	}
};

#endif