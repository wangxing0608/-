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
         std::cout << head -> data << "-->";
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
Node * addLists_recursive(Node *list1, Node *list2, int carry)
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
    resultNode -> next = addLists_recursive(list1 ? (list1 -> next) : nullptr,
            list2 ? (list2 -> next) : nullptr, value > 9 ? 1 : 0);
    return resultNode;
}

/**
 * Follow up part:
 * Lists are stored such that 1's digit is at tail of lists
 * 617 ==> 6 --> 1 --> 7
 * 295 ==> 2 --> 9 --> 5
 */

/**
 * [padList - Helper routine for padding the shorter list]
 * @param list [Current list]
 * @param padding [number of padding required]
 */
 // 填充较短的链表,在链表头部添0
 void padList(Node * &list, int padding)
 {
     for (int i = 0; i < padding; ++i)
     {
         insert(list, 0);
     }
 }

 /**
  * [length - helper routine to return length of list]
  * @param head [list's head]
  * @return length of the list
  */
 // 返回链表的长度
 int length(Node * head)
 {
     int len = 0;
     while (head)
     {
         len++;
         head = head -> next;
     }
     return len;
 }

 Node * addLists_followup_helper(Node *list1, Node *list2, int &carry)
 {
     // 递归终止条件
     if (list1 == nullptr && list2 == nullptr && carry == 0)
     {
         return nullptr;
     }

     // 递归调用
     Node * result = addLists_followup_helper(list1 ? (list1 -> next) : nullptr,
             list2 ? (list2 -> next) : nullptr, carry);

     int value = carry + (list1 ? list1 -> data : 0) + (list2 ? list2 -> data : 0);
     insert(result, value % 10);
     carry = (value > 9) ? 1 : 0;  // 进位标志
     return result;
 }

 /**
  * [addLists_followup - adding list such that 1's digit is at tail (follow up part of question)]
  * @param list1
  * @param list2
  * @return list3 representing sum of list1 and list2
  */
  Node * addLists_followup(Node *list1, Node *list2)
 {
      int len1 = length(list1);
      int len2 = length(list2);

      // 填充较短的链表
      if (list1 > list2)
      {
          padList(list2, len1-len2);
      }
      else {
          padList(list1, len2-len1);
      }

      int carry = 0;
      Node * list3 = addLists_followup_helper(list1, list2, carry);
      // 如果最高位有进位
      if (carry)
      {
          insert(list3, carry);
      }
      return list3;
 }

 /**
  * [deleteList - helper routine to delete list]
  * @param head [head of the list]
  */
  void deleteList(Node * &head)
 {
      Node *nextNode;
      while (head)
      {
          nextNode = head;
          delete(head);
          head = nextNode;
      }
 }

 int main()
 {
      // making list1 for number 617
      Node *list1 = nullptr;
      insert(list1, 6);
      insert(list1, 1);
      insert(list1, 7);
      std::cout << "list1: ";
      printList(list1);

      // making list2 for number 295
     Node *list2 = nullptr;
     insert(list2, 2);
     insert(list2, 9);
     insert(list2, 5);
     std::cout << "list2: ";
     printList(list2);

     Node * list3 = addLists_iterative(list1, list2);
     std::cout << "Iterative Solution: \n";
     std::cout << "List3: ";
     printList(list3);

     Node * list4 = addLists_recursive(list1, list2, 0);
     std::cout << "Iterative Solution: \n";
     std::cout << "List4: ";
     printList(list4);

     deleteList(list1);
     deleteList(list2);
     deleteList(list3);
     deleteList(list4);

     std::cout << "\n\nNow follow up case, lists are stored such that 1's digit is at the tail of list\n";
     insert(list1, 4);
     insert(list1, 3);
     insert(list1, 2);
     insert(list1, 9);
     std::cout << "List1:  ";
     printList(list1);

     insert(list2, 9);
     insert(list2, 9);
     insert(list2, 8);
     std::cout << "List2:  ";
     printList(list2);

     list3 = addLists_followup(list1, list2);
     std::cout << "Adding two above lists\n";
     std::cout << "List3:  ";
     printList(list3);

     deleteList(list1);
     deleteList(list2);
     deleteList(list3);

     return 0;
 }
