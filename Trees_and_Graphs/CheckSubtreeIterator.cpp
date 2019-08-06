//
// Created by wangxing on 19-8-6.
//

// T1,T2是两颗非常大的二叉树,T1比T2大,设计算法判断T2是否为T1的子树
// 如果T2为T1的子树,则T1中存在以节点n为根的子树与T2相等
// 使用二叉树节点迭代遍历算法进行求解

// T2的先序遍历序列为T1的先序遍历序列的子串,则T2一定为T1的子树

// 二叉树的迭代先序遍历

# include "tree.h"
#include "treenodeiterator.h"
#include "treetestutils.h"

template <typename T>
bool compareTrees(const NodePtr<T> &left, const NodePtr<T> &right);

template <typename T>
bool checkSubtree(const Tree<T> &tree, const Tree<T> &subtree)
{
    auto subtreeRoot = subtree.getRoot();
    // 子树为空
    if (!subtreeRoot)
        return true;

    auto subtreeRootValue = subtreeRoot -> getValue();   // 得到子树根节点的值
    for (const auto &node : tree)
    {
        if (compareTrees<int>(node, subtreeRoot))
            return true;
    }

    return false;
}

template <typename T>
bool compareTrees(const NodePtr<T> &left, const NodePtr<T> &right)
{
    if (!left && !right)
        return true;
    else if (!left || !right)  // one tree is not finished, another already finished
        return false;
    else if (left -> getValue() == right -> getValue())
        return compareTrees<T>(left -> getLeft(), right -> getLeft()) && compareTrees<T>(left -> getRight(), right -> getRight());
    return false;
}


int main()
{
    auto left = TestUtils::getSampleTree<int>(15);
    auto right = TestUtils::getSampleTree<int>(7);
    TestUtils::printTree(right);
    std::cout << (checkSubtree(left, right) ? "is subtree of\n" : " is not subtree of\n");
    TestUtils::printTree(left);

    right = TestUtils::getSampleTree<int >(8);
    TestUtils::printTree(right);
    std::cout << (checkSubtree(left, right) ? "is subtree of\n" : " is not subtree of\n");
    TestUtils::printTree(left);

    return 0;
}
