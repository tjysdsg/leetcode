#pragma once

#include "sol.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

TEST(test, 1) {
    SOLUTION_CLASS sol;
    auto *tree = TreeNode::from_heap({1, 3, 2, 5, 3, -1, 9});
    EXPECT_EQ(sol.widthOfBinaryTree(tree), 4);
}

TEST(test, 2) {
    SOLUTION_CLASS sol;
    auto *tree = TreeNode::from_heap({1, 3, 2, 5, -1, -1, 9, 6, -1, -1, -1, -1, -1, 7});
    EXPECT_EQ(sol.widthOfBinaryTree(tree), 7);
}
