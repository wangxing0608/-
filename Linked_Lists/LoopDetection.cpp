//
// Created by wangxing on 19-7-18.
//

// 确定一个链表是否为循环离链表,如果是,返回循环开始节点

#include <iostream>

struct Node {
    int data;
    Node *next;
    Node(int d) : data {d}, next {nullptr} {}
};

// 删除链表中的循环
void removeLoop(Node *loopNode, Node *head)
{
    Node *ptr1 = head;
    Node *ptr2 = loopNode;
    while (ptr1 -> next != ptr2 -> next)
    {
        ptr1 = ptr1 -> next;
        ptr2 = ptr2 -> next;
    }
    // ptr2指针到达链表循环的开始节点处
    ptr2 -> next = nullptr;
}

// 检测链表中的循环并删除
bool detectAndRemoveCycle(Node *head)
{
    if (head == nullptr)
    {
        return false;
    }
    Node *fastPtr = head;
    Node *slowPtr = head;
    while (slowPtr && fastPtr && fastPtr -> next)
    {
        fastPtr = fastPtr -> next ->next;  // 快指针一次向前移动两个节点
        slowPtr = slowPtr -> next;         // 慢指针一次向前移动一个节点
        // 链表中存在循环
        if (fastPtr == slowPtr)
        {
            removeLoop(slowPtr, head);   // 删除链表中的循环
            return true;
        }
    }
    return false;   // 链表没有循环
}

void insert(Node * &head, int data)
{
    Node *newNode = new Node(data);
    if (head == nullptr)
    {
        head = newNode;
    } else {
        Node *temp = head;
        // 尾插法在链表中插入新节点
        while (temp -> next != nullptr)
        {
            temp = temp -> next;
        }
        temp -> next = newNode;
    }
}

void printList(Node *head)
{
    while (head )
    {
        std::cout << head -> data << "-->";
        head = head -> next;
    }
    std::cout << "nullptr" << std::endl;
}

int main()
{
    Node *head = nullptr;
    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    insert(head, 5);
    std::cout << "Current List:\n";
    printList(head);
    std::cout << "Inserting loop, connecting 5 to 2 \n";
    head -> next -> next -> next -> next -> next = head -> next;
    std::cout << "Detecting and deleting loop \n";
    detectAndRemoveCycle(head);
    std::cout << "Back to the same old list \n";
    printList(head);
    return 0;
}