#pragma once

#include "sol.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

TEST(test, 1) {
    SOLUTION_CLASS sol;
    vector<int> v{1, 10, 3, 10, 2};
    EXPECT_EQ(sol.minDays(v, 3, 1), 3);
}

TEST(test, 2) {
    SOLUTION_CLASS sol;
    vector<int> v{1, 10, 3, 10, 2};
    EXPECT_EQ(sol.minDays(v, 3, 2), -1);
}

TEST(test, 3) {
    SOLUTION_CLASS sol;
    vector<int> v{7, 7, 7, 7, 12, 7, 7};
    EXPECT_EQ(sol.minDays(v, 2, 3), 12);
}
