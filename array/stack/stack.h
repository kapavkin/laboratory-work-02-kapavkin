#ifndef STACK_H
#define STACK_H

#include "array.h"

#include "ADT.h"

class stack : private array {
public:
    stack(size_t = 0);
    stack(stack&);

    size_t size() const;
    bool is_empty() const;

    void push(ADT*);
    ADT* pop();

    void push_front(ADT*);
    ADT* pop_front();

    ADT*& operator[](size_t);
};

#endif
