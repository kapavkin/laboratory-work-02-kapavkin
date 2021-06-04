#include "tree.h"

tree::node::node(int key, ADT* value, bool color, size_t size)
    : _key(key)
    , _value(value)
    , _color(color)
    , _size(size)
{
}

bool tree::is_red(node* n) const
{
    if (n == nullptr)
        return BLACK;
    else
        return n->_color == RED;
}

size_t tree::size(node* n) const
{
    if (n == nullptr)
        return 0;
    else
        return n->_size;
}

bool tree::contains(node* n, int key) const
{
    while (n != nullptr) {
        if (key < n->_key)
            n = n->_left;
        else if (key > n->_key)
            n = n->_right;
        else
            return true;
    }

    return false;
}

tree::node* tree::insert(node* n, int key, ADT* value)
{
    if (n == nullptr) {
        return new node(key, value, RED, 1);
    }

    if (key < n->_key) {
        n->_left = insert(n->_left, key, value);
    } else if (key > n->_key) {
        n->_right = insert(n->_right, key, value);
    } else {
        n->_value = value;
    }

    if (is_red(n->_right) && !is_red(n->_left)) {
        n = rotate_left(n);
    }

    if (is_red(n->_left) && is_red(n->_left->_left)) {
        n = rotate_right(n);
    }

    if (is_red(n->_left) && is_red(n->_right)) {
        flip_colors(n);
    }

    n->_size = size(n->_left) + size(n->_right) + 1;

    return n;
}

tree::node* tree::erase(node* n, int key)
{
    if (key < n->_key) {
        if (!is_red(n->_left) && !is_red(n->_left->_left)) {
            n = move_red_left(n);
        }
        n->_left = erase(n->_left, key);
    } else {
        if (is_red(n->_left)) {
            n = rotate_right(n);
        }

        if (key == n->_key && n->_right == nullptr) {
            return nullptr;
        }

        if (!is_red(n->_right) && !is_red(n->_right->_left)) {
            n = move_red_right(n);
        }

        if (key == n->_key) {
            node* temp = min(n->_right);
            n->_key = temp->_key;
            n->_value = temp->_value;
            n->_right = delete_min(n->_right);
        } else {
            n->_right = erase(n->_right, key);
        }
    }

    return balance(n);
}

ADT*& tree::get(node* n, int key)
{
    while (n != nullptr) {
        if (key < n->_key)
            n = n->_left;
        else if (key > n->_key)
            n = n->_right;
        else
            return n->_value;
    }
}

void tree::flip_colors(node* n)
{
    n->_color = !n->_color;
    n->_left->_color = !n->_left->_color;
    n->_right->_color = !n->_right->_color;
}

tree::node* tree::rotate_left(node* n)
{
    node* temp = n->_right;
    n->_right = temp->_left;
    temp->_left = n;
    temp->_color = temp->_left->_color;
    temp->_left->_color = RED;
    temp->_size = n->_size;
    n->_size = size(n->_left) + size(n->_right) + 1;

    return temp;
}

tree::node* tree::rotate_right(node* n)
{
    node* temp = n->_left;
    n->_left = temp->_right;
    temp->_right = n;
    temp->_color = temp->_right->_color;
    temp->_right->_color = RED;
    temp->_size = n->_size;
    n->_size = size(n->_left) + size(n->_right) + 1;

    return temp;
}

tree::node* tree::move_red_left(node* n)
{
    flip_colors(n);
    if (is_red(n->_right->_left)) {
        n->_right = rotate_right(n->_right);
        n = rotate_left(n);
        flip_colors(n);
    }

    return n;
}

tree::node* tree::move_red_right(node* n)
{
    flip_colors(n);
    if (is_red(n->_left->_left)) {
        n = rotate_left(n);
        flip_colors(n);
    }

    return n;
}

tree::node* tree::balance(node* n)
{
    if (is_red(n->_right) && !is_red(n->_left)) {
        n = rotate_left(n);
    }

    if (is_red(n->_left) && is_red(n->_left->_left)) {
        n = rotate_right(n);
    }

    if (is_red(n->_left) && is_red(n->_right)) {
        flip_colors(n);
    }

    n->_size = size(n->_left) + size(n->_right) + 1;

    return n;
}

tree::node* tree::min(node* n)
{
    if (n->_left == nullptr)
        return n;
    else
        return min(n->_left);
}

tree::node* tree::max(node* n)
{
    if (n->_right == nullptr)
        return n;
    else
        return max(n->_right);
}

tree::node* tree::delete_min(node* n)
{
    if (n->_left == nullptr) {
        return nullptr;
    }

    if (!is_red(n->_left) && !is_red(n->_left->_left)) {
        n = move_red_left(n);
    }

    n->_left = delete_min(n->_left);

    return balance(n);
}

tree::node* tree::delete_max(node* n)
{
    if (is_red(n->_left)) {
        n = rotate_right(n);
    }

    if (n->_right == nullptr) {
        return nullptr;
    }

    if (!is_red(n->_right) && !is_red(n->_right->_left)) {
        n = move_red_right(n);
    }

    n->_right = delete_max(n->_right);

    return balance(n);
}

tree::tree()
    : _root(nullptr)
{
}

tree::tree(tree& other)
    : _root(nullptr)
{
}

tree::~tree()
{
}

size_t tree::size() const
{
    return size(_root);
}

bool tree::is_empty() const
{
    return size() == 0;
}

bool tree::contains(int key) const
{
    return contains(_root, key);
}

void tree::insert(int key, ADT* value)
{
    if (value == nullptr) {
        erase(key);
        return;
    }

    _root = insert(_root, key, value);
    _root->_color = BLACK;
}

void tree::erase(int key)
{
    if (!contains(key)) {
        throw std::invalid_argument("key is not exist");
    }

    if (!is_red(_root->_left) && !is_red(_root->_right)) {
        _root->_color = RED;
    }

    _root = erase(_root, key);

    if (!is_empty()) {
        _root->_color = BLACK;
    }
}

ADT*& tree::operator[](int key)
{
    if (!contains(key)) {
        throw std::invalid_argument("key is not exist");
    }

    return get(_root, key);
}
