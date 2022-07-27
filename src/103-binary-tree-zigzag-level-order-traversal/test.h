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
    auto res = sol.zigzagLevelOrder(&t);
    vector<vector<int>> ans{{3},
                            {20, 9},
                            {15, 7}};
    EXPECT_EQ(res, ans);
}

TEST(test, 2) {
    TreeNode t(1);

    SOLUTION_CLASS sol;
    auto res = sol.zigzagLevelOrder(&t);
    vector<vector<int>> ans{{1}};
    EXPECT_EQ(res, ans);
}

TEST(test, 3) {
    SOLUTION_CLASS sol;
    auto res = sol.zigzagLevelOrder(nullptr);
    vector<vector<int>> ans{};
    EXPECT_EQ(res, ans);
}
