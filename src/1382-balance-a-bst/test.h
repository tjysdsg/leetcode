#pragma once

#include "sol.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

TEST(test, 1) {
    SOLUTION_CLASS sol;

    TreeNode *root = TreeNode::from_heap({1, -1, 2, -1, -1, -1, 3, -1, -1, -1, -1, -1, -1, -1, 4});
    TreeNode *ans1 = TreeNode::from_heap({2, 1, 3, -1, -1, -1, 4});
    TreeNode *ans2 = TreeNode::from_heap({3, 1, 4, -1, 2});

    auto *res = sol.balanceBST(root);

    vector<vector<int>> ans = {{ans1->to_heap(), ans2->to_heap()}};
    EXPECT_THAT(ans, Contains(res->to_heap()));
    // EXPECT_TRUE(*res == *ans1 || *res == *ans2);

    delete root;
}

TEST(test, 2) {
    SOLUTION_CLASS sol;

    TreeNode *root = TreeNode::from_heap({2, 1, 3});
    TreeNode *ans = TreeNode::from_heap({2, 1, 3});
    EXPECT_EQ(sol.balanceBST(root)->to_heap(), ans->to_heap());

    delete root;
}
