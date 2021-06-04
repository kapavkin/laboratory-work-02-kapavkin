#ifndef QUEUE_H
#define QUEUE_H

#include <stdexcept>

#include "ADT.h"

class queue {
    size_t _capacity, _start, _size;
    ADT** _circle;

public:
    queue(size_t);
    queue(queue&);
    virtual ~queue();

    size_t capacity() const;
    size_t size() const;
    bool is_empty() const;

    void enqueue(ADT*);
    ADT* dequeue();

    ADT*& operator[](size_t);
};

#endif
