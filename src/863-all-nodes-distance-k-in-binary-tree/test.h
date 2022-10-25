#pragma once

#include "sol.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

TEST(test, 0) {
    SOLUTION_CLASS sol;
    TreeNode *node = TreeNode::from_heap({0, 1, -1, 3, 2});
    vector<int> ans{1};
    EXPECT_EQ(sol.distanceK(node, node->left->right, 1), ans);
}

TEST(test, 1) {
    SOLUTION_CLASS sol;
    TreeNode *node = TreeNode::from_heap({3, 5, 1, 6, 2, 0, 8, -1, -1, 7, 4});
    vector<int> ans{7, 4, 1};
    EXPECT_THAT(sol.distanceK(node, node->left, 2), UnorderedElementsAreArray(ans));
}

TEST(test, 2) {
    SOLUTION_CLASS sol;
    TreeNode node(1);
    vector<int> ans{};
    EXPECT_EQ(sol.distanceK(&node, &node, 3), ans);
}

