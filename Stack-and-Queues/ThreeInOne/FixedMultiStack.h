//
// Created by wangxing on 19-7-19.
//

#ifndef CODING_INTERVIEW_FIXEDMULTISTACK_H
#define CODING_INTERVIEW_FIXEDMULTISTACK_H


class FixedMultiStack
{

public:
    // Create 3 stacks. each stack is of size stackCapacity
    FixedMultiStack(int stackCapacity);   // 构造函数
    virtual ~FixedMultiStack();           // 析构函数

    // Push an element from stack stackNum, where stackNum is 0 to 2
    void push(int stackNum, int value);

    // Pop the top element from stack stackNum, where stackNum is 0 to 2
    void pop(int stackNum);

    // Return the top element on stack stackNum, where stackNum is 0 to 2
    int top(int stackNum);

    bool isEmpty(int stackNum) const;
    bool isFull(int stackNum)  const;

private:
    int numOfStack = 3;
    int stackCapacity;   // 栈容量
    int *stackArray;
    int *stackCapacityUsed;

    // Return the top index of stack stackNum, where stackNum is from 0 to 2
    int indexOfTop(int stackNum) const;
};

#endif //CODING_INTERVIEW_FIXEDMULTISTACK_H
