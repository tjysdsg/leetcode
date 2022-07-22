#pragma once

#include "sol.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

TEST(test, 1) {
    SOLUTION_CLASS sol;
    vector<vector<int>> mat{
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9},
    };
    vector<int> ans{1, 2, 3, 6, 9, 8, 7, 4, 5};
    EXPECT_EQ(sol.spiralOrder(mat), ans);
}

TEST(test, 2) {
    SOLUTION_CLASS sol;
    vector<vector<int>> mat{
            {1, 2,  3,  4},
            {5, 6,  7,  8},
            {9, 10, 11, 12},
    };
    vector<int> ans{1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7};
    EXPECT_EQ(sol.spiralOrder(mat), ans);
}
