#ifndef QUEUE_H
#define QUEUE_H

#include "IContainer.h"
#include "DoublyLinkedList.h"

template<typename T>
class Queue : public IContainer<T> 
{
private:
    DoublyLinkedList<T> list;

public:
    void push(const T& value) override 
    {
        list.push_back(value);
    }

    void pop() override 
    {
        list.pop_front();
    }

    bool isEmpty() const override 
    {
        return list.empty();
    }

    T& front() override 
    {
        return list.front();
    }

    const T& front() const override 
    {
        return list.front();
    }
};

#endif
