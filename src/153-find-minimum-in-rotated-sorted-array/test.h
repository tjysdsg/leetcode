#pragma once

#include "sol.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

TEST(test, 0) {
    SOLUTION_CLASS sol;
    vector<int> v{3, 1, 2};
    EXPECT_EQ(sol.findMin(v), 1);
}

TEST(test, 1) {
    SOLUTION_CLASS sol;
    vector<int> v{3, 4, 5, 1, 2};
    EXPECT_EQ(sol.findMin(v), 1);
}

TEST(test, 2) {
    SOLUTION_CLASS sol;
    vector<int> v{4, 5, 6, 7, 0, 1, 2};
    EXPECT_EQ(sol.findMin(v), 0);
}

TEST(test, 3) {
    SOLUTION_CLASS sol;
    vector<int> v{11, 13, 15, 17};
    EXPECT_EQ(sol.findMin(v), 11);
}
