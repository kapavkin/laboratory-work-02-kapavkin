#include "tree.h"

tree::tree()
    : _size(0)
    , _root(nullptr)
{
}

tree::tree(tree& other)
{
    _size = other._size;
    _root = nullptr;
    
    for (size_t i = 0; i < other._size; i++) {
        insert(i, other[i]);
    }
}

tree::~tree()
{
    for (size_t i = 0; i < _size; i++) {
        erase(0);
    }
}

size_t tree::size() const
{
    return _size;
}

void tree::insert(size_t pos, ADT* value)
{
}

ADT* tree::erase(size_t pos)
{
    return nullptr;
}

ADT*& tree::operator[](size_t pos)
{
    
}
