#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include "Node.h"
#include <iostream>
#include <stdexcept>

template<typename T>
class DoublyLinkedList 
{
private:
    Node<T>* head;
    Node<T>* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    ~DoublyLinkedList() 
    {
        clear();
    }

    DoublyLinkedList(const DoublyLinkedList& other) : head(nullptr), tail(nullptr) 
    {
        Node<T>* current = other.head;
        while (current != nullptr) 
        {
            push_back(current->data);
            current = current->next;
        }
    }

    DoublyLinkedList& operator=(const DoublyLinkedList& other) 
    {
        if (this != &other) 
        {
            clear();
            Node<T>* current = other.head;
            while (current != nullptr) 
            {
                push_back(current->data);
                current = current->next;
            }
        }
        return *this;
    }

    void push_back(const T& value) 
    {
        Node<T>* node = new Node<T>(value);
        if (tail == nullptr) 
        {
            head = tail = node;
        }
        else 
        {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
    }

    void push_front(const T& value) 
    {
        Node<T>* node = new Node<T>(value);
        if (head == nullptr) 
        {
            head = tail = node;
        }
        else 
        {
            node->next = head;
            head->prev = node;
            head = node;
        }
    }

    void pop_front() 
    {
        if (head == nullptr) 
        {
            std::cerr << "Error: an attempt to remove an item from an empty list.\n";
            return;
        }

        Node<T>* temp = head;
        head = head->next;
        if (head != nullptr) 
        {
            head->prev = nullptr;
        }
        else 
        {
            tail = nullptr;
        }
        delete temp;
    }

    void pop_back() 
    {

        if (tail == nullptr) 
        {
            std::cerr << "Error: an attempt to remove an item from an empty list.\n";
            return;
        }

        Node<T>* temp = tail;
        tail = tail->prev;
        if (tail != nullptr) 
        {
            tail->next = nullptr;
        }
        else 
        {
            head = nullptr;
        }
        delete temp;
    }

    T& front() 
    {
        if (head == nullptr) throw std::out_of_range("The list is empty");
        return head->data;
    }

    const T& front() const 
    {
        if (head == nullptr) throw std::out_of_range("The list is empty");
        return head->data;
    }

    T& back() 
    {
        if (tail == nullptr) throw std::out_of_range("The list is empty");
        return tail->data;
    }

    const T& back() const 
    {
        if (tail == nullptr) throw std::out_of_range("The list is empty");
        return tail->data;
    }

    bool empty() const 
    {
        return head == nullptr;
    }

    void clear() 
    {
        while (head != nullptr) 
        {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
    }
};

#endif
