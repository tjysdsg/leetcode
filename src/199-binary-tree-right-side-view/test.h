#pragma once

#include "sol.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

TEST(test, 1) {
    SOLUTION_CLASS sol;
    vector<int> ans{};
    EXPECT_EQ(sol.rightSideView(nullptr), ans);
}

TEST(test, 2) {
    SOLUTION_CLASS sol;
    vector<int> ans{1, 2};
    EXPECT_EQ(sol.rightSideView(TreeNode::from_heap({1, 2})), ans);
}
