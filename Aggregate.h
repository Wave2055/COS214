#ifndef AGGREGATE_H
#define AGGREGATE_H

#include "Iterator.h"

class Aggregate
{
public:
    Aggregate() {};
    virtual ~Aggregate() {};
    virtual Iterator *createIterator() const = 0;
};

#endif
