#pragma once

#include "sol.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

TEST(test, 1) {
    SOLUTION_CLASS sol;
    vector<int> v{1, 1, 1};
    EXPECT_EQ(sol.subarraySum(v, 2), 2);
}

TEST(test, 2) {
    SOLUTION_CLASS sol;
    vector<int> v{1, 2, 3};
    EXPECT_EQ(sol.subarraySum(v, 3), 2);
}

TEST(test, 3) {
    SOLUTION_CLASS sol;
    vector<int> v{1};
    EXPECT_EQ(sol.subarraySum(v, 3), 0);
}

TEST(test, 4) {
    SOLUTION_CLASS sol;
    vector<int> v{-1, 1};
    EXPECT_EQ(sol.subarraySum(v, 0), 1);
}
