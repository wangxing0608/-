//
// Created by wangxing on 19-7-9.
//

// 2.2 查找单链表中倒数第k个节点

// 方法1： 使用双指针,向后移动第一个指针k个位置,再同时移动两个指针,当第一个指针到达尾节点时,第二个指针位于倒数第k个节点
// 方法2：

#include <iostream>

struct Node {
    int data;    // 节点数据
    Node *next;  // 指向下一个节点
    Node(int d): data{d}, next{nullptr} {}
};

/**
 * Insert to the head of the list
 * @param head - Current head of list
 * @param data - new node's data
 */
 void insert(Node * &head, int data)
{
     Node *newNode = new Node(data);
     newNode->next = head;
     head = newNode;
}

/**
 * [deleteList - delete the entire list]
 * @param head - head of the list
 */
 void deleteList(Node * &head){
     Node * nextNode;
     while(head) {
         head = head->next;
         delete(head);
         head = nextNode;
     }
 }

 /**
  * printList - Helper routine to print the list
  * @parm head - Current head of the list
  */
  void printList(Node *head)
 {
      while(head)
      {
          std::cout << head->data << "-->";
          head = head->next;
      }
      std::cout << "null" << std::endl;
 }

 /**
  * [kthToLastHelper - helper routine to find nth node for recursive approch]
  * @param head - head of the list
  * @param k - the k value for finding kth element from last of the list.
  * @param i - an index maintained to keep track of current node.
  * @return  - kth node from last.
  */
 Node *kthToLastHelper(Node *head, int k, int &i)
 {
     // 链表为空
     if (head == nullptr)
     {
         return nullptr;
     }

     // 递归调用
     Node *node = kthToLastHelper(head->next, k, i);
     i = i + 1;
     // if ew have solved problem k times from last/
     if (i == k)
     {
         return head;
     }
     return node;
 }


 /**
  * kthToLastRecursive - Recursive approach for finding kth to last element the list.
  * @param head  - head of node
  * @param k     - the k value for finding kth element from last of the list.
  * @return      - kth node form last.
  */
  Node * kthToLastRecursive(Node *head, int k)
 {
      int i = 0;
      return kthToLastHelper(head, k, i);
 }

 /**
  * kthToLastIterative - Iterative approach for finding kth to last element of list.
  * @param head - head of node
  * @param k    - the k value for finding kth element from last of the list
  * @return     - kth node from last.
  */
  Node * kthToLastIterative(Node *head, int k)
 {
      // 链表为空
      if (head == nullptr)
      {
          return head;
      }

      Node *ptr1 = head;      // ptr1 指针指向列表后方元素
      Node *ptr2 = head;      // ptr2 指针
      int i = 0;   // 计数器
      while (i < k && ptr1)
      {
          ptr1 = ptr1 -> next;
          ++i;
      }

      // 链表长度小于k
      if (i < k)
      {
          return nullptr;
      }

      while (ptr1 != nullptr)
      {
          // 向后移动两个指针
          ptr1 = ptr1 -> next;
          ptr2 = ptr2 -> next;
      }
      return ptr2;
 }

 int main()
 {
      Node *head = nullptr;
      for (int i = 7; i > 0; i--)
      {
          insert(head, i);
      }
      std::cout << "List: ";
      printList(head);

      std::cout << "4th node from last (Recursive): ";
      Node *node4 = kthToLastRecursive(head, 4);
      if (node4 != nullptr)
      {
          std::cout << node4->data << std::endl;
      } else {
          std::cout << "NULL NODE\n";
      }

     std::cout << "4th node from last (Iterative): ";
     node4 = kthToLastRecursive(head, 4);
     if (node4 != nullptr)
     {
         std::cout << node4->data << std::endl;
     } else {
         std::cout << "NULL NODE\n";
     }

     deleteList(head);
     return 0;
 }
