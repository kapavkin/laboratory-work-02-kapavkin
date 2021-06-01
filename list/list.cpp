#include "list.h"

list::node::node(ADT* value, node* next)
    : _value(value)
    , _next(next)
{
}

list::list()
    : _size(0)
    , _root(nullptr)
{
}

list::list(list& other)
{
    _size = other._size;
    _root = nullptr;

    for (size_t i = 0; i < other._size; i++) {
        insert(i, other[i]);
    }
}

list::~list()
{
    for (size_t i = 0; i < _size; i++) {
        erase(0);
    }
}

size_t list::size() const
{
    return _size;
}

void list::insert(size_t pos, ADT* value)
{
    if (pos > _size) {
        throw std::out_of_range("index out of range");
    }

    if (pos == 0) {
        if (_root == nullptr) {
            _root = new node(value);
        } else {
            _root = new node(value, _root);
        }

        _size++;

        return;
    }

    node* prev = _root;
    for (size_t i = 0; i < pos - 1; i++) {
        prev = prev->_next;
    }

    prev->_next = new node(value, prev->_next);

    _size++;
}

ADT* list::erase(size_t pos)
{
    if (pos + 1 > _size) {
        throw std::out_of_range("index out of range");
    }

    if (pos == 0) {
        ADT* value = _root->_value;
        node* next = _root->_next;

        delete _root;

        _root = next;

        _size--;

        return value;
    }

    node* prev = _root;
    for (size_t i = 0; i < pos - 1; i++) {
        prev = prev->_next;
    }

    ADT* value = prev->_next->_value;
    node* next = prev->_next->_next;

    delete prev->_next;

    prev->_next = next;

    _size--;

    return value;
}

ADT*& list::operator[](size_t pos)
{
    if (pos + 1 > _size) {
        throw std::out_of_range("index out of range");
    }

    node* node = _root;
    for (size_t i = 0; i < pos; i++) {
        node = node->_next;
    }

    return node->_value;
}
