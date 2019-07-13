//
// Created by wangxing on 19-7-12.
//

// 2.3 使用x分隔链表中的节点,使得节点中数值小于x的出现在x节点之前,大于x的出现在x之后
// 如果x出现在链表中,只需要出现在比它小的节点之后

#include <iostream>
#include <random>

struct Node {
    int data;
    Node *next;
    Node (int d): data{ d }, next {nullptr} {}
};

void insert(Node * &head, int data)
{
    Node *newNode = new Node(data);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node *curr = head;
        // 链表的头插法
        while (curr->next)
        {
            curr = curr -> next;
        }
        curr -> next = newNode;
    }
}

void printList(Node *head)
{
    while (head)
    {
        std::cout << head->data << "-->";
        head = head -> next;
    }
    std::cout << "nullptr" << std::endl;
}

// 将链表中元素值大于x的插入到x之后,小于x的插入到头结点之后
Node *partition(Node *listhead, int x)
{
    Node *head = nullptr;          //  head 链表中的指针
    Node *headInitial = nullptr;   //  head 链表的头结点
    Node *tail = nullptr;
    Node *tailInitial = nullptr;   // tail 链表中的指针
    Node *curr = listhead;         // tail链表的头结点
    // 遍历链表
    while (curr != nullptr)
    {
        Node *nextNode = curr -> next;
        // 当前节点元素小于x,在head链表中添加节点
        if (curr -> data < x) {
            // 如果tail链表为空,使用第一个小于x的元素初始化head链表
            if (head == nullptr) {
                head = curr;
                headInitial = head;
            }
            // head链表非空, head指针指向的节点链接在head链表后
            head -> next = curr;
            head = curr;
        }
        //  当前元素大于等于x,在tail链表中添加节点
        else {
            // 如果tail链表为空,使用第一个小于x的元素初始化head链表
            if (tail == nullptr) {
                tail = curr;
                tailInitial = tail;
            }
            // tail链表非空, tail指针指向的节点链接在head链表后
            tail -> next = curr;
            tail = curr;
        }
        curr = nextNode;
    }
    // 原始链表遍历完后,将两个链表链接在一起
    head -> next = tailInitial;
    tail -> next = nullptr;   // tail指针指向新的链表的最后一个节点,它的尾节点为nullptr
    return headInitial;       // 返回新的链表
}

int main()
{
    Node *head = nullptr;
    for (int i = 0; i < 10; i++)
    {
        insert(head, rand() % 9);
    }
    std::cout << "List before partition around 5:\n";
    printList(head);
    std::cout << "List after partition around 5:\n";
    printList(partition(head, 5));
    return 0;
}

