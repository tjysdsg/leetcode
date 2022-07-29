#pragma once

#include "sol.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

TEST(test, 3) {
    SOLUTION_CLASS sol;

    TreeNode *root = new TreeNode(
            1,
            nullptr,
            new TreeNode(2)
    );
    EXPECT_EQ(sol.kthSmallest(root, 2), 2);
}

TEST(test, 1) {
    SOLUTION_CLASS sol;

    TreeNode *root = new TreeNode(
            3,
            new TreeNode(
                    1,
                    nullptr,
                    new TreeNode(2)
            ),
            new TreeNode(4)
    );
    EXPECT_EQ(sol.kthSmallest(root, 1), 1);
}

TEST(test, 2) {
    SOLUTION_CLASS sol;

    TreeNode *root = new TreeNode(
            5,
            new TreeNode(
                    3,
                    new TreeNode(
                            2,
                            new TreeNode(1),
                            nullptr
                    ),
                    new TreeNode(4)
            ),
            new TreeNode(6)
    );
    EXPECT_EQ(sol.kthSmallest(root, 3), 3);
}
