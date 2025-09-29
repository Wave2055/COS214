#ifndef ITERATOR_H
#define ITERATOR_H

#include <string>
class Iterator 
{    
    //virtual ~Iterator() {};
    virtual void first() = 0;   
    virtual void next() = 0;
    virtual bool isDone() const = 0;
    virtual std::string currentItem() const = 0;
public:
    virtual ~Iterator() {};
};

#endif
