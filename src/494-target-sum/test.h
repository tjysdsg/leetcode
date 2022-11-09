#pragma once

#include "sol.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

TEST(test, 1) {
    SOLUTION_CLASS sol;
    vector<int> v{1, 1, 1, 1, 1};
    EXPECT_EQ(sol.findTargetSumWays(v, 3), 5);
}

TEST(test, 2) {
    SOLUTION_CLASS sol;
    vector<int> v{1};
    EXPECT_EQ(sol.findTargetSumWays(v, 1), 1);
}

TEST(test, 3) {
    SOLUTION_CLASS sol;
    vector<int> v{5};
    EXPECT_EQ(sol.findTargetSumWays(v, 0), 0);
}
