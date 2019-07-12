//
// Created by wangxing on 19-7-12.
//

// 2.3 删除单链表中的中间节点,只能存取该中间节点
// 由于只能访问要删除的节点,所以需要将该节点下一个节点中的数据复制到该节点
// 再删除该节点的后继节点，实现删除该节点的要求

#include <iostream>

struct Node {
    char data;
    Node *next;
    Node (char c) : data{c}, next{nullptr} {}
};

/**
 * [printList - Helper routine to print the list]
 * @param head [head of the list]
 */
void printList(Node *head)
{
    while (head)
    {
        std::cout << head->data << "-->";
        head = head->next;
    }
    std::cout << "nullptr" << std::endl;
}

/**
 * [deleteNode - delete the "node" from the list]
 * @param node [node to be deleted]
 */
 // 删除单链表中的中间节点,只能访问该节点
 void deleteNode(Node *node)
 {
     // 如果要删除的节点为空或该节点为最后一个节点
     if (node == nullptr || node->next == nullptr)
         return;
     Node *nextNode = node -> next;   // 指向该节点后继节点的指针
     node -> data = nextNode -> data; 
     node -> next = nextNode ->next;   // 将该节点后继节点中的内容复制到该节点
     delete nextNode;   // 删除后继节点
 }
 
 int main()
 {
     Node *head = new Node('a');
     head -> next = new Node('b');
     head -> next -> next = new Node('c');
     head -> next -> next -> next = new Node('d');
     head -> next -> next -> next ->next = new Node('e');
     std::cout << "List before deletion: \n";
     printList(head);
     std::cout << "Deleting node containing data as 'c'\n";
     deleteNode(head->next->next);
     std::cout << "List after deletion:\n";
     printList(head);
     return 0;
 }
 