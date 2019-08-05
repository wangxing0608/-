//
// Created by wangxing on 19-8-5.
//

// 4.9 二叉搜索树通过从左到右遍历数组,并将每一个元素插入到合适的位置形成
// 给定一颗由不重复元素组成的二叉搜索树,输出所有可能形成这颗二叉树的数组序列

#include <deque>
#include <list>
#include <cassert>
#include "tree.h"
#include "treetestutils.h"

template <typename T>
std::list<std::deque<T>> possibleStableJoins(std::deque<T> &prefix, std::deque<T> &left, std::deque<T> &right);

template <typename T>
std::list<std::deque<T>> possibleArrays(const NodePtr<T> &root)
{
    std::list<std::deque<T>> result;

    if (!root)
    {
        result.emplace_back();   // empty is required to call cycle body at least once
        return result;
    }

    auto leftArrays = possibleArrays<T>(root -> getLeft());
    auto rightArrays = possibleArrays<T>(root -> getRight());

    std::deque<T> prefix;
    prefix.push_back(root -> getValue());
    for (auto &left : leftArrays)
    {
        for (auto &right : rightArrays)
        {
            auto joins = possibleStableJoins<T>(prefix, left, right);
            result.splice(result.end(), std::move(joins));
            assert(prefix.size() == 1 && prefix[0] == root -> getValue());
        }
    }
    return result;
}

template <typename T>
std::list<std::deque<T>> possibleStableJoins(std::deque<T> &prefix, std::deque<T> &left, std::deque<T> &right)
{
    std::list<std::deque<T>> result;

    if (left.empty() || right.empty())
    {
        std::deque<T> r(prefix);
        r.insert(r.end(), left.begin(), left.end());
        r.insert(r.end(), right.begin(), right.end());
        result.push_back(std::move(r));
        return result;
    }

    prefix.push_back(left.front());
    left.pop_front();
    result.splice(result.end(), possibleStableJoins(prefix, left, right));
    left.push_front(prefix.back());
    prefix.pop_back();

    prefix.push_back(right.front());
    right.pop_front();
    result.splice(result.end(), possibleStableJoins(prefix, left, right));
    right.push_front(prefix.back());
    prefix.pop_back();

    return result;
}

int main()
{
    auto tree = TestUtils::treeFromArray({5, 10, 15, 20, 25, 50, 60, 65, 70, 80});
    TestUtils::printTree(tree);

    auto result = possibleArrays<int>(tree.getRoot());

    for (auto &array : result)
    {
        std::string sep;
        std::cout << "{";
        for (auto &n : array)
        {
            std::cout << sep << n;
            if (sep.empty())
                sep = ", ";
        }
        std::cout << "}" << std::endl;
    }
    return 0;
}
