#pragma once

#include "sol.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

TEST(test, 1) {
    SOLUTION_CLASS sol;
    vector<vector<int>> v{{0, 1},
                          {1, 2},
                          {3, 4}};
    EXPECT_EQ(sol.countComponents(5, v), 2);
}

TEST(test, 2) {
    SOLUTION_CLASS sol;
    vector<vector<int>> v{{0, 1},
                          {1, 2},
                          {2, 3},
                          {3, 4}};
    EXPECT_EQ(sol.countComponents(5, v), 1);
}
