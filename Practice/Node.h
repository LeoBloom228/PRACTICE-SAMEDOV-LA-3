#ifndef NODE_H
#define NODE_H

template<typename T>
struct Node 
{
    T data;
    Node<T>* prev;
    Node<T>* next;

    Node(const T& value) : data(value), prev(nullptr), next(nullptr) {}
};

#endif
