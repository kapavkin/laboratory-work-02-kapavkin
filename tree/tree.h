#ifndef TREE_H
#define TREE_H

#include <stdexcept>

#include "ADT.h"

class tree {
    struct node {
        ADT* _value;
        node* _left;
        node* _right;

        node(ADT*, node*, node*);
    };

    size_t _size;
    node* _root;

public:
    tree();
    tree(tree&);
    ~tree();

    size_t size() const;

    void insert(size_t, ADT*);
    ADT* erase(size_t);

    ADT*& operator[](size_t);
};

#endif
