//
// Created by wangxing on 19-7-24.
//

#ifndef CODING_INTERVIEW_QUEUE_H
#define CODING_INTERVIEW_QUEUE_H

#include <utility>

template <typename T>
class Queue
{
public:
    // 使用链表数据结构实现队列
    // 构造函数
    Queue() : first(nullptr), last(nullptr), queueSize(0) {}
    Queue(Queue &&other) : first(std::move(other.first)), last(std::move(other.last)),queueSize(std::move(other.queueSize))  {}
    // 析构函数
    ~Queue()
    {
        while (!isEmpty())
        {
            remove();
        }
    }

    template <typename U>
    void add(U &&value)
    {
        auto n = new Node(std::forward<U>(value));
        // 队列为空
        if (!first)
        {
            first = n;
        } else {
            last -> next = n;
        }
        last = n;
        ++queueSize;
    }

    T &peek()
    {
        // 队列为空
        if (!first)
        {
            throw QueueIsEmptyException();
        }
        return first -> value;
    }

    T remove()
    {
        if (!first)
        {
            throw QueueIsEmptyException();
        }
        auto value(std::move(first->value));
        auto n = first;
        first = n -> next;
        if (!first)
        {
            last = nullptr;
        }
        delete n;
        --queueSize;
        return value;
    }

    bool isEmpty()
    {
        return !first;
    }

    size_t size() const
    {
        return queueSize;
    }

    class QueueIsEmptyException
    {

    };

private:
    struct Node
    {
        Node (T &&v): value(std::move(v)), next(nullptr) {}
        T value;
        Node *next;
    };

    Node *first;
    Node *last;
    size_t queueSize;
};



#endif //CODING_INTERVIEW_QUEUE_H
