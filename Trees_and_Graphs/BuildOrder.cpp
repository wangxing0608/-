//
// Created by wangxing on 19-7-31.
//

// 4.7 给定项目列表和项目依赖列表,确定该项目集的构建顺序,如果没有合理的顺序则返回错误


#include <list>
#include <iostream>
#include "graph.h"
#include "graphtestutils.h"


std::list<Node<int>> buildOrder(const Graph<int> &graph)
{
    std::list<Node<int>> order;   // 保存项目构建顺序的列表
    auto &projects = graph.getNodes();

    for (auto &n : projects)
    {
        for (auto &c : n -> getAdjacent())
            c.lock() -> state++;      // skip check c.lock()
    }

    for (auto &n : projects)
    {
        if (n -> state == 0)
        {
            order.push_back(n);
        }
    }

    for (auto &p : order)
    {
        for (auto &c : p -> getAdjacent())
        {
            auto n = c.lock();
            if (n && (--n->state) == 0)
            {
                order.push_back(n);
            }
        }
    }

    if (order.size() != projects.size())
    {
        order.clear();
    }
    return order;
}

void test(const Graph<int> &graph)
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
    test(TestUtils::createGraph<int>({"a", "b", "c", "d", "e", "f"},
                                    {{"a", "d"}, {"f", "b"}, {"b", "d"}, {"f", "a"}, {"d", "c"}}));

    test(TestUtils::createGraph<int>({"a", "b", "c", "d", "e", "f", "g"},
                                     {{"a", "e"}, {"b", "a"}, {"b", "e"}, {"c", "a"}, {"d", "g"}, {"f", "a"}, {"f", "b"}, {"f", "c"}}));
}