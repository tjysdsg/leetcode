#pragma once

#include "sol.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

TEST(test, 4) {
    SOLUTION_CLASS sol;

    TreeNode *root = TreeNode::from_heap({6, 2, 8, 0, 4, 7, 9, -1, -1, 3, 5});
    auto *res = sol.lowestCommonAncestor(root, root->left->right->left, root->left->right->right);
    EXPECT_EQ(res, root->left->right);

    delete root;
}

TEST(test, 1) {
    SOLUTION_CLASS sol;

    TreeNode *root = TreeNode::from_heap({6, 2, 8, 0, 4, 7, 9, -1, -1, 3, 5});
    auto *res = sol.lowestCommonAncestor(root, root->left, root->right);
    EXPECT_EQ(res, root);

    delete root;
}


TEST(test, 2) {
    SOLUTION_CLASS sol;

    TreeNode *root = TreeNode::from_heap({6, 2, 8, 0, 4, 7, 9, -1, -1, 3, 5});
    auto *res = sol.lowestCommonAncestor(root, root->left, root->left->right);
    EXPECT_EQ(res, root->left);

    delete root;
}

TEST(test, 3) {
    SOLUTION_CLASS sol;

    TreeNode *root = TreeNode::from_heap({2, 1});
    auto *res = sol.lowestCommonAncestor(root, root, root->left);
    EXPECT_EQ(res, root);

    delete root;
}
