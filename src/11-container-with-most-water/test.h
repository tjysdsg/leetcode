#pragma once

#include "sol.hpp"
#include <gtest/gtest.h>
#include <algorithm>

TEST(test, 1) {
    SOLUTION_CLASS sol;
    vector<int> v{1, 8, 6, 2, 5, 4, 8, 3, 7};
    EXPECT_EQ(sol.maxArea(v), 49);
}

TEST(test, 2) {
    SOLUTION_CLASS sol;
    vector<int> v{1, 1};
    EXPECT_EQ(sol.maxArea(v), 1);
}

TEST(test, 3) {
    SOLUTION_CLASS sol;
    vector<int> v{2, 9, 3, 4, 7, 2, 12, 6};
    EXPECT_EQ(sol.maxArea(v), 45);
}
