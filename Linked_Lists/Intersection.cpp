//
// Created by wangxing on 19-7-17.
//

// 2.7 判断两个链表是否相交,如果相交,返回相交的节点
// 首先确定两个链表是否相交:如果两个链表的尾节点地址相同,则两个链表相交
// 再确定相交的节点： 如果两个链表长度相同,则同同步遍历两个链表,当它们发生碰撞时该节点为相交节点
// 如果两链表长度不等,则根据第一步求得的链表长度,截取它们相同的长度进行遍历

#include <iostream>
#include <cmath>

struct Node {
    int data;
    Node *next;
    Node (int d) : data {d}, next {nullptr} {}
};

/**
 * [printList helper routine to print list]
 * @param head [head of the list]
 */
void printList(Node *head)
{
    while (head)
    {
        std::cout << head -> data << "-->";
        head = head -> next;
    }
    std::cout << "nullptr" << std::endl;
}

int listLen(Node *head)
{
    int count = 0;
    while (head)
    {
        head = head -> next;
        count ++;
    }
    return count;
}

/**
 * [interSectionPoint returns the point of intersection of two lists]
 */

// 返回两个链表中相交的节点
Node *intersectionPoint(Node *head1, Node *head2)
{
    int len1 = listLen(head1);   // 链表1长度
    int len2 = listLen(head2);   // 链表2长度

    // ptr1指针指向较长的链表,ptr2指针指向较短的链表
    Node *ptr1 = (len1 > len2) ? head1 : head2;
    Node *ptr2 = (len1 > len2) ? head2 : head1;
    int i = 0;
    while (i < std::abs(len1 - len2) && ptr1)
    {
        ptr1 = ptr1 -> next;
        ++i;
    }

    // 现在ptr1 和ptr2指针所指的两个链表长度相同
    // 遍历两个长度相同的链表,找到它们的交叉点
    while (ptr1 && ptr2)
    {
        if (ptr1 == ptr2)
        {
            return ptr1;
        }
        ptr1 = ptr1 -> next;
        ptr2 = ptr2 -> next;
    }
    return nullptr;
}

int main()
{
    Node *list1 = new Node(3);
    list1 -> next = new Node(6);
    list1 -> next -> next = new Node(6);
    list1 -> next -> next -> next = new Node(12);
    list1 -> next -> next -> next -> next = new Node(15);
    list1 -> next -> next -> next -> next -> next = new Node(18);

    Node *list2 = new Node(7);
    list2 -> next = new Node(10);
    list2 -> next -> next = list1 -> next -> next -> next;

    printList(list1);
    printList(list2);

    Node *intersectionNode = intersectionPoint(list1, list2);
    if (intersectionNode)
    {
        std::cout << "Intersecting Node of lists is: " << intersectionNode -> data << std::endl;
    } else {
        std::cout << "Lists do not intersect" << std::endl;
    }

    return 0;
}
