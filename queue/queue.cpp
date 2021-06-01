#include "queue.h"

queue::queue(size_t capacity)
{
    _capacity = capacity;
    _circle = new ADT*[capacity];
    _start = 0;
    _size = 0;
}

queue::queue(queue& other)
{
    _capacity = other._capacity;

    _circle = new ADT*[_capacity];
    for (size_t i = 0; i < _capacity; i++) {
        _circle[i] = other._circle[i];
    }

    _start = other._start;
    _size = other._size;
}

queue::~queue()
{
    delete[] _circle;
}

size_t queue::capacity() const
{
    return _capacity;
}

size_t queue::size() const
{
    return _size;
}

void queue::enqueue(ADT* value)
{
    if (_size == _capacity) {
        throw std::out_of_range("index out of range");
    }

    _circle[(_start + _size++) % _capacity] = value;
}

ADT* queue::dequeue()
{
    if (_size == 0) {
        throw std::out_of_range("index out of range");
    }

    ADT* value = _circle[_start];

    _start = (_start + 1) % _capacity;
    _size--;

    return value;
}

ADT*& queue::operator[](size_t pos)
{
    if (pos + 1 > _size) {
        throw std::out_of_range("index out of range");
    }

    return _circle[(_start + pos) % _capacity];
}
