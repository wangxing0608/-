//
// Created by wangxing on 19-7-20.
//

#ifndef CODING_INTERVIEW_STACK_H
#define CODING_INTERVIEW_STACK_H

#include "StackNode.h"
#include <iostream>
#include <cstdlib>

class Stack
{
public:
    Stack();            // 默认构造函数
    virtual ~Stack();   // 析构函数
    void push();
    int pop();
    int top() const;
    int getMinimum() const;

    bool isEmpty() const;
    int getSize() const;

private:
    StackNode *head;
    int stackSize;
};

#endif //CODING_INTERVIEW_STACK_H
