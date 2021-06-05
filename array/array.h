#ifndef ARRAY_H
#define ARRAY_H

#include <algorithm>
#include <cmath>
#include <stdexcept>

#include "ADT.h"

class array {
    size_t _capacity, _size;
    ADT** _array;

    void resize(size_t);

public:
    array(size_t = 0);
    array(array&);
    virtual ~array();

    size_t size() const;
    bool is_empty() const;

    void insert(size_t, ADT*);
    ADT* remove(size_t);

    ADT*& operator[](size_t);
};

#endif
