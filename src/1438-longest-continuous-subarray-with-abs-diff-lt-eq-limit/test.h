#pragma once

#include "sol.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

TEST(test, 1) {
    SOLUTION_CLASS sol;
    vector<int> v{8, 2, 4, 7};
    EXPECT_EQ(sol.longestSubarray(v, 4), 2);
}

TEST(test, 2) {
    SOLUTION_CLASS sol;
    vector<int> v{10, 1, 2, 4, 7, 2};
    EXPECT_EQ(sol.longestSubarray(v, 5), 4);
}

TEST(test, 3) {
    SOLUTION_CLASS sol;
    vector<int> v{4, 2, 2, 2, 4, 4, 2, 2};
    EXPECT_EQ(sol.longestSubarray(v, 0), 3);
}
