#ifndef STACK_H
#define STACK_H

#include "array.h"

#include "ADT.h"

class stack : private array {
public:
    stack(size_t = 0);
    stack(stack&);

    size_t size() const;

    void push(ADT*);
    ADT* pop();

    ADT*& operator[](size_t);
};

#endif
