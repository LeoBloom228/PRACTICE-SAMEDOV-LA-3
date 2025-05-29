#ifndef ICONTAINER_H
#define ICONTAINER_H

template<typename T>
class IContainer
{
public:
    virtual ~IContainer() = default;

    virtual void push(const T& value) = 0;
    virtual void pop() = 0;
    virtual bool isEmpty() const = 0;

    virtual T& front() = 0;
    virtual const T& front() const = 0;
};

#endif
