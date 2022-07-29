#pragma once

#include "sol.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

TEST(test, 1) {
    SOLUTION_CLASS sol;

    TreeNode *root = TreeNode::from_heap({3, 1, 4, -1, 2});
    EXPECT_EQ(sol.kthSmallest(root, 1), 1);

    delete root;
}

TEST(test, 2) {
    SOLUTION_CLASS sol;

    TreeNode *root = TreeNode::from_heap({5, 3, 6, 2, 4, -1, -1, 1});
    EXPECT_EQ(sol.kthSmallest(root, 3), 3);

    delete root;
}

TEST(test, 3) {
    SOLUTION_CLASS sol;

    TreeNode *root = TreeNode::from_heap({1, -1, 2});
    EXPECT_EQ(sol.kthSmallest(root, 2), 2);

    delete root;
}

