//
// Created by wangxing on 19-7-29.
//

// 4.5 检测一个二叉树是否为二叉搜索树


#include <vector>
#include "tree.h"
#include "treetestutils.h"

template <typename T>
bool checkNode(const NodePtr<T> &node, const T *minValue, const T *maxValue)
{
    // 节点为空
    if (!node)
        return true;

    if (minValue && node -> getValue() <= *minValue)
        return false;
    if (maxValue && node -> getValue() > *maxValue)
        return false;

    return checkNode<T>(node -> getLeft(), minValue, &node -> getValue()) && checkNode<T>(node -> getRight(), &node -> getValue(), maxValue);
}

template <typename T>
bool isValidBST(const Tree<T> &tree)
{
    return checkNode<T>(tree.getRoot(), nullptr, nullptr);
}

int main()
{
    // valid BST
    auto tree = TestUtils::getSampleTree<int>(20);
    TestUtils::printTree(tree);
    std::cout << "Tre tree is " << (isValidBST<int>(tree) ? "" : "NOT ") << "binary search tree" << std::endl;

    // invalid BST
    tree.getRoot() -> getRight() -> getRight() -> getRight() -> setLeftChild(std::make_shared<Node<int>>(19));
    TestUtils::printTree(tree);
    std::cout << "The tree is " << (isValidBST<int>(tree) ? "" : "NOT ") << "binary search tree" << std::endl;


    // invalid BST
    tree.getRoot() -> getRight() -> getRight() -> getRight() -> setLeftChild(std::make_shared<Node<int>>(15));
    TestUtils::printTree(tree);
    std::cout << "The tree is " << (isValidBST<int>(tree) ? "" : "NOT ") << "binary search tree" << std::endl;
}

