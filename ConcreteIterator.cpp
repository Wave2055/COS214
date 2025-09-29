#include "ConcreteIterator.h"

ConcreteIterator::ConcreteIterator(const ChatRoom* room) 
    : chatRoom(room), currentIndex(0) 
{

}

void ConcreteIterator::first() 
{
    currentIndex = 0;
}

void ConcreteIterator::next() 
{
    if (index < chatRoom->chatHistory.size()) 
    {
        currentIndex++;
    }
    
}

