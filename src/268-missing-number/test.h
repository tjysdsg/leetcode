#pragma once

#include "sol.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

TEST(test, 1) {
    SOLUTION_CLASS sol;
    vector<int> v{3, 0, 1};
    EXPECT_EQ(sol.missingNumber(v), 2);
}

TEST(test, 2) {
    SOLUTION_CLASS sol;
    vector<int> v{0, 1};
    EXPECT_EQ(sol.missingNumber(v), 2);
}

TEST(test, 3) {
    SOLUTION_CLASS sol;
    vector<int> v{9, 6, 4, 2, 3, 5, 7, 0, 1};
    EXPECT_EQ(sol.missingNumber(v), 8);
}
