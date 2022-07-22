#pragma once

#include "sol.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

TEST(test, 1) {
    SOLUTION_CLASS sol;
    vector<int> v{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    EXPECT_EQ(sol.maxSubArray(v), 6);
}

TEST(test, 2) {
    SOLUTION_CLASS sol;
    vector<int> v{1};
    EXPECT_EQ(sol.maxSubArray(v), 1);
}

TEST(test, 3) {
    SOLUTION_CLASS sol;
    vector<int> v{5, 4, -1, 7, 8};
    EXPECT_EQ(sol.maxSubArray(v), 23);
}

TEST(test, 4) {
    SOLUTION_CLASS sol;
    vector<int> v{-1};
    EXPECT_EQ(sol.maxSubArray(v), -1);
}
