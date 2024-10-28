#ifndef LAB4_NODE_H
#define LAB4_NODE_H

#include <iostream>

template <typename T>
struct Node{
    T value;
    Node<T>* left;
    Node<T>* right;

    explicit Node(const T& val) : value(val), left(nullptr), right(nullptr) {}
};

#endif //LAB4_NODE_H
