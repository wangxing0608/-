//
// Created by wangxing on 19-7-19.
//

#include "FixedMultiStack.h"

// 构造函数实现
FixedMultiStack::FixedMultiStack(int stackCapacity)
{
    this -> stackCapacity = stackCapacity;               // 每个栈的存储能力
    stackArray = new int [numOfStack * stackCapacity];   // 存储栈的数组
    stackCapacityUsed = new int[numOfStack]();
}

// 析构函数实现
FixedMultiStack::~FixedMultiStack()
{
    delete [] stackArray;
    delete [] stackCapacityUsed;
}

// 向指定栈中添加元素
void FixedMultiStack::push(int stackNum, int value)
{
    if (isFull(stackNum))
    {
        std::cout << "Stack "<< stackNum << "is full.";
    }
    else
    {
        stackCapacityUsed[stackNum]++;
        stackArray[indexOfTop(stackNum)] = value;
    }
}

void FixedMultiStack::pop(int stackNum)
{
    if (isEmpty(stackNum))
    {
        std::cout << "Stack " stackNum << "is empty.";
    }
    else
    {
        int topIndex = indexOfTop(stackNum);
        stackArray[topIndex] = 0;
        stackCapacityUsed[stackNum]--;
    }
}

int FixedMultiStack::top(int stackNum) const
{
    if (isEmpty(stackNum))
    {
        std::cout << "Stack" << stackNum << " is empty.\n";
        exit(0);
    }
    else
    {
        return stackArray[indexOfTop(stackNum)];
    }
}

bool FixedMultiStack::isEmpty(int stackNum) const
{
    return (stackCapacityUsed[stackNum] == 0);
}

bool FixedMultiStack::isFull(int stackNum) const
{
    return (stackCapacityUsed[stackNum] == stackCapacity);
}

int FixedMultiStack::indexOfTop(int stackNum) const
{
    int startIndex = stackNum * stackCapacity;
    int capacity = stackCapacityUseds[stackNum];
    return (startIndex + capacity -1);
}
