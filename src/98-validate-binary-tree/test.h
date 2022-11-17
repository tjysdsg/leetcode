#pragma once

#include "sol.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

TEST(test, 1) {
    SOLUTION_CLASS sol;
    auto *node = TreeNode::from_heap({-2147483648, -1, 2147483647});
    EXPECT_EQ(sol.isValidBST(node), true);
}

TEST(test, 2) {
    SOLUTION_CLASS sol;
    auto *node = TreeNode::from_heap({2, 1, 3});
    EXPECT_EQ(sol.isValidBST(node), true);
}

TEST(test, 3) {
    SOLUTION_CLASS sol;
    auto *node = TreeNode::from_heap({5, 1, 4, -1, -1, 3, 6});
    EXPECT_EQ(sol.isValidBST(node), false);
}
