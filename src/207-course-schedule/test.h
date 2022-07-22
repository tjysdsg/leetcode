#pragma once

#include "sol.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

TEST(test, 1) {
    SOLUTION_CLASS sol;
    vector<vector<int>> v{
            {1, 0},
    };
    EXPECT_EQ(sol.canFinish(2, v), true);
}

TEST(test, 2) {
    SOLUTION_CLASS sol;
    vector<vector<int>> v{
            {1, 0},
            {0, 1},
    };
    EXPECT_EQ(sol.canFinish(2, v), false);
}
