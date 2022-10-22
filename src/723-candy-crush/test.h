#pragma once

#include "sol.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

TEST(test, 1) {
    SOLUTION_CLASS sol;
    vector<vector<int>> v{{110, 5,   112, 113, 114},
                          {210, 211, 5,   213, 214},
                          {310, 311, 3,   313, 314},
                          {410, 411, 412, 5,   414},
                          {5,   1,   512, 3,   3},
                          {610, 4,   1,   613, 614},
                          {710, 1,   2,   713, 714},
                          {810, 1,   2,   1,   1},
                          {1,   1,   2,   2,   2},
                          {4,   1,   4,   4,   1014}};
    vector<vector<int>> ans{{0,   0,   0,   0,   0},
                            {0,   0,   0,   0,   0},
                            {0,   0,   0,   0,   0},
                            {110, 0,   0,   0,   114},
                            {210, 0,   0,   0,   214},
                            {310, 0,   0,   113, 314},
                            {410, 0,   0,   213, 414},
                            {610, 211, 112, 313, 614},
                            {710, 311, 412, 613, 714},
                            {810, 411, 512, 713, 1014}};
    EXPECT_EQ(sol.candyCrush(v), ans);
}

TEST(test, 2) {
    SOLUTION_CLASS sol;
    vector<vector<int>> v{{1, 3, 5, 5, 2},
                          {3, 4, 3, 3, 1},
                          {3, 2, 4, 5, 2},
                          {2, 4, 4, 5, 5},
                          {1, 4, 4, 1, 1}};
    vector<vector<int>> ans{{1, 3, 0, 0, 0},
                            {3, 4, 0, 5, 2},
                            {3, 2, 0, 3, 1},
                            {2, 4, 0, 5, 2},
                            {1, 4, 3, 1, 1}};
    EXPECT_EQ(sol.candyCrush(v), ans);
}
