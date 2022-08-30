#pragma once

#include "sol.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

TEST(test, 1) {
    SOLUTION_CLASS sol;
    vector<int> v{100, 4, 200, 1, 3, 2};
    EXPECT_EQ(sol.longestConsecutive(v), 4);
}

TEST(test, 2) {
    SOLUTION_CLASS sol;
    vector<int> v{0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    EXPECT_EQ(sol.longestConsecutive(v), 9);
}
