#pragma once

#include "sol.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

TEST(test, 1) {
    SOLUTION_CLASS sol;
    vector<int> v{1, 2, 5};
    EXPECT_EQ(sol.coinChange(v, 11), 3);
}

TEST(test, 2) {
    SOLUTION_CLASS sol;
    vector<int> v{2};
    EXPECT_EQ(sol.coinChange(v, 3), -1);
}

TEST(test, 3) {
    SOLUTION_CLASS sol;
    vector<int> v{1};
    EXPECT_EQ(sol.coinChange(v, 0), 0);
}

TEST(test, 4) {
    SOLUTION_CLASS sol;
    vector<int> v{5, 4, 3};
    EXPECT_EQ(sol.coinChange(v, 7), 2);
}

TEST(test, 5) {
    SOLUTION_CLASS sol;
    vector<int> v{1, 2147483647};
    EXPECT_EQ(sol.coinChange(v, 2), 2);
}

TEST(test, 6) {
    SOLUTION_CLASS sol;
    vector<int> v{186, 419, 83, 408};
    EXPECT_EQ(sol.coinChange(v, 6249), 20);
}
