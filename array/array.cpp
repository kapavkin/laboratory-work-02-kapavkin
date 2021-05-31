#include "array.h"

void array::resize(size_t capacity)
{
    ADT** array = new ADT*[capacity];

    std::copy(_array, _array + std::min(_capacity, capacity), array);

    delete[] _array;

    _array = new ADT*[capacity];

    std::copy(array, array + capacity, _array);

    delete[] array;

    _capacity = capacity;
}

array::array(size_t capacity)
{
    _capacity = capacity;
    _array = new ADT*[capacity];
    _size = 0;
}

array::array(array& other)
{
    _capacity = other._capacity;

    _array = new ADT*[_capacity];
    for (size_t i = 0; i < other._size; i++) {
        _array[i] = other._array[i];
    }

    _size = other._size;
}

array::~array()
{
    delete[] _array;
}

size_t array::size() const
{
    return _size;
}

void array::insert(size_t pos, ADT* value)
{
    if (pos > _size) {
        throw std::out_of_range("index out of range");
    }

    if (_size == _capacity) {
        if (_capacity > 0) {
            resize(2 * _capacity);
        } else {
            resize(1);
        }
    }

    ADT** array = new ADT*[_capacity];

    std::copy(_array, _array + pos, array);

    array[pos] = value;

    std::copy(_array + pos, _array + _capacity - 1, array + pos + 1);

    delete[] _array;

    _array = new ADT*[_capacity];

    std::copy(array, array + _capacity, _array);

    delete[] array;

    _size++;
}

ADT* array::erase(size_t pos)
{
    if (pos + 1 > _size) {
        throw std::out_of_range("index out of range");
    }

    ADT* value = _array[pos];

    ADT** array = new ADT*[_capacity];

    std::copy(_array, _array + pos, array);
    std::copy(_array + pos + 1, _array + _capacity, array + pos);

    delete[] _array;

    _array = new ADT*[_capacity];

    std::copy(array, array + _capacity, _array);

    delete[] array;

    _size--;

    if (_size <= _capacity / 2) {
        resize(_capacity / 2);
    }

    return value;
}

ADT*& array::operator[](size_t pos)
{
    if (pos + 1 > _size) {
        throw std::out_of_range("index out of range");
    }

    return _array[pos];
}
