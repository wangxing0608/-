//
// Created by wangxing on 19-8-8.
//

// 4.11 设计数据结构和算法在二叉搜索树中实现插入,查找,
// 和getRandomnNode()随机从二叉搜索树中返回一个节点的

// Tree contains all nodes in a dequeue. It needs to handles insert and delete methods
// getRandomNode(): O(1) time
// To fill tree with deque additional: + O(N) time + O(N) memory
// To clean tree with deque additional: + O(N) time

#include <memory>
#include <deque>
#include <random>
#include <chrono>
#include <iostream>


template <typename T>
class Tree
{
public:
    // 默认构造函数
    Tree()
    {
        // construct a trivial random generator engine from a time-based seed:
        auto seed = std::chrono::system_clock::now().time_since_epoch().count();
        randomEngine = std::default_random_engine(seed);
    }

    class RandomNode;
    using NodePtr = std::shared_ptr<RandomNode>;

    class RandomNode
    {
    public:
        template <typename U>
        explicit RandomNode(U &&value) : v(std::forward<U>(value)) {}

        const NodePtr &left() const
        {
            return childs[0];
        }

        const NodePtr &right() const
        {
            childs[1];
        }

        const T &value() const
        {
            return v;
        }

    private:
        std::array<NodePtr, 2> childs;
        T v;
        size_t idx;  // index in the Tree::nodes, used for quick deletion from Tree::nodes
        friend class Tree;
    };

    template <typename U>
    const NodePtr insert(const NodePtr &parent, U && value, bool insertRight)
    {
        NodePtr newNode;
        if (!parent)
            rootNode = newNode = std::make_shared<RandomNode>(std::forward<U>(value));
        else
            parent -> childs[insertRight ? 1 : 0] = newNode = std::make_shared<RandomNode>(std::forward<U>(value));
        newNode -> idx = nodes.size();
        nodes.push_back(newNode);
        return newNode;
    }

    const NodePtr getRandomNode() const
    {
        if (nodes.size() == 0)
            return nullptr;
        else if (nodes.size() == 1)
            return rootNode;
        else
        {
            if (randomDistribution.max() != nodes.size() - 1)
                randomDistribution = std::uniform_int_distribution<size_t>(0, nodes.size() - 1);

            return nodes.at(randomDistribution(randomEngine));
        }
    }

    const NodePtr  &root() const
    {
        return this -> rootNode;
    }

private:
    NodePtr rootNode;
    std::deque<NodePtr> nodes;
    mutable std::default_random_engine randomEngine;
    mutable std::uniform_int_distribution<size_t> randomDistribution;
};

int main()
{
    Tree<int> tree;
    auto node = tree.insert(nullptr, 3, false);   //       3
    auto left = tree.insert(node, 1, false);      //     /   \     .
    tree.insert(left, 0, false);                  //    1     5
    tree.insert(left, 2, true);                   //   / \   / \   .
    auto right = tree.insert(node, 5, true);      //  0   2 4   6
    tree.insert(right, 4, false);
    tree.insert(right, 6, true);

    std::string coma;
    for (int i = 0; i < 100; ++i)
    {
        std::cout << coma << tree.getRandomNode() -> value();
        if (coma.empty())
            coma = ", ";
    }
    std::cout << std::endl;
    return 0;
}