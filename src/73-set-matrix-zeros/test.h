#pragma once

#include "sol.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

TEST(test, 0) {
    SOLUTION_CLASS sol;
    vector<vector<int>> v{{1,  2,  3,  4},
                          {5,  0,  7,  8},
                          {0,  10, 11, 12},
                          {13, 14, 15, 0}};
    vector<vector<int>> ans{{0, 0, 3, 0},
                            {0, 0, 0, 0},
                            {0, 0, 0, 0},
                            {0, 0, 0, 0}};
    sol.setZeroes(v);
    EXPECT_EQ(v, ans);
}

TEST(test, 1) {
    SOLUTION_CLASS sol;
    vector<vector<int>> v{{1, 1, 1},
                          {1, 0, 1},
                          {1, 1, 1}};
    vector<vector<int>> ans{{1, 0, 1},
                            {0, 0, 0},
                            {1, 0, 1}};
    sol.setZeroes(v);
    EXPECT_EQ(v, ans);
}

TEST(test, 2) {
    SOLUTION_CLASS sol;
    vector<vector<int>> v{{0, 1, 2, 0},
                          {3, 4, 5, 2},
                          {1, 3, 1, 5}};
    vector<vector<int>> ans{{0, 0, 0, 0},
                            {0, 4, 5, 0},
                            {0, 3, 1, 0}};
    sol.setZeroes(v);
    EXPECT_EQ(v, ans);
}
