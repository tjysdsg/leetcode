#pragma once

#include "sol.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

TEST(test, 1) {
    SOLUTION_CLASS sol;
    vector<int> v{1, 3, 5, 4, 7};
    EXPECT_EQ(sol.findLengthOfLCIS(v), 3);
}

TEST(test, 2) {
    SOLUTION_CLASS sol;
    vector<int> v{2, 2, 2, 2, 2};
    EXPECT_EQ(sol.findLengthOfLCIS(v), 1);
}

TEST(test, 3) {
    SOLUTION_CLASS sol;
    vector<int> v{1};
    EXPECT_EQ(sol.findLengthOfLCIS(v), 1);
}
