//
// Created by wangxing on 19-7-13.
//

// 2.5 有两个由链表表示的数字,其中每个节点包含一个数字
// 链表中的数字以相反的顺序存储,第一位的数字出现在链表开头
// 对链表中的数字求和并以链表的形式返回

#include <iostream>

struct Node {
    int data;
    Node *next;
    Node (int d) : data {d}, next {nullptr} {};
};

/**
 * [insert - insert a new node at head of the list]
 * @param head [head of the list]
 * @param data [new node's data]
 */
 void insert(Node * &head, int data) {
     Node *newNode = new Node(data);
     newNode -> next = head;
     head = newNode;
 }

 /**
  * [printList - print the list]
  * @param head [head of the list]
  */
 void printList(Node *head) {
     while (head) {
         std::cout << head -> next << "-->";
         head = head -> next;
     }
     std::cout << "nullptr" << std::endl;
 }

 /**
  * [addLists_iterative iterative approach to add two given lists]
  * @param list1
  * @param list2
  * @return list3
  */

 // 使用迭代法求两个链表表示的数值的和
 Node * addLists_iterative(Node *list1, Node *list2) {
     // 链表1为空,返回链表2表示的数值
     if (list1 == nullptr)
     {
         return list2;
     }
     // 链表2为空,返回链表1表示的数值
     if (list2 == nullptr)
     {
         return list1;
     }
     // 使用链表3作为最后的结果链表
     Node *list3 = nullptr;
     // 将新添加的节点链接到链表3的尾部
     Node *list3Tail = nullptr;
     //保存当前节点的值和进位值
     int value = 0, carry = 0;
     while (list1 || list2)
     {
         // 求两个两个链表中当前节点的和
         value = carry + (list1 ? list1 -> data : 0) + (list2 ? list2 -> data : 0);
         if  (value > 9) {
             carry = 1;  // 进位为1
             value = value % 10;
         }
         else {
             carry = 0;
         }
         // 新建节点
         Node * temp = new Node(value);

         // 如果该节点是链表3的第一个节点
         if (list3 == nullptr) {
             list3 = temp;
         }
         else {
             list3Tail -> next = temp;
         }
         // 向后移动list3Tail指针
         list3Tail = temp;

         if (list1) {
             list1 = list1 -> next;  // 链表1向后移动一个节点
         }
         if (list2) {
             list2 = list2 -> next;  // 链表2向后移动一个节点
         }
     }
     if (carry > 0) {
         list3Tail -> next = new Node(carry);
     }
     return list3;
 }
  /**
* [addList3_recursive - recursive addition of two list3]
* @param list1
* @param list2
* @param carry
* @return list3
*/
// 使用迭代法求两个链表表示的数值的和
Node * addList3_recursive(Node *list1, Node *list2, int carry)
{
    if (list1 == nullptr && list2 == nullptr && carry == 0)
    {
        return nullptr;
    }
    int value = carry;
    if (list1) {
        value += list1 -> data;
    }
    if (list2) {
        value += list2 -> data;
    }

    Node *resultNode = new Node(value%10);
    resultNode -> next = addList3_recursive(list1 ? (list1 -> next) : nullptr,
            list2 ? (list2 -> next) : nullptr, value > 9 ? 1 :0);
    return resultNode;
}




































































































