//
// Created by wangxing on 19-7-26.
//
#pragma once

#ifndef CODING_INTERVIEW_TREE_H
#define CODING_INTERVIEW_TREE_H

#include "treenode.h"

template <typename T, bool WithParent = false, template<typename, bool> class N = Node>
class Tree
{
    using NodePtr = typename N<T, WithParent>::NodePtr;

    const NodePtr& getRoot() const
    {
        if (isEmpty())
            throw TreeIsEmptyException();
        return root;
    }

    template <typename U>
    void setRoot(U &&node)
    {
        root = std::forward<U>(node);
    }

    bool isEmpty() const
    {
        return !root;
    }

    class TreeIsEmptyException {};

protected:
    NodePtr  root;
};

template <typename T, bool WithParent = false>
using NodePtr = typename Tree<T, WithParent>::NodePtr;

#endif //CODING_INTERVIEW_TREE_H
