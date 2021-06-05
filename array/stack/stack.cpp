#include "stack.h"

stack::stack(size_t capacity)
    : array(capacity)
{
}

stack::stack(stack& other)
    : array(other)
{
}

size_t stack::size() const
{
    return array::size();
}

bool stack::is_empty() const
{
    return array::is_empty();
}

void stack::push(ADT* value)
{
    array::insert(size(), value);
}

ADT* stack::pop()
{
    return array::remove(size() - 1);
}

ADT*& stack::operator[](size_t pos)
{
    return array::operator[](pos);
}
