//
// Created by wangxing on 19-7-30.
//

// 4.6 在二叉搜索树中找到给定节点的"下一个节点"(即,有序后继节点)
// 假设每个节点都有一个指向父节点的链接


#include <vector>
#include "tree.h"
#include "treetestutils.h"

template <typename T>
NodePtr<T, true> getMin(NodePtr<T, true> node)
{
    if (!node)
        return nullptr;

    while (node -> getLeft())
        node = node -> getLeft();

    return node;
}

template <typename T>
NodePtr<T, true> nextNode(NodePtr<T, true> node)
{
    if (!node)
        return nullptr;

    if (node -> getRight())
        return getMin<T>(node -> getRight());

    auto next = node -> getParent();
    while (next && node == next -> getRight())
    {
        // right subtree is traversed -> parent and all its childs were travered
        node = next;
        next = next -> getParent();
    }

    return next;
}

int main()
{
    // valid BST
    auto tree = TestUtils::getSampleTree<int, true>(20);
    TestUtils::printTree(tree);
    auto node = getMin<int>(tree.getRoot());
    if (node)
    {
        std::cout << node -> getValue();
        for (node = nextNode<int>(node); node; node = nextNode<int>(node))
        {
            std::cout << " --> " << node -> getValue();
        }
        std::cout << std::endl;
    }
    return 0;
}

