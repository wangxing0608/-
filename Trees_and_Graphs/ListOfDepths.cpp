//
// Created by wangxing on 19-7-27.
//

// 给定一颗二叉树,设计算法创建深度相同的节点的链表(如深度为D的二叉树,则有D个链表)

#include <list>
#include "tree.h"
#include "treetestutils.h"

template <typename T>
using ListOfDepths = std::list<std::list<NodePtr<T>>>;

template <typename T>
ListOfDepths<T> getListOfDepths(const Tree<T> &tree)
{
    ListOfDepths<T> result;

    result.emplace_back();
    auto list = &result.back();
    list -> push_back(tree.getRoot());

    do{
        result.emplace_back();
        auto &childs = result.back();
        for (const auto &n : *list)
        {
            if (n -> getLeft())
                childs.push_back(n -> getLeft());
            if (n -> getRight())
                childs.push_back( n-> getRight());
        }
        if (childs.empty())
        {
            result.pop_back();
            break;
        }
        list = &childs;
    } while (true);
}

template <typename T>
void printDepths(const ListOfDepths<T> &depths)
{
    std::cout << "Nodes:\n";
    int depth = 0;
    for (const auto &line : depths)
    {
        std::cout << depth << ": ";
        auto sep = "";
        for (const auto &n : line)
        {
            std::cout << sep << n -> getValue();
            sep = ", ";
        }
        std::cout << std::endl;
        ++depth;
    }
    std::cout << std::endl;
}

int main()
{
    auto tree = TestUtils::getSampleTree<int>(15);
    TestUtils::printTree(tree);
    auto depths = getListOfDepths(tree);
    printDepths<int>(depths);

    tree = TestUtils::getSampleTree<int>(20);
    TestUtils::printTree(tree);
    depths = getListOfDepths(tree);
    printDepths<int>(depths);
    return 0;
}

