#pragma once

#include "sol.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

TEST(test, 4) {
    SOLUTION_CLASS sol;
    vector<int> v{96, 90, 41, 82, 39, 74, 64, 50, 30};
    EXPECT_EQ(sol.maxScore(v, 8), 536);
}

TEST(test, 1) {
    SOLUTION_CLASS sol;
    vector<int> v{1, 2, 3, 4, 5, 6, 1};
    EXPECT_EQ(sol.maxScore(v, 3), 12);
}

TEST(test, 2) {
    SOLUTION_CLASS sol;
    vector<int> v{2, 2, 2};
    EXPECT_EQ(sol.maxScore(v, 2), 4);
}

TEST(test, 3) {
    SOLUTION_CLASS sol;
    vector<int> v{9, 7, 7, 9, 7, 7, 9};
    EXPECT_EQ(sol.maxScore(v, 7), 55);
}
