#pragma once

#include "sol.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

TEST(test, 1) {
    SOLUTION_CLASS sol;
    vector<vector<int>> v{{5, 4},
                          {6, 4},
                          {6, 7},
                          {2, 3}};
    EXPECT_EQ(sol.maxEnvelopes(v), 3);
}

TEST(test, 2) {
    SOLUTION_CLASS sol;
    vector<vector<int>> v{{1, 1},
                          {1, 1},
                          {1, 1}};
    EXPECT_EQ(sol.maxEnvelopes(v), 1);
}

TEST(test, 3) {
    SOLUTION_CLASS sol;
    vector<vector<int>> v{{5, 4},
                          {6, 5},
                          {3, 6},
                          {2, 3}};
    EXPECT_EQ(sol.maxEnvelopes(v), 3);
}

TEST(test, 4) {
    SOLUTION_CLASS sol;
    vector<vector<int>> v{{4, 5},
                          {4, 6},
                          {6, 7},
                          {2, 3},
                          {1, 1}};
    EXPECT_EQ(sol.maxEnvelopes(v), 4);
}
