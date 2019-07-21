//
// Created by wangxing on 19-7-21.
//

#ifndef HELLO_WORLD_STACK_H
#define HELLO_WORLD_STACK_H

#include <utility>

// 栈的模板类
template <typename T>
class Stack
{
public:
    Stack () : top(nullptr), stackSize (0) {}
    Stack (Stack &&other) : top(std::move(other.top)), stackSize(std::move(other.stackSize)) {}
    ~Stack()
    {
        while (!isEmpty())
            pop();
    }

    template <typename U>
    void push(U &&value)
    {
        auto n = new Node(std::forward<U>(value), top);
        top = n;
        ++stackSize;
    }
    T &peek()
    {
        if (!top)
            throw StackIsEmptyException();
        return top -> value;
    }

    T pop()
    {
        if (!top)
            throw StackIsEmptyException();
        auto value(std::move(top -> value));
        auto n = top;
        top = n -> next;
        delete n;
        --stackSize;
        return value;
    }

    bool isEmpty() const
    {
        return !top;
    }

    size_t size() const
    {
        return stackSize;
    }

    class StackIsEmptyException
    {

    };

private:
    struct Node
    {
        Node (T &&v, Node *n) : value (std::move(v)), next(n) { }
        Node (const T &v, Node *n) : value(v), next(n) {}

        T value;
        Node *next;
    };

    Node *top;
    size_t stackSize;
};
#endif //HELLO_WORLD_STACK_H
