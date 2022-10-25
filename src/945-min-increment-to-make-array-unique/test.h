#pragma once

#include "sol.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

TEST(test, 1) {
    SOLUTION_CLASS sol;
    vector<int> v{1, 2, 2};
    EXPECT_EQ(sol.minIncrementForUnique(v), 1);
}

TEST(test, 2) {
    SOLUTION_CLASS sol;
    vector<int> v{3, 2, 1, 2, 1, 7};
    EXPECT_EQ(sol.minIncrementForUnique(v), 6);
}

TEST(test, 3) {
    SOLUTION_CLASS sol;
    vector<int> v{1};
    EXPECT_EQ(sol.minIncrementForUnique(v), 0);
}
