#pragma once

#include "sol.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

TEST(test, 0) {
    SOLUTION_CLASS sol;
    vector<int> v{99, 1};
    EXPECT_EQ(sol.canPartition(v), false);
}

TEST(test, 1) {
    SOLUTION_CLASS sol;
    vector<int> v{1, 5, 11, 5};
    EXPECT_EQ(sol.canPartition(v), true);
}

TEST(test, 2) {
    SOLUTION_CLASS sol;
    vector<int> v{1, 2, 3, 5};
    EXPECT_EQ(sol.canPartition(v), false);
}

TEST(test, 3) {
    SOLUTION_CLASS sol;
    vector<int> v{2, 2, 1, 1};
    EXPECT_EQ(sol.canPartition(v), true);
}

TEST(test, 4) {
    SOLUTION_CLASS sol;
    vector<int> v{1};
    EXPECT_EQ(sol.canPartition(v), false);
}
