//
// Created by wangxing on 19-7-23.
//

// 对栈中的元素进行排序,栈顶保存栈中最小的元素
// 只能使用一个额外的栈,并且不能将元素复制到其他任何数据结构

#include <iostream>
#include "Stack.h"

template <typename T>
class StortedStack
{
public:
    StortedStack() : sorted(false)  { }

    template <typename U>
    void push(U &&value)
    {
        stack.push(std::forward<U>(value));
    }

    T &peek()
    {
        sort();
        return stack.peek();
    }

    T pop()
    {
        sort();
        return stack.pop();
    }

    bool isEmpty() const
    {
        return stack.isEmpty();
    }

private:
    // 排序算法
    void sort()
    {
        if (sorted)
        {
            return;
        }
        Stack<T> helper;   // 额外的排序辅助栈
        while (!stack.isEmpty())
        {
            T value = stack.pop();
            // 将helper栈中大于stack栈顶元素的元素放入stack栈
            while (!helper.isEmpty() && value < helper.peek())
            {
                stack.push(helper.pop());
            }

            // 将value保存的stack栈中的栈顶元素放入helper栈中
            helper.push(std::move(value));
        }

        // 将helper栈中排好序的元素放回stack栈
        while (!helper.isEmpty())
        {
            stack.push(helper.pop());
        }
        sorted = true;
    }

    Stack<T> stack;
    bool sorted;
};

int main()
{
    StortedStack<int> stack;
    for (auto v : {5, 10, 4, 9, 3, 8, 1, 2, 2, 7, 6})
    {
        stack.push(v);
        std::cout << "Pushed value: " << v << std::endl;
    }

    std::cout << std::endl;

    while (!stack.isEmpty())
    {
        auto v = stack.pop();
        std::cout << "Poped value: " << v << std::endl;
    }
    return 0;
}