//
// Created by wangxing on 19-7-15.
//

// 判断一个链表中的所有节点是否构成回文
// 方法1: 翻转链表并比较,只需要比较原始链表的前半部分和翻转链表的前半部分是否相等



#include <iostream>
#include <stack>

struct Node {
    char data;
    Node *next;
    Node (char c) : data {c}, next {nullptr} {}
};

/**
 * [insert helper routine to insert new node at head]
 * @param head [current head of the list]
 * @param c [new node's data]
 */
void insert(Node * &head, char c)
{
    Node *newNode = new Node(c);
    newNode -> next = head;
    head = newNode;
}

 /**
  * [printList helper routine to print the list]
  * @param head [head of the list]
  */

 void printList(Node *head)
 {
     while (head)
     {
         std::cout << head -> data << "-->";
         head = head->next;
     }
     std::cout << "nullptr" << std::endl;
 }

 /**
  * [reverseList helper routine to reverse a list]
  * @param head [head of current list]
  * @return [reversed list's head]
  */

 // 翻转链表
 void reverse(Node * &head)
 {
      // 链表为空,或链表中只有一个节点
      if (head == nullptr || head && (head -> next == nullptr))
      {
          return;
      }
      Node *newHead = nullptr;
      Node *nextNode = nullptr;
      while (head)
      {
          nextNode = head -> next;
          head ->next = newHead;
          newHead = head;
          head = nextNode;
      }
      head = newHead;
 }

 /**
  * [isPalindromeIter1 Iteratively determine if list is palindrome using reversing the list]
  * @param head [head node of the list]
  * @return [True if list is palindrome, false if not]
  */
// 使用f翻转链表的方法判断一个链表是否为回文
bool isPalindromeIter1(Node *head)
{
    // 如果链表为空或链表只有一个元素
    if (head == nullptr || head ->next == nullptr)
    {
        return true;
    }

    // 找到链表的中间节点
    Node *ptr1 = head;
    Node *ptr2 = head;
    Node *middleNode = nullptr;
    while (ptr2 && ptr1 && ptr1->next)
    {
        ptr1 = ptr1 -> next -> next;
        ptr2 = ptr2 -> next;
    }

    // 链表节点数为奇数
    if (ptr1 && ptr1 -> next == nullptr)
    {
        ptr2 = ptr2 -> next;
    }

    // 翻转列表的后半部分
    reverse(ptr2);

    middleNode = ptr2;

    ptr1 = head;

    while (ptr1 && ptr2 && ptr1 -> data == ptr2 ->data)
    {
        ptr1 = ptr1 -> next;
        ptr2 = ptr2 -> next;
    }

    // 再一次翻转链表
    reverse(middleNode)
    if (ptr2 == nullptr) {
        return true;
    }
    else {
        return false;
    }
}

/**
 * [isPalindromeIter2 - Iterative determine if list is palindrome using a stack]
 * @param head [head node of the list]
 * @return [True if list is palindrome, false if not]
 */

bool isPalindromeIter2(Node *head)
{
    // 链表为空或只有一个元素
    if (head == nullptr || head ->next == nullptr)
    {
        return true;
    }

    // 快慢指针遍历链表,得到链表中的一半节点
    Node *ptr1 = head;
    Node *ptr2 = head;

    // 存储链表中一半节点的栈
    std::stack<Node*> nodeStack;
    while (ptr2 && ptr1 -> next;)
    {
        ptr1 = ptr1 -> next -> next;
        nodeStack.push(ptr2);
        ptr2 = ptr2 -> next;
    }

    // 链表节点数为奇数,向前移动一个节点
    if (ptr1 && ptr1 -> next == nullptr) {
        ptr2 = ptr2 -> next;
    }

    while (!nodeStack.empty() && ptr2) {
        Node * curr = nodeStack.top();  // 返回栈顶节点
        nodeStack.pop();
        if (curr -> data != ptr2 -> data)
        {
            return false;
        }
        ptr2 = ptr2 -> next;
    }
    return true;
}

/**
 * [isPalindromeRecurHelper - Recursive approach to determine if list is palindrome]
 * Idea is to ues two pointer left and right, we move left and right to reduce
 * problem size in each recursive call, for a list to be palindrome, we need these two
 * conditions to be true in each recursive call.
 *                      a. Data of left and right should match
 *                      b. Remaining Sub-list is palindrome
 *  We are using function call stack for right to reach at last node and them compare
 *  it with first node (which is left)
 *  @param left [left pointer of sublist]
 *  @param right [right pointer of sublist]
 *  @return [true if sublist is palindrome, false if not]
 */
// 递归调用,每次问题规模减少left和right指针所指的两个节点的规模
// 当left和right两个指针所指的节点相等并且子链表为回文链表事,该链表才满足回文链表
bool isPalindromeRecurHelper(Node * &left, Node *right)
{
    //base case Stop when right becomes nullptr
    if (right == nullptr)
    {
        return true;
    }

    // 子链表是否为回文链表
    bool isPalindrome = isPalindromeRecurHelper(left, right -> next);
    // 子链表不是回文链表
    if (!isPalindrome)
    {
        return false;
    }

    // 检查left和right指针所指节点是否相等
    isPalindrome = (left -> data == right -> data);

    // 向前移动left指针
    left = left -> next;
    return isPalindrome;
}

bool isPalindromeRecur(Node *head)
{
    return isPalindromeRecurHelper(head, head);
}

int main()
{
    Node * head1 = nullptr;
    insert( head1, 'a' );
    insert( head1, 'b' );
    insert( head1, 'c' );
    insert( head1, 'c' );
    insert( head1, 'b' );
    insert( head1, 'a' );
    std::cout << "List 1: ";
    printList(head1);
    if ( isPalindromeIter1(head1) ) {
        std::cout << "List 1 is palindrome list\n";
    } else {
        std::cout << "List 1 is not a palindrome list\n";
    }
    std::cout << "List 1: ";
    printList(head1);

    Node * head2 = nullptr;
    insert( head2, 'r');
    insert( head2, 'a');
    insert( head2, 'd');
    insert( head2, 'a');
    insert( head2, 'r');
    std::cout << "List 2: ";
    printList(head2);

    if ( isPalindromeIter2( head2 ) ) {
        std::cout << "List 2 is palindrome list\n";
    } else {
        std::cout << "List 2 is not a palindrome list\n";
    }

    std::cout << "List 2: ";
    printList(head2);

    Node * head = nullptr;
    insert( head, 'a' );
    insert( head, 'b' );
    insert( head, 'c' );
    insert( head, 'b' );
    insert( head, 'd' );
    std::cout << "List 3: ";
    printList(head);

    if ( isPalindromeRecur(head) ) {
        std::cout << "List 3 is palindrome list\n";
    } else {
        std::cout << "List 3 is not a palindrome list\n";
    }
    std::cout << "List 3: ";
    printList(head);
    return 0;
}
