#pragma once

#include "sol.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

TEST(test, 1) {
    SOLUTION_CLASS sol;
    vector<vector<int>> v{{4, 10, 15, 24, 26},
                          {0, 9,  12, 20},
                          {5, 18, 22, 30}};
    vector<int> ans{20, 24};
    EXPECT_EQ(sol.smallestRange(v), ans);
}

TEST(test, 2) {
    SOLUTION_CLASS sol;
    vector<vector<int>> v{{1, 2, 3},
                          {1, 2, 3},
                          {1, 2, 3}};
    vector<int> ans{1, 1};
    EXPECT_EQ(sol.smallestRange(v), ans);
}
