//
// Created by wangxing on 19-8-3.
//

// 4.8 在二叉树中找到两个节点的共同祖先节点
// 每个节点包含到父节点的指针,沿着其中一个节点上溯到根节点,得到从该节点到根节点的路径链表,
// 再根据2.7题中求两个链表是否相交的思想找到第一个相交节点,即为第一个公共祖先节点


#include "tree.h"
#include "treetestutils.h"
#include "treenode.h"
#include "treenodeiterator.h"

// 得到节点在树中的深度
template <typename T>
int getDepth(const Tree<T, true> &tree, NodePtr<T, true> node)
{
    size_t depth = 0;
    if (node)
    {
        while (node -> getParent())
        {
            node = node -> getParent();
            ++depth;
        }
    }

    // Check if the node is in this tree
    if (node != tree.getRoot())
        depth = -1;
    return depth;
}

// 在二叉树中寻找两个节点的共同祖先节点
template <typename T>
NodePtr<T, true> findCommonAncestor(const Tree<T, true> &tree, NodePtr<T, true> one, NodePtr<T, true> two)
{
    // 两个节点相同
    if (one == two)
    {
        return one;
    }

    auto depthL = getDepth(tree, one);
    auto depthR = getDepth(tree, two);

    // 两个节点不在同一颗二叉树中
    if (depthL == -1 || depthR == -1)
    {
        return nullptr;
    }

    if (depthL > depthR)
    {
        std::swap(depthL, depthR);
        std::swap(one, two);   // that is why we pass 'one' and 'two' arguments by values
    }

    // depthR为二叉树中较长路径的节点,将它向前移动到两个节点路径长度一致
    while (depthR != depthL)
    {
        two = two -> getParent();
        --depthR;
    }

    // 求两个相等长度的链表序列的公共交点,即为第一个公共祖先节点
    while (one != two)
    {
        one = one -> getParent();
        two = two -> getParent();
    }
    return one;
}

int main()
{
    auto tree = TestUtils::treeFromArray<int, true>({10, 1, 12, 3, 14, 25, 16, 27, 18, 29, 10, 13, 2, 15, 4, 5, 17, 7, 19, 9});
    TestUtils::printTree(tree);

    for (auto one : tree)
    {
        if (one == tree.getRoot())
        {
            continue;   // it is not interesting
        }

        for (auto two : tree)
        {
            if (two == tree.getRoot() || two == one)
            {
                continue;   // it is not interesting
            }
            auto ancestor = findCommonAncestor<int>(tree, one, two);
            std::cout << one -> getValue() << ", " << two -> getValue() << "<-- ";
            std::cout << (ancestor ? std::to_string(ancestor -> getValue()) : "Not Found") << std::endl;
        }
    }
}
