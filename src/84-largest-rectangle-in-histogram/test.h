#pragma once

#include "sol.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

TEST(test, 3) {
    SOLUTION_CLASS sol;
    vector<int> v{1, 1};
    EXPECT_EQ(sol.largestRectangleArea(v), 2);
}

TEST(test, 1) {
    SOLUTION_CLASS sol;
    vector<int> v{2, 1, 5, 6, 2, 3};
    EXPECT_EQ(sol.largestRectangleArea(v), 10);
}

TEST(test, 2) {
    SOLUTION_CLASS sol;
    vector<int> v{2, 4};
    EXPECT_EQ(sol.largestRectangleArea(v), 4);
}
