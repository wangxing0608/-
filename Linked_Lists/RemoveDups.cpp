//
// Created by wangxing on 19-7-7.
//

// 2.1 链表去重： 从未排序的链表中删除重复元素

// 方法1： 使用双指针,删除链表中当前节点之后的可能存在的重复节点, 空间复杂度:O(1),时间复杂度:O(n^2)
// 方法2： 使用hash方法,迭代链表中的元素,如果该节点的元素第一次出现,则存入链表
// 向后移动指针,如果指针所指节点已经在hash表中出现,则删除该指针所指节点

#include <iostream>
#include <unordered_map>
#include <random>

// 定义链表节点类型
struct Node {
    int data = 0;            // int类型的数据单元
    Node *next = nullptr;    // 指向下一节点的指针
};

/**
 *  [insert - insert a node at the head of list]
 *  @param head [head of the list]
 *  @param data [new node's data]
 */
// 使用头插法在链表中插入新的元素
void insert(Node * & head, int data)
{
    // 创建新的头节点
    Node * newNode = new Node;
    newNode->data = data;
    newNode->next = head;   // newNode作为头结点
    head = newNode;
}

/**
 * [printList Helper routine to print list]
 * @param head [head of the list]
 */
 void printList(Node *head)
{
     while(head)
     {
         std::cout << head->data << "-->";
         head = head->next;
     }
     std::cout << "nullptr" << std::endl;
}

// generate a random int between min and max
/**
 * [rand_range helper routine to generate a random number between min and max (including)]
 * @param min [min of range]
 * @param max [max of range]
 * @return [A random number between min and max]
 */
static inline int random_range(const int min, const int max)
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> distribution(min, max);
    return distribution(mt);
}

//Method1
// space complexity O(1)
// time complexity O(n^2)
/**
 * [removeDups1 Remove without using extra space]
 * @param head [head of list]
 */
void removeDups1(Node *head)
{
    // 如果链表为空,或者链表只含一个元素
    if (head == nullptr || (head && (head->next == nullptr)))
    {
        return;
    }
    Node *curr = head;  // 指向要遍历的链表元素
    //遍历链表
    while (curr)
    {
        Node * runner = curr;   //遍历器,遍历该节点之后的节点,查找是否有重复元素
        while (runner->next != nullptr)
        {
            // 存在重复元素
            if (runner->next->data == curr->data)
            {
                runner->next = runner->next->next;   //删除重复元素
            } else {
                runner = runner->next;   // runner 向后移动一个节点
            }
        }
        curr = curr->next;   // 向后移动到下一个待检测节点
    }
}

//Method2
//space complexity O(n)
//time complexity O(n)
/**
 * [removeDuplicates2 Reomve duplicates from the list using hash table]
 * @param head [head of list]
 */
 void removeDups2(Node *head)
{
     // 链表为空或只含一个元素
     if (head == nullptr || (head && (head->next == nullptr)))
     {
         return;
     }
     std::unordered_map<int, int> node_map;
     Node *prev = head;
     Node *curr = head->next;
     node_map[head->data] = 1;   // 将链表的头元素放入hash表
     while (curr != nullptr)
     {
         // 该节点后面的节点中存在重复元素
         while (curr && node_map.find(curr->data) != node_map.end())
         {
             curr = curr->next;
         }
         prev = curr;
         if (curr) {
             node_map[curr->data] = 1;
             curr = curr->next;
         }
     }
}

int main()
{
     std::cout << "Method1 : \n";
     Node *head = nullptr;
     for (int i = 0; i < 10; i++)
     {
         insert(head, random_range(1, 7));
     }
     printList(head);
     removeDups1(head);
     printList(head);

    std::cout << "Method2 : \n";
    Node *head1 = nullptr;
    for (int i = 0; i < 10; i++)
    {
        insert(head1, random_range(1, 7));
    }
    printList(head1);
    removeDups1(head1);
    printList(head1);
    return 0;
}




































































