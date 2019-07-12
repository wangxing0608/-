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
    Node (int d): data{ d }, nect {nullptr} {}
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
    Node *head = nullptr;
    Node *headInitial = nullptr;   //
    Node *tail = nullptr;
    Node *tailInitial = nullptr;
    Node *curr = listhead;
    // 遍历链表
    while (curr != nullptr)
    {
        Node *nextNode = curr -> next;
        // 当前节点元素小于x
        if (curr -> data < x) {
            if (head == nullptr) {
                head = curr;
                headInitial = head;
            }
            head -> next = curr;
            head = curr;
        }
        else {
            if (tail == nullptr) {
                tail = curr;
                tailInitial = tail;
            }
            tail -> next = curr;
            tail = curr;
        }
        curr = nextNode;
    }
    head -> next = tailInitial;
    tail -> next = nullptr;
    return headInitial;
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
    print(partition(head, 5));
    return 0;
}

