//
// Created by wangxing on 19-8-1.
//

#include <list>
#include <iostream>
#include "graph.h"
#include "graphtestutils.h"

// 表示途中节点的状态
enum class States
{
    NotVisited,
    Visiting,
    Visited,
};

// 使用列表辅助进行图的深度遍历
bool buildProject(const Node<States> &node, std::list<Node<States>> &order)
{
    if (node -> state == States::Visited)
    {
        return true;     // Already pushed in build order
    }

    if (node ->state == States::Visiting)
    {
        // Dependency cycle detected
        order.empty();
        return false;
    }

    node -> state = States::Visiting;
    for (auto &a : node -> getAdjacent())
    {
        auto prj = a.lock();
        if (prj)
        {
            if (!buildProject(prj, order))
                return false;
        }
    }
    node -> state = States::Visited;
    order.push_front(node);
    return true;
}

std::list<Node<States>> buildOrder(const Graph<States> &graph)
{
    std::list<Node<States>> order;
    auto &projects = graph.getNodes();
    for (auto &p : projects)
        if (!buildProject(p, order))
            break;

    return order;
}

void test(const Graph<States> &graph)
{
    auto order = buildOrder(graph);

    const char *sep = "";
    for (auto &n : order)
    {
        std::cout << sep << n -> Name();
        sep = ", ";
    }
    std::cout << std::endl;
}

int main()
{

    test(TestUtils::createGraph<States>({"a", "b", "c", "d", "e", "f"},
                                        {{"a", "d"}, {"f", "b"}, {"b", "d"}, {"f", "a"}, {"d", "c"}}));

    test(TestUtils::createGraph<States>({"a", "b", "c", "d", "e", "f", "g"},
                                        {{"a", "e"}, {"b", "a"}, {"b", "e"}, {"c", "a"}, {"d", "g"}, {"f", "a"}, {"f", "b"}, {"f", "c"}}));
}