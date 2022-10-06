#pragma once

#include "sol.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

TEST(test, 0) {
    SOLUTION_CLASS sol;
    vector<int> v{0, 0, 1, 0, 0, 1, 1, 1, 1, 1};
    EXPECT_EQ(sol.longestMountain(v), 3);
}

TEST(test, 1) {
    SOLUTION_CLASS sol;
    vector<int> v{1};
    EXPECT_EQ(sol.longestMountain(v), 0);
}

TEST(test, 2) {
    SOLUTION_CLASS sol;
    vector<int> v{2, 1, 4, 7, 3, 2, 5};
    EXPECT_EQ(sol.longestMountain(v), 5);
}

TEST(test, 3) {
    SOLUTION_CLASS sol;
    vector<int> v{2, 2, 2};
    EXPECT_EQ(sol.longestMountain(v), 0);
}

TEST(test, 4) {
    SOLUTION_CLASS sol;
    vector<int> v{1, 1, 0, 0, 1, 0};
    EXPECT_EQ(sol.longestMountain(v), 3);
}
