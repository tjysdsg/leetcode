#pragma once

#include "sol.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

TEST(test, 1) {
    SOLUTION_CLASS sol;

    auto *node = TreeNode::from_heap({1, 2, 5, 3, 4, -1, 6});
    sol.flatten(node);
    while (node) {
        cout << node->val << '\n';
        node = node->right;
    }
}

