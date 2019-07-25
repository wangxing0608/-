//
// Created by wangxing on 19-7-25.
//

// 设计算法确定有向图中的两个节点是否有路径相连
// 图遍历算法,从其中一个节点出发,使用深度优先搜索或广度优先搜索
// 在遍历期间检查是否找到另一个节点
// 实现图的广度优先搜索

#include <queue>
#include <iostream>
#include <cassert>
#include "graph.h"
#include "graphtestutils.h"

enum State {Unvisited, Visiting, Visited};

// width viaiting
bool routeBetweenNodes(const Graph<State> &graph, const Node<State> &from, const Node<State> &to)
{
    // 两个节点相同
    if (from == to)
        return true;

    // 图中所有节点设为未访问过
    for (auto &n : graph.getNodes())
        n -> state = Unvisited;

    std::queue<Node<State >> queue;
    from -> state = Visiting;
    queue.push(from);
    while (!queue.empty())
    {
        Node<State> n = queue.front();
        queue.pop();
        for (auto &c : n -> getAdjacent())
        {
            auto v = c.lock();
            if (v && v -> state == Unvisited)
            {
                if (v == to)
                    return true;
                else
                {
                    v -> state = Visiting;
                    queue.push(v);
                }
            }
        }
        n -> state = Visited;
    }
    // 广度优先遍历中未找到另外一个节点,则两个节点在该有向图中没有路径相连
    return false;
}

// Recursive visiting
// 递推遍历
bool routeBetweenNodesWalker(const Graph<State> &graph, const Node<State > &from, const Node<State> &to)
{
    if (from == to)
        return true;

    from -> state = Visited;
    for (auto &c : from -> getAdjacent())
    {
        auto node = c.lock();
        if (node && node -> state != Visited)
        {
            if (routeBetweenNodesWalker(graph, node, to))
                return true;
        }
    }
    return false;
}

bool routeBetweenNodeR(const Graph<State> &graph, const Node<State> &from, const Node<State> &to)
{
    for (auto &n : graph.getNodes())
        n -> state = Unvisited;

    return routeBetweenNodesWalker(graph, from, to);
}

bool test(const Graph<State> &graph, size_t from, size_t to)
{
    auto &fromNode = graph[from], &toNode = graph[to];
    bool result = routeBetweenNodes(graph, fromNode, toNode);
    bool resultR = routeBetweenNodeR(graph, fromNode, toNode);

    assert(result == resultR);
    std::cout << toNode -> Name() << " is " << (result ? "" : "NOT") << "reachable from " << fromNode -> Name() << std::endl;
    std::cout << toNode -> Name() << " is " << (result ? "" : "NOT") << "reachable from " << fromNode -> Name() << std::endl;
    return result;
}

void testGraph(const Graph<State> &graph)
{
    auto size = graph.getNodes().size();
    for (decltype(size) i = 0; i < size; ++i)
    {
        for (decltype(size) j = 0; j < size; ++j)
            test(graph, i, j);
        std::cout << std::endl;
    }
}

int main()
{
    testGraph(TestUtils::getExampleGraph<State>());
    testGraph(TestUtils::getExampleGraph2<State>());
    testGraph(TestUtils::getExampleGraph3<State>());
    return 0;
}

