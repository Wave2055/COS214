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
    if (curretIndex < chatRoom->chatHistory.size()) 
    {
        currentIndex++;
    }
}

bool ConcreteIterator::isDone() const 
{
    return currentIndex >= chatRoom->chatHistory.size();
}

std::string ConcreteIterator::currentItem() const 
{
    if (isDone()) 
    {
        return chatRoom->getChatHistory()[index];
    }
    return "";
}
