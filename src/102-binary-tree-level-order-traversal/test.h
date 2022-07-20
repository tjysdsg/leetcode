#pragma once

#include "sol.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

TEST(test, 1) {
    TreeNode t(
            3,
            new TreeNode(9),
            new TreeNode(
                    20,
                    new TreeNode(15), new TreeNode(7)
            )
    );

    SOLUTION_CLASS sol;
    auto res = sol.levelOrder(&t);
    vector<vector<int>> ans{{3},
                            {9,  20},
                            {15, 7}};
    EXPECT_EQ(res, ans);
}
