#include <iostream>
#include <fstream>

// Container interface
template<typename T>
class IContainer 
{
public:
    virtual void push(const T& value) = 0;
    virtual void pop() = 0;
    virtual bool isEmpty() const = 0;
    virtual T& front() = 0;
    virtual ~IContainer() {}
};

// Doubly linked list node
template<typename T>
struct Node 
{
    T data;
    Node<T>* prev;
    Node<T>* next;
    Node(const T& value) : data(value), prev(nullptr), next(nullptr) {}
};

// Doubly Linked List Template Class
template<typename T>
class DoublyLinkedList 
{
private:
    Node<T>* head;
    Node<T>* tail;

    void clear() 
    {
        while (head) 
        {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
    }

    void copyFrom(const DoublyLinkedList& other) 
    {
        Node<T>* curr = other.head;
        while (curr) 
        {
            push_back(curr->data);
            curr = curr->next;
        }
    }

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Copy constructor
    DoublyLinkedList(const DoublyLinkedList& other) : head(nullptr), tail(nullptr) 
    {
        copyFrom(other);
    }

    // Assignment operator
    DoublyLinkedList& operator=(const DoublyLinkedList& other) 
    {
        if (this != &other) 
        {
            clear();
            copyFrom(other);
        }
        return *this;
    }

    // Destructor
    ~DoublyLinkedList() 
    {
        clear();
    }

    void push_back(const T& value) 
    {
        Node<T>* node = new Node<T>(value);
        if (!tail) 
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

    void pop_front() 
    {
        if (!head) return;
        Node<T>* temp = head;
        head = head->next;
        if (head) head->prev = nullptr;
        else tail = nullptr;
        delete temp;
    }

    T& front() 
    {
        if (!head) throw std::runtime_error("List is empty");
        return head->data;
    }

    bool empty() const 
    {
        return head == nullptr;
    }
};

// The Queue class, implemented on a doubly linked list
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
};

// Main program
int main() 
{
    Queue<char> chars;
    Queue<char> digits;

    std::ifstream file("input.txt");
    if (!file) 
    {
        std::cerr << "Error, unable to open a file!\n";
        return 1;
    }

    char ch;
    while (file.get(ch)) 
    {
        if (isdigit(ch)) 
        {
            digits.push(ch);
        }
        else 
        {
            chars.push(ch);
        }
    }

    // Symbols first (not digits)
    while (!chars.isEmpty()) 
    {
        std::cout << chars.front();
        chars.pop();
    }

    // Then the digits
    while (!digits.isEmpty()) 
    {
        std::cout << digits.front();
        digits.pop();
    }

    std::cout << std::endl;
    return 0;
}
