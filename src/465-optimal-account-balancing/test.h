#pragma once

#include "sol.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

TEST(test, 1) {
    SOLUTION_CLASS sol;
    vector<vector<int>> v{{0, 1, 10},
                          {2, 0, 5}};
    EXPECT_EQ(sol.minTransfers(v), 2);
}

TEST(test, 2) {
    SOLUTION_CLASS sol;
    vector<vector<int>> v{{0, 1, 10},
                          {1, 0, 1},
                          {1, 2, 5},
                          {2, 0, 5}};
    EXPECT_EQ(sol.minTransfers(v), 1);
}

TEST(test, 3) {
    SOLUTION_CLASS sol;
    vector<vector<int>> v{{0, 1, 1}};
    EXPECT_EQ(sol.minTransfers(v), 1);
}

TEST(test, 4) {
    SOLUTION_CLASS sol;
    vector<vector<int>> v{{1, 5, 8},
                          {8, 9, 8},
                          {2, 3, 9},
                          {4, 3, 1}};
    EXPECT_EQ(sol.minTransfers(v), 4);
}
