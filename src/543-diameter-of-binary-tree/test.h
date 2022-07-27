#pragma once

#include "sol.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

TEST(test, 1) {
    TreeNode t(
            1,
            new TreeNode(
                    2,
                    new TreeNode(4), new TreeNode(5)
            ),
            new TreeNode(3)
    );

    SOLUTION_CLASS sol;
    EXPECT_EQ(sol.diameterOfBinaryTree(&t), 3);
}

TEST(test, 2) {
    TreeNode t(1, new TreeNode(2), nullptr);
    SOLUTION_CLASS sol;
    EXPECT_EQ(sol.diameterOfBinaryTree(&t), 1);
}
