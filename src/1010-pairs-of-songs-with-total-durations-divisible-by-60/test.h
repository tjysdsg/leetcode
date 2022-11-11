#pragma once

#include "sol.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

TEST(test, 1) {
    SOLUTION_CLASS sol;
    vector<int> v{30, 20, 150, 100, 40};
    EXPECT_EQ(sol.numPairsDivisibleBy60(v), 3);
}

TEST(test, 2) {
    SOLUTION_CLASS sol;
    vector<int> v{60, 60, 60};
    EXPECT_EQ(sol.numPairsDivisibleBy60(v), 3);
}

TEST(test, 3) {
    SOLUTION_CLASS sol;
    vector<int> v{30, 30, 30, 30, 30};
    EXPECT_EQ(sol.numPairsDivisibleBy60(v), 10);
}
