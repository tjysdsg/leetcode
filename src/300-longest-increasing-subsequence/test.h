#pragma once

#include "sol.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

TEST(test, 1) {
    SOLUTION_CLASS sol;
    vector<int> v{10, 9, 2, 5, 3, 7, 101, 18};
    EXPECT_EQ(sol.lengthOfLIS(v), 4);
}

TEST(test, 2) {
    SOLUTION_CLASS sol;
    vector<int> v{0, 1, 0, 3, 2, 3};
    EXPECT_EQ(sol.lengthOfLIS(v), 4);
}

TEST(test, 3) {
    SOLUTION_CLASS sol;
    vector<int> v{7, 7, 7, 7, 7, 7, 7};
    EXPECT_EQ(sol.lengthOfLIS(v), 1);
}

TEST(test, 4) {
    SOLUTION_CLASS sol;
    vector<int> v{0};
    EXPECT_EQ(sol.lengthOfLIS(v), 1);
}
