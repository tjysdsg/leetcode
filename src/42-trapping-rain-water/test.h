#pragma once

#include "sol.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

TEST(test, 1) {
    SOLUTION_CLASS sol;
    vector<int> v{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    EXPECT_EQ(sol.trap(v), 6);
}

TEST(test, 2) {
    SOLUTION_CLASS sol;
    vector<int> v{4, 2, 0, 3, 2, 5};
    EXPECT_EQ(sol.trap(v), 9);
}

TEST(test, 3) {
    SOLUTION_CLASS sol;
    vector<int> v{1};
    EXPECT_EQ(sol.trap(v), 0);
}
