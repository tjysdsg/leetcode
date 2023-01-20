#pragma once

#include "sol.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

TEST(test, 1) {
    SOLUTION_CLASS sol;
    vector<vector<int>> ans{{1}};
    EXPECT_EQ(sol.generateMatrix(1), ans);
}

TEST(test, 2) {
    SOLUTION_CLASS sol;
    vector<vector<int>> ans{{1, 2, 3},
                            {8, 9, 4},
                            {7, 6, 5}};
    EXPECT_EQ(sol.generateMatrix(3), ans);
}

TEST(test, 3) {
    SOLUTION_CLASS sol;
    vector<vector<int>> ans{{1, 2},
                            {4, 3}};
    EXPECT_EQ(sol.generateMatrix(2), ans);
}

TEST(test, 4) {
    SOLUTION_CLASS sol;
    vector<vector<int>> ans{{1,  2,  3,  4},
                            {12, 13, 14, 5},
                            {11, 16, 15, 6},
                            {10, 9,  8,  7}};
    EXPECT_EQ(sol.generateMatrix(4), ans);
}
