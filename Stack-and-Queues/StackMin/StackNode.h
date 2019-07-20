//
// Created by wangxing on 19-7-20.
//

#ifndef CODING_INTERVIEW_STACKNODE_H
#define CODING_INTERVIEW_STACKNODE_H

class Stack;

class StackNode
{
public:
    friend class Stack;     // 定义友元类
    StackNode(int data, StackNode *next);

private:
    int data;
    StackNode *next;
    StackNode *minimum;
};

#endif //CODING_INTERVIEW_STACKNODE_H
