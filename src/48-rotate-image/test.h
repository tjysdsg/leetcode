#pragma once

#include "sol.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

TEST(test, 1) {
    SOLUTION_CLASS sol;
    vector<vector<int>> v{{1, 2, 3},
                          {4, 5, 6},
                          {7, 8, 9}};
    vector<vector<int>> ans{{7, 4, 1},
                            {8, 5, 2},
                            {9, 6, 3}};
    sol.rotate(v);
    EXPECT_EQ(v, ans);
}

TEST(test, 2) {
    SOLUTION_CLASS sol;
    vector<vector<int>> v{{5,  1,  9,  11},
                          {2,  4,  8,  10},
                          {13, 3,  6,  7},
                          {15, 14, 12, 16}};
    vector<vector<int>> ans{{15, 13, 2,  5},
                            {14, 3,  4,  1},
                            {12, 6,  8,  9},
                            {16, 7,  10, 11}};
    sol.rotate(v);
    EXPECT_EQ(v, ans);
}

TEST(test, 3) {
    SOLUTION_CLASS sol;
    vector<vector<int>> v{{1, 2},
                          {3, 4}};
    vector<vector<int>> ans{{3, 1},
                            {4, 2}};
    sol.rotate(v);
    EXPECT_EQ(v, ans);
}
