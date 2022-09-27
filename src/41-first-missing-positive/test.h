#pragma once

#include "sol.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

TEST(test, 1) {
    SOLUTION_CLASS sol;
    vector<int> v{1, 2, 0};
    EXPECT_EQ(sol.firstMissingPositive(v), 3);
}

TEST(test, 2) {
    SOLUTION_CLASS sol;
    vector<int> v{3, 4, -1, 1};
    EXPECT_EQ(sol.firstMissingPositive(v), 2);
}

TEST(test, 3) {
    SOLUTION_CLASS sol;
    vector<int> v{7, 8, 9, 11, 12};
    EXPECT_EQ(sol.firstMissingPositive(v), 1);
}

TEST(test, 4) {
    SOLUTION_CLASS sol;
    vector<int> v{1, 2, 3, 4};
    EXPECT_EQ(sol.firstMissingPositive(v), 5);
}
