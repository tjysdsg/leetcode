#pragma once

#include "sol.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

TEST(test, 1) {
    SOLUTION_CLASS sol;
    vector<vector<int>> v{{1,  3},
                          {2,  6},
                          {8,  10},
                          {15, 18}};
    vector<vector<int>> ans{{1,  6},
                            {8,  10},
                            {15, 18}};
    EXPECT_EQ(sol.merge(v), ans);
}

TEST(test, 2) {
    SOLUTION_CLASS sol;
    vector<vector<int>> v{{1, 4},
                          {4, 5}};
    vector<vector<int>> ans{{1, 5}};
    EXPECT_EQ(sol.merge(v), ans);
}

TEST(test, 3) {
    SOLUTION_CLASS sol;
    vector<vector<int>> v{{1, 4},
                          {4, 4},
                          {6, 6}};
    vector<vector<int>> ans{{1, 4},
                            {6, 6}};
    EXPECT_EQ(sol.merge(v), ans);
}
