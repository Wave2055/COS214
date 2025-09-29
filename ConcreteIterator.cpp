#include "ConcreteIterator.h"

ConcreteIterator::ConcreteIterator(const ChatRoom *room)
    : chatRoom(room), currentIndex(0)
{
}

ConcreteIterator::~ConcreteIterator()
{
}

void ConcreteIterator::first()
{
    currentIndex = 0;
}

void ConcreteIterator::next()
{

    if (currentIndex < chatRoom->getChatHistory().size())
    {
        currentIndex++;
    }
}

bool ConcreteIterator::isDone() const
{
    return currentIndex >= chatRoom->getChatHistory().size();
}

std::string ConcreteIterator::currentItem() const
{
    if (isDone())
    {
        return chatRoom->getChatHistory()[currentIndex];
    }
    return "";
}
