//
// Created by wangxing on 19-7-20.
//

#include "StackNode.h"

StackNode::StackNode(int data, StackNode *next)
{
    this -> data = data;
    this -> next = next;
    minimum = nullptr;
}