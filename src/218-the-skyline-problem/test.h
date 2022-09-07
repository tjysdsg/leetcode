#pragma once

#include "sol.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

TEST(test, 3) {
    SOLUTION_CLASS sol;
    vector<vector<int>> v{{1, 2, 1},
                          {1, 2, 2},
                          {1, 2, 3}};
    vector<vector<int>> ans{{1, 3},
                            {2, 0}};
    EXPECT_EQ(sol.getSkyline(v), ans);
}

TEST(test, 1) {
    SOLUTION_CLASS sol;
    vector<vector<int>> v{{2,  9,  10},
                          {3,  7,  15},
                          {5,  12, 12},
                          {15, 20, 10},
                          {19, 24, 8}};
    vector<vector<int>> ans{{2,  10},
                            {3,  15},
                            {7,  12},
                            {12, 0},
                            {15, 10},
                            {20, 8},
                            {24, 0}};
    EXPECT_EQ(sol.getSkyline(v), ans);
}

TEST(test, 2) {
    SOLUTION_CLASS sol;
    vector<vector<int>> v{{0, 2, 3},
                          {2, 5, 3}};
    vector<vector<int>> ans{{0, 3},
                            {5, 0}};
    EXPECT_EQ(sol.getSkyline(v), ans);
}
