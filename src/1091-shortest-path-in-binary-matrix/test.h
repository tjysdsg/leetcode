#pragma once

#include "sol.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

TEST(test, 1) {
    SOLUTION_CLASS sol;
    vector<vector<int>> v{{0, 1},
                          {1, 0}};
    EXPECT_EQ(sol.shortestPathBinaryMatrix(v), 2);
}

TEST(test, 2) {
    SOLUTION_CLASS sol;
    vector<vector<int>> v{{0, 0, 0},
                          {1, 1, 0},
                          {1, 1, 0}};
    EXPECT_EQ(sol.shortestPathBinaryMatrix(v), 4);
}

TEST(test, 3) {
    SOLUTION_CLASS sol;
    vector<vector<int>> v{{1, 0, 0},
                          {1, 1, 0},
                          {1, 1, 0}};
    EXPECT_EQ(sol.shortestPathBinaryMatrix(v), -1);
}
