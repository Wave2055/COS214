#ifndef CONCRETEITERATOR_H
#define CONCRETEITERATOR_H
#include "Iterator.h"
#include "ChatRoom.h"
class ConcreteIterator : Iterator {
private:
    const ChatRoom* chatRoom;
    size_t currentIndex;
public:
    ConcreteIterator(const ChatRoom* room);
    ~ConcreteIterator();
    void first() override;
    void next() override;
    void isDone() const override;
    std::string currentItem() const override;
};

#endif
