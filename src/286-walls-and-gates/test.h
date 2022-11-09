#pragma once

#include "sol.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

TEST(test, 1) {
    SOLUTION_CLASS sol;
    vector<vector<int>> v{{2147483647, -1,         0,          2147483647},
                          {2147483647, 2147483647, 2147483647, -1},
                          {2147483647, -1,         2147483647, -1},
                          {0,          -1,         2147483647, 2147483647}};
    vector<vector<int>> ans{{3, -1, 0, 1},
                            {2, 2,  1, -1},
                            {1, -1, 2, -1},
                            {0, -1, 3, 4}};
    sol.wallsAndGates(v);
    EXPECT_EQ(v, ans);
}

TEST(test, 2) {
    SOLUTION_CLASS sol;
    vector<vector<int>> v{{-1}};
    vector<vector<int>> ans{{-1}};
    sol.wallsAndGates(v);
    EXPECT_EQ(v, ans);
}
