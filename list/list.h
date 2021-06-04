#ifndef LIST_H
#define LIST_H

#include <stdexcept>

#include "ADT.h"

class list {
    struct node {
        ADT* _value;
        node* _next;

        node(ADT*, node* = nullptr);
    };

    size_t _size;
    node* _root;

public:
    list();
    list(list&);
    virtual ~list();

    size_t size() const;
    bool is_empty() const;

    void insert(size_t, ADT*);
    ADT* erase(size_t);

    ADT*& operator[](size_t);
};

#endif
