//
// Created by wangxing on 19-8-6.
//

// 4.10 T1,T2是两颗非常大的二叉树,T1比T2大,设计算法判断T2是否为T1的子树
// 如果T2为T1的子树,则T1中存在以节点n为根的子树与T2相等
// 使用二叉树节点递归遍历算法进行求解

#include "tree.h"
#include "treenodeiterator.h"
#include "treetestutils.h"

template <typename T>
bool compareTrees(const NodePtr<T> &left, const NodePtr<T> &right);

template <typename T>
bool checkSubtree(const NodePtr<T> &root, const NodePtr<T> &subtreeRoot);

template <typename T>
bool checkSubtree(const Tree<T> &tree, const Tree<T> &subtree)
{
    if (!subtree.getRoot())
        return true;    // empty subtree

    return checkSubtree<T>(tree.getRoot(), subtree.getRoot());
}

template <typename T>
bool compareTrees(const NodePtr<T> &left, const NodePtr<T> &right)
{
    if (!left && !right)
        return true;
    else if (!left || !right)   // one tree is not finished, another already finished
        return false;
    else if (left -> getValue() == right -> getValue())
        return compareTrees<T>(left -> getLeft(), right -> getLeft()) && compareTrees<T>(left -> getRight(), right -> getRight());
    return false;
}

template <typename T>
bool checkSubtree(const NodePtr<T> &root, const NodePtr<T> &subtreeRoot)
{
    if (!root)
        return false;
    if (root -> getValue() == subtreeRoot -> getValue() && compareTrees<T>(root, subtreeRoot))
        return true;
    return checkSubtree<T>(root -> getLeft(), subtreeRoot) || checkSubtree<T>(root -> getRight(), subtreeRoot);
}

int main()
{
    auto left = TestUtils::getSampleTree<int>(15);
    auto right = TestUtils::getSampleTree<int>(7);
    TestUtils::printTree(right);
    std::cout << (checkSubtree<int>(left, right) ? "is subtree of\n" : "is not subtree of\n");
    TestUtils::printTree(left);

    std::cout << std::endl;
    right = TestUtils::getSampleTree<int>(8);
    TestUtils::printTree(right);
    std::cout << (checkSubtree<int>(left, right) ? "is subtree of\n" : "is not subtree of\n");
    TestUtils::printTree(left);
}
