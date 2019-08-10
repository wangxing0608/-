//
// Created by wangxing on 19-8-10.
//

// 给定一颗二叉树,其中每个节点都包含有一个整数值(正数或负数)
// 设计算法计算到给定数值的总的路径数,路径不需要从h根或叶子节点开始,但必须向下

#include <unordered_map>
#include "tree.h"
#include "treetestutils.h"

int sumsFrom(const NodePtr<int> &node, int requierdSum, int pathSum, std::unordered_map<int, int> &sums)
{
    if (!node)
        return 0;


    pathSum += node -> getValue();

    //Count of paths ending here and having required sum
    int overflow = pathSum - requierdSum;
    int cnt = sums.count(overflow) ? sums.at(overflow) : 0;

    // Starting from root
    if (pathSum == requierdSum)
        ++cnt;

    sums[pathSum] +=1;
    cnt += sumsFrom(node -> getLeft(), requierdSum, pathSum, sums);
    cnt += sumsFrom(node -> getRight(), requierdSum, pathSum, sums);

    // Done with this node, do not ust pathSum till this node anymore
    if ((sums[pathSum] -= 1) == 0)
        sums.erase(pathSum);  // less memory

    return cnt;
}

int countPathWithSum(const Tree<int> &tree, int sum)
{
    std::unordered_map<int, int> tmp;
    return sumsFrom(tree.getRoot(), sum, 0, tmp);
}

int main()
{
    auto tree = TestUtils::treeFromArray({1, -2, 3, -5, 7, -11, 13, -1, 2, -3, 5, -7, 11, -1, 2, -3, 1, -2, 3, -7});
    TestUtils::printTree(tree);

    // From sum of negative values till sum of positive values
    for (int i = -42; i <= 48; ++i)
    {
        std::cout << "Sum " << i << " can ne reached in " << countPathWithSum(tree, i) << " paths\n";
    }
    return 0;
}
