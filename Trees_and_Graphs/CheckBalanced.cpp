//
// Created by wangxing on 19-7-28.
//

// 实4.4 现算法检测一颗二叉树是否为平衡二叉树
// 平衡二叉树：任何节点的两个子树的高度差小于2


#include <limits>
#include "tree.h"
#include "treetestutils.h"


template <typename T>
int getHeight(const NodePtr<int> &node)
{
    // 树为空
    if (!node)
        return 0;
    int leftH = getHeight<T>(node -> getLeft());
    if (leftH == -1)
        return -1;

    int rightH = getHeight<T>(node -> getRight());
    if (rightH == -1)
        return -1;
    // 该节点不平衡
    if (std::abs(leftH - rightH) > 1)
        return -1;
    return std::max(leftH, rightH) + 1;   // 返回以当前节点为根的树高
}


template <typename T>
bool isTreeBalanced(const Tree<T> &tree)
{
    return getHeight<T>(tree.getRoot()) != -1;
}

int main()
{
    auto tree = TestUtils::getSampleTree<int>(20);  // 平衡二叉树
    std::cout << "Tree is " << (isTreeBalanced<int>(tree) ? "" : "NOT") << "balanced" << std::endl;

    // Disconnect right subtree, the result tree is balanced
    auto r = tree.getRoot() -> getRight();
    tree.getRoot() -> getRight() = std::make_shared<Node<int>>(100);
    std::cout << "Tree is " << (isTreeBalanced<int>(tree) ? "" : "NOT") << "balanced" << std::endl;

    // Return right subtree and check if the tree is balanced again
    tree.getRoot() -> getRight() = r;   // balanced
    std::cout << "Tree is " << (isTreeBalanced<int>(tree) ? "" : "NOT") << "balanced" << std::endl;
    return 0;
}
