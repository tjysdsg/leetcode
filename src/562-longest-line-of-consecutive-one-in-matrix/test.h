#pragma once

#include "sol.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

TEST(test, 0) {
    SOLUTION_CLASS sol;
    vector<vector<int>> v{{0, 1, 0, 1, 1},
                          {1, 1, 0, 0, 1},
                          {0, 0, 0, 1, 0},
                          {1, 0, 1, 1, 1},
                          {1, 0, 0, 0, 1}};
    EXPECT_EQ(sol.longestLine(v), 3);
}

TEST(test, 1) {
    SOLUTION_CLASS sol;
    vector<vector<int>> v{{0, 1, 1, 0},
                          {0, 1, 1, 0},
                          {0, 0, 0, 1}};
    EXPECT_EQ(sol.longestLine(v), 3);
}

TEST(test, 2) {
    SOLUTION_CLASS sol;
    vector<vector<int>> v{{1, 1, 1, 1},
                          {0, 1, 1, 0},
                          {0, 0, 0, 1}};
    EXPECT_EQ(sol.longestLine(v), 4);
}
