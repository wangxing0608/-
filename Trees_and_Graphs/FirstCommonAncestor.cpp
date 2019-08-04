//
// Created by wangxing on 19-8-3.
//

// 4.8 在二叉树中找到两个节点的共同祖先节点

#include <vector>
#include "tree.h"
#include "treetestutils.h"
#include "treenodeiterator.h"


enum
{
    NotFound;        // node not found in subtree
    FoundLeft;       // node found in left subtree
    FoundRight;      // node found in right subtree
    FoundEqual;      // node is subtree root
};

template <typename T>
FindResult findNodeFrom(const NodePtr<T> &startNode, const NodePtr<T> &node)
{
    if (!startNode)
        return NotFound;
    if (startNode == node)
        return FoundEqual;

    if (findNodeFrom<T>(startNode -> getLeft(), node) != NotFound)
        return FoundLeft;
    else if (findNodeFrom(startNode -> getRight(), node) != NotFound)
        return FoundRight;

    return NotFound;
}

template <typename T>
NodePtr<T> findCommonAncestor(const Tree<T> &tree, const NodePtr<T> &one, const NodePtr<T> &two)
{
    if (one == two)
        return one;

    auto startNode = tree.getRoot();

    auto firstResult = findNodeFrom<T>(startNode, one);
    if (firstResult == NotFound)
        return nullptr;

    auto secondResult = findNodeFrom<T>(startNode, two);
    if (secondResult == NotFound)
        return nullptr;

    while (firstResult == secondResult)
    {
        startNode = (firstResult == FoundLeft) ? startNode -> getLeft() : startNode -> getRight();
        firstResult = findNodeFrom<T>(startNode, one);
        secondResult = findNodeFrom<T>(startNode, two);
    }
}

int main()
{
    auto tree = TestUtils::treeFromArray({10, 1, 12, 3, 14, 25, 16, 27, 18, 29, 10, 13, 2, 15, 4, 5, 17, 7, 19, 9});
    TestUtils::printTree(tree);

    for (auto one : tree)
    {
        if (one == tree.getRoot())
            continue;   // it is not interesting

        for (auto two : tree)
        {
            if (two == tree.getRoot() || two == one)
                continue;     // it it not interesting;

            auto ancestor = findCommonAncestor<int>(tree, one, two);
            std::cout << one -> getValue() << ", " << two -> getValue() << "<-- ";
            std::cout << (ancestor ? std::to_string(ancestor -> getValue()) : "Not Found") << std::endl;
        }

        // Test nodes of different trees
        auto tree2 = TestUtils::getSampleTree<int>(7);
        auto node1 = tree.getRoot() -> getLeft() -> getRight();
        auto node2 = tree.getRoot() -> getRight() -> getLeft();
        auto ancestor = findCommonAncestor<int>(tree, node1, node2);
        std::cout << "Nodes below are of different trees:\n";
        std::cout << node1 -> getValue() << ", " << node2 -> getValue() << " <-- ";
        std::cout << (ancestor ? std::to_string(ancestor -> getValue()) : "Not Found") << std::endl;
    }
}
