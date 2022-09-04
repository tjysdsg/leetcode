#pragma once

#include "sol.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

TEST(test, 1) {
    SOLUTION_CLASS sol;
    vector<int> v{1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    EXPECT_EQ(sol.longestOnes(v, 2), 6);
}

TEST(test, 2) {
    SOLUTION_CLASS sol;
    vector<int> v{0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1};
    EXPECT_EQ(sol.longestOnes(v, 3), 10);
}

TEST(test, 3) {
    SOLUTION_CLASS sol;
    vector<int> v{0, 0, 1, 1, 1, 0, 0};
    EXPECT_EQ(sol.longestOnes(v, 0), 3);
}
