#pragma once

#include "sol.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

TEST(test, 5) {
    SOLUTION_CLASS sol;
    vector<int> v{2, 2, 2, 0, 2, 2};
    EXPECT_EQ(sol.findMin(v), 0);
}

TEST(test, 0) {
    SOLUTION_CLASS sol;
    vector<int> v{1, 3, 5};
    EXPECT_EQ(sol.findMin(v), 1);
}

TEST(test, 1) {
    SOLUTION_CLASS sol;
    vector<int> v{2, 2, 2, 0, 1};
    EXPECT_EQ(sol.findMin(v), 0);
}

TEST(test, 2) {
    SOLUTION_CLASS sol;
    vector<int> v{4, 5, 6, 7, 0, 1, 4};
    EXPECT_EQ(sol.findMin(v), 0);
}

TEST(test, 3) {
    SOLUTION_CLASS sol;
    vector<int> v{3, 3, 1, 3};
    EXPECT_EQ(sol.findMin(v), 1);
}

TEST(test, 4) {
    SOLUTION_CLASS sol;
    vector<int> v{3, 1, 3, 3, 3};
    EXPECT_EQ(sol.findMin(v), 1);
}
