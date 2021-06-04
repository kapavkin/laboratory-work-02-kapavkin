#ifndef TREE_H
#define TREE_H

#include <stdexcept>

#include "ADT.h"

class tree {
    static const bool RED = true;
    static const bool BLACK = false;

    struct node {
        int _key;
        ADT* _value;
        node* _left;
        node* _right;
        bool _color;
        size_t _size;

        node(int, ADT*, bool, size_t);
    };

    node* _root;

    bool is_red(node*) const;

    size_t size(node*) const;
    bool contains(node*, int) const;

    node* insert(node*, int, ADT*);
    node* erase(node*, int);

    ADT*& get(node*, int);

    void flip_colors(node*);
    node* rotate_left(node*);
    node* rotate_right(node*);
    node* move_red_left(node*);
    node* move_red_right(node*);
    node* balance(node*);
    node* min(node*);
    node* max(node*);
    node* delete_min(node*);
    node* delete_max(node*);

public:
    tree();
    tree(tree&);
    virtual ~tree();

    size_t size() const;
    bool is_empty() const;
    bool contains(int) const;

    void insert(int, ADT*);
    void erase(int);

    ADT*& operator[](int);
};

#endif
