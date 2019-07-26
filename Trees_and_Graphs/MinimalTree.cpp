//
// Created by wangxing on 19-7-26.
//

// 给定具有唯一整数元素的排序数组,创建具有最小高度的二叉搜索树

// 要想构建的二叉搜索树高度最小,对于任意节点,它的左子树节点和右字数节点应该尽可能相当
// 如果将一个数放在根节点,则理想情况下,该节点将数组中剩下的数对半分,一半放在左子树,一半放在右子树
// 不断递归调用该过程,则构建的二叉搜索树高度最小

#include <array>
#include <numeric>
#include "tree.h"
#include "treetestutils.h"

template <typename T>
NodePtr<T> subtreeFromArray(const T *array, int start, int end)
{
    if (end < start)
        return nullptr;
    // 计算中间节点
    int i = (start + end)  / 2;
    auto node  = std::make_shared<Node<T>>(array[i]);
    node -> setLeftChild(subtreeFromArray(array, start, i-1));  // 递归调用左子树
    node -> setRightChild(subtreeFromArray(array, i+1, end));     // 递归调用右字树
    return node;
}

template <typename T>
Tree<T> treeFromArray(const T *array, size_t size)
{
    Tree<T> tree;
    tree.setRoot(subtreeFromArray(array, 0, size-1));
    return tree;   // 返回构建好的最小高度的二叉搜索树
}

int main()
{
    std::array<int, 63> array;
    std::iota(array.begin(), array.end(), 0);  // fill with 0...62

    for (auto &i : {1,2, 3, 6, 7, 8, 14, 15, 16, 29, 30, 31})
    {
        auto tree = treeFromArray(&array[0], i);
        TestUtils::printTree(tree);
    }
    return 0;
}
